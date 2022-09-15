/*
 * pra_list_ec.h
 * created on Wed Sep 14 2022
 * created by Seven Lv
 * comments:    error code definitions of pra_list
 * version: 0.2
 * history: #       date                modification
 *          0.1     Wed Sep 14 2022     created
 *          0.2     Thu Sep 15 2022     remove PRA_LIST_EC_NONE macro
 */

#ifndef INC_PRA_LIST_EC_H_
#define INC_PRA_LIST_EC_H_

/* includes */
#include "pra_num_defs.h"

/* macros */

#define PRA_LIST_EC_NULL_PTR          PRA_NUM_BIT_MASK_00
#define PRA_LIST_EC_NEXT_NOT_NULL     PRA_NUM_BIT_MASK_01
#define PRA_LIST_EC_PREVIOUS_NOT_NULL PRA_NUM_BIT_MASK_02
#define PRA_LIST_EC_INVALID_NEXT      PRA_NUM_BIT_MASK_03
#define PRA_LIST_EC_INVALID_PREVIOUS  PRA_NUM_BIT_MASK_04
#define PRA_LIST_EC_INVALID_CURRENT   PRA_NUM_BIT_MASK_05

/* types */

/* variables */

/* functions */

#endif