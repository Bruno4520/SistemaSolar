// CRaioDlg.cpp : arquivo de implementação
//

#include "pch.h"
#include "Prova8379.h"
#include "afxdialogex.h"
#include "CRaioDlg.h"


// caixa de diálogo de CRaioDlg

IMPLEMENT_DYNAMIC(CRaioDlg, CDialogEx)

CRaioDlg::CRaioDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Raio, pParent)
	, raio_terra(50)
	, raio_sol(100)
	, raio_lua(10)
	, orbita_lua(100)
	, orbita_terra(300)
{

}

CRaioDlg::~CRaioDlg()
{
}

void CRaioDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRaioDlg, CDialogEx)
END_MESSAGE_MAP()


// manipuladores de mensagens de CRaioDlg
