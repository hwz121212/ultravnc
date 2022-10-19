/////////////////////////////////////////////////////////////////////////////
//  Copyright (C) 2002-2013 UltraVNC Team Members. All Rights Reserved.
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 2 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307,
//  USA.
//
// If the source code for the program is not available from the place from
// which you received this file, check 
// http://www.uvnc.com/
//
////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <winsock2.h>
#include <windows.h>
#include "win32_helpers.h"

#define DWL_MSGRESULT   0
#define GWL_USERDATA        (-21)
#define GWL_HINSTANCE       (-6)
#define GWL_WNDPROC         (-4)


namespace helper {

void SafeSetMsgResult(HWND hwnd, LPARAM result)
{
	SetWindowLong(hwnd, DWL_MSGRESULT, result);
}

void SafeSetWindowUserData(HWND hwnd, LPARAM lParam)
{
	SetWindowLong(hwnd, GWL_USERDATA, lParam);
}

HINSTANCE SafeGetWindowInstance(HWND hWnd)
{
    HINSTANCE hInstance = (HINSTANCE)GetWindowLong(hWnd,GWL_HINSTANCE);
	return hInstance;
}

LONG SafeGetWindowProc(HWND hWnd)
{
    LONG pWndProc = GetWindowLong(hWnd, GWL_WNDPROC);
    return pWndProc;
}

void SafeSetWindowProc(HWND hWnd, LONG pWndProc)
{
    SetWindowLong(hWnd, GWL_WNDPROC, pWndProc);
}

void close_handle(HANDLE& h)
{
    if (h != INVALID_HANDLE_VALUE) 
    {
        ::CloseHandle(h);
        h = INVALID_HANDLE_VALUE;
    }
}

DynamicFnBase::DynamicFnBase(const TCHAR* dllName, const char* fnName) : dllHandle(0), fnPtr(0) {
  dllHandle = LoadLibrary(dllName);
  if (!dllHandle) {
    return;
  }
  fnPtr = (void *) GetProcAddress(dllHandle, fnName);
}

DynamicFnBase::~DynamicFnBase() {
  if (dllHandle)
    FreeLibrary(dllHandle);
}

} // namespace helper
