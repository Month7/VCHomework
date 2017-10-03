; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=SCORE_UP_Dialog
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Student.h"
LastPage=0

ClassCount=20
Class1=CStudentApp
Class2=CStudentDoc
Class3=CStudentView
Class4=CMainFrame

ResourceCount=12
Resource1=IDD_DIALOG_STUDENT
Class5=CAboutDlg
Resource2=IDD_DIALOG_LOGIN
Class6=CUserLogin
Class7=CUserSet
Class8=CUserSet1
Class9=CUserSet2
Resource3=IDD_DIALOG_STUDENT_INFO
Class10=CUserDlg
Resource4=IDD_DIALOG_USER
Class11=CStudentDlg
Resource5=IDD_DIALOG_SCORE_INPUT
Class12=CStudentInfoDlg
Class13=CStudentSet
Class14=CStudentSet1
Resource6=IDD_ABOUTBOX
Class15=CScoreInputDlg
Class16=CScoreSet
Resource7=IDD_DIALOG_SCORE
Resource8=IDD_DIALOG_WRITER
Class17=CScore
Class18=SEARCH
Resource9=IDD_DIALOG_SCORE_UP
Class19=WriterDialog
Resource10=IDR_MAINFRAME
Class20=SCORE_UP_Dialog
Resource11=IDD_DIALOG_SEARCH
Resource12=IDD_DIALOG1

[CLS:CStudentApp]
Type=0
HeaderFile=Student.h
ImplementationFile=Student.cpp
Filter=N

[CLS:CStudentDoc]
Type=0
HeaderFile=StudentDoc.h
ImplementationFile=StudentDoc.cpp
Filter=N
LastObject=CStudentDoc

[CLS:CStudentView]
Type=0
HeaderFile=StudentView.h
ImplementationFile=StudentView.cpp
Filter=C
LastObject=IDC_WRITER
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=Student.cpp
ImplementationFile=Student.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_USER_MSG
Command2=ID_STU_MSG
Command3=ID_SCORE_INPUT
Command4=ID_SCORE_SEARCH
Command5=ID_APP_ABOUT
Command6=ID_APP_EXIT
Command7=IDC_WRITER
CommandCount=7

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[DLG:IDD_DIALOG_LOGIN]
Type=1
Class=CUserLogin
ControlCount=5
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_USER,edit,1350631552
Control4=IDC_PASSWD,edit,1350631584
Control5=IDC_BnClickedOk,button,1342242816

[CLS:CUserLogin]
Type=0
HeaderFile=UserLogin.h
ImplementationFile=UserLogin.cpp
BaseClass=CDialog
Filter=D
LastObject=CUserLogin
VirtualFilter=dWC

[CLS:CUserSet]
Type=0
HeaderFile=UserSet.h
ImplementationFile=UserSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CUserSet

[DB:CUserSet]
DB=1
DBType=ODBC
ColumnCount=3
Column1=[user], 12, 510
Column2=[password], 12, 510
Column3=[idAdmin], -7, 1

[CLS:CUserSet1]
Type=0
HeaderFile=UserSet1.h
ImplementationFile=UserSet1.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:CUserSet1]
DB=1
DBType=ODBC
ColumnCount=3
Column1=[user], 12, 510
Column2=[password], 12, 510
Column3=[idAdmin], -7, 1

[CLS:CUserSet2]
Type=0
HeaderFile=UserSet2.h
ImplementationFile=UserSet2.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CUserSet2

[DB:CUserSet2]
DB=1
DBType=ODBC
ColumnCount=3
Column1=[user], 12, 510
Column2=[password], 12, 510
Column3=[idAdmin], -7, 1

[DLG:IDD_DIALOG_USER]
Type=1
Class=CUserDlg
ControlCount=13
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_USERNAME,edit,1350631552
Control6=IDC_PASSWORD1,edit,1350631584
Control7=IDC_PASSWORD2,edit,1350631584
Control8=IDC_BUTTON_NEW,button,1342242816
Control9=IDC_BUTTON_DELETE,button,1342242816
Control10=IDOK,button,1342242816
Control11=IDC_LIST_USERNAME,SysListView32,1350631429
Control12=IDC_CHECK1,button,1342242819
Control13=IDOK2,button,1342242817

[CLS:CUserDlg]
Type=0
HeaderFile=UserDlg.h
ImplementationFile=UserDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CUserDlg
VirtualFilter=dWC

[DLG:IDD_DIALOG_STUDENT]
Type=1
Class=CStudentDlg
ControlCount=14
Control1=IDC_BUTTON_NEW,button,1342242816
Control2=IDC_BUTTON_MODIFY,button,1342242816
Control3=IDC_BUTTON_DELETE1,button,1342242816
Control4=IDC_BUTTON_BROWSE,button,1342242816
Control5=IDC_BUTTON_SEARCH,button,1342242816
Control6=IDC_STATIC,button,1342177287
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_DEPARTMENT,edit,1350631552
Control10=IDC_MAJOR,edit,1350631552
Control11=IDC_CLASS,edit,1350631552
Control12=IDC_STATIC,static,1342308352
Control13=IDC_LIST1,SysListView32,1350631425
Control14=IDOK,button,1342242817

[CLS:CStudentDlg]
Type=0
HeaderFile=StudentDlg.h
ImplementationFile=StudentDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CStudentDlg
VirtualFilter=dWC

[DLG:IDD_DIALOG_STUDENT_INFO]
Type=1
Class=CStudentInfoDlg
ControlCount=20
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STUCODE,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STUDEPARTMENT,edit,1350631552
Control12=IDC_STUCLASS,edit,1350631552
Control13=IDC_STUADDR,edit,1350631552
Control14=IDC_STUNAME,edit,1350631552
Control15=IDC_STUMAJOR,edit,1350631552
Control16=IDC_STUPHONE,edit,1350631552
Control17=IDC_STUSEX,combobox,1344340226
Control18=IDC_STUBIRTH,SysDateTimePick32,1342242848
Control19=IDOK2,button,1342242817
Control20=IDCANCEL2,button,1342242816

[CLS:CStudentInfoDlg]
Type=0
HeaderFile=StudentInfoDlg.h
ImplementationFile=StudentInfoDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_STUSEX
VirtualFilter=dWC

[CLS:CStudentSet]
Type=0
HeaderFile=StudentSet.h
ImplementationFile=StudentSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:CStudentSet]
DB=1
DBType=ODBC
ColumnCount=9
Column1=[code], 12, 510
Column2=[name], 12, 510
Column3=[sex], 12, 510
Column4=[birth], 12, 510
Column5=[address], 12, 510
Column6=[phnoe], 12, 510
Column7=[department], 12, 510
Column8=[major], 12, 510
Column9=[class], 12, 510

[CLS:CStudentSet1]
Type=0
HeaderFile=StudentSet1.h
ImplementationFile=StudentSet1.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:CStudentSet1]
DB=1
DBType=ODBC
ColumnCount=9
Column1=[code], 12, 510
Column2=[name], 12, 510
Column3=[sex], 12, 510
Column4=[birthday], 11, 16
Column5=[address], 12, 510
Column6=[phone], 12, 510
Column7=[department], 12, 510
Column8=[major], 12, 510
Column9=[class], 12, 510

[DLG:IDD_DIALOG_SCORE_INPUT]
Type=1
Class=CScoreInputDlg
ControlCount=10
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_CLASS1,edit,1350631552
Control6=IDC_EXAMCLASS,edit,1350631552
Control7=IDC_TIME,edit,1350631552
Control8=IDC_SUBJECT,edit,1350631552
Control9=IDC_BUTTON_INPUT,button,1342242816
Control10=IDC_LIST1,SysListView32,1350631425

[CLS:CScoreInputDlg]
Type=0
HeaderFile=ScoreInputDlg.h
ImplementationFile=ScoreInputDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CScoreInputDlg
VirtualFilter=dWC

[CLS:CScoreSet]
Type=0
HeaderFile=ScoreSet.h
ImplementationFile=ScoreSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:CScoreSet]
DB=1
DBType=ODBC
ColumnCount=10
Column1=[ID], 4, 4
Column2=[class], 12, 510
Column3=[time], 12, 510
Column4=[code], 12, 510
Column5=[name], 12, 510
Column6=[subject], 12, 510
Column7=[type], 12, 510
Column8=[score], 4, 4
Column9=[makeup_score], 4, 4
Column10=[absent], 12, 510

[DLG:IDD_DIALOG_SCORE]
Type=1
Class=CScore
ControlCount=7
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT_SCORE,edit,1350631552
Control4=IDC_EDIT_MAKEUP,edit,1350631552
Control5=IDC_CHECK1,button,1342242819
Control6=IDOK,button,1342242816
Control7=IDCANCLE,button,1342242817

[CLS:CScore]
Type=0
HeaderFile=Score.h
ImplementationFile=Score.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CScore

[DLG:IDD_DIALOG_SEARCH]
Type=1
Class=SEARCH
ControlCount=12
Control1=IDC_BUTTON1_MODIFY,button,1342242816
Control2=IDC_BUTTON1_DELETE,button,1342242816
Control3=IDC_BnClickedButtonSearch,button,1342242816
Control4=IDC_STATIC,button,1342177287
Control5=IDC_STATIC,static,1342308352
Control6=IDC_SE_CLASS,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_SE_NAME,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_SE_SUB,edit,1350631552
Control11=IDOK,button,1342373888
Control12=IDC_LIST1,SysListView32,1350631425

[CLS:SEARCH]
Type=0
HeaderFile=SEARCH.h
ImplementationFile=SEARCH.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_APP_ABOUT
VirtualFilter=dWC

[DLG:IDD_DIALOG_WRITER]
Type=1
Class=WriterDialog
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[CLS:WriterDialog]
Type=0
HeaderFile=WriterDialog.h
ImplementationFile=WriterDialog.cpp
BaseClass=CDialog
Filter=D

[DLG:IDD_DIALOG_SCORE_UP]
Type=1
Class=SCORE_UP_Dialog
ControlCount=5
Control1=IDOK,button,1342242816
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT2,edit,1350631552

[CLS:SCORE_UP_Dialog]
Type=0
HeaderFile=SCORE_UP_Dialog.h
ImplementationFile=SCORE_UP_Dialog.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_APP_ABOUT
VirtualFilter=dWC

[DLG:IDD_DIALOG1]
Type=1
Class=?
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

