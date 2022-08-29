/*
 * pra_bits.c
 * created on Mon Aug 29 2022
 * created by Seven Lv
 * comments:    functions of bit functions
 */

/* includes */
#include "pra_bits.h"

/* variables */

/* functions */

pra_bit pra_bit_is_actived(pra_bit value)
{
    pra_bit result = PRA_BIT_UNKNOWN;

    if (PRA_BIT_ACTIVED == value)
    {
        result = PRA_BIT_ACTIVED;
    }
    else
    {
        result = PRA_BIT_INACTIVED;
    }

    return result;
}
