// SampleParserDlg.h : header file
//

#if !defined(AFX_SAMPLEPARSERDLG_H__42B60349_3CD1_494F_8240_9AFF7FD2E942__INCLUDED_)
#define AFX_SAMPLEPARSERDLG_H__42B60349_3CD1_494F_8240_9AFF7FD2E942__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CSampleParserDlg dialog

class CSampleParserDlg : public CDialog
{
// Construction
public:
	CSampleParserDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSampleParserDlg)
	enum { IDD = IDD_SAMPLEPARSER_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSampleParserDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSampleParserDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLEPARSERDLG_H__42B60349_3CD1_494F_8240_9AFF7FD2E942__INCLUDED_)
