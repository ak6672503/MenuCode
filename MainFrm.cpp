
// MainFrm.cpp: CMainFrame 类的实现
//

#include "pch.h"
#include "framework.h"
#include "Menu.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(IDM_Test, &CMainFrame::OnTest)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CUT, &CMainFrame::OnUpdateEditCut)
	ON_COMMAND(IDM_SHOW, &CMainFrame::OnShow)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame() noexcept
{
	//m_bAutoMenuEnable = FALSE; mfc自带的管理菜单

}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: 如果不需要可停靠工具栏，则删除这三行
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	//GetMenu()->GetSubMenu(0)->CheckMenuItem(0, MF_BYPOSITION | MF_CHECKED); //利用序号来改变菜单子项的复选状态
	////GetMenu()->GetSubMenu(0)->CheckMenuItem(ID_FILE_NEW, MF_BYPOSITION | MF_UNCHECKED);//利用ID号来改变菜单子项的复选状态
	//GetMenu()->GetSubMenu(0)->SetDefaultItem(1, TRUE); //设置某子项目变成黑色粗体

	//m_bitmap.LoadBitmap(IDB_BITMAP1); //加载位图资源
	//GetMenu()->GetSubMenu(0)->SetMenuItemBitmaps(0, MF_BYPOSITION, &m_bitmap, &m_bitmap); //让位图资源变成菜单小图标



	//GetMenu()->GetSubMenu(0)->EnableMenuItem(1, MF_BYPOSITION | MF_DISABLED);//设置菜单中的某一子项不给使用

	SetMenu(NULL);//禁用整个菜单

	CMenu menu;  //创建菜单对象
	menu.LoadMenuW(IDR_MAINFRAME);//加载菜单资源
	SetMenu(&menu);   //设置菜单
	menu.Detach(); //因为设置的菜单对象是局部的 创建完之后会被销毁，这个函数把菜单句柄与菜单对象分离

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return TRUE;
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


void CMainFrame::OnTest()
{
	MessageBox(L"asdasdasd");

}


void CMainFrame::OnUpdateEditCut(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	if (2 == pCmdUI->m_nIndex) {
	
		pCmdUI->SetCheck();
	}
	pCmdUI->Enable();

}


void CMainFrame::OnShow()
{
	// TODO: 在此添加命令处理程序代码


	MessageBox(L"main show");

}
