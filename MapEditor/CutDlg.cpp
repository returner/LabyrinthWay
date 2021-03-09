// CutDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mapeditor.h"
#include "CutDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCutDlg dialog


CCutDlg::CCutDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCutDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCutDlg)
	m_nCutX = 0;
	m_nCutY = 0;
	m_nBlue = 0;
	m_nGreen = 0;
	m_nRed = 0;
	//}}AFX_DATA_INIT
}


void CCutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCutDlg)
	DDX_Text(pDX, IDC_EDIT_CUT_X, m_nCutX);
	DDV_MinMaxInt(pDX, m_nCutX, 1, 100);
	DDX_Text(pDX, IDC_EDIT_CUT_Y, m_nCutY);
	DDV_MinMaxInt(pDX, m_nCutY, 1, 100);
	DDX_Text(pDX, IDC_EDIT_BLUE, m_nBlue);
	DDV_MinMaxInt(pDX, m_nBlue, 0, 255);
	DDX_Text(pDX, IDC_EDIT_GREEN, m_nGreen);
	DDV_MinMaxInt(pDX, m_nGreen, 0, 255);
	DDX_Text(pDX, IDC_EDIT_RED, m_nRed);
	DDV_MinMaxInt(pDX, m_nRed, 0, 255);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCutDlg, CDialog)
	//{{AFX_MSG_MAP(CCutDlg)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCutDlg message handlers

int CCutDlg::GetXPitch()
{
	return m_nCutX;
}

int CCutDlg::GetYPitch()
{
	return m_nCutY;
}

void CCutDlg::OnOK() 
{
	UpdateData(TRUE);
	CDialog::OnOK();
}

void CCutDlg::OnCancel() 
{
	// TODO: Add your control notification handler code here
	
	CDialog::OnCancel();
}


void CCutDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	m_nRed = 0;
	m_nGreen = 0;
	m_nBlue = 0;
	UpdateData(FALSE);
	// Do not call CDialog::OnPaint() for painting messages
}

int CCutDlg::GetColorRed()
{
	// »¡°£»ö ¾òÀ½
	return m_nRed;
}

int CCutDlg::GetColorGreen()
{
	// ³ì»ö¾òÀ½
	return m_nGreen;
}

int CCutDlg::GetColorBlue()
{
	// ÆÄ¶û¾òÀ½
	return m_nBlue;
}
