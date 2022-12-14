/*
 * pra_task.h
 * created on Thu Sep 15 2022
 * created by Seven Lv
 * comments:    function definitions of pra_task
 * version: 0.4
 * history: #       date                modification
 *          0.1     Thu Sep 15 2022     created
 *          0.2     Thu Sep 15 2022     add new error code to pra_task_add
 *          0.3     Thu Sep 15 2022     add pra_task_remove function declaration
 *          0.4     Thu Sep 29 2022     reorganize error codes
 */

#ifndef INC_PRA_TASK_H_
#define INC_PRA_TASK_H_

/* includes */
#include "pra_ec.h"
#include "pra_task_types.h"

/* macros */

/* types */

/* variables */

/* functions */

/**
 * @brief           initialize a pra_task struct
 * @note
 * @param  p_task:  pointer of the pra_task struct
 * @param  p_ec:    output error code:
 *                  PRA_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_task_init(
    pra_task *const p_task,
    PRA_EC_T *const p_ec);

/**
 * @brief   pra_task main function
 * @note    this function should be invoked periodically, pra_task will invoke execute function of each task
 * @retval  PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_task_execute(void);

/**
 * @brief           add a task
 * @note
 * @param  p_task:  pointer of the pra_task struct
 * @param  p_ec:    output error code:
 *                  PRA_EC_NULL_PTR
 *                  PRA_EC_INVALID_EXECUTE_FUNC
 *                  PRA_EC_TASK_LIST_FULL
 *                  PRA_EC_ALREADY_ADDED
 *                  PRA_EC_FIND_UNUSED_NODE_FAILED
 *                  PRA_EC_INSERT_NODE_FAILED
 *                  PRA_EC_APPEND_NODE_FAILED
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_task_add(
    pra_task *const p_task,
    PRA_EC_T *const p_ec);

/**
 * @brief           remove a task
 * @note
 * @param  p_task:  pointer of the pra_task struct
 * @param  p_ec:    output error code:
 *                  PRA_EC_NULL_PTR
 *                  PRA_EC_NEVER_ADDED
 *                  PRA_EC_REMOVE_NODE_FAILED
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_task_remove(
    pra_task *const p_task,
    PRA_EC_T *const p_ec);

#endif