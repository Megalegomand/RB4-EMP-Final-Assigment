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
#include "switch.h"
#include "task.h"
#include "led.h"
/*****************************    Defines    *******************************/
#ifndef COFFEE_H_
#define COFFEE_H_

#define COFFEE_TYPES_LENGTH 10 // Allows for one digit types
#define COFFEE_CYCLE_TIME_MS 3000

#define SWITCH_POLL_DELAY_MS 500 // Also determines display flash rate
#define SLOW_DISPENSE_TIME_MS 2000.0f
#define SLOW_DISPENSE_AMOUNT 0.5f
#define FAST_DISPENSE_AMOUNT 1.0f
#define MAX_INACTIVITY_MS 5000.0f
/*****************************   Constants   *******************************/
/*****************************   Functions   *******************************/

void coffee_init();

void coffee_task(void *pvParameters);



#endif /* COFFEE_H_ */
