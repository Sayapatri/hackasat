/*
** Purpose: Define configurations for the UART Telemetry Output Command Ingest application
**
** Notes:
**   1. These macros can only be built with the application and can't
**      have a platform scope because the same file name is used for
**      all applications following the object-based application design.
**
** License:
**   Modified from code written by David McComas, licensed under the copyleft GNU
**   General Public License (GPL). 
**
** References:
**   1. OpenSatKit Object-based Application Developer's Guide.
**   2. cFS Application Developer's Guide.
**
*/

#ifndef _app_cfg_
#define _app_cfg_

/*
** Includes
*/

#include "cfe_platform_cfg.h"
#include "uart_to_ci_platform_cfg.h"
#include "osk_app_fw.h"

/******************************************************************************
** Telemetry Output Application Macros
*/

#define  UART_TO_CI_MAJOR_VERSION      1
#define  UART_TO_CI_MINOR_VERSION      0
#define  UART_TO_CI_REVISION           0
#define  UART_TO_CI_MISSION_REV        0

#define  UART_TO_CI_CMD_PIPE_DEPTH    100
#define  UART_TO_CI_CMD_PIPE_NAME     "UART_TO_CI_CMD_PIPE"


/******************************************************************************
** Command Macros
*/

#define UART_TO_CI_PKT_TBL_LOAD_CMD_FC     (CMDMGR_APP_START_FC + 0)
#define UART_TO_CI_PKT_TBL_DUMP_CMD_FC     (CMDMGR_APP_START_FC + 1)
#define UART_TO_CI_ADD_PKT_CMD_FC          (CMDMGR_APP_START_FC + 2)
#define UART_TO_CI_REMOVE_PKT_CMD_FC       (CMDMGR_APP_START_FC + 3)
#define UART_TO_CI_REMOVE_ALL_PKTS_CMD_FC  (CMDMGR_APP_START_FC + 4)
#define UART_TO_CI_ENABLE_OUTPUT_CMD_FC    (CMDMGR_APP_START_FC + 5)
#define UART_TO_CI_DISABLE_OUTPUT_CMD_FC   (CMDMGR_APP_START_FC + 6)
#define UART_TO_CI_SET_RATE_CMD_FC         (CMDMGR_APP_START_FC + 7)



/******************************************************************************
** Event Macros
**
** Define the base event message IDs used by each object/component used by the
** application. There are no automated checks to ensure an ID range is not
** exceeded so it is the developer's responsibility to verify the ranges. 
*/

#define UART_TO_CI_BASE_EID  (APP_FW_APP_BASE_EID +  0)
#define PKTTBL_BASE_EID  (APP_FW_APP_BASE_EID + 10)
#define PKTMGR_BASE_EID  (APP_FW_APP_BASE_EID + 20)

/*
** One event ID is used for all initialization debug messages. Uncomment one of
** the KIT_TO_INIT_EVS_TYPE definitions. Set it to INFORMATION if you want to
** see the events during initialization. This is opposite to what you'd expect 
** because INFORMATION messages are enabled by default when an app is loaded.
*/

#define UART_TO_CI_INIT_DEBUG_EID 999
#define UART_TO_CI_INIT_EVS_TYPE CFE_EVS_DEBUG
//#define KIT_TO_INIT_EVS_TYPE CFE_EVS_INFORMATION


/******************************************************************************
** pktmgr.h Configurations
*/

/*
** Maximum Number of Packet Definitions in Packet Table. Must be greater than zero.
*/

#define PKTTBL_MAX_PKT_CNT     80
#define PKTTBL_UNUSED_MSG_ID   (CFE_SB_HIGHEST_VALID_MSGID+1)


/******************************************************************************
** pktmgr.h Configurations
*/

#define PKTMGR_PIPE_DEPTH      132
#define PKTMGR_PIPE_NAME       "UART_TO_PKT_PIPE"


#endif /* _app_cfg_ */
