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
#include "Payment.h"

/*****************************   Constants   *******************************/
/*****************************   Variables   *******************************/
/*****************************   Functions   *******************************/
/*****************************************************************************
*   Input    :
*   Output   :
*   Function :
******************************************************************************/
void payment_init(INT8U order){
    Payment_struct order;

}
/*****************************************************************************
*   Input    :
*   Output   :
*   Function :
******************************************************************************/
void payment_method(INT8U method, INT8U order){

    // lcd task that says choose method

    if(method)
    {
        order.PaymentType = 1;
    }
    {
        order.PaymentType = 0;
    }
}
/*****************************************************************************
*   Input    :
*   Output   :
*   Function :
******************************************************************************/
void payment(INT8U order, INT8U amount ){

    switch (coffee.type)
    {
    case 1
    order.Balance = order.Balance + coffee.price;
    }
}
