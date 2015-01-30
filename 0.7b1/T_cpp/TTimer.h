TTimer::TTimer( TForm* parent )
{
    this->_id = (GLOBAL > 5) ? GLOBAL++:5;
    wapi->_T_TIMER[ this->_id ] = this;
    this->hWnd = parent->hWnd;

}
void TTimer::Start()
{
    SetTimer( this->hWnd, this->_id, this->interval, _W_API_TIMER_PROC );
}
void TTimer::Stop()
{
    KillTimer( this->hWnd, this->_id );
}
TTimer::~TTimer()
{
    this->Stop();
}
/*void TTimerST::Create(TForm* parent, int interval, bool repeat, void( *onTimer )(TTimer*))
{
    TTimer* timer = new TTimer(parent, ( GLOBAL > 5 ) ? GLOBAL++ : 5);
    timer->interval = interval;
    timer->repeat = repeat;
    timer->onTimer = onTimer;
    timer->Start();
}*/
