
// Prova8379View.h: interface da classe CProva8379View
//

#pragma once


class CProva8379View : public CView
{
protected: // criar apenas com base na serialização
	CProva8379View() noexcept;
	DECLARE_DYNCREATE(CProva8379View)

// Atributos
public:
	CProva8379Doc* GetDocument() const;

// Operações
public:

// Substitui
public:
	virtual void OnDraw(CDC* pDC);  // substituído para desenhar esta visualização
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementação
public:
	virtual ~CProva8379View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Funções geradas de mapa de mensagens
protected:
	DECLARE_MESSAGE_MAP()
	COLORREF m_corpreenchimentosol;
	int raio_sol;
	int m_orbitaTerra;
	int m_orbitaLua;
	int raio_terra;
	COLORREF m_corpreenchimentoterra;
	int raio_lua;
	COLORREF m_corpreenchimentolua;
	int angulo;
	int verificar_orbita;
	CPoint sol;
	int pdesenho;
	UINT m_nTimer;
public:
	
	afx_msg void OnConfigurarOrbitas();
	afx_msg void OnIddRaio();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnConfiguracorsol();
	afx_msg void OnConfiguracorterra();
	afx_msg void OnConfiguracorlua();
	afx_msg void OnConfiguratimer();
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
//	afx_msg void OnMenuRButtonUp(UINT nPos, CMenu* pMenu);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // versão de depuração em Prova8379View.cpp
inline CProva8379Doc* CProva8379View::GetDocument() const
   { return reinterpret_cast<CProva8379Doc*>(m_pDocument); }
#endif

