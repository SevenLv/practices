#include "pra_types_def.h"

int main(void);

int main(void)
{
    const int err_none = 0x0;
    const int err_error1 = 0x1;
    const int err_error2 = 0x2;
    const int err_error3 = 0x4;

    int result = err_none;

    BOOLEAN expected = FALSE;
    BOOLEAN value = TRUE;

    if (expected != BOOLEAN_NOT(value))
    {
        result |= err_error1;
    }

    expected = TRUE;
    value = FALSE;

    if (expected != BOOLEAN_NOT(value))
    {
        result |= err_error2;
    }

    expected = TRUE;
    value = BOOLEAN_UNKNOWN;

    if (expected != BOOLEAN_NOT(value))
    {
        result |= err_error3;
    }

    return result;
}