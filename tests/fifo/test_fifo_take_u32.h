#ifndef TEST_FIFO_TAKE_U32_
#define TEST_FIFO_TAKE_U32_

#include "pra_fifo.h"

#define DATA_LENGTH 10U

typedef pra_boolean (*take_func)(pra_fifo *const, uint32_t *const, PRA_EC_T *const);
typedef pra_boolean (*append_func)(pra_fifo *const, uint32_t, PRA_EC_T *const);

int test_fifo_take_u32(
    take_func   take,
    append_func append);

#endif