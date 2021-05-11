/********************************************** 
 * Univeristy of Southern Denmark
 * Embedded Programming (EMP)
 *
 * MODULENAME: digiswitch
 * PROJECT: digiswitch
 * DESCRIPTION: See module specification file (.h-file)
 * Change log:
 **********************************************
 * Date Ud Change
 * YYMMDD
 * ----------------
 * 11 May 2021 PO Module created.
 *
 ***********************************************/

/***************** Header *********************/
/***************** Include files **************/
#include "digiswitch.h"
/***************** Defines ********************/
/***************** Constants ******************/
/***************** Variables ******************/
TaskHandle_t digiswitch_t;
QueueHandle_t ds_input_queue;
/***************** Functions ******************/
/********************************************** 
 * Input:
 * Output:
 * Function:
 ***********************************************/

void digiswitch_init()
{
    int dummy;

    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0; // Enable port A

    dummy = SYSCTL_RCGC2_R; // Wait for clock enable

    // Enable pins
    GPIO_PORTA_DEN_R |= 0x60;

    // Interrupt on A (PA5)
    GPIO_PORTA_IS_R &= ~(0b00100000); // Edge trigger
    GPIO_PORTA_IBE_R |= 0b00100000; // Both edges
    GPIO_PORTA_IM_R |= 0b00100000; // Interrupt mask

    // NVIC Enable interrupt 0 (GPIOA)
    NVIC_EN0_R |= (1 << 0);
    // Set next highest priority (lowest numberical value) allowed by FreeRTOS
    NVIC_PRI0_R |= (101 << 5);

    // Create input queue
    ds_input_queue = xQueueCreate(DS_INPUT_QUEUE_LENGTH, DS_INPUT_QUEUE_WIDTH);
}

void digiswitch_isr()
{
    if (GPIO_PORTA_RIS_R & 0b00100000)
    {
        // Disable interrupt
        GPIO_PORTA_IM_R &= ~(0b00100000);

        INT8S dir = 0;
        // Rotation dependent on falling or rising edge
        // and the value of B (PA6)
        if (GPIO_PORTA_DATA_R & 0b00100000) // Rising edge
        {
            if (GPIO_PORTA_DATA_R & 0b01000000)
            {
                dir = 1;
            }
            else
            {
                dir = -1;
            }
        }
        else // Faling edge
        {
            if (GPIO_PORTA_DATA_R & 0b01000000)
            {
                dir = -1;
            }
            else
            {
                dir = 1;
            }
        }

        xQueueSendToBack(ds_input_queue, &dir, portMAX_DELAY);

        vTaskNotifyGiveFromISR(digiswitch_t, NULL);
    }
}

void digiswitch_task(void* pvParameters)
{
    digiswitch_t = xTaskGetCurrentTaskHandle();

    while (1)
    {
        // Clear and enable interrupt
        GPIO_PORTA_ICR_R |= 0b00100000;
        GPIO_PORTA_IM_R |= 0b00100000;

        // Wait debounce
        vTaskDelay(pdMS_TO_TICKS(DS_DEBOUNCE_MS));

        // Wait for next interrupt
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
    }
}

INT8S digiswitch_get(TickType_t xTicksToWait)
{
    INT8S dir;
    xQueueReceive(ds_input_queue, &dir, xTicksToWait);
    return dir;
}

/***************** End of module **************/
