TMemo::TMemo( TForm* parent, LPSTR caption, int x = 0, int y = 0, int w = 120, int h = 100 )
{
    this->_id = GLOBAL++;
    this->hWnd = CreateWindow(
                                    "edit",
                                    caption,
                                    WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_MULTILINE | WS_HSCROLL | WS_VSCROLL,
                                    x, y,
                                    w, h,
                                    parent->hWnd,
                                    (HMENU)GLOBAL,
                                    wapi->_H_INST,
                                    NULL
                                 );
    if( !this->hWnd ){
        Message( (char*)"Cannot create TMemo" );
        return;
    }
    wapi->_T_MEMO[  GLOBAL ] = this;
}
