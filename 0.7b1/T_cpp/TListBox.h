TListBox::TListBox( TForm* parent, int x = 0, int y = 0, int w = 100, int h = 150 )
{
    GLOBAL++;
    this->hWnd = CreateWindow(
                                    "listbox", "",
                                    WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_BORDER,
                                    x, y,
                                    w, h,
                                    parent->hWnd,
                                    (HMENU)GLOBAL,
                                    wapi->_H_INST,
                                    NULL
                                 );
    if( !this->hWnd ){
        Message( (char*)"Cannot create TListBox" );
        return;
    }
    wapi->_T_LISTBOX[ GLOBAL ] = this;
}
void TListBox::Add(LPSTR text)
{
    static int currentLine;
    SendMessage( this->hWnd, LB_ADDSTRING, 0, (LPARAM)(LPCTSTR)text );
    this->items.lines[ currentLine++ ] = text;///@FIXIt::
    this->items.count++;
}
void TListBox::Delete( int index)
{
    SendMessage( this->hWnd, LB_DELETESTRING, (WPARAM)index, 0 );
    this->items.count--;
}
void TListBox::SetSelect( int i )
{
    SendMessage( this->hWnd, LB_SETCURSEL, i, 0 );
}
int TListBox::GetSelect()
{
    return SendMessage( this->hWnd, LB_GETCURSEL, 0, 0 );
}
