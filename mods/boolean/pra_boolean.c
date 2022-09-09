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

pra_boolean pra_boolean_and(
    pra_boolean value1,
    pra_boolean value2)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;

    if (PRA_BOOL_TRUE == pra_boolean_is_true(value1) &&
        PRA_BOOL_TRUE == pra_boolean_is_true(value2))
    {
        result = PRA_BOOL_TRUE;
    }
    else
    {
        result = PRA_BOOL_FALSE;
    }

    return result;
}

pra_boolean pra_boolean_or(
    pra_boolean value1,
    pra_boolean value2)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;

    if (PRA_BOOL_TRUE == pra_boolean_is_true(value1) ||
        PRA_BOOL_TRUE == pra_boolean_is_true(value2))
    {
        result = PRA_BOOL_TRUE;
    }
    else
    {
        result = PRA_BOOL_FALSE;
    }

    return result;
}

pra_boolean pra_boolean_xor(
    pra_boolean value1,
    pra_boolean value2)
{
    pra_boolean result = PRA_BOOL_UNKNOWN;

    pra_boolean temp1 = PRA_BOOL_UNKNOWN;
    pra_boolean temp2 = PRA_BOOL_UNKNOWN;

    temp1 = pra_boolean_is_true(value1);
    temp2 = pra_boolean_is_true(value2);

    if (temp1 == temp2)
    {
        result = PRA_BOOL_TRUE;
    }
    else
    {
        result = PRA_BOOL_FALSE;
    }

    return result;
}