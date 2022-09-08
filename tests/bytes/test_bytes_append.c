#include "pra_bytes.h"
#include "pra_defs.h"
#include "test.h"

int main(void);

int main(void)
{
    int result = err_none;

    uint8_t data1[10] = {1U, 2U, 3U, 4U, 5U};
    uint8_t data2[10] = {6U, 7U, 8U, 9U, 10U};
    pra_bytes bytes1 = {
        .length = 10,
        .used_length = 5,
        .data = data1};
    pra_bytes bytes2 = {
        .length = 10,
        .used_length = 5,
        .data = data2};
    pra_bytes *p_bytes1 = &bytes1;
    pra_bytes *p_bytes2 = &bytes2;
    uint32_t actual_ec = PRA_BYTES_EC_NONE;
    uint32_t expected_ec = PRA_BYTES_EC_NONE;
    pra_boolean expected_result = PRA_BOOL_UNKNOWN;

    actual_ec = PRA_BYTES_EC_NONE;
    expected_ec = PRA_BYTES_EC_NULL_PTR;
    expected_result = PRA_BOOL_FALSE;
    if (expected_result != pra_bytes_append(
                               PRA_BYTES_NULL,
                               p_bytes2,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error1;
    }

    actual_ec = PRA_BYTES_EC_NONE;
    expected_ec = PRA_BYTES_EC_NULL_PTR;
    expected_result = PRA_BOOL_FALSE;
    if (expected_result != pra_bytes_append(
                               p_bytes1,
                               PRA_BYTES_NULL,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error2;
    }

    p_bytes1->data = PRA_UINT8_NULL;
    actual_ec = PRA_BYTES_EC_NONE;
    expected_ec = PRA_BYTES_EC_NULL_DATA_PTR;
    expected_result = PRA_BOOL_FALSE;
    if (expected_result != pra_bytes_append(
                               p_bytes1,
                               p_bytes2,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error3;
    }

    p_bytes1->data = data1;
    p_bytes2->data = PRA_UINT8_NULL;
    actual_ec = PRA_BYTES_EC_NONE;
    expected_ec = PRA_BYTES_EC_NULL_DATA_PTR;
    expected_result = PRA_BOOL_FALSE;
    if (expected_result != pra_bytes_append(
                               p_bytes1,
                               p_bytes2,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error4;
    }

    p_bytes2->data = data2;
    p_bytes2->used_length = 10;
    actual_ec = PRA_BYTES_EC_NONE;
    expected_ec = PRA_BYTES_EC_NOT_ENOUGH_LENGTH;
    expected_result = PRA_BOOL_FALSE;
    if (expected_result != pra_bytes_append(
                               p_bytes1,
                               p_bytes2,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error5;
    }

    p_bytes2->used_length = 5;
    actual_ec = PRA_BYTES_EC_NONE;
    expected_ec = PRA_BYTES_EC_NONE;
    expected_result = PRA_BOOL_TRUE;
    if (expected_result != pra_bytes_append(
                               p_bytes1,
                               p_bytes2,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error6;
    }
    else
    {
        if (10 != p_bytes1->used_length)
        {
            result |= err_error7;
        }
        else
        {
            for (uint16_t i = 5U; i < 10; i++)
            {
                if (data2[i - 5] != data1[i])
                {
                    result |= err_error8;
                    break;
                }
            }
        }
    }

    return result;
}