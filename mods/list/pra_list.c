/*
 * list.c
 * created on Tue Sep 13 2022
 * created by Seven Lv
 * comments:    definitions and functions of linked list
 */

/* includes */
#include "pra_list.h"

/* variables */

/* function declarations */

static pra_boolean pra_list_init_args_check(
    const pra_list_node *const p_node,
    PRA_EC_T                  *p_ec);

/* functions */

static pra_boolean pra_list_init_args_check(
    const pra_list_node *const p_node,
    PRA_EC_T                  *p_ec)
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

pra_boolean pra_list_init(
    pra_list_node *const p_node,
    PRA_EC_T            *p_ec)
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