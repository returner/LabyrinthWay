#if !defined(AFX_HELPDIALOG_H__82DBD67D_7535_4064_9CC7_46572AC26FAC__INCLUDED_)
#define AFX_HELPDIALOG_H__82DBD67D_7535_4064_9CC7_46572AC26FAC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HelpDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHelpDialog dialog

class CHelpDialog : public CDialog
{
// Construction
public:
	CHelpDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CHelpDialog)
	enum { IDD = IDD_DIALOG_HELP };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHelpDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CHelpDialog)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HELPDIALOG_H__82DBD67D_7535_4064_9CC7_46572AC26FAC__INCLUDED_)
