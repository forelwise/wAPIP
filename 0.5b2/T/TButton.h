class TButton: public TObject
{
public:
    void  (*onClick)(TButton*);

    TButton( TForm*, LPSTR, int, int, int, int );
    void doClick();


    /**@VirtualByTObject**/
    //void Focus();
    //void SetText( LPSTR );
    //LPSTR getText(  );

};

