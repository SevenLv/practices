/*
 * pra_math.c
 * created on Wed Oct 12 2022
 * created by Seven Lv
 * comments:    functions of math
 * version: 0.1
 * history: #       date                modification
 *          0.1     Wed Oct 12 2022     created
 */

/* includes */
#include "pra_math.h"
#include "pra_math_gcd_internal.h"

/* variables */

/* functions */

pra_boolean pra_math_is_coprime(
    const uint32_t a,
    const uint32_t b)
{
    pra_boolean result;

    if (PRA_MATH_GCD_MIN_FACTOR == pra_math_gcd_euclid_unsafe(a, b))
    {
        result = PRA_BOOL_TRUE;
    }
    else
    {
        result = PRA_BOOL_FALSE;
    }

    return result;
}