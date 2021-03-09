#include "stdafx.h"
#include "LabyrinthWay.h"
#include "CColor.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CColor::CColor()
{
	red = 0;
	green = 0;
	blue = 0;
}

CColor::CColor(const CColor& pColor)
{
	red = pColor.red;
	green = pColor.green;
	blue = pColor.blue;
}


CColor::~CColor()
{
}


