cmake_minimum_required(VERSION 3.30)
project(MLProject)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(googletest)

FILE(GLOB HEADER_FILE ${CMAKE_SOURCE_DIR}/include/*.hpp)
FILE(GLOB SOURCE_FILE ${CMAKE_SOURCE_DIR}/src/*.cpp)
FILE(GLOB SOURCE_FILE_NOMAIN ${CMAKE_SOURCE_DIR}/src/*.cpp)
FILE(GLOB TEST_FILE ${CMAKE_SOURCE_DIR}/tests/*.cpp)
LIST(REMOVE_ITEM SOURCE_FILE_NOMAIN ${CMAKE_SOURCE_DIR}/src/main.cpp)

add_executable(MLProject ${HEADER_FILE} ${SOURCE_FILE})
add_executable(MLTest ${TEST_FILE} ${HEADER_FILE} ${SOURCE_FILE_NOMAIN})

target_include_directories(MLProject PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(MLTest PUBLIC ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/tests)
target_link_libraries(MLTest gtest gtest_main)

enable_testing()

add_test(NAME MLTest COMMAND MLTest)