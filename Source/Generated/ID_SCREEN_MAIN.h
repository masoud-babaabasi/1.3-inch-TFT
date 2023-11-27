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
File        : ID_SCREEN_MAIN.h
Purpose     : Generated file do NOT edit!
---------------------------END-OF-HEADER------------------------------
*/

#ifndef ID_SCREEN_MAIN_H
#define ID_SCREEN_MAIN_H

#include "AppWizard.h"

/*********************************************************************
*
*       Objects
*/
#define ID_BOX_BG       (GUI_ID_USER + 1)
#define ID_TIMER_INT    (GUI_ID_USER + 2)
#define ID_IMAGE_BELL   (GUI_ID_USER + 3)
#define ID_IMAGE_KEYPAD (GUI_ID_USER + 4)
#define ID_IMAGE_STTING (GUI_ID_USER + 5)
#define ID_TEXT_COUNT   (GUI_ID_USER + 6)
#define ID_GAUGE_COUNT  (GUI_ID_USER + 7)

/*********************************************************************
*
*       Slots
*/
void ID_SCREEN_MAIN__APPW_NOTIFICATION_INITDIALOG__ID_TIMER_INT__APPW_JOB_START(APPW_ACTION_ITEM * pAction, WM_HWIN hScreen, WM_MESSAGE * pMsg, int * pResult);
void ID_SCREEN_MAIN__ID_TIMER_INT__APPW_NOTIFICATION_TIMER                     (APPW_ACTION_ITEM * pAction, WM_HWIN hScreen, WM_MESSAGE * pMsg, int * pResult);

/*********************************************************************
*
*       Callback
*/
void cbID_SCREEN_MAIN(WM_MESSAGE * pMsg);

#endif  // ID_SCREEN_MAIN_H

/*************************** End of file ****************************/
