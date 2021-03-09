// LabyrinthWay.h : main header file for the LABYRINTHWAY application
//

#if !defined(AFX_LABYRINTHWAY_H__362C7438_F4AB_4317_ABF1_FF68F9451732__INCLUDED_)
#define AFX_LABYRINTHWAY_H__362C7438_F4AB_4317_ABF1_FF68F9451732__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CLabyrinthWayApp:
// See LabyrinthWay.cpp for the implementation of this class
//

class CLabyrinthWayApp : public CWinApp
{
public:
	CLabyrinthWayApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLabyrinthWayApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CLabyrinthWayApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LABYRINTHWAY_H__362C7438_F4AB_4317_ABF1_FF68F9451732__INCLUDED_)
