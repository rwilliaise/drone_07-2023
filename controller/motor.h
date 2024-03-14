
#ifndef MOTOR_H_
#define MOTOR_H_

#include "def.h"

#define MOTOR_PORT GPIOA
#define MOTOR_NE_PIN GPIO_PIN_0
#define MOTOR_SE_PIN GPIO_PIN_1
#define MOTOR_NW_PIN GPIO_PIN_2
#define MOTOR_SW_PIN GPIO_PIN_3
#define MOTOR_CLK_ENABLE __HAL_RCC_GPIOA_CLK_ENABLE

void motor_init ();

#endif // MOTOR_H_

