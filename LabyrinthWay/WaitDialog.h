#if !defined(AFX_WAITDIALOG_H__2DD3D20A_65F8_4D88_84C9_7A1422319A57__INCLUDED_)
#define AFX_WAITDIALOG_H__2DD3D20A_65F8_4D88_84C9_7A1422319A57__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WaitDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWaitDialog dialog

class CWaitDialog : public CDialog
{
// Construction
public:
	CWaitDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CWaitDialog)
	enum { IDD = IDD_WAIT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWaitDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWaitDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WAITDIALOG_H__2DD3D20A_65F8_4D88_84C9_7A1422319A57__INCLUDED_)
