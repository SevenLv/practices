#include "test.h"
#include "pra_bytes.h"
#include "pra_defs.h"

uint32_t main(void);

uint32_t main(void)
{
    int result = err_none;

    uint8_t src[10] = {1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U};
    uint8_t dst[10] = {0U};
    pra_bytes src_bytes = {
        .length = 10,
        .used_length = 10,
        .data = src};
    pra_bytes dst_bytes = {
        .length = 10,
        .used_length = 0,
        .data = dst};
    uint32_t actual_ec = PRA_BYTES_EC_NONE;
    uint32_t expected_ec = PRA_BYTES_EC_NONE;
    pra_boolean expected_result = PRA_BOOL_UNKNOWN;

    actual_ec = PRA_BYTES_EC_NONE;
    expected_ec = PRA_BYTES_EC_NULL_PTR;
    expected_result = PRA_BOOL_FALSE;
    if (expected_result != pra_bytes_copy(
                               PRA_BYTES_NULL,
                               &dst_bytes,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error1;
    }

    actual_ec = PRA_BYTES_EC_NONE;
    expected_ec = PRA_BYTES_EC_NULL_PTR;
    expected_result = PRA_BOOL_FALSE;
    if (expected_result != pra_bytes_copy(
                               &src_bytes,
                               PRA_BYTES_NULL,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error2;
    }

    actual_ec = PRA_BYTES_EC_NONE;
    expected_ec = PRA_BYTES_EC_NULL_PTR;
    expected_result = PRA_BOOL_FALSE;
    if (expected_result != pra_bytes_copy(
                               &src_bytes,
                               &dst_bytes,
                               PRA_UINT32_NULL))
    {
        result |= err_error3;
    }

    src_bytes.data = PRA_UINT8_NULL;
    dst_bytes.data = PRA_UINT8_NULL;
    actual_ec = PRA_BYTES_EC_NONE;
    expected_ec = PRA_BYTES_EC_NULL_DATA_PTR;
    expected_result = PRA_BOOL_FALSE;
    if (expected_result != pra_bytes_copy(
                               &src_bytes,
                               &dst_bytes,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error4;
    }

    src_bytes.data = src;
    dst_bytes.data = dst;
    src_bytes.length = 0;
    dst_bytes.length = 0;
    actual_ec = PRA_BYTES_EC_NONE;
    expected_ec = PRA_BYTES_EC_DATA_LENGTH_ZERO;
    expected_result = PRA_BOOL_FALSE;
    if (expected_result != pra_bytes_copy(
                               &src_bytes,
                               &dst_bytes,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error5;
    }

    src_bytes.data = src;
    dst_bytes.data = dst;
    src_bytes.length = 1;
    dst_bytes.length = 2;
    actual_ec = PRA_BYTES_EC_NONE;
    expected_ec = PRA_BYTES_EC_DIFFERENT_LENGTH;
    expected_result = PRA_BOOL_FALSE;
    if (expected_result != pra_bytes_copy(
                               &src_bytes,
                               &dst_bytes,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error6;
    }

    src_bytes.length = 10;
    dst_bytes.length = 10;
    actual_ec = PRA_BYTES_EC_NONE;
    expected_ec = PRA_BYTES_EC_NONE;
    expected_result = PRA_BOOL_TRUE;
    if (expected_result != pra_bytes_copy(
                               &src_bytes,
                               &dst_bytes,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error7;
    }
    else
    {
        if (src_bytes.used_length != dst_bytes.used_length)
        {
            result |= err_error8;
        }
        else
        {
            for (uint16_t i = 0; i < src_bytes.length; i++)
            {
                if (src[i] != dst[i])
                {
                    result |= err_error9;
                    break;
                }
            }
        }
    }

    return result;
}