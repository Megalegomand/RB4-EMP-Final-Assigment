/*****************************************************************************
 * University of Southern Denmark
 * Embedded Programming (EMP)
 *
 * MODULENAME.: key.h
 *
 * PROJECT....: EMP
 *
 * DESCRIPTION: Test.
 *
 * Change Log:
 ******************************************************************************
 * Date    Id    Change
 * YYMMDD
 * --------------------
 * 150321  MoH   Module created.
 *
 *****************************************************************************/
#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "emp_type.h"
#include "FreeRTOS.h"
#include "queue.h"
#include "task.h"

#ifndef _KEY_H
#define _KEY_H

#define KEY_Q_WIDTH sizeof(INT8U)
#define KEY_Q_LENGTH 10
#define KEY_DEBOUNCE_DELAY_MS 5

INT8U key_get(TickType_t xTicksToWait);
void key_task();
void key_init();

#endif
