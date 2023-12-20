
// Prova8379.h: arquivo de cabeçalho principal para o aplicativo Prova8379
//
#pragma once

#ifndef __AFXWIN_H__
	#error "inclua 'pch.h' antes de incluir este arquivo para PCH"
#endif

#include "resource.h"       // símbolos principais


// CProva8379App:
// Consulte Prova8379.cpp para a implementação desta classe
//

class CProva8379App : public CWinApp
{
public:
	CProva8379App() noexcept;


// Substitui
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementação
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CProva8379App theApp;
