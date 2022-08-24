/*
 * pra_bytes.h
 * created on Wed Aug 24 2022
 * created by Seven Lv
 * comments:    definitions and functions of the bytes type
 */

#ifndef INC_PRA_BYTES_H_
#define INC_PRA_BYTES_H_

/* includes */
#include "pra_boolean.h"
#include "stdint.h"

/* macros */

#define PRA_BYTES_NULL ((pra_bytes *)0)

/* types */

/* byte array */
typedef struct _pra_bytes
{
    uint16_t length;      /* 字节数组长度 */
    uint16_t used_length; /*有效数据长度*/
    uint8_t *bytes;       /* 字节数组指针 */
} pra_bytes;

/* variables */

/* functions */

/**
 * @brief           determines a bytes pointer is not null and bytes->bytes is
 * not null
 * @note
 * @param  *bytes:  the bytes pointer
 * @retval          PRA_BOOL_TRUE - the bytes pointer is not null and
 * bytes->bytes is not null; PRA_BOOL_FALSE - others
 */
pra_boolean pra_bytes_not_null_ptr(pra_bytes *bytes);

#endif