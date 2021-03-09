// CellData.cpp : implementation file
//

#include "stdafx.h"
#include "mapeditor.h"
#include "CellData.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCellData

CCellData::CCellData()
{
	Height = _T("");
	Slope = _T("");
	DirectionX = _T("");
	DirectionY = _T("");
	Ground = _T("");
	bInputFlag = FALSE;
	bDataFlag = FALSE;
}

CCellData::~CCellData()
{
}


BEGIN_MESSAGE_MAP(CCellData, CWnd)
	//{{AFX_MSG_MAP(CCellData)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CCellData message handlers

void CCellData::SetAttributes(BOOL bFlags, CString strHeight, CString strSlope, CString strGround, CString DX, CString DY)
{
	bInputFlag = bFlags;
	Height = strHeight;
	Slope = strSlope;
	Ground = strGround;
	DirectionX = DX;
	DirectionY = DY;
}


CString CCellData::GetAtt()
{
	CString ret;
//	ret = Height+";" + Slope + "," + Ground + "*" +DirectionX + "&" + DirectionY+"/";
	ret = Height+";" + Slope + "," + Ground + "*";

	return ret;
}

void CCellData::SetAttributes(BOOL bSetFlags, BOOL bDataFlag, CString strHeight, CString strSlope, CString strGround, CString DX, CString DY)
{
	bInputFlag = bSetFlags;
	Height = strHeight;
	Slope = strSlope;
	Ground = strGround;
	DirectionX = DX;
	DirectionY = DY;
}

CString CCellData::GetAtt(int nFlags)
{
	if (nFlags == 1 ) return Height;
	if (nFlags == 2 ) return Slope;
	if (nFlags == 3 ) return Ground;
	if (nFlags == 4 ) return DirectionX;
	if (nFlags == 5 ) return DirectionY;

	return "Error";
}
