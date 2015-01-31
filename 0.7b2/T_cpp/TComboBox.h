TComboBox::TComboBox( TForm* parent, int x = 0, int y = 0, int w = 120, int h = 300 )
{
    GLOBAL++;
    this->hWnd = CreateWindow("ComboBox", NULL, WS_CHILD | WS_VISIBLE | CBS_SIMPLE, 30, 30, 200, 100, parent->hWnd, (HMENU)GLOBAL, wapi->_H_INST, NULL);
    if( this->hWnd == NULL )
    {
        Message((char*)"Cannot create TComboBox");
        return;
    }
}
void TComboBox::Add( LPSTR string )
{
    SendMessage(this->hWnd, CB_ADDSTRING, 0, (LPARAM)string );
}
