// MyWordView.cpp : implementation of the CMyWordView class
//

#include "stdafx.h"
#include "MyWord.h"

#include "MyWordDoc.h"
#include "CntrItem.h"
#include "MyWordView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyWordView

IMPLEMENT_DYNCREATE(CMyWordView, CRichEditView)

BEGIN_MESSAGE_MAP(CMyWordView, CRichEditView)
	//{{AFX_MSG_MAP(CMyWordView)
	ON_WM_DESTROY()
	ON_COMMAND(ID_FormatFont, OnFormatFont)
	ON_COMMAND(ID_Bkcolor, OnBkcolor)
	ON_COMMAND(ID_LEFT, OnLeft)
	ON_COMMAND(ID_RIGHT, OnRight)
	ON_COMMAND(ID_CENTER, OnCenter)
	ON_COMMAND(ID_2, On2)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_TxtColor, OnTxtColor)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CRichEditView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyWordView construction/destruction

CMyWordView::CMyWordView()
{
	// TODO: add construction code here

}

CMyWordView::~CMyWordView()
{
}

BOOL CMyWordView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRichEditView::PreCreateWindow(cs);
}

void CMyWordView::OnInitialUpdate()
{
	CRichEditView::OnInitialUpdate();


	// Set the printing margins (720 twips = 1/2 inch).
	SetMargins(CRect(720, 720, 720, 720));
}

/////////////////////////////////////////////////////////////////////////////
// CMyWordView printing

BOOL CMyWordView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}


void CMyWordView::OnDestroy()
{
	// Deactivate the item on destruction; this is important
	// when a splitter view is being used.
   CRichEditView::OnDestroy();
   COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
   if (pActiveItem != NULL && pActiveItem->GetActiveView() == this)
   {
      pActiveItem->Deactivate();
      ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
   }
}


/////////////////////////////////////////////////////////////////////////////
// CMyWordView diagnostics

#ifdef _DEBUG
void CMyWordView::AssertValid() const
{
	CRichEditView::AssertValid();
}

void CMyWordView::Dump(CDumpContext& dc) const
{
	CRichEditView::Dump(dc);
}

CMyWordDoc* CMyWordView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyWordDoc)));
	return (CMyWordDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyWordView message handlers

void CMyWordView::OnFormatFont() 
{
	// TODO: Add your command handler code here
	CMyWordDoc *pDoc=GetDocument();
	ASSERT_VALID(pDoc);
	CFontDialog cfd(&pDoc->m_lf,CF_SCREENFONTS|CF_INITTOLOGFONTSTRUCT);
	if(cfd.DoModal()==IDOK)     //�����ȷ������������
	{  
		CHARFORMAT cf;
		cf.cbSize = sizeof (CHARFORMAT);
		cf.dwMask = CFM_FACE | CFM_SIZE;
		::lstrcpy (cf.szFaceName, cfd.GetFaceName());
		cf.yHeight = cfd.GetSize()*2;
		SetCharFormat (cf);
	}
}

void CMyWordView::OnBkcolor() 
{
	// TODO: Add your command handler code here
	CMyWordDoc *pDoc=GetDocument();
	ASSERT_VALID(pDoc);
    CColorDialog dlg;
	CRichEditCtrl& EditCtrl = GetRichEditCtrl();
    CHARFORMAT cf;
    if(dlg.DoModal()==IDOK)
	{
		EditCtrl.SetBackgroundColor(FALSE,dlg.GetColor());  //��ȡ�û���ѡ��ɫ
		cf.dwMask = CFM_COLOR;
		cf.cbSize = sizeof(CHARFORMAT);
		EditCtrl.GetDefaultCharFormat(cf);
		cf.crTextColor =RGB(0,0,0);                     
		cf.dwEffects &= ~CFE_AUTOCOLOR; 
		EditCtrl.SetDefaultCharFormat(cf);
	}

}

void CMyWordView::OnLeft() 
{
	// TODO: Add your command handler code here
	OnParaAlign(PFA_LEFT); 
}

void CMyWordView::OnRight() 
{
	// TODO: Add your command handler code here
	OnParaAlign(PFA_RIGHT); 
}

void CMyWordView::OnCenter() 
{
	// TODO: Add your command handler code here
	OnParaAlign(PFA_CENTER); 
}

void CMyWordView::On2() 
{
	// TODO: Add your command handler code here
	CHARFORMAT cf;
	cf = GetCharFormatSelection ();
    if (!(cf.dwMask & CFM_BOLD) || !(cf.dwEffects & CFE_BOLD)) //��ԭ�����Ǵ��壬���Ϊ����
        cf.dwEffects = CFE_BOLD;
    else                            //���򣬸�Ϊԭ��������
        cf.dwEffects = 0;
    cf.dwMask = CFM_BOLD;
    SetCharFormat (cf);
}



void CMyWordView::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
	CMenu menuPopup;
	if(menuPopup.CreatePopupMenu())
	{
		menuPopup.AppendMenu(MF_STRING,ID_EDIT_UNDO,"����(&U)\tCtrl+Z");
		menuPopup.AppendMenu(MF_STRING,ID_EDIT_CUT,"����(&C)\tCtrl+X");
		menuPopup.AppendMenu(MF_STRING,ID_EDIT_COPY,"����(&C)\tCtrl+C");
		// 		menuPopup.AppendMenu(MF_STRING,ID_EDIT_PASTE,"ճ��(&P)\tCtrl+V");
		// 		menuPopup.AppendMenu(MF_STRING,ID_EDIT_SELECT_ALL,"ȫѡ(&L)\tCtrl+A");
		// 		menuPopup.AppendMenu(MF_STRING,ID_APP_ABOUT,"����(&F)");
		menuPopup.TrackPopupMenu(TPM_LEFTALIGN,point.x,point.y,this);
	}
}

void CMyWordView::OnRButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	HWND hWnd;
	POINT p;
	GetCursorPos(&p);
	::ScreenToClient(hWnd,&p);
	CMenu menuPopup;
	if(menuPopup.CreatePopupMenu())
	{
		menuPopup.AppendMenu(MF_STRING,ID_EDIT_UNDO,"����(&U)\tCtrl+Z");
		menuPopup.AppendMenu(MF_STRING,ID_EDIT_CUT,"����(&C)\tCtrl+X");
		menuPopup.AppendMenu(MF_STRING,ID_EDIT_COPY,"����(&C)\tCtrl+C");
		menuPopup.AppendMenu(MF_STRING,ID_EDIT_PASTE,"ճ��(&P)\tCtrl+V");
		menuPopup.AppendMenu(MF_STRING,ID_EDIT_SELECT_ALL,"ȫѡ(&L)\tCtrl+A");
		menuPopup.AppendMenu(MF_STRING,ID_FORMAT_FONT,"����(&F)");
// 		menuPopup.AppendMenu(MF_STRING,IDM_BKCOLOR,"������ɫ(&B)");
// 		menuPopup.AppendMenu(MF_STRING,IDM_TXTCOLOR,"������ɫ(&T)");
		menuPopup.TrackPopupMenu(TPM_LEFTALIGN,p.x,p.y,this);
	}
	CRichEditView::OnRButtonUp(nFlags, point);
}

void CMyWordView::OnTxtColor() 
{
	// TODO: Add your command handler code here
	CHARFORMAT cf;
	CMyWordDoc *pDoc=GetDocument();
	ASSERT_VALID(pDoc);
	CColorDialog dlg;
	if(dlg.DoModal()==IDOK)
	{
		cf.crTextColor=dlg.GetColor();      //��ȡ�û���ѡ��ɫ
           ZeroMemory(&cf, sizeof(CHARFORMAT));
		cf.crTextColor=dlg.GetColor();
		cf.dwMask=CFM_CHARSET | CFM_COLOR ;
		cf.dwEffects  = cf.dwEffects  & ~CFE_AUTOCOLOR;  //ȥ��ԭ������ɫЧ������Ϊ�µ���ɫ
        SetCharFormat(cf);       //����
	}

}
