TCheckBox::TCheckBox( TForm* parent, LPSTR caption, int x = 0, int y = 0, int w = 120, int h = 20 )
{
    GLOBAL++;
    this->hWnd = CreateWindow(
                                    "button",
                                    caption,
                                    WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
                                    x, y,
                                    w, h,
                                    parent->hWnd,
                                    (HMENU)GLOBAL,
                                    wapi->_H_INST,
                                    NULL
                                 );
    if( !this->hWnd ){
        Message((char*)"Error create CheckBox!");
        return;
    }

    wapi->_T_CHECKBOX[ GLOBAL ] = this;

}

/*void TCheckBox::Focus()
{
   TObject::Focus();
}
void TCheckBox::SetText( LPSTR text)
{
    TObject::SetText( text );
}
LPSTR TCheckBox::getText(  )
{
    return TObject::getText();
}
*/
