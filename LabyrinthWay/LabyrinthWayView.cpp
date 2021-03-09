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
	// ���� �ʱ�ȭ
	m_nImageSizeWidth = 1;
	m_nImageSizeHeight = 1;
	m_nXPitch = 1;
	m_nYPitch = 1;

	m_pInfoDlg = NULL;
//	m_CutDlg = NULL;

	m_nScrollPoint.x = 0;
	m_nScrollPoint.y = 0;

	m_bSaveData = FALSE; //�����Ͱ� CInformationDlg�� ������ �Ǿ����� Ȯ���ϴ� �÷���
	m_bLoadTextFile = FALSE; // ����Ÿ�� ����� ������ �ε� �Ǿ����� Ȯ���ϴ� �÷���
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
	// ��ũ�ѵ� �κ��� ��ǥ �缳��
	m_nScrollPoint = GetScrollPosition();
	
	///////////////////////////////////////////
	// ���⼭����...
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
	// ���������...�̰�����.. 
	//////////////////////////////////////////////
	
	// ��ũ�Ѻ�......
	SetScrollSizes (MM_TEXT, sizeTotal, sizeTotal, sizeArrow);

	// ���߱�
	DrawLineByPitch(m_nXPitch, m_nYPitch, m_cColor);

	//////////////////////////////////////////
	// ȭ���� ���ŵɶ����� ��ŷ�� �κ��� �˻��ѵ� �ٽ� �׷���
	if (bImageLoad == TRUE)
	{
		int temp;  //���� ����
		temp = (m_nImageSizeWidth / m_nXPitch) * (m_nImageSizeHeight / m_nYPitch);
		for (int i=0; i<temp; i++)
		{
			if (m_bMark[i] == TRUE)
			{
				//	this->DrawMark(IDB_MARK_RED, i);
				// ��ũ�Ѹ��� ������ �� ��ȣ�� �޾Ƽ�
				// ����ȣ�� ��ǥ�� ������ (��ü �̹���ũ�⿡���� ��ǥ)
				// ���� Ŭ���̾�Ʈ ������ ��ǥ�� ��ȯ�ѵ� ����ŷ����
	
				////////////////////////////////////////
				// Ŭ���̾�Ʈ ũ��
				CRect rect;
				GetClientRect(&rect);
				int clientWidth, clientHeight;
				clientWidth = rect.Width();
				clientHeight = rect.Height();
	
				// ��ũ�ѵ� ��ǥ�� ����..
				CPoint tempPoint;   
				int scrollWidth, scrollHeight;
				tempPoint = GetScrollPosition();
				scrollWidth  = clientWidth  + tempPoint.x;
				scrollHeight = clientHeight + tempPoint.y;

				//////////////////////////////////////////////////
				// ����ȣ�� ��ǥ�� ��ȯ
				CParser parser;
				POINT point;
				point = parser.NumberToPoint(i, m_nImageSizeWidth, m_nXPitch, m_nYPitch);
				int xx, yy;
				xx = point.x * m_nXPitch;
				yy = point.y * m_nYPitch;
	
				///////////////////////////////////////////
				// ���� �ش��ϴ� ���� ��ǥ�� ���� Ŭ���̾�Ʈ��ǥ+��ũ����ǥ ���� ũ��
				// ���� ���� �����ȿ� ���� ���̹Ƿ� �׳� ������.
		//		if (! ( (xx > scrollWidth) && (yy > scrollHeight) ) )
		//		{
					// ��ũ�� ��ǥ�� ���� ��ũ�� ��ǥ�� �ٲ���..
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

	// ���� �κ��� View������ �̷������ ���̰�, ���� CInformationDlg���� 
	// �����Ͱ� �ԷµǸ� m_bMarkp[ �迭�� InitArrayByView() �Լ����� ���
	// FALSE�� �ʱ�ȭ �Ǹ�, CInformationDlg�� m_pbMarkArray[]�迭����
	// ���� �޾ƿ� ���� TRUE�̸� �Ķ������� ���� �ٽ� �׷���.
	if ( (bImageLoad == TRUE) && ( (m_bSaveData == TRUE) || (m_bLoadTextFile == TRUE) ) )
	{
		int temp;  //���� ����
		temp = (m_nImageSizeWidth / m_nXPitch) * (m_nImageSizeHeight / m_nYPitch);
		for (int i=0; i<temp; i++)
		{
			if (m_pInfoDlg->m_pbMarkArray[i] == TRUE)
			{
				//	this->DrawMark(IDB_MARK_RED, i);
				// ��ũ�Ѹ��� ������ �� ��ȣ�� �޾Ƽ�
				// ����ȣ�� ��ǥ�� ������ (��ü �̹���ũ�⿡���� ��ǥ)
				// ���� Ŭ���̾�Ʈ ������ ��ǥ�� ��ȯ�ѵ� ����ŷ����
	
				////////////////////////////////////////
				// Ŭ���̾�Ʈ ũ��
				CRect rect;
				GetClientRect(&rect);
				int clientWidth, clientHeight;
				clientWidth = rect.Width();
				clientHeight = rect.Height();
	
				// ��ũ�ѵ� ��ǥ�� ����..
				CPoint tempPoint;   
				int scrollWidth, scrollHeight;
				tempPoint = GetScrollPosition();
				scrollWidth  = clientWidth  + tempPoint.x;
				scrollHeight = clientHeight + tempPoint.y;

				//////////////////////////////////////////////////
				// ����ȣ�� ��ǥ�� ��ȯ
				CParser parser;
				POINT point;
				point = parser.NumberToPoint(i, m_nImageSizeWidth, m_nXPitch, m_nYPitch);
				int xx, yy;
				xx = point.x * m_nXPitch;
				yy = point.y * m_nYPitch;
	
				///////////////////////////////////////////
				// ���� �ش��ϴ� ���� ��ǥ�� ���� Ŭ���̾�Ʈ��ǥ+��ũ����ǥ ���� ũ��
				// ���� ���� �����ȿ� ���� ���̹Ƿ� �׳� ������.
		//		if (! ( (xx > scrollWidth) && (yy > scrollHeight) ) )
		//		{
					// ��ũ�� ��ǥ�� ���� ��ũ�� ��ǥ�� �ٲ���..
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
	nNumber = GetImageNumber(point.x + pt.x, point.y + pt.y); // �� ��ȣ�� ���ѵ�..
	
	// ��Ʈ��Ű�� �������� ��ŷ����..
	if (nFlags == 9)
	{	
	
		if (m_bMark[nNumber] == FALSE)  // m_bMark[����ȣ]�� FALSE�̸�..
		{
			m_bMark[nNumber] = TRUE; // TRUE�� �ٲ���..
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
		// ���̾�α׿� ��ǥ ������..
		m_pInfoDlg->SetMousePoint(point, CPoint(xx, yy), nNumber); 
		} // end if
	} // end if

	// ���̾�α׿� ��ǥ ��� �ѷ���
	m_pInfoDlg->SetMousePoint (CPoint(point.x + pt.x , point.y + pt.y), CPoint(xx, yy), nNumber);

	CScrollView::OnMouseMove(nFlags, point);


}

void CLabyrinthWayView::PostNcDestroy() 
{
	m_pInfoDlg->DeletePostNcDestroy(); //CInformationDlg�� deleteȣ��
	                                   // ��ü�� �ױ� ���� ���� ����..-.-;;
	                                   // ��� �� ���� �����..
	delete m_pInfoDlg; // CInformationDlg ��ü ����

	// �޸� ����.........
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
	// �߶����� �ȼ��� ���� �޴� ���̾�α� ���.
	CPointInt pointInt;

	if (m_CutDlg.DoModal() == IDOK)
	{
		m_cColor = m_CutDlg.GetColor();
		pointInt = m_CutDlg.GetPointInt();
	}  // end if
	// �ӽ÷� �������� �������� ���� ���������� �˻�.
	// ���� ���� ����...�� ��������� ��...

	int tempX, tempY; 
	tempX = m_nImageSizeWidth % pointInt.x;
	tempY = m_nImageSizeHeight % pointInt.y;

	if (! (tempX == 0) ) 
	{
		MessageBox(_T("�������� ���� �������� �ʽ��ϴ�. �ٽ��Է��ϼ���"), 
			_T("Error"));
		this->OnCutDialog();
	} // end if
	else
	if ( ! (tempY == 0) )
	{
		MessageBox (_T("�������� ���� �������� �ʽ��ϴ�. �ٽ� �Է��ϼ���"),
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
		OnCutDialog(); //�̹��� �ڸ��� ���̾�α� ���
		this->SetFocus();
		bImageLoad = TRUE;
	} // end if
	else
	{
		if (dlg.DoModal() == IDCANCEL) return;
	}


	////////////////////////////////////////////
	// ����� �����迭�� ����
	int nArraySize;  // �迭 ũ��
	nArraySize = ( m_nImageSizeWidth / m_nXPitch) * ( m_nImageSizeHeight / m_nYPitch );

	// �÷��׿� ���� �迭 �Ҵ�
	m_bMark = new BOOL [nArraySize];
	for (int i=0; i<nArraySize; i++)
	{
		// �迭 �ʱ�ȭ
		m_bMark[i] = FALSE;
	}

	// CInformationDlg���� ����� �迭 �ʱ�ȭ
	m_pInfoDlg->InitArray(m_nImageSizeWidth, m_nImageSizeHeight, m_nXPitch, m_nYPitch);

	// �����Ͱ� ����Ǵ� �迭 �ʱ�ȭ
	m_pCellData = new CCellData[nArraySize];
	bViewArrayCreated = true;  // �迭�� �����Ǿ����� �˸�..(PostNcDestroy()���� ���)

	CCellType ct;
	ct.ctDecision = 0;
	ct.ctGround = 0;
	ct.ctNumber = 0;
	ct.ctTime = 0;

	for (i=0; i<nArraySize; i++)
	{
		// �迭 �ʱ�ȭ
		m_pCellData->SetAttributes(TRUE, ct);
	}

	Invalidate();
}

BOOL CLabyrinthWayView::DrawLineByPitch(int pitchX, int pitchY, CColor color)
{
	// CColor Ÿ���� �������� ������ �׷���.
	int cWidth = 0, cHeight = 0;
	int xp=0, yp=0;
	
	xp = m_nImageSizeWidth / pitchX;  // �׾����� ������ �� ����.
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
	
	dc.MoveTo(0,0);  // �������� (0,0 �̵�

	for (int i=1; i<=xp; i++)
	{
		// ���μ� ����
		dc.MoveTo(pitchX*i, 0);   
		dc.LineTo(pitchX*i, m_nImageSizeHeight);
	}

	dc.MoveTo(0,0); // �ٽ� �������� �̵� (0,0)
	for (i=1; i<=yp; i++)
	{
		// ���μ� ����
		dc.MoveTo(0, pitchY*i);
		dc.LineTo(m_nImageSizeWidth, pitchY*i); // �̹������� �ణ ũ�� ���� ����
		                                        // ũ�� �ȱ���..���� +15����..
	}
	return TRUE;
}

void CLabyrinthWayView::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// ��ũ�� ����⸦ �ٵ�� ��ũ���� ������ �ٽ� �׷���..
	// �������� �� ���Ѱ� ����...�翬�� ���....--;;

	if (nSBCode == SB_ENDSCROLL) Invalidate();
	m_nScrollPoint = GetScrollPosition(); // ��ũ�ѵ� ��ǥ �缳��..
	CScrollView::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CLabyrinthWayView::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// ���� ����
	// �ּ��ٴ°� �ڵ��ϴ°ź��� �� �����...
	if (nSBCode == SB_ENDSCROLL) Invalidate();
	m_nScrollPoint = GetScrollPosition(); // ��ũ�ѵ� �κ��� ��ǥ �缳��
	CScrollView::OnVScroll(nSBCode, nPos, pScrollBar);
}

BOOL CLabyrinthWayView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
	// ���� ������ �ٽ� �׷���..
	// �� ������ �ɸ��� �׾� !! -_-+++
	Invalidate();	
	m_nScrollPoint = GetScrollPosition(); // ���� ��ǥ �缳��..
	return CScrollView::OnMouseWheel(nFlags, zDelta, pt);
}

void CLabyrinthWayView::OnRButtonUp(UINT nFlags, CPoint point) 
{
	// ������ ��ư�� ������ ���콺 ��ǥ�� ��ũ�Ѹ��� �� ��ǥ����
	// ����ؼ� �޽��� �ڽ��� ���...
	// �׳� �׽�Ʈ�� �޽��� �ڵ鷯..
	CPoint po;
	po = GetScrollPosition();
	CString mm;
	mm.Format(_T("%d %d"), po.x, po.y);
	MessageBox(mm);
	CScrollView::OnRButtonUp(nFlags, point);
}

void CLabyrinthWayView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// ���� ��ư�� ������ ������ ��ŷ�� �ϰ�, GetScrollPosition()����
	// ��ũ�ѵ� ��ŭ�� ������ ���� �ؼ� ����ϰ� ó����
	
	// ���콺�� ���õ� ����üũ
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
		// �̹����� �ε��Ǿ���,
		// �̹� ��ŷ�� �Ǿ� �ִٸ� �׺κ��� ������ �ٽ� �׷���(����).
		// ������ ��ŷ�Ǿ� �ִ� �κи�..
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
		// �Ķ��� (�̹� �����Ͱ� �ԷµǾ� �ִ� �κ�) �κ��� ��ŷ������
		// ������
		rect.left = xx * m_nXPitch;
		rect.top = yy * m_nYPitch;
		rect.right = rect.left + m_nXPitch;
		rect.bottom  = rect.top + m_nYPitch;
		
		m_pInfoDlg->m_pbMarkArray[number] = FALSE;
		InvalidateRect(rect);
	}
	
	// ��Ʈ��Ű�� �������� ��ŷ����..
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
		nNumber = GetImageNumber(xx, yy); // �� ��ȣ�� ���ѵ�..
		if (m_bMark[nNumber] == FALSE)  // m_bMark[����ȣ]�� FALSE�̸�..
		{
			m_bMark[nNumber] = TRUE; // TRUE�� �ٲ���..
//			m_pInfoDlg->m_pbMarkArray[nNumber] = 1;
		}
		// ���̾�α׿� ��ǥ ������..

		m_pInfoDlg->SetMousePoint(point, CPoint(xx, yy), nNumber); 

	}

//	Invalidate(FALSE);
	CScrollView::OnLButtonDown(nFlags, CPoint(xx, yy));
}

int CLabyrinthWayView::GetImageNumber(int x, int y)
{
	// ��ǥ�� ���� �з��Ǵ� �̹��� ��ȣ
	// Ŭ���̾�Ʈ ������ ���콺 ��ǥ + ��ũ�ѵ� ��ǥ���� x,y
	int Count;
	Count = ( (m_nImageSizeWidth / m_nXPitch) * (y/m_nYPitch ) + (x/m_nXPitch) );

	return Count;
}

void CLabyrinthWayView::DrawMark(int nBitmapID, CPoint markPoint)
{
	// ��Ʈ�� ID�� ��ǥ�� �޾� �� ���� ��ŷ�� ����
	// ���� �ߵ�...-.-;;

	/////////////////////////////////////////////////////
	/////////////////////////////////////////////////////
	///// ������ //////////////////////////////////////
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
	// ��Ʈ�� ID�� ����ȣ�� ����
	// ��ũ�Ѹ��� ������ �� ��ȣ�� �޾Ƽ�
	// ����ȣ�� ��ǥ�� ������ (��ü �̹���ũ�⿡���� ��ǥ)
	// ���� Ŭ���̾�Ʈ ������ ��ǥ�� ��ȯ�ѵ� ����ŷ����
	/////////////////////////////////////////////////////
	/////////////////////////////////////////////////////
	///// ������ //////////////////////////////////////
	/////////////////////////////////////////////////////
	/////////////////////////////////////////////////////
	////////////////////////////////////////
	// Ŭ���̾�Ʈ ũ��
	CRect rect;
	GetClientRect(&rect);
	int clientWidth, clientHeight;
	clientWidth = rect.Width();
	clientHeight = rect.Height();
	
	// ��ũ�ѵ� ��ǥ�� ����..
	CPoint tempPoint;   
	int scrollWidth, scrollHeight;
	tempPoint = GetScrollPosition();
	scrollWidth  = clientWidth  + tempPoint.x;
	scrollHeight = clientHeight + tempPoint.y;

	//////////////////////////////////////////////////
	// ����ȣ�� ��ǥ�� ��ȯ
	CParser parser;
	POINT point;
	point = parser.NumberToPoint(nCellNumber, m_nImageSizeWidth, m_nXPitch, m_nYPitch);
	int xx, yy;
	xx = point.x * m_nXPitch;
	yy = point.y * m_nYPitch;
	
	///////////////////////////////////////////
	// ���� �ش��ϴ� ���� ��ǥ�� ���� Ŭ���̾�Ʈ��ǥ+��ũ����ǥ ���� ũ��
	// ���� ���� �����ȿ� ���� ���̹Ƿ� �׳� ������.
	if (! ( (xx > scrollWidth) && (yy > scrollHeight) ) )
	{
		// ��ũ�� ��ǥ�� ���� ��ũ�� ��ǥ�� �ٲ���..
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
	
	CWaitDialog * pWaitDlg = new CWaitDialog;  //��� ��ٸ���� ���̾�α� ���
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

	MessageBox(_T("����Ϸ�"), _T("Ȯ��"));
}



void CLabyrinthWayView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	Invalidate(TRUE);

	// CInformationDlg�� m_bMarkArray�� m_bMark�� ���� ��������..
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
	// ȣ��ɶ� m_bMark[] �迭�� ��� ���� �ʱ�ȭ ��Ŵ.

	int nSize = (m_nImageSizeWidth / m_nXPitch) * (m_nImageSizeHeight / m_nYPitch);

	for (int i=0; i<nSize; i++)
	{
		m_bMark[i] = FALSE;
	}

	m_bSaveData = TRUE;
}

void CLabyrinthWayView::SetInformationDlgArray()
{
	// CInformationDialog�� �Է� ��ư�� ������ �������
	// m_bMark[]�� ������ �ִ� ���� ������ CInformationDlg�� m_bTempMark[]�� 
	// ��������...(TRUE�϶���)

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
	// �̹� ����� ������ ������ ��� CInformationDlg�� m_bpMark[] �迭��
	// m_pCellData[]�� ������ ������..

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
	int nSize = (m_nImageSizeWidth / m_nXPitch) * (m_nImageSizeHeight / m_nYPitch); // ���� ����
	
	celltype = new CCellType [nSize];

	for (int i=0; i<nLineCount; i++)
	{
		celltype[i] = celldata[i].GetAttributes(); // ������ ������...
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
