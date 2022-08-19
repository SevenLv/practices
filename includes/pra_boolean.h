/*
 * pra_boolean.h
 * created on Wed Aug 17 2022
 * created by Seven Lv
 * comments:    definitions of boolean types, functions of boolean types
 *              normally user should include pra_types_def.h instead of this
 *              file.
 */

#ifndef INC_PRA_BOOLEAN_H_
#define INC_PRA_BOOLEAN_H_

/* includes */

/* macros */

/* the boolean enum type */
typedef enum _pra_boolean
{
    PRA_BOOL_UNKNOWN = 0x00, /* the unknown value of pra_boolean type */
    PRA_BOOL_TRUE = 0x55,    /* the true value of pra_boolean */
    PRA_BOOL_FALSE = 0xAA,   /* the false value of pra_boolean */
} pra_boolean;

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

#endif