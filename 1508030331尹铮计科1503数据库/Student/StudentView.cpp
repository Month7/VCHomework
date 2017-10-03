// StudentView.cpp : implementation of the CStudentView class
//

#include "stdafx.h"
#include "Student.h"
#include "UserDlg.h"
#include "StudentDoc.h"
#include "StudentView.h"
#include "StudentDlg.h"
#include "ScoreInputDlg.h"
#include "SEARCH.h"
#include "WriterDialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStudentView

IMPLEMENT_DYNCREATE(CStudentView, CView)

BEGIN_MESSAGE_MAP(CStudentView, CView)
	//{{AFX_MSG_MAP(CStudentView)
	ON_WM_PAINT()
	ON_COMMAND(ID_USER_MSG, OnUserMsg)
	ON_COMMAND(ID_STU_MSG, OnStuMsg)
	ON_COMMAND(ID_SCORE_INPUT, OnScoreInput)
	ON_COMMAND(ID_SCORE_SEARCH, OnScoreSearch)
	ON_COMMAND(IDC_WRITER, OnWriter)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStudentView construction/destruction

CStudentView::CStudentView()
{
	// TODO: add construction code here

}

CStudentView::~CStudentView()
{
}

BOOL CStudentView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CStudentView drawing

void CStudentView::OnDraw(CDC* pDC)
{
	CStudentDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CStudentView printing

BOOL CStudentView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CStudentView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CStudentView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CStudentView diagnostics

#ifdef _DEBUG
void CStudentView::AssertValid() const
{
	CView::AssertValid();
}

void CStudentView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CStudentDoc* CStudentView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStudentDoc)));
	return (CStudentDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStudentView message handlers

void CStudentView::OnPaint() 
{
	// TODO: Add your message handler code here
	CPaintDC* pDC=new CPaintDC(this); //  创建设备上下文
	CBitmap bmp;
	RECT Rect;
	RECT RectView;
	POINT ptSize;
	CDC dcmem;
	BITMAP bm;
	int b = bmp.LoadBitmap(IDB_BITMAP_BG); // 将位图取出；
	dcmem.CreateCompatibleDC(pDC); // 创建兼容设备上下文。
	dcmem.SelectObject(&bmp); // 用设备上下文选择位图；
	dcmem.SetMapMode(pDC->GetMapMode()); // 设置映射方式；
	GetObject(bmp.m_hObject, sizeof(BITMAP), (LPSTR)&bm); // 映射位图；
	GetClientRect(&Rect);
	ptSize.x=bm.bmWidth;
	ptSize.y=bm.bmHeight;
	pDC->DPtoLP((LPPOINT)&ptSize,1); // 设备单元 to  逻辑单元;
	GetClientRect(&RectView);
	CRect RectBmp = RectView;
	// 当位图宽度容纳不下的处理
	if((RectView.right - RectView.left) > bm.bmWidth)
	{
		RectBmp.left = RectView.left + (RectView.right - RectView.left - bm.bmWidth) / 2;
		RectBmp.right = bm.bmWidth;
	}
	else
	{
		RectBmp.left = RectView.left;
		RectBmp.right = RectView.right - RectBmp.left;
}
	if((RectView.bottom - RectView.top) > bm.bmHeight)
	{
		RectBmp.top = RectView.top + (RectView.bottom - RectView.top - bm.bmHeight) / 2;
		RectBmp.bottom = bm.bmHeight;
	}
	else
	{
		RectBmp.top = RectView.top;
		RectBmp.bottom = RectView.bottom - RectBmp.top;
	}
	// 加载视图到设备上下文中
	pDC->StretchBlt(RectBmp.left, RectBmp.top, RectBmp.right,
		RectBmp.bottom, &dcmem, 0, 0, bm.bmWidth, bm.bmHeight,
		SRCCOPY);
	// 删除设备上下文
	dcmem.DeleteDC();
	// Do not call CView::OnPaint() for painting messages
}

void CStudentView::OnUserMsg() 
{
	// TODO: Add your command handler code here
	CUserDlg dlg;
	dlg.DoModal();
}

void CStudentView::OnStuMsg() 
{
	// TODO: Add your command handler code here
	CStudentDlg dlg;
	dlg.DoModal();
}

void CStudentView::OnScoreInput() 
{
	// TODO: Add your command handler code here
	CScoreInputDlg dlg;
	dlg.DoModal();
}

void CStudentView::OnScoreSearch() 
{
	// TODO: Add your command handler code here
	SEARCH dlg;
	dlg.DoModal();
}

void CStudentView::OnWriter() 
{
	// TODO: Add your command handler code here
	WriterDialog dlg;
	dlg.DoModal();
}
