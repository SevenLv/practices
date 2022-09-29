#include "pra_ec.h"
#include "pra_stp_cycle.h"
#include "test.h"

int main(void);

int main(void)
{
    int result = err_none;

    uint8_t     expected_value = PRA_NUM_ZERO_U;
    uint8_t     actual_value = PRA_NUM_ZERO_U;
    uint8_t    *p_value = &actual_value;
    pra_boolean expected_result = PRA_BOOL_UNKNOWN;
    PRA_EC_T    expected_ec = PRA_EC_NONE;
    PRA_EC_T    actual_ec = PRA_EC_NONE;

    expected_result = PRA_BOOL_FALSE;
    if (expected_result != pra_stp_cycle_default_u8(
                               p_value,
                               PRA_EC_T_NULL))
    {
        result |= err_error1;
    }

    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_EC_NULL_PTR;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_stp_cycle_default_u8(
                               PRA_UINT8_NULL,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error2;
    }

    expected_value = 1U;
    actual_value = PRA_NUM_ZERO_U;
    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_EC_NONE;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_stp_cycle_default_u8(
                               p_value,
                               &actual_ec) ||
        expected_ec != actual_ec ||
        expected_value != actual_value)
    {
        result |= err_error3;
    }

    expected_value = PRA_NUM_ZERO_U;
    actual_value = PRA_NUM_MAX_VALUE_U8;
    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_EC_NONE;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_stp_cycle_default_u8(
                               p_value,
                               &actual_ec) ||
        expected_ec != actual_ec ||
        expected_value != actual_value)
    {
        result |= err_error4;
    }

    return result;
}