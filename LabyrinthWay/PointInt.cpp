// PointInt.cpp : implementation file
//

#include "stdafx.h"
#include "labyrinthway.h"
#include "PointInt.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPointInt

CPointInt::CPointInt()
{
}

CPointInt::~CPointInt()
{
}

CPointInt::CPointInt(const CPointInt & pPointInt)
{
	x = pPointInt.x;
	y = pPointInt.y;
}
