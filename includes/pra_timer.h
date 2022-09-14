/*
 * pra_timer.h
 * created on Wed Sep 14 2022
 * created by Seven Lv
 * comments:    function definitions of pra_timer
 * version: 0.2
 * history: #       date                modification
 *          0.1     Wed Sep 14 2022     created
 *          0.2     Wed Sep 14 2022     add pra_timer_is_done function declaration
 *                                      add pra_timer_stop function declaration
 *                                      add pra_timer_init function declaration
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
 * @brief           initialize a pra_timer struct
 * @note
 * @param  p_timer: pointer of the pra_timer struct
 * @param  p_ec:    output error code:
 *                  PRA_TIMER_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_timer_init(
    pra_timer *const p_timer,
    PRA_EC_T *const  p_ec);

/**
 * @brief   pra_timer main function
 * @note    this function should be invoked periodically, current time will be increase 1
 * @retval  PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_timer_execute(void);

/**
 * @brief           start a timer
 * @note
 * @param  p_timer: pointer of the pra_timer struct
 * @param  p_ec:    output error code:
 *                  PRA_TIMER_EC_NULL_PTR
 *                  PRA_TIMER_EC_INVALID_INTERVAL - 0U == interval
 *                  PRA_TIMER_EC_ALREADY_STARTED - PRA_BOOL_TRUE == actived
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_timer_start(
    pra_timer *const p_timer,
    PRA_EC_T *const  p_ec);

/**
 * @brief           determins whether a timer reached it's interval
 * @note
 * @param  p_timer: pointer of the pra_timer struct
 * @param  p_done:  output the result, PRA_TRUE_BOOL for done, or not
 * @param  p_ec:    output error code:
 *                  PRA_TIMER_EC_NULL_PTR
 *                  PRA_TIMER_EC_NOT_STARTED
 *                  PRA_TIMER_EC_CALCULATION_FAILED
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_timer_is_done(
    const pra_timer *const p_timer,
    pra_boolean *const     p_done,
    PRA_EC_T *const        p_ec);

/**
 * @brief           stop a timer
 * @note
 * @param  p_timer: pointer of the pra_timer struct
 * @param  p_ec:    output error code:
 *                  PRA_TIMER_EC_NULL_PTR
 *                  PRA_TIMER_EC_NOT_STARTED
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_timer_stop(
    pra_timer *const p_timer,
    PRA_EC_T *const  p_ec);

#endif