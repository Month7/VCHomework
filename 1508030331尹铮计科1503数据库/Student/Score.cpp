// Score.cpp : implementation file
//

#include "stdafx.h"
#include "Student.h"
#include "Score.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScore dialog


CScore::CScore(CWnd* pParent /*=NULL*/)
	: CDialog(CScore::IDD, pParent)
{
	//{{AFX_DATA_INIT(CScore)
	m_strScore = _T("");
	m_strMakeup = _T("");
	m_bAbsent = FALSE;
	//}}AFX_DATA_INIT
}


void CScore::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScore)
	DDX_Text(pDX, IDC_EDIT_SCORE, m_strScore);
	DDX_Text(pDX, IDC_EDIT_MAKEUP, m_strMakeup);
	DDX_Check(pDX, IDC_CHECK1, m_bAbsent);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CScore, CDialog)
	//{{AFX_MSG_MAP(CScore)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScore message handlers

void CScore::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	CDialog::OnOK();
}
