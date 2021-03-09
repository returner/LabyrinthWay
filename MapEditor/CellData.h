#if !defined(AFX_CELLDATA_H__D48B694F_A582_492E_B0B3_989944BC6A83__INCLUDED_)
#define AFX_CELLDATA_H__D48B694F_A582_492E_B0B3_989944BC6A83__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CellData.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCellData window

class CCellData : public CWnd
{
// Construction
public:
	CCellData();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCellData)
	//}}AFX_VIRTUAL

// Implementation
public:
	CString GetAtt(int nFlags);
	BOOL bInputFlag;
	void SetAttributes(BOOL bSetFlags,BOOL bDataFlag, CString strHeight, CString strSlope, CString strGround, CString DX, CString DY);
	CString GetAtt();
	void SetAttributes(BOOL bFlags, CString strHeight, CString strSlope, CString strGround, CString DX, CString DY);
	virtual ~CCellData();
	// Generated message map functions
protected:
	//{{AFX_MSG(CCellData)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL bDataFlag;
	CString Height;
	CString Slope;
	CString Ground;
	CString DirectionX;
	CString DirectionY;

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CELLDATA_H__D48B694F_A582_492E_B0B3_989944BC6A83__INCLUDED_)
