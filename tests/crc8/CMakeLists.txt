project(practices_test VERSION 0.1.0)

include_directories(
    ../
)

add_executable(
    test_crc8_default
    test_crc8_default.c
    test_crc8.c)
target_link_libraries(test_crc8_default practices)
add_test(NAME test_crc8_default COMMAND test_crc8_default)

add_executable(
    test_crc8_itu
    test_crc8_itu.c
    test_crc8.c)
target_link_libraries(test_crc8_itu practices)
add_test(NAME test_crc8_itu COMMAND test_crc8_itu)

add_executable(
    test_crc8_rohc
    test_crc8_rohc.c
    test_crc8.c)
target_link_libraries(test_crc8_rohc practices)
add_test(NAME test_crc8_rohc COMMAND test_crc8_rohc)

add_executable(
    test_crc8_maxim
    test_crc8_maxim.c
    test_crc8.c)
target_link_libraries(test_crc8_maxim practices)
add_test(NAME test_crc8_maxim COMMAND test_crc8_maxim)

add_executable(
    test_crc8_cdma2000
    test_crc8_cdma2000.c
    test_crc8.c)
target_link_libraries(test_crc8_cdma2000 practices)
add_test(NAME test_crc8_cdma2000 COMMAND test_crc8_cdma2000)

add_executable(
    test_crc8_wcdma
    test_crc8_wcdma.c
    test_crc8.c)
target_link_libraries(test_crc8_wcdma practices)
add_test(NAME test_crc8_wcdma COMMAND test_crc8_wcdma)