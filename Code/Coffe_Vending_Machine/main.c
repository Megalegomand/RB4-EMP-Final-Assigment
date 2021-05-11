#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include "tm4c123gh6pm.h"
#include "emp_type.h"
#include "FreeRTOS.h"
#include "task.h"
#include "uart0.h"
#include "key.h"
#include "systick_frt.h"
#include "digiswitch.h"
#include "lcd.h"

extern QueueHandle_t uart0_rx_queue;
void test_task(void* pvParameters)
{
    while (1)
    {
        //char buf[1];
        INT8U msg;
        xQueueReceive(uart0_rx_queue, &msg, portMAX_DELAY);
        clr_LCD();
        //INT8U key = key_get(portMAX_DELAY);
        //INT8S dir = digiswitch_get(portMAX_DELAY);
        wr_ch_LCD(msg);
        //uprintf(buf, "%i", dir);
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
    key_init();
    digiswitch_init();
    lcd_init();

    // Create tasks
    xTaskCreate(uart0_write_task, "UART write task",
    configMINIMAL_STACK_SIZE + 50,
                NULL, PRIORITY_LOW, NULL);

    xTaskCreate(key_task, "Key task",
        configMINIMAL_STACK_SIZE,
                    NULL, PRIORITY_IDLE, NULL);

    xTaskCreate(digiswitch_task, "Digiswitch task",
            configMINIMAL_STACK_SIZE,
                        NULL, PRIORITY_HIGH, NULL);

    xTaskCreate(lcd_task, "LCD task",
               configMINIMAL_STACK_SIZE + 100,
                            NULL, PRIORITY_LOW, NULL);

    xTaskCreate(test_task, "Test task",
    configMINIMAL_STACK_SIZE + 100,
                NULL, PRIORITY_LOW, NULL);

    // Start scheduler
    vTaskStartScheduler();

    return 1;
}
