class TProgressBar : public TObject
{
public:
    TProgressBar( TForm*, int, int, int, int, int );
    void SetPos(int);
    int GetPos();
};
