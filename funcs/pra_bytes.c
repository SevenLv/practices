/*
 * pra_bytes.c
 * created on Wed Aug 24 2022
 * created by Seven Lv
 * comments:    definitions and functions of the bytes type
 */

/* includes */
#include "pra_bytes.h"
#include "pra_defs.h"

/* variables */

/* functions */

pra_boolean pra_bytes_not_null_ptr(pra_bytes *bytes)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;

    if (PRA_BYTES_NULL == bytes)
    {
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_UINT8_NULL == bytes->bytes)
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}
