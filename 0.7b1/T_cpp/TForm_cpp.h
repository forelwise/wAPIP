TForm::TForm( LPSTR CAP = wapi->_C_LASSNAME, int W_STYLE = 0, int w = 640, int h = 480, int x = 0, int y = 0 )
{
    static int is_first = 1;
    if( is_first == 1 )
    {
        is_first = 0;
        wapi->SetMainForm( this );
    }



    this->hWnd = CreateWindowEx(
                                   9,
                                   wapi->_C_LASSNAME,
                                   CAP,
                                   W_STYLE,
                                   x, y,
                                   w, h,
                                   HWND_DESKTOP,
                                   NULL,
                                   wapi->_H_INST,
                                   NULL
                                   );
    if( !this->hWnd )
        Message((char*)"Can`t create window");
    wapi->_T_FORMS[ GLOBAL ] = this;
//    this->Caption = CAP;
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
