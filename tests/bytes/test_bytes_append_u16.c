#include "pra_bytes.h"
#include "pra_defs.h"
#include "pra_ec.h"
#include "test.h"


int main(void);

static uint32_t test_func(
    uint16_t data_to_append,
    pra_boolean (*func)(
        pra_bytes *const,
        const uint16_t,
        uint32_t *const));

int main(void)
{
    int result = err_none;

    result = test_func(
                 0x090AU,
                 pra_bytes_append_u16_be) ||
             test_func(
                 0x0A09U,
                 pra_bytes_append_u16_le);

    return result;
}

static uint32_t test_func(
    uint16_t data_to_append,
    pra_boolean (*func)(
        pra_bytes *const,
        const uint16_t,
        uint32_t *const))
{
    int result = err_none;

    uint8_t   data[10] = { 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U };
    pra_bytes bytes = {
        .length = 10,
        .used_length = 8,
        .data = data
    };
    pra_bytes  *p_bytes = &bytes;
    uint32_t    actual_ec = PRA_EC_NONE;
    uint32_t    expected_ec = PRA_EC_NONE;
    pra_boolean expected_result = PRA_BOOL_UNKNOWN;

    actual_ec = PRA_EC_NONE;
    expected_ec = PRA_EC_NULL_PTR;
    expected_result = PRA_BOOL_FALSE;
    if (expected_result != func(
                               PRA_BYTES_NULL,
                               data_to_append,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error1;
    }

    bytes.data = PRA_UINT8_NULL;
    p_bytes = &bytes;
    actual_ec = PRA_EC_NONE;
    expected_ec = PRA_EC_NULL_PTR;
    expected_result = PRA_BOOL_FALSE;
    if (expected_result != func(
                               p_bytes,
                               data_to_append,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error2;
    }

    bytes.data = data;
    bytes.used_length = 9;
    actual_ec = PRA_EC_NONE;
    expected_ec = PRA_EC_NOT_ENOUGH_LENGTH;
    expected_result = PRA_BOOL_FALSE;
    if (expected_result != func(
                               p_bytes,
                               data_to_append,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error3;
    }

    bytes.used_length = 8;
    actual_ec = PRA_EC_NONE;
    expected_ec = PRA_EC_NONE;
    expected_result = PRA_BOOL_TRUE;
    if (expected_result != func(
                               p_bytes,
                               data_to_append,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error4;
    }
    else
    {
        if (10 != bytes.used_length)
        {
            result |= err_error5;
        }
        else if (0x09 != bytes.data[8] ||
                 0x0A != bytes.data[9])
        {
            result |= err_error6;
        }
    }

    return result;
}