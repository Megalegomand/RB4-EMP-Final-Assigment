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
#include "payment.h"
#include "coffee.h"

extern QueueHandle_t uart0_rx_queue;
void test_task(void* pvParameters)
{
    while (1)
    {

        char buf[1];
        INT8U msg;
        xQueueReceive(uart0_rx_queue, &msg, portMAX_DELAY);
        //clr_LCD();
        //INT8U key = key_get(portMAX_DELAY);
        //INT8S dir = digiswitch_get(portMAX_DELAY);
        //char buffer[20];
        //sprintf(buffer, "%c%cOffset:", 0x1B, 0xA8);

        //wr_str_LCD(buffer);
        lprintf(0, "Wut");
        lprintf(1, "What? %c", msg);
        //uprintf(buf, "%i", dir);
    }
}

void vAssertCalled(const char * pcFile, unsigned long ulLine)
{
    static portBASE_TYPE xPrinted = pdFALSE;
    volatile uint32_t ulSetToNonZeroInDebuggerToContinue = 0;

    /* Parameters are not used. */
    //(void) ulLine;
    //(void) pcFileName;
    //taskENTER_CRITICAL_FROM_ISR();
    {
        /* You can step out of this function to debug the assertion by using
         the debugger to set ulSetToNonZeroInDebuggerToContinue to a non-zero
         value. */
        while (ulSetToNonZeroInDebuggerToContinue == 0)
        {
        }
    }
    //uart0_sendstring(pcFile,1);
    //uart0_sendstring(ulLine,1);
    taskEXIT_CRITICAL();
}

TaskHandle_t payment_t;
TaskHandle_t coffee_t;

#define PRIORITY_HIGH 3
#define PRIORITY_MEDIUM 2
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
    payment_init();
    coffee_init();
    switch_init();

    // Create tasks
    xTaskCreate(coffee_task, "Coffee task",
    configMINIMAL_STACK_SIZE+100,
                NULL, PRIORITY_LOW, &coffee_t);

    xTaskCreate(payment_task, "Payment task",
    configMINIMAL_STACK_SIZE + 100,
                NULL, PRIORITY_LOW, &payment_t);

    xTaskCreate(uart0_write_task, "UART write task",
    configMINIMAL_STACK_SIZE,
                NULL, PRIORITY_LOW, NULL);

    xTaskCreate(key_task, "Key task",
    configMINIMAL_STACK_SIZE,
                NULL, PRIORITY_IDLE, NULL);

    xTaskCreate(digiswitch_task, "Digiswitch task",
    configMINIMAL_STACK_SIZE,
                NULL, PRIORITY_HIGH, NULL);

    xTaskCreate(lcd_task, "LCD task",
    configMINIMAL_STACK_SIZE,
                NULL, PRIORITY_LOW, NULL);

    xTaskCreate(test_task, "Test task",
    configMINIMAL_STACK_SIZE + 100,
                NULL, PRIORITY_LOW, NULL);

    // Start scheduler
    vTaskStartScheduler();

    return 1;
}
