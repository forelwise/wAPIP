class TForm: public TObject
{
public:
    TForm( LPSTR, int, int, int, int, int );

    void Minimize();
    void Maximize();

    void Focus();
    void SetText( LPSTR );
    LPSTR getText(  );
};

