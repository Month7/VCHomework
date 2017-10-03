// StudentDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Student.h"
#include "StudentDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStudentDlg dialog


CStudentDlg::CStudentDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStudentDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStudentDlg)
	m_strClass = _T("");
	m_strMajor = _T("");
	m_strDepartment = _T("");
	//}}AFX_DATA_INIT
}


void CStudentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStudentDlg)
	DDX_Control(pDX, IDC_DEPARTMENT, m_ctrDepartment);
	DDX_Control(pDX, IDC_MAJOR, m_ctrMajor);
	DDX_Control(pDX, IDC_CLASS, m_ctrClass);
	DDX_Control(pDX, IDC_LIST1, m_ctrlList);
	DDX_Text(pDX, IDC_CLASS, m_strClass);
	DDX_Text(pDX, IDC_MAJOR, m_strMajor);
	DDX_Text(pDX, IDC_DEPARTMENT, m_strDepartment);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStudentDlg, CDialog)
	//{{AFX_MSG_MAP(CStudentDlg)
	ON_BN_CLICKED(IDC_BUTTON_NEW, OnButtonNew)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY, OnButtonModify)
	ON_BN_CLICKED(IDC_BUTTON_DELETE1, OnButtonDelete1)
	ON_BN_CLICKED(IDC_BUTTON_BROWSE, OnButtonBrowse)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, OnButtonSearch)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStudentDlg message handlers

void CStudentDlg::OnButtonNew() 
{
	// TODO: Add your control notification handler code here
	CStudentInfoDlg Dlg;
	if(IDOK==Dlg.DoModal())
	{// 添加新记录
		if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE))
		{
			AfxMessageBox(" 打开数据库失败!");
			return ;
		}
		m_recordset.AddNew();
		m_recordset.m_code =Dlg.m_strCode ;
		m_recordset.m_name =Dlg.m_strName ;
		m_recordset.m_sex =Dlg.m_strSex ;
		m_recordset.m_birthday =Dlg.m_tmBirth ;
		m_recordset.m_department =Dlg.m_strDepartment ;
		m_recordset.m_major =Dlg.m_strMajor ;
		m_recordset.m_class =Dlg.m_strClass ;
		m_recordset.m_phone =Dlg.m_strPhone ;
		m_recordset.m_address =Dlg.m_strAddress ;
		m_recordset.Update();
		m_recordset.Close();
		CString strSQL= "select * from student ";
			RefreshData(strSQL);
	}
}

void CStudentDlg::OnButtonModify() 
{
	// TODO: Add your control notification handler code here
	CStudentInfoDlg Dlg;
	UpdateData();
	int i = m_ctrlList.GetSelectionMark();
	if(0>i)
	{
		AfxMessageBox(" 请选择一条记录进行修改！");
		return;
}
	Dlg.m_strCode=m_ctrlList.GetItemText(i,0);
	if(IDOK==Dlg.DoModal())
	{// 修改记录
		CString strSQL;
		strSQL.Format("select * from student where code = '%s'",Dlg.m_strCode);
		if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
		{
			AfxMessageBox(" 打开数据库失败!");
			return ;
		}
		m_recordset.Edit();
		m_recordset.m_code =Dlg.m_strCode ;
		m_recordset.m_name =Dlg.m_strName ;
		m_recordset.m_sex =Dlg.m_strSex ;
		m_recordset.m_birthday =Dlg.m_tmBirth ;
		m_recordset.m_department =Dlg.m_strDepartment ;
		m_recordset.m_major =Dlg.m_strMajor ;
		m_recordset.m_class =Dlg.m_strClass ;
		m_recordset.m_phone =Dlg.m_strPhone ;
		m_recordset.m_address =Dlg.m_strAddress ;
		m_recordset.Update();
		m_recordset.Close();
strSQL= "select * from student ";
	}
}

void CStudentDlg::OnButtonDelete1() 
{
	// TODO: Add your control notification handler code here
	int i = m_ctrlList.GetSelectionMark();
	if(0>i)
	{
		AfxMessageBox(" 请选择一条记录进行查看！");
		return;
	}
	CString strSQL;
	strSQL.Format("select * from student where code = '%s'",m_ctrlList.GetItemText(i,0));
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		AfxMessageBox(" 打开数据库失败!");
		return ;
	}
	m_recordset.Delete();
	m_recordset.Close();
strSQL= "select * from student";
	RefreshData(strSQL);
}

void CStudentDlg::OnButtonBrowse() 
{
	// TODO: Add your control notification handler code here
	CStudentInfoDlg Dlg;
	UpdateData();
	int i = m_ctrlList.GetSelectionMark();
	if(0>i)
	{
		AfxMessageBox(" 请选择一条记录进行查看！");
		return;
	}
	Dlg.m_strCode=m_ctrlList.GetItemText(i,0);
	Dlg.DoModal();
}

void CStudentDlg::OnButtonSearch() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	CString strSQL,strTemp;
	strTemp="";
	BOOL bHaveCon = FALSE;
	if(m_strDepartment!="")
	{
		strSQL.Format("select * from student where department = '%s' ",m_strDepartment);
		bHaveCon = TRUE;
	}
	if(m_strMajor!="")
	{
		if(bHaveCon)
		{
			strTemp.Format(" major = '%s' ",m_strMajor);
			strSQL=strSQL+ " and " + strTemp;
		}
		else
		{
			strSQL.Format("select * from student where major = '%s' ",m_strMajor);
		}
bHaveCon=TRUE;
	}
	if(m_strClass!="")
{
		if(bHaveCon)
		{
			strTemp.Format(" class = '%s' ",m_strClass);
			strSQL=strSQL+ " and " + strTemp;
		}
		else
		{
			strSQL.Format("select * from student where class = '%s' ",m_strClass);
		}
		bHaveCon=TRUE;
	}
	if(!bHaveCon)
	{
		strSQL="select * from student";
}
	RefreshData(strSQL);
}

//DEL void CStudentDlg::RefreshData()
//DEL {
//DEL 	
//DEL }

void CStudentDlg::RefreshData(CString strSQL)
{
	m_ctrlList.DeleteAllItems();
	m_ctrlList.SetRedraw(FALSE);
	UpdateData(TRUE);
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox(" 打开数据库失败!"," 数据库错误",MB_OK);
		return ;
}
	int i=0;
	CString strTime;
	while(!m_recordset.IsEOF())
	{
		m_ctrlList.InsertItem(i,m_recordset.m_code);
		m_ctrlList.SetItemText(i,1,m_recordset.m_name);
		m_ctrlList.SetItemText(i,2,m_recordset.m_sex);
		strTime.Format("%d-%d-%d",m_recordset.m_birthday.GetYear(),m_recordset.m_birthday.GetMonth(),m_recordset.m_birthday.GetDay());
		m_ctrlList.SetItemText(i,3,strTime);
		m_ctrlList.SetItemText(i,4,m_recordset.m_department);
		m_ctrlList.SetItemText(i,5,m_recordset.m_major);
		m_ctrlList.SetItemText(i,6,m_recordset.m_class);
		m_ctrlList.SetItemText(i,7,m_recordset.m_phone);
		m_ctrlList.SetItemText(i,8,m_recordset.m_address);
		i++;
		m_recordset.MoveNext();
	}
	m_recordset.Close();
	m_ctrlList.SetRedraw(TRUE);
}

BOOL CStudentDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CDialog::OnInitDialog();
	m_ctrlList.InsertColumn(0," 学号");
	m_ctrlList.InsertColumn(1," 姓名");
    m_ctrlList.InsertColumn(2," 性别");
	m_ctrlList.InsertColumn(3," 出生年月");
	m_ctrlList.InsertColumn(4," 所在院系");
	m_ctrlList.InsertColumn(5," 专业");
	m_ctrlList.InsertColumn(6," 班级");
	m_ctrlList.InsertColumn(7," 联系电话");
	m_ctrlList.InsertColumn(8," 家庭地址");
	m_ctrlList.SetColumnWidth(0,60);
	m_ctrlList.SetColumnWidth(1,80);
	m_ctrlList.SetColumnWidth(2,40);
	m_ctrlList.SetColumnWidth(3,60);
	m_ctrlList.SetColumnWidth(4,100);
	m_ctrlList.SetColumnWidth(5,100);
	m_ctrlList.SetColumnWidth(6,100);
	m_ctrlList.SetColumnWidth(7,60);
	m_ctrlList.SetColumnWidth(8,100);
	m_ctrlList.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	CString strSQL= "select * from student ";
	RefreshData(strSQL);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
