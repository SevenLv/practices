#include "test_crc16.h"
#include "test.h"

int main(void);

int main(void)
{
    int result = err_none;

    result |= test_get(&pra_crc16_get_modbus);
    result |= test_init(&pra_crc16_get_modbus);
    result |= test_compute(&pra_crc16_get_modbus, 0x4B37U);

    return result;
}