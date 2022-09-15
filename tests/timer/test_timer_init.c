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
    const pra_boolean expected_actived = PRA_BOOL_UNKNOWN;
    const uint32_t    expected_interval = PRA_NUM_ZERO_U;
    const uint32_t    expected_start_timer = PRA_NUM_ZERO_U;

    expected_result = PRA_BOOL_FALSE;
    if (expected_result != pra_timer_init(
                               &timer,
                               PRA_EC_T_NULL))
    {
        result |= err_error1;
    }

    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_TIMER_EC_NULL_PTR;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_timer_init(
                               PRA_TIMER_NULL,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error2;
    }

    timer.actived = PRA_BOOL_TRUE;
    timer.start_time = PRA_NUM_MAX_VALUE_U32;
    timer.interval = PRA_NUM_MAX_VALUE_U32;
    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_EC_NONE;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_timer_init(
                               &timer,
                               &actual_ec) ||
        expected_actived != timer.actived ||
        expected_interval != timer.interval ||
        expected_start_timer != timer.start_time)
    {
        result |= err_error3;
    }

    return result;
}