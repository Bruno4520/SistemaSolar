// MudarRaioDlg.cpp : arquivo de implementação
//

#include "pch.h"
#include "Prova8379.h"
#include "afxdialogex.h"
#include "MudarRaioDlg.h"


// caixa de diálogo de MudarRaioDlg

IMPLEMENT_DYNAMIC(MudarRaioDlg, CDialogEx)

MudarRaioDlg::MudarRaioDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Raio, pParent)
	, raio_lua(0)
	, Orbita_Lua(0)
	, orbita_terra(0)
	, raio_sol(0)
	, raio_terra(0)
{

}

MudarRaioDlg::~MudarRaioDlg()
{
}

void MudarRaioDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_lua, raio_lua);
	DDX_Text(pDX, IDC_OrbitaLua, Orbita_Lua);
	DDX_Text(pDX, IDC_OrbitaTerra, orbita_terra);
	DDX_Text(pDX, IDC_sol, raio_sol);
	DDX_Text(pDX, IDC_terra, raio_terra);
}


BEGIN_MESSAGE_MAP(MudarRaioDlg, CDialogEx)
END_MESSAGE_MAP()


// manipuladores de mensagens de MudarRaioDlg
