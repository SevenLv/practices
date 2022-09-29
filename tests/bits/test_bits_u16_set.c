#include "pra_bits.h"
#include "pra_defs.h"
#include "pra_ec.h"
#include "test.h"


static uint16_t u16_masks[16] = {
    0x0001U, 0x0002U, 0x0004U, 0x0008U,
    0x0010U, 0x0020U, 0x0040U, 0x0080U,
    0x0100U, 0x0200U, 0x0400U, 0x0800U,
    0x1000U, 0x2000U, 0x4000U, 0x8000U
};

static uint16_t u16_reversed_masks[16] = {
    0xFFFEU, 0xFFFDU, 0xFFFBU, 0xFFF7U,
    0xFFEFU, 0xFFDFU, 0xFFBFU, 0xFF7FU,
    0xFEFFU, 0xFDFFU, 0xFBFFU, 0xF7FFU,
    0xEFFFU, 0xDFFFU, 0xBFFFU, 0x7FFFU
};

int main(void);

int main(void)
{
    int result = err_none;

    uint16_t    expected_value = 0U;
    uint16_t    actual_value = 0U;
    uint8_t     bit_offset = 0U;
    pra_boolean actived = PRA_BOOL_UNKNOWN;
    pra_boolean expected_result = PRA_BOOL_UNKNOWN;
    uint32_t    expected_ec = PRA_EC_NONE;
    uint32_t    actual_ec = PRA_EC_NONE;

    expected_result = PRA_BOOL_FALSE;
    if (expected_result != pra_bits_u16_set(
                               &actual_value,
                               bit_offset,
                               actived,
                               PRA_UINT32_NULL))
    {
        result |= err_error1;
    }

    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_EC_NULL_PTR;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_bits_u16_set(
                               PRA_UINT16_NULL,
                               bit_offset,
                               actived,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error2;
    }

    bit_offset = 16U;
    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_EC_INVALID_OFFSET;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_bits_u16_set(
                               &actual_value,
                               bit_offset,
                               actived,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error3;
    }

    bit_offset = 0U;
    actived = PRA_BOOL_TRUE;
    expected_result = PRA_BOOL_TRUE;
    for (bit_offset = 0U; bit_offset < 16U; bit_offset++)
    {
        expected_ec = PRA_EC_NONE;
        actual_ec = PRA_EC_NONE;
        expected_value = u16_masks[bit_offset];
        actual_value = 0U;
        if (expected_result != pra_bits_u16_set(
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

    bit_offset = 0U;
    actived = PRA_BOOL_UNKNOWN;
    expected_result = PRA_BOOL_TRUE;
    for (bit_offset = 0U; bit_offset < 16U; bit_offset++)
    {
        expected_ec = PRA_EC_NONE;
        actual_ec = PRA_EC_NONE;
        expected_value = u16_reversed_masks[bit_offset];
        actual_value = 0xFFFFU;
        if (expected_result != pra_bits_u16_set(
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

    bit_offset = 0U;
    actived = PRA_BOOL_FALSE;
    expected_result = PRA_BOOL_TRUE;
    for (bit_offset = 0U; bit_offset < 16U; bit_offset++)
    {
        expected_ec = PRA_EC_NONE;
        actual_ec = PRA_EC_NONE;
        expected_value = u16_reversed_masks[bit_offset];
        actual_value = 0xFFFFU;
        if (expected_result != pra_bits_u16_set(
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

    return result;
}