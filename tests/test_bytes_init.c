#include "pra_bytes.h"

int main(void);

int main(void)
{
    const int err_none = 0x0;
    const int err_error1 = 0x1;
    const int err_error2 = 0x2;
    const int err_error3 = 0x4;

    int result = err_none;

    uint8_t data[10] = {0xFF};

    pra_bytes bytes = {
        .length = 10,
        .used_length = 10,
        .bytes = data};

    pra_bytes *p_bytes = PRA_BYTES_NULL;
    pra_boolean expected = PRA_BOOL_FALSE;

    if (expected != pra_bytes_init(p_bytes))
    {
        result |= err_error1;
    }

    p_bytes = &bytes;
    expected = PRA_BOOL_TRUE;
    if (expected != pra_bytes_init(p_bytes))
    {
        result |= err_error2;
    }
    else
    {
        for (uint16_t i = 0U; i < bytes.used_length; i++)
        {
            if (0U != bytes.bytes[i])
            {
                result |= err_error3;
                break;
            }
        }
    }

    return result;
}