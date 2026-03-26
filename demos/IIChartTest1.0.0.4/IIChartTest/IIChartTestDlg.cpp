
// IIChartTestDlg.cpp: 实现文件
//

#include "pch.h"
#include <vector>
#include <random>
#include <stdexcept>
#include "framework.h"
#include "IIChartTest.h"
#include "IIChartTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;
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


// CIIChartTestDlg 对话框



CIIChartTestDlg::CIIChartTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_IICHARTTEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CIIChartTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CIIChartTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_SHOW_CHART, &CIIChartTestDlg::OnBnClickedButtonShowChart)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE, &CIIChartTestDlg::OnBnClickedButtonUpdate)
END_MESSAGE_MAP()


int CIIChartTestDlg::InitChart()
{
	int nResult = 0;
	HWND hWnd = GetDlgItem(IDC_CHART)->GetSafeHwnd();

	try
	{
		// 创建对象;
		m_pChartManager = IIChart::CreateChartManager();
		m_pGlobalUtility = IIChart::CreateGlobalUtility();

		// 初始化
		nResult = m_pChartManager->Init(hWnd);
		if (0 != nResult)
		{
			return nResult;
		}
	}
	catch (...)
	{
		return 1;
	}

	return nResult;
}

int CIIChartTestDlg::ShowLineChart()
{
	int nResult = 0;
	CWnd* pWnd = GetDlgItem(IDC_CHART);

	CRect rect;
	pWnd->GetWindowRect(&rect); // 获取包含边框的矩形区域
	int width = rect.Width(); // 宽度
	int height = rect.Height() - 50; // 高度


	try
	{
		// 创建图表对象
		m_pChart = m_pChartManager->CreateChart(nResult);

		// 设置图表显示尺寸
		m_pChart->GetSetting()->SetHeight(height);
		m_pChart->GetSetting()->SetWidth(width);
		m_pChart->Init();

		// 创建并设置 X 轴;
		m_pXAxis = m_pChart->GetGeneralOptions()->GetXAxis();
		m_pXAxis->SetType(ERCTAxisType::E_Category);
		m_pXAxis->AddData(L"周一,周二,周三,周四,周五,周六,周日");

		// 创建并设置 Y 轴;
		m_pYAxis = m_pChart->GetGeneralOptions()->GetYAxis();
		m_pYAxis->SetType(ERCTAxisType::E_Value);

		// 添加坐标轴
		m_pChart->GetGeneralOptions()->Add(m_pXAxis);
		m_pChart->GetGeneralOptions()->Add(m_pYAxis);

		// 创建 折线;
		m_pLineType = m_pChart->GetGeneralOptions()->GetSeries()->CreateLineType();


		m_pLineType->SetData(L"1,21,25,65,85,14,23");

		// 系列;
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(m_pLineType);

		// 更新数据;
		
		m_pChart->SetOption();
	}
	catch (...)
	{

	}

	return 0;
}

int CIIChartTestDlg::UpdateChartData()
{
	return 0;
}

// CIIChartTestDlg 消息处理程序

BOOL CIIChartTestDlg::OnInitDialog()
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
	InitChart();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CIIChartTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CIIChartTestDlg::OnPaint()
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
HCURSOR CIIChartTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CIIChartTestDlg::OnBnClickedButtonShowChart()
{
	ShowLineChart();
}

/**
 * @brief 生成指定数量的随机整数，范围 [1, nMax]
 * @param nMax 最大值（包含）
 * @param N 需要生成的数字个数
 * @return std::vector<int> 包含 N 个随机数的向量
 * @note 如果 nMax <= 0 或 N <= 0，返回空向量
 */
void GenerateNumbers(int nMax, int N, std::vector<int>& vctResult)
{
	if (nMax <= 0 || N <= 0) 
	{
		return ;  // 返回空向量
	}

	// 随机设备，用于获取种子
	std::random_device rd;
	// 使用梅森旋转引擎，种子来自随机设备
	std::mt19937 gen(rd());
	// 均匀分布 [1, nMax]
	std::uniform_int_distribution<int> dist(1, nMax);

	std::vector<int> result;
	vctResult.reserve(N);  // 预分配空间，提高效率

	for (int i = 0; i < N; ++i) 
	{
		vctResult.push_back(dist(gen));
	}

	return ;
}

void CIIChartTestDlg::OnBnClickedButtonUpdate()
{
	vector<int> vctData;
	GenerateNumbers(100,7,vctData);
	m_pLineType->SetData(vctData);

	// 系列;
	m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(m_pLineType);

	// 更新数据;
	m_pChart->SetOption();
}
