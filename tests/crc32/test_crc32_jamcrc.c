#include "test_crc32.h"
#include "test.h"

int main(void);

int main(void)
{
    int result = err_none;

    result |= test_get(&pra_crc32_get_jamcrc);
    result |= test_init(&pra_crc32_get_jamcrc);
    result |= test_compute(&pra_crc32_get_jamcrc, 0x340BC6D9U);

    return result;
}