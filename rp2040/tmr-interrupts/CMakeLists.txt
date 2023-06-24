# The example below was taken from https://www.digikey.com/en/maker/projects/raspberry-pi-pico-and-rp2040-cc-part-1-blink-and-vs-code/7102fb8bca95452e9df6150f39ae8422

# Set minimum required version of CMake
cmake_minimum_required(VERSION 3.12)

# Include build functions from Pico SDK
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

# Set name of project (as PROJECT_NAME) and C/C++ standards
project(tmr-interrupts C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Creates a pico-sdk subdirectory in our project for the libraries
pico_sdk_init()

# Tell CMake where to find the executable source file
add_executable(tmr-interrupts
    main.c
    system.c
    interrupts.c
)

# Create map/bin/hex/uf2 files
pico_add_extra_outputs(tmr-interrupts)

# Link to pico_stdlib (gpio, time, etc. functions)
target_link_libraries(tmr-interrupts
    pico_stdlib
)

# Enable usb output, disable uart output
# pico_enable_stdio_usb(blinky 1)
# pico_enable_stdio_uart(blinky 0)