#include "pra_types_def.h"
#include "pra_boolean.h"
#include "stdio.h"

int main(void);

int main(void)
{
    BOOLEAN expected = TRUE;
    BOOLEAN value = TRUE;

    if (expected == BOOLEAN_IS_TRUE(value))
    {
        printf("success\r\n");
        return 1;
    }
    else
    {
        printf("failed\r\n");
        return 0;
    }
}