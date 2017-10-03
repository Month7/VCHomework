; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CStudentbaView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "studentba.h"
LastPage=0

ClassCount=6
Class1=CStudentbaApp
Class2=CStudentbaDoc
Class3=CStudentbaView
Class4=CMainFrame
Class6=CAboutDlg

ResourceCount=7
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CStudentbaSet
Resource7=IDD_STUDENTBA_FORM

[CLS:CStudentbaApp]
Type=0
HeaderFile=studentba.h
ImplementationFile=studentba.cpp
Filter=N

[CLS:CStudentbaDoc]
Type=0
HeaderFile=studentbaDoc.h
ImplementationFile=studentbaDoc.cpp
Filter=N

[CLS:CStudentbaView]
Type=0
HeaderFile=studentbaView.h
ImplementationFile=studentbaView.cpp
Filter=D
BaseClass=CRecordView
VirtualFilter=RVWC
LastObject=CStudentbaView


[CLS:CStudentbaSet]
Type=0
HeaderFile=studentbaSet.h
ImplementationFile=studentbaSet.cpp
Filter=N

[DB:CStudentbaSet]
DB=1
DBType=ODBC
ColumnCount=7
Column1=[±àºÅ], 4, 4
Column2=[Num], 12, 100
Column3=[Name], 12, 100
Column4=[NormalScore], 4, 4
Column5=[MidScore], 4, 4
Column6=[FinalScore], 4, 4
Column7=[SumScore], 4, 4


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=studentba.cpp
ImplementationFile=studentba.cpp
Filter=D

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
Command1=ID_FILE_PRINT
Command2=ID_FILE_PRINT_PREVIEW
Command3=ID_FILE_PRINT_SETUP
Command4=ID_APP_EXIT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_RECORD_FIRST
Command10=ID_RECORD_PREV
Command11=ID_RECORD_NEXT
Command12=ID_RECORD_LAST
Command13=ID_VIEW_TOOLBAR
Command14=ID_VIEW_STATUS_BAR
Command15=ID_APP_ABOUT
CommandCount=15

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_PRINT
Command2=ID_EDIT_UNDO
Command3=ID_EDIT_CUT
Command4=ID_EDIT_COPY
Command5=ID_EDIT_PASTE
Command6=ID_EDIT_UNDO
Command7=ID_EDIT_CUT
Command8=ID_EDIT_COPY
Command9=ID_EDIT_PASTE
Command10=ID_NEXT_PANE
Command11=ID_PREV_PANE
CommandCount=11

[DLG:IDD_STUDENTBA_FORM]
Type=1
Class=CStudentbaView
ControlCount=22
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT2,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT3,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT4,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDIT5,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,button,1342177287
Control12=IDC_STATIC,button,1342177287
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_EDIT6,edit,1350631552
Control16=IDC_EDIT7,edit,1350631552
Control17=IDC_BUTTON1,button,1342242816
Control18=IDC_BUTTON2,button,1342242816
Control19=IDC_BUTTON3,button,1342242816
Control20=IDC_BUTTON4,button,1342242816
Control21=IDC_BUTTON5,button,1342242816
Control22=IDC_BUTTON6,button,1342242816

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_EDIT_CUT
Command2=ID_EDIT_COPY
Command3=ID_EDIT_PASTE
Command4=ID_FILE_PRINT
Command5=ID_RECORD_FIRST
Command6=ID_RECORD_PREV
Command7=ID_RECORD_NEXT
Command8=ID_RECORD_LAST
Command9=ID_APP_ABOUT
CommandCount=9

