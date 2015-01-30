/** Прототипы методов и классов wAPI+ **/

LRESULT CALLBACK WAPI_W_NDPROC(HWND, UINT, WPARAM, LPARAM);
void Message( LPSTR );

class _WAPI_P
{
public:
    HINSTANCE _H_INST;
    LPSTR _C_LASSNAME;
    WNDCLASSEX _W_ND;

    int __init( HINSTANCE, LPSTR );
};
_WAPI_P *wapi = new _WAPI_P;
class TObject
{
public:
    HWND hWnd;
    HWND _parent;
    LPSTR caption;

};
class TForm: public TObject
{
public:
    TForm( LPSTR, int, int, int, int );

    void Show();
    void Hide();
    void Minimize();
    void Maximize();
};

class TButton: public TObject
{
public:
    TButton( TForm*, LPSTR, int, int, int, int );

};


class app
{
public:
    void static close(LPSTR);
};
#include "wapi_core_cpp.h"
