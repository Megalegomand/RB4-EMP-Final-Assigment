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
#include "coffee.h"
#include "payment.h"
#include "FreeRTOS.h"
#include "queue.h"
/***************** Include files **************/ 
/***************** Defines ********************/ 
#ifndef LOGGER_H_
#define LOGGER_H_
/***************** Variables ******************/ 
/***************** Functions ******************/
void logger_task(void* pvParameters);
void log_coffee();
/********************************************** 
* Input: 
* Output: 
* Function: 
***********************************************/ 

#endif /* LOGGER_H_ */
/***************** End of module **************/
