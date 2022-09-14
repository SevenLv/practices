/*
 * list.c
 * created on Tue Sep 13 2022
 * created by Seven Lv
 * comments:    definitions and functions of linked list
 * version: 0.4
 * history: #       date                modification
 *          0.1     Tue Sep 13 2022     created
 *          0.2     Tue Sep 13 2022     move static functions to internal files
 *          0.3     Tue Sep 13 2022     add pra_list_remove function
 *          0.4     Wed Sep 14 2022     include pra_list_ec.h
 *                                      include pra_list.h
 */

/* includes */
#include "pra_list.h"
#include "pra_list_ec.h"
#include "pra_list_internal.h"


/* variables */

/* functions */

pra_boolean pra_list_init(
    pra_list_node *const p_node,
    PRA_EC_T *const      p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_list_init_args_check(
                             p_node,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        p_node->p_data = PRA_VOID_NULL;
        p_node->p_previous = PRA_LIST_ST_NODE_NULL;
        p_node->p_next = PRA_LIST_ST_NODE_NULL;

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_list_append(
    pra_list_node *const p_cur_node,
    pra_list_node *const p_next_node,
    PRA_EC_T *const      p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_list_append_args_check(
                             p_cur_node,
                             p_next_node,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        p_next_node->p_next = p_cur_node->p_next;
        p_cur_node->p_next = p_next_node;
        p_next_node->p_previous = p_cur_node;

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_list_insert(
    pra_list_node *const p_cur_node,
    pra_list_node *const p_pre_node,
    PRA_EC_T *const      p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_list_insert_args_check(
                             p_cur_node,
                             p_pre_node,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        p_pre_node->p_previous = p_cur_node->p_previous;
        p_cur_node->p_previous = p_pre_node;
        p_pre_node->p_next = p_cur_node;

        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_list_remove(
    pra_list_node *const p_node,
    PRA_EC_T *const      p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_list_remove_args_check(
                             p_node,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        if (PRA_LIST_ST_NODE_NULL != p_node->p_previous &&
            PRA_LIST_ST_NODE_NULL != p_node->p_next)
        {
            p_node->p_previous->p_next = p_node->p_next;
            p_node->p_next->p_previous = p_node->p_previous;

            p_node->p_next = PRA_LIST_ST_NODE_NULL;
            p_node->p_previous = PRA_LIST_ST_NODE_NULL;

            result = PRA_BOOL_TRUE;
        }
        else if (PRA_LIST_ST_NODE_NULL != p_node->p_previous &&
                 PRA_LIST_ST_NODE_NULL == p_node->p_next)
        {
            p_node->p_previous->p_next = PRA_LIST_ST_NODE_NULL;
            p_node->p_previous = PRA_LIST_ST_NODE_NULL;

            result = PRA_BOOL_TRUE;
        }
        else if (PRA_LIST_ST_NODE_NULL == p_node->p_previous &&
                 PRA_LIST_ST_NODE_NULL != p_node->p_next)
        {
            p_node->p_next->p_previous = PRA_LIST_ST_NODE_NULL;
            p_node->p_next = PRA_LIST_ST_NODE_NULL;

            result = PRA_BOOL_TRUE;
        }
        else
        {
            *p_ec |= PRA_LIST_EC_INVALID_CURRENT;
            result = PRA_BOOL_FALSE;
        }
    }

    return result;
}
