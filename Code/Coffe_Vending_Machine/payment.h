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
    BOOLEAN PaymentType;
    int Balance;

} Payment_struct;

/***************** Variables ******************/
<<<<<<< Updated upstream:Code/Coffe_Vending_Machine/payment.h
typedef enum PAYMENT_STATES{Start, Paymenttype, Card, Cash, Cnumber, Pin, Log, Change} PAYMENT_STATES;
=======
typedef enum PAYMENT_STATES{START, PAYMENT_TYPE, CARD, CASH, CARD_NUMBER, PIN, LOG, CHANGE} PAYMENT_STATE;
>>>>>>> Stashed changes:Code/Coffe_Vending_Machine/Payment.h
/*****************************   Constants   *******************************/
/*****************************   Functions   *******************************/
void payment_task (void* pvParameters);
PAYMENT_STATES paymenttype_state();
/*****************************************************************************
*   Input    : INT8U
*   Output   : -
*   Function : Choose payment method
******************************************************************************/

/****************************** End Of Module *******************************/




