// StudentInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Student.h"
#include "StudentInfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStudentInfoDlg dialog


CStudentInfoDlg::CStudentInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStudentInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStudentInfoDlg)
	m_strCode = _T("");
	m_strDepartment = _T("");
	m_strName = _T("");
	m_strSex = _T("");
	m_strMajor = _T("");
	m_tmBirth = 0;
	m_strClass = _T("");
	m_strPhone = _T("");
	m_strAddress = _T("");
	//}}AFX_DATA_INIT
}


void CStudentInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStudentInfoDlg)
	DDX_Text(pDX, IDC_STUCODE, m_strCode);
	DDX_Text(pDX, IDC_STUDEPARTMENT, m_strDepartment);
	DDX_Text(pDX, IDC_STUNAME, m_strName);
	DDX_CBString(pDX, IDC_STUSEX, m_strSex);
	DDX_Text(pDX, IDC_STUMAJOR, m_strMajor);
	DDX_DateTimeCtrl(pDX, IDC_STUBIRTH, m_tmBirth);
	DDX_Text(pDX, IDC_STUCLASS, m_strClass);
	DDX_Text(pDX, IDC_STUPHONE, m_strPhone);
	DDX_Text(pDX, IDC_STUADDR, m_strAddress);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStudentInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CStudentInfoDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStudentInfoDlg message handlers
