/*
 * pra_ec.h
 * created on Thu Sep 15 2022
 * created by Seven Lv
 * comments:    error code definitions
 * version: 0.2
 * history: #       date                modification
 *          0.1     Thu Sep 15 2022     created
 *          0.2     Thu Sep 29 2022     reorganize error codes
 */

#ifndef INC_PRA_EC_H_
#define INC_PRA_EC_H_

/* includes */
#include "pra_num_defs.h"
/* macros */

#define PRA_EC_T      uint32_t
#define PRA_EC_T_NULL PRA_NULL_PTR(PRA_EC_T)

#define PRA_EC_NONE                    PRA_NUM_ZERO_U      /* no error */
#define PRA_EC_NULL_PTR                PRA_NUM_BIT_MASK_00 /* null pointer */
#define PRA_EC_INVALID_OFFSET          PRA_NUM_BIT_MASK_01 /* invalid offset */
#define PRA_EC_INVALID_LENGTH          PRA_NUM_BIT_MASK_02 /* invalid length */
#define PRA_EC_DIFFERENT_LENGTH        PRA_NUM_BIT_MASK_03 /* different length */
#define PRA_EC_NOT_ENOUGH_LENGTH       PRA_NUM_BIT_MASK_04 /* not enough length */
#define PRA_EC_NOT_INIT                PRA_NUM_BIT_MASK_05 /* not initialized */
#define PRA_EC_INVALID_REF_IN          PRA_NUM_BIT_MASK_06 /* invalid ref in */
#define PRA_EC_INVALID_REF_OUT         PRA_NUM_BIT_MASK_07 /* invalid ref out */
#define PRA_EC_REVERSE_FAILED          PRA_NUM_BIT_MASK_08 /* failed to reverse bits */
#define PRA_EC_DATA_FULL               PRA_NUM_BIT_MASK_09 /* data is full */
#define PRA_EC_NEXT_NOT_NULL           PRA_NUM_BIT_MASK_10 /* next pointer is not null */
#define PRA_EC_PREVIOUS_NOT_NULL       PRA_NUM_BIT_MASK_11 /* previous pointer is not null */
#define PRA_EC_INVALID_NEXT            PRA_NUM_BIT_MASK_12 /* invalid next pointer */
#define PRA_EC_INVALID_PREVIOUS        PRA_NUM_BIT_MASK_13 /* invalid previous pointer */
#define PRA_EC_INVALID_CURRENT         PRA_NUM_BIT_MASK_14 /* invalid current pointer */
#define PRA_EC_INVALID_RANGE           PRA_NUM_BIT_MASK_15 /* invalid range */
#define PRA_EC_VALUE_OUT_OF_RANGE      PRA_NUM_BIT_MASK_16 /* out of range */
#define PRA_EC_INVALID_STEP            PRA_NUM_BIT_MASK_17 /* invalid step */
#define PRA_EC_INVALID_EXECUTE_FUNC    PRA_NUM_BIT_MASK_18 /* invalid execute function */
#define PRA_EC_TASK_LIST_FULL          PRA_NUM_BIT_MASK_19 /* task list is full */
#define PRA_EC_ALREADY_ADDED           PRA_NUM_BIT_MASK_20 /* the task is already added */
#define PRA_EC_FIND_UNUSED_NODE_FAILED PRA_NUM_BIT_MASK_21 /* failed to find unused node */
#define PRA_EC_INSERT_NODE_FAILED      PRA_NUM_BIT_MASK_22 /* failed to insert node */
#define PRA_EC_APPEND_NODE_FAILED      PRA_NUM_BIT_MASK_23 /* failed to append node */
#define PRA_EC_NEVER_ADDED             PRA_NUM_BIT_MASK_24 /* the task is never added */
#define PRA_EC_REMOVE_NODE_FAILED      PRA_NUM_BIT_MASK_25 /* failed to remove node */
#define PRA_EC_INVALID_INTERVAL        PRA_NUM_BIT_MASK_26 /* invalid interval */
#define PRA_EC_ALREADY_STARTED         PRA_NUM_BIT_MASK_27 /* the timer is already started */
#define PRA_EC_NOT_STARTED             PRA_NUM_BIT_MASK_28 /* the timer is not started */
#define PRA_EC_CALCULATION_FAILED      PRA_NUM_BIT_MASK_29 /* failed to calculate */

/* types */

/* variables */

/* functions */

#endif