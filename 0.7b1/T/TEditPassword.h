class TEditPassword: public TObject
{
public:
    void(*onEdit)( TEditPassword* );

    TEditPassword( TForm*, LPSTR, int, int, int, int );
    void SetMaxLenght(int);
    void SetPassworwWord( LPSTR );
    void SetEnable( bool );
};
