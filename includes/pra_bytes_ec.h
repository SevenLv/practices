/*
 * pra_bytes_ec.h
 * created on Wed Sep 14 2022
 * created by Seven Lv
 * comments:    error code definitions of pra_bytes
 * version: 0.2
 * history: #       date                modification
 *          0.1     Wed Sep 14 2022     created
 *          0.2     Thu Sep 15 2022     remove PRA_BYTES_EC_NONE macro
 */

#ifndef INC_PRA_BYTES_EC_H_
#define INC_PRA_BYTES_EC_H_

/* includes */
#include "pra_num_defs.h"

/* macros */

#define PRA_BYTES_EC_NULL_PTR          PRA_NUM_BIT_MASK_00 /* null pointer */
#define PRA_BYTES_EC_NULL_DATA_PTR     PRA_NUM_BIT_MASK_01 /* null data pointer */
#define PRA_BYTES_EC_DATA_LENGTH_ZERO  PRA_NUM_BIT_MASK_02 /* the length of data is zero */
#define PRA_BYTES_EC_DIFFERENT_LENGTH  PRA_NUM_BIT_MASK_03 /* different length */
#define PRA_BYTES_EC_NOT_ENOUGH_LENGTH PRA_NUM_BIT_MASK_04 /* not enough length */

/* types */

/* variables */

/* functions */

#endif