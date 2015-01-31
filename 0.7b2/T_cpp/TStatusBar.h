TStatusBar::TStatusBar( TForm* parent, LPSTR caption )
{
        this->hWnd = CreateStatusWindow( WS_CHILD | WS_VISIBLE, caption, parent->hWnd, GLOBAL++ );
}
void TStatusBar::SetText( LPSTR strText )
{
        TObject::SetText( strText );
}
