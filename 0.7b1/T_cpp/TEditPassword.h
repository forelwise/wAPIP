TEditPassword::TEditPassword( TForm* parent, LPSTR caption, int x = 0, int y = 0, int w = 120, int h = 20 )
{
    GLOBAL++;
    this->hWnd = CreateWindow(
                                    "edit",
                                    caption,
                                    WS_CHILD | WS_VISIBLE | WS_BORDER | ES_PASSWORD,
                                    x, y,
                                    w, h,
                                    parent->hWnd,
                                    (HMENU)GLOBAL,
                                    wapi->_H_INST,
                                    NULL
                                 );
    if( !this->hWnd ){
        Message( (char*)"Cannot create TEditPassword" );
        return;
    }
    wapi->_T_EDITP[  GLOBAL  ] = this;
}
void TEditPassword::SetEnable( bool i )
{
        if(!i)
            SendMessage(this->hWnd, EM_SETREADONLY, ES_READONLY, true);
        else
            SendMessage(this->hWnd, EM_SETREADONLY, false, false);
}
void TEditPassword::SetMaxLenght( int i )
{
    SendMessage(this->hWnd, EM_LIMITTEXT, i, 0);
}
void TEditPassword::SetPassworwWord(LPSTR w)
{
    SendMessage( this->hWnd, EM_SETPASSWORDCHAR, (WPARAM)w, 0 );
}
