class TEdit: public TObject
{
public:
    void (*onEdit)( TEdit* );
    void (*onFocus)( TEdit* );
    void (*onKillFocus)( TEdit* );

    TEdit( TForm*, LPSTR, int, int, int, int );
    void SetMaxLenght(int);
    void SetEnable(bool);

    /**@VirtualByTObject
    void Focus();
    void SetText( LPSTR );
    LPSTR getText(  );
    void Redraw();
    void Free();**/
};
