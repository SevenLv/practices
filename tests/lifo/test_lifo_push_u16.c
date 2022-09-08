#include "test_lifo_push_u16.h"
#include "test.h"

int test_lifo_push_u16(
    push_func push,
    get_u8_h_func get_u8_h,
    get_u8_l_func get_u8_l)
{
    int result = err_none;

    pra_lifo lifo;
    uint8_t data[DATA_LENGTH] = {0U};
    uint16_t data_length = DATA_LENGTH;
    uint16_t data_to_push = 0U;
    uint16_t expected_data = 0U;
    uint16_t expected_used_length = 0U;
    pra_boolean expected_result = PRA_BOOL_UNKNOWN;
    uint32_t expected_ec = PRA_LIFO_EC_NONE;
    uint32_t actual_ec = PRA_LIFO_EC_NONE;

    expected_result = PRA_BOOL_FALSE;
    if (expected_result != push(
                               &lifo,
                               data_to_push,
                               PRA_EC_T_NULL))
    {
        result |= err_error1;
    }

    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_LIFO_EC_NULL_PTR;
    actual_ec = PRA_LIFO_EC_NONE;
    if (expected_result != push(
                               PRA_LIFO_NULL,
                               data_to_push,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error2;
    }

    expected_result = PRA_BOOL_TRUE;
    if (expected_result != pra_lifo_init(
                               &lifo,
                               data,
                               data_length,
                               &actual_ec))
    {
        result |= err_error3;
    }

    lifo.p_data = PRA_UINT8_NULL;
    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_LIFO_EC_NULL_PTR;
    actual_ec = PRA_LIFO_EC_NONE;
    if (expected_result != push(
                               &lifo,
                               data_to_push,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error4;
    }

    lifo.p_data = data;
    lifo.initialized = PRA_BOOL_FALSE;
    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_LIFO_EC_NOT_INIT;
    actual_ec = PRA_LIFO_EC_NONE;
    if (expected_result != push(
                               &lifo,
                               data_to_push,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error5;
    }

    lifo.initialized = PRA_BOOL_TRUE;
    lifo.used_length = lifo.data_length - 1U;
    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_LIFO_EC_DATA_FULL;
    actual_ec = PRA_LIFO_EC_NONE;
    if (expected_result != push(
                               &lifo,
                               data_to_push,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error6;
    }

    lifo.used_length = 0U;
    data_to_push = 0xEEFFU;
    expected_data = 0xEEFFU;
    expected_used_length = 2U;
    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_LIFO_EC_NONE;
    actual_ec = PRA_LIFO_EC_NONE;
    if (expected_result != push(
                               &lifo,
                               data_to_push,
                               &actual_ec) ||
        expected_ec != actual_ec ||
        get_u8_h(expected_data) != lifo.p_data[0U] ||
        get_u8_l(expected_data) != lifo.p_data[1U] ||
        expected_used_length != lifo.used_length)
    {
        result |= err_error7;
    }

    lifo.p_data[0U] = 0U;
    lifo.used_length = 0U;
    lifo.next_w_pos = 8U;
    data_to_push = 0xEEFFU;
    expected_data = 0xEEFFU;
    expected_used_length = 2U;
    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_LIFO_EC_NONE;
    actual_ec = PRA_LIFO_EC_NONE;
    if (expected_result != push(
                               &lifo,
                               data_to_push,
                               &actual_ec) ||
        expected_ec != actual_ec ||
        get_u8_h(expected_data) != lifo.p_data[8U] ||
        get_u8_l(expected_data) != lifo.p_data[9U] ||
        expected_used_length != lifo.used_length ||
        0U != lifo.next_w_pos)
    {
        result |= err_error8;
    }

    return result;
}