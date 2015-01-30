/** Прототипы методов и классов wAPI+ **/
#define _l (char*)

LRESULT CALLBACK WAPI_W_NDPROC(HWND, UINT, WPARAM, LPARAM);
void CALLBACK _W_API_TIMER_PROC(HWND, UINT, UINT_PTR, DWORD);
int GLOBAL;


class TObject
{
public   :
    HWND hWnd;
    HWND _parent;
    LPSTR Caption;
    UINT _id;

    virtual void Focus();
    virtual void SetText( LPSTR );
    virtual LPSTR getText(  );
};

#include "T/app.h"
#include "T/TForm.h"
#include "T/TButton.h"
#include "T/TCheckBox.h"
#include "T/TEdit.h"
#include "T/TMemo.h"
#include "T/TEditPassword.h"
#include "T/TLabel.h"
#include "T/TListBox.h"
#include "T/TTimer.h"

void Message( LPSTR );
void Message( LPSTR, HWND );
void Message( LPSTR, TForm* );

class _WAPI_P
{
public:
    HINSTANCE _H_INST;
    LPSTR _C_LASSNAME;
    WNDCLASSEX _W_ND;
    void(*HotFunction)(int);

    TForm* _T_FORMS[];
    TButton* _T_BUTTONS[];
    TCheckBox* _T_CHECKBOX[];
    TEdit* _T_EDIT[];
    TEditPassword* _T_EDITP[];
    TLabel* _T_LABEL[];
    TMemo* _T_MEMO[];
    TListBox* _T_LISTBOX[];
    TTimer* _T_TIMER[];


    int __init( HINSTANCE, LPSTR );
};
_WAPI_P *wapi = new _WAPI_P;

#include "T_cpp/TForm_cpp.h"
#include "T_cpp/TButton.h"
#include "T_cpp/TEditPassword.h"
#include "T_cpp/TMemo.h"
#include "T_cpp/TEdit.h"
#include "T_cpp/TCheckBox.h"
#include "T_cpp/TTimer.h"
#include "T_cpp/TListBox.h"
#include "T_cpp/TLabel.h"
#include "T_cpp/app.h"

void _W_API_Event_Listener( WPARAM, LPARAM );
#include "wapi_core_cpp.h"
