#include "pra_ec.h"
#include "pra_timer.h"
#include "test.h"

int main(void);

int main(void)
{
    int result = err_none;

    pra_timer      timer;
    pra_boolean    expected_result = PRA_BOOL_UNKNOWN;
    PRA_EC_T       expected_ec = PRA_EC_NONE;
    PRA_EC_T       actual_ec = PRA_EC_NONE;
    pra_boolean    expected_done = PRA_BOOL_UNKNOWN;
    pra_boolean    actual_done = PRA_BOOL_UNKNOWN;
    const uint32_t interval = PRA_NUM_MAX_VALUE_U32 - 1U;

    expected_result = PRA_BOOL_TRUE;
    if (expected_result != pra_timer_init(
                               &timer,
                               &actual_ec))
    {
        result |= err_error1;
    }

    timer.interval = interval;
    expected_result = PRA_BOOL_TRUE;
    if (expected_result != pra_timer_start(
                               &timer,
                               &actual_ec))
    {
        result |= err_error2;
    }

    expected_result = PRA_BOOL_FALSE;
    if (expected_result != pra_timer_is_done(
                               &timer,
                               &actual_done,
                               PRA_EC_T_NULL))
    {
        result |= err_error3;
    }

    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_EC_NULL_PTR;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_timer_is_done(
                               PRA_TIMER_NULL,
                               &actual_done,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error4;
    }

    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_EC_NULL_PTR;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_timer_is_done(
                               &timer,
                               PRA_UINT32_NULL,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error5;
    }

    timer.actived = PRA_BOOL_FALSE;
    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_EC_NOT_STARTED;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_timer_is_done(
                               &timer,
                               &actual_done,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error6;
    }

    timer.actived = PRA_BOOL_TRUE;
    expected_result = PRA_BOOL_TRUE;
    expected_done = PRA_BOOL_FALSE;
    expected_ec = PRA_EC_NONE;

    for (uint32_t i = PRA_NUM_ZERO_U; i < interval - 1U; i++)
    {
        if (expected_result != pra_timer_execute())
        {
            result |= err_error7;
            break;
        }
    }

    expected_result = PRA_BOOL_TRUE;
    expected_done = PRA_BOOL_FALSE;
    expected_ec = PRA_EC_NONE;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_timer_is_done(
                               &timer,
                               &actual_done,
                               &actual_ec) ||
        expected_ec != actual_ec ||
        expected_done != actual_done)
    {
        result |= err_error8;
    }

    expected_result = PRA_BOOL_TRUE;
    if (expected_result != pra_timer_execute())
    {
        result |= err_error9;
    }

    expected_result = PRA_BOOL_TRUE;
    expected_done = PRA_BOOL_TRUE;
    expected_ec = PRA_EC_NONE;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_timer_is_done(
                               &timer,
                               &actual_done,
                               &actual_ec) ||
        expected_ec != actual_ec ||
        expected_done != actual_done)
    {
        result |= err_error9;
    }

    return result;
}