
// MainFrm.h: interface da classe CMainFrame
//

#pragma once

class CMainFrame : public CMDIFrameWnd
{
	DECLARE_DYNAMIC(CMainFrame)
public:
	CMainFrame() noexcept;

// Atributos
public:

// Operações
public:

// Substitui
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementação
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // membros incorporados da barra de controle
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;

// Funções geradas de mapa de mensagens
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

};


