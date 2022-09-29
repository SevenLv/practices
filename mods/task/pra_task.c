/*
 * pra_task.c
 * created on Thu Sep 15 2022
 * created by Seven Lv
 * comments:    functions of pra_task
 * version: 0.4
 * history: #       date                modification
 *          0.1     Thu Sep 15 2022     created
 *          0.2     Thu Sep 15 2022     optimize pra_task_add function
 *                                      add new error code to pra_task_add function
 *                                      optimize pra_task_execute function
 *          0.3     Thu Sep 15 2022     add pra_task_remove function
 *          0.4     Fri Sep 16 2022     fixed bugs in pra_task_execute and pra_task_remove
 *          0.4     Thu Sep 29 2022     reorganize error codes
 */

/* includes */
#include "pra_boolean.h"
#include "pra_list.h"
#include "pra_num_defs.h"
#include "pra_task.h"
#include "pra_task_internal.h"
#include "pra_timer.h"


/* variables */

static pra_list_node task_nodes[PRA_TASK_LIST_MAX_COUNT] = {
    { .p_data = PRA_VOID_NULL,
        .p_next = PRA_LIST_ST_NODE_NULL,
        .p_previous = PRA_LIST_ST_NODE_NULL }
};                                                           /* task list nodes */
static pra_list_node *p_task_list = PRA_LIST_NODE_NULL;      /* task list, first node address */
static uint32_t       task_list_used_count = PRA_NUM_ZERO_U; /* task list count */

/* functions */

pra_boolean pra_task_init(
    pra_task *const p_task,
    PRA_EC_T *const p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_task_init_args_check(
                             p_task,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        p_task->priority = PRA_NUM_ZERO_U;
        p_task->execute_func = PRA_TASK_EXECUTE_FUNC_NULL;
        p_task->execute_result = PRA_BOOL_UNKNOWN;
        p_task->execute_ec = PRA_EC_NONE;

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_task_execute(void)
{
    pra_boolean result;
    uint32_t    time;
    PRA_EC_T    error_code;

    if (PRA_LIST_NODE_NULL == p_task_list)
    {
        result = PRA_BOOL_TRUE;
    }
    else if (PRA_NUM_ZERO_U == task_list_used_count)
    {
        result = PRA_BOOL_TRUE;
    }
    else if (PRA_BOOL_TRUE != pra_timer_get_time(&time, &error_code))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        pra_list_node *p_current_node = p_task_list;
        pra_task      *p_current_task = (pra_task *)p_current_node->p_data;
        pra_boolean    failed = PRA_BOOL_FALSE;

        for (uint32_t i = PRA_NUM_ZERO_U; i < task_list_used_count; i++)
        {
            if (PRA_TASK_NULL == p_current_task)
            {
                failed = PRA_BOOL_TRUE;
                break;
            }
            else
            {
                p_current_task->execute_result = p_current_task->execute_func(
                    time,
                    &p_current_task->execute_ec);

                p_current_node = p_current_node->p_next;
                if (PRA_LIST_NODE_NULL != p_current_node)
                {
                    p_current_task = (pra_task *)p_current_node->p_data;
                }
                else
                {
                    p_current_task = PRA_TASK_NULL;
                }
            }
        }

        result = pra_boolean_not(failed);
    }

    return result;
}

pra_boolean pra_task_add(
    pra_task *const p_task,
    PRA_EC_T *const p_ec)
{
    pra_boolean result = PRA_BOOL_FALSE;

    if (PRA_BOOL_TRUE != pra_task_add_args_check(
                             p_task,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_TASK_LIST_MAX_COUNT <= task_list_used_count)
    {
        *p_ec |= PRA_EC_TASK_LIST_FULL;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_BOOL_TRUE == pra_task_exists(
                                  p_task_list,
                                  task_list_used_count,
                                  p_task))
    {
        *p_ec |= PRA_EC_ALREADY_ADDED;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        pra_boolean    find_unused_result = PRA_BOOL_UNKNOWN;
        pra_list_node *p_unused_node;
        uint32_t       unused_index = PRA_NUM_ZERO_U;

        /* find first unused node */
        find_unused_result = pra_task_find_first_unused_node(
            task_nodes,
            &unused_index);

        if (PRA_BOOL_TRUE != find_unused_result)
        {
            *p_ec |= PRA_EC_FIND_UNUSED_NODE_FAILED;
            result = PRA_BOOL_FALSE;
        }
        else
        {
            /* first task */
            if (PRA_LIST_NODE_NULL == p_task_list)
            {
                /* set the node to list */
                p_unused_node = &task_nodes[unused_index];
                p_unused_node->p_data = p_task;
                p_task_list = p_unused_node;

                task_list_used_count += 1U;

                result = PRA_BOOL_TRUE;
            }
            else
            {
                PRA_EC_T error_code = PRA_EC_NONE;

                p_unused_node = &task_nodes[unused_index];
                p_unused_node->p_data = p_task;

                pra_list_node *p_current_node = p_task_list;
                pra_task      *p_current_task = (pra_task *)p_current_node->p_data;

                /* find the position to add node */
                for (uint32_t i = PRA_NUM_ZERO_U; i < task_list_used_count; i++)
                {
                    /* insert before lower priority task */
                    if (p_current_task->priority < p_task->priority)
                    {
                        /* insert node */
                        result = pra_list_insert(
                            p_current_node,
                            p_unused_node,
                            &error_code);

                        if (PRA_BOOL_TRUE == result)
                        {
                            task_list_used_count += 1U;
                            result = PRA_BOOL_TRUE;
                        }
                        else
                        {
                            *p_ec |= PRA_EC_INSERT_NODE_FAILED;
                            result = PRA_BOOL_FALSE;
                        }
                        break;
                    }
                    /* append last */
                    else if (PRA_LIST_ST_NODE_NULL == p_current_node->p_next)
                    {
                        /* append node */
                        result = pra_list_append(
                            p_current_node,
                            p_unused_node,
                            &error_code);

                        if (PRA_BOOL_TRUE == result)
                        {
                            task_list_used_count += 1U;
                            result = PRA_BOOL_TRUE;
                        }
                        else
                        {
                            *p_ec |= PRA_EC_APPEND_NODE_FAILED;
                            result = PRA_BOOL_FALSE;
                        }
                        break;
                    }
                    /* move next */
                    else
                    {
                        p_current_node = p_current_node->p_next;
                        p_current_task = (pra_task *)p_current_node->p_data;
                    }
                }
            }
        }
    }

    return result;
}

pra_boolean pra_task_remove(
    pra_task *const p_task,
    PRA_EC_T *const p_ec)
{
    pra_boolean    result;
    pra_list_node *p_node = PRA_LIST_NODE_NULL;

    if (PRA_BOOL_TRUE != pra_task_remove_args_check(
                             p_task,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_LIST_NODE_NULL != p_task_list &&
             PRA_BOOL_TRUE != pra_task_find_node(
                                  p_task_list,
                                  task_list_used_count,
                                  p_task,
                                  &p_node))
    {
        *p_ec |= PRA_EC_NEVER_ADDED;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        PRA_EC_T temp_ec = PRA_EC_NONE;

        if (PRA_NUM_ZERO_U == task_list_used_count)
        {
            *p_ec |= PRA_EC_NEVER_ADDED;
            result = PRA_BOOL_FALSE;
        }
        else if (1U == task_list_used_count)
        {
            if (p_task_list == p_node)
            {
                p_task_list = PRA_LIST_NODE_NULL;
                result = pra_list_init(
                    p_node,
                    &temp_ec);

                if (PRA_BOOL_TRUE == result)
                {
                    task_list_used_count -= 1U;
                }
            }
            else
            {
                *p_ec |= PRA_EC_NEVER_ADDED;
                result = PRA_BOOL_FALSE;
            }
        }
        else
        {
            if (PRA_BOOL_TRUE != pra_list_remove(
                                     p_node,
                                     &temp_ec))
            {
                *p_ec |= PRA_EC_REMOVE_NODE_FAILED;
                result = PRA_BOOL_FALSE;
            }
            else
            {
                result = pra_list_init(
                    p_node,
                    &temp_ec);

                if (PRA_BOOL_TRUE != result)
                {
                    task_list_used_count -= 1U;
                }
            }
        }
    }

    return result;
}
