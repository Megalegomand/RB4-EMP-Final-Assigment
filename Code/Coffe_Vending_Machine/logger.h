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
/***************** Variables ******************/ 
/***************** Functions ******************/
void log_init();
void log_task(void* pvParameters);
//void log_coffee(COFFEE_TYPE coffee);
void log_payment(INT8U* payment);

/********************************************** 
* Input: 
* Output: 
* Function: 
***********************************************/ 

#endif /* LOGGER_H_ */
/***************** End of module **************/
