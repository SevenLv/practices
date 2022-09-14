/*
 * pra_crc_ec.h
 * created on Wed Sep 14 2022
 * created by Seven Lv
 * comments:    error code definitions of pra_crc
 * version: 0.1
 * history: #       date                modification
 *          0.1     Wed Sep 14 2022     created
 */

#ifndef INC_PRA_CRC_EC_H_
#define INC_PRA_CRC_EC_H_

/* includes */
#include "pra_num_defs.h"

/* macros */

#define PRA_CRC_EC_NONE            PRA_NUM_ZERO_U      /* no error*/
#define PRA_CRC_EC_NULL_PTR        PRA_NUM_BIT_MASK_00 /* null pointer */
#define PRA_CRC_EC_NOT_INIT        PRA_NUM_BIT_MASK_01 /* not initialized */
#define PRA_CRC_EC_INVALID_OFFSET  PRA_NUM_BIT_MASK_02 /* invalid offset */
#define PRA_CRC_EC_INVALID_LENGTH  PRA_NUM_BIT_MASK_03 /* invalid length */
#define PRA_CRC_EC_INVALID_REF_IN  PRA_NUM_BIT_MASK_04 /* invalid ref in */
#define PRA_CRC_EC_INVALID_REF_OUT PRA_NUM_BIT_MASK_05 /* invalid ref out */
#define PRA_CRC_EC_REVERSE_FAILED  PRA_NUM_BIT_MASK_06 /* reverse bits failed */

/* types */

/* variables */

/* functions */

#endif