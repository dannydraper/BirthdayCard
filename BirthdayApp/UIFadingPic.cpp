#include "UIFadingPic.h"

UIFadingPic::UIFadingPic ()
{
	// Blend settings
	g_blendop.BlendOp = AC_SRC_OVER;
	g_blendop.BlendFlags = 0;
	g_blendop.AlphaFormat = NULL;

	g_bTimeractive = false;
	g_bMouseover = false;
	g_bHighlighted = false;
	g_bDepressed = false;
	g_bHighlightlocked = false;
	
	// Default transparency settings
	m_clTranskey = RGB (255, 0, 255);
	m_bUsingTransparency = false;
	m_bVisible = true;
	m_bTogglemode = false;
	m_bUseRectHighlight = false;
	m_bfadein = true;
	m_busefadeout = true;
}

UIFadingPic::~UIFadingPic ()
{
}

unsigned long UIFadingPic::GetSize () {
	return sizeof (UIFadingPic);
}

void UIFadingPic::SetVisible (bool bVisible)
{
	m_bVisible = bVisible;
	InvalidateControl (false);
}

void UIFadingPic::SetBitmapResources (unsigned int wResbase)
{
	// Load the bitmap resources. Three resources are required, one for the base button image, one for the
	// highlighted button image, and one for the mouse down button image.
	
	g_hbmBase = LoadBitmapResource (wResbase);

	// The single bitmap flag tells this class how to draw the button bitmap. A single image is where the entire button
	// image is provided in it's entirity within the provided resources. Therefore the width and height of the button
	// is restricted to that in the resource. If singlebitmap is false then a 3 column tiled bitmap is assumed where the
	// columns 1 and 3 of the provided bitmap are the first and last segments and column 2 is the middle segment which
	// is repeated as many times as the requested width.
	g_bSinglebitmap = true;
	g_blendop.SourceConstantAlpha = 0;
}

void UIFadingPic::SetBitmapProperties (int c1xStart, int c1xWidth, int c2xStart, int c2xWidth, int c3xStart, int c3xWidth, int Height, int Width)
{
	g_c1xStart = c1xStart;
	g_c1xWidth = c1xWidth;
	g_c2xStart = c2xStart;
	g_c2xWidth = c2xWidth;
	g_c3xStart = c3xStart;
	g_c3xWidth = c3xWidth;
	g_iBitmapheight = Height;
	g_iBitmapwidth = Width;
}

void UIFadingPic::SetBitmapProperties (int Width, int Height)
{
	g_iBitmapwidth = Width;
	g_iBitmapheight = Height;
}

void UIFadingPic::SetToggleMode (bool bUsetoggle)
{
	m_bTogglemode = bUsetoggle;
}

void UIFadingPic::SetRectHighlight (bool bUseRectHighlight)
{
	m_bUseRectHighlight = bUseRectHighlight;
}

void UIFadingPic::SetTransparencyKey (COLORREF clTransparentKey)
{
	m_clTranskey = clTransparentKey;
	// Set our member variable of using transparent to true. This causes the blitting methods to use the
	// TransparentBlt Win32 API call instead of the standard BitBlt call.
	m_bUsingTransparency = true;
}

void UIFadingPic::Blit (HDC hdc, int xPos, int yPos, int Width, int Height, HDC srcDC, int srcxPos, int srcyPos, int srcWidth, int srcHeight, int Method, BLENDFUNCTION blendop)
{
	if (Method == BLITMETHOD_STANDARD) {
		if (m_bUsingTransparency == true) {
			//TransparentBlt (hdcTemp, 0, 0, width, height, hdcMem, srcxpos, srcypos, srcwidth, srcheight, transColor);
			TransparentBlt (hdc, xPos, yPos, Width, Height, srcDC, srcxPos, srcyPos, Width, Height, m_clTranskey);	
		} else {
			BitBlt (hdc, xPos, yPos, Width, Height, srcDC, srcxPos, srcyPos, SRCCOPY);
		}
	}
	if (Method == BLITMETHOD_ALPHABLEND) {
		AlphaBlend (hdc, xPos, yPos, Width, Height, srcDC, srcxPos, srcyPos, srcWidth, srcHeight, blendop);
	}
}

void UIFadingPic::DrawButton (HDC hdc, HDC hdcMem, int Method, BLENDFUNCTION blendop)
{
	if (g_bSinglebitmap == true) {
		Blit (hdc, g_xPos, g_yPos, g_iBitmapwidth, g_iBitmapheight, hdcMem, 0, 0, g_iBitmapwidth, g_iBitmapheight, Method, blendop);
	} else {
		for (int i=0;i<g_Width/g_iBitmapwidth;i++) {
			if (i==0) {
				Blit (hdc, g_xPos+(i*(g_c1xWidth)), g_yPos, g_c1xWidth, g_iBitmapheight, hdcMem, g_c1xStart, 0, g_c1xWidth, g_iBitmapheight, Method, blendop);
			}

			if (i>0 && i<(g_Width/g_iBitmapwidth)-1) {
				Blit (hdc, g_xPos+(i*(g_c2xWidth)), g_yPos, g_c2xWidth, g_iBitmapheight, hdcMem, g_c2xStart, 0, g_c2xWidth, g_iBitmapheight, Method, blendop);
			}

			if (i==(g_Width/g_iBitmapwidth)-1) {
				Blit (hdc, g_xPos+(i*(g_c3xWidth)), g_yPos, g_c3xWidth, g_iBitmapheight, hdcMem, g_c3xStart, 0, g_c3xWidth, g_iBitmapheight, Method, blendop);
				g_Rect.right = g_xPos+(i*(g_c3xWidth))+g_c3xWidth;
			}
		}
	}
}

void UIFadingPic::DrawClippedButton (HDC hdc, HDC hdcMem, int Method, BLENDFUNCTION blendop)
{
	if (g_bSinglebitmap == true) {
		Blit (hdc, g_xPos+1, g_yPos+1, g_iBitmapwidth-2, g_iBitmapheight-2, hdcMem, 1, 1, g_iBitmapwidth, g_iBitmapheight, Method, blendop);
	}
}

void UIFadingPic::DrawRect (HDC hdc)
{
	HBRUSH myBrush = CreateSolidBrush (RGB (0, 100, 200));
	RECT controlRect;
	controlRect.left = g_xPos;
	controlRect.right = g_xPos+g_iBitmapwidth;
	controlRect.top = g_yPos;
	controlRect.bottom = g_yPos+g_iBitmapheight;
	
	FillRect (hdc, &controlRect, myBrush);

	DeleteObject (myBrush);
}

void UIFadingPic::Paint (HDC hdc)
{
	if (m_bVisible == false) {
		return;
	}

	// Paint the title to the screen
	BITMAP bm;
	HDC hdcMem = CreateCompatibleDC (hdc);
	HBITMAP hbmOld;

	int i = 0;
	int a = 0;

	hbmOld = (HBITMAP) SelectObject (hdcMem, g_hbmBase);	
	GetObject (g_hbmBase, sizeof (bm), &bm);
	
	DrawButton (hdc, hdcMem, BLITMETHOD_ALPHABLEND, g_blendop);		

	SelectObject (hdcMem, hbmOld);
	DeleteObject (hbmOld);
	DeleteDC (hdcMem);
}

void UIFadingPic::Fade ()
{
	if (m_bfadein == true) {
		g_iAlpha+=2;
		if (g_iAlpha > 255) {
			g_iAlpha=255;
			StopFade ();
			if (m_busefadeout == true) {
				if (m_bextendedfade == true) {
					SetTimer (g_hWnd, TMR_WAIT+g_controlID, 8000, NULL);
				} else {
					SetTimer (g_hWnd, TMR_WAIT+g_controlID, 2000, NULL);
				}
			}
			
		}
	} else {
		g_iAlpha-=2;
		if (g_iAlpha <= 0) {
			g_iAlpha=0;
			StopFade ();	
			PostMessage (g_hWnd, WM_UICOMMAND, (WPARAM) g_controlID, WM_FADEDONE);
		}
	}
	
	g_blendop.SourceConstantAlpha = g_iAlpha;
	InvalidateRect (g_hWnd, &g_Rect, false);	
}

void UIFadingPic::NotifyTimer (unsigned int wParam)
{	
	if (wParam == TMR_FADE+g_controlID) {
		Fade ();
	}	

	if (wParam == TMR_WAIT+g_controlID) {
		KillTimer (g_hWnd, TMR_WAIT+g_controlID);
		FadeOut();
	}
}

void UIFadingPic::LockHighlight (bool bLock)
{
	g_bHighlightlocked = bLock;
}

void UIFadingPic::FadeIn (bool extended)
{
	m_bextendedfade = extended;
	m_bfadein = true;
	g_iAlpha = 0;
	if (g_bTimeractive == false) {
		g_bTimeractive = true;
		SetTimer (g_hWnd, TMR_FADE+g_controlID, 3, NULL);
		return;
	}
	if (g_bTimeractive == true) {
		KillTimer (g_hWnd, TMR_FADE+g_controlID);
		SetTimer (g_hWnd, TMR_FADE+g_controlID, 3, NULL);
		return;
	}
}

void UIFadingPic::FadeOut ()
{
	m_bfadein = false;
	g_iAlpha = 255;
	if (g_bTimeractive == false) {
		g_bTimeractive = true;
		SetTimer (g_hWnd, TMR_FADE+g_controlID, 3, NULL);
		return;
	}
	if (g_bTimeractive == true) {
		KillTimer (g_hWnd, TMR_FADE+g_controlID);
		SetTimer (g_hWnd, TMR_FADE+g_controlID, 3, NULL);
		return;
	}
}

void UIFadingPic::StopFade ()
{
	g_bTimeractive = false;
	KillTimer (g_hWnd, TMR_FADE+g_controlID);
	
}

void UIFadingPic::NotifyMouseMove (int iXPos, int iYPos)
{
	g_mouseXPos = iXPos;
	g_mouseYPos = iYPos;
	
}

void UIFadingPic::ReleaseToggle ()
{
	g_bMouseover = false;
	g_mouseDown = false;
	InvalidateRect (g_hWnd, &g_Rect, false);
}

void UIFadingPic::NotifyMouseDown ()
{

}

void UIFadingPic::NotifyMouseUp ()
{

}