#if !defined(AFX_POINTINT_H__CBDBE9F6_BAFB_465A_8FE4_1DF50E6BF44E__INCLUDED_)
#define AFX_POINTINT_H__CBDBE9F6_BAFB_465A_8FE4_1DF50E6BF44E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PointInt.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPointInt
//
// 용도 : 두개의 int 값을 쓸때 사용함..
// 그이외에 알아서 쓸것..

class CPointInt 
{
// Constructor
public:
	CPointInt();
	// copy constructor
	CPointInt(const CPointInt & pPointInt);
	~CPointInt();

	int x;
	int y;
};

#endif // !defined(AFX_POINTINT_H__CBDBE9F6_BAFB_465A_8FE4_1DF50E6BF44E__INCLUDED_)
