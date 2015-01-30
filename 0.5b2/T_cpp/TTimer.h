TTimer::TTimer( TForm* parent )
{
    this->_id = GLOBAL++;
    this->hWnd = parent->hWnd;
    wapi->_T_TIMER[  GLOBAL ] = this;
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
