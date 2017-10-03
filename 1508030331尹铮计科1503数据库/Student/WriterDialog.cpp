// WriterDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Student.h"
#include "WriterDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// WriterDialog dialog


WriterDialog::WriterDialog(CWnd* pParent /*=NULL*/)
	: CDialog(WriterDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(WriterDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void WriterDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(WriterDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(WriterDialog, CDialog)
	//{{AFX_MSG_MAP(WriterDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// WriterDialog message handlers
