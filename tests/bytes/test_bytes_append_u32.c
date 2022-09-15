#include "pra_bytes.h"
#include "pra_bytes_ec.h"
#include "pra_defs.h"
#include "test.h"


int main(void);

static uint32_t test_func(
    uint32_t data_to_append,
    pra_boolean (*func)(
        pra_bytes *const,
        const uint32_t,
        uint32_t *const));

int main(void)
{
    int result = err_none;

    result = test_func(
                 0x0708090AU,
                 pra_bytes_append_u32_be) ||
             test_func(
                 0x0A090807U,
                 pra_bytes_append_u32_le);

    return result;
}

static uint32_t test_func(
    uint32_t data_to_append,
    pra_boolean (*func)(
        pra_bytes *const,
        const uint32_t,
        uint32_t *const))
{
    int result = err_none;

    uint8_t   data[10] = { 1U, 2U, 3U, 4U, 5U, 6U };
    pra_bytes bytes = {
        .length = 10,
        .used_length = 6,
        .data = data
    };
    pra_bytes  *p_bytes = &bytes;
    uint32_t    actual_ec = PRA_EC_NONE;
    uint32_t    expected_ec = PRA_EC_NONE;
    pra_boolean expected_result = PRA_BOOL_UNKNOWN;

    actual_ec = PRA_EC_NONE;
    expected_ec = PRA_BYTES_EC_NULL_PTR;
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
    expected_ec = PRA_BYTES_EC_NULL_DATA_PTR;
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
    bytes.used_length = 7;
    actual_ec = PRA_EC_NONE;
    expected_ec = PRA_BYTES_EC_NOT_ENOUGH_LENGTH;
    expected_result = PRA_BOOL_FALSE;
    if (expected_result != func(
                               p_bytes,
                               data_to_append,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error3;
    }

    bytes.used_length = 6;
    actual_ec = PRA_EC_NONE;
    expected_ec = PRA_EC_NONE;
    expected_result = PRA_BOOL_TRUE;
    if (expected_result != func(
                               p_bytes,
                               data_to_append,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        if (10 != bytes.used_length)
        {
            result |= err_error5;
        }
        else if (0x07U != bytes.data[6U] ||
                 0x08U != bytes.data[7U] ||
                 0x09U != bytes.data[8U] ||
                 0x0AU != bytes.data[9U])
        {
            result |= err_error6;
        }
    }

    // TODO:

    return result;
}