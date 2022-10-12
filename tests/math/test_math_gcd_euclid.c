#include "pra_ec.h"
#include "pra_math_gcd.h"
#include "stdint.h"
#include "test.h"

int main(void);

int main(void)
{
    int result = err_none;

    uint32_t    a = PRA_NUM_ZERO_U;
    uint32_t    b = PRA_NUM_ZERO_U;
    uint32_t    expected_gcd = PRA_NUM_ZERO_U;
    uint32_t    actual_gcd = PRA_NUM_ZERO_U;
    uint32_t   *p_gcd = &actual_gcd;
    pra_boolean expected_result = PRA_BOOL_UNKNOWN;
    PRA_EC_T    expected_ec = PRA_EC_NONE;
    PRA_EC_T    actual_ec = PRA_EC_NONE;

    expected_result = PRA_BOOL_FALSE;
    if (expected_result != pra_math_gcd_euclid(
                               a,
                               b,
                               PRA_EC_T_NULL,
                               p_gcd))
    {
        result |= err_error1;
    }

    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_EC_NULL_PTR;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_math_gcd_euclid(
                               a,
                               b,
                               &actual_ec,
                               PRA_UINT32_NULL) ||
        expected_ec != actual_ec)
    {
        result |= err_error2;
    }

    a = 1U;
    b = PRA_NUM_ZERO_U;
    expected_gcd = a;
    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_EC_NONE;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_math_gcd_euclid(
                               a, b,
                               &actual_ec,
                               p_gcd) ||
        expected_ec != actual_ec ||
        expected_gcd != actual_gcd)
    {
        result |= err_error3;
    }

    a = PRA_NUM_ZERO_U;
    b = 1U;
    expected_gcd = b;
    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_EC_NONE;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_math_gcd_euclid(
                               a, b,
                               &actual_ec,
                               p_gcd) ||
        expected_ec != actual_ec ||
        expected_gcd != actual_gcd)
    {
        result |= err_error4;
    }

    a = 10U;
    b = a;
    expected_gcd = a;
    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_EC_NONE;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_math_gcd_euclid(
                               a, b,
                               &actual_ec,
                               p_gcd) ||
        expected_ec != actual_ec ||
        expected_gcd != actual_gcd)
    {
        result |= err_error5;
    }

    a = 100 * 3 * 7 * 9;
    b = 100 * 11 * 17 * 19;
    expected_gcd = 100U;
    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_EC_NONE;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_math_gcd_euclid(
                               a, b,
                               &actual_ec,
                               p_gcd) ||
        expected_ec != actual_ec ||
        expected_gcd != actual_gcd)
    {
        result |= err_error6;
    }

    return result;
}
