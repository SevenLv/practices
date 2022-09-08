#ifndef INC_TEST_CRC16_H_
#define INC_TEST_CRC16_H_

/* includes */
#include "pra_crc16.h"

/* macros */

/* types */

typedef pra_boolean (*get_func)(pra_crc16 *const, uint32_t *const);

/* variables */

/* functions */

int test_get(get_func get);

int test_init(get_func get);

int test_compute(
    get_func get,
    uint16_t expected_crc_result
);

#endif