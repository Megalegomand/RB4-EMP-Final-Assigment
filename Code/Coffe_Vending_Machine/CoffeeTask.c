/*****************************************************************************
* University of Southern Denmark
* Embedded C Programming (ECP)
*
* MODULENAME.: CoffeeTask.c
*
* PROJECT: FinalAssignment - Coffe_Vending_Machine
*
* DESCRIPTION:
*
* Date of creation or change:
******************************************************************************
* Month     Day     Year    Change
* 05        08      21
* --------------------
* 090215  MoH   Module created.
*
*****************************************************************************/
/***************************** Include files *******************************/
#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "emp_type.h"
#include "CoffeeTask.h"
/*****************************    Defines    *******************************/
enum CoffeeTask_states
{
Start,
CoffeeType,
Brew,
Log,
}
/*****************************   Constants   *******************************/
/*****************************   Variables   *******************************/
enum COFFEETASK_STATES CoffeeTask_state = Start;
INT8U CoffeeTask_init;
/*****************************   Functions   *******************************/

void Brewing (void)
{
    

}









void Coffee_Task(void *pvParameters)
{
    INT8U CoffeeTask_state = 0;

    COFFEETASK_STATES current_state;
    while(1)
    {
        switch (current_menu)
              {
              case Start:
                  current_menu = 1;
                  break;
              case CoffeeType:
                  current_menu = 1;
                  break;
              case Brew:
                  current_menu = 1;
                  break;
              case Log:
                  current_menu = 1;
                 break;

              }
    }
    
}










/****************************** End Of Module *******************************/
