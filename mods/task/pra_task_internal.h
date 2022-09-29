/*
 * pra_task_internal.h
 * created on Thu Sep 15 2022
 * created by Seven Lv
 * comments:    internal function definitions of pra_task
 * version: 0.4
 * history: #       date                modification
 *          0.1     Thu Sep 15 2022     created
 *          0.2     Thu Sep 15 2022     add pra_task_remove_args_check function declaration
 *                                      add pra_task_find_node function declaration
 *          0.3     Fri Sep 16 2022     changed parameter type of pra_task_find_node function
 *          0.4     Thu Sep 29 2022     reorganize error codes
 */

#ifndef INC_PRA_TASK_INTERNAL_H_
#define INC_PRA_TASK_INTERNAL_H_

/* includes */
#include "pra_ec.h"
#include "pra_list_types.h"
#include "pra_task_types.h"


/* macros */
#define PRA_TASK_LIST_MAX_COUNT 0x100U

/* types */

/* variables */

/* functions */

/**
 * @brief           arguments validation for pra_task_init
 * @note
 * @param  p_task:  pointer of the pra_task struct
 * @param  p_ec:    output error code:
 *                  PRA_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_task_init_args_check(
    const pra_task *const p_task,
    PRA_EC_T *const       p_ec);

/**
 * @brief           arguments validation for pra_task_add
 * @note
 * @param  p_task:  pointer of the pra_task struct
 * @param  p_ec:    output error code:
 *                  PRA_EC_NULL_PTR
 *                  PRA_EC_INVALID_EXECUTE_FUNC
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_task_add_args_check(
    const pra_task *const p_task,
    PRA_EC_T *const       p_ec);

/**
 * @brief           arguments validation for pra_task_remove
 * @note
 * @param  p_task:  pointer of the pra_task struct
 * @param  p_ec:    output error code:
 *                  PRA_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_task_remove_args_check(
    const pra_task *const p_task,
    PRA_EC_T *const       p_ec);

/**
 * @brief               find first unused node
 * @note
 * @param  p_nodes[]:   all nodes
 * @param  p_index:     output unused node index
 * @retval              PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_task_find_first_unused_node(
    const pra_list_node p_nodes[],
    uint32_t *const     p_index);

/**
 * @brief               determines whether a task exists
 * @note
 * @param  p_list:      pointer of task list
 * @param  used_count:  length of task list
 * @param  p_task:      pointer of pra_task struct
 * @retval              PRA_BOOL_TRUE - exists; PRA_BOOL_FALSE - not exist
 */
pra_boolean pra_task_exists(
    const pra_list_node *const p_list,
    const uint32_t             used_count,
    const pra_task *const      p_task);

/**
 * @brief               finde a node with the task
 * @note
 * @param  p_list:      pointer of task list
 * @param  used_count:  length of task list
 * @param  p_task:      pointer of pra_task struct
 * @param  *p_node:     output the found node
 * @retval              PRA_BOOL_TRUE - found; PRA_BOOL_FALSE - not found
 */
pra_boolean pra_task_find_node(
    pra_list_node *const  p_list,
    const uint32_t        used_count,
    const pra_task *const p_task,
    pra_list_node       **p_node);

#endif