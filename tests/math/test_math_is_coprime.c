#include "pra_math.h"
#include "test.h"

int main(void);

int main(void)
{
    int result = err_none;

    uint32_t    a = 0U;
    uint32_t    b = 0U;
    pra_boolean expected_result = PRA_BOOL_UNKNOWN;

    expected_result = PRA_BOOL_FALSE;
    if (expected_result != pra_math_is_coprime(a, b))
    {
        result |= err_error1;
    }

    a = 1U;
    b = 0U;
    expected_result = PRA_BOOL_TRUE;
    if (expected_result != pra_math_is_coprime(a, b))
    {
        result |= err_error2;
    }

    a = 0U;
    b = 1U;
    expected_result = PRA_BOOL_TRUE;
    if (expected_result != pra_math_is_coprime(a, b))
    {
        result |= err_error3;
    }

    a = 2U;
    b = 0U;
    expected_result = PRA_BOOL_FALSE;
    if (expected_result != pra_math_is_coprime(a, b))
    {
        result |= err_error4;
    }

    a = 0U;
    b = 2U;
    expected_result = PRA_BOOL_FALSE;
    if (expected_result != pra_math_is_coprime(a, b))
    {
        result |= err_error5;
    }

    a = 1U;
    b = 1U;
    expected_result = PRA_BOOL_TRUE;
    if (expected_result != pra_math_is_coprime(a, b))
    {
        result |= err_error6;
    }

    a = 2 * 7;
    b = 3 * 7;
    expected_result = PRA_BOOL_FALSE;
    if (expected_result != pra_math_is_coprime(a, b))
    {
        result |= err_error7;
    }

    a = 7 * 11;
    b = 3 * 13;
    expected_result = PRA_BOOL_TRUE;
    if (expected_result != pra_math_is_coprime(a, b))
    {
        result |= err_error8;
    }

    return result;
}