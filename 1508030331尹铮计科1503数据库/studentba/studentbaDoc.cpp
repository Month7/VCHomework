// studentbaDoc.cpp : implementation of the CStudentbaDoc class
//

#include "stdafx.h"
#include "studentba.h"

#include "studentbaSet.h"
#include "studentbaDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStudentbaDoc

IMPLEMENT_DYNCREATE(CStudentbaDoc, CDocument)

BEGIN_MESSAGE_MAP(CStudentbaDoc, CDocument)
	//{{AFX_MSG_MAP(CStudentbaDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStudentbaDoc construction/destruction

CStudentbaDoc::CStudentbaDoc()
{
	// TODO: add one-time construction code here

}

CStudentbaDoc::~CStudentbaDoc()
{
}

BOOL CStudentbaDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CStudentbaDoc diagnostics

#ifdef _DEBUG
void CStudentbaDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CStudentbaDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStudentbaDoc commands
