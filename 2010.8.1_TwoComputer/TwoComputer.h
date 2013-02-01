// TwoComputer.h : main header file for the TWOCOMPUTER application
//

#if !defined(AFX_TWOCOMPUTER_H__33B70570_70AB_4655_B50A_BFAEF3423CC1__INCLUDED_)
#define AFX_TWOCOMPUTER_H__33B70570_70AB_4655_B50A_BFAEF3423CC1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTwoComputerApp:
// See TwoComputer.cpp for the implementation of this class
//

class CTwoComputerApp : public CWinApp
{
public:
	CTwoComputerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTwoComputerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTwoComputerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TWOCOMPUTER_H__33B70570_70AB_4655_B50A_BFAEF3423CC1__INCLUDED_)
