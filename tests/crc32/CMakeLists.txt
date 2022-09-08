project(practices_test VERSION 0.1.0)

include_directories(
    ../
)

add_executable(
    test_crc32_default
    test_crc32_default.c
    test_crc32.c)
target_link_libraries(test_crc32_default practices)
add_test(NAME test_crc32_default COMMAND test_crc32_default)

add_executable(
    test_crc32_mpeg2
    test_crc32_mpeg2.c
    test_crc32.c)
target_link_libraries(test_crc32_mpeg2 practices)
add_test(NAME test_crc32_mpeg2 COMMAND test_crc32_mpeg2)

add_executable(
    test_crc32_bzip2
    test_crc32_bzip2.c
    test_crc32.c)
target_link_libraries(test_crc32_bzip2 practices)
add_test(NAME test_crc32_bzip2 COMMAND test_crc32_bzip2)

add_executable(
    test_crc32_posix
    test_crc32_posix.c
    test_crc32.c)
target_link_libraries(test_crc32_posix practices)
add_test(NAME test_crc32_posix COMMAND test_crc32_posix)

add_executable(
    test_crc32_jamcrc
    test_crc32_jamcrc.c
    test_crc32.c)
target_link_libraries(test_crc32_jamcrc practices)
add_test(NAME test_crc32_jamcrc COMMAND test_crc32_jamcrc)