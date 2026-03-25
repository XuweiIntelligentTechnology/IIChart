#include "pch.h"
#include "IIChartDemoDlg.h"
#include "PieTypeCase.h"

CPieTypeCase::CPieTypeCase(IIChart::IChartManager* pManager, CIIChartDemoDlg* pDlg, IChartEventDelegate* pDelegate)
     : m_pManager(pManager)
	 , m_pDlg(pDlg)
	 , m_pDelegate(pDelegate)
{
	m_vctFunction.push_back(L"<1>某站点用户");
	m_vctFunction.push_back(L"<2>圆角环形图");
	//m_vctFunction.push_back(L"<3>模拟更新数据");
}

CPieTypeCase::~CPieTypeCase()
{
}

vector<wstring> CPieTypeCase::GetFunctionList()
{
	return m_vctFunction;
}

int CPieTypeCase::RunFunction(const wstring& wsItemName)
{
	int nResult = 1;

	do
	{
		m_pDlg->OutputLine(L"RunFunction:[%s]", wsItemName.c_str());
		if (0 == wsItemName.compare(L"<1>某站点用户"))
		{
			if (FALSE == CreateRefererWebsite()) break;
		}	
		else if (0 == wsItemName.compare(L"<2>圆角环形图"))
		{
			if (FALSE == CreateRoundedCorner()) break;
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

void CPieTypeCase::ClearChart()
{
	if (nullptr != m_pChart)
	{
		m_pChart->Release();
		m_pChart = nullptr;
	}
}

void CPieTypeCase::Release()
{
	delete this;
}

BOOL CPieTypeCase::UpdateData()
{
	if (nullptr == m_pChart)
	{
		m_pDlg->OutputError(L"未创建 Chart");
		return FALSE;
	}

	return TRUE;
}

BOOL CPieTypeCase::CreateRefererWebsite()
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
			m_pChart->On(Evt_legendselectchanged, L"series");      // [可选项]注册一个点击事件;
		}

		/* 配置图表; */
		m_pChart->GetGeneralOptions()->GetTitle()->SetText(L"Referer of a Website"); // [可选项]设置标题
		m_pChart->GetGeneralOptions()->GetTitle()->SetSubText(L"Fake Data"); // [可选项]设置标题
		m_pChart->GetGeneralOptions()->GetTitle()->SetLeft(ELV_Center);
		m_pChart->GetGeneralOptions()->GetTooltip()->SetTrigger(ETT_Item);
		m_pChart->GetGeneralOptions()->GetLegend()->SetOrient(EA_Vertical);
		m_pChart->GetGeneralOptions()->GetLegend()->SetLeft(ELV_Left);

		/* 设置显示的系列  */
		Pie::IPieType* pPieType = m_pChart->GetGeneralOptions()->GetSeries()->CreatePieType(); // 显示为Pie;

		pPieType->SetName(L"Access From");
		pPieType->SetRadius(50, true);
		pPieType->SetId(L"PIE-001");
		pPieType->AddData(L"Search Engine", 1048);
		pPieType->AddData(L"Direct", 735);
		pPieType->AddData(L"Email", 580);
		pPieType->AddData(L"Union Ads", 484);
		pPieType->AddData(L"Video Ads", 300);
		Pie::IPieTypeEmphasisItemStyle* pItemStyle = pPieType->GetEmphasis()->GetItemStyle();
		if (pItemStyle)
		{
			pItemStyle->SetShadowBlur(10);
			pItemStyle->SetShadowOffsetX(1);
			pItemStyle->SetShadowColor(0,0,0,0.5);
		}

		/* 增加创建的 BarType; (4. 必须) */
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pPieType);

		/* 使配置生效; (5. 必须)*/
		m_pChart->SetOption();

		bResult = TRUE;
	} while (0);


	return bResult;
}

BOOL CPieTypeCase::CreateRoundedCorner()
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
		m_pChart->GetGeneralOptions()->GetTooltip()->SetTrigger(ETT_Item);
		m_pChart->GetGeneralOptions()->GetLegend()->SetTop(5, true);
		m_pChart->GetGeneralOptions()->GetLegend()->SetLeft(ELV_Center);

		/* 设置显示的系列  */
		Pie::IPieType* pPieType = m_pChart->GetGeneralOptions()->GetSeries()->CreatePieType(); // 显示为Pie;

		pPieType->SetName(L"Access From");
		pPieType->SetRadius(40, 70, true);
		pPieType->SetAvoidLabelOverlap(false);

		Pie::IPieTypeItemStyle* pItemStyle = pPieType->GetItemStyle();
		if (pItemStyle)
		{
			pItemStyle->SetBorderRadius(10, false);
			pItemStyle->SetBorderColor(L"#fff");
			pItemStyle->SetBorderWidth(2);
		}

		Pie::IPieTypeLabel* pPieTypeLabel = pPieType->GetLabel();
		if (pPieTypeLabel)
		{
			pPieTypeLabel->SetShow(false);
			pPieTypeLabel->SetPosition(EP_Inside);
		}

		Pie::IPieTypeEmphasisLabel* pPieTypeEmphasisLabel = pPieType->GetEmphasis()->GetLabel();
		if (pPieTypeEmphasisLabel)
		{
			pPieTypeEmphasisLabel->SetShow(true);
			pPieTypeEmphasisLabel->SetFontSize(40);
			pPieTypeEmphasisLabel->SetFontWeight(EFW_Bold);
		}

		Pie::IPieTypeLabelLine* pPieTypeLabelLine = pPieType->GetLabelLine();
		if (pPieTypeLabelLine)
		{
			pPieTypeLabelLine->SetShow(false);
		}

		pPieType->AddData(L"Search Engine", 1048);
		pPieType->AddData(L"Direct", 735);
		pPieType->AddData(L"Email", 580);
		pPieType->AddData(L"Union Ads", 484);
		pPieType->AddData(L"Video Ads", 300);

		/* 增加创建的 BarType; (4. 必须) */
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pPieType);

		/* 使配置生效; (5. 必须)*/
		m_pChart->SetOption();

		bResult = TRUE;
	} while (0);


	return bResult;
}