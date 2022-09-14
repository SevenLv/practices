/*
 * pra_timer.h
 * created on Wed Sep 14 2022
 * created by Seven Lv
 * comments:    function definitions of pra_timer
 * version: 0.1
 * history: #       date                modification
 *          0.1     Wed Sep 14 2022     created
 */

#ifndef INC_PRA_TIMER_H_
#define INC_PRA_TIMER_H_

/* includes */
#include "pra_timer_types.h"

/* macros */

/* types */

/* variables */

/* functions */

/**
 * @brief           get current time
 * @note
 * @param  p_time:  current time
 * @param  p_ec:    output error code:
 *                  PRA_TIMER_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_timer_get_time(
    uint32_t *const p_time,
    PRA_EC_T *const p_ec);

/**
 * @brief   pra_timer main function
 * @note    this function should be invoked periodically, current time will be increase 1
 * @retval  PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_timer_execute(void);

#endif