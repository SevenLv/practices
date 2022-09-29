#include "pra_ec.h"
#include "test.h"
#include "test_fifo_take_u32.h"


int test_fifo_take_u32(
    take_func   take,
    append_func append)
{
    int result = err_none;

    pra_fifo    fifo;
    uint8_t     data[DATA_LENGTH] = { 0 };
    uint32_t    data_length = DATA_LENGTH;
    uint32_t    expected_data_value = 0U;
    uint32_t    actual_data_value = 0U;
    uint32_t    expected_used_length = 0U;
    pra_boolean expected_result = PRA_BOOL_UNKNOWN;
    PRA_EC_T    expected_ec = PRA_EC_NONE;
    PRA_EC_T    actual_ec = PRA_EC_NONE;

    expected_result = PRA_BOOL_TRUE;
    if (expected_result != pra_fifo_init(
                               &fifo,
                               data,
                               data_length,
                               &actual_ec))
    {
        result |= err_error1;
    }

    expected_result = PRA_BOOL_FALSE;
    if (expected_result != take(
                               PRA_FIFO_NULL,
                               &actual_data_value,
                               &actual_ec))
    {
        result |= err_error2;
    }

    fifo.p_data = PRA_UINT8_NULL;
    actual_data_value = 0U;
    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_EC_NULL_PTR;
    actual_ec = PRA_EC_NONE;
    if (expected_result != take(
                               &fifo,
                               &actual_data_value,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error3;
    }

    fifo.p_data = data;
    actual_data_value = 0U;
    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_EC_NOT_ENOUGH_LENGTH;
    actual_ec = PRA_EC_NONE;
    if (expected_result != take(
                               &fifo,
                               &actual_data_value,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error4;
    }

    actual_data_value = 0xCCDDEEFFU;
    expected_result = PRA_BOOL_TRUE;
    if (expected_result != append(
                               &fifo,
                               actual_data_value,
                               &actual_ec))
    {
        result |= err_error5;
    }

    expected_data_value = 0xCCDDEEFFU;
    actual_data_value = 0U;
    expected_used_length = 0U;
    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_EC_NONE;
    actual_ec = PRA_EC_NONE;
    if (expected_result != take(
                               &fifo,
                               &actual_data_value,
                               &actual_ec) ||
        expected_ec != actual_ec ||
        expected_data_value != actual_data_value ||
        expected_used_length != fifo.used_length)
    {
        result |= err_error6;
    }

    return result;
}