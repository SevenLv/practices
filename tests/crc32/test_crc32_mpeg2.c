#include "test.h"
#include "test_crc32.h"


int main(void);

int main(void)
{
    int result = err_none;

    result |= test_get(&pra_crc32_get_mpeg2);
    result |= test_init(&pra_crc32_get_mpeg2);
    result |= test_compute(&pra_crc32_get_mpeg2, 0x0376E6E7U);

    return result;
}