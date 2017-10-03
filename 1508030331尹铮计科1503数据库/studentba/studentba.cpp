// studentba.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "studentba.h"

#include "MainFrm.h"
#include "studentbaSet.h"
#include "studentbaDoc.h"
#include "studentbaView.h"
#include "odbcinst.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStudentbaApp

BEGIN_MESSAGE_MAP(CStudentbaApp, CWinApp)
	//{{AFX_MSG_MAP(CStudentbaApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStudentbaApp construction

CStudentbaApp::CStudentbaApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CStudentbaApp object

CStudentbaApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CStudentbaApp initialization

BOOL CStudentbaApp::InitInstance()
{
	CString m_strExePath;
	char path[MAX_PATH] = {'\0'}; GetModuleFileName(NULL,path,MAX_PATH);//得到执行文件名
	//GetModuleFileName：The GetModuleFileName function
	//retrieves the full path and filename for the executable file
	//containing the specified module.
	
	
	m_strExePath.Format("%s", path); int iPosition;
	iPosition = m_strExePath.ReverseFind('\\'); 
	m_strExePath = m_strExePath.Left(iPosition + 1);
	CString strAccessPath = m_strExePath + "student1.mdb";
	//得到这个数据库文件的路径
	int iLen = strAccessPath.GetLength(); 
	char  cpConfig[MAX_PATH];
	//在这个联结串中靠\0 来分开数据源每个配置信息项
	strcpy(cpConfig, "DSN=student\0"); strcpy(cpConfig + 12,"DBQ="); 
	strcpy(cpConfig + 16,strAccessPath); strcpy(cpConfig + 16 + iLen, "\0");
	strcpy(cpConfig + 17 + iLen, "DEFAULTDIR="); strcpy(cpConfig + 17 + iLen + 11, m_strExePath);
	strcpy(cpConfig + 27 + iLen + m_strExePath.GetLength(), "\0\0");//设置odbc 数据源
		if(!SQLConfigDataSource(NULL,ODBC_ADD_SYS_DSN, "Microsoft Access Driver (*.mdb)\0",cpConfig))
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CStudentbaDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CStudentbaView));
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it.
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}


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
		// No message handlers
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

// App command to run the dialog
void CStudentbaApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CStudentbaApp message handlers

