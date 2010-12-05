
// Dogfight2D.MFC.h : main header file for the Dogfight2D.MFC application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CDogfight2DMFCApp:
// See Dogfight2D.MFC.cpp for the implementation of this class
//

class CDogfight2DMFCApp : public CWinAppEx
{
public:
	CDogfight2DMFCApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDogfight2DMFCApp theApp;
