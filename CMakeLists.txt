cmake_minimum_required(VERSION 3.0.0)
project(practices VERSION 0.1.0)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

if(CMAKE_BUILD_TYPE MATCHES "Debug")
    set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/.output/debug)
else()
    set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/.output/release)
endif()

set(CMAKE_STATIC_LIBRARY_PREFIX)
include(CPack)

include_directories(
    ./includes
)

aux_source_directory(./funcs ALL_SOURCE)
aux_source_directory(./mods/crc ALL_SOURCE)
aux_source_directory(./mods/fifo ALL_SOURCE)
aux_source_directory(./mods/lifo ALL_SOURCE)

add_library(practices STATIC ${ALL_SOURCE})

add_subdirectory(tests)
