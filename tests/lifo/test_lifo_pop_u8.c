#include "pra_lifo.h"
#include "pra_defs.h"
#include "test.h"

#define DATA_LENGTH 10U

int main(void);

int main(void)
{
    int result = err_none;

    pra_lifo lifo;
    uint8_t data[DATA_LENGTH] = {0};
    uint16_t data_length = DATA_LENGTH;
    uint8_t expected_data_value = 0U;
    uint8_t actual_data_value = 0U;
    uint16_t expected_used_length = 0U;
    pra_boolean expected_result = PRA_BOOL_UNKNOWN;
    PRA_EC_T expected_ec = PRA_LIFO_EC_NONE;
    PRA_EC_T actual_ec = PRA_LIFO_EC_NONE;

    expected_result = PRA_BOOL_TRUE;
    if (expected_result != pra_lifo_init(
                               &lifo,
                               data,
                               data_length,
                               &actual_ec))
    {
        result |= err_error1;
    }

    lifo.p_data = PRA_UINT8_NULL;
    actual_data_value = 0U;
    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_LIFO_EC_NULL_PTR;
    actual_ec = PRA_LIFO_EC_NONE;
    if (expected_result != pra_lifo_pop_u8(
                               &lifo,
                               &actual_data_value,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error3;
    }

    lifo.p_data = data;
    actual_data_value = 0U;
    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_LIFO_EC_DATA_NOT_ENOUGH;
    actual_ec = PRA_LIFO_EC_NONE;
    if (expected_result != pra_lifo_pop_u8(
                               &lifo,
                               &actual_data_value,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error4;
    }

    actual_data_value = 0xFFU;
    expected_result = PRA_BOOL_TRUE;
    if (expected_result != pra_lifo_push_u8(
                               &lifo,
                               actual_data_value,
                               &actual_ec))
    {
        result |= err_error5;
    }

    expected_data_value = 0xFFU;
    actual_data_value = 0U;
    expected_used_length = 0U;
    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_LIFO_EC_NONE;
    actual_ec = PRA_LIFO_EC_NONE;
    if (expected_result != pra_lifo_pop_u8(
                               &lifo,
                               &actual_data_value,
                               &actual_ec) ||
        expected_ec != actual_ec ||
        expected_data_value != actual_data_value ||
        expected_used_length != lifo.used_length)
    {
        result |= err_error6;
    }

    expected_result = PRA_BOOL_TRUE;
    if (expected_result != pra_lifo_init(
                               &lifo,
                               data,
                               data_length,
                               &actual_ec))
    {
        result |= err_error7;
    }

    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_LIFO_EC_NONE;
    for (uint8_t i = PRA_NUM_ZERO_U; i < DATA_LENGTH; i++)
    {
        actual_ec = PRA_LIFO_EC_NONE;
        if (expected_result != pra_lifo_push_u8(
                                   &lifo,
                                   i,
                                   &actual_ec) ||
            expected_ec != actual_ec)
        {
            result |= err_error8;
        }
    }

    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_LIFO_EC_NONE;
    for (uint8_t i = DATA_LENGTH; i > PRA_NUM_ZERO_U; i--)
    {
        expected_data_value = i - 1;
        actual_ec = PRA_LIFO_EC_NONE;
        if (expected_result != pra_lifo_pop_u8(
                                   &lifo,
                                   &actual_data_value,
                                   &actual_ec) ||
            expected_ec != actual_ec ||
            expected_data_value != actual_data_value)
        {
            result |= err_error9;
        }
    }

    return result;
}