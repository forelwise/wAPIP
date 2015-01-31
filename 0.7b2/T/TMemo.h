class TMemo: public TObject
{
public:
    void (*onEdit)( TMemo* );
    TMemo( TForm*, LPSTR, int, int, int, int );
};
