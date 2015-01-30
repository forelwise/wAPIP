#include "wapi.h" 

void initApplication()
{
    TForm *form1 = new TForm((char*)"Hello, world"); //Create new form with caption "Hello, world"
    TButton *button1 = new TButton( form1, (char*)"Button 1" ); //Create new button on form1 with caption "Button 1"


    form1->Show(); //Show form1
    wapi_MainLoop();//Message loop
}

int WinMain( HINSTANCE hI, HINSTANCE, LPSTR, int )
{
    wapi_Init(hI, (char*)"ClassName");//Initialization wAPI+
    initApplication();//Call function for create components
    return 0;
}
