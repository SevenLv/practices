/*
 * pra_bits_ec.h
 * created on Wed Sep 14 2022
 * created by Seven Lv
 * comments:    error code definitions of pra_bits
 * version: 0.2
 * history: #       date                modification
 *          0.1     Wed Sep 14 2022     created
 *          0.2     Thu Sep 15 2022     remove PRA_BITS_EC_NONE macro
 */

#ifndef INC_PRA_BITS_EC_H_
#define INC_PRA_BITS_EC_H_

/* includes */
#include "pra_num_defs.h"

/* macros */

#define PRA_BITS_EC_NULL_PTR       PRA_NUM_BIT_MASK_00 /* null pointer */
#define PRA_BITS_EC_INVALID_OFFSET PRA_NUM_BIT_MASK_01 /* invalid bit offset */

/* types */

/* variables */

/* functions */

#endif