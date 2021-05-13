/********************************************** 
 * Univeristy of Southern Denmark
 * Embedded Programming (EMP)
 *
 * MODULENAME: logger
 * PROJECT: logger
 * DESCRIPTION: See module specification file (.h-file)
 * Change log:
 **********************************************
 * Date Ud Change
 * YYMMDD
 * ----------------
 * 13 May 2021 PO Module created.
 *
 ***********************************************/

/***************** Header *********************/
/***************** Include files **************/
#include "logger.h"
/***************** Defines ********************/
#define LOG_INPUT_LENGTH    1
#define LOG_COFFEE_WIDTH    sizeof(COFFEE_TYPE)
#define LOG_PAYMENT_WIDTH   sizeof(INT8U)*CARD_LENGTH
#define LOG_LENGTH          10
/***************** Constants ******************/
/***************** Variables ******************/
QueueHandle_t log_coffee_q;
QueueHandle_t log_payment_q;

LOG_TYPE log_array[LOG_LENGTH];
SemaphoreHandle_t log_array_semaphore;
/***************** Functions ******************/
void log_init()
{
    // Create queues
    log_coffee_q = xQueueCreate(LOG_INPUT_LENGTH, LOG_COFFEE_WIDTH);
    configASSERT(log_coffee_q);

    log_payment_q = xQueueCreate(LOG_INPUT_LENGTH, LOG_PAYMENT_WIDTH);
    configASSERT(log_payment_q);

    // Create semaphore for array
    log_array_semaphore = xSemaphoreCreateMutex();
    xSemaphoreGive(log_array_semaphore);
}

void log_task(void* pvParameters)
{
    COFFEE_TYPE* coffee_type;
    INT8U* payment_type;
    while (1)
    {
        xQueueReceive(log_coffee_q, &coffee_type, portMAX_DELAY);
        xQueueReceive(log_payment_q, &payment_type, portMAX_DELAY);

        LOG_TYPE* log = log_nextlog();
    }
}

void log_coffee(COFFEE_TYPE* coffee)
{
    xQueueSendToBack(log_coffee_q, coffee, portMAX_DELAY);
}

void log_payment(INT8U* payment_type)
{
    xQueueSendToBack(log_coffee_q, &payment_type, portMAX_DELAY);
}

LOG_TYPE* log_nextlog() {
    for (int i = 0; i < LOG_LENGTH; i++) {
        if (!log_array[i].active) {
            return &log_array[i];
        }
    }
}

/********************************************** 
 * Input:
 * Output:
 * Function:
 ***********************************************/

/***************** End of module **************/
