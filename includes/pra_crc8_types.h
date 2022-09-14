/*
 * pra_crc8_types.h
 * created on Wed Sep 14 2022
 * created by Seven Lv
 * comments:    type definitions of pra_crc8
 * version: 0.1
 * history: #       date                modification
 *          0.1     Wed Sep 14 2022     created
 */

#ifndef INC_PRA_CRC8_TYPES_H_
#define INC_PRA_CRC8_TYPES_H_

/* includes */
#include "pra_boolean_types.h"
#include "pra_crc.h"
#include "pra_defs.h"
#include "stdint.h"


/* macros */
#define PRA_CRC8_NULL PRA_NULL_PTR(pra_crc8)

/* types */

/* crc8 struct */
typedef struct _pra_crc8
{
    pra_boolean initialized;               /* initialized flag */
    uint8_t     table[PRA_CRC_TABLE_SIZE]; /* the crc8 table */
    uint8_t     polynomial;                /* polynomial */
    uint8_t     initial_value;             /* initial value */
    uint8_t     xor_out;                   /* xor out*/
    pra_boolean ref_in;                    /* ref in */
    pra_boolean ref_out;                   /* ref out */
} pra_crc8;

/* variables */

/* functions */

#endif