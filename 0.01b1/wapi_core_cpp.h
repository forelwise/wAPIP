/** Описание методов и классов wAPI+ **/


void app::close( LPSTR msg = NULL ){
        if( msg != NULL )
            MessageBoxA(0, msg, wapi->_C_LASSNAME, 0);
    PostQuitMessage(0);
}


LRESULT CALLBACK WAPI_W_NDPROC(HWND hwnd, UINT msg, WPARAM wP, LPARAM lP)
{
    switch( msg )
    {
        default:
            return DefWindowProc(hwnd, msg, wP, lP);
    }

}
void Message(LPSTR msg)
{
    MessageBoxA(0, msg, wapi->_C_LASSNAME, 0);
}

int _WAPI_P::__init(HINSTANCE hInst, LPSTR CN){

            HICON hIcon = LoadIcon(NULL, IDI_APPLICATION);
            HCURSOR hCursor = LoadCursor(NULL, IDC_ARROW);

            this->_W_ND.hInstance = hInst;
            this->_W_ND.lpszClassName = CN;
            this->_W_ND.lpfnWndProc = WAPI_W_NDPROC;
            this->_W_ND.style = CS_HREDRAW | CS_VREDRAW;
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
}


TForm::TForm( LPSTR CAP, int w = 640, int h = 480, int x = 0, int y = 0 )
{
    this->hWnd = CreateWindowEx(
                                   0,
                                   wapi->_C_LASSNAME,
                                   CAP,
                                   WS_OVERLAPPEDWINDOW,
                                   x, y,
                                   w, h,
                                   HWND_DESKTOP,
                                   NULL,
                                   wapi->_H_INST,
                                   NULL
                                   );
    if( !this->hWnd )
        Message((char*)"Can`t create window");

}
void TForm::Show(){
    ShowWindow(this->hWnd, SW_SHOW);
}
void TForm::Hide(){
    ShowWindow(this->hWnd, SW_HIDE);
}
void TForm::Minimize(){
    ShowWindow(this->hWnd, SW_MINIMIZE);
}
void TForm::Maximize(){
    ShowWindow( this->hWnd, SW_MAXIMIZE );
}

TButton::TButton( TForm* parent, LPSTR caption, int x = 0, int y = 0, int w = 120, int h = 32 )
{
    this->hWnd = CreateWindow(
                                    "button",
                                    caption,
                                    WS_CHILD | WS_VISIBLE,
                                    x, y,
                                    w, h,
                                    parent->hWnd,
                                    0,
                                    wapi->_H_INST,
                                    NULL
                                 );
}
