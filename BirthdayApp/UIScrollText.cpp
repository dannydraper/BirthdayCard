#include "UIScrollText.h"

UIScrollText::UIScrollText ()
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
	m_scrollpos = 0;

	ZeroMemory (m_szText, 32768);

	//strcpy_s (m_szText, 32768, "Hello");
	

	//strcpy_s (m_szText, 32768, "The first use of the word computer was recorded in 1613, referring to a person who carried out calculations, or computations, and the word continued to be used in that sense until the middle of the 20th century. From the end of the 19th century onwards though, the word began to take on its more familiar meaning, describing a machine that carries out computations.[3]");

	//strcat_s (m_szText, 32768, "The history of the modern computer begins with two separate technologies—automated calculation and programmability—but no single device can be identified as the earliest computer, partly because of the inconsistent application of that term. Examples of early mechanical calculating devices include the abacus, the slide rule and arguably the astrolabe and the Antikythera mechanism (which dates from about 150–100 BC). Hero of Alexandria (c. 10–70 AD) built a mechanical theater which performed a play lasting 10 minutes and was operated by a complex system of ropes and drums that might be considered to be a means of deciding which parts of the mechanism performed which actions and when.[4] This is the essence of programmability.");

	strcat_s (m_szText, 32768, "Well this is it dood! Say goodbye to boyhood and welcome to manhood! Now I know you have a fascination for pink so you might notice the slight pinkish tint I've given the picture you're staring at above. My original intention was to spray paint your car bright pink, but your neighbours kept screaming at me when I came round with a spray truck - Damn it's been frikkin ages since I've written an app to do something quite like this on the PC! - The last time we did this was on our Amiga's ages ago passing disks each week whilst not getting noticed by our science teacher who would scream at us for trying to set our exercise books on fire (nothing wrong with that!). Now on the disk you'll find lots of goodies from Music to Video and maybe some software that I've snuck on there. The amount of stuff on the disk all depends on when this melatonin and camomile combination kick in which will send me into the land of unconsciousness - hopefully you'll find some good stuff on there, or at the very least you have 320GB of extra storage space - nobody can have enough storage! I'm sure you reckognised the movie soundtrack instantly - good old Transformers eh, now the trance track you should be hearing is called Trance around the World and was mixed by my Artificial Neural network - Nah it was mixed by some guys in Germany - and the Artificial Neural network I have is used for taking over world which will happen soon as soon as I've ironed out some bugs. Just incase you're wondering this app was written using C++ and the Win32 API - it needed to be done that way so it would run straight off the disk without needing installation. I wish the text would scroll smoother although I guess that's what you get for not using DirectX - Well I'll sign off my ramblings now and continue on my algorithm to simulate awareness! Enjoy d00d!..............P.S. I keep my iPhone at a safe distance from me now after reading a BBC News article about exploding iPhones....................What else....oh yeah - Thunder is actually caused by lightening which is kinda like the same thing as throwing a large stone into a small pond......");

	//strcat_s (m_szText, 32768, "The castle clock, an astronomical clock invented by Al-Jazari in 1206, is considered to be the earliest programmable analog computer.[5] It displayed the zodiac, the solar and lunar orbits, a crescent moon-shaped pointer travelling across a gateway causing automatic doors to open every hour,[6][7] and five robotic musicians who played music when struck by levers operated by a camshaft attached to a water wheel. The length of day and night could be re-programmed to compensate for the changing lengths of day and night throughout the year.[5]");

	//strcat_s (m_szText, 32768, "The Renaissance saw a re-invigoration of European mathematics and engineering. Wilhelm Schickard's 1623 device was the first of a number of mechanical calculators constructed by European engineers, but none fit the modern definition of a computer, because they could not be programmed.");

	//strcat_s (m_szText, 32768, "In 1801, Joseph Marie Jacquard made an improvement to the textile loom by introducing a series of punched paper cards as a template which allowed his loom to weave intricate patterns automatically. The resulting Jacquard loom was an important step in the development of computers because the use of punched cards to define woven patterns can be viewed as an early, albeit limited, form of programmability.");

	//strcat_s (m_szText, 32768, "It was the fusion of automatic calculation with programmability that produced the first recognizable computers. In 1837, Charles Babbage was the first to conceptualize and design a fully programmable mechanical computer, his analytical engine.[8] Limited finances and Babbage's inability to resist tinkering with the design meant that the device was never completed.");

	//strcat_s (m_szText, 32768, "In the late 1880s, Herman Hollerith invented the recording of data on a machine readable medium. Prior uses of machine readable media, above, had been for control, not data. After some initial trials with paper tape, he settled on punched cards ...[9] To process these punched cards he invented the tabulator, and the keypunch machines. These three inventions were the foundation of the modern information processing industry. Large-scale automated data processing of punched cards was performed for the 1890 United States Census by Hollerith's company, which later became the core of IBM. By the end of the 19th century a number of technologies that would later prove useful in the realization of practical computers had begun to appear: the punched card, Boolean algebra, the vacuum tube (thermionic valve) and the teleprinter.");

	//strcat_s (m_szText, 32768, "During the first half of the 20th century, many scientific computing needs were met by increasingly sophisticated analog computers, which used a direct mechanical or electrical model of the problem as a basis for computation. However, these were not programmable and generally lacked the versatility and accuracy of modern digital computers.");

	//strcat_s (m_szText, 32768, "Alan Turing is widely regarded to be the father of modern computer science. In 1936 Turing provided an influential formalisation of the concept of the algorithm and computation with the Turing machine. Of his role in the modern computer, Time Magazine in naming Turing one of the 100 most influential people of the 20th century, states: The fact remains that everyone who taps at a keyboard, opening a spreadsheet or a word-processing program, is working on an incarnation of a Turing machine. [10]");

	//strcat_s (m_szText, 32768, "George Stibitz is internationally recognized as a father of the modern digital computer. While working at Bell Labs in November 1937, Stibitz invented and built a relay-based calculator he dubbed the Model K (for kitchen table, on which he had assembled it), which was the first to use binary circuits to perform an arithmetic operation. Later models added greater sophistication including complex arithmetic and programmability.");
	
}

UIScrollText::~UIScrollText ()
{
}

unsigned long UIScrollText::GetSize () {
	return sizeof (UIScrollText);
}

void UIScrollText::SetVisible (bool bVisible)
{
	m_bVisible = bVisible;
	InvalidateControl (false);
}

void UIScrollText::SetBitmapResources (unsigned int wResbase)
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

void UIScrollText::SetBitmapProperties (int c1xStart, int c1xWidth, int c2xStart, int c2xWidth, int c3xStart, int c3xWidth, int Height, int Width)
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

void UIScrollText::SetBitmapProperties (int Width, int Height)
{
	g_iBitmapwidth = Width;
	g_iBitmapheight = Height;
}

void UIScrollText::SetToggleMode (bool bUsetoggle)
{
	m_bTogglemode = bUsetoggle;
}

void UIScrollText::SetRectHighlight (bool bUseRectHighlight)
{
	m_bUseRectHighlight = bUseRectHighlight;
}

void UIScrollText::SetTransparencyKey (COLORREF clTransparentKey)
{
	m_clTranskey = clTransparentKey;
	// Set our member variable of using transparent to true. This causes the blitting methods to use the
	// TransparentBlt Win32 API call instead of the standard BitBlt call.
	m_bUsingTransparency = true;
}

void UIScrollText::Blit (HDC hdc, int xPos, int yPos, int Width, int Height, HDC srcDC, int srcxPos, int srcyPos, int srcWidth, int srcHeight, int Method, BLENDFUNCTION blendop)
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

void UIScrollText::DrawButton (HDC hdc, HDC hdcMem, int Method, BLENDFUNCTION blendop)
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

void UIScrollText::DrawClippedButton (HDC hdc, HDC hdcMem, int Method, BLENDFUNCTION blendop)
{
	if (g_bSinglebitmap == true) {
		Blit (hdc, g_xPos+1, g_yPos+1, g_iBitmapwidth-2, g_iBitmapheight-2, hdcMem, 1, 1, g_iBitmapwidth, g_iBitmapheight, Method, blendop);
	}
}

void UIScrollText::DrawRect (HDC hdc)
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

void UIScrollText::Paint (HDC hdc)
{
	if (m_bVisible == false) {
		return;
	}

	PaintText (hdc, 1000+m_scrollpos, g_yPos, "Century Gothic", 170, m_szText, RGB(255, 255, 255));
}

void UIScrollText::Scroll ()
{
	m_scrollpos-=1;
	InvalidateRect (g_hWnd, &g_Rect, false);	
}

void UIScrollText::NotifyTimer (unsigned int wParam)
{	
	if (wParam == TMR_SCROLL+g_controlID) {
		Scroll ();
	}


}

void UIScrollText::LockHighlight (bool bLock)
{
	g_bHighlightlocked = bLock;
}

void UIScrollText::StartScroll ()
{

	if (g_bTimeractive == false) {
		g_bTimeractive = true;
		SetTimer (g_hWnd, TMR_SCROLL+g_controlID, 1, NULL);
		return;
	}
	if (g_bTimeractive == true) {
		KillTimer (g_hWnd, TMR_SCROLL+g_controlID);
		SetTimer (g_hWnd, TMR_SCROLL+g_controlID, 1, NULL);
		return;
	}
}



void UIScrollText::StopScroll ()
{
	g_bTimeractive = false;
	KillTimer (g_hWnd, TMR_SCROLL+g_controlID);
	
}

void UIScrollText::NotifyMouseMove (int iXPos, int iYPos)
{
	g_mouseXPos = iXPos;
	g_mouseYPos = iYPos;
	
}

void UIScrollText::ReleaseToggle ()
{
	g_bMouseover = false;
	g_mouseDown = false;
	InvalidateRect (g_hWnd, &g_Rect, false);
}

void UIScrollText::NotifyMouseDown ()
{

}

void UIScrollText::NotifyMouseUp ()
{

}