/********************************************************************************************
*                                                                                           *
*                                                                                           *
*                                                                                           *
* MIT License                                                                               *
*                                                                                           *
* Copyright (c) 2020 - 2026 BEAST                                                           *
*                                                                                           *
* Permission is hereby granted, free of charge, to any person obtaining a copy              *
* of this software and associated documentation files (the "Software"), to deal             *
* in the Software without restriction, including without limitation the rights              *
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell                 *
* copies of the Software, and to permit persons to whom the Software is                     *
* furnished to do so, subject to the following conditions:                                  *
*                                                                                           *
* The above copyright notice and this permission notice shall be included in all            *
* copies or substantial portions of the Software.                                           *
*                                                                                           *
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR                *
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,                  *
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE               *
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER                    *
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,             *
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE             *
* SOFTWARE.                                                                                 *
*********************************************************************************************
*/

#pragma once

//#include "ErrorDialog.h"

#define XY_ENABLE_VERIFIES 
#define _VA_AGRS_( x ) x

#if defined( XY_ENABLE_VERIFIES )

#if defined(XY_DEBUG) || defined(XY_RELEASE)
#define XY_BREAK_DEBUG() ::Core::BreakDebug()
#define XY_SHOW_ERROR_DIALOG( title, text ) 
#else
#define XY_BREAK_DEBUG()
#define XY_SHOW_ERROR_DIALOG( title, text ) /*::Core::ShowErrorDialogBoxAndTerminate( title, text, true )*/
#endif

#define XY_VERIFY_NO_MSG(cond) { if(!(cond)) { XY_CORE_ERROR("Verify Failed: {0}, Line {1}, File {2}", #cond, __LINE__, __FILE__); XY_SHOW_ERROR_DIALOG( "Verify Failed!", "No Message!" ); XY_BREAK_DEBUG(); } }

#define XY_VERIFY_MSG(cond, ...) { if(!(cond)) { XY_CORE_ERROR("Verify Failed: {0}, Line {1}, File {2}", __VA_ARGS__, __LINE__, __FILE__); XY_SHOW_ERROR_DIALOG( "Verify Failed!", __VA_ARGS__ ); XY_BREAK_DEBUG(); }  }

#define XY_VERIFY_RESOLVE(arg1, arg2, macro, ...) macro
#define XY_VERIFY_GET(...) _VA_AGRS_(XY_VERIFY_RESOLVE(__VA_ARGS__, XY_VERIFY_MSG, XY_VERIFY_NO_MSG))

#define XY_CORE_VERIFY( ... ) _VA_AGRS_( XY_VERIFY_GET( __VA_ARGS__ )(__VA_ARGS__) )
#define XY_VERIFY( ... ) _VA_AGRS_( XY_VERIFY_GET(__VA_ARGS__)(__VA_ARGS__) )
#else
#define XY_CORE_VERIFY( ... )
#define XY_VERIFY( ... )
#endif
