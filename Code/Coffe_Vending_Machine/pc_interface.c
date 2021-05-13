/********************************************** 
 * Univeristy of Southern Denmark
 * Embedded Programming (EMP)
 *
 * MODULENAME: pc_interface
 * PROJECT: pc_interface
 * DESCRIPTION: See module specification file (.h-file)
 * Change log:
 **********************************************
 * Date Ud Change
 * YYMMDD
 * ----------------
 * 12 May 2021 PO Module created.
 *
 ***********************************************/

/***************** Header *********************/
/***************** Include files **************/
#include "pc_interface.h"
/***************** Defines ********************/

/***************** Constants ******************/
/***************** Variables ******************/
extern COFFEE_TYPE coffee_types[COFFEE_TYPES_LENGTH];
extern SemaphoreHandle_t coffee_types_mutex;

extern LOG_TYPE log_array[LOG_LENGTH];
extern SemaphoreHandle_t log_array_semaphore;

extern QueueHandle_t uart0_rx_queue;

char buffer[70];
/***************** Functions ******************/

void ui_clear_screen()
{
    char buffer[5];
    uprintf(buffer, "%c[2J", ASCII_ESC); // Clear screen
    uprintf(buffer, "%c[H", ASCII_ESC); // Reset cursor
}

void ui_task(void *pvParameters)
{
    MENU current_menu = MAIN_MENU;

    while (1)
    {
        switch (current_menu)
        {
        case MAIN_MENU:
            current_menu = main_menu();
            break;
        case LOG_LIST:
            current_menu = log_list_menu();
            break;
        }
    }
}

MENU main_menu()
{
    ui_clear_screen();
    uprintf(buffer, "----------------------\n\r");
    uprintf(buffer, "Select menu\n\r");
    uprintf(buffer, "1 - List logs\n\r");
    uprintf(buffer, "----------------------\n\r");

    INT8U inp;
    while (1)
    {
        xQueueReceive(uart0_rx_queue, &inp, portMAX_DELAY);
        switch (inp)
        {
        case '1':
            return LOG_LIST;
        default:
            uprintf(buffer, "%c\n\rIncorrect input\n\r", inp);
            break;
        }
    }
}

MENU log_list_menu()
{
    ui_clear_screen();
    uprintf(buffer,
            "Order no. | Coffee no. | Coffee name | Price | Payment type\n\r");

    xSemaphoreTake(log_array_semaphore, portMAX_DELAY);
    xSemaphoreTake(coffee_types_mutex, portMAX_DELAY);

    for (int i = 0; i < LOG_LENGTH; i++)
    {
        if (log_array[i].active)
        {
            uprintf(buffer, "%d | %d | %s | %d \n\r", i,
                    log_array[i].coffee_number,
                    coffee_types[log_array[i].coffee_number].name,
                    log_array[i].price, log_array[i].payment_type);
        }
        else
        {
            break;
        }
    }

    xSemaphoreGive(log_array_semaphore);
    xSemaphoreGive(coffee_types_mutex);

    uprintf(buffer, "Press any key to return\n\r");
    INT8U inp;
    xQueueReceive(uart0_rx_queue, &inp, portMAX_DELAY);
    uprintf(buffer, ""); // This makes it work, line above has some memory leak

    return MAIN_MENU;
}
/********************************************** 
 * Input:
 * Output:
 * Function:
 ***********************************************/

/***************** End of module **************/
