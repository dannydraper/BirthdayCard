// This work is dedicated to the Lord our God. King of Heaven, Lord of Heaven's Armies.

#include "MainWindow.h"


MainWindow::MainWindow ()
{
	m_Video = NULL;
}

MainWindow::~MainWindow ()
{
}

void MainWindow::Initialise (HWND hWnd)
{	
	SetParentHWND (hWnd);
	//m_hwnd = hWnd;
	SetBgColor (RGB (200, 200, 200));
	SetCaption (TEXT ("Exchange Disk 2009"));
	SetWindowStyle (FS_STYLESTANDARD);
	CreateAppWindow ("CRYPTWindowClass", 70, 0, 1000, 760, false);	
	m_uihandler.SetWindowProperties (0, 0, 1000, 760, RGB (0, 0, 0));
	SetWindowPosition (FS_CENTER);
	Show ();
}

void MainWindow::SetDiagnostics (Diagnostics *pdiag)
{
	m_pdiag = pdiag;
}

void MainWindow::OnCreate (HWND hWnd)
{
	m_hwnd = hWnd;

	//m_header.SetBitmapResources (IDB_HEADER);
	//m_header.SetBitmapProperties (0, 0, 238, 64);
	//m_header.SetProperties (hWnd, CID_HEADER, 3, 3, 238, 64);
	//m_uihandler.AddDirectControl (&m_header);
	
	//m_mainmenu.CreateMainMenu (hWnd);

	//m_connectpanel.Hide ();
	m_icurrentslide = 1;

	
	SetSlideProperties (&m_pic1, 1);

	/*
	SetSlideProperties (&m_pic2, 2);
	SetSlideProperties (&m_pic3, 3);
	SetSlideProperties (&m_pic4, 4);
	SetSlideProperties (&m_pic5, 5);
	SetSlideProperties (&m_pic6, 6);
	SetSlideProperties (&m_pic7, 7);
	SetSlideProperties (&m_pic8, 8);
	SetSlideProperties (&m_pic9, 9);
	SetSlideProperties (&m_pic10, 10);
	SetSlideProperties (&m_pic11, 11);
	SetSlideProperties (&m_pic12, 12);
	SetSlideProperties (&m_pic13, 13);
	SetSlideProperties (&m_pic14, 14);
	SetSlideProperties (&m_pic15, 15);
	SetSlideProperties (&m_pic16, 16);
	SetSlideProperties (&m_pic17, 17);
	SetSlideProperties (&m_pic18, 18);
	SetSlideProperties (&m_pic19, 19);
	SetSlideProperties (&m_pic20, 20);
	SetSlideProperties (&m_pic21, 21);
	*/

	

	m_text.SetProperties (hWnd, CID_HEADER, 0, 690, 1000, 200);
	m_uihandler.AddControl (&m_text);	
	

	char szModuleFilename[SIZE_STRING];
	ZeroMemory (szModuleFilename, SIZE_STRING);

	GetModuleFileName(GetModuleHandle(NULL), szModuleFilename, SIZE_STRING);

	char szModulePath[SIZE_STRING];
	GetPathOnly(szModuleFilename, szModulePath);
	

	strcat_s (szModulePath, SIZE_STRING, "Music.mp3");

	m_Video = MCIWndCreate(hWnd, GetModuleHandle(NULL), WS_CHILD | MCIWNDF_NOMENU, szModulePath);


	MCIWndPlay(m_Video);


	SetTimer (m_hwnd, STARTTIMER, 4000, NULL);
}

void MainWindow::SetSlideProperties (UIFadingPic *pic, int num)
{
	SetSlideNumber (pic, num);
	pic->SetBitmapProperties (800, 114);
	pic->SetProperties (m_hwnd, CID_SLIDE1, 100, 300, 800, 114);
	m_uihandler.AddControl (pic);
}

void MainWindow::SetSlideNumber (UIFadingPic *pic, int num)
{
	if (num == 1) {pic->SetBitmapResources (IDB_SLIDE1);}
	if (num == 2) {pic->SetBitmapResources (IDB_SLIDE2);}
	if (num == 3) {pic->SetBitmapResources (IDB_SLIDE3);}
	if (num == 4) {pic->SetBitmapResources (IDB_SLIDE4);}
	if (num == 5) {pic->SetBitmapResources (IDB_SLIDE5);}
	if (num == 6) {pic->SetBitmapResources (IDB_SLIDE6);}
	if (num == 7) {pic->SetBitmapResources (IDB_SLIDE7);}
	if (num == 8) {pic->SetBitmapResources (IDB_SLIDE8);}
	if (num == 9) {pic->SetBitmapResources (IDB_SLIDE9);}
	if (num == 10) {pic->SetBitmapResources (IDB_SLIDE10);}
	if (num == 11) {pic->SetBitmapResources (IDB_SLIDE11);}
	if (num == 12) {pic->SetBitmapResources (IDB_SLIDE12);}
	if (num == 13) {pic->SetBitmapResources (IDB_SLIDE13);}
	if (num == 14) {pic->SetBitmapResources (IDB_SLIDE14);}
	if (num == 15) {pic->SetBitmapResources (IDB_SLIDE15);}
	if (num == 16) {pic->SetBitmapResources (IDB_SLIDE16);}
	if (num == 17) {pic->SetBitmapResources (IDB_SLIDE17);}
	if (num == 18) {pic->SetBitmapResources (IDB_SLIDE18);}
	if (num == 19) {pic->SetBitmapResources (IDB_SLIDE19);}
	if (num == 20) {pic->SetBitmapResources (IDB_SLIDE20);}
	if (num == 21) {pic->SetBitmapResources (IDB_SLIDE21);}
	if (num == 22) {pic->SetBitmapResources (IDB_SLIDE22);}
}

void MainWindow::FadeSlide (bool extendedfade, int num)
{
	//if (num == 1) {		
	SetSlideNumber(&m_pic1, num);	
	m_pic1.FadeIn(extendedfade);
	//}
	//if (num == 2) {
		//m_uihandler.AddControl (&m_pic2);
		//m_pic2.FadeIn();
	//}
	/*
	if (num == 3) {m_uihandler.AddControl (&m_pic3);m_pic3.FadeIn();}
	if (num == 4) {m_uihandler.AddControl (&m_pic4);m_pic4.FadeIn();}
	if (num == 5) {m_uihandler.AddControl (&m_pic5);m_pic5.FadeIn();}
	if (num == 6) {m_uihandler.AddControl (&m_pic6);m_pic6.FadeIn();}
	if (num == 7) {m_uihandler.AddControl (&m_pic7);m_pic7.FadeIn();}
	if (num == 8) {m_uihandler.AddControl (&m_pic8);m_pic8.FadeIn();}
	if (num == 9) {m_uihandler.AddControl (&m_pic9);m_pic9.FadeIn();}
	if (num == 10) {m_uihandler.AddControl (&m_pic10);m_pic10.FadeIn();}
	if (num == 11) {m_uihandler.AddControl (&m_pic11);m_pic11.FadeIn();}
	if (num == 12) {m_uihandler.AddControl (&m_pic12);m_pic12.FadeIn();}
	if (num == 13) {m_uihandler.AddControl (&m_pic13);{m_pic13.FadeIn();}
	if (num == 14) {m_uihandler.AddControl (&m_pic14);m_pic14.FadeIn();}
	if (num == 15) {m_uihandler.AddControl (&m_pic15);m_pic15.FadeIn();}
	if (num == 16) {m_uihandler.AddControl (&m_pic16);m_pic16.FadeIn();}
	if (num == 17) {m_uihandler.AddControl (&m_pic17);m_pic17.FadeIn();}
	if (num == 18) {m_uihandler.AddControl (&m_pic18);m_pic18.FadeIn();}
	if (num == 19) {m_uihandler.AddControl (&m_pic19);m_pic19.FadeIn();}
	if (num == 20) {m_uihandler.AddControl (&m_pic20);m_pic20.FadeIn();}
	if (num == 21) {m_uihandler.AddControl (&m_pic21);m_pic21.FadeIn();}
	*/
}

void MainWindow::GetPathOnly (char *szInpath, char *szOutpath)
{
	char szCurchar[SIZE_NAME];
	int seploc = 0;

	for (int c=strlen(szInpath);c>0;c--) {
		
		ZeroMemory (szCurchar, SIZE_NAME);
		strncpy_s (szCurchar, SIZE_NAME, szInpath+c, 1);

		if (strcmp (szCurchar, "\\") == 0) {
			seploc = c+1;
			break;
		}
	}

	strncpy_s (szOutpath, SIZE_STRING, szInpath, seploc);
}

DWORD WINAPI MainWindow::SlideShowProc (PVOID pParam)
{
	// The worker thread in which the pst scan takes place
	// once complete, a message is posted back to the main window to inform it
	// that the scan is complete.

	MainWindow *pmainwnd = (MainWindow *) pParam;

	//pmainwnd->ListPSTFiles ();
	pmainwnd->m_pic1.FadeIn(false);

	Sleep(1000);

	pmainwnd->m_pic1.FadeOut();

	return 0;
}

void MainWindow::StartSlideShow ()
{	
	DWORD dwThreadID;
	m_hShowthread = CreateThread (NULL, 0, SlideShowProc, (MainWindow *) this, 0, &dwThreadID);
}



void MainWindow::OnCryptEvent (HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	// Notify the communications object of an encryption event message.
	
}

void MainWindow::OnNotify (HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	
}

void MainWindow::OnCommand (HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	
}

void MainWindow::OnUICommand (HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	int controlID = wParam;

	/*
	if (controlID == CID_SLIDE1+m_icurrentslide) {
		if (lParam == WM_FADEDONE) {
					//MessageBox (NULL, "Done", "Done", MB_OK);
					m_icurrentslide++;
					FadeSlide(m_icurrentslide);
		}
	}
*/
	
	
	switch (controlID) {
		case CID_SLIDE1:
			{
				if (lParam == WM_FADEDONE) {
					//MessageBox (NULL, "Done", "Done", MB_OK);
					if (m_icurrentslide < 22) {
						m_icurrentslide++;
						
						if (m_icurrentslide == 21) {
							FadeSlide(true, m_icurrentslide);

						} else {
							if (m_icurrentslide == 22) {
								m_pic1.SetBitmapProperties (994, 637);
								m_pic1.SetProperties (m_hwnd, CID_SLIDE1, 0, 0, 994, 637);

								m_pic1.m_busefadeout = false;
								FadeSlide(false, m_icurrentslide);
								SetTimer(m_hwnd, TEXTTIMER, 3000, NULL);
							} else {
								FadeSlide(false, m_icurrentslide);
							}							
						}
					} else {
						
					}
					
				}
			}
			break;
	}
	
}

void MainWindow::OnTimer (WPARAM wParam)
{
	m_uihandler.NotifyTimer (wParam);

	if (wParam == STARTTIMER) {
		KillTimer (m_hwnd, STARTTIMER);
		m_pic1.FadeIn(false);
	}

	if (wParam == TEXTTIMER) {
		KillTimer (m_hwnd, TEXTTIMER);
		m_text.StartScroll ();
	}
}

void MainWindow::OnPaint (HWND hWnd)
{
	m_uihandler.PaintControls (hWnd);	
}

void MainWindow::OnMouseMove (HWND hWnd, int mouseXPos, int mouseYPos)
{		
	m_uihandler.NotifyMouseMove (mouseXPos, mouseYPos);
}

void MainWindow::OnLButtonDown (HWND hWnd)
{
	m_uihandler.NotifyMouseDown ();
}

void MainWindow::OnLButtonDblClick (HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	m_pdiag->OutputText ("Window Double Clicked.");
}

void MainWindow::OnLButtonUp (HWND hWnd)
{
	m_uihandler.NotifyMouseUp ();
}
