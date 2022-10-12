/*
 * pra_math_gcd.h
 * created on Wed Oct 12 2022
 * created by Seven Lv
 * comments:    function definitions of greatest common divisor
 * version: 0.1
 * history: #       date                modification
 *          0.1     Wed Oct 12 2022     created
 */

#ifndef INC_MATH_GCD_H_
#define INC_MATH_GCD_H_

/* includes */
#include "pra_boolean_types.h"
#include "pra_ec.h"
#include "stdint.h"

/* macros */

/* types */

/* variables */

/* functions */

/**
 * @brief           calculate gcd
 * @note            Euclid's algorithm
 * @param  a:       the first value
 * @param  b:       the second value
 * @param  p_ec:    output error codes
 * @param  p_gcd:   the gcd
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_math_gcd_euclid(
    const uint32_t  a,
    const uint32_t  b,
    PRA_EC_T *const p_ec,
    uint32_t *const p_gcd);

#endif