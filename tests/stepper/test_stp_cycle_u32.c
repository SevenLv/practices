#include "pra_ec.h"
#include "pra_stp_cycle.h"
#include "test.h"

int main(void);

int main(void)
{
    int result = err_none;

    uint32_t    expected_value = PRA_NUM_ZERO_U;
    uint32_t    value = PRA_NUM_ZERO_U;
    uint32_t   *p_value = &value;
    uint32_t    min_value = PRA_NUM_ZERO_U;
    uint32_t    max_value = PRA_NUM_MAX_VALUE_U32;
    uint32_t    step = 1U;
    pra_boolean expected_result = PRA_BOOL_UNKNOWN;
    PRA_EC_T    expected_ec = PRA_EC_NONE;
    PRA_EC_T    actual_ec = PRA_EC_NONE;

    expected_result = PRA_BOOL_FALSE;
    if (expected_result != pra_stp_cycle_u32(
                               p_value,
                               min_value,
                               max_value,
                               step,
                               PRA_EC_T_NULL))
    {
        result |= err_error1;
    }

    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_EC_NULL_PTR;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_stp_cycle_u32(
                               PRA_UINT32_NULL,
                               min_value,
                               max_value,
                               step,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error2;
    }

    min_value = PRA_NUM_MAX_VALUE_U32;
    max_value = PRA_NUM_MAX_VALUE_U32;
    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_EC_INVALID_RANGE;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_stp_cycle_u32(
                               p_value,
                               min_value,
                               max_value,
                               step,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error3;
    }

    min_value = PRA_NUM_MAX_VALUE_U32;
    max_value = PRA_NUM_MAX_VALUE_U32 - 1U;
    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_EC_INVALID_RANGE;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_stp_cycle_u32(
                               p_value,
                               min_value,
                               max_value,
                               step,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error4;
    }

    value = 0U;
    min_value = 1U;
    max_value = PRA_NUM_MAX_VALUE_U32;
    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_EC_VALUE_OUT_OF_RANGE;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_stp_cycle_u32(
                               p_value,
                               min_value,
                               max_value,
                               step,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error5;
    }

    value = 10U;
    min_value = PRA_NUM_ZERO_U;
    max_value = 9U;
    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_EC_VALUE_OUT_OF_RANGE;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_stp_cycle_u32(
                               p_value,
                               min_value,
                               max_value,
                               step,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error6;
    }

    value = PRA_NUM_ZERO_U;
    min_value = PRA_NUM_ZERO_U;
    max_value = PRA_NUM_MAX_VALUE_U32;
    step = PRA_NUM_ZERO_U;
    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_EC_INVALID_STEP;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_stp_cycle_u32(
                               p_value,
                               min_value,
                               max_value,
                               step,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error7;
    }

    value = PRA_NUM_ZERO_U;
    min_value = PRA_NUM_ZERO_U;
    max_value = 10U;
    step = PRA_NUM_MAX_VALUE_U32;
    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_EC_INVALID_STEP;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_stp_cycle_u32(
                               p_value,
                               min_value,
                               max_value,
                               step,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error8;
    }

    expected_value = 1U;
    value = PRA_NUM_ZERO_U;
    min_value = PRA_NUM_ZERO_U;
    max_value = PRA_NUM_MAX_VALUE_U32;
    step = 1U;
    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_EC_NONE;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_stp_cycle_u32(
                               p_value,
                               min_value,
                               max_value,
                               step,
                               &actual_ec) ||
        expected_ec != actual_ec ||
        expected_value != value)
    {
        result |= err_error9;
    }

    expected_value = PRA_NUM_ZERO_U;
    value = PRA_NUM_MAX_VALUE_U32;
    min_value = PRA_NUM_ZERO_U;
    max_value = PRA_NUM_MAX_VALUE_U32;
    step = 1U;
    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_EC_NONE;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_stp_cycle_u32(
                               p_value,
                               min_value,
                               max_value,
                               step,
                               &actual_ec) ||
        expected_ec != actual_ec ||
        expected_value != value)
    {
        result |= err_error10;
    }

    expected_value = PRA_NUM_ZERO_U;
    value = PRA_NUM_ZERO_U;
    min_value = PRA_NUM_ZERO_U;
    max_value = PRA_NUM_MAX_VALUE_U32;
    step = PRA_NUM_MAX_VALUE_U32;
    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_EC_NONE;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_stp_cycle_u32(
                               p_value,
                               min_value,
                               max_value,
                               step,
                               &actual_ec) ||
        expected_ec != actual_ec ||
        expected_value != value)
    {
        result |= err_error11;
    }

    expected_value = 1U;
    value = PRA_NUM_MAX_VALUE_U32;
    min_value = PRA_NUM_ZERO_U;
    max_value = PRA_NUM_MAX_VALUE_U32;
    step = 2U;
    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_EC_NONE;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_stp_cycle_u32(
                               p_value,
                               min_value,
                               max_value,
                               step,
                               &actual_ec) ||
        expected_ec != actual_ec ||
        expected_value != value)
    {
        result |= err_error11;
    }

    return result;
}