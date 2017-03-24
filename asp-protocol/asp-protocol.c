
/*==================================================*/
/*  INCLUDES                                        */
/*==================================================*/
#include <string.h>
#include "asp-protocol-primary.h"
#include "asp-protocol.h"


/*==================================================*/
/*  GLOBALS (VARIABLES) wit external likage         */
/*==================================================*/
/** \brief <b>g_sStruct</b>

    ToDo: A short description of the purpose the variables/structs/unions or objects task
 */


/*==================================================*/
/* MODULE GLOBALS (VARIABLES) with internal linkage */
/*==================================================*/
/** \brief <b>m_bAnSpecialArray</b>

    ToDo: A short description of the purpose the variables/structs/unions or objects task
*/
aspProtocol_SelfData aspProtocol_self;

/*==================================================*/
/*  MODULE GLOBALS (FUNCTIONS) declaration          */
/*  with internal likage                            */
/*==================================================*/
static void aspProtocol_dispatchEvent( aspProtocol_Event event);
static void aspProtocol_onFrameReady();
static void aspProtocol_onTimeOut();
static void aspProtocol_onSduReady();
static void aspProtocol_onStart();


/*==================================================*/
/*  IMPLEMENTATION                                  */
/*==================================================*/

//------------------------------------------------------------------------------
/** \brief <b>ctrlModule_init_control</b>

    ToDo: Describe the methods task and requirements.

\Objects        describe manipulated objects inside the method
\Return         N/A
\Image          ctrlModule_init_control.png <maybe for future use docu generation from EA>
\Derived        Either give the linking to the Confluence High Level Feature or name the Features tracked within JIRA by the corresponding ID.
*/


/* Detect Events **************************************************************************************/

void aspProtocol_detectEvents()
{
	uint8_t eventOffset;
	for( eventOffset = 0; eventOffset < aspProtocol_getNumberOfEventsElements(); eventOffset++ )
	{
		uint8_t contextBitPosition;
		for(contextBitPosition = 0; aspProtocol_getEventsElement(eventOffset)  != 0 ; contextBitPosition++)
		{
			aspProtocol_Event contextEvent;
			contextEvent = aspProtocol_getEventFromContext(eventOffset, contextBitPosition);
			if( aspProtocol_isRisenEvent(contextEvent) )
			{
				//aspProtocol_dispatchEvent(contextEvent);
				aspProtocol_clearEvent(contextEvent);
			}
		}
	}
}


/* Dispatch Events *************************************************************************************/
static void aspProtocol_dispatchEvent( aspProtocol_Event event)
{
	switch(event)
	{
		case aspProtocol_evInputFrameReady:
			aspProtocol_onFrameReady();
			break;
		case aspProtocol_evTimeOut:
			aspProtocol_onTimeOut();
			break;
		case aspProtocol_evSduReady:
			aspProtocol_onSduReady();
			break;
		case aspProtocol_evStart:
			aspProtocol_onStart();
			break;
		default:
			;
	}
}


/* Handle Events ****************************************************************************************/
static void aspProtocol_onStart()
{
	switch(aspProtocol_state)
	{
		case aspProtocol_stInactive:
			aspProtocol_init();
			break;
		default:
			;
	}
}

static void aspProtocol_onFrameReady()
{
	switch(aspProtocol_state)
	{
		case aspProtocol_stInactive:
		case aspProtocol_stReceive:
		case aspProtocol_stParse:
		case aspProtocol_stDataProcessing:
			break;
	}
}

static void aspProtocol_onTimeOut()
{
	switch(aspProtocol_state)
	{
		case aspProtocol_stInactive:
		case aspProtocol_stReceive:
		case aspProtocol_stParse:
		case aspProtocol_stDataProcessing:
			break;
	}
}

static void aspProtocol_onSduReady()
{
	switch(aspProtocol_state)
	{
		case aspProtocol_stInactive:
		case aspProtocol_stReceive:
		case aspProtocol_stParse:
		case aspProtocol_stDataProcessing:
			break;
	}
}

/* Interfaces *******************************************************************/

void aspProtocol_init()
{
	aspProtocol_clearEvents();
}
