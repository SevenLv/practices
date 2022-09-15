/*
 * pra_task.c
 * created on Thu Sep 15 2022
 * created by Seven Lv
 * comments:    functions of pra_task
 * version: 0.1
 * history: #       date                modification
 *          0.1     Thu Sep 15 2022     created
 */

/* includes */
#include "pra_num_defs.h"
#include "pra_task.h"
#include "pra_task_ec.h"
#include "pra_task_internal.h"

/* variables */

/* functions */

pra_boolean pra_task_init(
    pra_task *const p_task,
    PRA_EC_T *const p_ec)
{
    pra_boolean result;

    if (PRA_BOOL_TRUE != pra_task_init_args_check(
                             p_task,
                             p_ec))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        p_task->priority = PRA_NUM_ZERO_U;
        p_task->execute_func = PRA_TASK_EXECUTE_FUNC_NULL;
        p_task->execute_result = PRA_BOOL_UNKNOWN;
        p_task->execute_ec = PRA_EC_NONE;

        result = PRA_BOOL_TRUE;
    }

    return result;
}
