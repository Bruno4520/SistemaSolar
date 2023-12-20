
// ChildFrm.cpp : implementação da classe CChildFrame
//

#include "pch.h"
#include "framework.h"
#include "Prova8379.h"

#include "ChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWnd)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWnd)
END_MESSAGE_MAP()

// Construção/destruição de CChildFrame

CChildFrame::CChildFrame() noexcept
{
	// TODO: adicione o código de inicialização de membro aqui
}

CChildFrame::~CChildFrame()
{
}


BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: modifique a classe ou os estilos da Janela modificando os cs CREATESTRUCT
	if( !CMDIChildWnd::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}

// Diagnóstico de CChildFrame

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWnd::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWnd::Dump(dc);
}
#endif //_DEBUG

// Manipuladores de mensagens de CChildFrame
