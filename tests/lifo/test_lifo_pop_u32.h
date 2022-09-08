#ifndef TEST_LIFO_POP_U32_H_
#define TEST_LIFO_POP_U32_H_

#include "pra_lifo.h"

#define DATA_LENGTH 10U

typedef pra_boolean (*pop_func)(pra_lifo *const, uint32_t *const, PRA_EC_T *const);
typedef pra_boolean (*push_func)(pra_lifo *const, uint32_t, PRA_EC_T *const);

int test_lifo_pop_u32(
    pop_func pop,
    push_func push);

#endif