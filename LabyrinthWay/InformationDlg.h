#if !defined(AFX_INFORMATIONDLG_H__4CA5A3D4_E656_4E39_BDE4_B8B592A68B47__INCLUDED_)
#define AFX_INFORMATIONDLG_H__4CA5A3D4_E656_4E39_BDE4_B8B592A68B47__INCLUDED_

#include "Labyrinth.h"	// Added by ClassView
#include "PointInt.h"	// Added by ClassView
#include "CColor.h"	// Added by ClassView

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// InformationDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CInformationDlg dialog

class CInformationDlg : public CDialog
{
// Construction
public:
	BOOL * m_bTempMark;
	BOOL * m_pbMarkArray;
	CCellData * m_pCellData;
	void DeletePostNcDestroy();
	BOOL SetMousePoint (CPoint mousePoint, CPoint cellPoint, int cellNumber);
	CString GetData();
	BOOL InitArray(int nImageSizeWidth, int nImageSizeHeight, int pitchX, int pitchY);
	CInformationDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CInformationDlg)
	enum { IDD = IDD_INFORMATION };
	CButton	m_ButtonInput;
	CString	m_strDecision;
	CString	m_strGround;
	CString	m_strTime;
	CString	m_strCellX;
	CString	m_strCellNumber;
	CString	m_strCellY;
	CString	m_strMouseX;
	CString	m_strMouseY;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInformationDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
	
protected:
	int  m_nArraySize;
	BOOL bInitArray;
	CColor m_cColor;
	CPointInt m_cPointInt;

	// Generated message map functions
	//{{AFX_MSG(CInformationDlg)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnButtonInput();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INFORMATIONDLG_H__4CA5A3D4_E656_4E39_BDE4_B8B592A68B47__INCLUDED_)
