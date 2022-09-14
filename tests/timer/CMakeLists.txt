project(practices_test VERSION 0.1.0)

include_directories(
    ../
)

add_executable(test_timer_get_time test_timer_get_time.c)
target_link_libraries(test_timer_get_time practices)
add_test(NAME test_timer_get_time COMMAND test_timer_get_time)