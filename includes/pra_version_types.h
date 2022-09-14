/*
 * pra_version_types.h
 * created on Wed Sep 14 2022
 * created by Seven Lv
 * comments:    type definitions of pra_version
 * version: 0.1
 * history: #       date                modification
 *          0.1     Wed Sep 14 2022     created
 */

#ifndef INC_PRA_VERSION_TYPES_H_
#define INC_PRA_VERSION_TYPES_H_

/* includes */
#include "stdint.h"

/* macros */

/* types */

/* types */
typedef struct _pra_version
{
    uint8_t major;
    uint8_t minor;
    uint8_t reversion;
} pra_version;

/* variables */

/* functions */

#endif