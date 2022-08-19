/*
 * pra_boolean.c
 * created on Wed Aug 17 2022
 * created by Seven Lv
 * comments:    definitions of boolean types, functions of boolean types
 */

/* includes */
#include "pra_boolean.h"

/* variables */

/* functions */

pra_boolean pra_boolean_is_true(pra_boolean value)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;

    if (PRA_BOOL_TRUE == value)
    {
        result = PRA_BOOL_TRUE;
    }
    else
    {
        result = PRA_BOOL_FALSE;
    }

    return result;
}

pra_boolean pra_boolean_not(pra_boolean value)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;

    if (PRA_BOOL_TRUE == value)
    {
        result = PRA_BOOL_FALSE;
    }
    else
    {
        result = PRA_BOOL_TRUE;
    }

    return result;
}