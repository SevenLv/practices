/*
 * pra_timer_ec.h
 * created on Wed Sep 14 2022
 * created by Seven Lv
 * comments:    error code definitions of pra_timer
 * version: 0.2
 * history: #       date                modification
 *          0.1     Wed Sep 14 2022     created
 *          0.2     Wed Sep 14 2022     add PRA_TIMER_EC_NOT_STARTED macro
 *                                      add PRA_TIMER_EC_CALCULATION_FAILED macro
 */

#ifndef INC_H_
#define INC_H_

/* includes */
#include "pra_num_defs.h"

/* macros */
#define PRA_TIMER_EC_NONE               PRA_NUM_ZERO_U
#define PRA_TIMER_EC_NULL_PTR           PRA_NUM_BIT_MASK_00
#define PRA_TIMER_EC_INVALID_INTERVAL   PRA_NUM_BIT_MASK_01
#define PRA_TIMER_EC_ALREADY_STARTED    PRA_NUM_BIT_MASK_02
#define PRA_TIMER_EC_NOT_STARTED        PRA_NUM_BIT_MASK_03
#define PRA_TIMER_EC_CALCULATION_FAILED PRA_NUM_BIT_MASK_04

/* types */

/* variables */

/* functions */

#endif