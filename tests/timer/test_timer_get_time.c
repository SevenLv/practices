#include "pra_ec.h"
#include "pra_timer.h"
#include "test.h"


int main(void);

int main(void)
{
    int result = err_none;

    pra_boolean expected_result = PRA_BOOL_UNKNOWN;
    uint32_t    actual_time;
    PRA_EC_T    expected_ec;
    PRA_EC_T    actual_ec;

    expected_result = PRA_BOOL_FALSE;
    if (expected_result != pra_timer_get_time(
                               &actual_time,
                               PRA_EC_T_NULL))
    {
        result |= err_error1;
    }

    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_EC_NULL_PTR;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_timer_get_time(
                               PRA_UINT32_NULL,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error2;
    }

    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_EC_NONE;
    for (uint32_t i = PRA_NUM_ZERO_U; i < PRA_NUM_MAX_VALUE_U32; i++)
    {
        uint32_t expected_time = i;
        actual_ec = PRA_NUM_ZERO_U;
        actual_time = PRA_NUM_ZERO_U;
        if (expected_result != pra_timer_get_time(
                                   &actual_time,
                                   &actual_ec) ||
            expected_ec != actual_ec ||
            expected_time != actual_time)
        {
            result |= err_error3;
            break;
        }

        if (expected_result != pra_timer_execute())
        {
            result |= err_error4;
            break;
        }

        expected_time = i + 1U;
        actual_ec = PRA_NUM_ZERO_U;
        actual_time = PRA_NUM_ZERO_U;
        if (expected_result != pra_timer_get_time(
                                   &actual_time,
                                   &actual_ec) ||
            expected_ec != actual_ec ||
            expected_time != actual_time)
        {
            result |= err_error5;
            break;
        }
    }

    return result;
}