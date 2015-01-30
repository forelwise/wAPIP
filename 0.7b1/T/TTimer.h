class TTimer{
public:
    HWND hWnd;
    int _id;
    UINT interval;
    bool repeat;
    void (*onTimer)( TTimer* );

    TTimer( TForm* );
    void Start();
    void Stop();
    ~TTimer();
};/*
class TTimerST{
public:
    static void Create( TForm*, int, bool, void(*onTimer)(TTimer*) );
};*/

