project(practices_test VERSION 0.1.0)

include_directories(
    ../
)

add_executable(
    test_crc16_arc
    test_crc16_arc.c
    test_crc16.c)
target_link_libraries(test_crc16_arc practices)
add_test(NAME test_crc16_arc COMMAND test_crc16_arc)

add_executable(
    test_crc16_maxim
    test_crc16_maxim.c
    test_crc16.c)
target_link_libraries(test_crc16_maxim practices)
add_test(NAME test_crc16_maxim COMMAND test_crc16_maxim)

add_executable(
    test_crc16_usb
    test_crc16_usb.c
    test_crc16.c)
target_link_libraries(test_crc16_usb practices)
add_test(NAME test_crc16_usb COMMAND test_crc16_usb)

add_executable(
    test_crc16_modbus
    test_crc16_modbus.c
    test_crc16.c)
target_link_libraries(test_crc16_modbus practices)
add_test(NAME test_crc16_modbus COMMAND test_crc16_modbus)

add_executable(
    test_crc16_ccitt_false
    test_crc16_ccitt_false.c
    test_crc16.c)
target_link_libraries(test_crc16_ccitt_false practices)
add_test(NAME test_crc16_ccitt_false COMMAND test_crc16_ccitt_false)

add_executable(
    test_crc16_x25
    test_crc16_x25.c
    test_crc16.c)
target_link_libraries(test_crc16_x25 practices)
add_test(NAME test_crc16_x25 COMMAND test_crc16_x25)

add_executable(
    test_crc16_xmodem
    test_crc16_xmodem.c
    test_crc16.c)
target_link_libraries(test_crc16_xmodem practices)
add_test(NAME test_crc16_xmodem COMMAND test_crc16_xmodem)

add_executable(
    test_crc16_dnp
    test_crc16_dnp.c
    test_crc16.c)
target_link_libraries(test_crc16_dnp practices)
add_test(NAME test_crc16_dnp COMMAND test_crc16_dnp)