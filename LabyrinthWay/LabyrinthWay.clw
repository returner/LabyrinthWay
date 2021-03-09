; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLabyrinthWayView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "labyrinthway.h"
LastPage=0

ClassCount=10
Class1=CCutDlg
Class2=CInformationDlg
Class3=CLabyrinthWayApp
Class4=CAboutDlg
Class5=CLabyrinthWayDoc
Class6=CLabyrinthWayView
Class7=CMainFrame
Class8=CPointInt

ResourceCount=6
Resource1=IDD_CUT
Resource2=IDD_ABOUTBOX
Resource3=IDD_DIALOG_HELP
Resource4=IDD_WAIT_DIALOG
Class9=CWaitDialog
Resource5=IDD_INFORMATION
Class10=CHelpDialog
Resource6=IDR_MAINFRAME

[CLS:CCutDlg]
Type=0
BaseClass=CDialog
HeaderFile=CutDlg.h
ImplementationFile=CutDlg.cpp
Filter=D
VirtualFilter=dWC
LastObject=IDCANCEL

[CLS:CInformationDlg]
Type=0
BaseClass=CDialog
HeaderFile=InformationDlg.h
ImplementationFile=InformationDlg.cpp

[CLS:CLabyrinthWayApp]
Type=0
BaseClass=CWinApp
HeaderFile=LabyrinthWay.h
ImplementationFile=LabyrinthWay.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=LabyrinthWay.cpp
ImplementationFile=LabyrinthWay.cpp
LastObject=CAboutDlg

[CLS:CLabyrinthWayDoc]
Type=0
BaseClass=CDocument
HeaderFile=LabyrinthWayDoc.h
ImplementationFile=LabyrinthWayDoc.cpp

[CLS:CLabyrinthWayView]
Type=0
BaseClass=CScrollView
HeaderFile=LabyrinthWayView.h
ImplementationFile=LabyrinthWayView.cpp
Filter=C
VirtualFilter=VWC
LastObject=ID_FILE_SAVE

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
LastObject=CMainFrame

[CLS:CPointInt]
Type=0
BaseClass=CWnd
HeaderFile=PointInt.h
ImplementationFile=PointInt.cpp

[DLG:IDD_CUT]
Type=1
Class=CCutDlg
ControlCount=15
Control1=IDC_EDIT_X,edit,1350631552
Control2=IDC_EDIT_Y,edit,1350631552
Control3=IDOK,button,1342242817
Control4=IDC_EDIT_RED,edit,1350631552
Control5=IDC_EDIT_GREEN,edit,1350631552
Control6=IDC_EDIT_BLUE,edit,1350631552
Control7=IDCANCEL,button,1342242816
Control8=IDC_STATIC,button,1342177287
Control9=IDC_STATIC,button,1342177287
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352

[DLG:IDD_INFORMATION]
Type=1
Class=CInformationDlg
ControlCount=20
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC_MOUSE_X,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC_MOUSE_Y,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATI_CELL_X,static,1342308352
Control11=IDC_STATIC_CELL_Y,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC_CELL_NUMBER,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_EDIT_GROUND,edit,1350631552
Control18=IDC_EDIT_DECISION,edit,1350631552
Control19=IDC_EDIT_TIME,edit,1350631552
Control20=IDC_BUTTON_INPUT,button,1342242816

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=IDM_DATA_FILE_OPEN
Command4=ID_FILE_SAVE
Command5=IDM_VIEW_GROUND
Command6=IDM_VIEW_DECISION
Command7=IDM_VIEW_TIME
Command8=IDM_DIALOG_HELP
CommandCount=8

[MNU:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_OPEN
Command2=IDM_DATA_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=IDM_VIEW_GROUND
Command17=IDM_VIEW_DECISION
Command18=IDM_VIEW_TIME
Command19=IDM_DIALOG_HELP
Command20=ID_APP_ABOUT
CommandCount=20

[ACL:IDR_MAINFRAME]
Type=1
Class=?
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

[DLG:IDD_WAIT_DIALOG]
Type=1
Class=CWaitDialog
ControlCount=2
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352

[CLS:CWaitDialog]
Type=0
HeaderFile=WaitDialog.h
ImplementationFile=WaitDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=CWaitDialog

[DLG:IDD_DIALOG_HELP]
Type=1
Class=CHelpDialog
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352

[CLS:CHelpDialog]
Type=0
HeaderFile=HelpDialog.h
ImplementationFile=HelpDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=CHelpDialog
VirtualFilter=dWC

