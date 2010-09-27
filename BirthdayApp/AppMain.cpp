#include <windows.h>
#include "resource.h"
#include "UIWindow.h"
#include "MainWindow.h"
#include "Diagnostics.h"

////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// GLOBAL VARIABLES
////////////////////////////////////////////////////////////////////////////////////////

MainWindow g_windowmain;
Diagnostics g_windowdiag;

////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// FUNCTION PROTOTYPES
////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// IMPLEMENTATION
////////////////////////////////////////////////////////////////////////////////////////


int WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) 
{
	HWND hWnd = NULL;
	MSG msg;

	// Ensure that the common control DLL is loaded
	InitCommonControls ();

	MessageBox (NULL, "This application uses Audio. Please ensure your sound is turned on at a comfortable level before clicking Ok. Thank you.", "Information", MB_OK | MB_ICONINFORMATION);

	g_windowdiag.Initialise (hWnd);
	
	g_windowmain.SetDiagnostics (&g_windowdiag);
	g_windowmain.Initialise (hWnd);
	
	// Enter the message loop
	while (GetMessage (&msg, NULL, 0, 0))
	{
		TranslateMessage (&msg);
		DispatchMessage (&msg);
	}

	return 0;
}