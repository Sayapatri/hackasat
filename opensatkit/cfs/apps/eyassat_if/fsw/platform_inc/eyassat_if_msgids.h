/*
** Purpose: Define message IDs for the Eyassat_if application
**
** Notes:
**   None
**
** License:
**   Written by David McComas, licensed under the copyleft GNU General
**   Public License (GPL).
**
** References:
**   1. OpenSatKit Object-based Application Developer's Guide.
**   2. cFS Application Developer's Guide.
**
*/
#ifndef _eyassat_if_msgids_
#define _eyassat_if_msgids_

/*
** Command Message IDs
*/

#define  EYASSAT_IF_CMD_MID        0x19D5
// Send Internal and Temps with HK
#define  EYASSAT_IF_SEND_HK_MID    0x19D4
#define  EYASSAT_IF_SEND_POWER_MID 0x19DA
#define  EYASSAT_IF_SEND_ADCS_MID  0x19DB

/*
** Telemetry Message IDs
*/

#define  EYASSAT_IF_TLM_HK_MID             0x09D4
#define  EYASSAT_IF_TLM_INTERNAL_MID       0x09D5
#define  EYASSAT_IF_TLM_TEMP_MID           0x09D6
#define  EYASSAT_IF_TLM_POWER_MID          0x09D7
#define  EYASSAT_IF_TLM_ADCS_MID           0x09D9
#define  EYASSAT_IF_TLM_CAL_TBL_MID        0x09DA


#endif /* _eyassat_if_msgids_ */
