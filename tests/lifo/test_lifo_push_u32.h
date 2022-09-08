#ifndef TEST_LIFO_PUSH_U32_H_
#define TEST_LIFO_PUSH_U32_H_

#include "pra_lifo.h"

#define DATA_LENGTH 10U

typedef pra_boolean (*push_func)(pra_lifo *const, uint32_t, PRA_EC_T *const);

typedef uint8_t (*get_u8_h_func)(uint32_t);

typedef uint8_t (*get_u8_m_h_func)(uint32_t);

typedef uint8_t (*get_u8_m_l_func)(uint32_t);

typedef uint8_t (*get_u8_l_func)(uint32_t);

int test_lifo_push_u32(
    push_func push,
    get_u8_h_func get_u8_h,
    get_u8_m_h_func get_u8_m_h,
    get_u8_m_l_func get_u8_m_l,
    get_u8_l_func get_u8_l);

#endif