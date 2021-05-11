#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include "tm4c123gh6pm.h"
#include "emp_type.h"
#include "FreeRTOS.h"
#include "task.h"
#include "uart0.h"

extern QueueHandle_t uart0_rx_queue;
void test_task(void* pvParameters)
{
    while (1)
    {
        char msg[1];
        char buf[1];
        xQueueReceive(uart0_rx_queue, &msg, portMAX_DELAY);
        uprintf(buf, "%c", *msg);
    }
}

#define PRIORITY_HIGH 3
#define PRIORITY_MEDIUM 1
#define PRIORITY_LOW 1
#define PRIORITY_IDLE 0

int main(void)
{
    // Initialize
    uart0_init(19200, 8, 1, 0);
    init_systick();

    // Create tasks
    xTaskCreate(uart0_write_task, "UART write task",
    configMINIMAL_STACK_SIZE + 50,
                NULL, PRIORITY_LOW, NULL);

    xTaskCreate(test_task, "Test task",
    configMINIMAL_STACK_SIZE + 100,
                NULL, PRIORITY_LOW, NULL);

    // Start scheduler
    vTaskStartScheduler();

    return 1;
}
