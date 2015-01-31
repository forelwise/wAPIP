class TCheckBox: public TObject
{
public:
    void  (*onClick)(TCheckBox*);
    TCheckBox( TForm*, LPSTR, int, int, int, int );

    /**@VirtualByTObject
    void Focus();
    void SetText( LPSTR );
    LPSTR getText(  );**/
};
