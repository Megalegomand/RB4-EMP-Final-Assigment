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
#include "key.h"

/*****************************   Constants   *******************************/
#define CARD_METHOD 1
#define CASH_METHOD 2
#define CARD_LENGTH 8
#define PIN_LENGTH 4
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
    PAYMENT_TYPE payment;
    while (1)
    {

        switch (current_state)
        {
        case START:
            //Lock semaphore
            current_state = PAYMENT_TYPE;
            break;
        case PAYMENT_TYPE:
            current_state = paymenttype_state();
            break;
        case CARD:
            // Kï¿½r input card number ting
            current_state = Cnumber;
            break;
        case CARD_NUMBER:
            current_state = cardnumber_check_state();
            break;
        case PIN:
            current_state = pin_check_state();
            break;¨
        case CASH:
            current_state = cash_state();
        }
    }
}

PAYMENT_STATES paymenttype_state()
{
    // Display "card or cash?"
    INT8U keystroke;
    // Wait for key input getKey(portMAX_DELAY)
    while (1)
    {
        if (getKey(MAX_DELAY) == CARD_METHOD | CASH_METHOD)
        {
            keystroke = getKey(MAX_DELAY);
            break;
        }
    }
    switch (keystroke)
    {
    case 1:
    {
        return CARD;
    }
    case 2:
    {
        return CASH;
    }
    }
}

PAYMENT_STATES cardnumber_check_state()
{
    INT8U digit_counter;

    while (1)
    {
        if (counter < CARD_LENGTH)
        {

            payment.cardnumer[digit_counter] = getKey(MAX_DELAY);
            counter++;

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
        if (counter < PIN_LENGTH)
        {
            pin[pin_counter] = getKey(MAX_DELAY);
            counter++;
        }
        else
        {
            if ((pin[3] % 2 == 0 && payment.cardnumber[7] % 2 != 0)
                    || (pin[3] % 2 != 0 && payment.cardnumber[7] % 2 == 0))
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

    while(1)
    {
        if(payment.balance > coffee.price)
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

    while(1)
        {
            if(payment.balance > coffee.price)
            {
              difference = payment.balance - coffee.price;
              while(i =< difference)
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
    while(1)
    {
        // log data til pc
        return START;
    }
}
