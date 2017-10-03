// studentbaView.cpp : implementation of the CStudentbaView class
//

#include "stdafx.h"
#include "studentba.h"

#include "studentbaSet.h"
#include "studentbaDoc.h"
#include "studentbaView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStudentbaView

IMPLEMENT_DYNCREATE(CStudentbaView, CRecordView)

BEGIN_MESSAGE_MAP(CStudentbaView, CRecordView)
	//{{AFX_MSG_MAP(CStudentbaView)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStudentbaView construction/destruction

CStudentbaView::CStudentbaView()
	: CRecordView(CStudentbaView::IDD)
{
	//{{AFX_DATA_INIT(CStudentbaView)
	m_pSet = NULL;
	m_Add=FALSE;
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CStudentbaView::~CStudentbaView()
{
}

void CStudentbaView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStudentbaView)
	DDX_FieldText(pDX, IDC_EDIT1, m_pSet->m_NormalScore, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT2, m_pSet->m_MidScore, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT3, m_pSet->m_FinalScore, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT4, m_pSet->m_SumScore, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT5, m_pSet->m_column1, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT6, m_pSet->m_Num, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT7, m_pSet->m_Name, m_pSet);
	//}}AFX_DATA_MAP
}

BOOL CStudentbaView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRecordView::PreCreateWindow(cs);
}

void CStudentbaView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_studentbaSet;
	CRecordView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CStudentbaView printing

BOOL CStudentbaView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CStudentbaView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CStudentbaView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CStudentbaView diagnostics

#ifdef _DEBUG
void CStudentbaView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CStudentbaView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CStudentbaDoc* CStudentbaView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStudentbaDoc)));
	return (CStudentbaDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStudentbaView database support
CRecordset* CStudentbaView::OnGetRecordset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// CStudentbaView message handlers

void CStudentbaView::OnButton1() 
{
	// TODO: Add your control notification handler code here
	m_pSet->m_SumScore=long(m_pSet->m_NormalScore*0.1+m_pSet->m_MidScore*0.2+m_pSet->m_FinalScore*0.7);
    UpdateData(FALSE);

}

void CStudentbaView::OnButton2() 
{
	// TODO: Add your control notification handler code here
	m_pSet->MovePrev();
	UpdateData(FALSE);
}

void CStudentbaView::OnButton3() 
{
	// TODO: Add your control notification handler code here
	m_pSet->MoveNext();
	UpdateData(FALSE);
}

void CStudentbaView::OnButton4() 
{
	// TODO: Add your control notification handler code here
	m_pSet->MoveLast();
	UpdateData(FALSE);
}

BOOL CStudentbaView::OnMove(UINT nIDMoveCommand) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(m_Add)
	{
		if(!UpdateData()) return FALSE;
		m_pSet->Update();
		//更新记录
		m_pSet->Requery();
		//将记录移到新增的最后一条记录 
		m_pSet->MoveLast();
		//如果用户要求移到相应位置
		if(nIDMoveCommand==ID_RECORD_PREV) 
			m_pSet->MovePrev();
		else if(nIDMoveCommand==ID_RECORD_FIRST) 
			m_pSet->MoveFirst();
		UpdateData(FALSE); 
		m_Add=FALSE; 
		return TRUE;
	}
	else
	return CRecordView::OnMove(nIDMoveCommand);
}

void CStudentbaView::OnButton5() 
{
	// TODO: Add your control notification handler code here
	if(m_Add)
		OnMove(ID_RECORD_FIRST);
	//增加一个空记录 
	m_pSet->AddNew(); 
	m_Add=TRUE; UpdateData(FALSE);
}

void CStudentbaView::OnButton6() 
{
	// TODO: Add your control notification handler code here
	m_pSet->Delete(); 
	m_pSet->Requery();
	UpdateData(FALSE);
}
