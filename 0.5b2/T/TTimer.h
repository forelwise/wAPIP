class TTimer{
public:
    HWND hWnd;
    UINT _id;
    UINT interval;
    bool repeat;
    void (*onTimer)( TTimer* );

    TTimer( TForm* );
    void Start();
    void Stop();
    ~TTimer();
};

