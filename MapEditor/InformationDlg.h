#if !defined(AFX_INFORMATIONDLG_H__DE96543B_F6D9_4AA7_9F71_CEEDCBFE6BAC__INCLUDED_)
#define AFX_INFORMATIONDLG_H__DE96543B_F6D9_4AA7_9F71_CEEDCBFE6BAC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// InformationDlg.h : header file
//
/////////////////////////////////////////////////////////////////////////////
// CInformationDlg dialog

#include "CellData.h"
#include "Position.h"

class CInformationDlg : public CDialog
{
// Construction
public:
	CString GetData(int nArray, int nFlags);
	CString GetPosition();
	CString GetArray();
	int nSizeArray;
	BOOL * bMarkArray;
	void SetCount(int nNumberArray);
	void DeleteArray();
	int nPosy;
	int nPosx;
	void SetArrayData(int nPosX, int nPosY);
	CPosition cpos;
	void InitArray(int pitchX, int pitchY);
	CCellData * cellData;
	void SetPitch(int xP, int yP);
	void SetImageSize(int Width, int Height);
	void SetPoint(BOOL bFlags, int X, int Y);
	void SetPoint(BOOL bFlags, CString strX, CString strY);
	CInformationDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CInformationDlg)
	enum { IDD = IDD_INFORMATION };
	CString	m_EndX;
	CString	m_EndY;
	CString	m_OriginX;
	CString	m_OriginY;
	CString	m_PointX;
	CString	m_PointY;
	CString	m_AttAtt;
	CString	m_AttDirX;
	CString	m_AttHeight;
	CString	m_AttSlope;
	CString	m_Ax;
	CString	m_Ay;
	CString	m_Bx;
	CString	m_By;
	CString	m_Hx;
	CString	m_Hy;
	CString	m_AttDirY;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInformationDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void PostNcDestroy();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
protected:
	bool bInitArray;
	int yPitch;
	int xPitch;
	int nImageSizeHeight;
	int nImageSizeWidth;

	// Generated message map functions
	//{{AFX_MSG(CInformationDlg)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnButtonInput();
	afx_msg void OnButtonPosition();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INFORMATIONDLG_H__DE96543B_F6D9_4AA7_9F71_CEEDCBFE6BAC__INCLUDED_)
//DEL 
//DEL 
//DEL 
//DEL 
//DEL 
//DEL 
//DEL 
//DEL 
