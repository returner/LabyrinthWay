// InformationDlg.cpp : implementation file
//

#include "stdafx.h"
#include "LabyrinthWay.h"
#include "InformationDlg.h"
#include "MainFrm.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInformationDlg dialog


CInformationDlg::CInformationDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInformationDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CInformationDlg)
	m_strDecision = _T("");
	m_strGround = _T("");
	m_strTime = _T("");
	m_strCellX = _T("NULL");
	m_strCellNumber = _T("NULL");
	m_strCellY = _T("NULL");
	m_strMouseX = _T("NULL");
	m_strMouseY = _T("NULL");
	//}}AFX_DATA_INIT
}


void CInformationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInformationDlg)
	DDX_Control(pDX, IDC_BUTTON_INPUT, m_ButtonInput);
	DDX_Text(pDX, IDC_EDIT_DECISION, m_strDecision);
	DDV_MaxChars(pDX, m_strDecision, 2);
	DDX_Text(pDX, IDC_EDIT_GROUND, m_strGround);
	DDV_MaxChars(pDX, m_strGround, 2);
	DDX_Text(pDX, IDC_EDIT_TIME, m_strTime);
	DDV_MaxChars(pDX, m_strTime, 2);
	DDX_Text(pDX, IDC_STATI_CELL_X, m_strCellX);
	DDX_Text(pDX, IDC_STATIC_CELL_NUMBER, m_strCellNumber);
	DDX_Text(pDX, IDC_STATIC_CELL_Y, m_strCellY);
	DDX_Text(pDX, IDC_STATIC_MOUSE_X, m_strMouseX);
	DDX_Text(pDX, IDC_STATIC_MOUSE_Y, m_strMouseY);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInformationDlg, CDialog)
	//{{AFX_MSG_MAP(CInformationDlg)
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON_INPUT, OnButtonInput)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInformationDlg message handlers

BOOL CInformationDlg::PreTranslateMessage(MSG* pMsg) 
{
	// ����Ű ó��
	if( pMsg->message == WM_KEYDOWN) // Ű�� �������� �޽������ 
	{
		switch ( pMsg->wParam ) 
        {
         case VK_RETURN: // �׸��� ��Ű�� RETURN�̶��
			this->OnButtonInput();
            return 0; // �ƹ��͵� ���� �ʴ´�.
            break;
		 case VK_ESCAPE: //ESCŰ�� ����....-.-;;
			return 0;
			break;
		}
    }	
	return CDialog::PreTranslateMessage(pMsg);
}

void CInformationDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// ���̾�α��� �ƹ����̳� Ŭ���ص� �̵�����.
	PostMessage(WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM(point.x, point.y));
	
	CDialog::OnLButtonDown(nFlags, point);
}

BOOL CInformationDlg::InitArray(int nImageSizeWidth, int nImageSizeHeight, int pitchX, int pitchY)
{
	// Ŭ���� ���ο��� ����ϴ� CCellData�� bMarkArray �迭 ���� �Ҵ��
	// �ʱ�ȭ.
	m_nArraySize = (nImageSizeWidth / pitchX) * (nImageSizeHeight / pitchY);

	m_pCellData = new CCellData[m_nArraySize];
	m_pbMarkArray = new BOOL[m_nArraySize];
	m_bTempMark = new BOOL[m_nArraySize];   //�ӽ� �迭

	CCellType ct;
	ct.ctDecision = 9;
	ct.ctGround = 9;
	ct.ctNumber = 9;
	ct.ctTime = 9;

	for (int i=0; i<m_nArraySize; i++)
	{
		m_pCellData[i].SetAttributes(TRUE, ct);
		m_pbMarkArray[i] = FALSE;
		m_bTempMark[i] = FALSE;
	}
	bInitArray = TRUE;
	return TRUE;
}

void CInformationDlg::OnButtonInput() 
{
	UpdateData();
    
	// �� ����Ʈ �ڽ��� �Է°˻� /////////////////////////////////
	if (m_strGround == _T("")) 
	{
		MessageBox (_T("�����Ӽ��� �Է����ּ���"), _T("Error"));
		return;
	} // end if

	if (m_strDecision == _T(""))
	{
		MessageBox (_T("�����ڵ带 �Է����ּ���"), _T("Error"));
		return;
	} // end if
	
	if (m_strTime == _T(""))
	{
		MessageBox(_T("�ð��Ӽ��� �������ּ���"), _T("Error"));
		return;
	} // end if
    //////////////////////////////////////////////////////////////
	CCellType ct;

	ct.ctDecision = atoi( (LPCTSTR) m_strDecision );
	ct.ctGround   = atoi( (LPCTSTR) m_strGround );
	ct.ctTime     = atoi( (LPCTSTR) m_strTime );

	////////////////////////////////////////////////
	// CLabyrinthWayView�� �����͸� ����..
	CMainFrame * pFrame = (CMainFrame *) AfxGetMainWnd();
	CLabyrinthWayView * pView = (CLabyrinthWayView *)pFrame->GetActiveView();

	// ���� ���� ����....
	pView->SetInformationDlgArray();
	
	// m_pbMarkArray[] �迭�� ��ü�� �˻��ؼ� TRUE��
	// ������ ���� �����͸� �Է�����
	// ���� ���������� �����..-.-;;

	for (int i=0; i<m_nArraySize; i++)
	{
		if (m_bTempMark[i] == TRUE)
		{
			ct.ctNumber = i;
			m_pCellData[i].SetAttributes(TRUE, ct);
			m_pbMarkArray[i] = TRUE;
		} //end if
	} // end for
	for (i=0; i<m_nArraySize; i++)
	{
		m_bTempMark[i] = FALSE;
	}

	//View���� ����ϴ� m_pMark[] ������ ���� ���� FALSE�� �ʱ�ȭ��..
	pView->InitMarkArrayByView(); 

}

CString CInformationDlg::GetData()
{
	CString strTemp;
	CString strDecision, strGround, strTime, strNumber;
	CCellType ct;

	strTemp = _T("");

	for (int i=0; i<m_nArraySize; i++)
	{
		// ����� �����͸� CString�� ������ ���
		// ��������
		if (m_pbMarkArray[i] == TRUE)
		{
			ct = m_pCellData[i].GetAttributes();
			strNumber.Format(_T("%d"), ct.ctNumber);
			strGround.Format(_T("%d"), ct.ctGround);
			strDecision.Format(_T("%d"), ct.ctDecision);
			strTime.Format(_T("%d"), ct.ctTime);

			strTemp = strTemp + 
					  strNumber + _T(":") +
					  strGround + _T(";") +
					  strDecision + _T(",") +
					 strTime + _T("*") +
					_T("\n") ;
		} // end if
	} // end for

	return strTemp;
}


BOOL CInformationDlg::SetMousePoint(CPoint mousePoint, CPoint cellPoint, int cellNumber)
{
	// ���̾�α��� ��Ʈ�ѿ� ���콺 ��ǥ�� ���� ��ǥ, ���� ��ȣ��
	// �������
	
	// ���콺�� Ŭ���̾�Ʈ ���������� ��ǥ
	m_strMouseX.Format(_T("%d"), mousePoint.x);
	m_strMouseY.Format(_T("%d"), mousePoint.y);

	// ���� ��ǥ
	m_strCellX.Format(_T("%d"), cellPoint.x);
	m_strCellY.Format(_T("%d"), cellPoint.y);

	// ���� ��ȣ
	m_strCellNumber.Format(_T("%d"), cellNumber);

	UpdateData(FALSE);

	return TRUE;
}

void CInformationDlg::DeletePostNcDestroy()
{
	if (bInitArray == TRUE)
	{
		delete[] m_pCellData;
		delete[] m_pbMarkArray;
		delete[] m_bTempMark;
		bInitArray = FALSE;
	}
}
