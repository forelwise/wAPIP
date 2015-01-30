/**

    class TCanvas. By Windows API+( wapi+, wAPI+ )
    Version: 0.1
    Author: @almalk454

    TCanvas* canvas;
    canvas = new TCanvas;

    canvas->Begin( form1 );
    canvas->TextColor = RGB( 255, 0, 0 );
    canvas->BKColor = RGB(0, 255, 0);
    canvas->TextAlign = TA_LEFT;
    canvas->TextOut(0, 0, _l"Helloma!");
    canvas->End();
    form1->Redraw();
**/
class TCanvas{
public:
    COLORREF BrushColor;
    COLORREF BKColor;
    UINT TextAlign;

    void (*onCanvas)( TCanvas* );

    HWND hWnd;
    HDC hDC;

    void Begin( TForm* );
    void SetPixel( int x, int y );
    void TextOut(int, int, LPSTR);
    void TextOutSystem( int, int, LPSTR );
    void Rect( int, int, int, int, bool );
    void FrameRect(int, int, int, int);
    void LineTo( int, int, int, int );
    void RoundRect( int, int, int, int, int, int );

    void End();
};

