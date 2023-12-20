
// Prova8379View.cpp: implementação da classe CProva8379View
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS pode ser definido em um projeto ATL implementando a visualização, a miniatura
// e manipuladores de filtro de pesquisa e permite o compartilhamento de código do documento com esse projeto.
#ifndef SHARED_HANDLERS
#include "Prova8379.h"
#endif

#include "Prova8379Doc.h"
#include "Prova8379View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "MudarRaioDlg.h"


// CProva8379View

IMPLEMENT_DYNCREATE(CProva8379View, CView)

BEGIN_MESSAGE_MAP(CProva8379View, CView)
	// Comandos de impressão padrão
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_CONFIGURAR_ORBITAS, &CProva8379View::OnConfigurarOrbitas)
	ON_COMMAND(IDD_Raio, &CProva8379View::OnIddRaio)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_CONFIGURACORSOL, &CProva8379View::OnConfiguracorsol)
	ON_COMMAND(ID_CONFIGURACORTERRA, &CProva8379View::OnConfiguracorterra)
	ON_COMMAND(ID_CONFIGURACORLUA, &CProva8379View::OnConfiguracorlua)
	ON_COMMAND(ID_CONFIGURATIMER, &CProva8379View::OnConfiguratimer)
	ON_WM_DESTROY()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// Construção/destruição de CProva8379View

CProva8379View::CProva8379View() noexcept
{
	m_corpreenchimentosol = RGB(255, 255, 0);
	m_corpreenchimentoterra = RGB(0, 0, 255);
	m_corpreenchimentolua = RGB(0, 255, 255);
	raio_sol = 100;
	raio_terra = 50;
	raio_lua = 10;
	m_orbitaTerra = 300;
	m_orbitaLua = 100;
	angulo = 0;
	verificar_orbita = 0;
	pdesenho = 0;
	m_nTimer = 0;
	// TODO: adicione o código de construção aqui
}

CProva8379View::~CProva8379View()
{
}

BOOL CProva8379View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: modifique a classe ou os estilos de Janela aqui modificando
	//  os cs CREATESTRUCT

	return CView::PreCreateWindow(cs);
}

// desenho de CProva8379View

void CProva8379View::OnDraw(CDC* pDC)
{
	CProva8379Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CBrush* oldBrush, cor_sol(m_corpreenchimentosol), cor_terra(m_corpreenchimentoterra), cor_lua(m_corpreenchimentolua);
	CRect tela;
	GetClientRect(&tela);
	if (pdesenho == 0) {
		sol.x = tela.Width() / 2;
		sol.y = tela.Height() / 2;
	}
	CPoint terra, lua;
	terra.x = (sol.x + m_orbitaTerra * cos(angulo * 3.14 / 180));
	terra.y = (sol.y - m_orbitaTerra * sin(angulo * 3.14 / 180));
	lua.x = (terra.x + m_orbitaLua * cos(angulo * 3.14 / 180));
	lua.y = (terra.y + m_orbitaLua * sin(angulo * 3.14 / 180));
	if (verificar_orbita == 0) {
		pDC->Ellipse(sol.x + m_orbitaTerra, sol.y + m_orbitaTerra, sol.x - m_orbitaTerra, sol.y - m_orbitaTerra);
		pDC->Ellipse(terra.x + m_orbitaLua, terra.y + m_orbitaLua, terra.x - m_orbitaLua, terra.y - m_orbitaLua);
	}
	oldBrush = pDC->SelectObject(&cor_sol);
	pDC->Ellipse(sol.x + raio_sol, sol.y + raio_sol, sol.x - raio_sol, sol.y - raio_sol);
	pDC->SelectObject(&cor_terra);
	pDC->Ellipse(terra.x + raio_terra, terra.y + raio_terra, terra.x - raio_terra, terra.y - raio_terra);
	pDC->SelectObject(&cor_lua);
	pDC->Ellipse(lua.x + raio_lua, lua.y + raio_lua, lua.x - raio_lua, lua.y - raio_lua);
	pDC->SelectObject(oldBrush);
	pdesenho++;
	// TODO: adicione o código de desenho para dados nativos aqui
}


// impressão de CProva8379View

BOOL CProva8379View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// preparação padrão
	return DoPreparePrinting(pInfo);
}

void CProva8379View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: adicione inicialização extra antes de imprimir
}

void CProva8379View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: adicione a limpeza após a impressão
}


// Diagnóstico de CProva8379View

#ifdef _DEBUG
void CProva8379View::AssertValid() const
{
	CView::AssertValid();
}

void CProva8379View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CProva8379Doc* CProva8379View::GetDocument() const // a versão sem depuração está embutida
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CProva8379Doc)));
	return (CProva8379Doc*)m_pDocument;
}
#endif //_DEBUG

// Manipuladores de mensagens de CProva8379View


void CProva8379View::OnConfigurarOrbitas()
{
	verificar_orbita++;
	verificar_orbita %= 2;
	Invalidate();
	// TODO: Adicione seu código de manipulador de comandos aqui
}


void CProva8379View::OnIddRaio()
{
	MudarRaioDlg dlg;
	dlg.raio_sol = raio_sol;
	dlg.raio_terra = raio_terra;
	dlg.raio_lua = raio_lua;
	dlg.orbita_terra = m_orbitaTerra;
	dlg.Orbita_Lua = m_orbitaLua;
	if (dlg.DoModal() == IDOK) {
		raio_sol = dlg.raio_sol;
		raio_terra = dlg.raio_terra;
		raio_lua = dlg.raio_lua;
		m_orbitaTerra = dlg.orbita_terra;
		m_orbitaLua = dlg.Orbita_Lua;
		Invalidate();
	}
	// TODO: Adicione seu código de manipulador de comandos aqui
}

void CProva8379View::OnConfiguracorsol()
{
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK) {
		m_corpreenchimentosol = dlg.GetColor();
		Invalidate();
	}
	// TODO: Adicione seu código de manipulador de comandos aqui
}


void CProva8379View::OnConfiguracorterra()
{
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK) {
		m_corpreenchimentoterra = dlg.GetColor();
		Invalidate();
	}
	// TODO: Adicione seu código de manipulador de comandos aqui
}

void CProva8379View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Adicione seu código de manipulador de mensagens e/ou chame o padrão
	sol = point;
	Invalidate();
	CView::OnRButtonDown(nFlags, point);
}

void CProva8379View::OnConfiguracorlua()
{
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK) {
		m_corpreenchimentolua = dlg.GetColor();
		Invalidate();
	}
	// TODO: Adicione seu código de manipulador de comandos aqui
}


void CProva8379View::OnConfiguratimer()
{
	if (m_nTimer) {
		KillTimer(m_nTimer);
		m_nTimer = 0;
	}
	else {
		m_nTimer = SetTimer(1, 150, NULL);
	}
	// TODO: Adicione seu código de manipulador de comandos aqui
}


void CProva8379View::OnDestroy()
{
	CView::OnDestroy();
	CView::OnDestroy();
	if (m_nTimer) {
		KillTimer(m_nTimer);
		m_nTimer = 0;
	}
	// TODO: Adicione seu código de manipulador de mensagens aqui
}


void CProva8379View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Adicione seu código de manipulador de mensagens e/ou chame o padrão
	if (nIDEvent == m_nTimer) {
		angulo += 1;
		angulo %= 360;
		Invalidate();
	}
	CView::OnTimer(nIDEvent);
}
