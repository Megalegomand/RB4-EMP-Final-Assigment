/********************************************** 
* Univeristy of Southern Denmark 
* Embedded Programming (EMP) 
* 
* MODULENAME: digiswitch
* PROJECT: digiswitch
* DESCRIPTION: See module specification file (.h-file) 
* Change log: 
********************************************** 
* Date Ud Change 
* YYMMDD 
* ---------------- 
* 11 May 2021 PO Module created. 
* 
***********************************************/

/***************** Header *********************/ 
/***************** Include files **************/ 
#include "digiswitch.h"
/***************** Defines ********************/ 
/***************** Constants ******************/ 
/***************** Variables ******************/ 
TaskHandle_t digiswitch_t;
QueueHandle_t input_queue;
/***************** Functions ******************/ 
/********************************************** 
* Input: 
* Output: 
* Function: 
***********************************************/ 

void digiswitch_init() {
    int dummy;

    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0; // Enable port A

    dummy = SYSCTL_RCGC2_R; // Wait for clock enable

    // Enable pins
    GPIO_PORTA_DEN_R |= 0x60;

    // Interrupt on A (PA5)
    GPIO_PORTA_IS_R &= ~(0b00100000); // Edge trigger
    GPIO_PORTA_IBE_R |= 0b00100000; // Both edges
    GPIO_PORTA_IM_R |= 0b00100000; // Interrupt mask
}

void digiswitch_isr();

void digiswitch_task() {
    digiswitch_t = xTaskGetCurrentTaskHandle();
}

/***************** End of module **************/
