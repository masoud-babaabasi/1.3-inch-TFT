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
File        : ID_SCREEN_MAIN.c
Purpose     : Generated file do NOT edit!
---------------------------END-OF-HEADER------------------------------
*/

#include "Resource.h"
#include "ID_SCREEN_MAIN.h"

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/
/*********************************************************************
*
*       _aCreate
*/
static APPW_CREATE_ITEM _aCreate[] = {
  { WM_OBJECT_WINDOW_Create,
    ID_SCREEN_MAIN, 0,
    { { { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
      },
      0, 0, 0, 0, 0, 0
    },
    { 0, 0 }
  },
  { WM_OBJECT_BOX_Create,
    ID_BOX_BG, ID_SCREEN_MAIN,
    { { { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
      },
      0, 0, 0, 0, 0, 0
    },
    { 0, 0 }
  },
  { WM_OBJECT_TIMER_Create,
    ID_TIMER_INT, ID_SCREEN_MAIN,
    { { { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      0, 0, 0, 0, 0, 0
    },
    { 0, 0 }
  },
  { WM_OBJECT_IMAGE_Create,
    ID_IMAGE_BELL, ID_SCREEN_MAIN,
    { { { DISPOSE_MODE_REL_PARENT, 15, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 10, 0, 0 },
      },
      60, 60, 0, 0, 0, 0
    },
    { 0, 0 }
  },
  { WM_OBJECT_IMAGE_Create,
    ID_IMAGE_KEYPAD, ID_SCREEN_MAIN,
    { { { DISPOSE_MODE_REL_PARENT, 90, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 10, 0, 0 },
      },
      60, 60, 0, 0, 0, 0
    },
    { 0, 0 }
  },
  { WM_OBJECT_IMAGE_Create,
    ID_IMAGE_STTING, ID_SCREEN_MAIN,
    { { { DISPOSE_MODE_REL_PARENT, 165, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 10, 0, 0 },
      },
      60, 60, 0, 0, 0, 0
    },
    { 0, 0 }
  },
  { WM_OBJECT_TEXT_Create,
    ID_TEXT_COUNT, ID_SCREEN_MAIN,
    { { { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      240, 170, 0, 0, 0, 0
    },
    { 0, 0 }
  },
  { WM_OBJECT_GAUGE_Create,
    ID_GAUGE_COUNT, ID_SCREEN_MAIN,
    { { { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_REL_PARENT, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
        { DISPOSE_MODE_NULL, 0, 0, 0 },
      },
      240, 170, 0, 0, 0, 0
    },
    { 0, 0 }
  },
};

/*********************************************************************
*
*       _aSetup
*/
static GUI_CONST_STORAGE APPW_SETUP_ITEM _aSetup[] = {
  { ID_SCREEN_MAIN,  APPW_SET_PROP_PERSISTENT,   { ARG_V(0) } },
  { ID_BOX_BG,       APPW_SET_PROP_COLOR,        { ARG_V(0xff2c313c) } },
  { ID_TIMER_INT,    APPW_SET_PROP_PERIOD,       { ARG_V(50) } },
  { ID_TIMER_INT,    APPW_SET_PROP_AUTORESTART,  { ARG_V(0) } },
  { ID_IMAGE_BELL,   APPW_SET_PROP_TILE,         { ARG_V(0) } },
  { ID_IMAGE_BELL,   APPW_SET_PROP_SBITMAP,      { ARG_VP(0, acding),
                                                   ARG_V(1697), } },
  { ID_IMAGE_KEYPAD, APPW_SET_PROP_TILE,         { ARG_V(0) } },
  { ID_IMAGE_KEYPAD, APPW_SET_PROP_SBITMAP,      { ARG_VP(0, ackeypad),
                                                   ARG_V(2543), } },
  { ID_IMAGE_STTING, APPW_SET_PROP_TILE,         { ARG_V(0) } },
  { ID_IMAGE_STTING, APPW_SET_PROP_SBITMAP,      { ARG_VP(0, acsetting),
                                                   ARG_V(2582), } },
  { ID_TEXT_COUNT,   APPW_SET_PROP_COLOR,        { ARG_V(GUI_WHITE) } },
  { ID_TEXT_COUNT,   APPW_SET_PROP_ALIGNTEXT,    { ARG_V(GUI_ALIGN_HCENTER | GUI_ALIGN_VCENTER),
                                                   ARG_V(0),
                                                   ARG_V(0) } },
  { ID_TEXT_COUNT,   APPW_SET_PROP_TEXTID,       { ARG_V(ID_RTEXT_0) } },
  { ID_TEXT_COUNT,   APPW_SET_PROP_FONT,         { ARG_VP(0, acTahoma_72_Normal_EXT_AA4) } },
  { ID_GAUGE_COUNT,  APPW_SET_PROP_ALIGNBITMAP,  { ARG_V(GUI_ALIGN_HCENTER | GUI_ALIGN_VCENTER),
                                                   ARG_V(0),
                                                   ARG_V(0) } },
  { ID_GAUGE_COUNT,  APPW_SET_PROP_RANGE,        { ARG_V(0),
                                                   ARG_V(3600) } },
  { ID_GAUGE_COUNT,  APPW_SET_PROP_SPAN,         { ARG_V(0),
                                                   ARG_V(1000) } },
  { ID_GAUGE_COUNT,  APPW_SET_PROP_RADIUS,       { ARG_V(71) } },
  { ID_GAUGE_COUNT,  APPW_SET_PROP_COLORS,       { ARG_V(0xff2c2c30),
                                                   ARG_V(GUI_WHITE),
                                                   ARG_V(GUI_INVALID_COLOR) } },
  { ID_GAUGE_COUNT,  APPW_SET_PROP_VALUES,       { ARG_V(19),
                                                   ARG_V(13) } },
  { ID_GAUGE_COUNT,  APPW_SET_PROP_VALUE,        { ARG_V(1000) } },
};

/*********************************************************************
*
*       _aAction
*/
static GUI_CONST_STORAGE APPW_ACTION_ITEM _aAction[] = {
  { ID_SCREEN_MAIN,  APPW_NOTIFICATION_INITDIALOG,     ID_TIMER_INT,    APPW_JOB_START,          ID_SCREEN_MAIN__APPW_NOTIFICATION_INITDIALOG__ID_TIMER_INT__APPW_JOB_START,
    { { 0 } }, 0, NULL
  },
  { ID_TIMER_INT,    APPW_NOTIFICATION_TIMER,          0,               APPW_JOB_NULL,           ID_SCREEN_MAIN__ID_TIMER_INT__APPW_NOTIFICATION_TIMER,
  },
};

/*********************************************************************
*
*       Public data
*
**********************************************************************
*/
/*********************************************************************
*
*       ID_SCREEN_MAIN_RootInfo
*/
APPW_ROOT_INFO ID_SCREEN_MAIN_RootInfo = {
  ID_SCREEN_MAIN,
  _aCreate, GUI_COUNTOF(_aCreate),
  _aSetup,  GUI_COUNTOF(_aSetup),
  _aAction, GUI_COUNTOF(_aAction),
  cbID_SCREEN_MAIN,
  0
};

/*************************** End of file ****************************/
