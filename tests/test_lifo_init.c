#include "pra_lifo.h"
#include "pra_defs.h"
#include "test.h"

#define DATA_LENGTH 10U

int main(void);

int main(void)
{
    int result = err_none;

    pra_lifo lifo = {0};
    uint8_t data[DATA_LENGTH] = {1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U};
    uint16_t data_length = DATA_LENGTH;
    pra_boolean expected_result = PRA_BOOL_UNKNOWN;
    PRA_EC_T expected_ec = PRA_LIFO_EC_NONE;
    PRA_EC_T actual_ec = PRA_LIFO_EC_NONE;
    const uint8_t expected_data_value = 0U;
    uint16_t expected_data_length = DATA_LENGTH;
    uint16_t expected_used_length = 0U;
    uint16_t expected_next_r_pos = 0U;
    uint16_t expected_next_W_pos = 0U;

    expected_result = PRA_BOOL_FALSE;
    if (expected_result != pra_lifo_init(
                               &lifo,
                               data,
                               data_length,
                               PRA_EC_T_NULL))
    {
        result |= err_error1;
    }

    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_LIFO_EC_NULL_PTR;
    actual_ec = PRA_LIFO_EC_NONE;
    if (expected_result != pra_lifo_init(
                               PRA_LIFO_NULL,
                               data,
                               data_length,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error2;
    }

    data_length = 0U;
    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_LIFO_EC_INVALID_LENGTH;
    actual_ec = PRA_LIFO_EC_NONE;
    if (expected_result != pra_lifo_init(
                               &lifo,
                               data,
                               data_length,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error3;
    }

    data_length = DATA_LENGTH;
    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_LIFO_EC_NONE;
    actual_ec = PRA_LIFO_EC_NONE;
    if (expected_result != pra_lifo_init(
                               &lifo,
                               data,
                               data_length,
                               &actual_ec) ||
        expected_ec != actual_ec ||
        expected_data_length != lifo.data_length ||
        expected_used_length != lifo.used_length ||
        expected_next_r_pos != lifo.next_r_pos ||
        expected_next_W_pos != lifo.next_w_pos)
    {
        result |= err_error4;
    }
    else
    {
        for (uint16_t i = 0U; i < DATA_LENGTH; i++)
        {
            if (expected_data_value != lifo.p_data[i])
            {
                result |= err_error5;
                break;
            }
        }
    }

    return result;
}