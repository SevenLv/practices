/*
 * pra_list_types.h
 * created on Wed Sep 14 2022
 * created by Seven Lv
 * comments:    type definitions of pra_list
 * version: 0.1
 * history: #       date                modification
 *          0.1     Wed Sep 14 2022     created
 */

#ifndef INC_PRA_LIST_TYPES_H_
#define INC_PRA_LIST_TYPES_H_

/* includes */
#include "pra_defs.h"

/* macros */

#define PRA_LIST_ST_NODE_NULL PRA_NULL_PTR(struct _pra_list_node)
#define PRA_LIST_NODE_NULL    PRA_NULL_PTR(pra_list_node)

/* types */

/* linked list node */
typedef struct _pra_list_node
{
    struct _pra_list_node *p_previous; /* pointer of previous node */
    struct _pra_list_node *p_next;     /* pointer of next node */
    void                  *p_data;     /* pointer of current node data */
} pra_list_node;                       /* linked list node */

/* variables */

/* functions */

#endif