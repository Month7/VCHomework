// EditSoftView.cpp : implementation of the CEditSoftView class
//

#include "stdafx.h"
#include "EditSoft.h"

#include "EditSoftDoc.h"
#include "EditSoftView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEditSoftView

IMPLEMENT_DYNCREATE(CEditSoftView, CEditView)

BEGIN_MESSAGE_MAP(CEditSoftView, CEditView)
	//{{AFX_MSG_MAP(CEditSoftView)
	ON_WM_CTLCOLOR_REFLECT()
	ON_WM_CHAR()
	ON_COMMAND(ID_Font, OnFont)
	ON_COMMAND(ID_TXTCOLOR, OnTxtcolor)
	ON_COMMAND(ID_BKCOLOR, OnBkcolor)
	ON_WM_ERASEBKGND()
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_LEFT, OnLeft)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CEditView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditSoftView construction/destruction

CEditSoftView::CEditSoftView()
{
	// TODO: add construction code here

}

CEditSoftView::~CEditSoftView()
{
}

BOOL CEditSoftView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// Enable word-wrapping

	return bPreCreated;
}

/////////////////////////////////////////////////////////////////////////////
// CEditSoftView drawing

void CEditSoftView::OnDraw(CDC* pDC)
{
	CEditSoftDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CEditSoftView printing

BOOL CEditSoftView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default CEditView preparation
	return CEditView::OnPreparePrinting(pInfo);
}

void CEditSoftView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView begin printing.
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void CEditSoftView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView end printing
	CEditView::OnEndPrinting(pDC, pInfo);
}

/////////////////////////////////////////////////////////////////////////////
// CEditSoftView diagnostics

#ifdef _DEBUG
void CEditSoftView::AssertValid() const
{
	CEditView::AssertValid();
}

void CEditSoftView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CEditSoftDoc* CEditSoftView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEditSoftDoc)));
	return (CEditSoftDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEditSoftView message handlers

HBRUSH CEditSoftView::CtlColor(CDC* pDC, UINT nCtlColor) 
{
	// TODO: Change any attributes of the DC here
	CEditSoftDoc *pDoc =GetDocument();
	ASSERT_VALID(pDoc);
	pDC->SetTextColor(pDoc->m_txtColor);
	// TODO: Return a non-NULL brush if the parent's handler should not be called
	return !NULL;
}

void CEditSoftView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	CEditView::OnChar(nChar, nRepCnt, nFlags);
	InvalidateRect(NULL);
}

void CEditSoftView::OnFont() 
{
	// TODO: Add your command handler code here
	CEditSoftDoc* pDoc = GetDocument(); 
	ASSERT_VALID(pDoc);
	CFont *font=this->GetEditCtrl().GetFont(); //得到当前字体
	if(font==NULL)	//当前无字体，创建默认的字体
	{
		font =new CFont;
		font->CreatePointFont(120,"Fixedsys"); 
		font->GetLogFont(&pDoc->m_lf); 
		delete font;
	}
	else
	{
		font->GetLogFont(&pDoc->m_lf);
	}
	CFontDialog cf(&pDoc->m_lf,CF_SCREENFONTS|CF_INITTOLOGFONTSTRUCT);
	if(cf.DoModal()==IDOK)
	{
		pDoc->m_Font.DeleteObject();
		pDoc->m_Font.CreateFontIndirect(&pDoc->m_lf); this->SetFont(&pDoc->m_Font);
	}

}

void CEditSoftView::OnTxtcolor() 
{
	// TODO: Add your command handler code here
	CEditSoftDoc *pDoc=GetDocument();
	ASSERT_VALID(pDoc);
	CColorDialog dlg;
	if (dlg.DoModal()==IDOK)
	{
		pDoc->m_txtColor=dlg.GetColor();
	}
	InvalidateRect(NULL);
}

void CEditSoftView::OnBkcolor() 
{
	// TODO: Add your command handler code here
	CEditSoftDoc *pDoc=GetDocument();
	ASSERT_VALID(pDoc);
	CColorDialog dlg; 
	if(dlg.DoModal()==IDOK)
		pDoc->m_bkColor=dlg.GetColor(); 
	InvalidateRect(NULL);
}

BOOL CEditSoftView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	CEditSoftDoc *pDoc=GetDocument(); 
	ASSERT_VALID(pDoc);
	CBrush Brush (pDoc->m_bkColor);
	// Select the brush into the device context .
	CBrush* pOldBrush = pDC->SelectObject(&Brush);
	// Get the area that needs to be erased .
	CRect rect;
	GetClientRect(&rect);
	//Paint the area.
	pDC->PatBlt(rect.left,rect.top,rect.Width(), rect.Height(), PATCOPY);
	//Unselect brush out of device context . 
	pDC->SelectObject (pOldBrush ); 
	pDC->SetBkMode(TRANSPARENT);
	// Return nonzero to half fruther processing . 
	return TRUE;
	//return CEditView::OnEraseBkgnd(pDC);
}

void CEditSoftView::OnInitialUpdate() 
{
	CEditView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	CEditSoftDoc* pDoc = GetDocument(); ASSERT_VALID(pDoc);
	if(pDoc->bOpenFlag==TRUE)
	{
		pDoc->m_Font.DeleteObject();
		pDoc->m_Font.CreateFontIndirect(&pDoc->m_lf); 
		this->SetFont(&pDoc->m_Font);
		pDoc->bOpenFlag=FALSE;
	}
}

void CEditSoftView::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
	CMenu menuPopup;
	if(menuPopup.CreatePopupMenu())
	{
		menuPopup.AppendMenu(MF_STRING,ID_EDIT_UNDO,"撤销(&U)\tCtrl+Z");
		menuPopup.AppendMenu(MF_STRING,ID_EDIT_CUT,"剪切(&C)\tCtrl+X");
		menuPopup.AppendMenu(MF_STRING,ID_EDIT_COPY,"复制(&C)\tCtrl+C");
		menuPopup.AppendMenu(MF_STRING,ID_EDIT_PASTE,"粘贴(&P)\tCtrl+V");
		menuPopup.AppendMenu(MF_STRING,ID_EDIT_SELECT_ALL,"全选(&L)\tCtrl+A");
/*		menuPopup.AppendMenu(MF_STRING,ID_APP_ABOUT,"作者(&F)");*/
		menuPopup.TrackPopupMenu(TPM_LEFTALIGN,point.x,point.y,this);
	}
}

void CEditSoftView::OnLeft() 
{
	// TODO: Add your command handler code here
}
