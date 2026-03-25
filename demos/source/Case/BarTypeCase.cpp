#include "pch.h"
#include "IIChartDemoDlg.h"
#include "BarTypeCase.h"

CBarTypeCase::CBarTypeCase(IIChart::IChartManager* pManager, CIIChartDemoDlg* pDlg, IChartEventDelegate* pDelegate)
     : m_pManager(pManager)
	 , m_pDlg(pDlg)
	 , m_pDelegate(pDelegate)
{
	m_vctFunction.push_back(L"<1>平面直角坐标系中的直方图");	
	m_vctFunction.push_back(L"<2>X轴与Y轴互换的直方图");

	m_vctFunction.push_back(L"<3>极坐标系半径轴为类目的直方图");
	m_vctFunction.push_back(L"<4>极坐标系角度为类目的直方图");

	m_vctFunction.push_back(L"<5>多维直方图");
	m_vctFunction.push_back(L"<6>堆叠直方图");

	m_vctFunction.push_back(L"<7>模拟更新数据");
}

CBarTypeCase::~CBarTypeCase()
{
}

vector<wstring> CBarTypeCase::GetFunctionList()
{
	return m_vctFunction;
}

int CBarTypeCase::RunFunction(const wstring& wsItemName)
{
	int nResult = 1;

	do
	{
		m_pDlg->OutputLine(L"RunFunction:[%s]", wsItemName.c_str());
		if (0 == wsItemName.compare(L"<1>平面直角坐标系中的直方图"))
		{
			if (FALSE == CreateBasicBarChartInXY()) break;
		}
		else if (0 == wsItemName.compare(L"<2>X轴与Y轴互换的直方图"))
		{
			if (FALSE == CreateX2YBasicBarChart()) break;
		}
		else if (0 == wsItemName.compare(L"<3>极坐标系半径轴为类目的直方图"))
		{
			if (FALSE == CreateBasicBarChartInPolarRadiusAxis()) break;
		}
		else if (0 == wsItemName.compare(L"<4>极坐标系角度为类目的直方图"))
		{
			if (FALSE == CreateBasicBarChartInPolarAngleAxis()) break;
		}
		else if (0 == wsItemName.compare(L"<5>多维直方图"))
		{
			if (FALSE == CreateMultiBarChart()) break;
		}
		else if (0 == wsItemName.compare(L"<6>堆叠直方图"))
		{
			if (FALSE == CreateStackedBarChart()) break;
		}		
		else if (0 == wsItemName.compare(L"<7>模拟更新数据"))
		{
			if (FALSE == UpdateData()) break;
		}

		nResult = 0;
	} while (0);
	

	// 没有对应的项目;
	return nResult;
}

void CBarTypeCase::ClearChart()
{
	if (nullptr != m_pChart)
	{
		m_pChart->Release();
		m_pChart = nullptr;
	}
}

void CBarTypeCase::Release()
{
	delete this;
}

BOOL CBarTypeCase::UpdateData()
{
	if (nullptr == m_pChart)
	{
		m_pDlg->OutputError(L"未创建 Chart");
		return FALSE;
	}

	/* 1. 取新的数据; */
	vector<int> vctData ;
	G_GetRandomData(vctData, 7, 13, 300);

	/* 2. 通过 ID 获取指定的系列并设置最新的数据;  */
	Bar::IBarType* pBarType = m_pChart->GetGeneralOptions()->GetSeries()->CreateBarType(); // 显示为Bar;
	pBarType->SetId(L"LINE-001");
	pBarType->SetData(vctData); // 设置系列数据（当前只有一个维度的数据）;

	/* 3. 增加此系列; */
	m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pBarType);

	/* 4. 更新和配置生效【可同步也可异步】; */
	m_pChart->SetOptionAsync();

	return TRUE;
}

BOOL CBarTypeCase::CreateBasicBarChartInXY()
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
		Bar::IBarType* pBarType = m_pChart->GetGeneralOptions()->GetSeries()->CreateBarType(); // 显示为Bar;
		pBarType->SetId(L"LINE-001");
		pBarType->SetData(vctData); // 设置系列数据（当前只有一个维度的数据）;

		/* 增加创建的 BarType; (4. 必须) */
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pBarType);

		/* 使配置生效; (5. 必须)*/
		m_pChart->SetOption();

		bResult = TRUE;
	} while (0);


	return bResult;
}

BOOL CBarTypeCase::CreateBasicBarChartInPolarRadiusAxis()
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
		m_pChart->GetGeneralOptions()->GetPolar()->SetRadius(10, 80, true); 
		m_pChart->GetGeneralOptions()->GetAngleAxis()->SetData(L"星期一,星期二,星期三,星期四,星期五,星期六,星期七"); // 设置平面坐标轴：X 为类目(2. 必须)
		m_pChart->GetGeneralOptions()->GetAngleAxis()->SetType(ERCTAxisType::E_Category); // 设置平面坐标轴：Y 为 值(2. 必须);
		m_pChart->GetGeneralOptions()->GetRadiusAxis()->SetMax(300);

		vector<int> vctData = { 150, 230, 224, 218, 135, 147, 260 };

		/* 设置显示的系列  */
		Bar::IBarType* pBarType = m_pChart->GetGeneralOptions()->GetSeries()->CreateBarType(); // 显示为Bar;
		pBarType->SetId(L"LINE-001");
		pBarType->SetCoordinateSystem(ECoordinateSystem::ECS_Ploar);
		pBarType->SetData(vctData); // 设置系列数据（当前只有一个维度的数据）;

		/* 增加创建的 BarType; (4. 必须) */
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pBarType);

		/* 使配置生效; (5. 必须)*/
		m_pChart->SetOption();

		bResult = TRUE;
	} while (0);


	return bResult;
}

BOOL CBarTypeCase::CreateBasicBarChartInPolarAngleAxis()
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
		m_pChart->GetGeneralOptions()->GetPolar()->SetRadius(10, 80, true);
		m_pChart->GetGeneralOptions()->GetRadiusAxis()->SetData(L"星期一,星期二,星期三,星期四,星期五,星期六,星期七"); // 设置平面坐标轴：X 为类目(2. 必须)
		m_pChart->GetGeneralOptions()->GetRadiusAxis()->SetType(ERCTAxisType::E_Category); // 设置平面坐标轴：Y 为 值(2. 必须);
		m_pChart->GetGeneralOptions()->GetAngleAxis()->SetMax(300);

		vector<int> vctData = { 150, 230, 224, 218, 135, 147, 260 };

		/* 设置显示的系列  */
		Bar::IBarType* pBarType = m_pChart->GetGeneralOptions()->GetSeries()->CreateBarType(); // 显示为Bar;
		pBarType->SetId(L"LINE-001");
		pBarType->SetCoordinateSystem(ECoordinateSystem::ECS_Ploar);
		pBarType->SetData(vctData); // 设置系列数据（当前只有一个维度的数据）;

		/* 增加创建的 BarType; (4. 必须) */
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pBarType);

		/* 使配置生效; (5. 必须)*/
		m_pChart->SetOption();

		bResult = TRUE;
	} while (0);


	return bResult;
}


BOOL CBarTypeCase::CreateX2YBasicBarChart()
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
		m_pChart->GetGeneralOptions()->GetTitle()->SetText(L"X轴与Y轴互换的直方图"); // 设置标题
		m_pChart->GetGeneralOptions()->GetYAxis()->SetType(ERCTAxisType::E_Category);     // 设置平面坐标轴：Y 为类目(2. 必须)
		m_pChart->GetGeneralOptions()->GetYAxis()->SetData(L"星期一,星期二,星期三,星期四,星期五,星期六,星期七");  // 设置平面坐标轴：Y 为类目(2. 必须)
		m_pChart->GetGeneralOptions()->GetXAxis()->SetType(ERCTAxisType::E_Value);        // 设置平面坐标轴：X 为 值(2. 必须);

		/* 设置显示的系列  */
		Bar::IBarType* pBarType = m_pChart->GetGeneralOptions()->GetSeries()->CreateBarType(); // 显示为Bar;
		pBarType->SetId(L"LINE-001");

		vector<int> vctData = { 150, 230, 224, 218, 135, 147, 260 };
		pBarType->SetData(vctData);  // 设置系列数据（当前只有一个维度的数据）;


		/* 增加创建的 BarType; (4. 必须) */
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pBarType);


		/* 使配置生效; (5. 必须)*/
		m_pChart->SetOption();

		bResult = TRUE;
	} while (0);


	return bResult;
}


BOOL CBarTypeCase::CreateMultiBarChart()
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

		// 【男包】显示为Bar;
		Bar::IBarType* pBarType1 = m_pChart->GetGeneralOptions()->GetSeries()->CreateBarType();
		pBarType1->SetName(L"男包");
		pBarType1->AddData(vctData1); // 设置系列数据;


		// 【女包】显示为Line;
		Bar::IBarType* pBarType2 = m_pChart->GetGeneralOptions()->GetSeries()->CreateBarType();
		pBarType2->SetName(L"女包");
		pBarType2->AddData(vctData2); // 设置系列数据;


		// 【背包】显示为Bar;
		Bar::IBarType* pBarType3 = m_pChart->GetGeneralOptions()->GetSeries()->CreateBarType();
		pBarType3->SetName(L"背包");
		pBarType3->AddData(vctData3); // 设置系列数据;

		// 【手包】显示为Line;
		Bar::IBarType* pBarType4 = m_pChart->GetGeneralOptions()->GetSeries()->CreateBarType();
		pBarType4->SetName(L"手包");
		pBarType4->AddData(vctData4); // 设置系列数据;

		/* 增加创建的 BarType; (4. 必须) */
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pBarType1);
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pBarType2);
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pBarType3);
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pBarType4);

		/* 使配置生效; (5. 必须)*/
		m_pChart->SetOption();

		bResult = TRUE;
	} while (0);

	return bResult;
}

BOOL CBarTypeCase::CreateStackedBarChart()
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
		Bar::IBarType* pBarType1 = m_pChart->GetGeneralOptions()->GetSeries()->CreateBarType();
		pBarType1->SetName(L"男包");
		pBarType1->AddData(vctData1); // 设置系列数据;


		// 【女包】显示为Line;
		Bar::IBarType* pBarType2 = m_pChart->GetGeneralOptions()->GetSeries()->CreateBarType();
		pBarType2->SetName(L"女包");
		pBarType2->AddData(vctData2); // 设置系列数据;


		// 【背包】显示为Line;
		Bar::IBarType* pBarType3 = m_pChart->GetGeneralOptions()->GetSeries()->CreateBarType();
		pBarType3->SetName(L"背包");
		pBarType3->AddData(vctData3); // 设置系列数据;


		// 【手包】显示为Line;
		Bar::IBarType* pBarType4 = m_pChart->GetGeneralOptions()->GetSeries()->CreateBarType();
		pBarType4->SetName(L"手包");
		pBarType4->AddData(vctData4); // 设置系列数据;

		/* 增加创建的 BarType; (4. 必须) */
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pBarType1);
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pBarType2);
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pBarType3);
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pBarType4);

		/* 使配置生效; (5. 必须)*/
		m_pChart->SetOption();

		bResult = TRUE;
	} while (0);

	return bResult;
}
