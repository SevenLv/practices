/*
 * list.c
 * created on Tue Sep 13 2022
 * created by Seven Lv
 * comments:    definitions and functions of linked list
 * version: 0.1
 * history: #       date               modification
 *          0.1     Tue Sep 13 2022    created
 */

/* includes */
#include "pra_list.h"

/* variables */

/* function declarations */

/**
 * @brief           arguments validation for pra_list_init function
 * @note
 * @param  p_node:  pointer of the node
 * @param  p_ec:    output error code:
 *                  PRA_LIST_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
static pra_boolean pra_list_init_args_check(
    const pra_list_node *const p_node,
    PRA_EC_T *const            p_ec);

/**
 * @brief               arguments validation for pra_list_append function
 * @note
 * @param  p_cur_node:  pointer of current node
 * @param  p_next_node: pointer of next node
 * @param  p_ec:        output error code:
 *                      PRA_LIST_EC_NULL_PTR
 *                      PRA_LIST_EC_PREVIOUS_NOT_NULL - PRA_LIST_ST_NODE_NULL != p_next_node.p_previous
 * @retval              PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
static pra_boolean pra_list_append_args_check(
    const pra_list_node *const p_cur_node,
    const pra_list_node *const p_next_node,
    PRA_EC_T *const            p_ec);

/**
 * @brief               arguments validation for pra_list_insert function
 * @note
 * @param  p_cur_node:  pointer of current node
 * @param  p_pre_node:  poitner of previous node
 * @param  p_ec:        output error code:
 *                      PRA_LIST_EC_NULL_PTR
 *                      PRA_LIST_EC_NEXT_NOT_NULL -- PRA_LIST_ST_NODE_NULL != p_pre_node.p_next
 * @retval              PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
static pra_boolean pra_list_insert_args_check(
    const pra_list_node *const p_cur_node,
    const pra_list_node *const p_pre_node,
    PRA_EC_T *const            p_ec);

/* functions */

static pra_boolean pra_list_init_args_check(
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

static pra_boolean pra_list_append_args_check(
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

static pra_boolean pra_list_insert_args_check(
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
