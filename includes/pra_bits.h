/*
 * pra_bits.h
 * created on Mon Aug 29 2022
 * created by Seven Lv
 * comments:    functions of bit functions
 */

#ifndef INC_PRA_BITS_H_
#define INC_PRA_BITS_H_

/* includes */
#include "pra_boolean.h"

/* macros */

/* types */

/* the bit value */
typedef enum _pra_bit {
  PRA_BIT_UNKNOWN = PRA_BOOL_UNKNOWN, /* unknown bit value */
  PRA_BIT_INACTIVED = PRA_BOOL_FALSE, /* inactived */
  PRA_BIT_ACTIVED = PRA_BOOL_TRUE     /* actived */
} pra_bit;

/* variables */

/* functions */

/**
 * @brief           determins a pra_bit value equals to PRA_BIT_ACTIVED
 * @note
 * @param  value:   the pra_bit vlaue
 * @retval          PRA_BIT_ACTIVED - if the value equals to PRA_BIT_ACTIVED; PRA_BIT_INACTIVED - others
 */
pra_bit pra_bit_is_actived(pra_bit value);

#endif