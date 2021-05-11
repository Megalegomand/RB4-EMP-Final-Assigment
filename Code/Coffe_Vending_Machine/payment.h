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
/*****************************    Defines    *******************************/
#ifndef PAYMENT_H_
#define PAYMENT_H_



#endif /* PAYMENT_H_ */
typedef struct {
    bool PaymentType;
    int Balance;

} Payment_struct;

/***************** Variables ******************/
typedef enum PAYMENT_STATES{Start, Paymenttype, Card, Cash, Cnumber, Pin, Log, Change} PAYMENT_STATE;
/*****************************   Constants   *******************************/
/*****************************   Functions   *******************************/
void payment_task (void* pvParameters);

PAYMENT_STATES
/*****************************************************************************
*   Input    : INT8U
*   Output   : -
*   Function : Choose payment method
******************************************************************************/

/****************************** End Of Module *******************************/




