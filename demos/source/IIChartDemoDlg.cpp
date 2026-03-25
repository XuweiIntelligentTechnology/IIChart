
// IIChartDemoDlg.cpp: 实现文件
//

#include "pch.h"
#include <vector>
#include <string>
#include "framework.h"
#include "IIChartDemo.h"
#include "IIChartDemoDlg.h"
#include "afxdialogex.h"

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CIIChartDemoDlg 对话框



CIIChartDemoDlg::CIIChartDemoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_IICHARTDEMO_DIALOG, pParent)
	, m_strMessage(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CIIChartDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_MESSAGE, m_strMessage);
	DDX_Control(pDX, IDC_EDIT_MESSAGE, m_editMessage);
	DDX_Control(pDX, IDC_COMBO_CASE, m_combCase);
	DDX_Control(pDX, IDC_LIST_FUNCTION, m_lstFunction);
}


void CIIChartDemoDlg::OutputError(const wchar_t* formatstring, ...)
{
	wchar_t* wzMsg = nullptr;
	int nLen = 1024 * 20;
	wzMsg = new wchar_t[nLen];
	ZeroMemory(wzMsg, nLen * sizeof(wchar_t));

	va_list args;
	va_start(args, formatstring);
	_vsnwprintf(wzMsg, nLen, formatstring, args);
	va_end(args);

	m_strMessage += L"Error > ";
	m_strMessage += wzMsg;
	m_strMessage += L"\r\n";

	delete[] wzMsg;

	UpdateData(FALSE);

	m_editMessage.LineScroll(m_editMessage.GetLineCount());
}

void CIIChartDemoDlg::OutputLine(const wchar_t* formatstring, ...)
{
	wchar_t* wzMsg = nullptr;
	int nLen = 1024 * 20;
	wzMsg = new wchar_t[nLen];
	ZeroMemory(wzMsg, nLen * sizeof(wchar_t));

	va_list args;
	va_start(args, formatstring);
	_vsnwprintf(wzMsg, nLen, formatstring, args);
	va_end(args);

	m_strMessage += L"> ";
	m_strMessage += wzMsg;
	m_strMessage += L"\r\n";

	delete[] wzMsg;

	UpdateData(FALSE);

	m_editMessage.LineScroll(m_editMessage.GetLineCount());
}

void CIIChartDemoDlg::InitUIControl()
{
	OutputLine(L"InitUIControl");

	vector<wstring> vctCase = m_pCaseService->GetCaseList();

	/* 初始化 Case ; */
	for (int nIndex = 0; nIndex < vctCase.size(); ++nIndex)
	{
		m_combCase.InsertString(nIndex, vctCase[nIndex].c_str());
	}
	m_combCase.SetCurSel(0);

	/* 取当前选择的 Case; */
	wchar_t wzCurCase[256] = { 0 };
	int nIndex = m_combCase.GetCurSel();
	m_combCase.GetLBText(nIndex, wzCurCase);
	m_wsCurrentCase = wzCurCase;

	/* 初始化 Function ; */
	UpdateListControl();

	RunCurrentFunction();
}

void CIIChartDemoDlg::UpdateListControl()
{
	/* 消除当前列表; */
	int nCount = m_lstFunction.GetCount();
	for (int nIndex = nCount; nIndex >= 0; nIndex--)
	{
		m_lstFunction.DeleteString(nIndex);
	}

	/* 取当前选择的 Case; */
	wchar_t wzCurCase[256] = { 0 };
	int nIndex = m_combCase.GetCurSel();
	m_combCase.GetLBText(nIndex, wzCurCase);

	/* 更新 Function 列表; */
	vector<wstring> vctCase = m_pCaseService->GetFunctionList(wzCurCase);
	for (int nIndex = 0; nIndex < vctCase.size(); ++nIndex)
	{
		m_lstFunction.AddString(vctCase[nIndex].c_str());
	}
	m_lstFunction.SetCurSel(0);
}

void CIIChartDemoDlg::RunCurrentFunction()
{
	/* 取当前选择的 Case; */
	wchar_t wzCurCase[256] = { 0 };
	int nIndex = m_combCase.GetCurSel();
	m_combCase.GetLBText(nIndex, wzCurCase);

	
	/* 取当前选择的 Function; */
	wchar_t wzCurFunction[256] = { 0 };
	int idx = m_lstFunction.GetCurSel();
	m_lstFunction.GetText(idx, wzCurFunction);

	m_pCaseService->RunFunction(wzCurCase, wzCurFunction);
}

BEGIN_MESSAGE_MAP(CIIChartDemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_LBN_DBLCLK(IDC_LIST_FUNCTION, &CIIChartDemoDlg::OnLbnDblclkListFunction)
	ON_CBN_SELCHANGE(IDC_COMBO_CASE, &CIIChartDemoDlg::OnCbnSelchangeComboCase)
END_MESSAGE_MAP()


// CIIChartDemoDlg 消息处理程序

BOOL CIIChartDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_pChartDelegate = new CChartEventDelegate(this);
	m_pChartManagerDelegate = new CChartManagerDelegateImp(this);
	m_pCaseService = new CCaseService(this, m_pChartDelegate, m_pChartManagerDelegate);

	HWND hWnd = nullptr;
	GetDlgItem(IDC_EDIT_IICHART, &hWnd);
	m_pCaseService->Init(hWnd);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CIIChartDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CIIChartDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CIIChartDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CIIChartDemoDlg::OnLbnDblclkListFunction()
{
	RunCurrentFunction();
}


void CIIChartDemoDlg::OnCbnSelchangeComboCase()
{
	m_pCaseService->ClearCaseChart(m_wsCurrentCase);

	/* 取当前选择的最新的 Case; */
	wchar_t wzCurCase[256] = { 0 };
	int nIndex = m_combCase.GetCurSel();
	m_combCase.GetLBText(nIndex, wzCurCase);
	m_wsCurrentCase = wzCurCase;

	UpdateListControl();
	RunCurrentFunction();
}
