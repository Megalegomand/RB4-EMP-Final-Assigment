/********************************************** 
* Univeristy of Southern Denmark 
* Embedded Programming (EMP) 
* 
* MODULENAME: pc_interface
* PROJECT: pc_interface
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
#include "logger.h"
#include "uart0.h"
#include "FreeRTOS.h"
#include "queue.h"
#include "task.h"
/***************** Defines ********************/ 
#ifndef PC_INTERFACE_H_
#define PC_INTERFACE_H_

#define ASCII_ESC 27

typedef enum MENU
{
    MAIN_MENU, LOG_LIST, SALES_REPORT
} MENU;
/***************** Variables ******************/ 
/***************** Functions ******************/
void ui_clear_screen();
void ui_task(void* pvParameters);
MENU main_menu();
MENU log_list_menu();
MENU sales_report_menu();
/********************************************** 
* Input: 
* Output: 
* Function: 
***********************************************/ 

#endif /* PC_INTERFACE_H_ */
/***************** End of module **************/
