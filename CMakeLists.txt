cmake_minimum_required(VERSION 3.12)
include(pico_sdk_import.cmake)

project(oledtest C CXX ASM)

pico_sdk_init()
add_executable(oledtest)

add_subdirectory(../libpo13 libpo13)

target_sources(oledtest PUBLIC ${CMAKE_CURRENT_LIST_DIR}/src/main.c)

target_link_libraries(
        oledtest PUBLIC
        po13
        pico_stdlib
        hardware_pwm
        )

pico_add_extra_outputs(oledtest)
