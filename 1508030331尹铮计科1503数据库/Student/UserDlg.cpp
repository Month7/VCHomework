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
		MessageBox(" 请选择一个用户！");
		return;
	}
	CString strSQL;
	strSQL.Format("select * from user where user='%s'",m_strUser);
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox(" 打开数据库失败!"," 数据库错误",MB_OK);
		return ;
	}
	// 删除该用户
	m_recordset.Delete();
	m_recordset.Close();
	// 刷新用户列表
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
	{// 增加新用户
		if(m_strUser=="")
		{
			MessageBox(" 请填写用户名！");
			m_ctrUser.SetFocus();
			return;
		}
	}
	else
	{// 修改用户信息
		if(m_strUser=="")
		{
			MessageBox(" 请选择一个用户！");
			return;
		}
	}
	if(m_strPass=="")
	{
		MessageBox(" 密码不能为空，请输入密码！");
		m_ctrPass.SetFocus();
		return;
	}
	if(m_strPass!=m_strRePass)
	{
MessageBox(" 两次输入地密码不一致，请重新输入密码！");
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
		MessageBox(" 打开数据库失败!"," 数据库错误",MB_OK);
		return ;
	}
	if(m_ctrUser.IsWindowEnabled())
	{// 增加新用户
		// 判断用户是否已经存在
		if(m_recordset.GetRecordCount()!=0)
		{
			m_recordset.Close();
			MessageBox(" 该用户已经存在！");
			return;
		}
		m_recordset.AddNew();
		m_recordset.m_user = m_strUser;
		m_recordset.m_password = m_strPass;
/*		m_recordset.m_isadmin = m_bIsAdmin;*/
		m_recordset.m_idAdmin=m_bIsAdmin;
m_recordset.Update();
MessageBox(" 用户添加成功！请记住用户名和密码！");
m_recordset.Close();
	}
else 
{
	if(m_recordset.GetRecordCount()==0)
	{// 判断用户是否不存在
		m_recordset.Close();
		MessageBox(" 该用户不存在！请更新数据库");
		return;
	}
	m_recordset.Edit();
	m_recordset.m_user = m_strUser;
	m_recordset.m_password = m_strPass;
	m_recordset.m_idAdmin= m_bIsAdmin;
	m_recordset.Update();
	MessageBox(" 用户修改成功！请记住用户名和密码！");
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
		MessageBox(" 打开数据库失败!"," 数据库错误",MB_OK);
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
	m_ctrList.InsertColumn(0," 用户名");
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
		MessageBox(" 打开数据库失败!"," 数据库错误",MB_OK);
		return ;
	}
	m_strPass = m_recordset.m_password;
	m_strRePass = m_strPass;
	m_bIsAdmin = m_recordset.m_idAdmin;
	m_recordset.Close();
	UpdateData(FALSE);
	*pResult = 0;
}
