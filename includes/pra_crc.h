/*
 * pra_crc.h
 * created on Fri Sep 02 2022
 * created by Seven Lv
 * comments:
 */

#ifndef INC_PRA_CRC_H_
#define INC_PRA_CRC_H_

/* includes */

/* macros */
#define PRA_CRC_TABLE_SIZE 0x100U /* table size */

#define PRA_CRC_EC_NONE 0x0U             /* no error*/
#define PRA_CRC_EC_NULL_PTR 0x1U         /* null pointer */
#define PRA_CRC_EC_NOT_INIT 0x2U         /* not initialized */
#define PRA_CRC_EC_INVALID_OFFSET 0x4U   /* invalid offset */
#define PRA_CRC_EC_INVALID_LENGTH 0x8U   /* invalid length */
#define PRA_CRC_EC_INVALID_REF_IN 0x10U  /* invalid ref in */
#define PRA_CRC_EC_INVALID_REF_OUT 0x20U /* invalid ref out */

/* types */

/* variables */

/* functions */

#endif