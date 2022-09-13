/*
 * list.c
 * created on Tue Sep 13 2022
 * created by Seven Lv
 * comments:    definitions and functions of linked list
 * version: 0.2
 * history: #       date                modification
 *          0.1     Tue Sep 13 2022     created
 *          0.2     Tue Sep 13 2022     move static functions to internal files
 */

/* includes */
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
        p_cur_node->p_next = (struct _pra_list_node *)p_next_node;
        p_next_node->p_previous = (struct _pra_list_node *)p_cur_node;

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
        p_cur_node->p_previous = (struct _pra_list_node *)p_pre_node;
        p_pre_node->p_next = (struct _pra_list_node *)p_cur_node;

        result = PRA_BOOL_TRUE;
    }

    return result;
}
