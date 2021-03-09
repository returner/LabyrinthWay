// LabyrinthWayDoc.cpp : implementation of the CLabyrinthWayDoc class
//

#include "stdafx.h"
#include "LabyrinthWay.h"

#include "LabyrinthWayDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLabyrinthWayDoc

IMPLEMENT_DYNCREATE(CLabyrinthWayDoc, CDocument)

BEGIN_MESSAGE_MAP(CLabyrinthWayDoc, CDocument)
	//{{AFX_MSG_MAP(CLabyrinthWayDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLabyrinthWayDoc construction/destruction

CLabyrinthWayDoc::CLabyrinthWayDoc()
{
	// TODO: add one-time construction code here

}

CLabyrinthWayDoc::~CLabyrinthWayDoc()
{
}

BOOL CLabyrinthWayDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CLabyrinthWayDoc serialization

void CLabyrinthWayDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CLabyrinthWayDoc diagnostics

#ifdef _DEBUG
void CLabyrinthWayDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLabyrinthWayDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLabyrinthWayDoc commands
