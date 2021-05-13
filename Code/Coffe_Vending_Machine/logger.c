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
#define LOG_COFFEE_WIDTH    1//sizeof(COFFEE_TYPE)
#define LOG_PAYMENT_WIDTH   sizeof(INT8U)*CARD_LENGTH
#define LOG_LENGTH          10
/***************** Constants ******************/
/***************** Variables ******************/
QueueHandle_t log_coffee_q;
QueueHandle_t log_payment_q;
/***************** Functions ******************/
void log_init()
{
    // Create queues
    log_coffee_q = xQueueCreate(LOG_INPUT_LENGTH, LOG_COFFEE_WIDTH);
    configASSERT(log_coffee_q);

    log_payment_q = xQueueCreate(LOG_INPUT_LENGTH, LOG_PAYMENT_WIDTH);
    configASSERT(log_payment_q);
}

void log_task(void* pvParameters)
{

}

//void log_coffee(COFFEE_TYPE coffee)
//{
//    xQueueSendToBack(log_coffee_q, &coffee, portMAX_DELAY);
//}

void log_payment(INT8U* payment)
{
    xQueueSendToBack(log_coffee_q, &payment, portMAX_DELAY);
}

/********************************************** 
 * Input:
 * Output:
 * Function:
 ***********************************************/

/***************** End of module **************/
