/*
 * pra_defs.h
 * created on Wed Aug 24 2022
 * created by Seven Lv
 * comments:    some defintions
 * version: 0.1
 * history: #       date               modification
 *          0.1     Wed Aug 24 2022    created
 */

#ifndef INC_PRA_DEFS_H_
#define INC_PRA_DEFS_H_

/* includes */
#include "stdint.h"

/* macros */

#define PRA_NULL_PTR(type) ((type *)0)

#define PRA_VOID_NULL   PRA_NULL_PTR(void)
#define PRA_UINT8_NULL  PRA_NULL_PTR(uint8_t)
#define PRA_UINT16_NULL PRA_NULL_PTR(uint16_t)
#define PRA_UINT32_NULL PRA_NULL_PTR(uint32_t)

#define PRA_EC_T      uint32_t
#define PRA_EC_T_NULL PRA_NULL_PTR(PRA_EC_T)

/* types */

/* variables */

/* functions */

#endif