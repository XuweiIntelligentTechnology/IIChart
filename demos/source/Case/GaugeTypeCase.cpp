#include "pch.h"
#include "IIChartDemoDlg.h"
#include "GaugeTypeCase.h"

CGaugeTypeCase::CGaugeTypeCase(IIChart::IChartManager* pManager, CIIChartDemoDlg* pDlg, IChartEventDelegate* pDelegate)
     : m_pManager(pManager)
	 , m_pDlg(pDlg)
	 , m_pDelegate(pDelegate)
{
	m_vctFunction.push_back(L"<1>基础仪表盘");
	m_vctFunction.push_back(L"<2>带标签数字动画的基础仪表盘");
	m_vctFunction.push_back(L"<3>速度仪表盘");
	//m_vctFunction.push_back(L"<4>进度仪表盘");
	//m_vctFunction.push_back(L"<5>阶段速度仪表盘");
	//m_vctFunction.push_back(L"<6>等级仪表盘");
	//m_vctFunction.push_back(L"<7>多标题仪表盘");
	//m_vctFunction.push_back(L"<8>气温仪表盘");
	//m_vctFunction.push_back(L"<9>得分环");
	//m_vctFunction.push_back(L"<10>气压表");
	//m_vctFunction.push_back(L"<11>时钟仪表盘");
	//m_vctFunction.push_back(L"<12>汽车仪表盘");
	//m_vctFunction.push_back(L"<13>模拟更新数据");
}

CGaugeTypeCase::~CGaugeTypeCase()
{
}

vector<wstring> CGaugeTypeCase::GetFunctionList()
{
	return m_vctFunction;
}

int CGaugeTypeCase::RunFunction(const wstring& wsItemName)
{
	int nResult = 1;

	do
	{
		m_pDlg->OutputLine(L"RunFunction:[%s]", wsItemName.c_str());
		if (0 == wsItemName.compare(L"<1>基础仪表盘"))
		{
			if (FALSE == CreateGaugeBasic()) break;
		}	
		else if (0 == wsItemName.compare(L"<2>带标签数字动画的基础仪表盘"))
		{
			if (FALSE == CreateSimpleGauge()) break;
		}
		else if (0 == wsItemName.compare(L"<3>速度仪表盘"))
		{
			if (FALSE == CreateSpeedGauge()) break;
		}
		else if (0 == wsItemName.compare(L"<4>进度仪表盘"))
		{
		}
		else if (0 == wsItemName.compare(L"<5>阶段速度仪表盘"))
		{
		}
		else if (0 == wsItemName.compare(L"<6>等级仪表盘"))
		{
		}
		else if (0 == wsItemName.compare(L"<7>多标题仪表盘"))
		{
		}
		else if (0 == wsItemName.compare(L"<8>气温仪表盘"))
		{
		}
		else if (0 == wsItemName.compare(L"<9>得分环"))
		{
		}
		else if (0 == wsItemName.compare(L"<10>气压表"))
		{
		}
		else if (0 == wsItemName.compare(L"<11>时钟仪表盘"))
		{
		}
		else if (0 == wsItemName.compare(L"<12>汽车仪表盘"))
		{
		}
		else if (0 == wsItemName.compare(L"<13>模拟更新数据"))
		{
			if (FALSE == UpdateData()) break;
		}

		nResult = 0;
	} while (0);
	

	// 没有对应的项目;
	return nResult;
}

void CGaugeTypeCase::ClearChart()
{
	if (nullptr != m_pChart)
	{
		m_pChart->Release();
		m_pChart = nullptr;
	}
}

void CGaugeTypeCase::Release()
{
	delete this;
}

BOOL CGaugeTypeCase::UpdateData()
{
	if (nullptr == m_pChart)
	{
		m_pDlg->OutputError(L"未创建 Chart");
		return FALSE;
	}

	return TRUE;
}

BOOL CGaugeTypeCase::CreateGaugeBasic()
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
		m_pChart->GetGeneralOptions()->GetTooltip()->SetFormatter(L"{a}<br/>{b}:{c}%");


		/* 设置显示的系列  */
		Gauge::IGaugeType* pGaugeType = m_pChart->GetGeneralOptions()->GetSeries()->CreateGaugeType(); // 显示为Gauge;
		pGaugeType->SetName(L"Pressure");
		pGaugeType->GetDetail()->SetFormatter(L"{value}");
		pGaugeType->AddData(50, L"SCORE");


		/* 增加创建的 GaugeType*/
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pGaugeType);

		/* 使配置生效*/
		m_pChart->SetOption();

		bResult = TRUE;
	} while (0);


	return bResult;
}

BOOL CGaugeTypeCase::CreateSimpleGauge()
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
		m_pChart->GetGeneralOptions()->GetTooltip()->SetFormatter(L"{a}<br/>{b}:{c}%");


		/* 设置显示的系列  */
		Gauge::IGaugeType* pGaugeType = m_pChart->GetGeneralOptions()->GetSeries()->CreateGaugeType(); // 显示为Gauge;
		pGaugeType->SetName(L"Pressure");
		pGaugeType->GetProgress()->SetShow(true);
		pGaugeType->GetDetail()->SetValueAnimation(true);
		pGaugeType->GetDetail()->SetFormatter(L"{value}");
		pGaugeType->AddData(50, L"SCORE");


		/* 增加创建的 GaugeType*/
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pGaugeType);

		/* 使配置生效*/
		m_pChart->SetOption();

		bResult = TRUE;
	} while (0);


	return bResult;
}

BOOL CGaugeTypeCase::CreateSpeedGauge()
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

		/* 设置显示的系列  */
		Gauge::IGaugeType* pGaugeType = m_pChart->GetGeneralOptions()->GetSeries()->CreateGaugeType(); // 显示为Gauge
		pGaugeType->GetProgress()->SetShow(true);
		pGaugeType->GetProgress()->SetWidth(18);

		pGaugeType->GetAxisLine()->GetLineStyle()->SetWidth(18);
		pGaugeType->GetAxisTick()->SetShow(false);
		pGaugeType->GetSplitLine()->SetLength(15, false);
		pGaugeType->GetSplitLine()->GetLineStyle()->SetWidth(2);
		pGaugeType->GetSplitLine()->GetLineStyle()->SetColor(L"#999");
		pGaugeType->GetAxisLabel()->SetDistance(25);
		pGaugeType->GetAxisLabel()->SetColor(L"#999");
		pGaugeType->GetAxisLabel()->SetFontSize(20);
		pGaugeType->GetAnchor()->SetShow(true);
		pGaugeType->GetAnchor()->SetShowAbove(true);
		pGaugeType->GetAnchor()->SetSize(25);
		pGaugeType->GetAnchor()->GetItemStyle()->SetBorderWidth(10);
		pGaugeType->GetTitle()->SetShow(false);

		pGaugeType->GetDetail()->SetValueAnimation(true);
		pGaugeType->GetDetail()->SetFontSize(80);
		pGaugeType->GetDetail()->SetOffsetCenter(0, 70, true);
		pGaugeType->AddData(70);


		/* 增加创建的 GaugeType*/
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pGaugeType);

		/* 使配置生效*/
		m_pChart->SetOption();

		bResult = TRUE;
	} while (0);


	return bResult;
}