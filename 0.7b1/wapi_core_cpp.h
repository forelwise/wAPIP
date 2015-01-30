/** Описание методов и классов wAPI+ **/

void _W_API_Event_Listener( WPARAM wP, LPARAM lP )
{
    switch( HIWORD( wP ) )
    {
        case BN_CLICKED:
            if( wapi->_T_BUTTONS[ LOWORD( wP ) ] != NULL )
                if( wapi->_T_BUTTONS[ LOWORD( wP ) ]->onClick != NULL  ){
                        ///wapi->_T_BUTTONS[ LOWORD( wP ) ]->onClick( wapi->_T_BUTTONS[ LOWORD( wP ) ] );

                        return;
            }
            if( wapi->_T_CHECKBOX[ LOWORD( wP ) ] != NULL ){
                if( wapi->_T_CHECKBOX[ LOWORD( wP ) ]->onClick != NULL )
                        wapi->_T_CHECKBOX[ LOWORD( wP ) ]->onClick( wapi->_T_CHECKBOX[ LOWORD( wP ) ] );
                       return;
            }
        break;
        case EN_CHANGE:
            if( wapi->_T_EDIT[ LOWORD( wP ) ] != NULL ){
                if( wapi->_T_EDIT[ LOWORD( wP ) ]->onEdit != NULL )
                        wapi->_T_EDIT[ LOWORD( wP ) ]->onEdit( wapi->_T_EDIT[ LOWORD( wP ) ] );
                    return;
            }
            if( wapi->_T_MEMO[ LOWORD( wP ) ] != NULL ){
                if(  wapi->_T_MEMO[ LOWORD( wP ) ]->onEdit != NULL )
                        wapi->_T_MEMO[ LOWORD( wP ) ]->onEdit( wapi->_T_MEMO[ LOWORD( wP ) ] );
                    return;
            }
            if( wapi->_T_EDITP[ LOWORD( wP ) ] != NULL ){
                if(  wapi->_T_EDITP[ LOWORD( wP ) ]->onEdit != NULL )
                        wapi->_T_EDITP[ LOWORD( wP ) ]->onEdit( wapi->_T_EDITP[ LOWORD( wP ) ] );
                    return;
            }
        break;
    }
}

LRESULT CALLBACK WAPI_W_NDPROC(HWND hwnd, UINT msg, WPARAM wP, LPARAM lP)
{
    switch( msg )
    {
        case WM_COMMAND:
            _W_API_Event_Listener( wP, lP );
        break;
        case WM_KEYDOWN:
            if( wapi->HotFunction != NULL )
                wapi->HotFunction( LOWORD(wP) );
        break;
        case WM_QUIT:
            PostQuitMessage(0);
        break;
        case WM_CLOSE:
            if( wapi->_T_FORMMAIN->hWnd == hwnd )
                app::close();
            ShowWindow( hwnd, SW_HIDE );
        break;
        case WM_PAINT:{
                canvas->onCanvas( canvas );
        }
        default:
            return DefWindowProc(hwnd, msg, wP, lP);
    }
    return 0;
}
void CALLBACK _W_API_TIMER_PROC(HWND hWnd, UINT msg, UINT_PTR id, DWORD dwTime)
{
    if(  wapi->_T_TIMER[ id ] != NULL  )
    {
        if( !wapi->_T_TIMER[ id ]->repeat ){
            wapi->_T_TIMER[ id ]->Stop();
            wapi->_T_TIMER[ id ]->onTimer( wapi->_T_TIMER[ id ] );
        }else   wapi->_T_TIMER[ id ]->onTimer( wapi->_T_TIMER[ id ] );
    }


}
void Message(LPSTR msg)
{
    MessageBoxA( (wapi->_T_FORMMAIN == NULL) ? 0 : wapi->_T_FORMMAIN->hWnd , msg, wapi->_C_LASSNAME, 0);
}
void Message(LPSTR msg, TForm* form)
{
    MessageBoxA(form->hWnd, msg, form->getText(), 0);
}
void Message(LPSTR msg, HWND hWnd)
{
    MessageBoxA(hWnd, msg, wapi->_C_LASSNAME, 0);
}

int _WAPI_P::__init( HINSTANCE hInst, LPSTR CN, HICON hIcon ){

            HCURSOR hCursor = wAPI_CURSOR;

            int win_style = 0;

            if( wAPI_NOCLOSE == 1 )
                win_style += CS_NOCLOSE;
            if( wAPI_HREDRAW == 1 )
                win_style += CS_HREDRAW;
            if( wAPI_VREDRAW == 1 )
                win_style += CS_VREDRAW;


            this->_W_ND.hInstance = hInst;
            this->_W_ND.lpszClassName = CN;
            this->_W_ND.lpfnWndProc = WAPI_W_NDPROC;
            this->_W_ND.style = win_style;
            this->_W_ND.cbSize = sizeof (WNDCLASSEX);


            this->_W_ND.hIcon = this->_W_ND.hIconSm = hIcon;
            this->_W_ND.hCursor = hCursor;
            this->_W_ND.lpszMenuName = NULL;
            this->_W_ND.cbClsExtra = 0;
            this->_W_ND.cbWndExtra = 0;
            this->_W_ND.hbrBackground = (HBRUSH)COLOR_WINDOW;

            if( !RegisterClassEx(&this->_W_ND) ){
                Message((char*)"Error registering class");
                return -1;
            }
            this->_C_LASSNAME = CN;
            this->_H_INST = hInst;

    return 0;
}/*
void _WAPI_P::RegCanvas( TCanvas* canv )
{
    this->_T_CANVAS = canv;
}*/
void _WAPI_P::SetMainForm(TForm* form)
{
    this->_T_FORMMAIN = form;
}
TForm* _WAPI_P::GetMainForm()
{
    return this->_T_FORMMAIN;
}

void TObject::Focus()
{
    SetFocus(this->hWnd);
}
void TObject::SetText( LPSTR caption )
{
    SetWindowText( this->hWnd, caption);
}
LPSTR TObject::getText()
{
    char text[1000];
    SendMessage( this->hWnd, WM_GETTEXT, 1000, (LPARAM)text );
    return text;
}
void TObject::Redraw()
{
     UpdateWindow( this->hWnd );
}
void TObject::Free()
{
    DestroyWindow( this->hWnd );
}
void TObject::Show()
{
    ShowWindow( this->hWnd, SW_SHOW );
}
void TObject::Hide()
{
    ShowWindow( this->hWnd, SW_HIDE );
}
void TObject::SetPos( int x = -1, int y = -1, int w = -1, int h = -1 )
{
   RECT r;
   GetWindowRect( this->hWnd, &r );
   SetWindowPos( this->hWnd,
                 HWND_TOP,
                ( x == -1 ) ? r.left : x,
                ( y == -1 ) ? r.top : y,
                ( w == -1 ) ? r.right : w,
                ( h == -1 ) ? r.bottom : h,
                SWP_SHOWWINDOW );
}
void TObject::ToUp()
{
   RECT r;
   GetWindowRect( this->hWnd, &r );
   SetWindowPos( this->hWnd,
                 HWND_TOP,
                r.left,
                r.top,
                r.right,
                r.bottom,
                SWP_SHOWWINDOW );
}
void TObject::ToDown(  )
{
   RECT r;
   GetWindowRect( this->hWnd, &r );
   SetWindowPos( this->hWnd,
                 HWND_BOTTOM,
                r.left,
                r.top,
                r.right,
                r.bottom,
                SWP_SHOWWINDOW );
}
