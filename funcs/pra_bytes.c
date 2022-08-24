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

pra_boolean pra_bytes_init(pra_bytes *bytes)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;
    u_int16_t i = 0U;

    if (PRA_BOOL_FALSE == pra_bytes_not_null_ptr(bytes))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        bytes->used_length = 0U;
        for (i = 0U; i < bytes->length; i++)
        {
            bytes->bytes[i] = 0U;
        }

        result = PRA_BOOL_TRUE;
    }

    return result;
}