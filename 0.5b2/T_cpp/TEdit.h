TEdit::TEdit( TForm* parent, LPSTR caption, int x = 0, int y = 0, int w = 120, int h = 20 )
{
    this->_id = GLOBAL++;
    this->hWnd = CreateWindow(
                                    "edit",
                                    caption,
                                    WS_CHILD | WS_VISIBLE | WS_BORDER,
                                    x, y,
                                    w, h,
                                    parent->hWnd,
                                    (HMENU)GLOBAL,
                                    wapi->_H_INST,
                                    NULL
                                 );
    if( !this->hWnd ){
        Message( (char*)"Cannot create TEdit" );
        return;
    }
    wapi->_T_EDIT[ GLOBAL ] = this;
}

void TEdit::SetMaxLenght(int max)
{
        SendMessage(this->hWnd, EM_LIMITTEXT, max, 0);
}
void TEdit::SetEnable(bool i)
{
        if(!i)
            SendMessage(this->hWnd, EM_SETREADONLY, ES_READONLY, true);
        else
            SendMessage(this->hWnd, EM_SETREADONLY, false, false);
}
