/*
 * pra_version.h
 * created on Fri Sep 02 2022
 * created by Seven Lv
 * comments:    the version
 * version: 0.2
 * history: #       date                modification
 *          0.1     Fri Sep 02 2022     created
 *          0.2     Wed Sep 14 2022     move type definitions to pra_version_types.h
 */

#ifndef INC_PRA_VERSION_H_
#define INC_PRA_VERSION_H_

/* includes */
#include "pra_version_types.h"

/* macros */
#define PRA_VERSION_MAJOR     0
#define PRA_VERSION_MINOR     9
#define PRA_VERSION_REVERSION 29

/* variables */

/* functions */

/**
 * @brief   get the practices library version
 * @note
 * @retval  the practices library version
 */
pra_version pra_get_version(void);

#endif
