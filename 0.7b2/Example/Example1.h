#define WAPI_COMMCTRL
#include "resource.h"
#include "wapi.h"

TForm* form1;
TButton* button1;

int WinMain(HINSTANCE hI, HINSTANCE, LPSTR, int)
{
    wapi_Init( hI, _l"Font!", TResource::GetIcon(hI, MY_ICON) );

    form1 = new TForm( _l"Main form", W_NORMAL  );
    button1 = new TButton( form1, _l"Font Test" );
    button1->SetFont(_l"Segoe UI");

    form1->SetStyle( W_NORMAL );

    form1->Show();

    wapi_MainLoop();


    return 0;
