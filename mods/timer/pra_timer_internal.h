/*
 * pra_timer_internal.h
 * created on Wed Sep 14 2022
 * created by Seven Lv
 * comments:    internal function definitions of pra_timer
 * version: 0.3
 * history: #       date                modification
 *          0.1     Wed Sep 14 2022     created
 *          0.2     Wed Sep 14 2022     add pra_timer_is_done_args_check function declaration
 *                                      add function comments
 *                                      add pra_timer_increase function declaration
 *                                      add pra_timer_stop_args_check function declaration
 *                                      add pra_timer_init_args_check function declaration
 *          0.3     Thu Sep 15 2022     include pra_ec.h
 */

#ifndef INC_PRA_TIMER_INTERNAL_H_
#define INC_PRA_TIMER_INTERNAL_H_

/* includes */
#include "pra_boolean_types.h"
#include "pra_defs.h"
#include "pra_ec.h"
#include "pra_timer_types.h"
#include "stdint.h"


/* macros */

#define PRA_TIME_MIN  PRA_NUM_ZERO_U
#define PRA_TIME_MAX  PRA_NUM_MAX_VALUE_U32
#define PRA_TIME_STEP 1U

/* types */

/* variables */

/* functions */

/**
 * @brief               increase current value with the step
 * @note                start from 0 when reach max value
 * @param  p_value:     pointer of the value
 * @param  step:        the step
 * @retval              PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_timer_increase(
    uint32_t *const p_value,
    const uint32_t  step);

/**
 * @brief           arguments validation for pra_timer_init function
 * @note
 * @param  p_timer: pointer of the pra_timer struct
 * @param  p_ec:    output error code:
 *                  PRA_TIMER_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_timer_init_args_check(
    const pra_timer *const p_timer,
    PRA_EC_T *const        p_ec);

/**
 * @brief           arguments validation for pra_timer_get_time function
 * @note
 * @param  p_time:  pointer of pra_timer struct
 * @param  p_ec:    output error code:
 *                  PRA_TIMER_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_timer_get_time_args_check(
    const uint32_t *const p_time,
    PRA_EC_T *const       p_ec);

/**
 * @brief           arguments validation for pra_timer_start function
 * @note
 * @param  p_timer: pointer of the pra_timer struct
 * @param  p_ec:    output error code:
 *                  PRA_TIMER_EC_NULL_PTR
 *                  PRA_TIMER_EC_INVALID_INTERVAL - 0U == interval
 *                  PRA_TIMER_EC_ALREADY_STARTED - PRA_BOOL_TRUE == actived
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_timer_start_args_check(
    const pra_timer *const p_timer,
    PRA_EC_T *const        p_ec);

/**
 * @brief           arguments validation for pra_timer_is_done function
 * @note
 * @param  p_timer: pointer of the pra_timer struct
 * @param  p_done:  output the result, PRA_TRUE_BOOL for done, or not
 * @param  p_ec:    output error code:
 *                  PRA_TIMER_EC_NULL_PTR
 *                  PRA_TIMER_EC_NOT_STARTED
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_timer_is_done_args_check(
    const pra_timer *const   p_timer,
    const pra_boolean *const p_done,
    PRA_EC_T *const          p_ec);

/**
 * @brief           arguments validation for pra_timer_stop function
 * @note
 * @param  p_timer: pointer of the pra_timer struct
 * @param  p_ec:    output error code:
 *                  PRA_TIMER_EC_NULL_PTR
 *                  PRA_TIMER_EC_NOT_STARTED
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_timer_stop_args_check(
    const pra_timer *const p_timer,
    PRA_EC_T *const        p_ec);

#endif