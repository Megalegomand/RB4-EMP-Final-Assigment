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
#include "coffee.h"
/*****************************    Defines    *******************************/
typedef enum CoffeeTask_states
{
Start,
CoffeeType,
Brew,
Log,
} CoffeeTask_states;

typedef struct {
   char  Name[20];
   int   Price;
} CoffeeType1;

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

    CoffeeTask_states current_state;
    while(1)
    {
        switch (current_state)
              {
              case Start:
                  current_state = 1;
                  break;
              case CoffeeType:
                  current_state = 1;
                  break;
              case Brew:
                  current_state = 1;
                  break;
              case Log:
                  current_state = 1;
                 break;

              }
    }
    
}










/****************************** End Of Module *******************************/
