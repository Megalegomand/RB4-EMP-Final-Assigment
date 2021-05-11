/*****************************************************************************
* University of Southern Denmark
* Embedded C Programming (ECP)
*
* MODULENAME.: button.c
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
#include <payment.h>

/*****************************   Constants   *******************************/
#define IDIOT_CHECK 8
/*****************************   Variables   *******************************/
/*****************************   Functions   *******************************/
/*****************************************************************************
*   Input    :
*   Output   :
*   Function :
******************************************************************************/
void payment_task (void* pvParamters){
    PAYMENT_STATE = Start;

    while(1)
    {

       switch(PAYMENT_STATES)
        {
           case Start:
                 //Lock semaphore
                   PAYMENT_STATE = Paymenttype;
                   break;
           case Paymenttype:
               if(payment_method)
                     {
                         PAYMENT_STATE = Card;
                         break;
                     }
                     {
                         PAYMENT_STATE = Cash;
                         break;
                     }
           case Card:
               // K�r input card number ting
               PAYMENT_STATE = Cnumber;
               break;
           case Cnumber:
               if(getCardNumber.length()!=IDIOT_CHECK)
               {
                   LCDout = " use correct number u fat fuck"
                   PAYMENT_STATE = Card;
                   break;
               }
               {
                   PAYMENT_STATE = Pin;
                   break;
               }
        }
    }
}
