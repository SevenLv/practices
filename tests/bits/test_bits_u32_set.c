#include "pra_bits.h"
#include "pra_defs.h"
#include "test.h"

static uint32_t u32_masks[32] = {
    0x00000001U, 0x00000002U, 0x00000004U, 0x00000008U,
    0x00000010U, 0x00000020U, 0x00000040U, 0x00000080U,
    0x00000100U, 0x00000200U, 0x00000400U, 0x00000800U,
    0x00001000U, 0x00002000U, 0x00004000U, 0x00008000U,
    0x00010000U, 0x00020000U, 0x00040000U, 0x00080000U,
    0x00100000U, 0x00200000U, 0x00400000U, 0x00800000U,
    0x01000000U, 0x02000000U, 0x04000000U, 0x08000000U,
    0x10000000U, 0x20000000U, 0x40000000U, 0x80000000U
};

static uint32_t u32_reversed_masks[32] = {
    0xFFFFFFFEU, 0xFFFFFFFDU, 0xFFFFFFFBU, 0xFFFFFFF7U,
    0xFFFFFFEFU, 0xFFFFFFDFU, 0xFFFFFFBFU, 0xFFFFFF7FU,
    0xFFFFFEFFU, 0xFFFFFDFFU, 0xFFFFFBFFU, 0xFFFFF7FFU,
    0xFFFFEFFFU, 0xFFFFDFFFU, 0xFFFFBFFFU, 0xFFFF7FFFU,
    0xFFFEFFFFU, 0xFFFDFFFFU, 0xFFFBFFFFU, 0xFFF7FFFFU,
    0xFFEFFFFFU, 0xFFDFFFFFU, 0xFFBFFFFFU, 0xFF7FFFFFU,
    0xFEFFFFFFU, 0xFDFFFFFFU, 0xFBFFFFFFU, 0xF7FFFFFFU,
    0xEFFFFFFFU, 0xDFFFFFFFU, 0xBFFFFFFFU, 0x7FFFFFFFU
};

int main(void);

int main(void)
{
    int result = err_none;

    uint32_t    expected_value = 0U;
    uint32_t    actual_value = 0U;
    uint8_t     bit_offset = 0U;
    pra_boolean actived = PRA_BOOL_UNKNOWN;
    uint32_t    expected_ec = PRA_BITS_EC_NONE;
    uint32_t    actual_ec = PRA_BITS_EC_NONE;
    pra_boolean expected_result = PRA_BOOL_UNKNOWN;

    expected_result = PRA_BOOL_FALSE;
    if (expected_result != pra_bits_u32_set(
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
    if (expected_result != pra_bits_u32_set(
                               PRA_UINT32_NULL,
                               bit_offset,
                               actived,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error2;
    }

    bit_offset = 32U;
    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_BITS_EC_INVALID_OFFSET;
    actual_ec = PRA_BITS_EC_NONE;
    if (expected_result != pra_bits_u32_set(
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
    expected_ec = PRA_BITS_EC_NONE;
    for (bit_offset = 0U; bit_offset < 32U; bit_offset++)
    {
        actual_value = 0U;
        actual_ec = PRA_BITS_EC_NONE;
        expected_value = u32_masks[bit_offset];
        if (expected_result != pra_bits_u32_set(
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
    expected_ec = PRA_BITS_EC_NONE;
    for (bit_offset = 0U; bit_offset < 32U; bit_offset++)
    {
        actual_value = 0xFFFFFFFFU;
        actual_ec = PRA_BITS_EC_NONE;
        expected_value = u32_reversed_masks[bit_offset];
        if (expected_result != pra_bits_u32_set(
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

    bit_offset = 0U;
    actived = PRA_BOOL_FALSE;
    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_BITS_EC_NONE;
    for (bit_offset = 0U; bit_offset < 32U; bit_offset++)
    {
        actual_value = 0xFFFFFFFFU;
        actual_ec = PRA_BITS_EC_NONE;
        expected_value = u32_reversed_masks[bit_offset];
        if (expected_result != pra_bits_u32_set(
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