/*
 * pra_math.h
 * created on Wed Oct 12 2022
 * created by Seven Lv
 * comments:    function definitions of math
 * version: 0.1
 * history: #       date                modification
 *          0.1     Wed Oct 12 2022     created
 */

#ifndef INC_PRA_MATH_H_
#define INC_PRA_MATH_H_

/* includes */
#include "pra_boolean_types.h"
#include "stdint.h"

/* macros */

/* types */

/* variables */

/* functions */

/**
 * @brief       determins two numbers are coprime
 * @note
 * @param  a:   the first number
 * @param  b:   the second number
 * @retval      PRA_BOOL_TRUE - are coprime; PRA_BOOL_FALSE - are NOT coprime
 */
pra_boolean pra_math_is_coprime(
    const uint32_t a,
    const uint32_t b);

#endif