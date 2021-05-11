/*
 * Payment.h
 *
 *  Created on: 11 May 2021
 *      Author: Philip
 */


/*****************************************************************************
* University of Southern Denmark
* Embedded C Programming (ECP)
*
* MODULENAME.: button.h
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
#include <stdlib.h>
#include "tm4c123gh6pm.h"
#include "emp_type.h"
#include "key.h"
#include "digiswitch.h"
#include "lcd.h"
/*****************************    Defines    *******************************/
#ifndef PAYMENT_H_
#define PAYMENT_H_

#define CARD_METHOD '1'
#define CASH_METHOD '2'
#define CARD_LENGTH 8
#define PIN_LENGTH 4
#define CARD_MAX_ATTEMPTS 3
/***************** Variables ******************/
typedef enum PAYMENT_STATES{START, PAYMENT, CARD, CASH, CARD_NUMBER, PIN, LOG, CHANGE} PAYMENT_STATES;
typedef struct {
    INT8U balance;
    INT8U cardnumber[8];
} PAYMENT_TYPE;
/*****************************   Constants   *******************************/
/*****************************   Functions   *******************************/
void payment_task (void* pvParameters);
PAYMENT_STATES paymenttype_state();
PAYMENT_STATES cardnumber_check_state();
PAYMENT_STATES pin_check_state();
PAYMENT_STATES cash_state();
PAYMENT_STATES change_state();
PAYMENT_STATES log_state();
INT8S key2int(INT8U key);
/*****************************************************************************
*   Input    : INT8U
*   Output   : -
*   Function : Choose payment method
******************************************************************************/

/****************************** End Of Module *******************************/
#endif
