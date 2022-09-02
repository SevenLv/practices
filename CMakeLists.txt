cmake_minimum_required(VERSION 3.0.0)
project(practices VERSION 0.1.0)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/.output)
set(CMAKE_STATIC_LIBRARY_PREFIX)
include(CPack)

include_directories(
    ./includes
)

aux_source_directory(./funcs ALL_SOURCE)
aux_source_directory(./mods/crc ALL_SOURCE)

add_library(practices STATIC ${ALL_SOURCE})

add_subdirectory(tests)
