project(practices_test VERSION 0.1.0)

include_directories(
    ../
)

add_executable(test_lifo_init test_lifo_init.c)
target_link_libraries(test_lifo_init practices)
add_test(NAME test_lifo_init COMMAND test_lifo_init)