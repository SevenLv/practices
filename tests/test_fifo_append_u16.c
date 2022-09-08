#include "test_fifo_append_u16.h"
#include "pra_defs.h"
#include "test.h"
#include "pra_bits.h"

int test_fifo_append_u16(
    append_func append,
    get_u8_h_func get_u8_h,
    get_u8_l_func get_u8_l)
{
    int result = err_none;

    pra_fifo fifo = {0U};
    uint8_t data[DATA_LENGTH] = {0U};
    uint16_t data_length = DATA_LENGTH;
    uint16_t data_to_append = 0U;
    uint16_t expected_data = 0U;
    uint16_t expected_used_length = 0U;
    pra_boolean expected_result = PRA_BOOL_UNKNOWN;
    uint32_t expected_ec = PRA_FIFO_EC_NONE;
    uint32_t actual_ec = PRA_FIFO_EC_NONE;

    expected_result = PRA_BOOL_FALSE;
    if (expected_result != append(
                               &fifo,
                               data_to_append,
                               PRA_EC_T_NULL))
    {
        result |= err_error1;
    }

    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_FIFO_EC_NULL_PTR;
    actual_ec = PRA_FIFO_EC_NONE;
    if (expected_result != append(
                               PRA_FIFO_NULL,
                               data_to_append,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error2;
    }

    if (PRA_BOOL_TRUE != pra_fifo_init(
                             &fifo,
                             data,
                             data_length,
                             &actual_ec))
    {
        result |= err_error3;
    }

    fifo.p_data = PRA_UINT8_NULL;
    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_FIFO_EC_NULL_PTR;
    actual_ec = PRA_FIFO_EC_NONE;
    if (expected_result != append(
                               &fifo,
                               data_to_append,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error4;
    }

    fifo.p_data = data;
    fifo.initialized = PRA_BOOL_FALSE;
    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_FIFO_EC_NOT_INIT;
    actual_ec = PRA_FIFO_EC_NONE;
    if (expected_result != append(
                               &fifo,
                               data_to_append,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error5;
    }

    fifo.initialized = PRA_BOOL_TRUE;
    fifo.used_length = fifo.data_length - 1U;
    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_FIFO_EC_DATA_FULL;
    actual_ec = PRA_FIFO_EC_NONE;
    if (expected_result != append(
                               &fifo,
                               data_to_append,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error6;
    }

    fifo.used_length = 0U;
    data_to_append = 0xEEFFU;
    expected_data = 0xEEFFU;
    expected_used_length = 2U;
    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_FIFO_EC_NONE;
    actual_ec = PRA_FIFO_EC_NONE;
    if (expected_result != append(
                               &fifo,
                               data_to_append,
                               &actual_ec) ||
        expected_ec != actual_ec ||
        get_u8_h(expected_data) != fifo.p_data[0U] ||
        get_u8_l(expected_data) != fifo.p_data[1U] ||
        expected_used_length != fifo.used_length)
    {
        result |= err_error7;
    }

    fifo.p_data[0U] = 0U;
    fifo.used_length = 0U;
    fifo.next_w_pos = 8U;
    data_to_append = 0xEEFFU;
    expected_data = 0xEEFFU;
    expected_used_length = 2U;
    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_BITS_EC_NONE;
    actual_ec = PRA_BITS_EC_NONE;
    if (expected_result != append(
                               &fifo,
                               data_to_append,
                               &actual_ec) ||
        expected_ec != actual_ec ||
        get_u8_h(expected_data) != fifo.p_data[8U] ||
        get_u8_l(expected_data) != fifo.p_data[9U] ||
        expected_used_length != fifo.used_length ||
        0U != fifo.next_w_pos)
    {
        result != err_error8;
    }

    return result;
}