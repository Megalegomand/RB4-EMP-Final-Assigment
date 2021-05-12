/*****************************************************************************
* University of Southern Denmark
* Embedded C Programming (ECP)
*
* MODULENAME.: CoffeeTask.h
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
#include "key.h"
#include "lcd.h"
#include "payment.h"
/*****************************    Defines    *******************************/
#ifndef COFFEE_H_
#define COFFEE_H_

#define COFFEE_TYPES_LENGTH 10 // Allows for one digit types
#define COFFEE_CYCLE_TIME_MS 3000
/*****************************   Constants   *******************************/
/*****************************   Functions   *******************************/

void brewing (void);

void coffee_init();

void coffee_task(void *pvParameters);



#endif /* COFFEE_H_ */
