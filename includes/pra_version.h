/*
 * pra_version.h
 * created on Fri Sep 02 2022
 * created by Seven Lv
 * comments:    the version
 * version: 0.1
 * history: #       date               modification
 *          0.1     Fri Sep 02 2022    created
 */

#ifndef INC_PRA_VERSION_H_
#define INC_PRA_VERSION_H_

/* includes */
#include "stdint.h"

/* macros */

/* types */
typedef struct _pra_version
{
    uint8_t major;
    uint8_t minor;
    uint8_t reversion;
} pra_version;

/* variables */

/* functions */

/**
 * @brief   get the practices library version
 * @note
 * @retval  the practices library version
 */
pra_version pra_get_version(void);

#endif