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
File        : ID_SCREEN_MAIN_Slots.c
Purpose     : AppWizard managed file, function content could be changed
---------------------------END-OF-HEADER------------------------------
*/

#include "Application.h"
#include "../Generated/Resource.h"
#include "../Generated/ID_SCREEN_MAIN.h"

/*** Begin of user code area ***/
static int timer = 10;
static int gauge = 1000;
/*** End of user code area ***/

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       cbID_SCREEN_MAIN
*/
void cbID_SCREEN_MAIN(WM_MESSAGE * pMsg) {
  GUI_USE_PARA(pMsg);
}

/*********************************************************************
*
*       ID_SCREEN_MAIN__APPW_NOTIFICATION_INITDIALOG__ID_TIMER_INT__APPW_JOB_START
*/
void ID_SCREEN_MAIN__APPW_NOTIFICATION_INITDIALOG__ID_TIMER_INT__APPW_JOB_START(APPW_ACTION_ITEM * pAction, WM_HWIN hScreen, WM_MESSAGE * pMsg, int * pResult) {
  GUI_USE_PARA(pAction);
  GUI_USE_PARA(hScreen);
  GUI_USE_PARA(pMsg);
  GUI_USE_PARA(pResult);
}

/*********************************************************************
*
*       ID_SCREEN_MAIN__ID_TIMER_INT__APPW_NOTIFICATION_TIMER
*/
void ID_SCREEN_MAIN__ID_TIMER_INT__APPW_NOTIFICATION_TIMER(APPW_ACTION_ITEM * pAction, WM_HWIN hScreen, WM_MESSAGE * pMsg, int * pResult) {
  GUI_USE_PARA(pAction);
  GUI_USE_PARA(hScreen);
  GUI_USE_PARA(pMsg);
  GUI_USE_PARA(pResult);
  gauge -= 50;
  if(gauge < 0) {
	  gauge = 1000;
	  timer --;
	  if(timer < 0 ) timer = 10;
  }
  GAUGE_Handle hGauge = WM_GetDialogItem(hScreen, ID_GAUGE_COUNT);
  GAUGE_SetValue(hGauge, gauge);
  TEXT_Handle hText = WM_GetDialogItem(hScreen, ID_TEXT_COUNT);
  TEXT_SetDec(hText, timer, 0, 0, 0, 0);
}

/*************************** End of file ****************************/
