#include "pra_bits.h"
#include "pra_defs.h"
#include "test.h"

static uint8_t u8_masks[8] = {
    0x01U, 0x02U, 0x04U, 0x08U,
    0x10U, 0x20U, 0x40U, 0x80U
};

static uint8_t u8_reversed_masks[8] = {
    0xFEU, 0xFDU, 0xFBU, 0xF7U,
    0xEFU, 0xDFU, 0xBFU, 0x7FU
};

int main(void);

int main(void)
{
    int result = err_none;

    uint8_t     expected_value = 0U;
    uint8_t     actual_value = 0U;
    uint8_t     bit_offset = 0U;
    pra_boolean actived = PRA_BOOL_UNKNOWN;
    pra_boolean expected_result = PRA_BOOL_UNKNOWN;
    uint32_t    expected_ec = PRA_BITS_EC_NONE;
    uint32_t    actual_ec = PRA_BITS_EC_NONE;

    expected_result = PRA_BOOL_FALSE;
    if (expected_result != pra_bits_u8_set(
                               &actual_value,
                               bit_offset,
                               actived,
                               PRA_UINT32_NULL))
    {
        result |= err_error1;
    }

    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_BITS_EC_NULL_PTR;
    actual_ec = PRA_BITS_EC_NONE;
    if (expected_result != pra_bits_u8_set(
                               PRA_UINT8_NULL,
                               bit_offset,
                               actived,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error2;
    }

    bit_offset = 8U;
    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_BITS_EC_INVALID_OFFSET;
    actual_ec = PRA_BITS_EC_NONE;
    if (expected_result != pra_bits_u8_set(
                               &actual_value,
                               bit_offset,
                               actived,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error3;
    }

    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_BITS_EC_NONE;
    actual_ec = PRA_BITS_EC_NONE;
    actived = PRA_BOOL_TRUE;
    for (bit_offset = 0U; bit_offset < 8U; bit_offset++)
    {
        expected_value = u8_masks[bit_offset];
        actual_value = 0U;
        if (expected_result != pra_bits_u8_set(
                                   &actual_value,
                                   bit_offset,
                                   actived,
                                   &actual_ec) ||
            expected_ec != actual_ec ||
            expected_value != actual_value)
        {
            result |= err_error4;
            break;
        }
    }

    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_BITS_EC_NONE;
    actual_ec = PRA_BITS_EC_NONE;
    actived = PRA_BOOL_UNKNOWN;
    for (bit_offset = 0U; bit_offset < 8U; bit_offset++)
    {
        expected_value = u8_reversed_masks[bit_offset];
        actual_value = 0xFFU;
        if (expected_result != pra_bits_u8_set(
                                   &actual_value,
                                   bit_offset,
                                   actived,
                                   &actual_ec) ||
            expected_ec != actual_ec ||
            expected_value != actual_value)
        {
            result |= err_error5;
            break;
        }
    }

    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_BITS_EC_NONE;
    actual_ec = PRA_BITS_EC_NONE;
    actived = PRA_BOOL_FALSE;
    for (bit_offset = 0U; bit_offset < 8U; bit_offset++)
    {
        expected_value = u8_reversed_masks[bit_offset];
        actual_value = 0xFFU;
        if (expected_result != pra_bits_u8_set(
                                   &actual_value,
                                   bit_offset,
                                   actived,
                                   &actual_ec) ||
            expected_ec != actual_ec ||
            expected_value != actual_value)
        {
            result |= err_error6;
            break;
        }
    }

    return result;
}