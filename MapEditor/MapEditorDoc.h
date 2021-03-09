// MapEditorDoc.h : interface of the CMapEditorDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAPEDITORDOC_H__C5A8BCA1_0644_46EF_8FD0_F03BB92406F8__INCLUDED_)
#define AFX_MAPEDITORDOC_H__C5A8BCA1_0644_46EF_8FD0_F03BB92406F8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMapEditorDoc : public CDocument
{
protected: // create from serialization only
	CMapEditorDoc();
	DECLARE_DYNCREATE(CMapEditorDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMapEditorDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMapEditorDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMapEditorDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAPEDITORDOC_H__C5A8BCA1_0644_46EF_8FD0_F03BB92406F8__INCLUDED_)
