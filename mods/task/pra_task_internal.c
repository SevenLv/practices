/*
 * pra_task_internal.c
 * created on Thu Sep 15 2022
 * created by Seven Lv
 * comments:    internal functions of pra_task
 * version: 0.3
 * history: #       date                modification
 *          0.1     Thu Sep 15 2022     created
 *          0.2     Thu Sep 15 2022     add pra_task_remove_args_check function
 *                                      add pra_task_find_node function
 *          0.3     Fri Sep 16 2022     changed parameter type of pra_task_find_node function
 */

/* includes */
#include "pra_ec.h"
#include "pra_list.h"
#include "pra_task_ec.h"
#include "pra_task_internal.h"


/* variables */

/* functions */

pra_boolean pra_task_init_args_check(
    const pra_task *const p_task,
    PRA_EC_T *const       p_ec)
{
    pra_boolean result;

    if (PRA_EC_T_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_TASK_NULL == p_task)
    {
        *p_ec |= PRA_TASK_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_task_add_args_check(
    const pra_task *const p_task,
    PRA_EC_T *const       p_ec)
{
    pra_boolean result;

    if (PRA_EC_T_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_TASK_NULL == p_task)
    {
        *p_ec |= PRA_TASK_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_TASK_EXECUTE_FUNC_NULL == p_task->execute_func)
    {
        *p_ec |= PRA_TASK_EC_INVALID_EXECUTE_FUNC;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_task_remove_args_check(
    const pra_task *const p_task,
    PRA_EC_T *const       p_ec)
{
    pra_boolean result;

    if (PRA_EC_T_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_TASK_NULL == p_task)
    {
        *p_ec |= PRA_TASK_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_task_find_first_unused_node(
    const pra_list_node p_nodes[],
    uint32_t *const     p_index)
{
    pra_boolean result;

    if (PRA_UINT32_NULL == p_index)
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_FALSE;

        for (uint32_t i = PRA_NUM_ZERO_U; i < PRA_TASK_LIST_MAX_COUNT; i++)
        {
            if (PRA_VOID_NULL == p_nodes[i].p_data)
            {
                *p_index = i;
                result = PRA_BOOL_TRUE;
                break;
            }
        }
    }

    return result;
}

pra_boolean pra_task_exists(
    const pra_list_node *const p_list,
    const uint32_t             used_count,
    const pra_task *const      p_task)
{
    pra_boolean result;

    if (PRA_LIST_NODE_NULL == p_list)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_TASK_NULL == p_task)
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        const pra_list_node *p_current_node = p_list;
        for (uint32_t i = PRA_NUM_ZERO_U; i < used_count; i++)
        {
            if (p_task == p_current_node->p_data)
            {
                result = PRA_BOOL_TRUE;
                break;
            }
            else if (PRA_LIST_ST_NODE_NULL != p_current_node->p_next)
            {
                p_current_node = p_current_node->p_next;
            }
            else
            {
                /* NOTE current node does not match and no next node */
                result = PRA_BOOL_FALSE;
                break;
            }
        }
    }

    return result;
}

pra_boolean pra_task_find_node(
    pra_list_node *const  p_list,
    const uint32_t        used_count,
    const pra_task *const p_task,
    pra_list_node       **p_node)
{
    pra_boolean result;

    if (PRA_LIST_NODE_NULL == p_list)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_TASK_NULL == p_task)
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        pra_list_node *p_current_node = p_list;
        for (uint32_t i = PRA_NUM_ZERO_U; i < used_count; i++)
        {
            if (p_task == p_current_node->p_data)
            {
                *p_node = p_current_node;
                result = PRA_BOOL_TRUE;
                break;
            }
            else if (PRA_LIST_ST_NODE_NULL != p_current_node->p_next)
            {
                p_current_node = p_current_node->p_next;
            }
            else
            {
                /* NOTE current node does not match and no next node */
                result = PRA_BOOL_FALSE;
                break;
            }
        }
    }
    return result;
}
