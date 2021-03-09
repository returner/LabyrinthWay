// SampleParserDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SampleParser.h"
#include "SampleParserDlg.h"
#include "Labyrinth.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSampleParserDlg dialog

CSampleParserDlg::CSampleParserDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSampleParserDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSampleParserDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSampleParserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSampleParserDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSampleParserDlg, CDialog)
	//{{AFX_MSG_MAP(CSampleParserDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSampleParserDlg message handlers

BOOL CSampleParserDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	CenterWindow(GetDesktopWindow());	// center to the hpc screen

	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}



void CSampleParserDlg::OnButton1() 
{
	CParser parser;
	CCellData * cellData;
	CCellType ct;
	int LineCount;
	LineCount = parser.GetLineCount(_T("\\My Documents\\test.txt"));
	cellData = parser.ParseFile(_T("\\My Documents\\test.txt"), LineCount);
		
	MessageBox(_T("Reading End"));

	CString a,b,c,d,e,f;
	a.Format(_T("%d"), LineCount);

	for (int i=0; i<LineCount; i++)
	{
		ct = cellData[i].GetAttributes();
		b.Format(_T("%d"), ct.ctNumber);
		c.Format(_T("%d"), ct.ctGround);
		d.Format(_T("%d"), ct.ctDecision);
		e.Format(_T("%d"), ct.ctTime);

		f = _T("LineCount : ") + a + _T("\n") + 
			_T("Number    : ") + b + _T("\n") +
			_T("Ground    : ") + c + _T("\n") +
			_T("Decision  : ") + d + _T("\n") +
			_T("Time      : ") + e + _T("\n");
		MessageBox (f);
	}	
}
