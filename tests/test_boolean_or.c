#include "pra_boolean.h"

int main(void);

int main(void)
{
    const int err_none = 0x0;
    const int err_error1 = 0x1;
    const int err_error2 = 0x2;
    const int err_error3 = 0x4;
    const int err_error4 = 0x8;
    const int err_error5 = 0x10;
    const int err_error6 = 0x20;
    const int err_error7 = 0x40;
    const int err_error8 = 0x80;
    const int err_error9 = 0x100;

    int result = err_none;

    pra_boolean expected = PRA_BOOL_TRUE;
    pra_boolean value1 = PRA_BOOL_TRUE;
    pra_boolean value2 = PRA_BOOL_TRUE;

    if (expected != pra_boolean_or(value1, value2))
    {
        result |= err_error1;
    }

    expected = PRA_BOOL_TRUE;
    value1 = PRA_BOOL_TRUE;
    value2 = PRA_BOOL_FALSE;

    if (expected != pra_boolean_or(value1, value2))
    {
        result |= err_error2;
    }

    expected = PRA_BOOL_TRUE;
    value1 = PRA_BOOL_TRUE;
    value2 = PRA_BOOL_UNKNOWN;

    if (expected != pra_boolean_or(value1, value2))
    {
        result |= err_error3;
    }

    expected = PRA_BOOL_TRUE;
    value1 = PRA_BOOL_FALSE;
    value2 = PRA_BOOL_TRUE;

    if (expected != pra_boolean_or(value1, value2))
    {
        result |= err_error4;
    }

    expected = PRA_BOOL_FALSE;
    value1 = PRA_BOOL_FALSE;
    value2 = PRA_BOOL_FALSE;

    if (expected != pra_boolean_or(value1, value2))
    {
        result |= err_error5;
    }

    expected = PRA_BOOL_FALSE;
    value1 = PRA_BOOL_FALSE;
    value2 = PRA_BOOL_UNKNOWN;

    if (expected != pra_boolean_or(value1, value2))
    {
        result |= err_error6;
    }

    expected = PRA_BOOL_TRUE;
    value1 = PRA_BOOL_UNKNOWN;
    value2 = PRA_BOOL_TRUE;

    if (expected != pra_boolean_or(value1, value2))
    {
        result |= err_error7;
    }

    expected = PRA_BOOL_FALSE;
    value1 = PRA_BOOL_UNKNOWN;
    value2 = PRA_BOOL_FALSE;

    if (expected != pra_boolean_or(value1, value2))
    {
        result |= err_error8;
    }

    expected = PRA_BOOL_FALSE;
    value1 = PRA_BOOL_UNKNOWN;
    value2 = PRA_BOOL_UNKNOWN;

    if (expected != pra_boolean_or(value1, value2))
    {
        result |= err_error9;
    }

    return result;
}