/*
 * pra_math_gcd_internal.h
 * created on Wed Oct 12 2022
 * created by Seven Lv
 * comments:    internal definitions of greatest common divisor
 * version: 0.1
 * history: #       date                modification
 *          0.1     Wed Oct 12 2022     created
 */

#ifndef INC_MATH_GCD_INTERNAL_H_
#define INC_MATH_GCD_INTERNAL_H_

/* includes */
#include "pra_boolean_types.h"
#include "stdint.h"

/* macros */

#define PRA_MATH_GCD_MIN_FACTOR 1U

/* types */

/* variables */

/* functions */

/**
 * @brief       calculate greatest common divisor
 * @note        euclid's algorithm
 * @param  a:   the first value
 * @param  b:   the second value
 * @retval      the gcd
 */
uint32_t pra_math_gcd_euclid_unsafe(
    const uint32_t a,
    const uint32_t b);

#endif