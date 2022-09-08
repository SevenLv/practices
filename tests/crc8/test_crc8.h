#ifndef INC_TEST_CRC8_H_
#define INC_TEST_CRC8_H_

/* includes */
#include "pra_boolean.h"
#include "pra_crc8.h"

/* macros */

/* types */

typedef pra_boolean (*get_func)(pra_crc8 *const, uint32_t *const);

/* variables */

/* functions */

int test_get(get_func get);

int test_init(get_func get);

int test_compute(
    get_func get,
    uint8_t expected_crc_result);

#endif