#THIS FILE IS AUTO GENERATED FROM THE TEMPLATE! DO NOT CHANGE!
SET(CMAKE_SYSTEM_NAME Generic)
SET(CMAKE_SYSTEM_VERSION 1)
cmake_minimum_required(VERSION 3.19)

# specify cross compilers and tools
SET(CMAKE_C_COMPILER arm-none-eabi-gcc)
SET(CMAKE_CXX_COMPILER arm-none-eabi-g++)
SET(CMAKE_ASM_COMPILER arm-none-eabi-gcc)
SET(CMAKE_AR arm-none-eabi-ar)
SET(CMAKE_OBJCOPY arm-none-eabi-objcopy)
SET(CMAKE_OBJDUMP arm-none-eabi-objdump)
SET(SIZE arm-none-eabi-size)
SET(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

SET(CMAKE_COMPILE_FILES_DIR ${CMAKE_SOURCE_DIR}/compile_files)

# project SETtings
project(NRF_FREERTOS_CMAKE_TEMPLATE C CXX ASM)
SET(CMAKE_CXX_STANDARD 14)
SET(CMAKE_C_STANDARD 11)


# uncomment to mitigate c++17 absolute addresses warnings
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-register")

if ("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
    message(STATUS "Maximum optimization for speed")
    add_compile_options(-Ofast)
elseif ("${CMAKE_BUILD_TYPE}" STREQUAL "RelWithDebInfo")
    message(STATUS "Maximum optimization for speed, debug info included")
    add_compile_options(-Ofast -g)
elseif ("${CMAKE_BUILD_TYPE}" STREQUAL "MinSizeRel")
    message(STATUS "Maximum optimization for size")
    add_compile_options(-Os)
else ()
    message(STATUS "Minimal optimization, debug info included")
    add_compile_options(-Og -g)
endif ()

include_directories(
    include
    include/commons
    include/devices/
    include/devices/mcus/nrf_commons
    include/devices/mcus/nrf52840
    include/devices/mcus/nrf52840/boot
    include/devices/mcus/nrf52840/freeRTOS_port
    include/devices/mcus/nrf52840/it
    include/drivers
    include/drivers/hal
    include/drivers/nrfx
    include/drivers/nrfx/prs
    include/freeRTOS
    include/system
)

file(GLOB_RECURSE SOURCES
        "include/**"
        "src/**",
        )

add_definitions(-DNRF52840_XXAA)

SET(COMMON_LINKER_SCRIPT ${CMAKE_COMPILE_FILES_DIR}/nrf_common.ld)
SET(LINKER_SCRIPT ${CMAKE_COMPILE_FILES_DIR}/nrf52840_xxaa.ld)


# let linker dump unused sections and print memory useage
add_link_options(-Wl,-gc-sections,--print-memory-usage,-Map=${PROJECT_BINARY_DIR}/${PROJECT_NAME}.map)
add_link_options(-mcpu=cortex-m4 -mthumb -mthumb-interwork)
add_link_options(-T ${LINKER_SCRIPT})

# build related commands
SET(HEX_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.hex)
SET(BIN_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.bin)


# use newlib in nano version
SET(NO_SYS_LIB_FLAGS "-specs=nano.specs")
# enable float support in snprintf
SET(COMMON_FLAGS "-u _printf_float -u _scanf_float")
# Add standard libraries at the very end of the linker input, after all objects
# that may need symbols provided by these libraries.
SET(STANDARD_LIB "-lc -lnosys -lm")

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${COMMON_FLAGS} ${NO_SYS_LIB_FLAGS} ${STANDARD_LIB}")

# enable fpu support
add_compile_options(-mcpu=cortex-m4 -mthumb -mthumb-interwork)
add_compile_options(-mfloat-abi=hard -mfpu=fpv4-sp-d16)
add_link_options(-mfloat-abi=hard -mfpu=fpv4-sp-d16)

add_executable(${PROJECT_NAME}.elf ${SOURCES} ${COMMON_LINKER_SCRIPT} ${LINKER_SCRIPT})

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -Oihex $<TARGET_FILE:${PROJECT_NAME}.elf> ${HEX_FILE}
    COMMAND ${CMAKE_OBJCOPY} -Obinary $<TARGET_FILE:${PROJECT_NAME}.elf> ${BIN_FILE}
    COMMENT "Building ${HEX_FILE}
            Building ${BIN_FILE}"
)
