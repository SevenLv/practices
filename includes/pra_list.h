/*
 * list.h
 * created on Tue Sep 13 2022
 * created by Seven Lv
 * comments:    definitions and functions of linked list
 * version: 0.2
 * history: #       date                modification
 *          0.1     Tue Sep 13 2022     created
 *          0.2     Tue Sep 13 2022     add pra_list_remove function
 */

#ifndef INC_PRA_LIST_H_
#define INC_PRA_LIST_H_

/* includes */
#include "pra_boolean.h"
#include "pra_defs.h"
#include "pra_num_defs.h"
#include "stdio.h"

/* macros */

#define PRA_LIST_ST_NODE_NULL PRA_NULL_PTR(struct _pra_list_node)
#define PRA_LIST_NODE_NULL    PRA_NULL_PTR(pra_list_node)

#define PRA_LIST_EC_NONE              PRA_NUM_ZERO_U
#define PRA_LIST_EC_NULL_PTR          PRA_NUM_BIT_MASK_00
#define PRA_LIST_EC_NEXT_NOT_NULL     PRA_NUM_BIT_MASK_01
#define PRA_LIST_EC_PREVIOUS_NOT_NULL PRA_NUM_BIT_MASK_02
#define PRA_LIST_EC_INVALID_NEXT      PRA_NUM_BIT_MASK_03
#define PRA_LIST_EC_INVALID_PREVIOUS  PRA_NUM_BIT_MASK_04
#define PRA_LIST_EC_INVALID_CURRENT   PRA_NUM_BIT_MASK_05

/* types */

/* linked list node */
typedef struct _pra_list_node
{
    struct _pra_list_node *p_previous; /* pointer of previous node */
    struct _pra_list_node *p_next;     /* pointer of next node */
    void                  *p_data;     /* pointer of current node data */
} pra_list_node;                       /* linked list node */

/* variables */

/* functions */

/**
 * @brief           initialize a pra_list_node struct
 * @note
 * @param  p_node:  pointer of the node
 * @param  p_ec:    output error code:
 *                  PRA_LIST_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_list_init(
    pra_list_node *const p_node,
    PRA_EC_T *const      p_ec);

/**
 * @brief               append a next node to current node
 * @note
 * @param  p_cur_node:  pointer of current node
 * @param  p_next_node: pointer of next node
 * @param  p_ec:        output error code:
 *                      PRA_LIST_EC_NULL_PTR
 *                      PRA_LIST_EC_PREVIOUS_NOT_NULL - PRA_LIST_ST_NODE_NULL != p_next_node.p_previous
 * @retval              PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_list_append(
    pra_list_node *const p_cur_node,
    pra_list_node *const p_next_node,
    PRA_EC_T *const      p_ec);

/**
 * @brief               insert a previous node to current node
 * @note
 * @param  p_cur_node:  pointer of current node
 * @param  p_pre_node:  poitner of next node
 * @param  p_ec:        output error code:
 *                      PRA_LIST_EC_NULL_PTR
 *                      PRA_LIST_EC_NEXT_NOT_NULL -- PRA_LIST_ST_NODE_NULL != p_pre_node.p_next
 * @retval              PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_list_insert(
    pra_list_node *const p_cur_node,
    pra_list_node *const p_pre_node,
    PRA_EC_T *const      p_ec);

/**
 * @brief           remove node for the linked list
 * @note
 * @param  p_node:  pointer of node
 * @param  p_ec:    output error code:
 *                  PRA_LIST_EC_NULL_PTR
 *                  PRA_LIST_EC_INVALID_NEXT - next node of previous node is not current node
 *                  PRA_LIST_EC_INVALID_PREVIOUS - previous node of next node is not current node
 *                  PRA_LIST_EC_INVALID_CURRENT - previous node and next node of current node is null
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_list_remove(
    pra_list_node *const p_node,
    PRA_EC_T *const      p_ec);

#endif