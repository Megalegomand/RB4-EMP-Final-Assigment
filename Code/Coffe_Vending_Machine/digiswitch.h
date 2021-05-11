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
#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "emp_type.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
/***************** Defines ********************/ 
#ifndef DIGISWITCH_H_
#define DIGISWITCH_H_

#define DS_INPUT_QUEUE_WIDTH sizeof(INT8S)
#define DS_INPUT_QUEUE_LENGTH 20
#define DS_DEBOUNCE_MS 1
/***************** Variables ******************/ 
/***************** Functions ******************/
void digiswitch_init();
void digiswitch_task(void* pvParameters);
void digiswitch_isr();
INT8S digiswitch_get(TickType_t xTicksToWait);
/********************************************** 
* Input: 
* Output: 
* Function: 
***********************************************/ 

#endif /* DIGISWITCH_H_ */
/***************** End of module **************/
