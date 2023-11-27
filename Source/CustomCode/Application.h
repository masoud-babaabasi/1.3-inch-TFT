/*********************************************************************
*                     SEGGER Microcontroller GmbH                    *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2023  SEGGER Microcontroller GmbH                *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************
----------------------------------------------------------------------
File        : Application.h
Purpose     : Content to be managed by customer
---------------------------END-OF-HEADER------------------------------
*/

#ifndef APPLICATION_H
#define APPLICATION_H
#include "stdint.h"
#include "persian_numbers.h"
#include "string.h"
#include "stdio.h"

extern void get_date(uint16_t* year, uint8_t* month, uint8_t* date);
extern void get_time(uint8_t* hour, uint8_t* min, uint8_t *sec);
extern int get_auth();
#endif  // APPLICATION_H

/*************************** End of file ****************************/
