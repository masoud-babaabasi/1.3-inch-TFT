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
File        : Resource.h
Purpose     : Generated file do NOT edit!
---------------------------END-OF-HEADER------------------------------
*/

#ifndef RESOURCE_H
#define RESOURCE_H

#include "AppWizard.h"

/*********************************************************************
*
*       Text
*/
#define ID_RTEXT_0 0

#define APPW_MANAGE_TEXT APPW_MANAGE_TEXT_EXT
extern GUI_CONST_STORAGE unsigned char acAPPW_Language_0[];

/*********************************************************************
*
*       Fonts
*/
extern GUI_CONST_STORAGE unsigned char acTahoma_72_Normal_EXT_AA4[];

/*********************************************************************
*
*       Images
*/
extern GUI_CONST_STORAGE unsigned char acding[];
extern GUI_CONST_STORAGE unsigned char ackeypad[];
extern GUI_CONST_STORAGE unsigned char acsetting[];

/*********************************************************************
*
*       Variables
*/
#define ID_VAR_SETTING_AUT (GUI_ID_USER + 2048)

/*********************************************************************
*
*       Screens
*/
#define ID_SCREEN_MAIN (GUI_ID_USER + 4096)

extern APPW_ROOT_INFO ID_SCREEN_MAIN_RootInfo;

#define APPW_INITIAL_SCREEN &ID_SCREEN_MAIN_RootInfo

/*********************************************************************
*
*       Project path
*/
#define APPW_PROJECT_PATH "D:/Masoud/github_projects/240x240_lcd"

#endif  // RESOURCE_H

/*************************** End of file ****************************/
