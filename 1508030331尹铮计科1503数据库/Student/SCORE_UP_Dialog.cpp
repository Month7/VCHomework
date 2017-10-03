// SCORE_UP_Dialog.cpp : implementation file
//

#include "stdafx.h"
#include "Student.h"
#include "SCORE_UP_Dialog.h"
#include "ScoreSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// SCORE_UP_Dialog dialog


SCORE_UP_Dialog::SCORE_UP_Dialog(CWnd* pParent /*=NULL*/)
	: CDialog(SCORE_UP_Dialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(SCORE_UP_Dialog)
	m_str_Score = 0;
	m_str_Makeup = 0;
	//}}AFX_DATA_INIT
}


void SCORE_UP_Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(SCORE_UP_Dialog)
	DDX_Text(pDX, IDC_EDIT1, m_str_Score);
	DDX_Text(pDX, IDC_EDIT2, m_str_Makeup);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(SCORE_UP_Dialog, CDialog)
	//{{AFX_MSG_MAP(SCORE_UP_Dialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// SCORE_UP_Dialog message handlers
