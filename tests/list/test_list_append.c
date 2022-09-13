#include "pra_list.h"
#include "test.h"

int main(void);

int main(void)
{
    int result = err_none;

    pra_list_node temp_node;
    pra_list_node current_node;
    pra_list_node next_node;
    pra_boolean   expected_result = PRA_BOOL_UNKNOWN;
    PRA_EC_T      expected_ec = PRA_LIST_EC_NONE;
    PRA_EC_T      actual_ec = PRA_LIST_EC_NONE;

    const struct _pra_list_node *const expected_current_next = (struct _pra_list_node *)(&next_node);
    const struct _pra_list_node *const expected_next_previous = (struct _pra_list_node *)(&current_node);
    const struct _pra_list_node *const expected_next_next = (struct _pra_list_node *)(&temp_node);

    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_LIST_EC_NONE;
    actual_ec = PRA_LIST_EC_NONE;
    if (expected_result != pra_list_init(
                               &current_node,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error1;
    }

    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_LIST_EC_NONE;
    actual_ec = PRA_LIST_EC_NONE;
    if (expected_result != pra_list_init(
                               &next_node,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error2;
    }

    expected_result = PRA_BOOL_FALSE;
    if (expected_result != pra_list_append(
                               &current_node,
                               &next_node,
                               PRA_EC_T_NULL))
    {
        result |= err_error3;
    }

    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_LIST_EC_NULL_PTR;
    actual_ec = PRA_LIST_EC_NONE;
    if (expected_result != pra_list_append(
                               PRA_LIST_NODE_NULL,
                               &next_node,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error4;
    }

    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_LIST_EC_NULL_PTR;
    actual_ec = PRA_LIST_EC_NONE;
    if (expected_result != pra_list_append(
                               &current_node,
                               PRA_LIST_NODE_NULL,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error5;
    }

    current_node.p_next = PRA_LIST_ST_NODE_NULL;
    next_node.p_previous = (struct _pra_list_node *)(&temp_node);
    expected_result = PRA_BOOL_FALSE;
    expected_ec = PRA_LIST_EC_PREVIOUS_NOT_NULL;
    actual_ec = PRA_LIST_EC_NONE;
    if (expected_result != pra_list_append(
                               &current_node,
                               &next_node,
                               &actual_ec) ||
        expected_ec != actual_ec)
    {
        result |= err_error7;
    }

    current_node.p_next = (struct _pra_list_node *)(&temp_node);
    next_node.p_previous = PRA_LIST_ST_NODE_NULL;
    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_LIST_EC_NONE;
    actual_ec = PRA_LIST_EC_NONE;
    if (expected_result != pra_list_append(
                               &current_node,
                               &next_node,
                               &actual_ec) ||
        expected_ec != actual_ec ||
        expected_next_next != next_node.p_next)
    {
        result |= err_error6;
    }

    next_node.p_previous = PRA_LIST_ST_NODE_NULL;
    expected_result = PRA_BOOL_TRUE;
    expected_ec = PRA_LIST_EC_NONE;
    actual_ec = PRA_LIST_EC_NONE;
    if (expected_result != pra_list_append(
                               &current_node,
                               &next_node,
                               &actual_ec) ||
        expected_ec != actual_ec ||
        expected_current_next != current_node.p_next ||
        expected_next_previous != next_node.p_previous)
    {
        result |= err_error8;
    }

    return result;
}