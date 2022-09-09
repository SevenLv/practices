#include "pra_bits.h"
#include "pra_defs.h"
#include "test.h"

int main(void);

int main(void)
{
    int result = err_none;

    const uint8_t min_value = 0x00U;
    const uint8_t max_value = 0xFFU;

    pra_boolean expected_result = PRA_BOOL_UNKNOWN;
    pra_boolean expected_actived = PRA_BOOL_UNKNOWN;
    pra_boolean actual_actived = PRA_BOOL_UNKNOWN;
    uint32_t expected_ec = PRA_BITS_EC_NONE;
    uint32_t actual_ec = PRA_BITS_EC_NONE;
    uint8_t value = PRA_NUM_ZERO_U;
    uint8_t bit_offset = PRA_NUM_ZERO_U;

    expected_result = PRA_BOOL_FALSE;
    if (expected_result != pra_bits_u8_get(
                               value,
                               bit_offset,
                               &actual_actived,
                               PRA_UINT32_NULL))
    {
        result |= err_error1;
    }

    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_BITS_EC_NULL_PTR;
    if (expected_result != pra_bits_u8_get(
                               value,
                               bit_offset,
                               PRA_BOOL_NULL,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error2;
    }

    bit_offset = 8;
    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_BITS_EC_INVALID_OFFSET;
    actual_ec = PRA_BITS_EC_NONE;
    if (expected_result != pra_bits_u8_get(
                               value,
                               bit_offset,
                               &actual_actived,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error3;
    }

    value = min_value;
    bit_offset = PRA_NUM_ZERO_U;
    expected_result = PRA_BOOL_TRUE;
    expected_actived = PRA_BOOL_FALSE;
    expected_ec = PRA_BITS_EC_NONE;
    actual_ec = PRA_BITS_EC_NONE;
    for (bit_offset = PRA_NUM_ZERO_U; bit_offset < 8; bit_offset++)
    {
        if (expected_result != pra_bits_u8_get(
                                   value,
                                   bit_offset,
                                   &actual_actived,
                                   &actual_ec) ||
            expected_ec != actual_ec ||
            expected_actived != actual_actived)
        {
            result |= err_error4;
            break;
        }
    }

    value = max_value;
    bit_offset = PRA_NUM_ZERO_U;
    expected_result = PRA_BOOL_TRUE;
    expected_actived = PRA_BOOL_TRUE;
    expected_ec = PRA_BITS_EC_NONE;
    actual_ec = PRA_BITS_EC_NONE;
    for (bit_offset = PRA_NUM_ZERO_U; bit_offset < 8; bit_offset++)
    {
        if (expected_result != pra_bits_u8_get(
                                   value,
                                   bit_offset,
                                   &actual_actived,
                                   &actual_ec) ||
            expected_ec != actual_ec ||
            expected_actived != actual_actived)
        {
            result |= err_error5;
            break;
        }
    }

    return result;
}