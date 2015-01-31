class TListBox: public TObject{
public:
    struct{
        int count;
        LPTSTR lines[ 256 ];///@FixMe::
    } items;

    TListBox( TForm* parent, int, int, int, int );
    void Add(LPSTR);
    void Delete( int );
    void SetSelect( int );
    int  GetSelect();
//private:
   // int currentLine;
};
