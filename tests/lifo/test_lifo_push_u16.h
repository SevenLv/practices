#ifndef TEST_LIFO_PUSH_U8_H_
#define TEST_LIFO_PUSH_U8_H_

#include "pra_lifo.h"

#define DATA_LENGTH 10U

typedef pra_boolean (*push_func)(pra_lifo *const, uint16_t, PRA_EC_T *const);

typedef uint8_t (*get_u8_h_func)(uint16_t);

typedef uint8_t (*get_u8_l_func)(uint16_t);

int test_lifo_push_u16(
    push_func push,
    get_u8_h_func get_u8_h,
    get_u8_l_func get_u8_l);

#endif