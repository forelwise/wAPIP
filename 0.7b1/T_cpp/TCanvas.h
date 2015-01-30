void TCanvas::Begin(TForm* form = NULL)
{
        this->hWnd = ( form == NULL ) ? wapi->GetMainForm()->hWnd : form->hWnd;
        this->hDC = GetDC(this->hWnd);
}
void TCanvas::TextOut(int x, int y, LPSTR text)
{
        ::SetBkColor( this->hDC, this->BKColor );
        ::SetTextColor( this->hDC, this->BrushColor );
        ::SetTextAlign( this->hDC, this->TextAlign );
        ::TextOut( this->hDC, x, y, text, strlen(text) );
}
void TCanvas::TextOutSystem(int x, int y, LPSTR text)
{
        HDC lastDC = this->hDC;
        this->hDC = GetWindowDC(this->hWnd);
        ::SetBkColor( this->hDC, this->BKColor );
        ::SetTextColor( this->hDC, this->BrushColor );
        ::SetTextAlign( this->hDC, this->TextAlign );
        ::TextOut( this->hDC, x, y, text, strlen(text) );
        this->hDC = lastDC;
}
void TCanvas::Rect( int x1, int y1, int x2, int y2, bool frame = false )
{
    RECT _rect;
    _rect.left = x1;
    _rect.right = x2;
    _rect.top = y1;
    _rect.bottom = y2;

    ::FillRect( this->hDC, &_rect, CreateSolidBrush( this->BKColor ) );
    if( frame )
        this->FrameRect( x1, y1, x2, y2 );
}
void TCanvas::FrameRect(int x1, int y1, int x2, int y2)
{
    RECT _rect;
    _rect.left = x1;
    _rect.right = x2;
    _rect.top = y1;
    _rect.bottom = y2;
    ::FrameRect( this->hDC, &_rect, CreateSolidBrush( this->BrushColor ) );
}
void TCanvas::LineTo(int x1, int y1, int x2, int y2)
{
    POINT ps;
    ::MoveToEx( this->hDC, x1, y1, &ps );
    ::LineTo( this->hDC, x2, y2 );
}
void TCanvas::SetPixel(int x, int y)
{
    ::SetPixel( this->hDC, x, y, this->BrushColor );
}
void TCanvas::RoundRect( int x1, int y1, int x2, int y2, int w, int h)
{
    ::RoundRect( this->hDC, x1, y1, x2, y2, w, h );
}
void TCanvas::End()
{
        ReleaseDC( this->hWnd, this->hDC );
        this->hWnd = NULL;
        this->hDC = NULL;
}
