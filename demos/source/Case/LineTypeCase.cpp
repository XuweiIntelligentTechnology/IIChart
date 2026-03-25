#include "pch.h"
#include "IIChartDemoDlg.h"
#include "LineTypeCase.h"

CLineTypeCase::CLineTypeCase(IIChart::IChartManager* pManager, CIIChartDemoDlg* pDlg, IChartEventDelegate* pDelegate)
     : m_pManager(pManager)
	 , m_pDlg(pDlg)
	 , m_pDelegate(pDelegate)
{
	m_vctFunction.push_back(L"<1>简单折线图");
	m_vctFunction.push_back(L"<2>简单曲线图");
	m_vctFunction.push_back(L"<3>虚线曲线图");
	m_vctFunction.push_back(L"<4>简单面积图");
	m_vctFunction.push_back(L"<5>简单平滑面积图");
	m_vctFunction.push_back(L"<6>阶梯图");
	m_vctFunction.push_back(L"<7>基础面积图");

	m_vctFunction.push_back(L"<8>带网络与图例的折线图");
	m_vctFunction.push_back(L"<9>显示X轴刻度线的折线图");
	m_vctFunction.push_back(L"<10>X轴与Y轴互换的折线图");
	
	m_vctFunction.push_back(L"<11>多维折线图");
	m_vctFunction.push_back(L"<12>多维面积图");
	m_vctFunction.push_back(L"<13>坡度多维面积图");

	m_vctFunction.push_back(L"<14>模拟更新数据");
}

CLineTypeCase::~CLineTypeCase()
{
}

vector<wstring> CLineTypeCase::GetFunctionList()
{
	return m_vctFunction;
}

int CLineTypeCase::RunFunction(const wstring& wsItemName)
{
	int nResult = 1;

	do
	{
		m_pDlg->OutputLine(L"RunFunction:[%s]", wsItemName.c_str());
		if (0 == wsItemName.compare(L"<1>简单折线图"))
		{
			if (FALSE == CreateBasicLineChart()) break;
		}else if (0 == wsItemName.compare(L"<2>简单曲线图"))
		{
			if (FALSE == CreateBasicSmoothLineChart()) break;
		}
		else if (0 == wsItemName.compare(L"<3>虚线曲线图"))
		{
			if (FALSE == CreateSmoothBasicLineChart()) break;
		}
		else if (0 == wsItemName.compare(L"<4>简单面积图"))
		{
			if (FALSE == CreateBasicAreaChart()) break;
		}
		else if (0 == wsItemName.compare(L"<5>简单平滑面积图"))
		{
			if (FALSE == CreateBasicSmoothAreaChart()) break;
		}
		else if (0 == wsItemName.compare(L"<6>阶梯图"))
		{
			if (FALSE == CreateLadderBasicLineChart()) break;
		}
		else if (0 == wsItemName.compare(L"<7>基础面积图"))
		{
			if (FALSE == CreateBasicAreaChart()) break;
		}
		else if (0 == wsItemName.compare(L"<8>带网络与图例的折线图"))
		{
			if (FALSE == CreateGrideLegendBasicLineChart()) break;
		}
		else if (0 == wsItemName.compare(L"<9>显示X轴刻度线的折线图"))
		{
			if (FALSE == CreateShowXAxisBasicLineChart()) break;
		}
		else if (0 == wsItemName.compare(L"<10>X轴与Y轴互换的折线图"))
		{
			if (FALSE == CreateX2YBasicLineChart()) break;
		}
		else if (0 == wsItemName.compare(L"<11>多维折线图"))
		{
			if (FALSE == CreateStackedLineChart()) break;
		}
		else if (0 == wsItemName.compare(L"<12>多维面积图"))
		{
			if (FALSE == CreateStackedAreaChart()) break;
		}
		else if (0 == wsItemName.compare(L"<13>坡度多维面积图"))
		{
			if (FALSE == CreateGradientStackedAreaChart()) break;
		}
		else if (0 == wsItemName.compare(L"<14>模拟更新数据"))
		{
			if (FALSE == UpdateData()) break;
		}

		nResult = 0;
	} while (0);
	

	// 没有对应的项目;
	return nResult;
}

void CLineTypeCase::ClearChart()
{
	if (nullptr != m_pChart)
	{
		m_pChart->Release();
		m_pChart = nullptr;
	}
}

void CLineTypeCase::Release()
{
	delete this;
}

BOOL CLineTypeCase::UpdateData()
{
	if (nullptr == m_pChart)
	{
		m_pDlg->OutputError(L"未创建 Chart");
		return FALSE;
	}

	/* 1. 取新的数据; */
	vector<int> vctData ;
	G_GetRandomData(vctData, 7, 300, 18300);

	/* 2. 通过 ID 获取指定的系列并设置最新的数据;  */
	Line::ILineType* pLineType = m_pChart->GetGeneralOptions()->GetSeries()->CreateLineType(); // 显示为Line;
	pLineType->SetId(L"LINE-001");
	pLineType->SetData(vctData); // 设置系列数据（当前只有一个维度的数据）;

	/* 3. 增加此系列; */
	m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pLineType);

	/* 4. 更新和配置生效【可同步也可异步】; */
	m_pChart->SetOptionAsync();

	return TRUE;
}

BOOL CLineTypeCase::CreateBasicLineChart()
{
	int nError = 0;
	BOOL bResult = FALSE;
	
	do
	{
		/* 为了方便查看 Chart 的整个编辑过程，此处把之前的实例删除掉; */
		if (nullptr != m_pChart)
		{
			m_pChart->Release();
			m_pChart = nullptr;
		}

		/* 创建 Chart 实例(1.必须) */		
		m_pChart = m_pManager->CreateChart(nError);
		if (0 != nError)
		{
			m_pDlg->OutputError(L"创建 Chart 失败", nError);
			break;
		}
		m_pChart->Init();
		m_pChart->SetEventDelegate(m_pDelegate); // 设置接收响应事件的代理;
		m_pChart->On(Evt_click, L"series");      // 注册一个点击事件;

		/* 创建 Chart 实例(1.必须) */
		if (nullptr == m_pChart)
		{
			m_pChart = m_pManager->CreateChart(nError);
			if (0 != nError)
			{
				m_pDlg->OutputError(L"创建 Chart 失败", nError);
				break;
			}

			m_pChart->Init();
			m_pChart->SetEventDelegate(m_pDelegate); // [可选项]设置接收响应事件的代理;
			m_pChart->On(Evt_click, L"series");      // [可选项]注册一个点击事件;
		}

		/* 配置图表; */
		m_pChart->GetGeneralOptions()->GetTitle()->SetText(L"基础折线图"); // [可选项]设置标题
		m_pChart->GetGeneralOptions()->GetXAxis()->SetType(ERCTAxisType::E_Category); // 设置平面坐标轴：X 为类目(2. 必须)
		m_pChart->GetGeneralOptions()->GetXAxis()->SetData(L"星期一,星期二,星期三,星期四,星期五,星期六,星期七"); // 设置平面坐标轴：X 为类目(2. 必须)
		m_pChart->GetGeneralOptions()->GetYAxis()->SetType(ERCTAxisType::E_Value); // 设置平面坐标轴：Y 为 值(2. 必须);

		vector<int> vctData = { 150, 230, 224, 218, 135, 147, 260 };

		/* 设置显示的系列  */
		Line::ILineType* pLineType = m_pChart->GetGeneralOptions()->GetSeries()->CreateLineType(); // 显示为Line;
		pLineType->SetId(L"LINE-001");
		pLineType->SetData(vctData); // 设置系列数据（当前只有一个维度的数据）;

		/* 增加创建的 LineType; (4. 必须) */
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pLineType);

		/* 使配置生效; (5. 必须)*/
		m_pChart->SetOption();

		bResult = TRUE;
	} while (0);


	return bResult;
}

BOOL CLineTypeCase::CreateBasicSmoothLineChart()
{
	int nError = 0;
	BOOL bResult = FALSE;

	do
	{
		/* 为了方便查看 Chart 的整个编辑过程，此处把之前的实例删除掉; */
		if (nullptr != m_pChart)
		{
			m_pChart->Release();
			m_pChart = nullptr;
		}

		/* 创建 Chart 实例(1.必须) */
		m_pChart = m_pManager->CreateChart(nError);
		if (0 != nError)
		{
			m_pDlg->OutputError(L"创建 Chart 失败", nError);
			break;
		}
		m_pChart->Init();
		m_pChart->SetEventDelegate(m_pDelegate); // 设置接收响应事件的代理;
		m_pChart->On(Evt_click, L"series");      // 注册一个点击事件;

		/* 创建 Chart 实例(1.必须) */
		if (nullptr == m_pChart)
		{
			m_pChart = m_pManager->CreateChart(nError);
			if (0 != nError)
			{
				m_pDlg->OutputError(L"创建 Chart 失败", nError);
				break;
			}

			m_pChart->Init();
			m_pChart->SetEventDelegate(m_pDelegate); // [可选项]设置接收响应事件的代理;
			m_pChart->On(Evt_click, L"series");      // [可选项]注册一个点击事件;
		}

		/* 配置图表; */
		m_pChart->GetGeneralOptions()->GetTitle()->SetText(L"基础折线图"); // [可选项]设置标题
		m_pChart->GetGeneralOptions()->GetXAxis()->SetType(ERCTAxisType::E_Category); // 设置平面坐标轴：X 为类目(2. 必须)
		m_pChart->GetGeneralOptions()->GetXAxis()->SetData(L"星期一,星期二,星期三,星期四,星期五,星期六,星期七"); // 设置平面坐标轴：X 为类目(2. 必须)
		m_pChart->GetGeneralOptions()->GetYAxis()->SetType(ERCTAxisType::E_Value); // 设置平面坐标轴：Y 为 值(2. 必须);

		vector<int> vctData = { 150, 230, 224, 218, 135, 147, 260 };

		/* 设置显示的系列  */
		Line::ILineType* pLineType = m_pChart->GetGeneralOptions()->GetSeries()->CreateLineType(); // 显示为Line;
		pLineType->SetId(L"LINE-001");
		pLineType->SetSmooth(true);
		pLineType->SetData(vctData); // 设置系列数据（当前只有一个维度的数据）;

		/* 增加创建的 LineType; (4. 必须) */
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pLineType);

		/* 使配置生效; (5. 必须)*/
		m_pChart->SetOption();

		bResult = TRUE;
	} while (0);


	return bResult;
}

BOOL CLineTypeCase::CreateBasicAreaChart()
{
	int nError = 0;
	BOOL bResult = FALSE;

	do
	{
		/* 为了方便查看 Chart 的整个编辑过程，此处把之前的实例删除掉; */
		if (nullptr != m_pChart)
		{
			m_pChart->Release();
			m_pChart = nullptr;
		}

		/* 创建 Chart 实例(1.必须) */
		m_pChart = m_pManager->CreateChart(nError);
		if (0 != nError)
		{
			m_pDlg->OutputError(L"创建 Chart 失败", nError);
			break;
		}
		m_pChart->Init();
		m_pChart->SetEventDelegate(m_pDelegate); // 设置接收响应事件的代理;
		m_pChart->On(Evt_click, L"series");      // 注册一个点击事件;

		/* 创建 Chart 实例(1.必须) */
		if (nullptr == m_pChart)
		{
			m_pChart = m_pManager->CreateChart(nError);
			if (0 != nError)
			{
				m_pDlg->OutputError(L"创建 Chart 失败", nError);
				break;
			}

			m_pChart->Init();
			m_pChart->SetEventDelegate(m_pDelegate); // [可选项]设置接收响应事件的代理;
			m_pChart->On(Evt_click, L"series");      // [可选项]注册一个点击事件;
		}

		/* 配置图表; */
		m_pChart->GetGeneralOptions()->GetTitle()->SetText(L"基础折线图"); // [可选项]设置标题
		m_pChart->GetGeneralOptions()->GetXAxis()->SetType(ERCTAxisType::E_Category); // 设置平面坐标轴：X 为类目(2. 必须)
		m_pChart->GetGeneralOptions()->GetXAxis()->SetBoundaryGap(false); // [可选项];
		m_pChart->GetGeneralOptions()->GetXAxis()->SetData(L"星期一,星期二,星期三,星期四,星期五,星期六,星期七"); // 设置平面坐标轴：X 为类目(2. 必须)
		m_pChart->GetGeneralOptions()->GetYAxis()->SetType(ERCTAxisType::E_Value); // 设置平面坐标轴：Y 为 值(2. 必须);

		vector<int> vctData = { 150, 230, 224, 218, 135, 147, 260 };

		/* 设置显示的系列  */
		Line::ILineType* pLineType = m_pChart->GetGeneralOptions()->GetSeries()->CreateLineType(); // 显示为Line;
		pLineType->SetId(L"LINE-001");
		pLineType->GetAreaStyle();
		pLineType->SetData(vctData); // 设置系列数据（当前只有一个维度的数据）;

		/* 增加创建的 LineType; (4. 必须) */
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pLineType);

		/* 使配置生效; (5. 必须)*/
		m_pChart->SetOption();

		bResult = TRUE;
	} while (0);


	return bResult;
}

BOOL CLineTypeCase::CreateBasicSmoothAreaChart()
{
	int nError = 0;
	BOOL bResult = FALSE;

	do
	{
		/* 为了方便查看 Chart 的整个编辑过程，此处把之前的实例删除掉; */
		if (nullptr != m_pChart)
		{
			m_pChart->Release();
			m_pChart = nullptr;
		}

		/* 创建 Chart 实例(必须) */
		m_pChart = m_pManager->CreateChart(nError);
		if (0 != nError)
		{
			m_pDlg->OutputError(L"创建 Chart 失败", nError);
			break;
		}
		m_pChart->Init();
		m_pChart->SetEventDelegate(m_pDelegate); // 设置接收响应事件的代理;
		m_pChart->On(Evt_click, L"series");      // 注册一个点击事件;

		/* 创建 Chart 实例(必须) */
		if (nullptr == m_pChart)
		{
			m_pChart = m_pManager->CreateChart(nError);
			if (0 != nError)
			{
				m_pDlg->OutputError(L"创建 Chart 失败", nError);
				break;
			}

			m_pChart->Init();
			m_pChart->SetEventDelegate(m_pDelegate); // [可选项]设置接收响应事件的代理;
			m_pChart->On(Evt_click, L"series");      // [可选项]注册一个点击事件;
		}

		/* 配置图表; */
		m_pChart->GetGeneralOptions()->GetTitle()->SetText(L"基础折线图"); // [可选项]设置标题
		m_pChart->GetGeneralOptions()->GetXAxis()->SetType(ERCTAxisType::E_Category); // 设置平面坐标轴：X 为类目(2. 必须)
		m_pChart->GetGeneralOptions()->GetXAxis()->SetData(L"星期一,星期二,星期三,星期四,星期五,星期六,星期七"); // 设置平面坐标轴：X 为类目(2. 必须)
		m_pChart->GetGeneralOptions()->GetYAxis()->SetType(ERCTAxisType::E_Value); // 设置平面坐标轴：Y 为 值(2. 必须);

		

		/* 设置显示的系列  */
		vector<int> vctData = { 150, 230, 224, 218, 135, 147, 260 };
		Line::ILineType* pLineType = m_pChart->GetGeneralOptions()->GetSeries()->CreateLineType(); // 显示为Line;
		pLineType->SetId(L"LINE-001");
		pLineType->SetSmooth(true);
		pLineType->GetAreaStyle();
		pLineType->SetData(vctData); // 设置系列数据（当前只有一个维度的数据）;

		/* 增加创建的 LineType; (必须) */
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pLineType);

		/* 使配置生效; (必须)*/
		m_pChart->SetOption();

		bResult = TRUE;
	} while (0);


	return bResult;
}


BOOL CLineTypeCase::CreateX2YBasicLineChart()
{
	int nError = 0;
	BOOL bResult = FALSE;
	
	do
	{
		/* 为了方便查看 Chart 的整个编辑过程，此处把之前的实例删除掉; */
		if (nullptr != m_pChart)
		{
			m_pChart->Release();
			m_pChart = nullptr;
		}

		/* 创建 Chart 实例(1.必须) */
		m_pChart = m_pManager->CreateChart(nError);
		if (0 != nError)
		{
			m_pDlg->OutputError(L"创建 Chart 失败", nError);
			break;
		}
		m_pChart->Init();
		m_pChart->SetEventDelegate(m_pDelegate); // 设置接收响应事件的代理;
		m_pChart->On(Evt_click, L"series");      // 注册一个点击事件;


		/* 配置图表; */
		m_pChart->GetGeneralOptions()->GetTitle()->SetText(L"X轴与Y轴互换的折线图"); // 设置标题
		m_pChart->GetGeneralOptions()->GetYAxis()->SetType(ERCTAxisType::E_Category);     // 设置平面坐标轴：Y 为类目(2. 必须)
		m_pChart->GetGeneralOptions()->GetYAxis()->SetData(L"星期一,星期二,星期三,星期四,星期五,星期六,星期七");  // 设置平面坐标轴：Y 为类目(2. 必须)
		m_pChart->GetGeneralOptions()->GetXAxis()->SetType(ERCTAxisType::E_Value);        // 设置平面坐标轴：X 为 值(2. 必须);

		/* 设置显示的系列  */
		Line::ILineType* pLineType = m_pChart->GetGeneralOptions()->GetSeries()->CreateLineType(); // 显示为Line;
		pLineType->SetId(L"LINE-001");

		vector<int> vctData = { 150, 230, 224, 218, 135, 147, 260 };
		pLineType->SetData(vctData);  // 设置系列数据（当前只有一个维度的数据）;


		/* 增加创建的 LineType; (4. 必须) */
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pLineType);


		/* 使配置生效; (5. 必须)*/
		m_pChart->SetOption();

		bResult = TRUE;
	} while (0);


	return bResult;
}


BOOL CLineTypeCase::CreateGrideLegendBasicLineChart()
{
	int nError = 0;
	BOOL bResult = FALSE;
	
	do
	{
		/* 为了方便查看 Chart 的整个编辑过程，此处把之前的实例删除掉; */
		if (nullptr != m_pChart)
		{
			m_pChart->Release();
			m_pChart = nullptr;
		}

		/* 创建 Chart 实例(1.必须) */
		m_pChart = m_pManager->CreateChart(nError);
		if (0 != nError)
		{
			m_pDlg->OutputError(L"创建 Chart 失败", nError);
			break;
		}
		m_pChart->Init();
		m_pChart->SetEventDelegate(m_pDelegate); // 设置接收响应事件的代理;
		m_pChart->On(Evt_click, L"series");      // 注册一个点击事件;


		/* 配置图表; */
		m_pChart->GetGeneralOptions()->GetTitle()->SetText(L"带网络与图例的折线图"); // 设置标题
		m_pChart->GetGeneralOptions()->GetTooltip(); // 显示默认Tooltip
		m_pChart->GetGeneralOptions()->GetLegend();  // 显示默认图例
		m_pChart->GetGeneralOptions()->GetGrid();    // 显示默认Gride
		m_pChart->GetGeneralOptions()->GetGrid()->SetLeft(7, true);
		m_pChart->GetGeneralOptions()->GetGrid()->SetTop(7, true);

		// 设置平面坐标轴：X 为类目(2. 必须)
		m_pChart->GetGeneralOptions()->GetXAxis()->SetType(ERCTAxisType::E_Category);
		m_pChart->GetGeneralOptions()->GetXAxis()->SetData(L"星期一,星期二,星期三,星期四,星期五,星期六,星期七");
		m_pChart->GetGeneralOptions()->GetXAxis()->SetBoundaryGap(false); // 首尾不留空，即数据从 0 刻度开始,
		m_pChart->GetGeneralOptions()->GetXAxis()->GetSplitLine(); // 显示 x 轴分隔线;

		// 设置平面坐标轴：Y 为 值(2. 必须);
		m_pChart->GetGeneralOptions()->GetYAxis()->SetType(ERCTAxisType::E_Value);
		m_pChart->GetGeneralOptions()->GetYAxis()->SetBoundaryGap(true);

		vector<int> vctData = { 150, 230, 224, 218, 135, 147, 260 };

		/* 设置显示的系列  */
		Line::ILineType* pLineType = m_pChart->GetGeneralOptions()->GetSeries()->CreateLineType(); // 显示为Line;
		pLineType->SetId(L"LINE-001");
		pLineType->GetLineStyle()->SetType(ELineStyle::ELS_Dotted);
		pLineType->SetData(vctData); // 设置系列数据（当前只有一个维度的数据）;

		/* 增加创建的 LineType; (4. 必须) */
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pLineType);

		/* 使配置生效; (5. 必须)*/
		m_pChart->SetOption();

		bResult = TRUE;
	} while (0);


	return bResult;
}


BOOL CLineTypeCase::CreateShowXAxisBasicLineChart()
{
	int nError = 0;
	BOOL bResult = FALSE;
	
	do
	{
		/* 为了方便查看 Chart 的整个编辑过程，此处把之前的实例删除掉; */
		if (nullptr != m_pChart)
		{
			m_pChart->Release();
			m_pChart = nullptr;
		}

		/* 创建 Chart 实例(1.必须) */
		m_pChart = m_pManager->CreateChart(nError);
		if (0 != nError)
		{
			m_pDlg->OutputError(L"创建 Chart 失败", nError);
			break;
		}
		m_pChart->Init();
		m_pChart->SetEventDelegate(m_pDelegate); // 设置接收响应事件的代理;
		m_pChart->On(Evt_click, L"series");      // 注册一个点击事件;



		/* 配置图表; */
		m_pChart->GetGeneralOptions()->GetTitle()->SetText(L"显示X轴刻度线的折线图"); // 设置标题
		m_pChart->GetGeneralOptions()->GetTooltip();  // 显示默认Tooltip
		m_pChart->GetGeneralOptions()->GetLegend();   // 显示默认图例
		m_pChart->GetGeneralOptions()->GetGrid();     // 显示默认Gride

		// 设置平面坐标轴：X 为类目(2. 必须)
		m_pChart->GetGeneralOptions()->GetXAxis()->SetType(ERCTAxisType::E_Category);
		m_pChart->GetGeneralOptions()->GetXAxis()->SetData(L"星期一,星期二,星期三,星期四,星期五,星期六,星期日");
		m_pChart->GetGeneralOptions()->GetXAxis()->GetAxisTick();
		m_pChart->GetGeneralOptions()->GetXAxis()->GetAxisTick()->SetAlignWithLabel(true);
		m_pChart->GetGeneralOptions()->GetXAxis()->GetAxisTick()->SetInside(true);
		m_pChart->GetGeneralOptions()->GetXAxis()->GetAxisLabel()->SetRotate(-45);
		m_pChart->GetGeneralOptions()->GetXAxis()->GetAxisLabel()->SetColor(L"green");
		m_pChart->GetGeneralOptions()->GetXAxis()->GetAxisLabel()->SetTextBorderType(EBorderType::EBT_Dotted);
		m_pChart->GetGeneralOptions()->GetXAxis()->GetAxisLabel()->SetTextBorderColor(L"green");

		// 设置平面坐标轴：Y 为 值(2. 必须);
		m_pChart->GetGeneralOptions()->GetYAxis()->SetType(ERCTAxisType::E_Value);

		vector<int> vctData = { 150, 230, 224, 218, 135, 147, 260 };
		
		/* 设置显示的系列  */
		Line::ILineType* pLineType = m_pChart->GetGeneralOptions()->GetSeries()->CreateLineType(); // 显示为Line;
		pLineType->SetId(L"LINE-001");
		pLineType->SetSymbol(ESymbol::ES_Diamond); // 设置Symbol
		pLineType->SetSymbolSize(10);
		pLineType->SetData(vctData); // 设置系列数据（当前只有一个维度的数据）;

		/* 增加创建的 LineType; (4. 必须) */
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pLineType);

		/* 使配置生效; (5. 必须)*/
		m_pChart->SetOption();

		bResult = TRUE;
	} while (0);

	return bResult;
}


BOOL CLineTypeCase::CreateLadderBasicLineChart()
{
	int nError = 0;
	BOOL bResult = FALSE;
	
	
	do
	{
		/* 为了方便查看 Chart 的整个编辑过程，此处把之前的实例删除掉; */
		if (nullptr != m_pChart)
		{
			m_pChart->Release();
			m_pChart = nullptr;
		}

		/* 创建 Chart 实例(1.必须) */
		m_pChart = m_pManager->CreateChart(nError);
		if (0 != nError)
		{
			m_pDlg->OutputError(L"创建 Chart 失败", nError);
			break;
		}
		m_pChart->Init();
		m_pChart->SetEventDelegate(m_pDelegate); // 设置接收响应事件的代理;
		m_pChart->On(Evt_click, L"series");      // 注册一个点击事件;



		/* 配置图表; */
		m_pChart->GetGeneralOptions()->GetTitle()->SetText(L"阶梯图");  // 设置标题
		m_pChart->GetGeneralOptions()->GetTooltip();  // 显示默认Tooltip
		m_pChart->GetGeneralOptions()->GetLegend();   // 显示默认图例
		m_pChart->GetGeneralOptions()->GetGrid();     // 显示默认Gride


		// 设置平面坐标轴：X 为类目(2. 必须)
		m_pChart->GetGeneralOptions()->GetXAxis()->SetType(ERCTAxisType::E_Category);
		m_pChart->GetGeneralOptions()->GetXAxis()->SetData(L"星期一,星期二,星期三,星期四,星期五,星期六,星期七");

		// 设置平面坐标轴：Y 为 值(2. 必须);
		m_pChart->GetGeneralOptions()->GetYAxis()->SetType(ERCTAxisType::E_Value);

		vector<int> vctData = { 150, 230, 224, 218, 135, 147, 260 };

		/* 设置显示的系列  */
		Line::ILineType* pLineType = m_pChart->GetGeneralOptions()->GetSeries()->CreateLineType(); // 显示为Line;
		pLineType->SetId(L"LINE-001");
		pLineType->SetStepType(EStepType::EST_Auto);
		pLineType->GetItemStyle()->SetColor(L"red");
		pLineType->GetLineStyle()->SetWidth(5);
		pLineType->SetData(vctData); // 设置系列数据（当前只有一个维度的数据）;

		/* 增加创建的 LineType; (4. 必须) */
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pLineType);

		/* 使配置生效; (5. 必须)*/
		m_pChart->SetOption();

		bResult = TRUE;
	} while (0);

	return bResult;
}


BOOL CLineTypeCase::CreateSmoothBasicLineChart()
{
	int nError = 0;
	BOOL bResult = FALSE;

	/* 获取 Chart 的配置; */
	do
	{
		/* 为了方便查看 Chart 的整个编辑过程，此处把之前的实例删除掉; */
		if (nullptr != m_pChart)
		{
			m_pChart->Release();
			m_pChart = nullptr;
		}

		/* 创建 Chart 实例(1.必须) */
		m_pChart = m_pManager->CreateChart(nError);
		if (0 != nError)
		{
			m_pDlg->OutputError(L"创建 Chart 失败", nError);
			break;
		}
		m_pChart->Init();
		m_pChart->SetEventDelegate(m_pDelegate); // 设置接收响应事件的代理;
		m_pChart->On(Evt_click, L"series");      // 注册一个点击事件;

		/* 配置图表; */
		m_pChart->GetGeneralOptions()->GetTitle()->SetText(L"平滑曲线图");  // 设置标题
		m_pChart->GetGeneralOptions()->GetTooltip();  // 显示默认Tooltip
		m_pChart->GetGeneralOptions()->GetLegend();   // 显示默认图例
		m_pChart->GetGeneralOptions()->GetGrid();     // 显示默认Gride


		// 设置平面坐标轴：X 为类目(2. 必须)
		m_pChart->GetGeneralOptions()->GetXAxis()->SetType(ERCTAxisType::E_Category);
		m_pChart->GetGeneralOptions()->GetXAxis()->SetData(L"星期一,星期二,星期三,星期四,星期五,星期六,星期七");
		m_pChart->GetGeneralOptions()->GetXAxis()->SetAlignTicks(true);
		m_pChart->GetGeneralOptions()->GetXAxis()->SetName(L"日期");
		m_pChart->GetGeneralOptions()->GetXAxis()->SetNameLocation(ENameLocation::ENL_End);
		m_pChart->GetGeneralOptions()->GetXAxis()->GetNameTextStyle()->SetColor(L"red");

		// 设置平面坐标轴：Y 为 值(2. 必须);
		m_pChart->GetGeneralOptions()->GetYAxis()->SetType(ERCTAxisType::E_Value);
		m_pChart->GetGeneralOptions()->GetYAxis()->SetName(L"销量");
		m_pChart->GetGeneralOptions()->GetYAxis()->SetNameLocation(ENameLocation::ENL_End);
		m_pChart->GetGeneralOptions()->GetYAxis()->GetNameTextStyle()->SetColor(L"red");

		vector<int> vctData = { 50, 230, 14, 218, 135, 147, 460 };

		/* 设置显示的系列  */
		Line::ILineType* pLineType = m_pChart->GetGeneralOptions()->GetSeries()->CreateLineType();// 显示为Line;
		pLineType->SetId(L"LINE-001");
		//pLineType->SetSymbol(ESymbol::ES_Triangle);
		pLineType->SetSymbolSize(10);
		pLineType->SetSmooth(true);
		pLineType->GetLineStyle()->SetType(ELineStyle::ELS_Dashed);
		pLineType->GetLineStyle()->SetDashOffset(3);
		pLineType->SetData(vctData);// 设置系列数据（当前只有一个维度的数据）;

		/* 增加创建的 LineType; (4. 必须) */
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pLineType);


		/* 使配置生效; (5. 必须)*/
		m_pChart->SetOption();

		bResult = TRUE;
	} while (0);

	return bResult;
}


BOOL CLineTypeCase::CreateBasicAreaChartEx()
{
	int nError = 0;
	BOOL bResult = FALSE;
	
	do
	{
		/* 为了方便查看 Chart 的整个编辑过程，此处把之前的实例删除掉; */
		if (nullptr != m_pChart)
		{
			m_pChart->Release();
			m_pChart = nullptr;
		}

		/* 创建 Chart 实例(1.必须) */
		m_pChart = m_pManager->CreateChart(nError);
		if (0 != nError)
		{
			m_pDlg->OutputError(L"创建 Chart 失败", nError);
			break;
		}
		m_pChart->Init();
		m_pChart->SetEventDelegate(m_pDelegate); // 设置接收响应事件的代理;
		m_pChart->On(Evt_click, L"series");      // 注册一个点击事件;



		/* 配置图表; */
		m_pChart->GetGeneralOptions()->GetTitle()->SetText(L"基础面积图"); // 设置标题
		m_pChart->GetGeneralOptions()->GetTooltip();  // 显示默认Tooltip
		m_pChart->GetGeneralOptions()->GetLegend();   // 显示默认图例
		m_pChart->GetGeneralOptions()->GetGrid();     // 显示默认Gride


		// 设置平面坐标轴：X 为类目(2. 必须)
		m_pChart->GetGeneralOptions()->GetXAxis()->SetType(ERCTAxisType::E_Category);
		m_pChart->GetGeneralOptions()->GetXAxis()->SetData(L"星期一,星期二,星期三,星期四,星期五,星期六,星期七");
		m_pChart->GetGeneralOptions()->GetXAxis()->SetAlignTicks(true);
		m_pChart->GetGeneralOptions()->GetXAxis()->SetName(L"日期");
		m_pChart->GetGeneralOptions()->GetXAxis()->SetNameLocation(ENameLocation::ENL_End);
		m_pChart->GetGeneralOptions()->GetXAxis()->GetNameTextStyle()->SetColor(L"red");
		m_pChart->GetGeneralOptions()->GetXAxis()->SetBoundaryGap(false);

		// 设置平面坐标轴：Y 为 值(2. 必须);
		m_pChart->GetGeneralOptions()->GetYAxis()->SetType(ERCTAxisType::E_Value);
		m_pChart->GetGeneralOptions()->GetYAxis()->SetName(L"销量");
		m_pChart->GetGeneralOptions()->GetYAxis()->SetNameLocation(ENameLocation::ENL_End);
		m_pChart->GetGeneralOptions()->GetYAxis()->GetNameTextStyle()->SetColor(L"red");

		
		vector<int> vctData = { 150, 230, 224, 218, 135, 147, 260 };

		/* 设置显示的系列  */
		Line::ILineType* pLineType = m_pChart->GetGeneralOptions()->GetSeries()->CreateLineType(); // 显示为Line;
		//pLineType->SetSymbol(ESymbol::ES_Triangle);
		pLineType->SetSymbolSize(10);
		pLineType->GetLineStyle()->SetType(ELineStyle::ELS_Dashed);
		pLineType->GetLineStyle()->SetDashOffset(3);
		pLineType->GetAreaStyle();  // 显示区域面积;
		pLineType->SetData(vctData);// 设置系列数据（当前只有一个维度的数据）;


		/* 增加创建的 LineType; (4. 必须) */
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pLineType);


		/* 使配置生效; (5. 必须)*/
		m_pChart->SetOption();

		bResult = TRUE;
	} while (0);

	return bResult;
}

BOOL CLineTypeCase::CreateStackedLineChart()
{
	int nError = 0;
	BOOL bResult = FALSE;
	
	do
	{
		/* 为了方便查看 Chart 的整个编辑过程，此处把之前的实例删除掉; */
		if (nullptr != m_pChart)
		{
			m_pChart->Release();
			m_pChart = nullptr;
		}

		/* 创建 Chart 实例(1.必须) */
		m_pChart = m_pManager->CreateChart(nError);
		if (0 != nError)
		{
			m_pDlg->OutputError(L"创建 Chart 失败", nError);
			break;
		}
		m_pChart->Init();
		m_pChart->SetEventDelegate(m_pDelegate); // 设置接收响应事件的代理;
		m_pChart->On(Evt_click, L"series");      // 注册一个点击事件;


		/* 配置图表; */
		m_pChart->GetGeneralOptions()->GetTitle()->SetText(L"多维折线图");// 设置标题
		m_pChart->GetGeneralOptions()->GetTooltip(); // 显示默认Tooltip
		m_pChart->GetGeneralOptions()->GetLegend();  // 显示默认图例
		m_pChart->GetGeneralOptions()->GetGrid();    // 显示默认Gride

		// 设置平面坐标轴：X 为类目(2. 必须)
		m_pChart->GetGeneralOptions()->GetXAxis()->SetType(ERCTAxisType::E_Category);
		m_pChart->GetGeneralOptions()->GetXAxis()->SetData(L"星期一,星期二,星期三,星期四,星期五,星期六,星期七");
		m_pChart->GetGeneralOptions()->GetXAxis()->SetAlignTicks(true);
		m_pChart->GetGeneralOptions()->GetXAxis()->SetName(L"日期");
		m_pChart->GetGeneralOptions()->GetXAxis()->SetNameLocation(ENameLocation::ENL_End);
		m_pChart->GetGeneralOptions()->GetXAxis()->GetNameTextStyle()->SetColor(L"red");
		m_pChart->GetGeneralOptions()->GetXAxis()->SetBoundaryGap(false);

		// 设置平面坐标轴：Y 为 值(2. 必须);
		m_pChart->GetGeneralOptions()->GetYAxis()->SetType(ERCTAxisType::E_Value);
		m_pChart->GetGeneralOptions()->GetYAxis()->SetName(L"销量");
		m_pChart->GetGeneralOptions()->GetYAxis()->SetNameLocation(ENameLocation::ENL_End);
		m_pChart->GetGeneralOptions()->GetYAxis()->GetNameTextStyle()->SetColor(L"red");
		
		vector<int> vctData1 = { 14590, 16600, 14100, 12400, 13456, 17890, 12600 };
		vector<int> vctData2 = { 15000, 12430, 12240, 12218, 8135, 9147, 19260 };
		vector<int> vctData3 = { 9150, 6230, 7224, 5218, 5135, 8470, 8760 };
		vector<int> vctData4 = { 8150, 7230, 4224, 5218, 3135, 5747, 4860 };

		/* 设置显示的系列  */

		// 【男包】显示为Line;
		Line::ILineType* pLineType1 = m_pChart->GetGeneralOptions()->GetSeries()->CreateLineType();
		pLineType1->SetName(L"男包");
		pLineType1->SetSymbolSize(10);
		pLineType1->GetLineStyle()->SetType(ELineStyle::ELS_Dashed);
		pLineType1->GetLineStyle()->SetDashOffset(3);
		pLineType1->AddData(vctData1); // 设置系列数据;


		// 【女包】显示为Line;
		Line::ILineType* pLineType2 = m_pChart->GetGeneralOptions()->GetSeries()->CreateLineType();
		pLineType2->SetName(L"女包");
		pLineType2->SetSymbolSize(10);
		pLineType2->GetLineStyle()->SetType(ELineStyle::ELS_Dashed);
		pLineType2->GetLineStyle()->SetDashOffset(3);
		pLineType2->AddData(vctData2); // 设置系列数据;


		// 【背包】显示为Line;
		Line::ILineType* pLineType3 = m_pChart->GetGeneralOptions()->GetSeries()->CreateLineType();
		pLineType3->SetName(L"背包");
		pLineType3->SetSymbolSize(10);
		pLineType3->GetLineStyle()->SetType(ELineStyle::ELS_Dashed);
		pLineType3->GetLineStyle()->SetDashOffset(3);
		pLineType3->AddData(vctData3); // 设置系列数据;

		// 【手包】显示为Line;
		Line::ILineType* pLineType4 = m_pChart->GetGeneralOptions()->GetSeries()->CreateLineType();
		pLineType4->SetName(L"手包");
		pLineType4->SetSymbolSize(10);
		pLineType4->GetLineStyle()->SetType(ELineStyle::ELS_Dashed);
		pLineType4->GetLineStyle()->SetDashOffset(3);
		pLineType4->AddData(vctData4); // 设置系列数据;

		/* 增加创建的 LineType; (4. 必须) */
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pLineType1);
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pLineType2);
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pLineType3);
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pLineType4);

		/* 使配置生效; (5. 必须)*/
		m_pChart->SetOption();

		bResult = TRUE;
	} while (0);

	return bResult;
}

BOOL CLineTypeCase::CreateStackedAreaChart()
{
	int nError = 0;
	BOOL bResult = FALSE;
	
	do
	{
		/* 为了方便查看 Chart 的整个编辑过程，此处把之前的实例删除掉; */
		if (nullptr != m_pChart)
		{
			m_pChart->Release();
			m_pChart = nullptr;
		}

		/* 创建 Chart 实例(1.必须) */
		m_pChart = m_pManager->CreateChart(nError);
		if (0 != nError)
		{
			m_pDlg->OutputError(L"创建 Chart 失败", nError);
			break;
		}
		m_pChart->Init();
		m_pChart->SetEventDelegate(m_pDelegate); // 设置接收响应事件的代理;
		m_pChart->On(Evt_click, L"series");      // 注册一个点击事件;



		/* 配置图表; */
		m_pChart->GetGeneralOptions()->GetTitle()->SetText(L"多维面积图"); // 设置标题
		m_pChart->GetGeneralOptions()->GetTooltip();  // 显示默认Tooltip
		m_pChart->GetGeneralOptions()->GetLegend();   // 显示默认图例
		m_pChart->GetGeneralOptions()->GetGrid();     // 显示默认Gride

		// 设置平面坐标轴：X 为类目(2. 必须)
		m_pChart->GetGeneralOptions()->GetXAxis()->SetType(ERCTAxisType::E_Category);
		m_pChart->GetGeneralOptions()->GetXAxis()->SetData(L"星期一,星期二,星期三,星期四,星期五,星期六,星期七");
		m_pChart->GetGeneralOptions()->GetXAxis()->SetAlignTicks(true);
		m_pChart->GetGeneralOptions()->GetXAxis()->SetName(L"日期");
		m_pChart->GetGeneralOptions()->GetXAxis()->SetNameLocation(ENameLocation::ENL_End);
		m_pChart->GetGeneralOptions()->GetXAxis()->GetNameTextStyle()->SetColor(L"red");
		m_pChart->GetGeneralOptions()->GetXAxis()->SetBoundaryGap(false);

		// 设置平面坐标轴：Y 为 值(2. 必须);
		m_pChart->GetGeneralOptions()->GetYAxis()->SetType(ERCTAxisType::E_Value);
		m_pChart->GetGeneralOptions()->GetYAxis()->SetName(L"销量");
		m_pChart->GetGeneralOptions()->GetYAxis()->SetNameLocation(ENameLocation::ENL_End);
		m_pChart->GetGeneralOptions()->GetYAxis()->GetNameTextStyle()->SetColor(L"red");

		vector<int> vctData1 = { 590, 6600, 7100, 12400, 6456, 10890, 12600 };
		vector<int> vctData2 = { 15000, 12430, 1240, 818, 8135, 9147, 19260 };
		vector<int> vctData3 = { 9150, 6230, 224, 5218, 1135, 870, 8760 };
		vector<int> vctData4 = { 8150, 1230, 4224, 5218, 135, 5747, 860 };

		/* 设置显示的系列  */

		// 【男包】显示为Line;
		Line::ILineType* pLineType1 = m_pChart->GetGeneralOptions()->GetSeries()->CreateLineType();
		pLineType1->SetName(L"男包");
		pLineType1->GetLineStyle()->SetType(ELineStyle::ELS_Dashed);
		pLineType1->GetLineStyle()->SetDashOffset(3);
		pLineType1->GetAreaStyle();
		pLineType1->AddData(vctData1); // 设置系列数据;


		// 【女包】显示为Line;
		Line::ILineType* pLineType2 = m_pChart->GetGeneralOptions()->GetSeries()->CreateLineType();
		pLineType2->SetName(L"女包");
		pLineType2->GetLineStyle()->SetType(ELineStyle::ELS_Dashed);
		pLineType2->GetLineStyle()->SetDashOffset(3);
		pLineType2->GetAreaStyle();
		pLineType2->AddData(vctData2); // 设置系列数据;


		// 【背包】显示为Line;
		Line::ILineType* pLineType3 = m_pChart->GetGeneralOptions()->GetSeries()->CreateLineType();
		pLineType3->SetName(L"背包");
		pLineType3->GetLineStyle()->SetType(ELineStyle::ELS_Dashed);
		pLineType3->GetLineStyle()->SetDashOffset(3);
		pLineType3->GetAreaStyle();
		pLineType3->AddData(vctData3); // 设置系列数据;


		// 【手包】显示为Line;
		Line::ILineType* pLineType4 = m_pChart->GetGeneralOptions()->GetSeries()->CreateLineType();
		pLineType4->SetName(L"手包");
		pLineType4->GetLineStyle()->SetType(ELineStyle::ELS_Dashed);
		pLineType4->GetLineStyle()->SetDashOffset(3);
		pLineType4->GetAreaStyle();
		pLineType4->AddData(vctData4); // 设置系列数据;

		/* 增加创建的 LineType; (4. 必须) */
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pLineType1);
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pLineType2);
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pLineType3);
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pLineType4);

		/* 使配置生效; (5. 必须)*/
		m_pChart->SetOption();

		bResult = TRUE;
	} while (0);

	return bResult;
}

BOOL CLineTypeCase::CreateGradientStackedAreaChart()
{
	int nError = 0;
	BOOL bResult = FALSE;
	
	do
	{
		/* 为了方便查看 Chart 的整个编辑过程，此处把之前的实例删除掉; */
		if (nullptr != m_pChart)
		{
			m_pChart->Release();
			m_pChart = nullptr;
		}

		/* 创建 Chart 实例(1.必须) */
		m_pChart = m_pManager->CreateChart(nError);
		if (0 != nError)
		{
			m_pDlg->OutputError(L"创建 Chart 失败", nError);
			break;
		}
		m_pChart->Init();
		m_pChart->SetEventDelegate(m_pDelegate); // 设置接收响应事件的代理;
		m_pChart->On(Evt_click, L"series");      // 注册一个点击事件;


		/* 配置图表; */
		m_pChart->GetGeneralOptions()->GetTitle()->SetText(L"坡度多维面积图");  // 设置标题
		m_pChart->GetGeneralOptions()->GetTooltip();  // 显示默认Tooltip
		m_pChart->GetGeneralOptions()->GetLegend();   // 显示默认图例
		m_pChart->GetGeneralOptions()->GetGrid();     // 显示默认Gride

		// 设置平面坐标轴：X 为类目(2. 必须)
		m_pChart->GetGeneralOptions()->GetXAxis()->SetType(ERCTAxisType::E_Category);
		m_pChart->GetGeneralOptions()->GetXAxis()->SetData(L"星期一,星期二,星期三,星期四,星期五,星期六,星期七");
		m_pChart->GetGeneralOptions()->GetXAxis()->SetAlignTicks(true);
		m_pChart->GetGeneralOptions()->GetXAxis()->SetName(L"日期");
		m_pChart->GetGeneralOptions()->GetXAxis()->SetNameLocation(ENameLocation::ENL_End);
		m_pChart->GetGeneralOptions()->GetXAxis()->GetNameTextStyle()->SetColor(L"red");
		m_pChart->GetGeneralOptions()->GetXAxis()->SetBoundaryGap(false);

		// 设置平面坐标轴：Y 为 值(2. 必须);
		m_pChart->GetGeneralOptions()->GetYAxis()->SetType(ERCTAxisType::E_Value);
		m_pChart->GetGeneralOptions()->GetYAxis()->SetName(L"销量");
		m_pChart->GetGeneralOptions()->GetYAxis()->SetNameLocation(ENameLocation::ENL_End);
		m_pChart->GetGeneralOptions()->GetYAxis()->GetNameTextStyle()->SetColor(L"red");

		vector<int> vctData1 = { 14590, 16600, 14100, 12400, 13456, 17890, 12600 };
		vector<int> vctData2 = { 15000, 12430, 12240, 12218, 8135, 9147, 19260 };
		vector<int> vctData3 = { 9150, 6230, 7224, 5218, 5135, 8470, 8760 };
		vector<int> vctData4 = { 8150, 7230, 4224, 5218, 3135, 5747, 4860 };

		/* 设置显示的系列  */

		// 【男包】显示为Line;
		Line::ILineType* pLineType1 = m_pChart->GetGeneralOptions()->GetSeries()->CreateLineType();
		pLineType1->SetName(L"男包");
		//pLineType1->SetSymbolSize(10);
		pLineType1->SetSmooth(true);
		pLineType1->GetAreaStyle();
		pLineType1->AddData(vctData1); // 设置系列数据;


		// 【女包】显示为Line;
		Line::ILineType* pLineType2 = m_pChart->GetGeneralOptions()->GetSeries()->CreateLineType();
		pLineType2->SetName(L"女包");
		//pLineType2->SetSymbolSize(10);
		pLineType2->SetSmooth(true);
		pLineType2->GetAreaStyle();
		pLineType2->AddData(vctData2); // 设置系列数据;


		// 【背包】显示为Line;
		Line::ILineType* pLineType3 = m_pChart->GetGeneralOptions()->GetSeries()->CreateLineType();
		pLineType3->SetName(L"背包");
		//pLineType3->SetSymbolSize(10);
		pLineType3->SetSmooth(true);
		pLineType3->GetAreaStyle();
		pLineType3->AddData(vctData3); // 设置系列数据;


		// 【手包】显示为Line;
		Line::ILineType* pLineType4 = m_pChart->GetGeneralOptions()->GetSeries()->CreateLineType();
		pLineType4->SetName(L"手包");
		//pLineType4->SetSymbolSize(10);
		pLineType4->SetSmooth(true);
		pLineType4->GetAreaStyle();
		pLineType4->AddData(vctData4); // 设置系列数据;



		/* 增加创建的 LineType; (4. 必须) */
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pLineType1);
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pLineType2);
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pLineType3);
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pLineType4);


		/* 使配置生效; (5. 必须)*/
		m_pChart->SetOption();

		bResult = TRUE;
	} while (0);

	return bResult;
}
