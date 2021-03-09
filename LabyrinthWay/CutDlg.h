#if !defined(AFX_CUTDLG_H__AF389D9D_766F_4079_8B1D_25C4FD255FFA__INCLUDED_)
#define AFX_CUTDLG_H__AF389D9D_766F_4079_8B1D_25C4FD255FFA__INCLUDED_

#include "CColor.h"	// Added by ClassView
#include "PointInt.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// CutDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCutDlg dialog

class CCutDlg : public CDialog
{
// Construction
public:
	CPointInt GetPointInt();
	CColor GetColor();
	CColor color;
	CCutDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCutDlg)
	enum { IDD = IDD_CUT };
	int		m_nBlue;
	int		m_nGreen;
	int		m_nRed;
	int		m_nCutX;
	int		m_nCutY;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCutDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CCutDlg)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUTDLG_H__AF389D9D_766F_4079_8B1D_25C4FD255FFA__INCLUDED_)
