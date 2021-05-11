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
#include "emp_type.h"
/*****************************    Defines    *******************************/
#ifndef PAYMENT_H_
#define PAYMENT_H_



#endif /* PAYMENT_H_ */
typedef struct {
    BOOLEAN paymentType;
    INT8U balance;
    INT8U cardnumber[8];
} PAYMENT_TYPE;

/***************** Variables ******************/
typedef enum PAYMENT_STATES{START, PAYMENT_TYPE, CARD, CASH, CARD_NUMBER, PIN, LOG, CHANGE} PAYMENT_STATES;

/*****************************   Constants   *******************************/
/*****************************   Functions   *******************************/
void payment_task (void* pvParameters);
PAYMENT_STATES paymenttype_state();
PAYMENT_STATES cardnumber_check_state();
PAYMENT_STATES pin_check_state();

/*****************************************************************************
*   Input    : INT8U
*   Output   : -
*   Function : Choose payment method
******************************************************************************/

/****************************** End Of Module *******************************/




