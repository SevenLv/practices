#include "pra_types_def.h"

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

    BOOLEAN expected = TRUE;
    BOOLEAN value1 = TRUE;
    BOOLEAN value2 = TRUE;

    if (expected != BOOLEAN_XOR(value1, value2))
    {
        result |= err_error1;
    }

    expected = FALSE;
    value1 = TRUE;
    value2 = FALSE;

    if (expected != BOOLEAN_XOR(value1, value2))
    {
        result |= err_error2;
    }

    expected = FALSE;
    value1 = TRUE;
    value2 = BOOLEAN_UNKNOWN;

    if (expected != BOOLEAN_XOR(value1, value2))
    {
        result |= err_error3;
    }

    expected = FALSE;
    value1 = FALSE;
    value2 = TRUE;

    if (expected != BOOLEAN_XOR(value1, value2))
    {
        result |= err_error4;
    }

    expected = TRUE;
    value1 = FALSE;
    value2 = FALSE;

    if (expected != BOOLEAN_XOR(value1, value2))
    {
        result |= err_error5;
    }

    expected = TRUE;
    value1 = FALSE;
    value2 = BOOLEAN_UNKNOWN;

    if (expected != BOOLEAN_XOR(value1, value2))
    {
        result |= err_error6;
    }

    expected = FALSE;
    value1 = BOOLEAN_UNKNOWN;
    value2 = TRUE;

    if (expected != BOOLEAN_XOR(value1, value2))
    {
        result |= err_error7;
    }

    expected = TRUE;
    value1 = BOOLEAN_UNKNOWN;
    value2 = FALSE;

    if (expected != BOOLEAN_XOR(value1, value2))
    {
        result |= err_error8;
    }

    expected = TRUE;
    value1 = BOOLEAN_UNKNOWN;
    value2 = BOOLEAN_UNKNOWN;

    if (expected != BOOLEAN_XOR(value1, value2))
    {
        result |= err_error9;
    }

    return result;
}