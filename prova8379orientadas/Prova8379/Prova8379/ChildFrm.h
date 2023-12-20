
// ChildFrm.h : interface da classe CChildFrame
//

#pragma once

class CChildFrame : public CMDIChildWnd
{
	DECLARE_DYNCREATE(CChildFrame)
public:
	CChildFrame() noexcept;

// Atributos
protected:
	CSplitterWnd m_wndSplitter;
public:

// Operações
public:

// Substitui
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementação
public:
	virtual ~CChildFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// Funções geradas de mapa de mensagens
protected:
	DECLARE_MESSAGE_MAP()
};
