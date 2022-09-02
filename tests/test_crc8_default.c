#include "test_crc8.h"
#include "test.h"

int main(void);

int main(void)
{
    int result = err_none;

    result |= test_get(&pra_crc8_get_default);
    result |= test_init(&pra_crc8_get_default);
    result |= test_compute(&pra_crc8_get_default);

    return result;
}