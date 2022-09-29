#include "pra_bytes.h"
#include "pra_defs.h"
#include "pra_ec.h"
#include "test.h"


int main(void);

int main(void)
{
    int result = err_none;

    uint8_t   data[10] = { 1U, 2U, 3U, 4U, 5U };
    uint8_t   data_to_append[5] = { 6U, 7U, 8U, 9U, 10U };
    uint16_t  data_to_append_length = 5;
    pra_bytes bytes = {
        .length = 10,
        .used_length = 5,
        .data = data
    };
    pra_bytes  *p_bytes = PRA_BYTES_NULL;
    uint32_t    actual_ec = PRA_EC_NONE;
    uint32_t    expected_ec = PRA_EC_NONE;
    pra_boolean expected_result = PRA_BOOL_UNKNOWN;

    actual_ec = PRA_EC_NONE;
    expected_ec = PRA_EC_NULL_PTR;
    expected_result = PRA_BOOL_FALSE;
    if (expected_result != pra_bytes_append_u8_array(
                               PRA_BYTES_NULL,
                               data_to_append,
                               data_to_append_length,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error1;
    }

    bytes.data = PRA_UINT8_NULL;
    p_bytes = &bytes;
    actual_ec = PRA_EC_NONE;
    expected_ec = PRA_EC_NULL_PTR;
    expected_result = PRA_BOOL_FALSE;
    if (expected_result != pra_bytes_append_u8_array(
                               p_bytes,
                               data_to_append,
                               data_to_append_length,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error2;
    }

    bytes.data = data;
    actual_ec = PRA_EC_NONE;
    expected_ec = PRA_EC_NULL_PTR;
    expected_result = PRA_BOOL_FALSE;
    if (expected_result != pra_bytes_append_u8_array(
                               p_bytes,
                               PRA_UINT8_NULL,
                               data_to_append_length,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error3;
    }

    data_to_append_length = 6;
    actual_ec = PRA_EC_NONE;
    expected_ec = PRA_EC_NOT_ENOUGH_LENGTH;
    expected_result = PRA_BOOL_FALSE;
    if (expected_result != pra_bytes_append_u8_array(
                               p_bytes,
                               data_to_append,
                               data_to_append_length,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error4;
    }

    data_to_append_length = 5;
    actual_ec = PRA_EC_NONE;
    expected_ec = PRA_EC_NONE;
    expected_result = PRA_BOOL_TRUE;
    if (expected_result != pra_bytes_append_u8_array(
                               p_bytes,
                               data_to_append,
                               data_to_append_length,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error5;
    }
    else
    {
        if (10 != bytes.used_length)
        {
            result |= err_error6;
        }
        else
        {
            for (uint16_t i = 5U; i < 10U; i++)
            {
                if (data_to_append[i - 5U] != data[i])
                {
                    result |= err_error7;
                    break;
                }
            }
        }
    }

    return result;
}