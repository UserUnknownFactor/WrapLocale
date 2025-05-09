#pragma once

#include "MINT.h"

#define FLAG_ON(_V, _F)     (!!((_V) & (_F)))

#define WS_EX_ANSI          0x80000000
#define WINDOW_FLAG_ANSI    0x00000001

#define CLEAR_FLAG(_V, _F)  ((_V) &= ~(_F))

#define STATUS_SUCCESS                   ((NTSTATUS)0x00000000L)    // ntsubauth
#define STATUS_INVALID_PARAMETER_2       ((NTSTATUS)0xC00000F0L)
#define STATUS_BUFFER_OVERFLOW           ((NTSTATUS)0x80000005L)
#define RTL_DUPSTR_ADD_NULL                                     (0x00000001)

#define LOOP_ONCE   for (BOOL __condition_ = TRUE; __condition_; __condition_ = FALSE)

typedef HWND(WINAPI* NtUserCreateWindowExType)(
    _In_      ULONG                   ExStyle,
    _In_      PLARGE_UNICODE_STRING   ClassName,
    _In_opt_  PLARGE_UNICODE_STRING   ClassVersion,
    _In_opt_  PLARGE_UNICODE_STRING   WindowName,
    _In_      ULONG                   Style,
    _In_      LONG                    X,
    _In_      LONG                    Y,
    _In_      LONG                    Width,
    _In_      LONG                    Height,
    _In_opt_  HWND                    ParentWnd,
    _In_opt_  HMENU                   Menu,
    _In_opt_  PVOID                   Instance,
    _In_opt_  LPVOID                  Param,
    _In_      ULONG                   ShowMode,
    _In_      ULONG                   Unknown1,
    _In_      ULONG                   Unknown2,
    _In_      ULONG                   Unknown3
    );

typedef LRESULT(WINAPI* NtUserMessageCallType)(
    _In_      HWND         Window,
    _In_      UINT         Message,
    _In_      WPARAM       wParam,
    _In_      LPARAM       lParam,
    _In_      ULONG_PTR    xParam,
    _In_      ULONG        xpfnProc,
    _In_      ULONG        Flags
    );

HWND WINAPI HookNtUserCreateWindowEx(
    ULONG                   ExStyle,
    PLARGE_UNICODE_STRING   ClassName,
    PLARGE_UNICODE_STRING   ClassVersion,
    PLARGE_UNICODE_STRING   WindowName,
    ULONG                   Style,
    LONG                    X,
    LONG                    Y,
    LONG                    Width,
    LONG                    Height,
    HWND                    ParentWnd,
    HMENU                   Menu,
    PVOID                   Instance,
    LPVOID                  Param,
    ULONG                   ShowMode,
    ULONG                   Unknown1,
    ULONG                   Unknown2,
    ULONG                   Unknown3
);

LRESULT WINAPI HookNtUserMessageCall(
    HWND         Window,
    UINT         Message,
    WPARAM       wParam,
    LPARAM       lParam,
    ULONG_PTR    xParam,
    ULONG        xpfnProc,
    ULONG        Flags
);

/* Unicde to Ansi UserCall Functions */
LRESULT NTAPI UNICODE_EMPTY(WNDPROC PrevProc, HWND Window, UINT Message, WPARAM wParam, LPARAM lParam);
LRESULT NTAPI UNICODE_INLPCREATESTRUCT(WNDPROC PrevProc, HWND Window, UINT Message, WPARAM wParam, LPARAM lParam);
LRESULT NTAPI UNICODE_INLPMDICREATESTRUCT(WNDPROC PrevProc, HWND Window, UINT Message, WPARAM wParam, LPARAM lParam);
LRESULT NTAPI UNICODE_INSTRINGNULL(WNDPROC PrevProc, HWND Window, UINT Message, WPARAM wParam, LPARAM lParam);
LRESULT NTAPI UNICODE_OUTSTRING(WNDPROC PrevProc, HWND Window, UINT Message, WPARAM wParam, LPARAM lParam);
LRESULT NTAPI UNICODE_INSTRING(WNDPROC PrevProc, HWND Window, UINT Message, WPARAM wParam, LPARAM lParam);
LRESULT NTAPI UNICODE_INCNTOUTSTRING(WNDPROC PrevProc, HWND Window, UINT Message, WPARAM wParam, LPARAM lParam);
LRESULT NTAPI UNICODE_INCBOXSTRING(WNDPROC PrevProc, HWND Window, UINT Message, WPARAM wParam, LPARAM lParam);
LRESULT NTAPI UNICODE_OUTCBOXSTRING(WNDPROC PrevProc, HWND Window, UINT Message, WPARAM wParam, LPARAM lParam);
LRESULT NTAPI UNICODE_INLBOXSTRING(WNDPROC PrevProc, HWND Window, UINT Message, WPARAM wParam, LPARAM lParam);
LRESULT NTAPI UNICODE_OUTLBOXSTRING(WNDPROC PrevProc, HWND Window, UINT Message, WPARAM wParam, LPARAM lParam);
LRESULT NTAPI UNICODE_INCNTOUTSTRINGNULL(WNDPROC PrevProc, HWND Window, UINT Message, WPARAM wParam, LPARAM lParam);
LRESULT NTAPI UNICODE_GETDBCSTEXTLENGTHS(WNDPROC PrevProc, HWND Window, UINT Message, WPARAM wParam, LPARAM lParam);

/* Ansi to Unicode KernelCall Functions */
LRESULT NTAPI ANSI_EMPTY(HWND Window, UINT Message, WPARAM wParam, LPARAM lParam, ULONG_PTR xParam, ULONG xpfnProc, ULONG Flags);
LRESULT NTAPI ANSI_INLPCREATESTRUCT(HWND Window, UINT Message, WPARAM wParam, LPARAM lParam, ULONG_PTR xParam, ULONG xpfnProc, ULONG Flags);
LRESULT NTAPI ANSI_INLPMDICREATESTRUCT(HWND Window, UINT Message, WPARAM wParam, LPARAM lParam, ULONG_PTR xParam, ULONG xpfnProc, ULONG Flags);
LRESULT NTAPI ANSI_INSTRINGNULL(HWND Window, UINT Message, WPARAM wParam, LPARAM lParam, ULONG_PTR xParam, ULONG xpfnProc, ULONG Flags);
LRESULT NTAPI ANSI_OUTSTRING(HWND Window, UINT Message, WPARAM wParam, LPARAM lParam, ULONG_PTR xParam, ULONG xpfnProc, ULONG Flags);
LRESULT NTAPI ANSI_INSTRING(HWND Window, UINT Message, WPARAM wParam, LPARAM lParam, ULONG_PTR xParam, ULONG xpfnProc, ULONG Flags);
LRESULT NTAPI ANSI_INCNTOUTSTRING(HWND Window, UINT Message, WPARAM wParam, LPARAM lParam, ULONG_PTR xParam, ULONG xpfnProc, ULONG Flags);
LRESULT NTAPI ANSI_INCBOXSTRING(HWND Window, UINT Message, WPARAM wParam, LPARAM lParam, ULONG_PTR xParam, ULONG xpfnProc, ULONG Flags);
LRESULT NTAPI ANSI_OUTCBOXSTRING(HWND Window, UINT Message, WPARAM wParam, LPARAM lParam, ULONG_PTR xParam, ULONG xpfnProc, ULONG Flags);
LRESULT NTAPI ANSI_INLBOXSTRING(HWND Window, UINT Message, WPARAM wParam, LPARAM lParam, ULONG_PTR xParam, ULONG xpfnProc, ULONG Flags);
LRESULT NTAPI ANSI_OUTLBOXSTRING(HWND Window, UINT Message, WPARAM wParam, LPARAM lParam, ULONG_PTR xParam, ULONG xpfnProc, ULONG Flags);
LRESULT NTAPI ANSI_INCNTOUTSTRINGNULL(HWND Window, UINT Message, WPARAM wParam, LPARAM lParam, ULONG_PTR xParam, ULONG xpfnProc, ULONG Flags);
LRESULT NTAPI ANSI_GETDBCSTEXTLENGTHS(HWND Window, UINT Message, WPARAM wParam, LPARAM lParam, ULONG_PTR xParam, ULONG xpfnProc, ULONG Flags);

typedef LRESULT(NTAPI* UNICODE_MESSAGECALL)(
    WNDPROC     PrevProc,
    HWND        Window,
    UINT        Message,
    WPARAM      wParam,
    LPARAM      lParam
    );
typedef LRESULT(NTAPI* ANSI_MESSAGECALL)(
    HWND        Window,
    UINT        Message,
    WPARAM      wParam,
    LPARAM      lParam,
    ULONG_PTR   xParam,
    ULONG       xpfnProc,
    ULONG       Flags
    );

typedef struct
{
    UNICODE_MESSAGECALL UnicodeCall;
    ANSI_MESSAGECALL    AnsiCall;
} MESSAGE_FUNCTION_TABLE;

const UINT MessageSize = 1024;
static MESSAGE_FUNCTION_TABLE MessageTable[1024] =
{
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_NULL
    {UNICODE_INLPCREATESTRUCT,      ANSI_INLPCREATESTRUCT   }, // WM_CREATE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_DESTROY
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_MOVE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0004
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_SIZE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_ACTIVATE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_SETFOCUS
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_KILLFOCUS
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0009
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_ENABLE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_SETREDRAW
    {UNICODE_INSTRINGNULL,          ANSI_INSTRINGNULL       }, // WM_SETTEXT
    {UNICODE_OUTSTRING,             ANSI_OUTSTRING          }, // WM_GETTEXT
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_GETTEXTLENGTH
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_PAINT
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_CLOSE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_QUERYENDSESSION
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_QUIT
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_QUERYOPEN
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_ERASEBKGND
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_SYSCOLORCHANGE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_ENDSESSION
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0017
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_SHOWWINDOW
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0019
    {UNICODE_INSTRINGNULL,          ANSI_INSTRINGNULL       }, // WM_SETTINGCHANGE
    {UNICODE_INSTRING,              ANSI_INSTRING           }, // WM_DEVMODECHANGE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_ACTIVATEAPP
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_FONTCHANGE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_TIMECHANGE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_CANCELMODE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_SETCURSOR
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_MOUSEACTIVATE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_CHILDACTIVATE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_QUEUESYNC
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_GETMINMAXINFO
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0025
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_PAINTICON
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_ICONERASEBKGND
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_NEXTDLGCTL
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0029
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_SPOOLERSTATUS
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_DRAWITEM
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_MEASUREITEM
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_DELETEITEM
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_VKEYTOITEM
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_CHARTOITEM
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_SETFONT
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_GETFONT
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_SETHOTKEY
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_GETHOTKEY
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0034
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0035
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0036
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_QUERYDRAGICON
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0038
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_COMPAREITEM
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x003A
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x003B
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x003C
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_GETOBJECT
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x003E
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x003F
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0040
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_COMPACTING
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0042
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0043
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_COMMNOTIFY
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0045
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_WINDOWPOSCHANGING
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_WINDOWPOSCHANGED
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_POWER
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0049
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_COPYDATA
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_CANCELJOURNAL
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x004C
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x004D
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_NOTIFY
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x004F
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_INPUTLANGCHANGEREQUEST
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_INPUTLANGCHANGE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_TCARD
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_HELP
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_USERCHANGED
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_NOTIFYFORMAT
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0056
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0057
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0058
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0059
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x005A
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x005B
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x005C
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x005D
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x005E
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x005F
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0060
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0061
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0062
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0063
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0064
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0065
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0066
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0067
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0068
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0069
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x006A
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x006B
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x006C
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x006D
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x006E
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x006F
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0070
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0071
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0072
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0073
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0074
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0075
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0076
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0077
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0078
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0079
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x007A
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_CONTEXTMENU
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_STYLECHANGING
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_STYLECHANGED
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_DISPLAYCHANGE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_GETICON
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_SETICON
    {UNICODE_INLPCREATESTRUCT,      ANSI_INLPCREATESTRUCT   }, // WM_NCCREATE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_NCDESTROY
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_NCCALCSIZE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_NCHITTEST
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_NCPAINT
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_NCACTIVATE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_GETDLGCODE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_SYNCPAINT
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0089
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x008A
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x008B
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x008C
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x008D
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x008E
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x008F
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0090
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0091
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0092
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0093
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0094
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0095
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0096
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0097
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0098
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0099
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x009A
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x009B
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x009C
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x009D
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x009E
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x009F
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_NCMOUSEMOVE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_NCLBUTTONDOWN
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_NCLBUTTONUP
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_NCLBUTTONDBLCLK
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_NCRBUTTONDOWN
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_NCRBUTTONUP
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_NCRBUTTONDBLCLK
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_NCMBUTTONDOWN
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_NCMBUTTONUP
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_NCMBUTTONDBLCLK
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x00AA
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_NCXBUTTONDOWN
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_NCXBUTTONUP
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_NCXBUTTONDBLCLK
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x00AE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x00AF
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // EM_GETSEL
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // EM_SETSEL
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // EM_GETRECT
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // EM_SETRECT
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // EM_SETRECTNP
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // EM_SCROLL
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // EM_LINESCROLL
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // EM_SCROLLCARET
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // EM_GETMODIFY
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // EM_SETMODIFY
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // EM_GETLINECOUNT
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // EM_LINEINDEX
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // EM_SETHANDLE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // EM_GETHANDLE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // EM_GETTHUMB
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x00BF
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x00C0
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // EM_LINELENGTH
    {UNICODE_INSTRINGNULL,          ANSI_INSTRINGNULL       }, // EM_REPLACESEL
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x00C3
    {UNICODE_INCNTOUTSTRING,        ANSI_INCNTOUTSTRING     }, // EM_GETLINE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // EM_LIMITTEXT
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // EM_CANUNDO
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // EM_UNDO
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // EM_FMTLINES
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // EM_LINEFROMCHAR
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x00CA
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // EM_SETTABSTOPS
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // EM_SETPASSWORDCHAR
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // EM_EMPTYUNDOBUFFER
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // EM_GETFIRSTVISIBLELINE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // EM_SETREADONLY
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // EM_SETWORDBREAKPROC
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // EM_GETWORDBREAKPROC
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // EM_GETPASSWORDCHAR
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // EM_SETMARGINS
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // EM_GETMARGINS
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // EM_GETLIMITTEXT
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // EM_POSFROMCHAR
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // EM_CHARFROMPOS
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // EM_SETIMESTATUS
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // EM_GETIMESTATUS
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x00DA
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x00DB
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x00DC
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x00DD
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x00DE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x00DF
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // SBM_SETPOS
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // SBM_GETPOS
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // SBM_SETRANGE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // SBM_GETRANGE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // SBM_ENABLE_ARROWS
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x00E5
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // SBM_SETRANGEREDRAW
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x00E7
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x00E8
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // SBM_SETSCROLLINFO
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // SBM_GETSCROLLINFO
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // SBM_GETSCROLLBARINFO
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x00EC
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x00ED
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x00EE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x00EF
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x00F0
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x00F1
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x00F2
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x00F3
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x00F4
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x00F5
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x00F6
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x00F7
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x00F8
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x00F9
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x00FA
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x00FB
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x00FC
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x00FD
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_INPUT_DEVICE_CHANGE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_INPUT
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_KEYDOWN
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_KEYUP
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_CHAR
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_DEADCHAR
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_SYSKEYDOWN
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_SYSKEYUP
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_SYSCHAR
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_SYSDEADCHAR
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_KEYLAST
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_UNICHAR
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x010A
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x010B
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x010C
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_IME_STARTCOMPOSITION
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_IME_ENDCOMPOSITION
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_IME_KEYLAST
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_INITDIALOG
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_COMMAND
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_SYSCOMMAND
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_TIMER
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_HSCROLL
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_VSCROLL
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_INITMENU
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_INITMENUPOPUP
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0118
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_GESTURE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_GESTURENOTIFY
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x011B
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x011C
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x011D
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x011E
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_MENUSELECT
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_MENUCHAR
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_ENTERIDLE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_MENURBUTTONUP
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_MENUDRAG
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_MENUGETOBJECT
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_UNINITMENUPOPUP
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_MENUCOMMAND
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_CHANGEUISTATE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_UPDATEUISTATE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_QUERYUISTATE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x012A
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x012B
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x012C
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x012D
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x012E
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x012F
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0130
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0131
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_CTLCOLORMSGBOX
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_CTLCOLOREDIT
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_CTLCOLORLISTBOX
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_CTLCOLORBTN
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_CTLCOLORDLG
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_CTLCOLORSCROLLBAR
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_CTLCOLORSTATIC
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0139
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x013A
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x013B
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x013C
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x013D
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x013E
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x013F
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // CB_GETEDITSEL
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // CB_LIMITTEXT
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // CB_SETEDITSEL
    {UNICODE_INCBOXSTRING,          ANSI_INCBOXSTRING       }, // CB_ADDSTRING
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // CB_DELETESTRING
    {UNICODE_INSTRING,              ANSI_INSTRING           }, // CB_DIR
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // CB_GETCOUNT
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // CB_GETCURSEL
    {UNICODE_OUTCBOXSTRING,         ANSI_OUTCBOXSTRING      }, // CB_GETLBTEXT
    {UNICODE_GETDBCSTEXTLENGTHS,    ANSI_GETDBCSTEXTLENGTHS }, // CB_GETLBTEXTLEN
    {UNICODE_INCBOXSTRING,          ANSI_INCBOXSTRING       }, // CB_INSERTSTRING
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // CB_RESETCONTENT
    {UNICODE_INCBOXSTRING,          ANSI_INCBOXSTRING       }, // CB_FINDSTRING
    {UNICODE_INCBOXSTRING,          ANSI_INCBOXSTRING       }, // CB_SELECTSTRING
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // CB_SETCURSEL
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // CB_SHOWDROPDOWN
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // CB_GETITEMDATA
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // CB_SETITEMDATA
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // CB_GETDROPPEDCONTROLRECT
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // CB_SETITEMHEIGHT
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // CB_GETITEMHEIGHT
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // CB_SETEXTENDEDUI
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // CB_GETEXTENDEDUI
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // CB_GETDROPPEDSTATE
    {UNICODE_INCBOXSTRING,          ANSI_INCBOXSTRING       }, // CB_FINDSTRINGEXACT
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // CB_SETLOCALE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // CB_GETLOCALE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // CB_GETTOPINDEX
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // CB_SETTOPINDEX
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // CB_GETHORIZONTALEXTENT
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // CB_SETHORIZONTALEXTENT
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // CB_GETDROPPEDWIDTH
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // CB_SETDROPPEDWIDTH
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // CB_INITSTORAGE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0162
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // CB_MULTIPLEADDSTRING
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // CB_GETCOMBOBOXINFO
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0165
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0166
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0167
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0168
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0169
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x016A
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x016B
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x016C
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x016D
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x016E
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x016F
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // STM_SETICON
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // STM_GETICON
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // STM_SETIMAGE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // STM_GETIMAGE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0174
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0175
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0176
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0177
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0178
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0179
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x017A
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x017B
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x017C
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x017D
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x017E
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x017F
    {UNICODE_INLBOXSTRING,          ANSI_INLBOXSTRING       }, // LB_ADDSTRING
    {UNICODE_INLBOXSTRING,          ANSI_INLBOXSTRING       }, // LB_INSERTSTRING
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // LB_DELETESTRING
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // LB_SELITEMRANGEEX
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // LB_RESETCONTENT
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // LB_SETSEL
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // LB_SETCURSEL
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // LB_GETSEL
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // LB_GETCURSEL
    {UNICODE_OUTLBOXSTRING,         ANSI_OUTLBOXSTRING      }, // LB_GETTEXT
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // LB_GETTEXTLEN
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // LB_GETCOUNT
    {UNICODE_INLBOXSTRING,          ANSI_INLBOXSTRING       }, // LB_SELECTSTRING
    {UNICODE_INSTRING,              ANSI_INSTRING           }, // LB_DIR
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // LB_GETTOPINDEX
    {UNICODE_INLBOXSTRING,          ANSI_INLBOXSTRING       }, // LB_FINDSTRING
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // LB_GETSELCOUNT
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // LB_GETSELITEMS
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // LB_SETTABSTOPS
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // LB_GETHORIZONTALEXTENT
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // LB_SETHORIZONTALEXTENT
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // LB_SETCOLUMNWIDTH
    {UNICODE_INSTRING,              ANSI_INSTRING           }, // LB_ADDFILE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // LB_SETTOPINDEX
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // LB_GETITEMRECT
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // LB_GETITEMDATA
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // LB_SETITEMDATA
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // LB_SELITEMRANGE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // LB_SETANCHORINDEX
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // LB_GETANCHORINDEX
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // LB_SETCARETINDEX
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // LB_GETCARETINDEX
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // LB_SETITEMHEIGHT
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // LB_GETITEMHEIGHT
    {UNICODE_INLBOXSTRING,          ANSI_INLBOXSTRING       }, // LB_FINDSTRINGEXACT
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01A3
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01A4
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // LB_SETLOCALE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // LB_GETLOCALE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // LB_SETCOUNT
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // LB_INITSTORAGE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // LB_ITEMFROMPOINT
    {UNICODE_INLBOXSTRING,          ANSI_INLBOXSTRING       }, // 0x01AA
    {UNICODE_INLBOXSTRING,          ANSI_INLBOXSTRING       }, // 0x01AB
    {UNICODE_INLBOXSTRING,          ANSI_INLBOXSTRING       }, // 0x01AC
    {UNICODE_INLBOXSTRING,          ANSI_INLBOXSTRING       }, // 0x01AD
    {UNICODE_INLBOXSTRING,          ANSI_INLBOXSTRING       }, // 0x01AE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01AF
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01B0
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // LB_MULTIPLEADDSTRING
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // LB_GETLISTBOXINFO
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01B3
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01B4
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01B5
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01B6
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01B7
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01B8
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01B9
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01BA
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01BB
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01BC
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01BD
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01BE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01BF
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01C0
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01C1
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01C2
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01C3
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01C4
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01C5
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01C6
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01C7
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01C8
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01C9
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01CA
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01CB
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01CC
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01CD
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01CE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01CF
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01D0
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01D1
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01D2
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01D3
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01D4
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01D5
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01D6
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01D7
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01D8
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01D9
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01DA
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01DB
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01DC
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01DD
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01DE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01DF
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01E0
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01E1
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01E2
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01E3
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01E4
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01E5
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01E6
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01E7
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01E8
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01E9
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01EA
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01EB
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01EC
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01ED
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01EE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01EF
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01F0
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01F1
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01F2
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01F3
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01F4
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01F5
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01F6
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01F7
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01F8
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01F9
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01FA
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01FB
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01FC
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01FD
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01FE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x01FF
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_MOUSEMOVE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_LBUTTONDOWN
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_LBUTTONUP
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_LBUTTONDBLCLK
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_RBUTTONDOWN
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_RBUTTONUP
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_RBUTTONDBLCLK
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_MBUTTONDOWN
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_MBUTTONUP
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_MOUSELAST
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_MOUSEWHEEL
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_XBUTTONDOWN
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_XBUTTONUP
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_XBUTTONDBLCLK
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_MOUSEHWHEEL
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x020F
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_PARENTNOTIFY
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_ENTERMENULOOP
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_EXITMENULOOP
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_NEXTMENU
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_SIZING
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_CAPTURECHANGED
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_MOVING
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0217
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_POWERBROADCAST
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_DEVICECHANGE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x021A
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x021B
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x021C
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x021D
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x021E
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x021F
    {UNICODE_INLPMDICREATESTRUCT,   ANSI_INLPMDICREATESTRUCT}, // WM_MDICREATE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_MDIDESTROY
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_MDIACTIVATE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_MDIRESTORE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_MDINEXT
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_MDIMAXIMIZE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_MDITILE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_MDICASCADE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_MDIICONARRANGE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_MDIGETACTIVE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x022A
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x022B
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x022C
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x022D
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x022E
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x022F
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_MDISETMENU
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_ENTERSIZEMOVE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_EXITSIZEMOVE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_DROPFILES
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_MDIREFRESHMENU
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0235
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0236
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0237
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0238
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0239
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x023A
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x023B
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x023C
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x023D
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x023E
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x023F
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_TOUCH
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0241
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0242
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0243
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0244
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0245
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0246
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0247
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0248
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0249
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x024A
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x024B
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x024C
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x024D
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x024E
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x024F
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0250
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0251
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0252
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0253
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0254
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0255
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0256
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0257
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0258
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0259
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x025A
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x025B
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x025C
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x025D
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x025E
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x025F
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0260
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0261
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0262
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0263
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0264
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0265
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0266
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0267
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0268
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0269
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x026A
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x026B
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x026C
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x026D
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x026E
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x026F
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0270
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0271
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0272
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0273
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0274
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0275
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0276
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0277
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0278
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0279
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x027A
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x027B
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x027C
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x027D
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x027E
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x027F
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0280
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_IME_SETCONTEXT
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_IME_NOTIFY
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_IME_CONTROL
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_IME_COMPOSITIONFULL
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_IME_SELECT
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_IME_CHAR
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0287
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_IME_REQUEST
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0289
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x028A
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x028B
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x028C
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x028D
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x028E
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x028F
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_IME_KEYDOWN
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_IME_KEYUP
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0292
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0293
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0294
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0295
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0296
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0297
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0298
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0299
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x029A
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x029B
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x029C
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x029D
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x029E
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x029F
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_NCMOUSEHOVER
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_MOUSEHOVER
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_NCMOUSELEAVE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_MOUSELEAVE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02A4
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02A5
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02A6
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02A7
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02A8
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02A9
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02AA
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02AB
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02AC
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02AD
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02AE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02AF
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02B0
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_WTSSESSION_CHANGE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02B2
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02B3
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02B4
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02B5
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02B6
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02B7
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02B8
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02B9
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02BA
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02BB
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02BC
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02BD
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02BE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02BF
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_TABLET_FIRST
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02C1
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02C2
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02C3
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02C4
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02C5
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02C6
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02C7
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02C8
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02C9
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02CA
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02CB
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02CC
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02CD
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02CE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02CF
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02D0
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02D1
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02D2
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02D3
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02D4
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02D5
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02D6
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02D7
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02D8
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02D9
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02DA
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02DB
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02DC
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02DD
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02DE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_TABLET_LAST
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02E0
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02E1
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02E2
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02E3
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02E4
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02E5
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02E6
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02E7
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02E8
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02E9
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02EA
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02EB
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02EC
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02ED
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02EE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02EF
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02F0
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02F1
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02F2
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02F3
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02F4
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02F5
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02F6
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02F7
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02F8
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02F9
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02FA
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02FB
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02FC
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02FD
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02FE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x02FF
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_CUT
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_COPY
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_PASTE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_CLEAR
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_UNDO
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_RENDERFORMAT
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_RENDERALLFORMATS
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_DESTROYCLIPBOARD
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_DRAWCLIPBOARD
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_PAINTCLIPBOARD
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_VSCROLLCLIPBOARD
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_SIZECLIPBOARD
    {UNICODE_INCNTOUTSTRINGNULL,    ANSI_INCNTOUTSTRINGNULL }, // WM_ASKCBFORMATNAME
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_CHANGECBCHAIN
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_HSCROLLCLIPBOARD
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_QUERYNEWPALETTE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_PALETTEISCHANGING
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_PALETTECHANGED
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_HOTKEY
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0313
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0314
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0315
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0316
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_PRINT
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_PRINTCLIENT
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_APPCOMMAND
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_THEMECHANGED
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x031B
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x031C
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_CLIPBOARDUPDATE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_DWMCOMPOSITIONCHANGED
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_DWMNCRENDERINGCHANGED
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_DWMCOLORIZATIONCOLORCHANGED
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_DWMWINDOWMAXIMIZEDCHANGE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0322
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_DWMSENDICONICTHUMBNAIL
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0324
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0325
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_DWMSENDICONICLIVEPREVIEWBITMAP
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0327
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0328
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0329
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x032A
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x032B
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x032C
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x032D
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x032E
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x032F
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0330
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0331
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0332
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0333
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0334
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0335
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0336
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0337
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0338
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0339
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x033A
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x033B
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x033C
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x033D
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x033E
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_GETTITLEBARINFOEX
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0340
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0341
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0342
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0343
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0344
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0345
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0346
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0347
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0348
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0349
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x034A
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x034B
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x034C
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x034D
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x034E
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x034F
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0350
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0351
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0352
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0353
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0354
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0355
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0356
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0357
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_HANDHELDFIRST
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0359
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x035A
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x035B
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x035C
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x035D
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x035E
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_HANDHELDLAST
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_AFXFIRST
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0361
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0362
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0363
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0364
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0365
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0366
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0367
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0368
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0369
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x036A
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x036B
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x036C
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x036D
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x036E
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x036F
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0370
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0371
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0372
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0373
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0374
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0375
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0376
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0377
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0378
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0379
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x037A
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x037B
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x037C
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x037D
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x037E
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_AFXLAST
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_PENWINFIRST
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0381
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0382
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0383
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0384
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0385
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0386
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0387
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0388
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0389
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x038A
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x038B
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x038C
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x038D
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x038E
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // WM_PENWINLAST
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0390
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0391
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0392
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0393
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0394
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0395
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0396
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0397
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0398
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x0399
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x039A
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x039B
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x039C
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x039D
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x039E
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x039F
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03A0
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03A1
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03A2
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03A3
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03A4
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03A5
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03A6
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03A7
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03A8
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03A9
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03AA
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03AB
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03AC
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03AD
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03AE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03AF
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03B0
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03B1
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03B2
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03B3
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03B4
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03B5
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03B6
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03B7
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03B8
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03B9
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03BA
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03BB
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03BC
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03BD
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03BE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03BF
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03C0
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03C1
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03C2
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03C3
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03C4
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03C5
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03C6
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03C7
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03C8
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03C9
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03CA
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03CB
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03CC
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03CD
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03CE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03CF
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03D0
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03D1
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03D2
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03D3
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03D4
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03D5
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03D6
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03D7
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03D8
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03D9
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03DA
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03DB
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03DC
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03DD
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03DE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03DF
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03E0
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03E1
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03E2
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03E3
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03E4
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03E5
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03E6
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03E7
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03E8
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03E9
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03EA
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03EB
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03EC
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03ED
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03EE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03EF
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03F0
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03F1
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03F2
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03F3
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03F4
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03F5
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03F6
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03F7
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03F8
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03F9
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03FA
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03FB
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03FC
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03FD
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03FE
    {UNICODE_EMPTY,                 ANSI_EMPTY              }, // 0x03FF
};


VOID InitEmptyLargeString(PLARGE_UNICODE_STRING String);
VOID InitStringFromLargeString(PUNICODE_STRING UnicodeString, PLARGE_UNICODE_STRING LargeString);

PLARGE_UNICODE_STRING LargeStringDuplicate(PLARGE_UNICODE_STRING LargeString, PLARGE_UNICODE_STRING Destination);
PLARGE_UNICODE_STRING LargeStringAnsiToUnicode(PLARGE_UNICODE_STRING LargeAnsiString, PLARGE_UNICODE_STRING LargeUnicodeString);
PLARGE_UNICODE_STRING CaptureAnsiWindowName(PLARGE_UNICODE_STRING WindowName, PLARGE_UNICODE_STRING UnicodeWindowName);

// Hooked functions
LRESULT NTAPI WindowProcW(HWND Window, UINT Message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK CBTProc(int nCode, WPARAM wParam, LPARAM lParam);