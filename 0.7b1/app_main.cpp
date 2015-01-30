#define WAPI_COMMCTRL
#define wAPI_HREDRAW 1
#define wAPI_VREDRAW 1
#include "resource.h"
#include "wapi.h"

TForm* form1;
TEdit *edit_login, *edit_password;

void DrawGR( TCanvas* self )
{
    self->Begin( form1 );

    self->BKColor = RGB(77, 113, 152);
    self->Rect(0, 0, 640, 480);
    self->BKColor = RGB( 57, 87, 120 );
    self->BrushColor = RGB( 255, 255, 255 );
    self->Rect( 220, 230, 220+120, 230+22 );
    self->TextAlign = TA_CENTER;
    self->TextOut(282, 233, _l"Sign IN!");
    self->End();

    form1->Redraw();

}

int WinMain(HINSTANCE hI, HINSTANCE, LPSTR, int)
{
    wapi_Init( hI, _l"Test application with graphics", TResource::GetIcon(hI, MY_ICON) );

    form1 = new TForm( _l"Main form", W_NORMAL  );

    edit_password = new TEdit( form1, _l"Password...", 220, 200 );
    edit_login = new TEdit( form1, _l"Login...", 220, 180 );
    canvas->onCanvas = DrawGR;

    form1->Show();

    wapi_MainLoop();


    return 0;

}
