/*
 * pra_stp_cycle_ec.h
 * created on Thu Sep 22 2022
 * created by Seven Lv
 * comments:    error code definitions of cycle stepper
 * version: 0.1
 * history: #       date                modification
 *          0.1     Thu Sep 22 2022     created
 */

#ifndef INC_PRA_STP_CYCLE_EC_H_
#define INC_PRA_STP_CYCLE_EC_H_

/* includes */
#include "pra_ec.h"
#include "pra_num_defs.h"

/* macros */

#define PRA_STP_CYCLE_EC_NONE               PRA_EC_NONE
#define PRA_STP_CYCLE_EC_NULL_PTR           PRA_NUM_BIT_MASK_00
#define PRA_STP_CYCLE_EC_INVALID_RANGE      PRA_NUM_BIT_MASK_01
#define PRA_STP_CYCLE_EC_VALUE_OUT_OF_RANGE PRA_NUM_BIT_MASK_02
#define PRA_STP_CYCLE_EC_INVALID_STEP       PRA_NUM_BIT_MASK_03

/* types */

/* variables */

/* functions */

#endif