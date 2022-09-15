/*
 * pra_task_internal.c
 * created on Thu Sep 15 2022
 * created by Seven Lv
 * comments:    internal functions of pra_task
 * version: 0.1
 * history: #       date                modification
 *          0.1     Thu Sep 15 2022     created
 */

/* includes */
#include "pra_ec.h"
#include "pra_task_ec.h"
#include "pra_task_internal.h"


/* variables */

/* functions */

pra_boolean pra_task_init_args_check(
    const pra_task *const p_task,
    PRA_EC_T *const       p_ec)
{
    pra_boolean result;

    if (PRA_EC_T_NULL == p_ec)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_TASK_NULL == p_task)
    {
        *p_ec |= PRA_TASK_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}