#include "test.h"
#include "pra_boolean.h"
#include "stdint.h"

uint32_t main(void);

uint32_t main(void)
{
    int result = err_none;

    pra_boolean expected = PRA_BOOL_TRUE;
    pra_boolean value = PRA_BOOL_TRUE;

    if (expected != pra_boolean_is_true(value))
    {
        result |= err_error1;
    }

    expected = PRA_BOOL_FALSE;
    value = PRA_BOOL_FALSE;

    if (expected != pra_boolean_is_true(value))
    {
        result |= err_error2;
    }

    expected = PRA_BOOL_FALSE;
    value = PRA_BOOL_UNKNOWN;

    if (expected != pra_boolean_is_true(value))
    {
        result |= err_error3;
    }

    return result;
}