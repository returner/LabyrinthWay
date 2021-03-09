// MapEditorView.cpp : implementation of the CMapEditorView class
//

#include "stdafx.h"
#include "MapEditor.h"

#include "MapEditorDoc.h"
#include "MapEditorView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMapEditorView

IMPLEMENT_DYNCREATE(CMapEditorView, CFormView)

BEGIN_MESSAGE_MAP(CMapEditorView, CFormView)
	//{{AFX_MSG_MAP(CMapEditorView)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_WM_SIZE()
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(IDM_CUT, OnCut)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_FILE_SAVE_AS, OnFileSaveAs)
	ON_COMMAND(ID_INVALIDATE, OnInvalidate)
	ON_COMMAND(IDM_VIEW_HEIGHT, OnViewHeight)
	ON_COMMAND(IDM_VIEW_SLOPE, OnViewSlope)
	ON_COMMAND(IDM_VIEW_GROUND, OnViewGround)
	ON_COMMAND(IDM_VIEW_DIRX, OnViewDirx)
	ON_COMMAND(IDM_VIEW_DIRY, OnViewDiry)
	ON_WM_MOUSEWHEEL()
	ON_WM_RBUTTONUP()
	ON_WM_VSCROLL()
	ON_WM_HSCROLL()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMapEditorView construction/destruction

CMapEditorView::CMapEditorView()
	: CFormView(CMapEditorView::IDD)
{
	//{{AFX_DATA_INIT(CMapEditorView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// TODO: add construction code here
	m_pInfoDlg = NULL;
	m_pCutDlg = NULL;
	bImageCut = FALSE;
	m_nXPitch = 1;
	m_nYPitch = 1;
	bImageLoad = FALSE;
	flagCount = 0;
	nImageSizeWidth = 1;
	nImageSizeHeight = 1;
	nScrollX = 0;
	nScrollY = 0;
}

CMapEditorView::~CMapEditorView()
{
}

void CMapEditorView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMapEditorView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BOOL CMapEditorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CMapEditorView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	CSize sizeTotal(nImageSizeWidth, nImageSizeHeight);
	CSize sizeLine = CSize(sizeTotal.cx/m_nXPitch, sizeTotal.cy/m_nYPitch);

	SetScrollSizes(MM_TEXT, sizeTotal, sizeTotal, sizeLine);
//	SetScrollSizes(MM_TEXT, CSize(0,0) );
//	m_wndPalette.Create("", WS_VISIBLE|WS_CHILD|SS_BLACKFRAME,CRect(0,0,0,0),this);
	m_tracker.m_nStyle |= CRectTracker::solidLine | CRectTracker::resizeOutside;

	

}

/////////////////////////////////////////////////////////////////////////////
// CMapEditorView printing

BOOL CMapEditorView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMapEditorView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMapEditorView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMapEditorView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CMapEditorView diagnostics

#ifdef _DEBUG
void CMapEditorView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMapEditorView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMapEditorDoc* CMapEditorView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMapEditorDoc)));
	return (CMapEditorDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMapEditorView message handlers

void CMapEditorView::OnFileOpen() 
{
	CFileDialog dlg(TRUE, "bmp", "*.bmp");
	if (dlg.DoModal() == IDOK)
	{
		CFile file;
		file.Open(dlg.GetPathName(), CFile::modeRead);
		if (m_DibFile.Read(&file) == TRUE)
			Invalidate();
		CClientDC dc(this);
		m_DibFile.SetSystemPalette(&dc);
		bImageCut = TRUE;
		OnCut();
		this->SetFocus();
	}
}

void CMapEditorView::OnDraw(CDC* pDC) 
{
	///////////////////////////////////////
	BeginWaitCursor();
	
	m_DibFile.UsePalette(pDC);
	CSize sizeFileDib = m_DibFile.GetDimensions();
	nImageSizeWidth = sizeFileDib.cx;  //이미지 가로 사이즈
	nImageSizeHeight = sizeFileDib.cy; //이미지 세로 사이즈
	m_pInfoDlg->SetImageSize(nImageSizeWidth, nImageSizeHeight); //다이얼로그에 이미지 사이즈 전달.
	CSize sizeTotal(nImageSizeWidth, nImageSizeHeight);
	CSize sizeLine = CSize(sizeTotal.cx/m_nXPitch, sizeTotal.cy/m_nYPitch);
	CSize sizeArrow = CSize(m_nXPitch, m_nYPitch);

	CRect rect;
	GetClientRect(&rect);
	m_DibFile.Draw(pDC, CPoint(0, 0),sizeFileDib);

	EndWaitCursor();

	/////////////////////////////////////
	CMapEditorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
//	m_tracker.Draw(pDC);

	SetScrollSizes(MM_TEXT, sizeTotal, sizeTotal, sizeArrow);
	//////////////////////////////////////////////////////////////
	SetDrawLinePitch(TRUE, m_nXPitch, m_nYPitch, cRed, cGreen, cBlue);



}

void CMapEditorView::OnSize(UINT nType, int cx, int cy) 
{
	CFormView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	if (m_wndPalette.GetSafeHwnd())
	{
		CRect rc;
		GetClientRect(rc);
		m_wndPalette.MoveWindow(0,0,cx,rc.Height()/3);
	}
	
}

int CMapEditorView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	m_pInfoDlg = new CInformationDlg;
	m_pInfoDlg->Create(IDD_INFORMATION);
	m_pInfoDlg->MoveWindow(0,0,169,590,TRUE);
	m_pInfoDlg->SetWindowPos(&wndTopMost,0,0,169,500,SWP_NOSIZE); //Always on top...
	cBlue = 0;
	cRed = 0;
	cGreen = 0;
	m_nXPitch = 1;
	m_nYPitch = 1;
	bImageCut = FALSE;

	///////////////////////////////////////////////////
	
	return 0;
}

void CMapEditorView::PostNcDestroy() 
{
	// TODO: Add your specialized code here and/or call the base class
	if (bImageCut == TRUE)
	{
		m_pInfoDlg->DeleteArray();
		delete[] bMark;
		delete[] pCellData;
	}

	delete m_pInfoDlg;
	
	CFormView::PostNcDestroy();
}

void CMapEditorView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CPoint ptt;
	ptt = this->GetScrollPosition();

	int nMouseOriginX = 0, nMouseOriginY = 0; //initialize of coordinate X,Y
	int nEndX = 0, nEndY = 0;
	int xx, yy;
	xx = ( point.x + ptt.x ) /m_nXPitch;
	yy = ( point.y + ptt.y ) / m_nYPitch;

	CRect rect; 

	int nc = GetCount(xx, yy);
	if ( (bImageCut == TRUE) && (bMark[nc] == TRUE) )
	{
		rect.left = xx*m_nXPitch;
		rect.top = yy*m_nYPitch;
		rect.right = rect.left+m_nXPitch;
		rect.bottom = rect.top+m_nYPitch;

		InvalidateRect(rect);
		bMark[nc] = FALSE;
		m_pInfoDlg->SetCount(nc);
	}
	if (point.x > nImageSizeWidth) 
	{
		MessageBox(_T("좌표가 영역밖으로 벗어났습니다"),_T("경고"),MB_ICONEXCLAMATION);
		return;
	}
	if (nFlags == 5) 
	{
		MessageBox("ALT");
		this->SendMessage(WM_PAINT);
		return;
	}
	
	if ( (nFlags == 9) && (bImageCut == TRUE) ) 
	{
		//control key가 같이 눌렸을때 처리할 구문.
		m_pInfoDlg->SetPoint(TRUE,xx, yy);
		m_pInfoDlg->SetPoint(FALSE, xx, yy);

		int xr, yr;
		xr = (point.x / m_nXPitch) * m_nXPitch;
		yr = (point.y / m_nYPitch) * m_nYPitch;
		
		CClientDC dc(this);
		CDC memDC;

		memDC.CreateCompatibleDC (&dc);

		CBitmap bitmap;
		bitmap.LoadBitmap(IDB_MARK_RED);

		memDC.SelectObject(&bitmap);
		dc.BitBlt (xr,yr,m_nXPitch-1,m_nYPitch-1,&memDC,0,0,SRCCOPY);
		
		int nCount;
		nCount = GetCount(xx, yy);
		if (bMark[nCount] == FALSE)
			{
				bMark[nCount] = TRUE;
				flagCount += 1;
			}
		m_pInfoDlg->SetCount(nCount);
		return;
	}
/*	else 
	if (bImageCut == TRUE) //이미지를 로딩했으면 트랙커를 작동시킴.
	{
		if (m_tracker.TrackRubberBand(this, point, TRUE))
		{    //사각형이 그려졌으면 선택된 영역의 이미지 좌표출력.
			CPoint p1,p2;
			rect = m_tracker.m_rect;
			Invalidate();
			nMouseOriginX = rect.left/m_nXPitch; //시작점
			nMouseOriginY = rect.top/m_nYPitch;
			
			nEndX = rect.right/m_nXPitch;   //끝점
			nEndY = rect.bottom/m_nYPitch;
	
			if (nMouseOriginX < 0 || nMouseOriginY < 0 || nEndX < 0 || nEndY < 0) 
			// 0보다 작은 점이 있으면 현재 좌표로 설정
			{
				m_pInfoDlg->SetPoint(TRUE, point.x, point.y);
				m_pInfoDlg->SetPoint(FALSE, point.x, point.y);
			}
			else if (nMouseOriginX > nEndX) //끝점이 시작점보다 작으면 바꿔줌.
			{
				m_pInfoDlg->SetPoint(FALSE,nMouseOriginX, nMouseOriginY);
				m_pInfoDlg->SetPoint(TRUE, nEndX, nEndY);
			}
			else //트래커 사각형이 그려지지 않았으면 현재 좌표 설정.
			{
				m_pInfoDlg->SetPoint(TRUE, nMouseOriginX, nMouseOriginY);
				m_pInfoDlg->SetPoint(FALSE, nEndX, nEndY);
			}
		}
*/
	else   
	{
		// 트래커가 그려지지 않았으면 현재 좌표 출력
		m_pInfoDlg->SetPoint(TRUE, xx, yy);
		m_pInfoDlg->SetPoint(FALSE, xx, yy);
	}
	
	CFormView::OnLButtonDown(nFlags, point);
}

void CMapEditorView::OnCut() 
{
//	int red, green, blue;
	CCutDlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		bImageLoad = TRUE;

		m_nXPitch = dlg.GetXPitch();// --+ 잘라지는 간격 
		m_nYPitch = dlg.GetYPitch();// --+
		
		cRed = dlg.GetColorRed();    // 색상 얻음.
		cGreen = dlg.GetColorGreen(); //
		cBlue = dlg.GetColorBlue();   //

		m_pInfoDlg->SetPitch(m_nXPitch, m_nYPitch); //입력한 간격값 전달.
		
		// 입력 다이얼로그 활성화....
		m_pInfoDlg->GetDlgItem(IDC_EDIT_ATT_HEIGHT)->EnableWindow(TRUE);
		m_pInfoDlg->GetDlgItem(IDC_EDIT_ATT_SLOPE)->EnableWindow(TRUE);
		m_pInfoDlg->GetDlgItem(IDC_EDIT_ATT_ATT)->EnableWindow(TRUE);
		m_pInfoDlg->GetDlgItem(IDC_EDIT_ATT_DIR_X)->EnableWindow(TRUE);
		m_pInfoDlg->GetDlgItem(IDC_EDIT_ATT_DIR_Y)->EnableWindow(TRUE);
		m_pInfoDlg->GetDlgItem(IDC_BUTTON_INPUT)->EnableWindow(TRUE);
		m_pInfoDlg->GetDlgItem(IDC_EDIT_AX)->EnableWindow(TRUE);
		m_pInfoDlg->GetDlgItem(IDC_EDIT_AY)->EnableWindow(TRUE);
		m_pInfoDlg->GetDlgItem(IDC_EDIT_BX)->EnableWindow(TRUE);
		m_pInfoDlg->GetDlgItem(IDC_EDIT_BY)->EnableWindow(TRUE);
		m_pInfoDlg->GetDlgItem(IDC_EDIT_HX)->EnableWindow(TRUE);
		m_pInfoDlg->GetDlgItem(IDC_EDIT_HY)->EnableWindow(TRUE); 
		m_pInfoDlg->GetDlgItem(IDC_BUTTON_POSITION)->EnableWindow(TRUE);
		m_pInfoDlg->GetDlgItem(IDC_EDIT_ATT_HEIGHT)->SetFocus(); //높이에 포커스.
		
		nArraySize = ( nImageSizeWidth / m_nXPitch ) * ( nImageSizeHeight / m_nYPitch );
		bMark = new BOOL[nArraySize];
		for (int z=0; z < nArraySize; z++)
		{
			bMark[z] = FALSE;
		}

		m_pInfoDlg->InitArray(m_nXPitch, m_nYPitch); //클래스 배열 초기화
		                                             // 데이터 저장용...		
		int nSize;
		nSize = (nImageSizeWidth / m_nXPitch) * (nImageSizeHeight / m_nYPitch);
		pCellData = new CCellData[nSize];  //임시 클래스 배열 초기화
		for (int j=0; j<nSize; j++)        // 나중에 저장할때 CInformationDlg에 있는
		{                                  // 클래스에서 복사해올때 씀.
			pCellData[j].SetAttributes(FALSE,_T("0"),_T("0"),_T("0")_T("0")_T("0"),_T("0"),_T("0"));
			// 배열 초기화 ..
		}

		Invalidate();  //화면 리플래쉬.
	}

}

void CMapEditorView::OnMouseMove(UINT nFlags, CPoint point) 
{
	int xx, yy;
	xx = yy = 0;

	if (nFlags == 9)
	{
		xx = (point.x/m_nXPitch) * m_nXPitch;
		yy = (point.y/m_nYPitch) * m_nYPitch;
		
		CClientDC dc(this);
		CDC memDC;

		memDC.CreateCompatibleDC (&dc);

		CBitmap bitmap;
		bitmap.LoadBitmap(IDB_MARK_RED);

		memDC.SelectObject(&bitmap);
		dc.BitBlt (xx,yy,m_nXPitch-1,m_nYPitch-1,&memDC,0,0,SRCCOPY);

		int nCount;
		nCount = GetCount(point.x/m_nXPitch, point.y/m_nYPitch);
	
		if (bMark[nCount] == FALSE)
		{
			bMark[nCount] = TRUE;
			flagCount += 1;
		}

		m_pInfoDlg->SetCount(nCount);
	}

	// 마우스 이동시 좌표 출력.
	CString X, Y;   
	X.Format("%d", point.x+nScrollX);
	Y.Format("%d", point.y+nScrollY);

	m_pInfoDlg->m_PointX=X;
	m_pInfoDlg->m_PointY=Y;
	
	m_pInfoDlg->SetDlgItemText(IDC_POINT_X, X);
	m_pInfoDlg->SetDlgItemText(IDC_POINT_Y, Y);

	CFormView::OnMouseMove(nFlags, point);
}

void CMapEditorView::SetDrawLinePitch(int pitchX, int pitchY, int Red, int Green, int Blue)
{
	int cWidth = 0, cHeight = 0;
	int xp=0, yp=0;
	xp = nImageSizeWidth / pitchX;  // 그어지는 라인의 총 갯수.
 	yp = nImageSizeHeight / pitchY; //

	CRect rect;
	GetClientRect(rect);
	cWidth = rect.right;
	cHeight = rect.bottom;

	CClientDC dc(this);
	CPen pen;
	CPen *pOldPen;
	pen.CreatePen(PS_SOLID, 1, RGB(Red, Green, Blue));
	pOldPen = dc.SelectObject(&pen);
	
	dc.MoveTo(0,0);

	for (int i=1; i<=xp; i++)
	{
		dc.MoveTo(pitchX*i, 0);
		dc.LineTo(pitchX*i, nImageSizeHeight+15);
	}

	dc.MoveTo(0,0);
	for (i=1; i<=yp; i++)
	{
		dc.MoveTo(0, pitchY*i);
		dc.LineTo(nImageSizeWidth+15, pitchY*i);
	}
}


BOOL CMapEditorView::SetDrawLinePitch(BOOL bFlags, int pitchX, int pitchY, int Red, int Green, int Blue)
{
	// 간격별로 라인 그림. 
	if (bFlags == FALSE)
	{
		return FALSE;
	}
		int cWidth = 0, cHeight = 0;
	int xp=0, yp=0;
	xp = nImageSizeWidth / pitchX;  // 그어지는 라인의 총 갯수.
 	yp = nImageSizeHeight / pitchY; //

	CRect rect;
	GetClientRect(rect);
	cWidth = rect.right;
	cHeight = rect.bottom;

	CClientDC dc(this);
	CPen pen;
	CPen *pOldPen;
	pen.CreatePen(PS_SOLID, 1, RGB(Red, Green, Blue));
	pOldPen = dc.SelectObject(&pen);
	
	dc.MoveTo(0,0);

	for (int i=1; i<=xp; i++)
	{
		dc.MoveTo(pitchX*i, 0);
		dc.LineTo(pitchX*i, nImageSizeHeight+15);
	}

	dc.MoveTo(0,0);
	for (i=1; i<=yp; i++)
	{
		dc.MoveTo(0, pitchY*i);
		dc.LineTo(nImageSizeWidth+15, pitchY*i);
	}
	return TRUE;
}

int CMapEditorView::GetCount(int x, int y)
{
	// 좌표에 따라 분류되는 이미지 일련번호.
	int Count;
	Count = ( (nImageSizeWidth / m_nXPitch) * y ) + x;

	return Count;
}

void CMapEditorView::OnFileSaveAs() 
{
	// 파일저장.
	// CInformationDlg에 있는 함수에서 CCellData의 GetAtt를 호출
	// return값은 CString
	CString strData, strPosition;
	strData = m_pInfoDlg->GetArray();
//	strPosition = m_pInfoDlg->GetPosition();

	CStdioFile file;
	CFileDialog dlg(FALSE);
	if (dlg.DoModal() == IDOK)
	{
		file.Open(dlg.GetPathName(), CFile::modeCreate|CFile::modeWrite);
//		file.WriteString(strPosition);
		file.WriteString(strData);
		file.Close();
	}

	MessageBox("저장완료", "확인");

}

void CMapEditorView::OnInvalidate() 
{
	// 화면 리플래시
	// 마킹한 부분 삭제됨.
	Invalidate();	
}



void CMapEditorView::SaveTemp()
{
	// Not Used
	CStdioFile file;
	file.Open(_T("\\temp.dat"),CFile::modeCreate|CFile::modeWrite);
	CString strCount, strData, strWrite;
	strCount.Format("%d",flagCount);
	file.WriteString(strCount);
	
	for (int i=0; i<nArraySize; i++)
	{
		if (bMark[i] == TRUE)
		{
			strData = strWrite = _T("");
			strData.Format("%d", i);
			strWrite = strData + "\n";
			file.WriteString(strWrite);
		}
	}

	file.Close();
}

void CMapEditorView::OnViewHeight() 
{
	// 툴바의 높이 버튼 누르면 높이가 저장된 셀 출력.

	int xx, yy;

	CString temp;
	CClientDC dc(this);
	CDC memDC;

	memDC.CreateCompatibleDC (&dc);

	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_MARK_HEIGHT);

	memDC.SelectObject(&bitmap);
	for (int i=0; i<nArraySize; i++)
	{
		temp = m_pInfoDlg->GetData(i,1);
		if (! ( (temp == "0") || (temp == "00") || (temp == "000") || (temp == "") )) 
		{
			int T = (nImageSizeWidth / m_nXPitch);
			xx = (i % T)*m_nXPitch;
			yy = (i / T)*m_nYPitch;
			
			dc.BitBlt (xx,yy,m_nXPitch-1,m_nYPitch-1,&memDC,0,0,SRCCOPY);
		}
	}

}

void CMapEditorView::OnViewSlope() 
{
	// 툴바의 높이 버튼 누르면 기울기가 저장된 셀 출력.

	int xx, yy;

	CString temp;
	CClientDC dc(this);
	CDC memDC;

	memDC.CreateCompatibleDC (&dc);

	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_MARK_SLOPE);

	memDC.SelectObject(&bitmap);
	for (int i=0; i<nArraySize; i++)
	{
		temp = m_pInfoDlg->GetData(i,2);
		if (! ( (temp == "0") || (temp == "00") || (temp == "000") || (temp == "") )) 
		{
			int T = (nImageSizeWidth / m_nXPitch);
			xx = (i % T)*m_nXPitch;
			yy = (i / T)*m_nYPitch;
			
			dc.BitBlt (xx,yy,m_nXPitch-1,m_nYPitch-1,&memDC,0,0,SRCCOPY);
		}
	}
}

void CMapEditorView::OnViewGround() 
{
	// 툴바의 높이 버튼 누르면 속성이 저장된 셀 출력.

	int xx, yy;

	CString temp;
	CClientDC dc(this);
	CDC memDC;

	memDC.CreateCompatibleDC (&dc);

	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_MARK_GROUND);

	memDC.SelectObject(&bitmap);
	for (int i=0; i<nArraySize; i++)
	{
		temp = m_pInfoDlg->GetData(i,3);
		if (! ( (temp == "0") || (temp == "00") || (temp == "000") || (temp == "") )) 
		{
			int T = (nImageSizeWidth / m_nXPitch);
			xx = (i % T)*m_nXPitch;
			yy = (i / T)*m_nYPitch;
			
			dc.BitBlt (xx,yy,m_nXPitch-1,m_nYPitch-1,&memDC,0,0,SRCCOPY);
		}
	}
	
}

void CMapEditorView::OnViewDirx() 
{
	// 툴바의 높이 버튼 누르면 X값이 저장된 셀 출력.

	int xx, yy;

	CString temp;
	CClientDC dc(this);
	CDC memDC;

	memDC.CreateCompatibleDC (&dc);

	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_MARK_DIRX);

	memDC.SelectObject(&bitmap);
	for (int i=0; i<nArraySize; i++)
	{
		temp = m_pInfoDlg->GetData(i,4);
		if (! (temp == "" )) 
		{
			int T = (nImageSizeWidth / m_nXPitch);
			xx = (i % T)*m_nXPitch;
			yy = (i / T)*m_nYPitch;
			
			dc.BitBlt (xx,yy,m_nXPitch-1,m_nYPitch-1,&memDC,0,0,SRCCOPY);
		}
	}
}

void CMapEditorView::OnViewDiry() 
{
	// 툴바의 높이 버튼 누르면 Y값이  저장된 셀 출력.

	int xx, yy;

	CString temp;
	CClientDC dc(this);
	CDC memDC;

	memDC.CreateCompatibleDC (&dc);

	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_MARK_DIRY);

	memDC.SelectObject(&bitmap);
	for (int i=0; i<nArraySize; i++)
	{
		temp = m_pInfoDlg->GetData(i,5);
		if (! ( temp == "" )) 
		{
			int T = (nImageSizeWidth / m_nXPitch);
			xx = (i % T)*m_nXPitch;
			yy = (i / T)*m_nYPitch;
			
			dc.BitBlt (xx,yy,m_nXPitch-1,m_nYPitch-1,&memDC,0,0,SRCCOPY);
		}
	}
	
}

void CMapEditorView::DrawImage()
{
	BeginWaitCursor();
//	Invalidate();
	CClientDC pDC(this);
	m_DibFile.SetSystemPalette(&pDC);
	m_DibFile.UsePalette(&pDC);
	CSize sizeFileDib = m_DibFile.GetDimensions();
	nImageSizeWidth = sizeFileDib.cx;  //이미지 가로 사이즈
	nImageSizeHeight = sizeFileDib.cy; //이미지 세로 사이즈
	m_pInfoDlg->SetImageSize(nImageSizeWidth, nImageSizeHeight); //다이얼로그에 이미지 사이즈 전달.
	
	CRect rect;
	GetClientRect(&rect);
	int ncx, ncy;
	ncx = nImageSizeWidth - rect.Width();
	ncy = nImageSizeHeight - rect.Height();

	m_DibFile.Draw(&pDC, CPoint(0, 0), sizeFileDib);

	EndWaitCursor();
//	SetScrollSizes(MM_TEXT, sizeTotal, sizeTotal, sizeLine);

	/////////////////////////////////////
//	CMapEditorDoc* pDoc = GetDocument();
//	ASSERT_VALID(pDoc);
//	m_tracker.Draw(pDC);
//	InvalidateRect(&rect);
	//////////////////////////////////////////////////////////////
	SetDrawLinePitch(bImageLoad, m_nXPitch, m_nYPitch, cRed, cGreen, cBlue);
}


BOOL CMapEditorView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
	// TODO: Add your message handler code here and/or call default
	return FALSE;	
//	return CFormView::OnMouseWheel(nFlags, zDelta, pt);
}

BOOL CMapEditorView::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if (pMsg->message == WM_MOUSEWHEEL)
	{
		return 0;
	}

	return CFormView::PreTranslateMessage(pMsg);
}

void CMapEditorView::OnRButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CPoint po;
	po = GetScrollPosition();
	CString mm;
	mm.Format(_T("%d %d"), po.x, po.y);
	MessageBox(mm);
 
	CFormView::OnRButtonUp(nFlags, point);
}

void CMapEditorView::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	if (nSBCode == SB_ENDSCROLL) Invalidate();

	CFormView::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CMapEditorView::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	if (nSBCode == SB_ENDSCROLL ) Invalidate();
	CFormView::OnHScroll(nSBCode, nPos, pScrollBar);
}
