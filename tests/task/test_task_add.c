#include "pra_ec.h"
#include "pra_task.h"
#include "pra_timer.h"
#include "stdint.h"
#include "test.h"

#define TASKS_COUNT 0x100U

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
    pra_task    tasks[TASKS_COUNT];
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

    task.execute_func = &test_execute;

    expected_result = PRA_BOOL_FALSE;
    if (expected_result != pra_task_add(
                               &task,
                               PRA_EC_T_NULL))
    {
        result |= err_error2;
    }

    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_EC_NULL_PTR;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_task_add(
                               PRA_TASK_NULL,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error3;
    }

    task.execute_func = PRA_TASK_EXECUTE_FUNC_NULL;
    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_EC_INVALID_EXECUTE_FUNC;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_task_add(
                               &task,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error4;
    }

    task.execute_func = &test_execute;
    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_EC_NONE;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_task_add(
                               &task,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error5;
    }

    for (uint32_t i = PRA_NUM_ZERO_U; i < 100U; i++)
    {
        expected_result = PRA_BOOL_TRUE;
        if (expected_result != pra_timer_execute())
        {
            result |= err_error6;
        }

        expected_result = PRA_BOOL_TRUE;
        actual_ec = PRA_EC_NONE;
        if (expected_result != pra_timer_get_time(
                                   &expected_time,
                                   &actual_ec))
        {
            result |= err_error7;
            break;
        }

        expected_result = PRA_BOOL_TRUE;
        if (expected_result != pra_task_execute())
        {
            result |= err_error8;
            break;
        }

        if (expected_time != current_time)
        {
            result |= err_error9;
            break;
        }
    }

    /* PRA_EC_ALREADY_ADDED */
    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_EC_ALREADY_ADDED;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_task_add(
                               &task,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error10;
    }

    /* PRA_EC_TASK_LIST_FULL */
    expected_result = PRA_BOOL_TRUE;
    for (uint32_t i = PRA_NUM_ZERO_U; i < TASKS_COUNT; i++)
    {
        actual_ec = PRA_EC_NONE;
        if (expected_result != pra_task_init(
                                   &tasks[i],
                                   &actual_ec))
        {
            result |= err_error11;
            break;
        }
        else
        {
            tasks[i].execute_func = &test_execute;
        }
    }

    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_EC_NONE;
    for (uint32_t i = PRA_NUM_ZERO_U; i < TASKS_COUNT - 1U; i++)
    {
        actual_ec = PRA_EC_NONE;
        if (expected_result != pra_task_add(
                                   &tasks[i],
                                   &actual_ec) ||
            expected_ec != actual_ec)
        {
            result |= err_error12;
        }
    }

    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_EC_TASK_LIST_FULL;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_task_add(
                               &tasks[TASKS_COUNT - 1U],
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error13;
    }

    return result;
}