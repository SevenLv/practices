/*
 * pra_list_internal.h
 * created on Tue Sep 13 2022
 * created by Seven Lv
 * comments:    internal functions of pra_list
 * version: 0.3
 * history: #       date                modification
 *          0.1     Tue Sep 13 2022     created
 *          0.2     Tue Sep 13 2022     add pra_list_remove_ars_check function
 *          0.3     Wed Sep 14 2022     include pra_list_types.h
 *                                      include pra_boolean_types.h
 */

#ifndef INC_PRA_LIST_INTERNAL_H_
#define INC_PRA_LIST_INTERNAL_H_

/* includes */
#include "pra_boolean_types.h"
#include "pra_list_types.h"


/* macros */

/* types */

/* variables */

/* functions */

/**
 * @brief           arguments validation for pra_list_init function
 * @note
 * @param  p_node:  pointer of the node
 * @param  p_ec:    output error code:
 *                  PRA_LIST_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_list_init_args_check(
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
pra_boolean pra_list_append_args_check(
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
pra_boolean pra_list_insert_args_check(
    const pra_list_node *const p_cur_node,
    const pra_list_node *const p_pre_node,
    PRA_EC_T *const            p_ec);

/**
 * @brief           arguments validation for pra_list_remove function
 * @note
 * @param  p_node:  pointer of node
 * @param  p_ec:    output error code:
 *                  PRA_LIST_EC_NULL_PTR
 *                  PRA_LIST_EC_INVALID_NEXT - next node of previous node is not current node
 *                  PRA_LIST_EC_INVALID_PREVIOUS - previous node of next node is not current node
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_list_remove_args_check(
    const pra_list_node *const p_node,
    PRA_EC_T *const            p_ec);

#endif