// HelpDialog.cpp : implementation file
//

#include "stdafx.h"
#include "NewTetris.h"
#include "HelpDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// HelpDialog dialog


HelpDialog::HelpDialog(CWnd* pParent /*=NULL*/)
	: CDialog(HelpDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(HelpDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void HelpDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(HelpDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(HelpDialog, CDialog)
	//{{AFX_MSG_MAP(HelpDialog)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// HelpDialog message handlers

BOOL HelpDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	GetDlgItem(IDC_LINK)->GetWindowRect(&m_pRectLink); //将静态文本的屏幕坐标存放在m—pRectLink中
	ScreenToClient(&m_pRectLink);//将屏幕坐标转换为客户坐标
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void HelpDialog::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	//下面设置鼠标在静态文本区时，将光标设成小手状
	if (point.x>m_pRectLink.left&&point.x<m_pRectLink.right&&point.y>m_pRectLink.top&&point.y<m_pRectLink.bottom)
		
		//此处添加判断坐标算法
		
	{ 
		HCURSOR hCursor;
		hCursor=AfxGetApp()->LoadCursor(IDC_HAND);  
		//将鼠标设为小手状
		SetCursor(hCursor);
	}
	//下面语句用来设置默认(箭头)鼠标形状,一般鼠标移开后窗口会自动恢复默认鼠标形状，可酌情添加
//	if (...)//此处酌情添加鼠标不在静态文本区的坐标算法,本例可不加
		
// 	{ 
// 		hCURSOR hCursor;
// 	
// 	hCursor=AfxGetApp()->LoadStandardCursor(IDC_IBEAM);
// 	
// 	//将光标设为默认值(箭头)
// 	
// SetCursor(hCursor); }
	CDialog::OnMouseMove(nFlags, point);
}

void HelpDialog::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (point.x>m_pRectLink.left&&point.x<m_pRectLink.right&&point.y>m_pRectLink.top&&point.y<m_pRectLink.bottom)
		
		//此处添加判断坐标算法
		
	{ if (nFlags==MK_LBUTTON)//鼠标左键按下
	
	{ //为改善鼠标效果，此处加入以上变换鼠标形状的代码
		
		ShellExecute(0, NULL, "http://blog.csdn.net/qq_29187355?", NULL,NULL, SW_NORMAL);
		//也可以添加电子邮件的链接
	}
	}
	CDialog::OnLButtonDown(nFlags, point);
}
