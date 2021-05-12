/********************************************** 
* Univeristy of Southern Denmark 
* Embedded Programming (EMP) 
* 
* MODULENAME: led
* PROJECT: led
* DESCRIPTION: See module specification file (.h-file) 
* Change log: 
********************************************** 
* Date Ud Change 
* YYMMDD 
* ---------------- 
* 12 May 2021 PO Module created. 
* 
***********************************************/

/***************** Header *********************/ 
/***************** Include files **************/ 
#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "emp_type.h"
/***************** Defines ********************/ 
#ifndef LED_H_
#define LED_H_
/***************** Variables ******************/ 
/***************** Functions ******************/
void led_init();
void led_red();
void led_yellow();
void led_green();
void led_off();
/********************************************** 
* Input: 
* Output: 
* Function: 
***********************************************/ 

#endif /* LED_H_ */
/***************** End of module **************/
