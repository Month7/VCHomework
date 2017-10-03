// UserDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Student.h"
#include "UserDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUserDlg dialog


CUserDlg::CUserDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUserDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUserDlg)
	m_strUser = _T("");
	m_strPass = _T("");
	m_strRePass = _T("");
	m_bIsAdmin = FALSE;
	//}}AFX_DATA_INIT
}


void CUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUserDlg)
	DDX_Control(pDX, IDC_LIST_USERNAME, m_ctrList);
	DDX_Control(pDX, IDC_PASSWORD2, m_ctrRePass);
	DDX_Control(pDX, IDC_PASSWORD1, m_ctrPass);
	DDX_Control(pDX, IDC_USERNAME, m_ctrUser);
	DDX_Text(pDX, IDC_USERNAME, m_strUser);
	DDX_Text(pDX, IDC_PASSWORD1, m_strPass);
	DDX_Text(pDX, IDC_PASSWORD2, m_strRePass);
	DDX_Check(pDX, IDC_CHECK1, m_bIsAdmin);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUserDlg, CDialog)
	//{{AFX_MSG_MAP(CUserDlg)
	ON_BN_CLICKED(IDC_BUTTON_NEW, OnButtonNew)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
/*	ON_BN_CLICKED(ID_BUTTON_CANCLE, OnButtonCancle)*/
	ON_NOTIFY(NM_CLICK, IDC_LIST_USERNAME, OnClickListUsername)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUserDlg message handlers

void CUserDlg::OnButtonNew() 
{
	// TODO: Add your control notification handler code here
	m_strUser = "";
	m_strPass = "";
	m_strRePass = "";
	m_bIsAdmin = FALSE;
	m_ctrUser.EnableWindow(TRUE);
	m_ctrUser.SetFocus();
	UpdateData(FALSE);
}

void CUserDlg::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_strUser=="")
	{
		MessageBox(" ��ѡ��һ���û���");
		return;
	}
	CString strSQL;
	strSQL.Format("select * from user where user='%s'",m_strUser);
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox(" �����ݿ�ʧ��!"," ���ݿ����",MB_OK);
		return ;
	}
	// ɾ�����û�
	m_recordset.Delete();
	m_recordset.Close();
	// ˢ���û��б�
	RefreshData();
	m_strUser = "";
	m_strPass = "";
	m_strRePass = "";
	m_bIsAdmin = FALSE;
	UpdateData(FALSE);
}

void CUserDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	if(m_ctrUser.IsWindowEnabled())
	{// �������û�
		if(m_strUser=="")
		{
			MessageBox(" ����д�û�����");
			m_ctrUser.SetFocus();
			return;
		}
	}
	else
	{// �޸��û���Ϣ
		if(m_strUser=="")
		{
			MessageBox(" ��ѡ��һ���û���");
			return;
		}
	}
	if(m_strPass=="")
	{
		MessageBox(" ���벻��Ϊ�գ����������룡");
		m_ctrPass.SetFocus();
		return;
	}
	if(m_strPass!=m_strRePass)
	{
MessageBox(" ������������벻һ�£��������������룡");
m_ctrPass.SetFocus();
m_strPass = "";
m_strRePass = "";
UpdateData(FALSE);
return;
}
	CString strSQL;
	strSQL.Format("select * from user where user='%s'",m_strUser);
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox(" �����ݿ�ʧ��!"," ���ݿ����",MB_OK);
		return ;
	}
	if(m_ctrUser.IsWindowEnabled())
	{// �������û�
		// �ж��û��Ƿ��Ѿ�����
		if(m_recordset.GetRecordCount()!=0)
		{
			m_recordset.Close();
			MessageBox(" ���û��Ѿ����ڣ�");
			return;
		}
		m_recordset.AddNew();
		m_recordset.m_user = m_strUser;
		m_recordset.m_password = m_strPass;
/*		m_recordset.m_isadmin = m_bIsAdmin;*/
		m_recordset.m_idAdmin=m_bIsAdmin;
m_recordset.Update();
MessageBox(" �û���ӳɹ������ס�û��������룡");
m_recordset.Close();
	}
else 
{
	if(m_recordset.GetRecordCount()==0)
	{// �ж��û��Ƿ񲻴���
		m_recordset.Close();
		MessageBox(" ���û������ڣ���������ݿ�");
		return;
	}
	m_recordset.Edit();
	m_recordset.m_user = m_strUser;
	m_recordset.m_password = m_strPass;
	m_recordset.m_idAdmin= m_bIsAdmin;
	m_recordset.Update();
	MessageBox(" �û��޸ĳɹ������ס�û��������룡");
	m_recordset.Close();
	}
	m_ctrUser.EnableWindow(FALSE);
	RefreshData();
	CDialog::OnOK();
}

void CUserDlg::OnButtonCancle() 
{
	// TODO: Add your control notification handler code here
	m_strUser = "";
	m_strPass = "";
	m_strRePass = "";
	m_bIsAdmin = FALSE;
	m_ctrUser.EnableWindow(FALSE);
	UpdateData(FALSE);
}

void CUserDlg::RefreshData()
{
	m_ctrList.SetFocus();
	m_ctrList.DeleteAllItems();
	m_ctrList.SetRedraw(FALSE);
	CString strSQL;
	UpdateData(TRUE);
	strSQL="select * from user";
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox(" �����ݿ�ʧ��!"," ���ݿ����",MB_OK);
		return ;
	}
	int i=0;
	while(!m_recordset.IsEOF())
	{
		m_ctrList.InsertItem(i++,m_recordset.m_user);
		m_recordset.MoveNext();
	}
	m_recordset.Close();
m_ctrList.SetRedraw(TRUE);
}

BOOL CUserDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CDialog::OnInitDialog();
	m_ctrList.InsertColumn(0," �û���");
	m_ctrList.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	m_ctrList.SetColumnWidth(0,120);
	RefreshData();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CUserDlg::OnClickListUsername(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CString strSQL;
	UpdateData(TRUE);
	int i = m_ctrList.GetSelectionMark();
	m_strUser = m_ctrList.GetItemText(i,0);
	strSQL.Format("select * from user where user='%s'",m_strUser);
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox(" �����ݿ�ʧ��!"," ���ݿ����",MB_OK);
		return ;
	}
	m_strPass = m_recordset.m_password;
	m_strRePass = m_strPass;
	m_bIsAdmin = m_recordset.m_idAdmin;
	m_recordset.Close();
	UpdateData(FALSE);
	*pResult = 0;
}
