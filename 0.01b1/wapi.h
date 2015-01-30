/** Оболочка **/
#define WAPI
#ifndef _WINDOWS_H
    #include<windows.h>
    #define _WINDOWS_H
#endif
#ifndef _WAPI_CORE_H
    #define _WAPI_CORE_H
    #include "wapi_core.h"
#endif


int WAPI wapi_Init( HINSTANCE hInstance, LPSTR CN )
{
    return wapi->__init( hInstance,  CN);
}
void WAPI wapi_MainLoop()
{
    MSG msg;
    while( GetMessage(&msg, NULL, 0, 0) )
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}
