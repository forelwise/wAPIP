TLabel::TLabel( TForm* parent, LPSTR caption, int x = 0, int y = 0, int w = 120, int h = 20 )
{
     GLOBAL++;
    this->hWnd = CreateWindow(
                                    "static",
                                    caption,
                                    WS_CHILD | WS_VISIBLE,
                                    x, y,
                                    w, h,
                                    parent->hWnd,
                                    (HMENU)GLOBAL,
                                    wapi->_H_INST,
                                    NULL
                                 );
    if( !this->hWnd ){
        Message( (char*)"Cannot create TLabel" );
        return;
    }
    wapi->_T_LABEL[  GLOBAL  ] = this;
}
