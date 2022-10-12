/*
 * pra_math_gcd.c
 * created on Wed Oct 12 2022
 * created by Seven Lv
 * comments:    functions of greatest common divisor
 * version: 0.1
 * history: #       date                modification
 *          0.1     Wed Oct 12 2022     created
 */

/* includes */
#include "pra_math_gcd.h"
#include "pra_math_gcd_internal.h"
#include "pra_num_defs.h"

/* variables */

/* functions */

pra_boolean pra_math_gcd_euclid(
    const uint32_t  a,
    const uint32_t  b,
    PRA_EC_T *const p_ec,
    uint32_t *const p_gcd)
{
    pra_boolean result;

    if (PRA_EC_T_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_UINT32_NULL == p_gcd)
    {
        *p_ec |= PRA_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (a == b)
    {
        *p_gcd = a;
        result = PRA_BOOL_TRUE;
    }
    else
    {
        *p_gcd = pra_math_gcd_euclid_unsafe(a, b);
        result = PRA_BOOL_TRUE;
    }

    return result;
}

uint32_t pra_math_gcd_euclid_unsafe(
    const uint32_t a,
    const uint32_t b)
{
    uint32_t result;
    uint32_t temp_a;
    uint32_t temp_b;

    if (a > b)
    {
        temp_a = a;
        temp_b = b;
    }
    else
    {
        temp_a = b;
        temp_b = a;
    }

    if (PRA_NUM_ZERO_U == temp_b)
    {
        result = temp_a;
    }
    else
    {
        result = pra_math_gcd_euclid_unsafe(temp_b, temp_a % temp_b);
    }

    return result;
}