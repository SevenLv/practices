#include "test.h"
#include "test_crc16.h"


int main(void);

int main(void)
{
    int result = err_none;

    result |= test_get(&pra_crc16_get_dnp);
    result |= test_init(&pra_crc16_get_dnp);
    result |= test_compute(&pra_crc16_get_dnp, 0xEA82U);

    return result;
}