#include "pch.h"
#include "IIChartDemoDlg.h"
#include "RadarTypeCase.h"

CRadarTypeCase::CRadarTypeCase(IIChart::IChartManager* pManager, CIIChartDemoDlg* pDlg, IChartEventDelegate* pDelegate)
     : m_pManager(pManager)
	 , m_pDlg(pDlg)
	 , m_pDelegate(pDelegate)
{
	m_vctFunction.push_back(L"<1>基础雷达图");
	m_vctFunction.push_back(L"<2>多雷达图");
	//m_vctFunction.push_back(L"<3>模拟更新数据");
}

CRadarTypeCase::~CRadarTypeCase()
{
}

vector<wstring> CRadarTypeCase::GetFunctionList()
{
	return m_vctFunction;
}

int CRadarTypeCase::RunFunction(const wstring& wsItemName)
{
	int nResult = 1;

	do
	{
		m_pDlg->OutputLine(L"RunFunction:[%s]", wsItemName.c_str());
		if (0 == wsItemName.compare(L"<1>基础雷达图"))
		{
			if (FALSE == CreateBasicRadar()) break;
		}	
		else if (0 == wsItemName.compare(L"<2>多雷达图"))
		{
			if (FALSE == CreateMultipleRadar()) break;
		}
		else if (0 == wsItemName.compare(L"<3>模拟更新数据"))
		{
			if (FALSE == UpdateData()) break;
		}

		nResult = 0;
	} while (0);
	

	// 没有对应的项目;
	return nResult;
}

void CRadarTypeCase::ClearChart()
{
	if (nullptr != m_pChart)
	{
		m_pChart->Release();
		m_pChart = nullptr;
	}
}

void CRadarTypeCase::Release()
{
	delete this;
}

BOOL CRadarTypeCase::UpdateData()
{
	if (nullptr == m_pChart)
	{
		m_pDlg->OutputError(L"未创建 Chart");
		return FALSE;
	}

	return TRUE;
}

BOOL CRadarTypeCase::CreateBasicRadar()
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
		m_pChart->GetGeneralOptions()->GetTitle()->SetText(L"Basic Radar Chart"); // [可选项]设置标题
		m_pChart->GetGeneralOptions()->GetLegend()->SetData(L"Allocated Budget, Actual Spending");

		m_pChart->GetGeneralOptions()->GetRadar()->AddIndicator(L"Sales", 6500);
		m_pChart->GetGeneralOptions()->GetRadar()->AddIndicator(L"Administration", 16000);
		m_pChart->GetGeneralOptions()->GetRadar()->AddIndicator(L"Information Technology", 30000);
		m_pChart->GetGeneralOptions()->GetRadar()->AddIndicator(L"Customer Support", 38000);
		m_pChart->GetGeneralOptions()->GetRadar()->AddIndicator(L"Development", 52000);
		m_pChart->GetGeneralOptions()->GetRadar()->AddIndicator(L"Marketing", 25000);

		/* 设置显示的系列*/
		Radar::IRadarType* pRadarType = m_pChart->GetGeneralOptions()->GetSeries()->CreateRadarType(); // 显示为Radar;
		pRadarType->SetName(L"Budget vs spending");
		pRadarType->AddOneDimensionData(L"Allocated Budget", L"4200, 3000, 20000, 35000, 50000, 18000");
		pRadarType->AddOneDimensionData(L"Actual Spending", L"5000, 14000, 28000, 26000, 42000, 21000");

		/* 增加创建的 BarType*/
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pRadarType);

		/* 使配置生效*/
		m_pChart->SetOption();

		bResult = TRUE;
	} while (0);


	return bResult;
}

BOOL CRadarTypeCase::CreateMultipleRadar()
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
		m_pChart->GetGeneralOptions()->GetTitle()->SetText(L"Multiple Radar"); // [可选项]设置标题
		m_pChart->GetGeneralOptions()->GetTooltip()->SetTrigger(ETT_Axis);
		m_pChart->GetGeneralOptions()->GetLegend()->SetLeft(ELV_Center);
		m_pChart->GetGeneralOptions()->GetLegend()->SetData(L"A Software, A Phone, Another Phone, Precipitation, Evaporation");

		RadarComp::IRadar* pRadar = m_pChart->GetGeneralOptions()->CreateRadar();
		pRadar->AddIndicator(L"Brand", 100);
		pRadar->AddIndicator(L"Content", 100);
		pRadar->AddIndicator(L"Usability", 100);
		pRadar->AddIndicator(L"Function", 100);
		pRadar->SetCenter(25, 40, true);
		pRadar->SetRadius(80, false);
		m_pChart->GetGeneralOptions()->Add(pRadar);
		pRadar->Reset();

		pRadar->AddIndicator(L"Look", 100);
		pRadar->AddIndicator(L"Photo", 100);
		pRadar->AddIndicator(L"System", 100);
		pRadar->AddIndicator(L"Performance", 100);
		pRadar->AddIndicator(L"Screen", 100);
		pRadar->SetCenter(50, 60, true);
		pRadar->SetRadius(80, false);
		m_pChart->GetGeneralOptions()->Add(pRadar);
		pRadar->Reset();

		for (int i = 1; i <= 12; i++) {
			wstring strName = to_wstring(i) + L"月";
			pRadar->AddIndicator(strName.c_str(), 100);
		}
		pRadar->SetCenter(70, 40, true);
		pRadar->SetRadius(80, false);
		m_pChart->GetGeneralOptions()->Add(pRadar);

		/* 设置显示的系列  */
		Radar::IRadarType* pRadarType = m_pChart->GetGeneralOptions()->GetSeries()->CreateRadarType(); // 显示为Radar;
		pRadarType->GetTooltip();
		pRadarType->GetAreaStyle();
		pRadarType->SetRadarIndex(0);
		pRadarType->AddOneDimensionData(L"A Software", L"60, 73, 85, 40");
		/* 增加创建的 BarType */
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pRadarType);

		/* 设置显示的系列  */
		Radar::IRadarType* pRadarType1 = m_pChart->GetGeneralOptions()->GetSeries()->CreateRadarType(); // 显示为Radar;
		pRadarType1->SetRadarIndex(1);
		pRadarType1->GetAreaStyle();
		pRadarType1->AddOneDimensionData(L"A Phone", L"85, 90, 90, 95, 95");
		pRadarType1->AddOneDimensionData(L"Another Phone", L"95, 80, 95, 90, 93");
		/* 增加创建的 BarType */
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pRadarType1);

		/* 设置显示的系列 */
		Radar::IRadarType* pRadarType2 = m_pChart->GetGeneralOptions()->GetSeries()->CreateRadarType(); // 显示为Radar;
		pRadarType2->SetRadarIndex(2);
		pRadarType2->GetAreaStyle();
		pRadarType2->AddOneDimensionData(L"Precipitation", L"2.6, 5.9, 9.0, 26.4, 28.7, 70.7, 75.6, 82.2, 48.7, 18.8, 6.0, 2.3");
		pRadarType2->AddOneDimensionData(L"Evaporation", L"2.0, 4.9, 7.0, 23.2, 25.6, 76.7, 35.6, 62.2, 32.6, 20.0, 6.4, 3.3");
		/* 增加创建的 BarType*/
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pRadarType2);

		/* 使配置生效*/
		m_pChart->SetOption();

		bResult = TRUE;
	} while (0);


	return bResult;
}