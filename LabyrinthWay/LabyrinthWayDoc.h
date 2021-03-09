// LabyrinthWayDoc.h : interface of the CLabyrinthWayDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LABYRINTHWAYDOC_H__C263294A_F3AA_4F98_B167_DE5D53A7D50B__INCLUDED_)
#define AFX_LABYRINTHWAYDOC_H__C263294A_F3AA_4F98_B167_DE5D53A7D50B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CLabyrinthWayDoc : public CDocument
{
protected: // create from serialization only
	CLabyrinthWayDoc();
	DECLARE_DYNCREATE(CLabyrinthWayDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLabyrinthWayDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLabyrinthWayDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLabyrinthWayDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LABYRINTHWAYDOC_H__C263294A_F3AA_4F98_B167_DE5D53A7D50B__INCLUDED_)
