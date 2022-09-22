project(practices_test VERSION 0.1.0)

include_directories(
    ../
)

add_executable(test_stp_cycle_u8 test_stp_cycle_u8.c)
target_link_libraries(test_stp_cycle_u8 practices)
add_test(NAME test_stp_cycle_u8 COMMAND test_stp_cycle_u8)