#include "test.h"
#include "test_crc16.h"


int main(void);

int main(void)
{
    int result = err_none;

    result |= test_get(&pra_crc16_get_xmodem);
    result |= test_init(&pra_crc16_get_xmodem);
    result |= test_compute(&pra_crc16_get_xmodem, 0x31C3U);

    return result;
}