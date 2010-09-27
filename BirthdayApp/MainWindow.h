#include <windows.h>
#include <io.h>
#include <commctrl.h>
#include "UIWindow.h"
#include "UIHandler.h"
#include "ControlCreator.h"
#include "UIPicButton.h"
#include "UIFadingPic.h"
#include "UIScrollText.h"
#include "UIBanner.h"
#include "Diagnostics.h"
#include "UILabel.h"
#include "MenuHandler.h"
#include "Stack.h"
#include <vfw.h>

#define STARTTIMER		1034
#define TEXTTIMER		1035

class MainWindow : public UIWindow
{
	public:
		MainWindow ();
		~MainWindow ();
		
		void Initialise (HWND hWnd);
		void SetDiagnostics (Diagnostics *pdiag);
		
		static DWORD WINAPI SlideShowProc (PVOID pParam);		
		void StartSlideShow ();

		void GetPathOnly (char *szInpath, char *szOutpath);

		void SetSlideProperties (UIFadingPic *pic, int num);
		void SetSlideNumber (UIFadingPic *pic, int num);
		void FadeSlide (bool extendedfade, int num);

		UIFadingPic m_pic1;
		UIFadingPic m_pic2;
		UIFadingPic m_pic3;
		UIFadingPic m_pic4;
		UIFadingPic m_pic5;
		UIFadingPic m_pic6;
		UIFadingPic m_pic7;
		UIFadingPic m_pic8;
		UIFadingPic m_pic9;
		UIFadingPic m_pic10;
		UIFadingPic m_pic11;
		UIFadingPic m_pic12;
		UIFadingPic m_pic13;
		UIFadingPic m_pic14;
		UIFadingPic m_pic15;
		UIFadingPic m_pic16;
		UIFadingPic m_pic17;
		UIFadingPic m_pic18;
		UIFadingPic m_pic19;
		UIFadingPic m_pic20;
		UIFadingPic m_pic21;

		UIScrollText m_text;
	private:
		// Private Member Variables & objects
		
		// The UI Handler required for multiple handling of custom controls.
		UIHandler m_uihandler;

		// The Control Creater required for fast creation of controls
		ControlCreator m_ccontrols;
		
		//A test stack
		Stack m_stack;

		// Global hwnd
		HWND m_hwnd;		

		HWND m_Video;

		// The header bitmap image
		UIBanner m_header;

		// The main menu class
		MenuHandler m_mainmenu;

		// Fading Pics
		HANDLE m_hShowthread;

		// Pointer to the global diagnostics window
		Diagnostics *m_pdiag;

		int m_icurrentslide;

		// Temporary input output buffers
		//MemoryBuffer m_inBuffer;
		//MemoryBuffer m_outBuffer;

		// event notification from base class
		void OnCreate (HWND hWnd);
		void OnNotify (HWND hWnd, WPARAM wParam, LPARAM lParam);
		void OnCommand (HWND hWnd, WPARAM wParam, LPARAM lParam);
		void OnUICommand (HWND hWnd, WPARAM wParam, LPARAM lParam);		
		void OnPaint (HWND hWnd);
		void OnTimer (WPARAM wParam);
		void OnMouseMove (HWND hWnd, int mouseXPos, int mouseYPos);
		void OnLButtonDown (HWND hWnd);
		void OnLButtonDblClick (HWND hWnd, WPARAM wParam, LPARAM lParam);				
		void OnCryptEvent (HWND hWnd, WPARAM wParam, LPARAM lParam);
		void OnLButtonUp (HWND hWnd);
};
