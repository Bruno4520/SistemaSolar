#pragma once
#include "afxdialogex.h"


// caixa de diálogo de MudarRaioDlg

class MudarRaioDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MudarRaioDlg)

public:
	MudarRaioDlg(CWnd* pParent = nullptr);   // construtor padrão
	virtual ~MudarRaioDlg();

// Janela de Dados
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Raio };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Suporte DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	int raio_lua;
	int Orbita_Lua;
	int orbita_terra;
	int raio_sol;
	int raio_terra;
};
