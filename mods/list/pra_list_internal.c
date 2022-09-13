/*
 * pra_list_internal.c
 * created on Tue Sep 13 2022
 * created by Seven Lv
 * comments:    internal functions of pra_list
 * version: 0.2
 * history: #       date                modification
 *          0.1     Tue Sep 13 2022     created
 *          0.2     Tue Sep 13 2022     add pra_list_remove_ars_check function
 */

/* includes */
#include "pra_list_internal.h"

/* variables */

/* functions */

pra_boolean pra_list_init_args_check(
    const pra_list_node *const p_node,
    PRA_EC_T *const            p_ec)
{
    pra_boolean result;

    if (PRA_EC_T_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_LIST_NODE_NULL == p_node)
    {
        *p_ec = PRA_LIST_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_list_append_args_check(
    const pra_list_node *const p_cur_node,
    const pra_list_node *const p_next_node,
    PRA_EC_T *const            p_ec)
{
    pra_boolean result;

    if (PRA_EC_T_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_LIST_NODE_NULL == p_cur_node)
    {
        *p_ec |= PRA_LIST_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_LIST_NODE_NULL == p_next_node)
    {
        *p_ec |= PRA_LIST_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_LIST_ST_NODE_NULL != p_next_node->p_previous)
    {
        *p_ec |= PRA_LIST_EC_PREVIOUS_NOT_NULL;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_list_insert_args_check(
    const pra_list_node *const p_cur_node,
    const pra_list_node *const p_pre_node,
    PRA_EC_T *const            p_ec)
{
    pra_boolean result;

    if (PRA_EC_T_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_LIST_NODE_NULL == p_cur_node)
    {
        *p_ec |= PRA_LIST_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_LIST_NODE_NULL == p_pre_node)
    {
        *p_ec |= PRA_LIST_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_LIST_ST_NODE_NULL != p_pre_node->p_next)
    {
        *p_ec |= PRA_LIST_EC_NEXT_NOT_NULL;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_list_remove_args_check(
    const pra_list_node *const p_node,
    PRA_EC_T *const            p_ec)
{
    pra_boolean result;

    if (PRA_EC_T_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_LIST_NODE_NULL == p_node)
    {
        *p_ec |= PRA_LIST_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_LIST_ST_NODE_NULL != p_node->p_previous &&
             p_node->p_previous->p_next != p_node)
    {
        *p_ec |= PRA_LIST_EC_INVALID_NEXT;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_LIST_ST_NODE_NULL != p_node->p_next &&
             p_node->p_next->p_previous != p_node)
    {
        *p_ec |= PRA_LIST_EC_INVALID_PREVIOUS;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}
