
#include "def.h"

#include <task.h>

int main(void) {

    SystemInit();
    
    vTaskStartScheduler();
    for (;;);
    return 0;
}

void vApplicationTickHook(void) {}
void vApplicationIdleHook(void) {}
void vApplicationMallocFailedHook(void) {
    taskDISABLE_INTERRUPTS();
    for(;;);
}
void vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName)
{
    taskDISABLE_INTERRUPTS();
    for(;;);
}

