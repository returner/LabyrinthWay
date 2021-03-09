#if !defined(AFX_POSITION_H__D46C0871_F1BA_4674_87D1_822509B80FCE__INCLUDED_)
#define AFX_POSITION_H__D46C0871_F1BA_4674_87D1_822509B80FCE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Position.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPosition window

class CPosition : public CWnd
{
// Construction
public:
	CPosition();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPosition)
	//}}AFX_VIRTUAL

// Implementation
public:
	CString GetPositions(int nFlags);
	void SetPositions(BOOL bFlags, CString BallAX, CString BallAY, CString BallBX, CString BallBY, CString HallX, CString HallY);
	virtual ~CPosition();

	// Generated message map functions
protected:
	//{{AFX_MSG(CPosition)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString BallAPosX;
	CString BallAPosY;
	CString BallBPosX;
	CString BallBPosY;
	CString HallPosX;
	CString HallPosY;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POSITION_H__D46C0871_F1BA_4674_87D1_822509B80FCE__INCLUDED_)
