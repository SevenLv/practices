/*
 * pra_task_internal.h
 * created on Thu Sep 15 2022
 * created by Seven Lv
 * comments:    internal function definitions of pra_task
 * version: 0.1
 * history: #       date                modification
 *          0.1     Thu Sep 15 2022     created
 */

#ifndef INC_PRA_TASK_INTERNAL_H_
#define INC_PRA_TASK_INTERNAL_H_

/* includes */
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
 *                  PRA_TASK_EC_NULL_PTR
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
 *                  PRA_TASK_EC_NULL_PTR
 *                  PRA_TASK_EC_INVALID_EXECUTE_FUNC
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_task_add_args_check(
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
 * @param  used_count:  used count
 * @param  p_task:      pointer of pra_task struct
 * @retval              PRA_BOOL_TRUE - exists; PRA_BOOL_FALSE - not exist
 */
pra_boolean pra_task_exists(
    const pra_list_node *const p_list,
    const uint32_t             used_count,
    const pra_task *const      p_task);

#endif