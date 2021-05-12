/********************************************** 
 * Univeristy of Southern Denmark
 * Embedded Programming (EMP)
 *
 * MODULENAME: led
 * PROJECT: led
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
#include "led.h"
/***************** Defines ********************/
/***************** Constants ******************/
/***************** Variables ******************/
/***************** Functions ******************/
void led_init()
{
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5; // Enable port F

    GPIO_PORTF_DEN_R |= 0x0E; // Enable pins
    GPIO_PORTF_DIR_R |= 0x0E; // Set as output
}
void led_red()
{
    GPIO_PORTF_DATA_R &= ~(0x02);
}

void led_yellow()
{
    GPIO_PORTF_DATA_R &= ~(0x04);
}
void led_green()
{
    GPIO_PORTF_DATA_R &= ~(0x08);
}
void led_off()
{
    GPIO_PORTF_DATA_R |= 0x0E;
}
/********************************************** 
 * Input:
 * Output:
 * Function:
 ***********************************************/

/***************** End of module **************/
