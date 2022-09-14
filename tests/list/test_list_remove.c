#include "pra_list.h"
#include "pra_list_ec.h"
#include "test.h"


int main(void);

int main(void)
{
    int result = err_none;

    pra_list_node previous_node;
    pra_list_node current_node;
    pra_list_node next_node;

    pra_boolean expected_result = PRA_BOOL_UNKNOWN;
    PRA_EC_T    expected_ec = PRA_LIST_EC_NONE;
    PRA_EC_T    actual_ec = PRA_LIST_EC_NONE;

    expected_result = PRA_BOOL_FALSE;
    if (expected_result != pra_list_remove(
                               &current_node,
                               PRA_EC_T_NULL))
    {
        result |= err_error1;
    }

    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_LIST_EC_NULL_PTR;
    actual_ec = PRA_LIST_EC_NONE;
    if (expected_result != pra_list_remove(
                               PRA_LIST_NODE_NULL,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error2;
    }

    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_LIST_EC_NONE;
    actual_ec = PRA_LIST_EC_NONE;
    if (expected_result != pra_list_init(
                               &previous_node,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error3;
    }

    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_LIST_EC_NONE;
    actual_ec = PRA_LIST_EC_NONE;
    if (expected_result != pra_list_init(
                               &current_node,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error4;
    }

    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_LIST_EC_NONE;
    actual_ec = PRA_LIST_EC_NONE;
    if (expected_result != pra_list_init(
                               &next_node,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error5;
    }

    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_LIST_EC_NONE;
    actual_ec = PRA_LIST_EC_NONE;
    if (expected_result != pra_list_append(
                               &previous_node,
                               &current_node,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error6;
    }

    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_LIST_EC_NONE;
    actual_ec = PRA_LIST_EC_NONE;
    if (expected_result != pra_list_append(
                               &current_node,
                               &next_node,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error7;
    }

    previous_node.p_next = PRA_LIST_ST_NODE_NULL;
    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_LIST_EC_INVALID_NEXT;
    actual_ec = PRA_LIST_EC_NONE;
    if (expected_result != pra_list_remove(
                               &current_node,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error8;
    }

    previous_node.p_next = &current_node;
    next_node.p_previous = PRA_LIST_ST_NODE_NULL;
    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_LIST_EC_INVALID_PREVIOUS;
    actual_ec = PRA_LIST_EC_NONE;
    if (expected_result != pra_list_remove(
                               &current_node,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error9;
    }

    next_node.p_previous = &current_node;
    current_node.p_previous = PRA_LIST_ST_NODE_NULL;
    current_node.p_next = PRA_LIST_ST_NODE_NULL;
    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_LIST_EC_INVALID_CURRENT;
    actual_ec = PRA_LIST_EC_NONE;
    if (expected_result != pra_list_remove(
                               &current_node,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error10;
    }

    current_node.p_previous = &previous_node;
    current_node.p_next = &next_node;
    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_LIST_EC_NONE;
    actual_ec = PRA_LIST_EC_NONE;
    if (expected_result != pra_list_remove(
                               &current_node,
                               &actual_ec) ||
        expected_ec != actual_ec ||
        &next_node != previous_node.p_next ||
        &previous_node != next_node.p_previous ||
        PRA_LIST_ST_NODE_NULL != current_node.p_next ||
        PRA_LIST_ST_NODE_NULL != current_node.p_previous)
    {
        result |= 11;
    }

    return result;
}