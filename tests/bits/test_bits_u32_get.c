#include "pra_bits.h"
#include "pra_defs.h"
#include "pra_ec.h"
#include "test.h"


int main(void);

int main(void)
{
    int result = err_none;

    uint32_t    value = 0U;
    uint8_t     bit_offset = 0U;
    pra_boolean expected_result = PRA_BOOL_UNKNOWN;
    pra_boolean expected_actived = PRA_BOOL_UNKNOWN;
    pra_boolean actual_actived = PRA_BOOL_UNKNOWN;
    uint32_t    expected_ec = PRA_EC_NONE;
    uint32_t    actual_ec = PRA_EC_NONE;

    expected_result = PRA_BOOL_FALSE;
    if (expected_result != pra_bits_u32_get(
                               value,
                               bit_offset,
                               &actual_actived,
                               PRA_UINT32_NULL))
    {
        result |= err_error1;
    }

    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_EC_NULL_PTR;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_bits_u32_get(
                               value,
                               bit_offset,
                               PRA_BOOL_NULL,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error2;
    }

    bit_offset = 32U;
    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_EC_INVALID_OFFSET;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_bits_u32_get(
                               value,
                               bit_offset,
                               &actual_actived,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error3;
    }

    value = 0U;
    bit_offset = 0U;
    expected_result = PRA_BOOL_TRUE;
    expected_actived = PRA_BOOL_FALSE;
    actual_actived = PRA_BOOL_UNKNOWN;
    expected_ec = PRA_EC_NONE;
    for (bit_offset = 0U; bit_offset < 32U; bit_offset++)
    {
        actual_ec = PRA_EC_NONE;
        if (expected_result != pra_bits_u32_get(
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

    value = 0xFFFFFFFFU;
    bit_offset = 0U;
    expected_result = PRA_BOOL_TRUE;
    expected_actived = PRA_BOOL_TRUE;
    actual_actived = PRA_BOOL_UNKNOWN;
    expected_ec = PRA_EC_NONE;
    for (bit_offset = 0U; bit_offset < 32U; bit_offset++)
    {
        actual_ec = PRA_EC_NONE;
        if (expected_result != pra_bits_u32_get(
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

    return result;
}