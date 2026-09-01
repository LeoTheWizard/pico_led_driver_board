cmake_minimum_required(VERSION 3.13)

# Generate Compile Commands for editor.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

# Project Name
set(PROJECT_NAME led_driver)

project(${PROJECT_NAME} C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(PICO_BOARD pico2)

# Init SDK.
pico_sdk_init()

# Collect sources.
file(GLOB_RECURSE PROJECT_SRCS CONFIGURE_DEPENDS
    ${CMAKE_SOURCE_DIR}/src/*.c
)

# Add source to executable.
add_executable(${PROJECT_NAME}
  ${PROJECT_SRCS}
)

# Enable USB serial console.
pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)

# Link SDK libs
target_link_libraries(${PROJECT_NAME}
    pico_stdlib
    hardware_pio
)

# Generate UF2.
pico_add_extra_outputs(${PROJECT_NAME})

