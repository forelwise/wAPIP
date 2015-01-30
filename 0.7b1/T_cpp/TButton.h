TButton::TButton( TForm* parent, LPSTR caption, int x = 0, int y = 0, int w = 120, int h = 32 )
{
    GLOBAL++;

    this->hWnd = CreateWindow(
                                    "button",
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
        Message(_l"Error create button!");
        return;
    }

//    this->Caption = caption;
    wapi->_T_BUTTONS[ GLOBAL ] = this;
}
void TButton::doClick()
{
    if( this->onClick == NULL )
        return;
    this->onClick( this );
}
