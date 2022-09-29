#include "pra_ec.h"
#include "pra_task.h"
#include "pra_timer.h"
#include "test.h"

static uint32_t current_time = PRA_NUM_ZERO_U;

static pra_boolean test_execute(
    const uint32_t  time,
    PRA_EC_T *const p_ec);

int main(void);

static pra_boolean test_execute(
    const uint32_t  time,
    PRA_EC_T *const p_ec)
{
    current_time = time;

    *p_ec = PRA_EC_NONE;

    return PRA_BOOL_TRUE;
}

int main(void)
{
    int result = err_none;

    pra_task    task;
    pra_boolean expected_result = PRA_BOOL_UNKNOWN;
    PRA_EC_T    expected_ec = PRA_EC_NONE;
    PRA_EC_T    actual_ec = PRA_EC_NONE;
    uint32_t    expected_time = PRA_NUM_ZERO_U;

    expected_result = PRA_BOOL_TRUE;
    if (expected_result != pra_task_init(
                               &task,
                               &actual_ec))
    {
        result |= err_error1;
    }

    task.execute_func = test_execute;

    expected_result = PRA_BOOL_FALSE;
    if (expected_result != pra_task_remove(
                               &task,
                               PRA_EC_T_NULL))
    {
        result |= err_error2;
    }

    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_EC_NULL_PTR;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_task_remove(
                               PRA_TASK_NULL,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error3;
    }

    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_EC_NEVER_ADDED;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_task_remove(
                               &task,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error4;
    }

    expected_result = PRA_BOOL_TRUE;
    if (expected_result != pra_task_add(
                               &task,
                               &actual_ec))
    {
        result |= err_error5;
    }

    expected_result = PRA_BOOL_TRUE;
    if (expected_result != pra_timer_execute())
    {
        result |= err_error6;
    }

    expected_result = PRA_BOOL_TRUE;
    if (expected_result != pra_timer_get_time(
                               &expected_time,
                               &actual_ec))
    {
        result |= err_error7;
    }

    expected_result = PRA_BOOL_TRUE;
    if (expected_result != pra_task_execute())
    {
        result |= err_error8;
    }

    if (expected_time != current_time)
    {
        result |= err_error9;
    }

    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_EC_NONE;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_task_remove(
                               &task,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error10;
    }


    expected_result = PRA_BOOL_TRUE;
    if (expected_result != pra_timer_execute())
    {
        result |= err_error11;
    }

    expected_result = PRA_BOOL_TRUE;
    if (expected_result != pra_task_execute())
    {
        result |= err_error12;
    }

    if (expected_time != current_time)
    {
        result |= err_error13;
    }

    expected_result = PRA_BOOL_TRUE;
    if (expected_result != pra_timer_get_time(
                               &expected_time,
                               &actual_ec))
    {
        result |= err_error14;
    }

    if (expected_time == current_time ||
        expected_time != current_time + 1U)
    {
        result |= err_error15;
    }

    return result;
}