// InformationDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MapEditor.h"
#include "InformationDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInformationDlg dialog


CInformationDlg::CInformationDlg(CWnd* pParent /*=NULL*/)
{
	//{{AFX_DATA_INIT(CInformationDlg)
	m_EndX = _T("");
	m_EndY = _T("");
	m_OriginX = _T("");
	m_OriginY = _T("");
	m_PointX = _T("");
	m_PointY = _T("");
	m_AttAtt = _T("");
	m_AttDirX = _T("");
	m_AttHeight = _T("");
	m_AttSlope = _T("");
	m_Ax = _T("");
	m_Ay = _T("");
	m_Bx = _T("");
	m_By = _T("");
	m_Hx = _T("");
	m_Hy = _T("");
	m_AttDirY = _T("");
	//}}AFX_DATA_INIT

	bInitArray = false;
}


void CInformationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInformationDlg)
	DDX_Text(pDX, IDC_END_X, m_EndX);
	DDX_Text(pDX, IDC_END_Y, m_EndY);
	DDX_Text(pDX, IDC_ORIGIN_X, m_OriginX);
	DDX_Text(pDX, IDC_ORIGIN_Y, m_OriginY);
	DDX_Text(pDX, IDC_POINT_X, m_PointX);
	DDX_Text(pDX, IDC_POINT_Y, m_PointY);
	DDX_Text(pDX, IDC_EDIT_ATT_ATT, m_AttAtt);
	DDX_Text(pDX, IDC_EDIT_ATT_DIR_X, m_AttDirX);
	DDX_Text(pDX, IDC_EDIT_ATT_HEIGHT, m_AttHeight);
	DDX_Text(pDX, IDC_EDIT_ATT_SLOPE, m_AttSlope);
	DDX_Text(pDX, IDC_EDIT_AX, m_Ax);
	DDX_Text(pDX, IDC_EDIT_AY, m_Ay);
	DDX_Text(pDX, IDC_EDIT_BX, m_Bx);
	DDX_Text(pDX, IDC_EDIT_BY, m_By);
	DDX_Text(pDX, IDC_EDIT_HX, m_Hx);
	DDX_Text(pDX, IDC_EDIT_HY, m_Hy);
	DDX_Text(pDX, IDC_EDIT_ATT_DIR_Y, m_AttDirY);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInformationDlg, CDialog)
	//{{AFX_MSG_MAP(CInformationDlg)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_BUTTON_INPUT, OnButtonInput)
	ON_BN_CLICKED(IDC_BUTTON_POSITION, OnButtonPosition)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInformationDlg message handlers

int CInformationDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	m_EndX = m_EndY = _T("");
	m_OriginX = m_OriginY = _T("");
	m_PointX = m_PointY = _T("");

//	this->SetWindowPos(&wndTopMost,0,0,169,500,SWP_NOSIZE);
	return 0;
}

void CInformationDlg::SetPoint(BOOL bFlags, CString strX, CString strY)
{
	if (bFlags == TRUE)
	{
		m_OriginX = strX;
		m_OriginY = strY;
		UpdateData(FALSE);
	}
	else
	{
		m_EndX = strX;
		m_EndY = strY;
		UpdateData(FALSE);
	}


}

void CInformationDlg::SetPoint(BOOL bFlags, int X, int Y)
{
	CString strX, strY;
	nPosx = X;
	nPosy = Y;

	strX.Format("%d", X);
	strY.Format("%d", Y);
	if (bFlags == TRUE)   // Origin Coordinate
	{
		SetPoint(TRUE, strX, strY);
	}
	else //End Coordinate
	{
		SetPoint(FALSE, strX, strY);
	}

}

void CInformationDlg::SetImageSize(int Width, int Height)
{
	nImageSizeWidth = Width;
	nImageSizeHeight = Height;
}

BOOL CInformationDlg::PreTranslateMessage(MSG* pMsg) 
{
	if( pMsg->message == WM_KEYDOWN) // 키가 눌려지는 메시지라면 
            {
                switch ( pMsg->wParam ) 
                {
                case VK_RETURN: // 그리고 그키가 RETURN이라면
                    return 0; // 아무것도 하지 않는다.
                    break;
				case VK_ESCAPE: //ESC키도 역시....-.-;;
					return 0;
					break;
                }
            }
    
	return CDialog::PreTranslateMessage(pMsg);
}

void CInformationDlg::SetPitch(int xP, int yP)
{
	xPitch = xP;
	yPitch = yP;
}

void CInformationDlg::OnButtonInput() 
{
	UpdateData();

	for (int i=0; i< nSizeArray; i++)
	{
		if (bMarkArray[i] == TRUE)
		{
			cellData[i].SetAttributes(TRUE, TRUE, m_AttHeight, m_AttSlope, m_AttAtt, m_AttDirX, m_AttDirY);
			bMarkArray[i] = FALSE;
		}
	}
}

void CInformationDlg::InitArray(int pitchX, int pitchY)
{
	bInitArray = true;

	nSizeArray = (nImageSizeWidth / pitchX) * (nImageSizeHeight / pitchY);
	cellData = new CCellData[nSizeArray];
	bMarkArray = new BOOL[nSizeArray];

	for (int i=0; i<nSizeArray; i++)
	{
		cellData[i].SetAttributes(FALSE, FALSE, "", "", "","","");
		bMarkArray[i] = FALSE;
	}

}


void CInformationDlg::PostNcDestroy() 
{
	if (bInitArray == true)
	{
		delete[] cellData;
		bInitArray = false;
	}

	CDialog::PostNcDestroy();  //
}

void CInformationDlg::OnButtonPosition() 
{
	UpdateData(TRUE);
	cpos.SetPositions(TRUE, m_Ax, m_Ax, m_Bx, m_By, m_Hx, m_Hy);
}

void CInformationDlg::SetArrayData(int nPosX, int nPosY)
{
	UpdateData(TRUE);
	int nPosCount=0;
	nPosCount = ( (nImageSizeWidth/xPitch) * nPosY) + nPosX;
	cellData[nPosCount].SetAttributes(TRUE, m_AttHeight, m_AttSlope, m_AttAtt, m_AttDirX, m_AttDirY);
	CString aaa, p;
	aaa = cellData[nPosCount].GetAtt();
	p.Format("%d",nPosCount);
	MessageBox (p+": "+aaa);
}


void CInformationDlg::DeleteArray()
{
	delete[] cellData;
	delete[] bMarkArray;
}

void CInformationDlg::SetCount(int nNumberArray)
{
	if (bMarkArray[nNumberArray] == FALSE)
	{
		bMarkArray[nNumberArray] = TRUE;
	}
	else
	{
		bMarkArray[nNumberArray] = FALSE;
	}
}





CString CInformationDlg::GetArray()
{
	CString temp;
	CString aa;      //delete
	temp = aa = "";
	
	for (int k=0; k<nSizeArray; k++)
	{
		if (cellData[k].bInputFlag == TRUE)
		{
			aa.Format ("%d", k);
			temp = temp + aa + ":" + cellData[k].GetAtt() + "\n";
		}
	}

	return temp;
}

CString CInformationDlg::GetPosition()
{
	CString ret;
	ret = cpos.GetPositions(7);

	return ret;
}

CString CInformationDlg::GetData(int nArray, int nFlags)
{
	// 플래그별로 배열의 값을 리턴.
	if (nFlags == 1 ) return cellData[nArray].GetAtt(1);
	if (nFlags == 2 ) return cellData[nArray].GetAtt(2);
	if (nFlags == 3 ) return cellData[nArray].GetAtt(3);
	if (nFlags == 4 ) return cellData[nArray].GetAtt(4);
	if (nFlags == 5 ) return cellData[nArray].GetAtt(5);

	return "-_-;;;";
}

BOOL CInformationDlg::PreCreateWindow(CREATESTRUCT& cs) 
{
	// TODO: Add your specialized code here and/or call the base class
//	this->SetWindowPos(&wndTopMost,0,0,169,500,SWP_NOSIZE);
	return CDialog::PreCreateWindow(cs);
}

void CInformationDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	// 다이얼로그의 아무곳이나 클릭해도 이동가능.

	PostMessage(WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM(point.x, point.y));

	CDialog::OnLButtonDown(nFlags, point);
}
