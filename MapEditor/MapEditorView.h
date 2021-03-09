// MapEditorView.h : interface of the CMapEditorView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAPEDITORVIEW_H__2A16C89C_7BB3_4569_AB98_45732EB00706__INCLUDED_)
#define AFX_MAPEDITORVIEW_H__2A16C89C_7BB3_4569_AB98_45732EB00706__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CDIB.H"
#include "informationdlg.h"
#include "CutDlg.h"
#include "CellData.h"

class CMapEditorView : public CFormView
{
protected: // create from serialization only
	CMapEditorView();
	DECLARE_DYNCREATE(CMapEditorView)

public:
	//{{AFX_DATA(CMapEditorView)
	enum{ IDD = IDD_MAPEDITOR_FORM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	CMapEditorDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMapEditorView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnDraw(CDC* pDC);
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
public:
	int nScrollY;
	int nScrollX;
	void DrawImage();
	void SaveTemp();
	int flagCount;
	int nArraySize;
	int GetCount(int x, int y);
	BOOL * bMark;  //배열의 각 cell별 플래그.
	BOOL SetDrawLinePitch(BOOL bFlags, int pitchX, int pitchY, int Red, int Green, int Blue);
	int cBlue;
	int cGreen;
	int cRed;
	void SetDrawLinePitch(int pitchX, int pitchY, int Red, int Green, int Blue);
	CCellData * pCellData;
	int nImageSizeHeight;
	int nImageSizeWidth;
	BOOL bImageCut; //이미지가 로딩되었는지 아닌지 구분하는 플랙.
	CCutDlg * m_pCutDlg;
	CInformationDlg m_InfoDlg;
	CRectTracker m_tracker;
	CInformationDlg * m_pInfoDlg;
	CStatic m_wndPalette;
	CDib m_DibFile;
	virtual ~CMapEditorView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	BOOL bImageLoad;
	int m_nYPitch;
	int m_nXPitch;
	//{{AFX_MSG(CMapEditorView)
	afx_msg void OnFileOpen();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnCut();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnFileSaveAs();
	afx_msg void OnInvalidate();
	afx_msg void OnViewHeight();
	afx_msg void OnViewSlope();
	afx_msg void OnViewGround();
	afx_msg void OnViewDirx();
	afx_msg void OnViewDiry();
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MapEditorView.cpp
inline CMapEditorDoc* CMapEditorView::GetDocument()
   { return (CMapEditorDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAPEDITORVIEW_H__2A16C89C_7BB3_4569_AB98_45732EB00706__INCLUDED_)
