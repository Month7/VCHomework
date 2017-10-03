// CalculatorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "math.h"
#include "Dlg2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCalculatorDlg dialog

CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCalculatorDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCalculatorDlg)
	m_Cnumber = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_number = 0.0;
	NumberState = 1;
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCalculatorDlg)
	DDX_Text(pDX, IDC_EDIT1, m_Cnumber);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialog)
	//{{AFX_MSG_MAP(CCalculatorDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton8)
	ON_BN_CLICKED(IDC_BUTTON9, OnButton9)
	ON_COMMAND(ID_1, On1)
	ON_BN_CLICKED(IDC_BUTTON10, OnButton10)
	//}}AFX_MSG_MAP
		ON_COMMAND_RANGE(IDC_NUMBER1,IDC_Point,OnNumberKey)
	ON_COMMAND_RANGE(IDC_NUMBER_PlusMinus,IDC_NUMBER_Equal,OnOperationKey)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCalculatorDlg message handlers

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	m_Menu.LoadMenu(IDR_MENU1);
	SetMenu(&m_Menu);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCalculatorDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);
		CRect ClientRect;
		GetClientRect(ClientRect);
		CBrush bkBrush(RGB(93, 101, 120));
		dc.FillRect(ClientRect, &bkBrush);
		CDialog::OnPaint();
	}
}
void CCalculatorDlg:: OnNumberKey(UINT nID)
{
	CString n;
	switch(nID)
	{
case IDC_NUMBER1:n="1"; break;
case IDC_NUMBER2:n="2"; break;
case IDC_NUMBER3:n="3"; break;
case IDC_NUMBER4:n="4"; break;
case IDC_NUMBER5:n="5"; break;
case IDC_NUMBER6:n="6"; break;
case IDC_NUMBER7:n="7"; break;
case IDC_NUMBER8:n="8"; break;
case IDC_NUMBER9:n="9"; break;
case IDC_NUMBER0:n="0"; break;
case IDC_Point:
	if (!m_number)   n = ".";  //如果输入一个点后，就不能再输入点
	else               n = "";

	if (m_Cnumber == "")
		m_Cnumber = "0";         //如果直接按小数点按钮，小数点前显示“0”
	m_number = 1;
	break;
				}
if(NumberState==1)
{
	m_Cnumber=m_Cnumber+n;
	number1=atof(m_Cnumber);
	UpdateData(FALSE);
}
else
{
	m_Cnumber=m_Cnumber+n;
	number2=atof(m_Cnumber);
	UpdateData(FALSE);
}
}
void CCalculatorDlg::OnOperationKey(UINT nID)
{
	m_number = atof(m_Cnumber);
	switch (nID)
	{
	case IDC_NUMBER_PlusMinus:
		m_number=-m_number;
		if (NumberState == 1)
			number1 = m_number;
		else
			number2 = m_number;
		m_Cnumber.Format("%g", m_number);
		UpdateData(FALSE);
		break;
	case IDC_NUMBER_BackSpace:
		m_number = (int)m_number / 10;
		if (NumberState == 1)
			number1 = m_number;
		else
			number2 = m_number;
		m_Cnumber.Format("%g", m_number);
		UpdateData(FALSE);
		if (m_number == 0)
		{
			m_Cnumber == "";
		}
		break;
	case IDC_NUMBER_Divide:cal();
		OperationState = 1;
		m_number = 0;
		m_Cnumber = "";
		NumberState = 2;
		break;
	case IDC_NUMBER_Multiply:cal();
		OperationState = 2;
		m_number = 0;
		m_Cnumber = "";
		NumberState = 2;
		break;
	case IDC_NUMBER_Add:cal();
		OperationState = 3;
		m_number = 0;
		m_Cnumber = "";
		NumberState = 2;
		break;
	case IDC_NUMBER_Substract:cal();
		OperationState = 4;
		m_number = 0;
		m_Cnumber = "";
		NumberState = 2;
		break;
	case IDC_NUMBER_Clear:
		number1 = number2 = m_number = 0;
		m_Cnumber.Format("%g", m_number);
		UpdateData(FALSE);
		m_Cnumber = "";
		NumberState = 1;
		break;
	case IDC_NUMBER_Sqrt:
		number1 = m_number = sqrt(number1);
		m_Cnumber.Format("%g", m_number);
		UpdateData(FALSE);
		break;
	case IDC_NUMBER_Derivative:
		number1 = m_number = (double)1 / number1;
		m_Cnumber.Format("%g", m_number);
		UpdateData(FALSE);
		break;
	case IDC_NUMBER_Equal:
		cal();
		break;
	}
}
void CCalculatorDlg::cal()
{
	m_number = atof(m_Cnumber);
	switch (OperationState)
	{
	case 1:
		m_number = (double)number1 / number2;
		NumberState = 1;
		m_Cnumber.Format("%g", m_number);
		UpdateData(FALSE);
		break;
	case 2:
		m_number = (double)number1 * number2;
		NumberState = 1;
		m_Cnumber.Format("%g", m_number);
		UpdateData(FALSE);
		break;
	case 3:
		m_number = (double)number1 + number2;
		NumberState = 1;
		m_Cnumber.Format("%g", m_number);
		UpdateData(FALSE);
		break;
	case 4:
		m_number = (double)number1 - number2;
		NumberState = 1;
		m_Cnumber.Format("%g", m_number);
		UpdateData(FALSE);
		break;
	}
	number1 = m_number;
	OperationState = 0;
}
// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCalculatorDlg::OnPlusMinus6() 
{
	// TODO: Add your control notification handler code here
	
}

void CCalculatorDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	m_number = atof(m_Cnumber);
	m_number = cos(m_number*3.1415926 / 180);
	m_Cnumber.Format("%g", m_number);
	UpdateData(FALSE);
}

void CCalculatorDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	m_number=atof(m_Cnumber);
	m_number=sin(m_number*3.1415926/180);
	m_Cnumber.Format("%g",m_number);
	UpdateData(FALSE);
}

void CCalculatorDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
	long n;
	n = atoi(m_Cnumber);
	for (long i = n - 1; i >= 1; --i)
	{
		n *= i;
	}
	m_Cnumber.Format("%d", n);
	UpdateData(FALSE);
}

void CCalculatorDlg::OnButton4() 
{
	// TODO: Add your control notification handler code here
	m_number = atof(m_Cnumber);
	m_number = tan(m_number*3.1415926 / 180);
	m_Cnumber.Format("%g", m_number);
	UpdateData(FALSE);
}

void CCalculatorDlg::OnButton5() 
{
	// TODO: Add your control notification handler code here
	m_Cnumber += "3.14";
	UpdateData(FALSE);
}

void CCalculatorDlg::OnButton6() 
{
	// TODO: Add your control notification handler code here
	m_number = atof(m_Cnumber);
	m_number = log(m_number);
	m_Cnumber.Format("%g", m_number);
	UpdateData(FALSE);
}

void CCalculatorDlg::OnButton7() 
{
	// TODO: Add your control notification handler code here
	m_number = atof(m_Cnumber);
	m_number = log(m_number)/log(10);
	m_Cnumber.Format("%g", m_number);
	UpdateData(FALSE);
}

void CCalculatorDlg::OnButton8() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int i, j, m;
	int sum;
	sum = 0;
	m = m_Cnumber.GetLength();
	for (i = m - 1; i >= 0; i--)
		sum += ((m_Cnumber[i] - '0') << (m - i - 1));//<<是位操作符，
	                                                 // 表示二进制数向左移位
	if (sum == 0)
	{
		m_Cnumber = "0";
	}

	int a[10];
	i = 0;
	while (sum)
	{
		a[i] = sum % 8;//这部分是十进制转八进制的。
		sum /= 8;
		i++;
	}
	char str[10];
	m_Cnumber = "";

	for (j = i - 1; j >= 0; j--)
		m_Cnumber += itoa(a[j], str, 10);//itoa(a[j],str,10)，将这个八进制转换成十进制存在str 中
	UpdateData(FALSE);
}

void CCalculatorDlg::OnButton9() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int i, j, m;
	int sum;
	sum = 0;
	m = m_Cnumber.GetLength();
	for (i = m - 1; i >= 0; i--)
		sum += ((m_Cnumber[i] - '0') << (m - i - 1));//<<是位操作符，
													 // 表示二进制数向左移位
	if (sum == 0)
	{
		m_Cnumber = "0";
	}

	int a[10];
	i = 0;
	while (sum)
	{
		a[i] = sum % 8;//这部分是十进制转八进制的，原理同上。
		sum /= 8;
		i++;
	}
	char str[10];
	m_Cnumber = "";

	for (j = i - 1; j >= 0; j--)
		m_Cnumber += itoa(a[j], str, 2);//itoa(a[j],str,10)，将这个八进制转换成二进制存在str 中
	UpdateData(FALSE);
}

void CCalculatorDlg::On1() 
{
	// TODO: Add your command handler code here
	CDlg2 dlg;
	dlg.DoModal();
}

void CCalculatorDlg::OnButton10() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int i, j, m;
	int sum;
	sum = 0;
	m = m_Cnumber.GetLength();
	for (i = m - 1; i >= 0; i--)
		sum += ((m_Cnumber[i] - '0') << (m - i - 1));//<<是位操作符，
													 // 表示二进制数向左移位
	if (sum == 0)
	{
		m_Cnumber = "0";
	}

	int a[10];
	i = 0;
	while (sum)
	{
		a[i] = sum % 8;//这部分是十进制转八进制的，原理同上。
		sum /= 8;
		i++;
	}
	char str[10];
	m_Cnumber = "";

	for (j = i - 1; j >= 0; j--)
		m_Cnumber += itoa(a[j], str, 8);//itoa(a[j],str,10)，将这个八进制转换成二进制存在str 中
	UpdateData(FALSE);
}
