#include "pra_ec.h"
#include "pra_timer.h"
#include "test.h"

int main(void);

int main(void)
{
    int result = err_none;

    pra_timer         timer;
    pra_boolean       expected_result = PRA_BOOL_UNKNOWN;
    PRA_EC_T          expected_ec = PRA_EC_NONE;
    PRA_EC_T          actual_ec = PRA_EC_NONE;
    const pra_boolean expected_actived = PRA_BOOL_FALSE;

    expected_result = PRA_BOOL_TRUE;
    if (expected_result != pra_timer_init(
                               &timer,
                               &actual_ec))
    {
        result |= err_error1;
    }

    timer.interval = 100U;
    expected_result = PRA_BOOL_TRUE;
    if (expected_result != pra_timer_start(
                               &timer,
                               &actual_ec))
    {
        result |= err_error2;
    }

    expected_result = PRA_BOOL_FALSE;
    if (expected_result != pra_timer_stop(
                               &timer,
                               PRA_EC_T_NULL))
    {
        result |= err_error3;
    }

    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_EC_NULL_PTR;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_timer_stop(
                               PRA_TIMER_NULL,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error4;
    }

    timer.actived = PRA_BOOL_FALSE;
    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_EC_NOT_STARTED;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_timer_stop(
                               &timer,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error5;
    }

    timer.actived = PRA_BOOL_UNKNOWN;
    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_EC_NOT_STARTED;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_timer_stop(
                               &timer,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error6;
    }

    timer.actived = PRA_BOOL_TRUE;
    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_EC_NONE;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_timer_stop(
                               &timer,
                               &actual_ec) ||
        expected_ec != actual_ec ||
        expected_actived != timer.actived)
    {
        result |= err_error7;
    }

    return result;
}