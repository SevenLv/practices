/*
 * pra_boolean.h
 * created on Wed Aug 17 2022
 * created by Seven Lv
 * comments:    definitions and fucntions of boolean types
 * version: 0.2
 * history: #       date                modification
 *          0.1     Wed Aug 17 2022     created
 *          0.2     Wed Sep 14 2022     move type definitions to pra_boolean_types.h
 */

#ifndef INC_PRA_BOOLEAN_H_
#define INC_PRA_BOOLEAN_H_

/* includes */
#include "pra_boolean_types.h"

/* macros */

/* types */

/* variables */

/* functions */

/**
 * @brief           determins a pra_boolean value equals to PRA_BOOL_TRUE
 * @note
 * @param  value:   the pra_boolean value
 * @retval          PRA_BOOL_TRUE - if the value equals to PRA_BOOL_TRUE; PRA_BOOL_FALSE - others
 */
pra_boolean pra_boolean_is_true(pra_boolean value);

/**
 * @brief           the NOT operation for pra_boolean
 * @note
 * @param  value:   the pra_boolean value
 * @retval          PRA_BOOL_TRUE - if the value does not equals to PRA_BOOL_TRUE; PRA_BOOL_FALSE - others
 */
pra_boolean pra_boolean_not(pra_boolean value);

/**
 * @brief           the AND operation for pra_boolean
 * @note
 * @param  value1:  the first pra_boolean value
 * @param  value2:  the second pra_boolean value
 * @retval          PRA_BOOL_TRUE - if both of values equal to PRA_BOOL_TRUE; PRA_BOOL_FALSE - others
 */
pra_boolean pra_boolean_and(
    pra_boolean value1,
    pra_boolean value2);

/**
 * @brief           the OR operation for pra_boolean
 * @note
 * @param  value1:  the first pra_boolean value
 * @param  value2:  the second pra_boolean value
 * @retval          PRA_BOOL_TRUE - if any value equals to PRA_BOOL_TRUE; PRA_BOOL_FALSE - others;
 */
pra_boolean pra_boolean_or(
    pra_boolean value1,
    pra_boolean value2);

/**
 * @brief           the XOR operation for pra_boolean
 * @note
 * @param  value1:  the first pra_boolean value
 * @param  value2:  the second pra_boolean value
 * @retval          PRA_BOOL_TRUE - if value1 equals to value2; PRA_BOOL_FALSE - others
 */
pra_boolean pra_boolean_xor(
    pra_boolean value1,
    pra_boolean value2);

#endif