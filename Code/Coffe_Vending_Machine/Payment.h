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
/*****************************   Constants   *******************************/
/*****************************   Functions   *******************************/
void payment_init (INT8U order);
/*****************************************************************************
*   Input    : INT8U
*   Output   : -
*   Function : Choose payment method
******************************************************************************/

void payment_method(INT8U method, INT8U order);

/*****************************************************************************
*   Input    : INT8U
*   Output   : -
*   Function : Payment function
******************************************************************************/
void payment (INT8U order, INT8U amount);

/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Log payment
******************************************************************************/
void log_payment(void);
/****************************** End Of Module *******************************/




