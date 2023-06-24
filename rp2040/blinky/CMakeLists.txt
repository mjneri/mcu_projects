# This CMakeLists file was mostly copied from the CMakeLists files found within
# subdirectories of raspberrypi/pico-examples

# add_executable(blinky
#         main.c
#         )

# # Pull in our pico_stdlib which pulls in commonly used features
# target_link_libraries(blinky pico_stdlib)

# # create map/bin/hex file etc.
# pico_add_extra_outputs(blinky)

# # add url via pico_set_program_url
# example_auto_set_url(blinky)


# The example below was taken from https://www.digikey.com/en/maker/projects/raspberry-pi-pico-and-rp2040-cc-part-1-blink-and-vs-code/7102fb8bca95452e9df6150f39ae8422

# Set minimum required version of CMake
cmake_minimum_required(VERSION 3.12)

# Include build functions from Pico SDK
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

# Set name of project (as PROJECT_NAME) and C/C++ standards
project(blink C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Creates a pico-sdk subdirectory in our project for the libraries
pico_sdk_init()

# Tell CMake where to find the executable source file
add_executable(blinky
    main.c
    system.c
)

# Create map/bin/hex/uf2 files
pico_add_extra_outputs(blinky)

# Link to pico_stdlib (gpio, time, etc. functions)
target_link_libraries(blinky
    pico_stdlib
)

# Enable usb output, disable uart output
# pico_enable_stdio_usb(blinky 1)
# pico_enable_stdio_uart(blinky 0)