#include "pra_lifo_ec.h"
#include "test.h"
#include "test_lifo_pop_u32.h"


int test_lifo_pop_u32(
    pop_func  pop,
    push_func push)
{
    int result = err_none;

    pra_lifo    lifo;
    uint8_t     data[DATA_LENGTH] = { 0 };
    uint16_t    data_length = DATA_LENGTH;
    uint32_t    expected_data_value = 0U;
    uint32_t    actual_data_value = 0U;
    uint16_t    expected_used_length = 0U;
    pra_boolean expected_result = PRA_BOOL_UNKNOWN;
    PRA_EC_T    expected_ec = PRA_LIFO_EC_NONE;
    PRA_EC_T    actual_ec = PRA_LIFO_EC_NONE;

    expected_result = PRA_BOOL_TRUE;
    if (expected_result != pra_lifo_init(
                               &lifo,
                               data,
                               data_length,
                               &actual_ec))
    {
        result |= err_error1;
    }

    expected_result = PRA_BOOL_FALSE;
    if (expected_result != pop(
                               &lifo,
                               &actual_data_value,
                               PRA_UINT32_NULL))
    {
        result |= err_error2;
    }

    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_LIFO_EC_NULL_PTR;
    actual_ec = PRA_LIFO_EC_NONE;
    if (expected_result != pop(
                               PRA_LIFO_NULL,
                               &actual_data_value,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error3;
    }

    lifo.p_data = PRA_UINT8_NULL;
    actual_data_value = 0U;
    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_LIFO_EC_NULL_PTR;
    actual_ec = PRA_LIFO_EC_NONE;
    if (expected_result != pop(
                               &lifo,
                               &actual_data_value,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error4;
    }

    lifo.p_data = data;
    actual_data_value = 0U;
    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_LIFO_EC_DATA_NOT_ENOUGH;
    actual_ec = PRA_LIFO_EC_NONE;
    if (expected_result != pop(
                               &lifo,
                               &actual_data_value,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error5;
    }

    actual_data_value = 0xCCDDEEFFU;
    expected_result = PRA_BOOL_TRUE;
    if (expected_result != push(
                               &lifo,
                               actual_data_value,
                               &actual_ec))
    {
        result |= err_error6;
    }

    expected_data_value = 0xCCDDEEFFU;
    actual_data_value = 0U;
    expected_used_length = 0U;
    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_LIFO_EC_NONE;
    actual_ec = PRA_LIFO_EC_NONE;
    if (expected_result != pop(
                               &lifo,
                               &actual_data_value,
                               &actual_ec) ||
        expected_ec != actual_ec ||
        expected_data_value != actual_data_value ||
        expected_used_length != lifo.used_length)
    {
        result |= err_error7;
    }

    expected_result = PRA_BOOL_TRUE;
    if (expected_result != pra_lifo_init(
                               &lifo,
                               data,
                               data_length,
                               &actual_ec))
    {
        result |= err_error8;
    }

    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_LIFO_EC_NONE;
    for (uint32_t i = PRA_NUM_ZERO_U; i < (DATA_LENGTH / PRA_NUM_BYTE_SIZE_U32); i++)
    {
        actual_ec = PRA_LIFO_EC_NONE;
        if (expected_result != push(
                                   &lifo,
                                   i,
                                   &actual_ec) ||
            expected_ec != actual_ec)
        {
            result |= err_error9;
        }
    }

    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_LIFO_EC_NONE;
    for (uint32_t i = (DATA_LENGTH / PRA_NUM_BYTE_SIZE_U32); i > PRA_NUM_ZERO_U; i--)
    {
        expected_data_value = i - 1;
        actual_ec = PRA_LIFO_EC_NONE;
        if (expected_result != pop(
                                   &lifo,
                                   &actual_data_value,
                                   &actual_ec) ||
            expected_ec != actual_ec ||
            expected_data_value != actual_data_value)
        {
            result |= err_error10;
        }
    }

    return result;
}