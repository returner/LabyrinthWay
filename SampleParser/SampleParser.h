// SampleParser.h : main header file for the SAMPLEPARSER application
//

#if !defined(AFX_SAMPLEPARSER_H__2FC4A004_1758_48DD_A54F_CF7E5AC8E4FF__INCLUDED_)
#define AFX_SAMPLEPARSER_H__2FC4A004_1758_48DD_A54F_CF7E5AC8E4FF__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSampleParserApp:
// See SampleParser.cpp for the implementation of this class
//

class CSampleParserApp : public CWinApp
{
public:
	CSampleParserApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSampleParserApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSampleParserApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLEPARSER_H__2FC4A004_1758_48DD_A54F_CF7E5AC8E4FF__INCLUDED_)
