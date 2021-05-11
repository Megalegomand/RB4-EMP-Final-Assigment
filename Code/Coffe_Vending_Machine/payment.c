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
#include "payment.h"
/*****************************   Constants   *******************************/
#define CARD_METHOD 1
#define CASH_METHOD 2
#define CARD_LENGTH 8
#define PIN_LENGTH 4
/*****************************   Variables   *******************************/
PAYMENT_TYPE current_payment;
/*****************************   Functions   *******************************/
/*****************************************************************************
 *   Input    :
 *   Output   :
 *   Function :
 ******************************************************************************/

void payment_task(void* pvParamters)
{
    PAYMENT_STATES current_state = START;

    while (1)
    {

        switch (current_state)
        {
        case START:
            //Lock semaphore
            current_state = PAYMENT;
            break;
        case PAYMENT:
            current_state = paymenttype_state();
            break;
        case CARD:
            // K�r input card number ting
            current_state = CARD_NUMBER;
            break;
        case CARD_NUMBER:
            current_state = cardnumber_check_state();
            break;
        case PIN:
            current_state = pin_check_state();
            break;
        case CASH:
            current_state = cash_state();
            break;
        case CHANGE:
            current_state = change_state();
            break;
        case LOG:
            current_state = log_state();
            break;
        }
    }
}

PAYMENT_STATES paymenttype_state()
{
    // Display "card or cash?"

    // Wait for key input getKey(portMAX_DELAY)
    while (1)
    {
        switch (key_get(portMAX_DELAY))
        {

        case '1':
            return CARD;

        case '2':
            return CASH;
        default:
            break;

        }
    }

}

PAYMENT_STATES cardnumber_check_state()
{
    INT8U digit_counter;

    while (1)
    {
        if (digit_counter < CARD_LENGTH)
        {

            current_payment.cardnumber[digit_counter] = key_get(
            portMAX_DELAY);
            digit_counter++;

        }
        else
        {
            return PIN;
        }
    }
}

PAYMENT_STATES pin_check_state()
{
    INT8U pin[PIN_LENGTH];
    INT8U pin_counter;
    while (1)
    {
        if (pin_counter < PIN_LENGTH)
        {
            pin[pin_counter] = key_get(portMAX_DELAY);
            pin_counter++;
        }
        else
        {
            if ((pin[3] % 2 == 0 && current_payment.cardnumber[7] % 2 != 0)
                    || (pin[3] % 2 != 0
                            && current_payment.cardnumber[7] % 2 == 0))
            {
                // cout payment complete
                return LOG;
            }
            else
            {
                // cout incorrect pin
                return CARD;
            }
        }
    }
}

PAYMENT_STATES cash_state()
{

    while (1)
    {
        if (current_payment.balance > coffee.price)
        {

            return CHANGE;

        }
        else
        {
            // balance = balance + digiswitch * 10 if counterclockwise pr digiswitch*5 if cockwise YEP
        }
    }
}

PAYMENT_STATES change_state()
{
    INT8U difference;
    INT8U i;

    while (1)
    {
        if (current_payment.balance > coffee.price)
        {
            difference = current_payment.balance - coffee.price;
            while (i <= difference)
            {
                // difference out on LCD
                // flash yellow led
                // delay
                i++;
            }

        }
        else
        {
            return LOG;
        }
    }

}

PAYMENT_STATES log_state()
{
    while (1)
    {
        // log data til pc
        return START;
    }
}

