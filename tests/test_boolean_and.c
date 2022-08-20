#include "pra_types_def.h"

int main(void);

int main(void)
{
    const int err_none = 0x0;
    const int err_error1 = 0x1;
    const int err_error2 = 0x2;

    int result = err_none;

    BOOLEAN expected = TRUE;
    BOOLEAN value1 = TRUE;
    BOOLEAN value2 = TRUE;

    if (expected != BOOLEAN_AND(value1, value2))
    {
        result |= err_error1;
    }

    expected = FALSE;
    value1 = TRUE;
    value2 = FALSE;

    if (expected != BOOLEAN_AND(value1, value2))
    {
        result |= err_error2;
    }

    // TODO:

    return result;
}