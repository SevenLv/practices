/*
 * pra_bytes.h
 * created on Wed Aug 24 2022
 * created by Seven Lv
 * comments:    definitions and functions of bytes type
 */

#ifndef INC_PRA_BYTES_H_
#define INC_PRA_BYTES_H_

/* includes */
#include "pra_types_def.h"

/* macros */

/* types */

/* 字节数组 */
typedef struct _pra_bytes {
  UINT16 length;      /* 字节数组长度 */
  UINT16 used_length; /*有效数据长度*/
  UINT8 *bytes;       /* 字节数组指针 */
} pra_bytes;

/* variables */

/* functions */

#endif