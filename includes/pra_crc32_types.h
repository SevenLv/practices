/*
 * pra_crc32_types.h
 * created on Wed Sep 14 2022
 * created by Seven Lv
 * comments:    type definitions of pra_crc32
 * version: 0.1
 * history: #       date                modification
 *          0.1     Wed Sep 14 2022     created
 */

#ifndef INC_PRA_CRC32_TYPES_H_
#define INC_PRA_CRC32_TYPES_H_

/* includes */
#include "pra_boolean_types.h"
#include "pra_crc.h"
#include "pra_defs.h"
#include "stdint.h"


/* macros */
#define PRA_CRC32_NULL PRA_NULL_PTR(pra_crc32)

/* types */

/* crc16 struct */
typedef struct _pra_crc32
{
    pra_boolean initialized;               /* initialized flag */
    uint32_t    table[PRA_CRC_TABLE_SIZE]; /* the crc32 table */
    uint32_t    polynomial;                /* polynomial */
    uint32_t    initial_value;             /* initial value */
    uint32_t    xor_out;                   /* xor out */
    pra_boolean ref_in;                    /* ref in */
    pra_boolean ref_out;                   /* ref out */
} pra_crc32;

/* variables */

/* functions */

#endif