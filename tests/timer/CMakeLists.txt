project(practices_test VERSION 0.1.0)

include_directories(
    ../
)

add_executable(test_timer_get_time test_timer_get_time.c)
target_link_libraries(test_timer_get_time practices)
add_test(NAME test_timer_get_time COMMAND test_timer_get_time)

add_executable(test_timer_init test_timer_init.c)
target_link_libraries(test_timer_init practices)
add_test(NAME test_timer_init COMMAND test_timer_init)

add_executable(test_timer_start test_timer_start.c)
target_link_libraries(test_timer_start practices)
add_test(NAME test_timer_start COMMAND test_timer_start)

add_executable(test_timer_stop test_timer_stop.c)
target_link_libraries(test_timer_stop practices)
add_test(NAME test_timer_stop COMMAND test_timer_stop)

add_executable(test_timer_is_done test_timer_is_done.c)
target_link_libraries(test_timer_is_done practices)
add_test(NAME test_timer_is_done COMMAND test_timer_is_done)