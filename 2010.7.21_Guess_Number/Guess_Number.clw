; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CBKListBox
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Guess_Number.h"

ClassCount=8
Class1=CGuess_NumberApp
Class2=CGuess_NumberDlg
Class3=CAboutDlg

ResourceCount=6
Resource1=IDD_DIALOG1
Resource2=IDR_MAINFRAME
Resource3=IDD_GUESS_NUMBER_DIALOG
Class4=CStart
Class5=CMyEdit
Class6=CBKListBox
Resource4=IDD_DIALOG2
Class7=CInfoDlg
Resource5=IDD_ABOUTBOX
Class8=CSetDlg
Resource6=IDD_DIALOG3

[CLS:CGuess_NumberApp]
Type=0
HeaderFile=Guess_Number.h
ImplementationFile=Guess_Number.cpp
Filter=N

[CLS:CGuess_NumberDlg]
Type=0
HeaderFile=Guess_NumberDlg.h
ImplementationFile=Guess_NumberDlg.cpp
Filter=D
LastObject=CGuess_NumberDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=Guess_NumberDlg.h
ImplementationFile=Guess_NumberDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_GUESS_NUMBER_DIALOG]
Type=1
Class=CGuess_NumberDlg
ControlCount=5
Control1=IDC_LIST1,button,1342178055
Control2=IDC_BUTTON1,button,1342242816
Control3=IDC_BUTTON2,button,1342242816
Control4=IDC_BUTTON3,button,1342242816
Control5=IDC_BUTTON4,button,1342242816

[DLG:IDD_DIALOG1]
Type=1
Class=CStart
ControlCount=4
Control1=IDC_STATIC,button,1342178055
Control2=IDC_EDIT1,edit,1350631553
Control3=IDC_BUTTON1,button,1342242816
Control4=IDC_STATIC1,static,1342308865

[CLS:CStart]
Type=0
HeaderFile=Start.h
ImplementationFile=Start.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT1
VirtualFilter=dWC

[CLS:CMyEdit]
Type=0
HeaderFile=MyEdit.h
ImplementationFile=MyEdit.cpp
BaseClass=CEdit
Filter=W
VirtualFilter=WC

[CLS:CBKListBox]
Type=0
HeaderFile=BKListBox.h
ImplementationFile=BKListBox.cpp
BaseClass=CListBox
Filter=W
LastObject=IDC_EDIT1

[DLG:IDD_DIALOG2]
Type=1
Class=CInfoDlg
ControlCount=3
Control1=IDC_TAB1,SysTabControl32,1342177280
Control2=IDC_STATIC2,static,1342308352
Control3=IDC_STATIC1,static,1342308352

[CLS:CInfoDlg]
Type=0
HeaderFile=InfoDlg.h
ImplementationFile=InfoDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CInfoDlg
VirtualFilter=dWC

[DLG:IDD_DIALOG3]
Type=1
Class=CSetDlg
ControlCount=14
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT1,edit,1350631554
Control3=IDC_SPIN1,msctls_updown32,1342177458
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT2,edit,1350631554
Control6=IDC_SPIN2,msctls_updown32,1342177458
Control7=IDC_STATIC,static,1342308352
Control8=IDC_RADIO1,button,1342308361
Control9=IDC_RADIO2,button,1342177289
Control10=IDC_RADIO3,button,1342177289
Control11=IDC_STATIC,static,1342308865
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_BUTTON1,button,1342242816

[CLS:CSetDlg]
Type=0
HeaderFile=SetDlg.h
ImplementationFile=SetDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT1
VirtualFilter=dWC

