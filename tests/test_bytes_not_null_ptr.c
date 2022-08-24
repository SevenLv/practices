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
        .data = PRA_UINT8_NULL};

    pra_bytes *p_bytes = PRA_BYTES_NULL;
    pra_bytes_ec actual_ec = PRA_BYTES_EC_NONE;
    pra_bytes_ec expected_ec = PRA_BYTES_EC_NULL_PTR;
    pra_boolean expected = PRA_BOOL_FALSE;

    if (expected != pra_bytes_not_null_ptr(p_bytes, &actual_ec)||
        expected_ec != actual_ec)
    {
        result |= err_error1;
    }

    p_bytes = &bytes;
    actual_ec = PRA_BYTES_EC_NONE;
    expected_ec = PRA_BYTES_EC_NULL_DATA_PTR;
    expected = PRA_BOOL_FALSE;
    if (expected != pra_bytes_not_null_ptr(p_bytes, &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error2;
    }

    bytes.data = data;
    actual_ec = PRA_BYTES_EC_NONE;
    expected_ec = PRA_BYTES_EC_NONE;
    expected = PRA_BOOL_TRUE;
    if (expected != pra_bytes_not_null_ptr(p_bytes, &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error3;
    }

    return result;
}