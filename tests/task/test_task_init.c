#include "pra_ec.h"
#include "pra_task.h"
#include "test.h"


int main(void);

static pra_boolean test_task_execute(
    const uint32_t  time,
    PRA_EC_T *const p_ec);

static pra_boolean test_task_execute(
    const uint32_t  time,
    PRA_EC_T *const p_ec)
{
    return PRA_BOOL_TRUE;
}

int main(void)
{
    int result = err_none;

    pra_task task = {
        .priority = PRA_NUM_MAX_VALUE_U32,
        .execute_func = *test_task_execute,
        .execute_result = PRA_BOOL_TRUE,
        .execute_ec = PRA_EC_NULL_PTR
    };
    const uint32_t              expected_priority = PRA_NUM_ZERO_U;
    const pra_task_execute_func expected_execute_func = PRA_TASK_EXECUTE_FUNC_NULL;
    const pra_boolean           expected_execute_result = PRA_BOOL_UNKNOWN;
    const PRA_EC_T              expected_execute_ec = PRA_EC_NONE;
    pra_boolean                 expected_result = PRA_BOOL_UNKNOWN;
    PRA_EC_T                    expected_ec = PRA_EC_NONE;
    PRA_EC_T                    actual_ec = PRA_EC_NONE;

    expected_result = PRA_BOOL_FALSE;
    if (expected_result != pra_task_init(
                               &task,
                               PRA_EC_T_NULL))
    {
        result |= err_error1;
    }

    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_EC_NULL_PTR;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_task_init(
                               PRA_TASK_NULL,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error2;
    }

    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_EC_NONE;
    actual_ec = PRA_EC_NONE;
    if (expected_result != pra_task_init(
                               &task,
                               &actual_ec) ||
        expected_ec != actual_ec ||
        expected_priority != task.priority ||
        expected_execute_func != task.execute_func ||
        expected_execute_result != task.execute_result ||
        expected_execute_ec != task.execute_ec)
    {
        result |= err_error3;
    }

    return result;
}