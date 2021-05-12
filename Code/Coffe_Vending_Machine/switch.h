/********************************************** 
* Univeristy of Southern Denmark 
* Embedded Programming (EMP) 
* 
* MODULENAME: switch
* PROJECT: switch
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
#ifndef SWITCH_H_
#define SWITCH_H_
/***************** Variables ******************/ 
/***************** Functions ******************/
void switch_init();
/********************************************** 
* Input: 
* Output: 
* Function: 
***********************************************/ 

INT8U get_sw1();
INT8U get_sw2();

#endif /* SWITCH_H_ */
/***************** End of module **************/
