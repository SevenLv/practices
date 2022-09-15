#include "pra_timer.h"
#include "pra_timer_ec.h"
#include "test.h"

int main(void);

int main(void)
{
    int result = err_none;

    pra_timer         timer;
    pra_boolean       expected_result = PRA_BOOL_UNKNOWN;
    PRA_EC_T          expected_ec = PRA_EC_NONE;
    PRA_EC_T          actual_ec = PRA_EC_NONE;
    const pra_boolean expected_actived = PRA_BOOL_TRUE;
    const uint32_t    expected_start_time = 10U;

    expected_result = PRA_BOOL_TRUE;
    if (expected_result != pra_timer_init(
                               &timer,
                               &actual_ec))
    {
        result |= err_error1;
    }

    expected_result = PRA_BOOL_FALSE;
    if (expected_result != pra_timer_start(
                               &timer,
                               PRA_EC_T_NULL))
    {
        result |= err_error2;
    }

    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_TIMER_EC_NULL_PTR;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_timer_start(
                               PRA_TIMER_NULL,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error3;
    }

    timer.interval = PRA_NUM_ZERO_U;
    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_TIMER_EC_INVALID_INTERVAL;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_timer_start(
                               &timer,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error4;
    }

    timer.interval = 100;
    timer.actived = PRA_BOOL_TRUE;
    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_TIMER_EC_ALREADY_STARTED;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_timer_start(
                               &timer,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error5;
    }

    expected_result = PRA_BOOL_TRUE;
    for (uint32_t i = PRA_NUM_ZERO_U; i < expected_start_time; i++)
    {
        if (expected_result != pra_timer_execute())
        {
            result |= err_error6;
            break;
        }
    }

    timer.actived = PRA_BOOL_UNKNOWN;
    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_EC_NONE;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_timer_start(
                               &timer,
                               &actual_ec) ||
        expected_ec != actual_ec ||
        expected_start_time != timer.start_time ||
        expected_actived != timer.actived)
    {
        result |= err_error7;
    }

    return result;
}