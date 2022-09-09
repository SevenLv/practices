#include "test.h"
#include "test_crc8.h"


int main(void);

int main(void)
{
    int result = err_none;

    result |= test_get(&pra_crc8_get_itu);
    result |= test_init(&pra_crc8_get_itu);
    result |= test_compute(&pra_crc8_get_itu, 0xA1);

    return result;
}