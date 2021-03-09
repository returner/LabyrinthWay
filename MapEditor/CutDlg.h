#if !defined(AFX_CUTDLG_H__5CDC86C3_AB43_445F_BBBE_8EEB67DA6146__INCLUDED_)
#define AFX_CUTDLG_H__5CDC86C3_AB43_445F_BBBE_8EEB67DA6146__INCLUDED_

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
	int GetColorBlue();
	int GetColorGreen();
	int GetColorRed();
	int GetYPitch();
	int GetXPitch();
	CCutDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCutDlg)
	enum { IDD = IDD_CUT };
	int		m_nCutX;
	int		m_nCutY;
	int		m_nBlue;
	int		m_nGreen;
	int		m_nRed;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCutDlg)
	public:
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	int nImageSizeHeight;
	int nImageSizeWidth;


	// Generated message map functions
	//{{AFX_MSG(CCutDlg)
	virtual void OnOK();
	afx_msg void OnCancel();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUTDLG_H__5CDC86C3_AB43_445F_BBBE_8EEB67DA6146__INCLUDED_)
