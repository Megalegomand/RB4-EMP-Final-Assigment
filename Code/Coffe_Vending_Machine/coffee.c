/*****************************************************************************
 * University of Southern Denmark
 * Embedded C Programming (ECP)
 *
 * MODULENAME.: CoffeeTask.c
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
#include "coffee.h"
/*****************************    Defines    *******************************/
typedef enum COFFEE_STATES
{
    SELECT_COFFEE, BREW, C_LOG,
} COFFEE_STATES;

typedef struct
{
    BOOLEAN active;
    char name[14]; // Allows it to be displayed
    INT8U price;
    BOOLEAN amount_pay;
    FP32 grind_time;
    FP32 brew_time;
    FP32 milk_time;
} COFFEE_TYPE;

/*****************************   Constants   *******************************/
/*****************************   Variables   *******************************/
//enum CoffeeTask_states CoffeeTask_state = Start;
INT8U CoffeeTask_init;

COFFEE_TYPE coffee_types[10];
COFFEE_TYPE current_coffee;

static SemaphoreHandle_t active_semaphore;

extern TaskHandle_t payment_t;
/*****************************   Functions   *******************************/

void coffee_init()
{
    COFFEE_TYPE espresso;
    espresso.active = 1;
    strcpy(espresso.name, "Espresso");
    espresso.price = 15;
    espresso.amount_pay = 0;
    espresso.grind_time = 5.0f;
    espresso.brew_time = 15.0f;
    espresso.milk_time = 0.0f;
    coffee_types[0] = espresso;

    COFFEE_TYPE cappuccino;
    cappuccino.active = 1;
    strcpy(cappuccino.name, "Cappuccino");
    cappuccino.price = 24;
    cappuccino.amount_pay = 0;
    cappuccino.grind_time = 5.0f;
    cappuccino.brew_time = 15.0f;
    cappuccino.milk_time = 3.0f;
    coffee_types[1] = cappuccino;

    COFFEE_TYPE filter_coffee;
    filter_coffee.active = 1;
    strcpy(filter_coffee.name, "Filter coffee");
    filter_coffee.price = 1;
    filter_coffee.amount_pay = 1;
    filter_coffee.grind_time = 0.0f;
    filter_coffee.brew_time = 0.0f;
    filter_coffee.milk_time = 0.0f;
    coffee_types[2] = filter_coffee;

    active_semaphore = xSemaphoreCreateBinary();
    configASSERT(active_semaphore);
    xSemaphoreGive(active_semaphore);
}

COFFEE_STATES brew_state()
{
    FP32 price = 0.0f;
    FP32 slow_dispense = SLOW_DISPENSE_TIME_MS;
    while (1)
    {
        if (!get_sw1())
        {
            lprintf(0, "Place cup");
        }
        else if (!get_sw2())
        {
            lprintf(0, "Press start");
        }
        else
        {
            if (current_coffee.amount_pay)
            {
                FP32 dispense_mult = 0.0f;
                if (slow_dispense >= 0.0f) {
                    slow_dispense -= SWITCH_POLL_DELAY_MS * 1.0f;
                    dispense_mult = SLOW_DISPENSE_AMOUNT;
                } else {
                    dispense_mult = FAST_DISPENSE_AMOUNT;
                }
                price += (SWITCH_POLL_DELAY_MS / 1000.0f)
                        * current_coffee.price * dispense_mult;
                INT8U ceil_price = (INT8U) price + 0.5f;
                lprintf(0, "Price: %d", ceil_price); // Round up price
            }
        }
        // Poll switches, this causes the screen to blink
        // to make sure the text is read
        // Definitely a feature and not laziness
        vTaskDelay(pdMS_TO_TICKS(SWITCH_POLL_DELAY_MS));
    }

    return C_LOG;
}

COFFEE_STATES select_coffee_state()
{
    lprintf(0, "Pick coffee");

    INT8U num = -1; // To start from 0

    while (1)
    {
        do
        {
            if (num < COFFEE_TYPES_LENGTH)
            {
                num++;
            }
            else
            {
                num = 0;
            }
        }
        while (!coffee_types[num].active);

        lprintf(1, "%d-%s", num, coffee_types[num].name);

        INT8S inp = key2int(key_get(pdMS_TO_TICKS(COFFEE_CYCLE_TIME_MS)));
        if (inp != -1)
        {
            if (coffee_types[inp].active)
            {
                current_coffee = coffee_types[inp];

                xTaskNotifyGive(payment_t);

                //xSemaphoreTake(active_semaphore, portMAX_DELAY);

                return BREW;
            }
        }
    }
}

void coffee_task(void *pvParameters)
{
    COFFEE_STATES current_state = SELECT_COFFEE;
    while (1)
    {
        switch (current_state)
        {
        case SELECT_COFFEE:
            current_state = select_coffee_state();
            break;
        case BREW:
            ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
            current_state = brew_state();
            break;
        case C_LOG:
            current_state = 1;
            break;

        }
    }

}

/****************************** End Of Module *******************************/
