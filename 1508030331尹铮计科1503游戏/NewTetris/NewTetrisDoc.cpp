// NewTetrisDoc.cpp : implementation of the CNewTetrisDoc class
//

#include "stdafx.h"
#include "NewTetris.h"

#include "NewTetrisDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNewTetrisDoc

IMPLEMENT_DYNCREATE(CNewTetrisDoc, CDocument)

BEGIN_MESSAGE_MAP(CNewTetrisDoc, CDocument)
	//{{AFX_MSG_MAP(CNewTetrisDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewTetrisDoc construction/destruction

CNewTetrisDoc::CNewTetrisDoc()
{
	// TODO: add one-time construction code here

}

CNewTetrisDoc::~CNewTetrisDoc()
{
}

BOOL CNewTetrisDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	SetTitle(_T("¶íÂÞË¹·½¿é"));
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CNewTetrisDoc serialization

void CNewTetrisDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CNewTetrisDoc diagnostics

#ifdef _DEBUG
void CNewTetrisDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CNewTetrisDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CNewTetrisDoc commands
