/*H*****************************************************************************
  Use of this software is subject to LIEBHERR's Software License Agreement.
--------------------------------------------------------------------------------
  @Author               Christian Bechter
  @Creation Date        25.07.2016
--------------------------------------------------------------------------------
  @Project               xxxx
  @Target Platform       Windows - Dll, Library XY, Renesas-RL78, Independent
  @Target Compiler       IAR C/C++ Compiler Version X.Y, Qt - Creator Version X.Y, Independent
-------------------------------------------------------------------------------

******************************************************************************
* Copyright 2016, LIEBHERR LHG Ochsenhausen                                   *
*                                                                             *
* This software is owned by the LHG                                           *
* and is protected by and subject to worldwide patent protection.             *
* LHG hereby grants to licensee a personal,                                   *
* non-exclusive, non-transferable license to copy, use, modify, create        *
* derivative works of, and compile the LHG Source Code and derivative         *
* works for the sole purpose of creating custom software in support of        *
* licensee product to be used only in conjunction with a LHG based            *
* product. Any reproduction, modification, translation, compilation,          *
* or representation of this software except as specified above is             *
* prohibited without the express written permission of LHG.                   *
*                                                                             *
* Disclaimer: LHG MAKES NO WARRANTY OF ANY KIND,EXPRESS OR IMPLIED,           *
* WITH REGARD TO THIS MATERIAL, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED    *
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.         *
* LHG reserves the right to make changes without further notice to the        *
* materials described herein. LHG does not assume any liability arising       *
* out of the application or use of any product or circuit described herein.   *
* LHG does not authorize its products for use as critical components in       *
* life-support systems where a malfunction or failure may reasonably be       *
* expected to result in significant injury to the user. The inclusion of      *
* LHG products in a life-support systems application implies that the         *
* manufacturer assumes all risk of such use and in doing so indemnifies       *
* LHG against all charges.                                                    *
*                                                                             *
* Use may be limited by and subject to the applicable LHG software            *
* license agreement.                                                          *
******************************************************************************/
#ifndef apsProtocol_H
#define aspProtocol_H

/*==================================================*/
/*  INCLUDES                                        */
/*==================================================*/
#include <stdint.h>
#include <stdio.h>
#include "utils.h"



/*==================================================*/
/*  Constants                                       */
/*==================================================*/
// State
typedef enum
{
	aspProtocol_stInactive,
	aspProtocol_stReceive,
	aspProtocol_stParse,
	aspProtocol_stDataProcessing,
}aspProtocol_State;

// Events - the number represents the bit(representing an event) position in the "events" object
typedef enum
{
	aspProtocol_evStart,
	aspProtocol_evInputFrameReady,
	aspProtocol_evSduReady,
	aspProtocol_evTimeOut,
	aspProtocol_evTimeOut1,
	aspProtocol_evTimeOut2,
	aspProtocol_evTimeOut3,
	aspProtocol_evTimeOut4,
	aspProtocol_evTimeOut5,
	aspProtocol_evTimeOut7,
	aspProtocol_evTimeOut8,
	aspProtocol_evTimeOut9,
	aspProtocol_evTimeOut10,
	aspProtocol_evTimeOut11,
	aspProtocol_evTimeOut12,
	aspProtocol_evTimeOut13,
	aspProtocol_evTimeOut14,
}aspProtocol_Event;


/*==================================================*/
/*  DEFINES                                         */
/*==================================================*/

/**********************************************************************************************************************
* Private object-like macros   (moduleName_object_name)
**********************************************************************************************************************/
//
//#define aspProtocol_inputFrameContainer   						( aspProtocol_self.[aspProtocol_getInputFrameContainerIndex()] )
//#define aspProtocol_events										( aspProtocol_self.events )
//#define aspProtocol_state											( aspProtocol_self.state )
//
///**********************************************************************************************************************
//* Private function-like macros(moduleName_method_name)
//**********************************************************************************************************************/
//
//// Configurations
#define aspProtocol_getFrameContainerSize()							260U
#define aspProtocol_getFrameContainerCardinalNumber()				3U
#define aspProtocol_getNumberOfEventElements()						2U	//how many elements events-array will have

#define aspProtocol_getInputFrameContainerIndex()					0U
#define aspProtocol_getSecondaryInputFrameContainerIndex()			1U
#define aspProtocol_getOututFrameContainerIndex()					2U

/**********************************************************************************************************************
* Public object-like macros  (moduleName_object_name)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Public function-like macros that DO return value (moduleName_method_name)
**********************************************************************************************************************/

/*==================================================*/
/*  TYPE DEFINITIONS                                */
/*==================================================*/
/**********************************************************************************************************************
* Private typedefs  (Xxx)
**********************************************************************************************************************/

typedef uint16_t aspProtocol_Events[aspProtocol_getNumberOfEventElements()];

typedef uint8_t aspProtocol_FrameContainer[aspProtocol_getFrameContainerSize()];
typedef aspProtocol_FrameContainer aspProtocol_FramesContainer[aspProtocol_getFrameContainerCardinalNumber()];

typedef struct
{
	aspProtocol_State state;
	aspProtocol_Events events;
	aspProtocol_FramesContainer framesContainer;
}aspProtocol_SelfData;

/**********************************************************************************************************************
* Public typedefs  (Xxx)
**********************************************************************************************************************/

/*==================================================*/
/*  GLOBALS (VARIABLES) declaration                 */
/*==================================================*/
extern aspProtocol_SelfData aspProtocol_self;
/*==================================================*/
/*  GLOBALS (FUNCTIONS) declaration                 */
/*==================================================*/
void aspProtocol_detectEvents();
void aspProtocol_init();
#endif /* aspProtocol_H */
