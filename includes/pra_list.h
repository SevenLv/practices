/*
 * list.h
 * created on Tue Sep 13 2022
 * created by Seven Lv
 * comments:    definitions and functions of linked list
 */

#ifndef INC_PRA_LIST_H_
#define INC_PRA_LIST_H_

/* includes */
#include "pra_boolean.h"
#include "pra_defs.h"
#include "pra_num_defs.h"
#include "stdio.h"

/* macros */

#define PRA_LIST_ST_NODE_NULL PRA_NULL_PTR(struct pra_list_node)
#define PRA_LIST_NODE_NULL    PRA_NULL_PTR(pra_list_node)

#define PRA_LIST_EC_NONE     PRA_NUM_ZERO_U
#define PRA_LIST_EC_NULL_PTR PRA_NUM_BIT_MASK_00

/* types */

/* linked list node */
typedef struct _pra_list_node
{
    struct pra_list_node *p_previous; /* pointer of previous node */
    struct pra_list_node *p_next;     /* pointer of next node */
    void                 *p_data;     /* pointer of current node data */
} pra_list_node;

/* variables */

/* functions */

/**
 * @brief           initialize a pra_list_node struct
 * @note
 * @param  *p_node: pointer of the node
 * @param  *p_ec:   output error code:
 *                  PRA_LIST_EC_NULL_PTR
 * @retval          PRA_BOOL_TRUE - success; PRA_BOOL_FALSE - failed
 */
pra_boolean pra_list_init(
    pra_list_node *const p_node,
    PRA_EC_T            *p_ec);

#endif