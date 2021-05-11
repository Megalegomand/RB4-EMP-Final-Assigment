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
Log
};
/*****************************   Constants   *******************************/
/*****************************   Variables   *******************************/
//enum CoffeeTask_states CoffeeTask_state = Start;
INT8U CoffeeTask_init;
/*****************************   Functions   *******************************/

void Brewing (void)
{
    

}









void Coffee_Task(void *pvParameters)
{
    INT8U CoffeeTask_state = 0;


    while(1)
    {
    
    }
    
}










/****************************** End Of Module *******************************/
