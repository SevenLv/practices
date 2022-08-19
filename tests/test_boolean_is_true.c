#include "pra_types_def.h"
#include "pra_boolean.h"
#include "stdio.h"

int main(void);

int main(void)
{
    const char err_none = 0U;
    const char err_error1 = 1U;

    BOOLEAN expected = TRUE;
    BOOLEAN value = TRUE;

    if (expected == BOOLEAN_IS_TRUE(value))
    {
        return err_none;
    }
    else
    {
        return err_error1;
    }
}