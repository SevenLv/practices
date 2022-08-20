#include "pra_types_def.h"
#include "pra_boolean.h"
#include "stdio.h"

int main(void);

int main(void)
{
    const int err_none = 0x0U;
    const int err_error1 = 0x1;
    const int err_error2 = 0x2;
    const int err_error3 = 0x4;

    int result = err_none;

    BOOLEAN expected = TRUE;
    BOOLEAN value = TRUE;

    if (expected != BOOLEAN_IS_TRUE(value))
    {
        result |= err_error1;
    }

    expected = FALSE;
    value = FALSE;

    if (expected != BOOLEAN_IS_TRUE(value))
    {
        result |= err_error2;
    }

    expected = FALSE;
    value = BOOLEAN_UNKNOWN;

    if (expected != BOOLEAN_IS_TRUE(value))
    {
        result |= err_error3;
    }

    return result;
}