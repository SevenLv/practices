/*
 * pra_fifo_ec.h
 * created on Wed Sep 14 2022
 * created by Seven Lv
 * comments:    error code definitions of pra_fifo
 * version: 0.1
 * history: #       date                modification
 *          0.1     Wed Sep 14 2022     created
 */

#ifndef INC_PRA_FIFO_EC_H_
#define INC_PRA_FIFO_EC_H_

/* includes */
#include "pra_num_defs.h"

/* macros */

#define PRA_FIFO_EC_NONE            PRA_NUM_ZERO_U      /* no error */
#define PRA_FIFO_EC_NULL_PTR        PRA_NUM_BIT_MASK_00 /* null pointer */
#define PRA_FIFO_EC_NOT_INIT        PRA_NUM_BIT_MASK_01 /* not initialized */
#define PRA_FIFO_EC_INVALID_LENGTH  PRA_NUM_BIT_MASK_02 /* invalid length */
#define PRA_FIFO_EC_DATA_FULL       PRA_NUM_BIT_MASK_03 /* the fifo struct is full */
#define PRA_FIFO_EC_DATA_NOT_ENOUGH PRA_NUM_BIT_MASK_04 /* the fifo struct data is not enough */

/* types */

/* variables */

/* functions */

#endif