/*****************************************************************************
 * University of Southern Denmark
 * Embedded C Programming (ECP)
 *
 * MODULENAME.: leds.h
 *
 * PROJECT....: ECP
 *
 * DESCRIPTION: Test.
 *
 * Change Log:
 ******************************************************************************
 * Date    Id    Change
 * YYMMDD
 * --------------------
 * 050128  KA    Module created.
 *
 *****************************************************************************/

#ifndef _LCD_H
#define _LCD_H

/***************************** Include files *******************************/
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "tm4c123gh6pm.h"
#include "emp_type.h"
#include "string.h"
#include "FreeRTOS.h"
#include "queue.h"
/*****************************    Defines    *******************************/
// Special ASCII characters
// ------------------------
#define LF		0x0A
#define FF		0x0C
#define CR		0x0D

#define ESC		0x1B

#define LCD_Q_LENGTH 100
#define LCD_Q_WIDTH sizeof(INT8U)

/*****************************   Constants   *******************************/

/*****************************   Functions   *******************************/
void wr_str_LCD(INT8U*);
void move_LCD(INT8U, INT8U);
INT8U wr_ch_LCD(INT8U Ch);

void lcd_init();
void lcd_task(void* pvParameters);
void lprintf(INT16U line, const char * format, ... );
/*****************************************************************************
 *   Input    : -
 *   Output   : -
 *   Function : Test function
 ******************************************************************************/

/****************************** End Of Module *******************************/
#endif

