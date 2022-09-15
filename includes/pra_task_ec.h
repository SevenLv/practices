/*
 * pra_task_ec.h
 * created on Thu Sep 15 2022
 * created by Seven Lv
 * comments:    error code definitions of pra_task
 * version: 0.3
 * history: #       date                modification
 *          0.1     Thu Sep 15 2022     created
 *          0.2     Thu Sep 15 2022     add error code definitions:
 *                                          PRA_TASK_EC_FIND_UNUSED_NODE_FAILED
 *                                          PRA_TASK_EC_INSERT_NODE_FAILED
 *                                          PRA_TASK_EC_APPEND_NODE_FAILED
 *          0.3     Thu Sep 15 2022     add error code definitions:
 *                                          PRA_TASK_EC_NEVER_ADDED
 *                                          PRA_TASK_EC_REMOVE_NODE_FAILED
 */

#ifndef INC_PRA_TASK_EC_H_
#define INC_PRA_TASK_EC_H_

/* includes */
#include "pra_num_defs.h"

/* macros */
#define PRA_TASK_EC_NULL_PTR                PRA_NUM_BIT_MASK_00
#define PRA_TASK_EC_INVALID_EXECUTE_FUNC    PRA_NUM_BIT_MASK_01
#define PRA_TASK_EC_TASK_LIST_FULL          PRA_NUM_BIT_MASK_02
#define PRA_TASK_EC_ALREADY_ADDED           PRA_NUM_BIT_MASK_03
#define PRA_TASK_EC_FIND_UNUSED_NODE_FAILED PRA_NUM_BIT_MASK_04
#define PRA_TASK_EC_INSERT_NODE_FAILED      PRA_NUM_BIT_MASK_05
#define PRA_TASK_EC_APPEND_NODE_FAILED      PRA_NUM_BIT_MASK_06
#define PRA_TASK_EC_NEVER_ADDED             PRA_NUM_BIT_MASK_07
#define PRA_TASK_EC_REMOVE_NODE_FAILED      PRA_NUM_BIT_MASK_08

/* types */

/* variables */

/* functions */

#endif