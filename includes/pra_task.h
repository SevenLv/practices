/*
 * pra_task.h
 * created on Thu Sep 15 2022
 * created by Seven Lv
 * comments:    function definitions of pra_task
 * version: 0.1
 * history: #       date                modification
 *          0.1     Thu Sep 15 2022     created
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

#endif