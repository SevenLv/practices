/*
 * pra_task_types.h
 * created on Thu Sep 15 2022
 * created by Seven Lv
 * comments:    type definitions of pra_task
 * version: 0.1
 * history: #       date                modification
 *          0.1     Thu Sep 15 2022     created
 */

#ifndef INC_PRA_TASK_TYPES_H_
#define INC_PRA_TASK_TYPES_H_

/* includes */
#include "pra_boolean_types.h"
#include "pra_defs.h"
#include "pra_ec.h"
#include "stdint.h"


/* macros */

#define PRA_TASK_NULL              PRA_NULL_PTR(pra_task)
#define PRA_TASK_EXECUTE_FUNC_NULL ((pra_task_execute_func)0)

/* types */

/* task execute function declaration */
typedef pra_boolean (*pra_task_execute_func)(
    const uint32_t,
    PRA_EC_T *const);

/* variables */

/* task struct */
typedef struct _pra_task
{
    uint32_t              priority;       /* task priority */
    pra_task_execute_func execute_func;   /* task execute function */
    pra_boolean           execute_result; /* task execute function return value */
    PRA_EC_T              execute_ec;     /* task execute function error code */
} pra_task;

/* functions */

#endif