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

pra_boolean pra_bytes_not_null_ptr(pra_bytes *bytes, pra_bytes_ec *error_code)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;

    if (PRA_BYTES_NULL == bytes)
    {
        *error_code = PRA_BYTES_EC_NULL_PTR;
        result = PRA_BOOL_FALSE;
    }
    else if (PRA_UINT8_NULL == bytes->data)
    {
        *error_code = PRA_BYTES_EC_NULL_DATA_PTR;
        result = PRA_BOOL_FALSE;
    }
    else
    {
        *error_code = PRA_BYTES_EC_NONE;
        result = PRA_BOOL_TRUE;
    }

    return result;
}

pra_boolean pra_bytes_init(pra_bytes *bytes, pra_bytes_ec *error_code)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;
    u_int16_t i = 0U;

    if (PRA_BOOL_FALSE == pra_bytes_not_null_ptr(bytes, error_code))
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        bytes->used_length = 0U;
        for (i = 0U; i < bytes->length; i++)
        {
            bytes->data[i] = 0U;
        }

        result = PRA_BOOL_TRUE;
    }

    return result;
}