// TestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Test.h"
#include "TestDlg.h"
#include "Labyrinth.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestDlg dialog

CTestDlg::CTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTestDlg, CDialog)
	//{{AFX_MSG_MAP(CTestDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestDlg message handlers

BOOL CTestDlg::OnInitDialog()
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



void CTestDlg::OnButton1() 
{
	//////////////////////////////////////////////////////////////////////
	// Labyrinth 사용방법 !!!!

	CParser parser;
	CCellData * cellData;  /////// CCellData형 포인터를 구하고..
	CCellType ct;    //데이터가 들어가는 클래스..
	int LineCount=0;
	///////////////////////////////////////////////////////////
	cellData = parser.ParseFile(_T("\\My Documents\\test.txt")); //파일명을 넣주면..
	                                                             // CCellData형으로 리턴..

	LineCount = parser.GetLineCount();   // 파일의 길이를 구함..
    //////////////////////////////////////////

	MessageBox(_T("Reading End"));

	CString a,b,c,d,e,f;
	a.Format(_T("%d"), LineCount);

	for (int i=0; i<LineCount; i++)
	{
		ct = cellData[i].GetAttributes();   
		b.Format(_T("%d"), ct.ctNumber);   // 셀번호..
		c.Format(_T("%d"), ct.ctGround);   // 지면속성.
		d.Format(_T("%d"), ct.ctDecision); // 판정..
		e.Format(_T("%d"), ct.ctTime);     // 시간..

		f = _T("LineCount : ") + a + _T("\n") +
			_T("Number    : ") + b + _T("\n") +
			_T("Ground    : ") + c + _T("\n") +
			_T("Decision  : ") + d + _T("\n") +
			_T("Time      : ") + e + _T("\n");
		MessageBox (f);
	}	
}

void CTestDlg::OnButton2() 
{
	// NumberToPoint Test
	CCellData * cellData;
	CParser cPa;
	CCellType ct;
	POINT point;

	int count;
	cellData = cPa.ParseFile (_T("\\My Documents\\test.txt"));
	count = cPa.GetLineCount();
	MessageBox (_T("Reading End"));

	CString str, strCount, x, y;
	strCount.Format(_T("%d"), count);
	MessageBox (_T("Count") + strCount + _T(" items") );
	int n;
	for (int i=0; i<count; i++)
	{
		ct = cellData[i].GetAttributes();
		n = ct.ctNumber;
		point = cPa.NumberToPoint (n, 1200, 10, 10);

		x.Format(_T("%d"), point.x);
		y.Format(_T("%d"), point.y);
		str.Format(_T("%d"), n);
		MessageBox(_T("CellNumber : ") + str + _T("\n") +
				   _T("X : ") + x + _T("\n") +
				   _T("Y : ") + y + _T("\n") );
	}
	
}
