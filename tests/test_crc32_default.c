#include "test_crc32.h"
#include "test.h"

int main(void);

int main(void)
{
    int result = err_none;

    result |= test_get(&pra_crc32_get_default);
    result |= test_init(&pra_crc32_get_default);
    result |= test_compute(&pra_crc32_get_default, 0xCBF43926U);

    return result;
}