/*
 * pra_version.c
 * created on Fri Sep 02 2022
 * created by Seven Lv
 * comments:    version function of practices
 * version: 0.1
 * history: #       date               modification
 *          0.1     Fri Sep 02 2022    created
 */

/* includes */
#include "pra_version.h"

/* variables */
static pra_version const version = {
    .major = 0U,
    .minor = 4U,
    .reversion = 18U
};

/* functions */

pra_version pra_get_version(void)
{
    return version;
}