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
#ifndef LOGGER_H_
#define LOGGER_H_
/***************** Header *********************/ 
#include "coffee.h"
#include "payment.h"
#include "FreeRTOS.h"
#include "queue.h"
/***************** Include files **************/ 
/***************** Defines ********************/ 
#define LOG_INPUT_LENGTH    1
#define LOG_COFFEE_WIDTH    sizeof(COFFEE_TYPE)
#define LOG_PAYMENT_WIDTH   sizeof(INT8U)*CARD_LENGTH
#define LOG_LENGTH          10

typedef struct COFFEE_TYPE_S COFFEE_TYPE;

struct LOG_TYPE_S
{
    BOOLEAN active;
    INT8U coffee_number;
    INT8U price;
    char payment_type[CARD_LENGTH];
};

typedef struct LOG_TYPE_S LOG_TYPE;
/***************** Variables ******************/ 
/***************** Functions ******************/
void log_init();
void log_task(void* pvParameters);
void log_coffee(COFFEE_TYPE* coffee);
void log_payment(INT8U* payment);
LOG_TYPE* log_nextlog();
/********************************************** 
* Input: 
* Output: 
* Function: 
***********************************************/ 

#endif /* LOGGER_H_ */
/***************** End of module **************/
