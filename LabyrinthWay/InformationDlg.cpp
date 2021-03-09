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
	// 엔터키 처리
	if( pMsg->message == WM_KEYDOWN) // 키가 눌려지는 메시지라면 
	{
		switch ( pMsg->wParam ) 
        {
         case VK_RETURN: // 그리고 그키가 RETURN이라면
			this->OnButtonInput();
            return 0; // 아무것도 하지 않는다.
            break;
		 case VK_ESCAPE: //ESC키도 역시....-.-;;
			return 0;
			break;
		}
    }	
	return CDialog::PreTranslateMessage(pMsg);
}

void CInformationDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// 다이얼로그의 아무곳이나 클릭해도 이동가능.
	PostMessage(WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM(point.x, point.y));
	
	CDialog::OnLButtonDown(nFlags, point);
}

BOOL CInformationDlg::InitArray(int nImageSizeWidth, int nImageSizeHeight, int pitchX, int pitchY)
{
	// 클래스 내부에서 사용하는 CCellData와 bMarkArray 배열 동적 할당및
	// 초기화.
	m_nArraySize = (nImageSizeWidth / pitchX) * (nImageSizeHeight / pitchY);

	m_pCellData = new CCellData[m_nArraySize];
	m_pbMarkArray = new BOOL[m_nArraySize];
	m_bTempMark = new BOOL[m_nArraySize];   //임시 배열

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
    
	// 각 에디트 박스별 입력검사 /////////////////////////////////
	if (m_strGround == _T("")) 
	{
		MessageBox (_T("지형속성을 입력해주세요"), _T("Error"));
		return;
	} // end if

	if (m_strDecision == _T(""))
	{
		MessageBox (_T("판정코드를 입력해주세요"), _T("Error"));
		return;
	} // end if
	
	if (m_strTime == _T(""))
	{
		MessageBox(_T("시간속성을 입혁해주세요"), _T("Error"));
		return;
	} // end if
    //////////////////////////////////////////////////////////////
	CCellType ct;

	ct.ctDecision = atoi( (LPCTSTR) m_strDecision );
	ct.ctGround   = atoi( (LPCTSTR) m_strGround );
	ct.ctTime     = atoi( (LPCTSTR) m_strTime );

	////////////////////////////////////////////////
	// CLabyrinthWayView의 포인터를 구함..
	CMainFrame * pFrame = (CMainFrame *) AfxGetMainWnd();
	CLabyrinthWayView * pView = (CLabyrinthWayView *)pFrame->GetActiveView();

	// 그쪽 설명 참조....
	pView->SetInformationDlgArray();
	
	// m_pbMarkArray[] 배열의 전체를 검사해서 TRUE로
	// 설정된 곳에 데이터를 입력해줌
	// 역시 삽질스러운 방법임..-.-;;

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

	//View에서 사용하는 m_pMark[] 벼열의 값을 몽땅 FALSE로 초기화함..
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
		// 저장된 데이터를 CString형 변수에 담아
		// 리턴해줌
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
	// 다이얼로그의 컨트롤에 마우스 좌표와 셀의 좌표, 셀의 번호를
	// 출력해줌
	
	// 마우스의 클라이언트 영역에서의 좌표
	m_strMouseX.Format(_T("%d"), mousePoint.x);
	m_strMouseY.Format(_T("%d"), mousePoint.y);

	// 셀의 좌표
	m_strCellX.Format(_T("%d"), cellPoint.x);
	m_strCellY.Format(_T("%d"), cellPoint.y);

	// 셀의 번호
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
