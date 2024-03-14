
#include "motor.h"
#include <stm32wbxx_hal_gpio.h>

void motor_init() {
    GPIO_InitTypeDef GPIO_init;

    MOTOR_CLK_ENABLE();

    GPIO_init.Pin = 
        MOTOR_NE_PIN |
        MOTOR_SE_PIN |
        MOTOR_NW_PIN |
        MOTOR_SW_PIN;
    GPIO_init.Pull = GPIO_NOPULL;
    GPIO_init.Mode = GPIO_MODE_OUTPUT_PP;
    HAL_GPIO_Init(MOTOR_PORT, &GPIO_init);
}
