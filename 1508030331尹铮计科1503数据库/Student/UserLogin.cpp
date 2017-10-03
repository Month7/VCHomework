// UserLogin.cpp : implementation file
//

#include "stdafx.h"
#include "Student.h"
#include "UserLogin.h"
#include "UserSet2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUserLogin dialog


CUserLogin::CUserLogin(CWnd* pParent /*=NULL*/)
	: CDialog(CUserLogin::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUserLogin)
	m_strUser = _T("");
	m_strPass = _T("");
	//}}AFX_DATA_INIT
}


void CUserLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUserLogin)
	DDX_Control(pDX, IDC_PASSWD, m_ctrPass);
	DDX_Control(pDX, IDC_USER, m_ctrUser);
	DDX_Text(pDX, IDC_USER, m_strUser);
	DDX_Text(pDX, IDC_PASSWD, m_strPass);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUserLogin, CDialog)
	//{{AFX_MSG_MAP(CUserLogin)
	ON_BN_CLICKED(IDC_BnClickedOk, OnBnClickedOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUserLogin message handlers

void CUserLogin::OnBnClickedOk() 
{
	// TODO: Add your control notification handler code here
	CUserSet2 recordset;
	CString strSQL;
	UpdateData(TRUE);
	CStudentApp* ptheApp = (CStudentApp *)AfxGetApp();
	// ����û����Ƿ�����
	if(m_strUser.IsEmpty())
	{
		AfxMessageBox(" �������û�����");
		m_ctrUser.SetFocus();
		return;
	}
	// ��������Ƿ�����
	if(m_strPass.IsEmpty())
	{
		AfxMessageBox(" ���������룡");
		m_ctrPass.SetFocus();
		return;
	}
	// ���û����м���û��������Ƿ���ȷ
	strSQL.Format("select* from user where user='%s'AND password='%s'",m_strUser,m_strPass);
	if(!recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox(" �����ݿ�ʧ��!"," ���ݿ����",MB_OK);
		return;
	}
	if(recordset.GetRecordCount()==0)
	{
		recordset.Close(); // ���������
		MessageBox(" ����������������룡");
		m_strPass="";
		m_ctrPass.SetFocus();
		UpdateData(FALSE);
	}
	else
	{
		// ������ȷ����������̨���������û�Ȩ��
/*		ptheApp->m_bIsAdmin = recordset.m_isadmin;*/
		ptheApp->m_bIsAdmin = recordset.m_idAdmin;
		recordset.Close();
		CDialog::OnOK();
}
}
