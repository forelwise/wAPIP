/** Оболочка **/
#define WAPI

#ifndef _WINDOWS_H
    #include<windows.h>
    #include<windowsx.h>
    #ifdef WAPI_COMMCTRL
        #include<Commctrl.h>
    #endif
    #define _WINDOWS_H
#endif
#ifndef wAPI_NOCLOSE /// Резрешить закрытие окна
    #define wAPI_NOCLOSE 0
#endif
#ifndef wAPI_HREDRAW /// Перерисовывать окно при горизонтальном движении
    #define wAPI_HREDRAW 0
#endif
#ifndef wAPI_VREDRAW /// Перерисовывать окно при вертикальном движении
    #define wAPI_VREDRAW 0
#endif
#ifndef wAPI_CURSOR ///Стандартный курсор
    #define wAPI_CURSOR LoadCursor(NULL, IDC_ARROW)
#endif

#ifndef _WAPI_CORE_H
    #define _WAPI_CORE_H
    #include "wapi_core.h"
#endif

#define wapi_set( event, func_name ) wapi->event = func_name

#define wapi_Free( object ) object->Free(); delete object;
#define wapi_Redraw( object ) object->Redraw()

int WAPI wapi_Init( HINSTANCE hInstance, LPSTR CN, HICON hIcon = NULL )
{
    return wapi->__init( hInstance,  CN, (hIcon == NULL) ?  LoadIcon(NULL, IDI_APPLICATION) : hIcon);
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
void WAPI run( LPSTR filename )
{
        WinExec( filename, 0 );
}
