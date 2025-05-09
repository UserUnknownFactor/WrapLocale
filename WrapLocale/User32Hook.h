#pragma once

#include "HookFunc.h"

typedef LRESULT(WINAPI* NtUserMessageCallFn)(
    HWND         Window,
    UINT         Message,
    WPARAM       wParam,
    LPARAM       lParam,
    ULONG_PTR    xParam,
    ULONG        xpfnProc,
    ULONG        Flags
    );


#ifndef EM_SETCUEBANNER
#define EM_SETCUEBANNER (WM_USER + 0x1501)
#endif

#ifndef EM_SETWORDBREAK
#define EM_SETWORDBREAK 0x00D0
#endif

// Ansi to Unicode KernelCall Functions
LRESULT NTAPI ANSI_INLPCREATESTRUCT(HWND Window, UINT Message, WPARAM wParam, LPARAM lParam);
LRESULT NTAPI ANSI_INLPMDICREATESTRUCT(HWND Window, UINT Message, WPARAM wParam, LPARAM lParam);
LRESULT NTAPI ANSI_OUTSTRING(HWND Window, UINT Message, WPARAM wParam, LPARAM lParam);
LRESULT NTAPI ANSI_INSTRING(HWND Window, UINT Message, WPARAM wParam, LPARAM lParam);
LRESULT NTAPI ANSI_GETLINE(HWND Window, UINT Message, WPARAM wParam, LPARAM lParam);
LRESULT NTAPI ANSI_GETTEXT(HWND Window, UINT Message, WPARAM wParam, LPARAM lParam);
LRESULT NTAPI ANSI_GETTEXTLENGTH(HWND Window, UINT Message, WPARAM wParam, LPARAM lParam);