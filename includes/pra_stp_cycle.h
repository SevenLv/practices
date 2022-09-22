/*
 * pra_stp_cycle.h
 * created on Thu Sep 22 2022
 * created by Seven Lv
 * comments:    function definitions of cycle stepper
 * version: 0.1
 * history: #       date                modification
 *          0.1     Thu Sep 22 2022     created
 */

#ifndef INC_PRA_STP_CYCLE_H_
#define INC_PRA_STP_CYCLE_H_

/* includes */
#include "pra_boolean.h"
#include "pra_ec.h"
#include "stdint.h"

/* macros */

/* types */

/* variables */

/* functions */

/**
 * @brief               step a 8-bits value forward
 * @note                range: [min_value, max_value]
 * @param  p_value:     the 8-bits value
 * @param  min_value:   the min value
 * @param  max_value:   the max value
 * @param  step:        the step
 * @param  p_ec:        output error code:
 *                      PRA_STP_CYCLE_EC_NULL_PTR
 *                      PRA_STP_CYCLE_EC_INVALID_RANGE - the min value is greater than or equal to the max value
 *                      PRA_STP_CYCLE_EC_VALUE_OUT_OF_RANGE - the 8-bits value is greater than the max value or less than the min value
 *                      PRA_STP_CYCLE_EC_INVALID_STEP - step is greater than max value or is equal to zero
 * @retval              PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_stp_cycle_u8(
    uint8_t *const  p_value,
    const uint8_t   min_value,
    const uint8_t   max_value,
    const uint8_t   step,
    PRA_EC_T *const p_ec);

/**
 * @brief           step a 8-bits value forward
 * @note            range: [0x00U, 0xFFU], step: 1
 * @param  p_value: the 8-bits value
 * @param  p_ec:    output error code:
 *                  PRA_STP_CYCLE_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_stp_cycle_max_u8(
    uint8_t *const  p_value,
    PRA_EC_T *const p_ec);


#endif