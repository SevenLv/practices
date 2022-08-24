#include "pra_bytes.h"
#include "pra_defs.h"

int main(void);

int main(void)
{
    const int err_none = 0x0;
    const int err_error1 = 0x1;
    const int err_error2 = 0x2;
    const int err_error3 = 0x4;

    int result = err_none;

    uint8_t data[1] = {0};
    pra_bytes bytes = {
        .length = 1,
        .used_length = 0,
        .bytes = PRA_UINT8_NULL};

    pra_bytes *p_bytes = PRA_BYTES_NULL;
    pra_boolean expected = PRA_BOOL_FALSE;

    if (expected != pra_bytes_not_null_ptr(p_bytes))
    {
        result |= err_error1;
    }

    p_bytes = &bytes;
    expected = PRA_BOOL_FALSE;
    if (expected != pra_bytes_not_null_ptr(p_bytes))
    {
        result |= err_error2;
    }

    bytes.bytes = data;
    expected = PRA_BOOL_TRUE;
    if (expected != pra_bytes_not_null_ptr(p_bytes))
    {
        result |= err_error3;
    }

    return result;
}