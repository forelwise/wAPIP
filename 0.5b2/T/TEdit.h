class TEdit: public TObject
{
public:
    void (*onEdit)( TEdit* );

    TEdit( TForm*, LPSTR, int, int, int, int );
    void SetMaxLenght(int);
    void SetEnable(bool);
};
