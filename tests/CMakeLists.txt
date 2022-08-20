project(practices_test VERSION 0.1.0)

include_directories(
    ./includes
)

add_executable(test_boolean_is_true test_boolean_is_true.c)
target_link_libraries(test_boolean_is_true practices)
add_test(NAME test_boolean_is_true COMMAND test_boolean_is_true)

add_executable(test_boolean_not test_boolean_not.c)
target_link_libraries(test_boolean_not practices)
add_test(NAME test_boolean_not COMMAND test_boolean_not)
