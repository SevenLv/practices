#ifndef TEST_FIFO_APPEND_U16_
#define TEST_FIFO_APPEND_U16_

#include "pra_fifo.h"

#define DATA_LENGTH 10U

typedef pra_boolean (*append_func)(pra_fifo *const, uint16_t, PRA_EC_T *const);

typedef uint8_t (*get_u8_h_func)(uint16_t);

typedef uint8_t (*get_u8_l_func)(uint16_t);

int test_fifo_append_u16(
    append_func append,
    get_u8_h_func get_u8_h,
    get_u8_l_func get_u8_l);

#endif