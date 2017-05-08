/***********************************************************************
	filename: 	CEGUIEventArgs.h
	created:	21/2/2004
	author:		Paul D Turner
	
	purpose:	Defines base EventArgs class used with event signalling
*************************************************************************/
/***************************************************************************
 *   Copyright (C) 2004 - 2006 Paul D Turner & The CEGUI Development Team
 *
 *   Permission is hereby granted, free of charge, to any person obtaining
 *   a copy of this software and associated documentation files (the
 *   "Software"), to deal in the Software without restriction, including
 *   without limitation the rights to use, copy, modify, merge, publish,
 *   distribute, sublicense, and/or sell copies of the Software, and to
 *   permit persons to whom the Software is furnished to do so, subject to
 *   the following conditions:
 *
 *   The above copyright notice and this permission notice shall be
 *   included in all copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 *   IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 *   OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 *   ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 *   OTHER DEALINGS IN THE SOFTWARE.
 ***************************************************************************/
#ifndef _CEGUIEventArgs_h_
#define _CEGUIEventArgs_h_

#include "CEGUIBase.h"


// Start of CEGUI namespace section
namespace CEGUI
{
/*!
\brief
	Base class used as the argument to all subscribers Event object.

	The base EventArgs class does not contain any useful information, it is intended
	to be specialised for each type of event that can be generated by objects within
	the system.  The use of this base class allows all event subscribers to have the
	same function signature.

	The \a handled field is used to signal whether an event was actually handled or not.  While
	the event system does not look at this value, code at a higher level can use it to determine
	how far to propagate an event.
*/
class  EventArgs
{
public:
	/*************************************************************************
		Construction
	*************************************************************************/
	EventArgs(void) : handled(0) {}
	virtual ~EventArgs(void) {}


	/*************************************************************************
		Data members
	*************************************************************************/
    //! handlers should increment this if they handled the event.
    uint handled;
};

} // End of  CEGUI namespace section

#endif	// end of guard _CEGUIEventArgs_h_
