#include "pra_boolean.h"

int main(void);

int main(void)
{
    const int err_none = 0x0;
    const int err_error1 = 0x1;
    const int err_error2 = 0x2;
    const int err_error3 = 0x4;

    int result = err_none;

    pra_boolean expected = PRA_BOOL_FALSE;
    pra_boolean value = PRA_BOOL_TRUE;

    if (expected != pra_boolean_not(value))
    {
        result |= err_error1;
    }

    expected = PRA_BOOL_TRUE;
    value = PRA_BOOL_FALSE;

    if (expected != pra_boolean_not(value))
    {
        result |= err_error2;
    }

    expected = PRA_BOOL_TRUE;
    value = PRA_BOOL_UNKNOWN;

    if (expected != pra_boolean_not(value))
    {
        result |= err_error3;
    }

    return result;
}