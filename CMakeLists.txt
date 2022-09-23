cmake_minimum_required(VERSION 3.0.0)
project(practices VERSION 0.7.28)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
configure_file(
    ${PROJECT_SOURCE_DIR}/pra_version.h.in
    ${PROJECT_SOURCE_DIR}/includes/pra_version.h)

if(CMAKE_BUILD_TYPE MATCHES "Debug")
    set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/.output/${CPACK_PROJECT_VERSION}/debug)
else()
    set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/.output/${CPACK_PROJECT_VERSION}/release)
endif()

set(CMAKE_STATIC_LIBRARY_PREFIX)
include(CPack)

include_directories(
    ./includes
)

aux_source_directory(./funcs ALL_SOURCE)
aux_source_directory(./mods ALL_SOURCE)
aux_source_directory(./mods/bits ALL_SOURCE)
aux_source_directory(./mods/boolean ALL_SOURCE)
aux_source_directory(./mods/bytes ALL_SOURCE)
aux_source_directory(./mods/crc ALL_SOURCE)
aux_source_directory(./mods/fifo ALL_SOURCE)
aux_source_directory(./mods/lifo ALL_SOURCE)
aux_source_directory(./mods/list ALL_SOURCE)
aux_source_directory(./mods/timer ALL_SOURCE)
aux_source_directory(./mods/task ALL_SOURCE)
aux_source_directory(./mods/stepper ALL_SOURCE)

add_library(practices STATIC ${ALL_SOURCE})

add_subdirectory(tests)

install(
    DIRECTORY "${PROJECT_SOURCE_DIR}/includes/"
    DESTINATION "${LIBRARY_OUTPUT_PATH}/includes/")