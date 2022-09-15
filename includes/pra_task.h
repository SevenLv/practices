/*
 * pra_task.h
 * created on Thu Sep 15 2022
 * created by Seven Lv
 * comments:    function definitions of pra_task
 * version: 0.2
 * history: #       date                modification
 *          0.1     Thu Sep 15 2022     created
 *          0.2     Thu Sep 15 2022     add new error code to pra_task_add
 */

#ifndef INC_PRA_TASK_H_
#define INC_PRA_TASK_H_

/* includes */
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
 *                  PRA_TASK_EC_NULL_PTR
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
 *                  PRA_TASK_EC_NULL_PTR
 *                  PRA_TASK_EC_INVALID_EXECUTE_FUNC
 *                  PRA_TASK_EC_TASK_LIST_FULL
 *                  PRA_TASK_EC_ALREADY_ADDED
 *                  PRA_TASK_EC_FIND_UNUSED_NODE_FAILED
 *                  PRA_TASK_EC_INSERT_NODE_FAILED
 *                  PRA_TASK_EC_APPEND_NODE_FAILED
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_task_add(
    pra_task *const p_task,
    PRA_EC_T *const p_ec);

#endif