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
void payment_task(void* pvParamters)
{
    PAYMENT_STATES current_state = Start;

    while (1)
    {

        switch (current_state)
        {
        case Start:
            //Lock semaphore
            current_state = Paymenttype;
            break;
        case Paymenttype:
            current_state = paymenttype_state();
            break;
        case Card:
            // K�r input card number ting
            current_state = Cnumber;
            break;
        case Cnumber:
            if (0) //getCardNumber.length() != IDIOT_CHECK)
            {
                //LCDout = " use correct number u fat fuck"
                current_state = Card;
                break;
            }
            else
            {
                current_state = Pin;
                break;
            }
        }
    }
}

PAYMENT_STATES paymenttype_state()
{
    // Display "card or cash?"

    // Wait for key input getKey(portMAX_DELAY)
    if (0)//payment_method)
    {
        return Card;
    }
    else
    {
        return Cash;
    }
}
