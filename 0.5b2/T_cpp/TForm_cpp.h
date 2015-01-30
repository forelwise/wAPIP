TForm::TForm( LPSTR CAP = wapi->_C_LASSNAME, int w = 640, int h = 480, int x = 0, int y = 0 )
{
    this->hWnd = CreateWindowEx(
                                   9,
                                   wapi->_C_LASSNAME,
                                   CAP,
                                   WS_OVERLAPPEDWINDOW,
                                   x, y,
                                   w, h,
                                   HWND_DESKTOP,
                                   0,
                                   wapi->_H_INST,
                                   NULL
                                   );
    if( !this->hWnd )
        Message((char*)"Can`t create window");
    wapi->_T_FORMS[ GLOBAL ] = this;
    this->Caption = CAP;

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
void TForm::Focus()
{
    TObject::Focus();
}
void TForm::SetText( LPSTR str )
{
    TObject::SetText(str);
}
LPSTR TForm::getText(  )
{
    return TObject::getText();
}
