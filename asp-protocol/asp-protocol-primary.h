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
#ifndef aspProtocolPrimary_H
#define aspProtocolPrimary_H



/*==================================================*/
/*  INCLUDES                                        */
/*==================================================*/

#define aspProtocol_getEventFromContext(eventOffset, contextBitPosition) \
	((aspProtocol_Event)utils_getAbsoluteBitPosition(aspProtocol_events, eventOffset, contextBitPosition))

/*==================================================*/
/*  DEFINES                                         */
/*==================================================*/
/**********************************************************************************************************************
* Private object-like macros   (moduleName_object_name)
**********************************************************************************************************************/
//
#define aspProtocol_events											( aspProtocol_self.events )
#define aspProtocol_state											( aspProtocol_self.state )

/**********************************************************************************************************************
* Private function-like macros(moduleName_method_name)
**********************************************************************************************************************/

// Configurations
#define aspProtocol_getFrameContainerSize()							260U
#define aspProtocol_getFrameContainerCardinalNumber()				3U

#define aspProtocol_getInputFrameContainerIndex()					0U
#define aspProtocol_getSecondaryInputFrameContainerIndex()			1U
#define aspProtocol_getOututFrameContainerIndex()					2U

// Event Methods
#define aspProtocol_getEvents()										( aspProtocol_self.events )
#define aspProtocol_isRisenEvent(event)								( utils_isHighArrayBit(event, aspProtocol_events) )
#define aspProtocol_isRisenEventStart()								( aspProtocol_isRisenEvent(aspProtocol_evStart) )
#define aspProtocol_isRisenEventInputFrameReady()					( aspProtocol_isRisenEvent(aspProtocol_evInputFrameReady) )
#define aspProtocol_isRisenEventSduReady()							( aspProtocol_isRisenEvent(aspProtocol_evSduReady) )
#define aspProtocol_isRisenEventTimeOut()							( aspProtocol_isRisenEvent(aspProtocol_evTimeOut) )

#define aspProtocol_setEvent(event)									do{ utils_raiseBitInArray(event, aspProtocol_events); 			}while(0)
#define aspProtocol_clearEvents()									do{ memset(aspProtocol_events, 0, sizeof(aspProtocol_events)); 	}while(0)
#define aspProtocol_clearEvent(event)								do{ utils_clearBitInArray(event, aspProtocol_events); 			}while(0)
#define aspProtocol_setEventStart() 								do{ aspProtocol_setEvent( aspProtocol_evStart ); 				}while(0)


// State Methods
#define aspProtocol_getState()										( aspProtocol_state )
#define aspProtocol_setState(_state)								do{ aspProtocol_state = (_state) ;                    			}while(0)
#define aspProtocol_setStateInactive()								do{ aspProtocol_setState(aspProtocol_stInactive);   	       	}while(0)
#define aspProtocol_setStateReceive()								do{ aspProtocol_setState(aspProtocol_stReceive); 	          	}while(0)
#define aspProtocol_setStateParse()                              	do{ aspProtocol_setState(aspProtocol_stParse);             		}while(0)
#define aspProtocol_setStateDataProcessing()                      	do{ aspProtocol_setState(aspProtocol_stTimeOut);        	   	}while(0)

#define aspProtocol_getNumberOfEventsElements() 					( utils_getNumberOfElementsInArray( aspProtocol_events ) )
#define aspProtocol_getEventsElement(element)						( aspProtocol_events[element] )


/*==================================================*/
/*  GLOBALS (VARIABLES) declaration                 */
/*==================================================*/

/*==================================================*/
/*  GLOBALS (FUNCTIONS) declaration                 */
/*==================================================*/

#endif /* aspProtocolPrimary_H_H */
