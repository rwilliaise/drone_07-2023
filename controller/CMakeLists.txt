cmake_minimum_required(VERSION 3.26)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/stm32-cmake/cmake/stm32_gcc.cmake)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

project(stm32-controller C ASM)

stm32_fetch_cube(WB)

find_package(CMSIS COMPONENTS STM32WB REQUIRED)
find_package(HAL COMPONENTS RCC GPIO CORTEX STM32WB REQUIRED)

set(CONTROLLER_SOURCES
    main.c
)

add_executable(stm32-controller ${CONTROLLER_SOURCES})
target_link_libraries(stm32-controller
    HAL::STM32::WB::M4::RCC
    HAL::STM32::WB::M4::GPIO
    HAL::STM32::WB::M4::CORTEX
    CMSIS::STM32::WB35CC::M4
    STM32::NoSys
)
stm32_print_size_of_target(stm32-controller)
