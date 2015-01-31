
<h3>Windows API</h3>
	wAPI+( Windows API+ ) it is lib for creating win32 app. 
	wAPI is openSource project.
	wAPI has child-visible-classes: TButton, TEdit, TEditPassword, TMemo and etc.
	wAPI has child-system-classes: TResource, app, TCanvas.
	wAPI is easy in use.
	
<h3>Using:</h3>
	Include all files( From dir T/, T_cpp/ and wapi.h, wapi_core.h, wapi_core_cpp.h ).
	In main cpp file include wapi.h( #include "wapi.h" )
	In main function( WinMain ) use 
	
	
		wapi_init( 
			HINSTANCE : HINSTANCE App
			LPSTR : Class Name of application
			HICON = NULL : Icon. Can be loaded with help TResource::GetIcon( HINSTANCE, int )
		);
	After it u can create u`r first form:
	
	
	
		TForm* form = new TForm( 
			LPSTR = Class Name of Application : Caption
			int : Style of window. For normal window use W_NORMAL or WS_OVERLAPPEDWINDOW
			int = 0 : x
			int = 0: y
			int = 640: w
			int = 480: h
		);
	How to create component?
	wAPI has child-visible-classes: TButton, TEdit, TEditPassword, TMemo and etc.
	For example:
	TButton* button = new TButton(
		TForm : form-parent
		LPSTR : caption/text
		int = 0 : x
		int = 0 : y
		int = 120 : w
		int = 32 : h
	);
<h2>Other:</h2>
	All child-visible-classes is a child by TObject and has method:
	
	    *void SetText( 
	    	LPSTR : New caption 
	    );
	    *void SetPos( 
	    	int = -1: x 
	    	int = -1: y
	    	int = -1: w
	    	int = -1: h
	    );
	
	    *LPSTR getText();
	    *HWND GetParent();
	
	    *void Show();
	    *void Hide();
	    *void Focus();
	    *void Redraw();
	    *void ToUp();
	    *void ToDown();
	    *void Free();
	    *void SetFont( 
	    	LPSTR : Font Name 
	    );
	    *void SetStyle( 
	    	LONG : New style of Widow  
	    );
