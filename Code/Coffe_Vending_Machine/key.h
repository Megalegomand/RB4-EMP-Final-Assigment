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
#include "glob_def.h"

#ifndef _KEY_H
#define _KEY_H

INT8U get_key();
void key_task();

#endif
