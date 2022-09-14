/*
 * pra_bytes_types.h
 * created on Wed Sep 14 2022
 * created by Seven Lv
 * comments:    type definitions of pra_bytes
 * version: 0.1
 * history: #       date                modification
 *          0.1     Wed Sep 14 2022     created
 */

#ifndef INC_PRA_BYTES_TYPES_H_
#define INC_PRA_BYTES_TYPES_H_

/* includes */
#include "pra_defs.h"
#include "stdint.h"


/* macros */

#define PRA_BYTES_NULL PRA_NULL_PTR(pra_bytes)

/* types */

/* byte array */
typedef struct _pra_bytes
{
    uint16_t length;      /* 字节数组长度 */
    uint16_t used_length; /*有效数据长度*/
    uint8_t *data;        /* 字节数组指针 */
} pra_bytes;

/* variables */

/* functions */

#endif