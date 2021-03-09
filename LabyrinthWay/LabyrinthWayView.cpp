// LabyrinthWayView.cpp : implementation of the CLabyrinthWayView class
//

#include "stdafx.h"
#include "LabyrinthWay.h"

#include "LabyrinthWayDoc.h"
#include "LabyrinthWayView.h"
#include "WaitDialog.h"
#include "HelpDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLabyrinthWayView

IMPLEMENT_DYNCREATE(CLabyrinthWayView, CScrollView)

BEGIN_MESSAGE_MAP(CLabyrinthWayView, CScrollView)
	//{{AFX_MSG_MAP(CLabyrinthWayView)
	ON_WM_CREATE()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	ON_WM_MOUSEWHEEL()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_FILE_SAVE_AS, OnFileSaveAs)
	ON_WM_LBUTTONUP()
	ON_COMMAND(IDM_DATA_FILE_OPEN, OnDataFileOpen)
	ON_COMMAND(IDM_DIALOG_HELP, OnDialogHelp)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLabyrinthWayView construction/destruction

CLabyrinthWayView::CLabyrinthWayView()
{
	// TODO: add construction code here
	// 변수 초기화
	m_nImageSizeWidth = 1;
	m_nImageSizeHeight = 1;
	m_nXPitch = 1;
	m_nYPitch = 1;

	m_pInfoDlg = NULL;
//	m_CutDlg = NULL;

	m_nScrollPoint.x = 0;
	m_nScrollPoint.y = 0;

	m_bSaveData = FALSE; //데이터가 CInformationDlg에 저장이 되었는지 확인하는 플래그
	m_bLoadTextFile = FALSE; // 데이타가 저장된 파일이 로드 되었는지 확인하는 플래그
	bViewArrayCreated = false;
}

CLabyrinthWayView::~CLabyrinthWayView()
{
}

BOOL CLabyrinthWayView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CLabyrinthWayView drawing

void CLabyrinthWayView::OnDraw(CDC* pDC)
{
	CLabyrinthWayDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	///////////////////////////////////////////
	// 스크롤된 부분의 좌표 재설정
	m_nScrollPoint = GetScrollPosition();
	
	///////////////////////////////////////////
	// 여기서부터...
	BeginWaitCursor();

	CSize sizeFileDib = m_DibFile.GetDimensions();

	m_nImageSizeWidth = sizeFileDib.cx;
	m_nImageSizeHeight = sizeFileDib.cy;

	CSize sizeTotal (m_nImageSizeWidth, m_nImageSizeHeight);
	CSize sizeArrow = CSize(m_nXPitch, m_nYPitch);

	CRect rect;
	GetClientRect (&rect);
	m_DibFile.Draw(pDC, CPoint (0,0), sizeFileDib);

	EndWaitCursor();
	// 여기까지가...이것저것.. 
	//////////////////////////////////////////////
	
	// 스크롤빠......
	SetScrollSizes (MM_TEXT, sizeTotal, sizeTotal, sizeArrow);

	// 선긋기
	DrawLineByPitch(m_nXPitch, m_nYPitch, m_cColor);

	//////////////////////////////////////////
	// 화면이 갱신될때마다 마킹된 부분을 검색한뒤 다시 그려줌
	if (bImageLoad == TRUE)
	{
		int temp;  //셀의 갯수
		temp = (m_nImageSizeWidth / m_nXPitch) * (m_nImageSizeHeight / m_nYPitch);
		for (int i=0; i<temp; i++)
		{
			if (m_bMark[i] == TRUE)
			{
				//	this->DrawMark(IDB_MARK_RED, i);
				// 스크롤링된 지역의 셀 번호를 받아서
				// 셀번호의 좌표를 얻은뒤 (전체 이미지크기에서의 좌표)
				// 현재 클라이언트 영역의 좌표로 변환한뒤 리마킹해줌
	
				////////////////////////////////////////
				// 클라이언트 크기
				CRect rect;
				GetClientRect(&rect);
				int clientWidth, clientHeight;
				clientWidth = rect.Width();
				clientHeight = rect.Height();
	
				// 스크롤된 좌표를 얻음..
				CPoint tempPoint;   
				int scrollWidth, scrollHeight;
				tempPoint = GetScrollPosition();
				scrollWidth  = clientWidth  + tempPoint.x;
				scrollHeight = clientHeight + tempPoint.y;

				//////////////////////////////////////////////////
				// 셀번호를 좌표로 변환
				CParser parser;
				POINT point;
				point = parser.NumberToPoint(i, m_nImageSizeWidth, m_nXPitch, m_nYPitch);
				int xx, yy;
				xx = point.x * m_nXPitch;
				yy = point.y * m_nYPitch;
	
				///////////////////////////////////////////
				// 만일 해당하는 셀의 좌표가 현재 클라이언트좌표+스크롤좌표 보다 크면
				// 현재 뷰의 영역안에 없는 것이므로 그냥 리턴함.
		//		if (! ( (xx > scrollWidth) && (yy > scrollHeight) ) )
		//		{
					// 스크롤 좌표를 현재 스크린 좌표로 바꿔줌..
					int x, y;
					x = point.x - m_nScrollPoint.x;
					y = point.y - m_nScrollPoint.y;

					CClientDC dc(this);
					CDC memDC;

					memDC.CreateCompatibleDC (&dc);

					CBitmap bitmap;
					bitmap.LoadBitmap(IDB_MARK_RED);

					memDC.SelectObject (&bitmap);
					dc.BitBlt (x, y, m_nXPitch-1, m_nYPitch-1, &memDC, 0, 0, SRCCOPY);

		//		} // end if
			} // end if
		} // end for
	} // end if

	// 위의 부분은 View에서만 이루어지는 일이고, 만일 CInformationDlg에서 
	// 데이터가 입력되면 m_bMarkp[ 배열의 InitArrayByView() 함수에서 모두
	// FALSE로 초기화 되며, CInformationDlg의 m_pbMarkArray[]배열에서
	// 값을 받아와 만을 TRUE이면 파란색으로 점을 다시 그려줌.
	if ( (bImageLoad == TRUE) && ( (m_bSaveData == TRUE) || (m_bLoadTextFile == TRUE) ) )
	{
		int temp;  //셀의 갯수
		temp = (m_nImageSizeWidth / m_nXPitch) * (m_nImageSizeHeight / m_nYPitch);
		for (int i=0; i<temp; i++)
		{
			if (m_pInfoDlg->m_pbMarkArray[i] == TRUE)
			{
				//	this->DrawMark(IDB_MARK_RED, i);
				// 스크롤링된 지역의 셀 번호를 받아서
				// 셀번호의 좌표를 얻은뒤 (전체 이미지크기에서의 좌표)
				// 현재 클라이언트 영역의 좌표로 변환한뒤 리마킹해줌
	
				////////////////////////////////////////
				// 클라이언트 크기
				CRect rect;
				GetClientRect(&rect);
				int clientWidth, clientHeight;
				clientWidth = rect.Width();
				clientHeight = rect.Height();
	
				// 스크롤된 좌표를 얻음..
				CPoint tempPoint;   
				int scrollWidth, scrollHeight;
				tempPoint = GetScrollPosition();
				scrollWidth  = clientWidth  + tempPoint.x;
				scrollHeight = clientHeight + tempPoint.y;

				//////////////////////////////////////////////////
				// 셀번호를 좌표로 변환
				CParser parser;
				POINT point;
				point = parser.NumberToPoint(i, m_nImageSizeWidth, m_nXPitch, m_nYPitch);
				int xx, yy;
				xx = point.x * m_nXPitch;
				yy = point.y * m_nYPitch;
	
				///////////////////////////////////////////
				// 만일 해당하는 셀의 좌표가 현재 클라이언트좌표+스크롤좌표 보다 크면
				// 현재 뷰의 영역안에 없는 것이므로 그냥 리턴함.
		//		if (! ( (xx > scrollWidth) && (yy > scrollHeight) ) )
		//		{
					// 스크롤 좌표를 현재 스크린 좌표로 바꿔줌..
					int x, y;
					x = point.x - m_nScrollPoint.x;
					y = point.y - m_nScrollPoint.y;

					CClientDC dc(this);
					CDC memDC;

					memDC.CreateCompatibleDC (&dc);

					CBitmap bitmap;
					bitmap.LoadBitmap(IDB_MARK_BLUE);

					memDC.SelectObject (&bitmap);
					dc.BitBlt (x, y, m_nXPitch-1, m_nYPitch-1, &memDC, 0, 0, SRCCOPY);

		//		} // end if
			} // end if
		} // end for
	} // end if
}

void CLabyrinthWayView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	// scrollbar setting
	CSize sizeTotal(m_nImageSizeWidth, m_nImageSizeHeight);
	CSize sizeLine = CSize(sizeTotal.cx / m_nXPitch, sizeTotal.cy / m_nYPitch);
	
	SetScrollSizes(MM_TEXT, sizeTotal, sizeTotal, sizeLine);
}

/////////////////////////////////////////////////////////////////////////////
// CLabyrinthWayView printing

BOOL CLabyrinthWayView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLabyrinthWayView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLabyrinthWayView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CLabyrinthWayView diagnostics

#ifdef _DEBUG
void CLabyrinthWayView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CLabyrinthWayView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CLabyrinthWayDoc* CLabyrinthWayView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLabyrinthWayDoc)));
	return (CLabyrinthWayDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLabyrinthWayView message handlers

int CLabyrinthWayView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CScrollView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// Modaless Dialog
	m_pInfoDlg = new CInformationDlg;  
	m_pInfoDlg->Create(IDD_INFORMATION);
//	m_pWaitDlg->MoveWindow(0, 0, 300, 300, TRUE);

	// Always on top
	m_pInfoDlg->SetWindowPos (&wndTopMost, 0, 0, 169, 500, SWP_NOSIZE);

	return 0;
}

void CLabyrinthWayView::OnMouseMove(UINT nFlags, CPoint point) 
{
	int xx=0, yy =0;
	CPoint pt;
	pt = GetScrollPosition();
	xx = (point.x / m_nXPitch);
	yy = (point.y / m_nYPitch);
	
	int nNumber; 
	nNumber = GetImageNumber(point.x + pt.x, point.y + pt.y); // 셀 번호를 구한뒤..
	
	// 컨트롤키가 눌렸으면 마킹해줌..
	if (nFlags == 9)
	{	
	
		if (m_bMark[nNumber] == FALSE)  // m_bMark[셀번호]가 FALSE이면..
		{
			m_bMark[nNumber] = TRUE; // TRUE로 바꿔줌..
//			m_pInfoDlg->m_pbMarkArray[nNumber] = 1;
	
		/////////////////////////////////////////////////////
		int x,y;
		x = ( point.x / m_nXPitch ) * m_nXPitch;
		y = ( point.y / m_nYPitch ) * m_nYPitch;

		CClientDC dc(this);
		CDC memDC;

		memDC.CreateCompatibleDC (&dc); 

		CBitmap bitmap;
		bitmap.LoadBitmap(IDB_MARK_RED);

		memDC.SelectObject (&bitmap);
		dc.BitBlt (x, y, m_nXPitch-1, m_nYPitch-1, &memDC, 0, 0, SRCCOPY);
						/////////////////////////////////////
		// 다이얼로그에 좌표 보내줌..
		m_pInfoDlg->SetMousePoint(point, CPoint(xx, yy), nNumber); 
		} // end if
	} // end if

	// 다이얼로그에 좌표 계속 뿌려줌
	m_pInfoDlg->SetMousePoint (CPoint(point.x + pt.x , point.y + pt.y), CPoint(xx, yy), nNumber);

	CScrollView::OnMouseMove(nFlags, point);


}

void CLabyrinthWayView::PostNcDestroy() 
{
	m_pInfoDlg->DeletePostNcDestroy(); //CInformationDlg의 delete호출
	                                   // 객체가 죽기 전에 먼저 죽임..-.-;;
	                                   // 사실 별 관계 없어보임..
	delete m_pInfoDlg; // CInformationDlg 객체 삭제

	// 메모리 해제.........
	m_DibFile.Empty();
	if (bViewArrayCreated == true)
	{
		delete [] m_bMark;
		delete [] m_pCellData;
		bViewArrayCreated = false;
	}
	

//	if (m_bLoadTextFile == TRUE) delete[] celltype;

	CScrollView::PostNcDestroy();
}

void CLabyrinthWayView::OnCutDialog()
{
	// 잘라지는 픽셀의 값을 받는 다이얼로그 띄움.
	CPointInt pointInt;

	if (m_CutDlg.DoModal() == IDOK)
	{
		m_cColor = m_CutDlg.GetColor();
		pointInt = m_CutDlg.GetPointInt();
	}  // end if
	// 임시로 가로폭과 세로폭을 나눠 떨어지는지 검사.
	// 별로 쓸모 없음...왜 만들었는지 모름...

	int tempX, tempY; 
	tempX = m_nImageSizeWidth % pointInt.x;
	tempY = m_nImageSizeHeight % pointInt.y;

	if (! (tempX == 0) ) 
	{
		MessageBox(_T("가로폭이 나눠 떨어지지 않습니다. 다시입력하세요"), 
			_T("Error"));
		this->OnCutDialog();
	} // end if
	else
	if ( ! (tempY == 0) )
	{
		MessageBox (_T("세로폭이 나눠 떨어지지 않습니다. 다시 입력하세요"),
			_T("Error"));
		this->OnCutDialog();
	} // end if
	else
	{
		m_nXPitch = pointInt.x;
		m_nYPitch = pointInt.y;
	} // end else

	Invalidate();
}

void CLabyrinthWayView::OnFileOpen() 
{
	CFileDialog dlg(TRUE, "bmp", "*.bmp");

	if (dlg.DoModal() == IDOK)
	{
		CFile file;
		file.Open(dlg.GetPathName(), CFile::modeRead);
		if (m_DibFile.Read(&file) == TRUE)
		{
			Invalidate();
		} // end if
		CClientDC dc(this);
		m_DibFile.SetSystemPalette(&dc);
		OnCutDialog(); //이미지 자르는 다이얼로그 띄움
		this->SetFocus();
		bImageLoad = TRUE;
	} // end if
	else
	{
		if (dlg.DoModal() == IDCANCEL) return;
	}


	////////////////////////////////////////////
	// 사용할 동적배열들 생성
	int nArraySize;  // 배열 크기
	nArraySize = ( m_nImageSizeWidth / m_nXPitch) * ( m_nImageSizeHeight / m_nYPitch );

	// 플래그용 동적 배열 할당
	m_bMark = new BOOL [nArraySize];
	for (int i=0; i<nArraySize; i++)
	{
		// 배열 초기화
		m_bMark[i] = FALSE;
	}

	// CInformationDlg에서 사용할 배열 초기화
	m_pInfoDlg->InitArray(m_nImageSizeWidth, m_nImageSizeHeight, m_nXPitch, m_nYPitch);

	// 데이터가 저장되는 배열 초기화
	m_pCellData = new CCellData[nArraySize];
	bViewArrayCreated = true;  // 배열이 생성되었음을 알림..(PostNcDestroy()에서 사용)

	CCellType ct;
	ct.ctDecision = 0;
	ct.ctGround = 0;
	ct.ctNumber = 0;
	ct.ctTime = 0;

	for (i=0; i<nArraySize; i++)
	{
		// 배열 초기화
		m_pCellData->SetAttributes(TRUE, ct);
	}

	Invalidate();
}

BOOL CLabyrinthWayView::DrawLineByPitch(int pitchX, int pitchY, CColor color)
{
	// CColor 타입의 색상으로 라인을 그려줌.
	int cWidth = 0, cHeight = 0;
	int xp=0, yp=0;
	
	xp = m_nImageSizeWidth / pitchX;  // 그어지는 라인의 총 갯수.
 	yp = m_nImageSizeHeight / pitchY; //

	CRect rect;
	GetClientRect(rect);
	cWidth = rect.right;
	cHeight = rect.bottom;

	CClientDC dc(this);
	CPen pen;
	CPen *pOldPen;
	pen.CreatePen(PS_SOLID, 1, RGB(color.red, color.green, color.blue) );
	pOldPen = dc.SelectObject(&pen);
	
	dc.MoveTo(0,0);  // 원점으로 (0,0 이동

	for (int i=1; i<=xp; i++)
	{
		// 가로선 그음
		dc.MoveTo(pitchX*i, 0);   
		dc.LineTo(pitchX*i, m_nImageSizeHeight);
	}

	dc.MoveTo(0,0); // 다시 원점으로 이동 (0,0)
	for (i=1; i<=yp; i++)
	{
		// 세로선 그음
		dc.MoveTo(0, pitchY*i);
		dc.LineTo(m_nImageSizeWidth, pitchY*i); // 이미지보다 약간 크게 선을 그음
		                                        // 크게 안그음..원래 +15였음..
	}
	return TRUE;
}

void CLabyrinthWayView::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// 스크롤 막대기를 붙들고 스크롤이 끝나면 다시 그려줌..
	// 깜빡임이 좀 덜한것 같음...당연한 얘기....--;;

	if (nSBCode == SB_ENDSCROLL) Invalidate();
	m_nScrollPoint = GetScrollPosition(); // 스크롤된 좌표 재설정..
	CScrollView::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CLabyrinthWayView::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// 위와 동일
	// 주석다는게 코딩하는거보다 더 힘들다...
	if (nSBCode == SB_ENDSCROLL) Invalidate();
	m_nScrollPoint = GetScrollPosition(); // 스크롤된 부분의 좌표 재설정
	CScrollView::OnVScroll(nSBCode, nPos, pScrollBar);
}

BOOL CLabyrinthWayView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
	// 휠을 돌리면 다시 그려줌..
	// 휠 굴리다 걸리면 죽어 !! -_-+++
	Invalidate();	
	m_nScrollPoint = GetScrollPosition(); // 역지 좌표 재설정..
	return CScrollView::OnMouseWheel(nFlags, zDelta, pt);
}

void CLabyrinthWayView::OnRButtonUp(UINT nFlags, CPoint point) 
{
	// 오른쪽 버튼을 누르면 마우스 좌표에 스크롤링이 된 좌표까지
	// 계산해서 메시지 박스에 출력...
	// 그냥 테스트용 메시지 핸들러..
	CPoint po;
	po = GetScrollPosition();
	CString mm;
	mm.Format(_T("%d %d"), po.x, po.y);
	MessageBox(mm);
	CScrollView::OnRButtonUp(nFlags, point);
}

void CLabyrinthWayView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// 왼쪽 버튼을 누르면 빨강색 마킹을 하고, GetScrollPosition()으로
	// 스크롤된 만큼의 영역을 재계산 해서 출력하고 처리함
	
	// 마우스가 선택된 영역체크
	if (point.x > m_nImageSizeWidth) return;
	///////////////////////////////////////////////////
	///////////////////////////////////////////////////
	CPoint scrollPoint;
	scrollPoint = this->GetScrollPosition();

	int nMouseOriginX=0, nMouseOriginY=0;
	int nMouseEndX = 0, nMouseEndY = 0;

	int xx, yy;
	xx = (point.x + scrollPoint.x); // m_nXPitch;
	yy = (point.y + scrollPoint.y); // m_nYPitch;
	
	CRect rect;

	int number;
	number = GetImageNumber (xx, yy);

	if ( (bImageLoad == TRUE) && (m_bMark[number] == TRUE) ) 
	{
		// 이미지가 로딩되었고,
		// 이미 마킹이 되어 있다면 그부분의 영역을 다시 그려줌(지움).
		// 빨강색 마킹되어 있는 부분만..
	//	m_pInfoDlg->m_pbMarkArray[number] = FALSE;
		rect.left  = xx * m_nXPitch;
		rect.top   = yy * m_nYPitch;
		rect.right = rect.left + m_nXPitch;
		rect.bottom = rect.top + m_nYPitch;

		InvalidateRect(rect);
		m_bMark[number] = FALSE;
	} // end if

	if ( (bImageLoad == TRUE) && (m_pInfoDlg->m_pbMarkArray[number] == TRUE) )
	{
		// 파란색 (이미 데이터가 입력되어 있는 부분) 부분의 마킹영역을
		// 지워줌
		rect.left = xx * m_nXPitch;
		rect.top = yy * m_nYPitch;
		rect.right = rect.left + m_nXPitch;
		rect.bottom  = rect.top + m_nYPitch;
		
		m_pInfoDlg->m_pbMarkArray[number] = FALSE;
		InvalidateRect(rect);
	}
	
	// 컨트롤키가 눌렸으면 마킹해줌..
	if (nFlags == 9)
	{
		///////////////////////////////////////////////////////////////
		int x,y;
		x = ( xx / m_nXPitch ) * m_nXPitch;
		y = ( yy / m_nYPitch ) * m_nYPitch;

		CClientDC dc(this);
		CDC memDC;

		memDC.CreateCompatibleDC (&dc);

		CBitmap bitmap;
		bitmap.LoadBitmap(IDB_MARK_RED);

		memDC.SelectObject (&bitmap);
		dc.BitBlt (x, y, m_nXPitch-1, m_nYPitch-1, &memDC, 0, 0, SRCCOPY);
		/////////////////////////////////////////////////////////////////

		int nNumber; 
		nNumber = GetImageNumber(xx, yy); // 셀 번호를 구한뒤..
		if (m_bMark[nNumber] == FALSE)  // m_bMark[셀번호]가 FALSE이면..
		{
			m_bMark[nNumber] = TRUE; // TRUE로 바꿔줌..
//			m_pInfoDlg->m_pbMarkArray[nNumber] = 1;
		}
		// 다이얼로그에 좌표 보여줌..

		m_pInfoDlg->SetMousePoint(point, CPoint(xx, yy), nNumber); 

	}

//	Invalidate(FALSE);
	CScrollView::OnLButtonDown(nFlags, CPoint(xx, yy));
}

int CLabyrinthWayView::GetImageNumber(int x, int y)
{
	// 좌표에 따라 분류되는 이미지 번호
	// 클라이언트 영역의 마우스 좌표 + 스크롤된 좌표값이 x,y
	int Count;
	Count = ( (m_nImageSizeWidth / m_nXPitch) * (y/m_nYPitch ) + (x/m_nXPitch) );

	return Count;
}

void CLabyrinthWayView::DrawMark(int nBitmapID, CPoint markPoint)
{
	// 비트맵 ID와 좌표를 받아 각 셀에 마킹을 해줌
	// 아주 잘됨...-.-;;

	/////////////////////////////////////////////////////
	/////////////////////////////////////////////////////
	///// 사용안함 //////////////////////////////////////
	/////////////////////////////////////////////////////
	/////////////////////////////////////////////////////
	int x,y;
	x = ( markPoint.x / m_nXPitch ) * m_nXPitch;
	y = ( markPoint.y / m_nYPitch ) * m_nYPitch;

	CClientDC dc(this);
	CDC memDC;

	memDC.CreateCompatibleDC (&dc);

	CBitmap bitmap;
	bitmap.LoadBitmap(nBitmapID);

	memDC.SelectObject (&bitmap);
	dc.BitBlt (x, y, m_nXPitch-1, m_nYPitch-1, &memDC, 0, 0, SRCCOPY);
}

void CLabyrinthWayView::DrawMark(int nBitmapID, int nCellNumber)
{
	// 비트맵 ID와 셀번호를 받음
	// 스크롤링된 지역의 셀 번호를 받아서
	// 셀번호의 좌표를 얻은뒤 (전체 이미지크기에서의 좌표)
	// 현재 클라이언트 영역의 좌표로 변환한뒤 리마킹해줌
	/////////////////////////////////////////////////////
	/////////////////////////////////////////////////////
	///// 사용안함 //////////////////////////////////////
	/////////////////////////////////////////////////////
	/////////////////////////////////////////////////////
	////////////////////////////////////////
	// 클라이언트 크기
	CRect rect;
	GetClientRect(&rect);
	int clientWidth, clientHeight;
	clientWidth = rect.Width();
	clientHeight = rect.Height();
	
	// 스크롤된 좌표를 얻음..
	CPoint tempPoint;   
	int scrollWidth, scrollHeight;
	tempPoint = GetScrollPosition();
	scrollWidth  = clientWidth  + tempPoint.x;
	scrollHeight = clientHeight + tempPoint.y;

	//////////////////////////////////////////////////
	// 셀번호를 좌표로 변환
	CParser parser;
	POINT point;
	point = parser.NumberToPoint(nCellNumber, m_nImageSizeWidth, m_nXPitch, m_nYPitch);
	int xx, yy;
	xx = point.x * m_nXPitch;
	yy = point.y * m_nYPitch;
	
	///////////////////////////////////////////
	// 만일 해당하는 셀의 좌표가 현재 클라이언트좌표+스크롤좌표 보다 크면
	// 현재 뷰의 영역안에 없는 것이므로 그냥 리턴함.
	if (! ( (xx > scrollWidth) && (yy > scrollHeight) ) )
	{
		// 스크롤 좌표를 현재 스크린 좌표로 바꿔줌..
		int x, y;
		x = point.x - m_nScrollPoint.x;
		y = point.y - m_nScrollPoint.y;

		CClientDC dc(this);
		CDC memDC;

		memDC.CreateCompatibleDC (&dc);

		CBitmap bitmap;
		bitmap.LoadBitmap(nBitmapID);

		memDC.SelectObject (&bitmap);
		dc.BitBlt (x, y, m_nXPitch-1, m_nYPitch-1, &memDC, 0, 0, SRCCOPY);
	}
}

void CLabyrinthWayView::OnFileSaveAs() 
{
	CString strSaveData;
	
	CWaitDialog * pWaitDlg = new CWaitDialog;  //잠시 기다리라는 다이얼로그 출력
	pWaitDlg->Create(IDD_WAIT_DIALOG);

	strSaveData = m_pInfoDlg->GetData();
	delete pWaitDlg;

	CFileDialog dlg(FALSE);
	if (dlg.DoModal() == IDOK)
	{
		CStdioFile file;
		file.Open(dlg.GetFileName(), CFile::modeCreate|CFile::modeWrite);
		file.WriteString(strSaveData);
		file.Close();
	}

	MessageBox(_T("저장완료"), _T("확인"));
}



void CLabyrinthWayView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	Invalidate(TRUE);

	// CInformationDlg의 m_bMarkArray에 m_bMark의 값을 전달해줌..
/*
	int nArraySize;

	nArraySize = (m_nImageSizeWidth / m_nXPitch) + (m_nImageSizeHeight / m_nYPitch);
	
	for (int i=0; i<nArraySize; i++)
	{
		m_pInfoDlg->m_pbMarkArray[i] = m_bMark[i];
	}
*/	
	CScrollView::OnLButtonUp(nFlags, point);
}


void CLabyrinthWayView::InitMarkArrayByView()
{
	// 호출될때 m_bMark[] 배열의 모든 값을 초기화 시킴.

	int nSize = (m_nImageSizeWidth / m_nXPitch) * (m_nImageSizeHeight / m_nYPitch);

	for (int i=0; i<nSize; i++)
	{
		m_bMark[i] = FALSE;
	}

	m_bSaveData = TRUE;
}

void CLabyrinthWayView::SetInformationDlgArray()
{
	// CInformationDialog의 입력 버튼을 누르면 현재까지
	// m_bMark[]에 가지고 있던 값을 모조리 CInformationDlg의 m_bTempMark[]에 
	// 대입해줌...(TRUE일때만)

	int nSize = 0;
	nSize = (m_nImageSizeWidth / m_nXPitch) * (m_nImageSizeHeight / m_nYPitch);

	for (int i=0; i<nSize; i++)
	{
		if (m_bMark[i] == TRUE)
		{
			m_pInfoDlg->m_bTempMark[i] = m_bMark[i];
		}
	}

	CLabyrinthWayView::Invalidate();
	CLabyrinthWayView::SetFocus();
}

void CLabyrinthWayView::OnDataFileOpen() 
{
	// 이미 저장된 데이터 파일을 열어서 CInformationDlg의 m_bpMark[] 배열과
	// m_pCellData[]에 모조리 저장함..

	CFileDialog dlg(TRUE, "TXT", "TXT" );
	CString fileName;

	if (dlg.DoModal() == IDOK)
	{
		fileName = dlg.GetFileName();
		m_bLoadTextFile = TRUE;
	}

	CParser parser;
	CCellType * celltype;
	CCellData * celldata;

	celldata = parser.ParseFile( LPSTR(LPCTSTR(fileName)) );
	int nLineCount = parser.GetLineCount();
	int nSize = (m_nImageSizeWidth / m_nXPitch) * (m_nImageSizeHeight / m_nYPitch); // 셀의 갯수
	
	celltype = new CCellType [nSize];

	for (int i=0; i<nLineCount; i++)
	{
		celltype[i] = celldata[i].GetAttributes(); // 데이터 받은뒤...
		if (! ( (celltype[i].ctNumber == 9) && (celltype[i].ctDecision == 9) &&
			    (celltype[i].ctGround == 9) && (celltype[i].ctTime     == 9) ) )
		{
			m_pInfoDlg->m_pbMarkArray[(int)celltype[i].ctNumber] = TRUE;
			m_pInfoDlg->m_pCellData[(int)celltype[i].ctNumber].SetAttributes(TRUE, celltype[i]);
		} // end if
	} // end for

	delete [] celltype;

	Invalidate();
}

void CLabyrinthWayView::OnDialogHelp() 
{
	CHelpDialog dlg;
	if (dlg.DoModal() == IDOK) 
	{
	}
}

void CLabyrinthWayView::OnFileSave() 
{
	OnFileSaveAs();	
}
