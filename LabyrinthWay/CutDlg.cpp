// CutDlg.cpp : implementation file
//

#include "stdafx.h"
#include "LabyrinthWay.h"
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
	m_nBlue = 0;
	m_nGreen = 0;
	m_nRed = 0;
	m_nCutX = 10;
	m_nCutY = 10;
	//}}AFX_DATA_INIT
}


void CCutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCutDlg)
	DDX_Text(pDX, IDC_EDIT_BLUE, m_nBlue);
	DDV_MinMaxInt(pDX, m_nBlue, 0, 255);
	DDX_Text(pDX, IDC_EDIT_GREEN, m_nGreen);
	DDV_MinMaxInt(pDX, m_nGreen, 0, 255);
	DDX_Text(pDX, IDC_EDIT_RED, m_nRed);
	DDV_MinMaxInt(pDX, m_nRed, 0, 255);
	DDX_Text(pDX, IDC_EDIT_X, m_nCutX);
	DDV_MinMaxInt(pDX, m_nCutX, 0, 500);
	DDX_Text(pDX, IDC_EDIT_Y, m_nCutY);
	DDV_MinMaxInt(pDX, m_nCutY, 0, 255);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCutDlg, CDialog)
	//{{AFX_MSG_MAP(CCutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCutDlg message handlers

void CCutDlg::OnOK() 
{
	UpdateData(TRUE);

	CDialog::OnOK();

}

CColor CCutDlg::GetColor()
{
	CColor color;
	color.red = m_nRed;
	color.green = m_nGreen;
	color.blue = m_nBlue;

	return color;
}

CPointInt CCutDlg::GetPointInt()
{
	CPointInt pointInt;
	pointInt.x = m_nCutX;
	pointInt.y = m_nCutY;

	return pointInt;
}

BOOL CCutDlg::PreTranslateMessage(MSG* pMsg) 
{
	// 엔터키 처리
	if( pMsg->message == WM_KEYDOWN) // 키가 눌려지는 메시지라면 
	{
		switch ( pMsg->wParam ) 
        {
         case VK_RETURN: // 그리고 그키가 RETURN이라면
			this->OnOK();  // 버튼을 누른것처럼........
            return 0; 
            break;
		 case VK_ESCAPE: //ESC키는 죽임...-.-;;
			return 0;
			break;
		}
    }	
	return CDialog::PreTranslateMessage(pMsg);
}

void CCutDlg::OnCancel() 
{
	this->SendMessage(WM_DESTROY);
	CDialog::OnCancel();
}
