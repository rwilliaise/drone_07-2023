cmake_minimum_required(VERSION 3.26)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/stm32-cmake/cmake/stm32_gcc.cmake)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

project(stm32-controller C ASM)

stm32_fetch_cube(WB)


find_package(CMSIS COMPONENTS STM32WB REQUIRED)
find_package(HAL COMPONENTS RCC GPIO CORTEX STM32WB REQUIRED)
find_package(FreeRTOS COMPONENTS RTOS_V2 ARM_CM4_MPU STM32WB)

set(CONTROLLER_SOURCES
    main.c
    motor.c
)

add_executable(stm32-controller ${CONTROLLER_SOURCES})
target_link_libraries(stm32-controller
    HAL::STM32::WB::M4::RCC
    HAL::STM32::WB::M4::GPIO
    HAL::STM32::WB::M4::CORTEX
    FreeRTOS::STM32::WB::Timers
    FreeRTOS::STM32::WB::Heap::1
    FreeRTOS::STM32::WB::ARM_CM4_MPU
    CMSIS::STM32::WB35CC::M4
    CMSIS::STM32::WB::M4::RTOS_V2
    STM32::NoSys
)
target_compile_definitions(stm32-controller PRIVATE
    USE_CMSIS_RTOS_V2
    CMSIS_RTOS_V2_DEVICE_HEADER="stm32wbxx_hal.h"
)
stm32_print_size_of_target(stm32-controller)
stm32_generate_binary_file(stm32-controller)
stm32_generate_hex_file(stm32-controller)
