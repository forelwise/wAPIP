TProgressBar::TProgressBar( TForm* parent, int pos, int x, int y, int w, int h )
{
    this->hWnd = CreateWindowEx( 0, "msctls_progress32", NULL, WS_CHILD | WS_VISIBLE, x, y, w, h, parent->hWnd, (HMENU)GLOBAL++, wapi->_H_INST, NULL );
    if( !this->hWnd )
    {
        Message( (char*)"Cannot create TProgressBar" );
        return;
    }
    SendMessage( this->hWnd, PBM_SETRANGE, 0, MAKELONG(0, 100) );
    SendMessage( this->hWnd, PBM_SETSTEP, (WPARAM)1, 0 );
    this->SetPos( pos );
}
void TProgressBar::SetPos( int pos )
{
    SendMessage( this->hWnd, PBM_SETPOS, (WPARAM)pos, 0 );
}
int TProgressBar::GetPos()
{
    return SendMessage( this->hWnd, PBM_GETPOS, 0, 0 );
}
