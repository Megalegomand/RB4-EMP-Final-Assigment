/*****************************************************************************
* University of Southern Denmark
* Embedded C Programming (ECP)
*
* MODULENAME.: events.h
*
* PROJECT: FinalAssignment - Coffe_Vending_Machine
*
* DESCRIPTION: Test.
*
* Date of creation or change:
******************************************************************************
* Month     Day     Year    Change
* 05        08      21
* --------------------
* 090215  MoH   Module created.
*
*****************************************************************************/
#ifndef EVENTS_H_
#define EVENTS_H_

/***************************** Include files *******************************/
/*****************************    Defines    *******************************/
// Events.
// -------

// General Events
// --------------
#define GE_NO_EVENT      0

// Button Events
// -------------
#define BE_SINGLE_PUSH   1
#define BE_DOUBBLE_PUSH  2
#define BE_LONG_PUSH     3

// Timer Events
// ------------
#define TE_TIMEOUT      10
/*****************************   Constants   *******************************/

/*****************************   Functions   *******************************/

/****************************** End Of Module *******************************/
#endif /*EVENTS_H_*/
