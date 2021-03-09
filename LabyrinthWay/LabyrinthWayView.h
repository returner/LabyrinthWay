// LabyrinthWayView.h : interface of the CLabyrinthWayView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LABYRINTHWAYVIEW_H__9274588D_34F7_4414_BDA5_45FC84ECB850__INCLUDED_)
#define AFX_LABYRINTHWAYVIEW_H__9274588D_34F7_4414_BDA5_45FC84ECB850__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "LabyrinthWayDoc.h"
#ifndef _LABYRINTH_H
#include "Labyrinth.h"   //파서용 클래스
#include "CDIB.h"   // DIB 출력
#include "InformationDlg.h" //왼쪽 정보출력 다이얼로그
#include "CutDlg.h"   //중간에 뜨는 짜르는 다이얼로그
#include "WaitDialog.h"

#endif
#include "CColor.h"	// Added by ClassView

class CLabyrinthWayView : public CScrollView
{
protected: // create from serialization only
	CLabyrinthWayView();
	DECLARE_DYNCREATE(CLabyrinthWayView)

// Attributes
public:
	CLabyrinthWayDoc* GetDocument();
	void InitMarkArrayByView();
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLabyrinthWayView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
public:
	void SetInformationDlgArray();
	virtual ~CLabyrinthWayView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	bool bViewArrayCreated;
	BOOL m_bLoadTextFile;
	BOOL m_bSaveData;

	CWaitDialog * m_pWaitDlg;
	CPoint m_nScrollPoint;
	void DrawMark(int nBitmapID, int nCellNumber);
	void DrawMark(int nBitmapID, CPoint markPoint);
	int GetImageNumber(int x, int y);
	CColor m_cColor;
	BOOL DrawLineByPitch(int pitchX, int pitchY, CColor color);
	CDib m_DibFile;
	void OnCutDialog();
	BOOL bImageLoad;  //이미지가 로딩되었으면 TRUE;
	int m_nYPitch;
	int m_nXPitch;
	int m_nImageSizeHeight;
	int m_nImageSizeWidth;
	BOOL * m_bMark;
	CCellData * m_pCellData;
	CCutDlg m_CutDlg;
	CInformationDlg * m_pInfoDlg;
	//{{AFX_MSG(CLabyrinthWayView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnFileOpen();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnFileSaveAs();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnDataFileOpen();
	afx_msg void OnDialogHelp();
	afx_msg void OnFileSave();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in LabyrinthWayView.cpp
inline CLabyrinthWayDoc* CLabyrinthWayView::GetDocument()
   { return (CLabyrinthWayDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LABYRINTHWAYVIEW_H__9274588D_34F7_4414_BDA5_45FC84ECB850__INCLUDED_)
