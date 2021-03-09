// Position.cpp : implementation file
//

#include "stdafx.h"
#include "mapeditor.h"
#include "Position.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPosition

CPosition::CPosition()
{
	BallAPosX = _T("0");
	BallAPosY = _T("0");
	BallBPosX = _T("0");
	BallBPosY = _T("0");
	HallPosX = _T("0");
	HallPosY = _T("0");
}

CPosition::~CPosition()
{
}


BEGIN_MESSAGE_MAP(CPosition, CWnd)
	//{{AFX_MSG_MAP(CPosition)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CPosition message handlers

void CPosition::SetPositions(BOOL bFlags, CString BallAX, CString BallAY, CString BallBX, CString BallBY, CString HallX, CString HallY)
{
	BallAPosX = BallAX;
	BallAPosY = BallAY;
	BallBPosX = BallBX;
	BallBPosY = BallBY;
	HallPosX = HallX;
	HallPosY = HallY;
}

CString CPosition::GetPositions(int nFlags)
{
	if (nFlags == 1 ) return BallAPosX;
	if (nFlags == 2 ) return BallAPosY;
	if (nFlags == 3 ) return BallBPosX;
	if (nFlags == 4 ) return BallBPosY;
	if (nFlags == 5 ) return HallPosX;
	if (nFlags == 6 ) return HallPosY;
	if (nFlags == 7 )
	{
		CString all;
		all = BallAPosX + ";" + BallAPosY + "\n" +
			BallBPosX + ";" + BallBPosY + "\n" +
			HallPosX + ";" + HallPosY + "\n";
		return all;
	}

	return "it's just error Message";
}
