#include "pch.h"
#include "IIChartDemoDlg.h"
#include "MapTypeCase.h"

CMapTypeCase::CMapTypeCase(IIChart::IChartManager* pManager, CIIChartDemoDlg* pDlg, IChartEventDelegate* pDelegate)
     : m_pManager(pManager)
	 , m_pDlg(pDlg)
	 , m_pDelegate(pDelegate)
{
	m_vctFunction.push_back(L"<1>内脏数据");
	m_vctFunction.push_back(L"<2>地图");
	//m_vctFunction.push_back(L"<3>交通");
	//m_vctFunction.push_back(L"<4>模拟更新数据");
}

CMapTypeCase::~CMapTypeCase()
{
}

vector<wstring> CMapTypeCase::GetFunctionList()
{
	return m_vctFunction;
}

int CMapTypeCase::RunFunction(const wstring& wsItemName)
{
	int nResult = 1;

	do
	{
		m_pDlg->OutputLine(L"RunFunction:[%s]", wsItemName.c_str());
		if (0 == wsItemName.compare(L"<1>内脏数据"))
		{
			if (FALSE == CreateOrganData()) break;
		}	
		else if (0 == wsItemName.compare(L"<2>地图"))
		{
			if (FALSE == CreateMap()) break;
		}
		else if (0 == wsItemName.compare(L"<3>交通"))
		{
			if (FALSE == CreateTrafficMap()) break;
		}
		else if (0 == wsItemName.compare(L"<4>模拟更新数据"))
		{
			if (FALSE == UpdateData()) break;
		}

		nResult = 0;
	} while (0);
	

	// 没有对应的项目;
	return nResult;
}

void CMapTypeCase::ClearChart()
{
	if (nullptr != m_pChart)
	{
		m_pChart->Release();
		m_pChart = nullptr;
	}
}

void CMapTypeCase::Release()
{
	delete this;
}

BOOL CMapTypeCase::UpdateData()
{
	if (nullptr == m_pChart)
	{
		m_pDlg->OutputError(L"未创建 Chart");
		return FALSE;
	}

	return TRUE;
}

BOOL CMapTypeCase::CreateOrganData()
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
		m_pChart->On(Evt_mouseover, L"series");
		m_pChart->On(Evt_mouseout, L"series");
		m_pChart->On(Evt_geoselectchanged, L"series");
		//m_pChart->On(Evt_geoselected, L"series");

		wstring wsFile = GetCurrentPath() + L"TestData\\geo\\Veins_Medical_Diagram_clip_art.svg";
		/* 导入地图 */
		nError = m_pManager->RegisterSvgMapFromFile(L"organ_diagram", wsFile.c_str());

		/* 配置图表; */
		m_pChart->GetGeneralOptions()->GetTooltip();

		Geo::IGeo* pGeo = m_pChart->GetGeneralOptions()->GetGeo();
		pGeo->SetLeft(10, true);
		pGeo->SetRight(50, true);
		pGeo->SetMap(L"organ_diagram");
		pGeo->SetSelectedMode(ESM_Multiple);
		pGeo->SetZoom(0.75);
		pGeo->SetCenter(320, 220, false);

		Geo::IGeoEmphasisEx* pGeoEmphasis = pGeo->GetEmphasis();
		pGeoEmphasis->SetFocus(EF_Self);
		pGeoEmphasis->GetItemStyle()->SetColor(L"");

		Geo::IGeoLabel* pGeoLabel = pGeoEmphasis->GetLabel();
		pGeoLabel->SetPosition(EP_Bottom);
		pGeoLabel->SetDistance(0);
		pGeoLabel->SetTextBorderColor(L"#fff");
		pGeoLabel->SetTextBorderWidth(2);

		Geo::IGeoBlur* pGeoBlur = pGeo->GetBlur();
		Geo::IGeoSelect* pGeoSelect = pGeo->GetSelect();
		pGeoSelect->GetItemStyle()->SetColor(L"#b50205");
		Geo::IGeoLabel* pGeoSelectLabel = pGeoSelect->GetLabel();
		pGeoSelectLabel->SetShow(false);
		pGeoSelectLabel->SetTextBorderColor(L"#fff");
		pGeoSelectLabel->SetTextBorderWidth(2);
		
		Grid::IGrid* pGrid = m_pChart->GetGeneralOptions()->GetGrid();
		pGrid->SetLeft(60, true);
		pGrid->SetTop(20, true);
		pGrid->SetBottom(20, true);

		Axis::IAxis* pXAxis = m_pChart->GetGeneralOptions()->GetXAxis();
		Axis::IAxis* pYAxis = m_pChart->GetGeneralOptions()->GetYAxis();
		pYAxis->SetData(L"heart, large-intestine, small-intestine, spleen, kidney, lung, liver");
		
		vector<int> vctData = { 121, 321, 141, 52, 198, 289, 139 };
		/* 设置显示的系列  */
		Bar::IBarType* pBarType = m_pChart->GetGeneralOptions()->GetSeries()->CreateBarType(); // 显示为Bar;
		pBarType->GetEmphasis()->SetFocus(EF_Self);
		pBarType->SetData(vctData); // 设置系列数据（当前只有一个维度的数据）;


		/* 增加创建的 BarType; (4. 必须) */
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pBarType);

		/* 使配置生效; (5. 必须)*/
		m_pChart->SetOption();

		bResult = TRUE;
	} while (0);


	return bResult;
}

BOOL CMapTypeCase::CreateMap()
{
	int nError = 0;

	wstring wsMapFile = GetCurrentPath() + L"TestData\\geo\\USA.json";
	wstring wsSpecialAreas = L"{\"Alaska\": {\"left\":-131,\"top\":25,\"width\":15},";
	wsSpecialAreas += L"\"Hawaii\": {\"left\":-110, \"top\":28, \"width\":5},";
	wsSpecialAreas += L"\"Puerto Rico\": {\"left\":-76,\"top\":26,\"width\":2}}";

	do
	{
		/* 为了方便查看 Chart 的整个编辑过程，此处把之前的实例删除掉; */
		if (nullptr != m_pChart)
		{
			m_pChart->Release();
			m_pChart = nullptr;
		}

		/* 创建 Chart 实例(1.必须) */
		if (nullptr == m_pChart)
		{
			nError = m_pManager->RegisterGeoMapFromFile(L"USA", wsMapFile.c_str(), wsSpecialAreas.c_str());
			if (0 != nError)
			{
				m_pDlg->OutputError(L"加载 USA 地图失败", nError);
				break;
			}

			m_pChart = m_pManager->CreateChart(nError, nullptr);
			if (0 != nError)
			{
				m_pDlg->OutputError(L"创建 Chart 失败", nError);
				break;
			}
			m_pChart->Init();
			m_pChart->SetEventDelegate(m_pDelegate); // 设置接收响应事件的代理;
			m_pChart->On(Evt_click, L"series");      // 注册一个点击事件;
		}

		/* Visual Map */
		VisualMap::IVisualMapPiecewise* pPiecewise = m_pChart->GetGeneralOptions()->GetVisualMap()->CreatePiecewiseType();
		pPiecewise->AddPieceMin(1500);
		pPiecewise->AddPiece(900, 1500, L"[900, 1500]", L"rgb(200,100,0)");
		pPiecewise->AddPiece(310, 1000, L"[310, 1000]", L"rgb(200,50,0)");
		pPiecewise->AddPiece(200, 300, L"[200, 300]", L"rgb(100,200,0)");
		pPiecewise->AddPiece(10, 200, L"[10, 200]", L"rgb(50,150,100)");
		pPiecewise->GetOutOfRange()->SetColor(L"#eee");

		ResetChartForTestAddPiece(pPiecewise);
		pPiecewise->Release();

	} while (0);


	return TRUE;
}

BOOL CMapTypeCase::CreateTrafficMap()
{
	return TRUE;
}


void CMapTypeCase::ResetChartForTestAddPiece(VisualMap::IVisualMapPiecewise* pPiecewise)
{
	//m_pChart->Clear();

	// VisualMap
	m_pChart->GetGeneralOptions()->GetVisualMap()->Clear();
	m_pChart->GetGeneralOptions()->GetVisualMap()->Add(pPiecewise);

	/* 配置图表; */
	m_pChart->GetGeneralOptions()->GetTitle()->SetText(L"Map Type 测试"); // 设置标题
	m_pChart->GetGeneralOptions()->GetTitle()->SetSubText(L"Fake Data");
	m_pChart->GetGeneralOptions()->GetTitle()->SetLeft(ELeftValue::ELV_Center);
	m_pChart->GetGeneralOptions()->GetTitle()->SetTop(ETopValue::ETV_Top);

	m_pChart->GetGeneralOptions()->GetTooltip()->SetTrigger(ETrigger::ETT_Item);

	//m_pChart->GetGeneralOptions()->GetGrid()->SetContainLabel(true);
	//m_pChart->GetGeneralOptions()->GetGrid()->SetBackgroundColor(L"LightBlue");
	m_pChart->GetGeneralOptions()->GetGeo()->SetMap(L"USA");

	m_pChart->GetGeneralOptions()->SetAnimation(true);
	m_pChart->GetGeneralOptions()->SetAnimationEasing(EAnimationEasing::EAE_CircularIn);
	m_pChart->GetGeneralOptions()->SetAnimationDuration(2000);

	/* 设置显示的系列  */
	Map::IMapType* pType1 = m_pChart->GetGeneralOptions()->GetSeries()->CreateMapType(); // 显示为Line;
	pType1->SetName(L"Order");
	pType1->SetId(L"TestType01");
	pType1->SetMap(L"USA");
	pType1->GetLabel()->SetShow(true);
	pType1->GetLabel()->SetColor(L"inherit");
	pType1->SetLabelLayoutJSFun(L"fun(params){return {hideOverlag:true, fontSize: Math.max(params.rect.width / 10, 8)}}");
	pType1->AddData(L"Alabama", G_GetRandomData(10, 1500));
	pType1->AddData(L"Alaska", G_GetRandomData(10, 1500));
	pType1->AddData(L"Arizona", G_GetRandomData(10, 1500));
	pType1->AddData(L"Arkansas", G_GetRandomData(10, 1500));
	pType1->AddData(L"California", G_GetRandomData(10, 1500));
	pType1->AddData(L"Colorado", G_GetRandomData(10, 1500));
	pType1->AddData(L"Connecticut", G_GetRandomData(10, 1500));
	pType1->AddData(L"Delaware", G_GetRandomData(10, 1500));
	pType1->AddData(L"District of Columbia", G_GetRandomData(10, 1500));
	pType1->AddData(L"Florida", G_GetRandomData(10, 1500));
	pType1->AddData(L"Georgia", G_GetRandomData(10, 1500));
	pType1->AddData(L"Hawaii", G_GetRandomData(10, 1500));
	pType1->AddData(L"Idaho", G_GetRandomData(10, 1500));
	pType1->AddData(L"Illinois", G_GetRandomData(10, 1500));
	pType1->AddData(L"Indiana", G_GetRandomData(10, 1500));
	pType1->AddData(L"Iowa", G_GetRandomData(10, 1500));
	pType1->AddData(L"Kansas", G_GetRandomData(10, 1500));
	pType1->AddData(L"Kentucky", G_GetRandomData(10, 1500));
	pType1->AddData(L"Louisiana", G_GetRandomData(10, 1500));
	pType1->AddData(L"Maine", G_GetRandomData(10, 1500));
	pType1->AddData(L"Maryland", G_GetRandomData(10, 1500));
	pType1->AddData(L"Massachusetts", G_GetRandomData(10, 1500));
	pType1->AddData(L"Michigan", G_GetRandomData(10, 1500));
	pType1->AddData(L"Minnesota", G_GetRandomData(10, 1500));
	pType1->AddData(L"Mississippi", G_GetRandomData(10, 1500));
	pType1->AddData(L"Missouri", G_GetRandomData(10, 1500));
	pType1->AddData(L"Montana", G_GetRandomData(10, 1500));
	pType1->AddData(L"Nebraska", G_GetRandomData(10, 1500));
	pType1->AddData(L"Nevada", G_GetRandomData(10, 1500));
	pType1->AddData(L"New Hampshire", G_GetRandomData(10, 1500));
	pType1->AddData(L"New Jersey", G_GetRandomData(10, 1500));
	pType1->AddData(L"New Mexico", G_GetRandomData(10, 1500));
	pType1->AddData(L"New York", G_GetRandomData(10, 1500));
	pType1->AddData(L"North Carolina", G_GetRandomData(10, 1500));
	pType1->AddData(L"North Dakota", G_GetRandomData(10, 1500));
	pType1->AddData(L"Ohio", G_GetRandomData(10, 1500));
	pType1->AddData(L"Oklahoma", G_GetRandomData(10, 1500));
	pType1->AddData(L"Oregon", G_GetRandomData(10, 1500));
	pType1->AddData(L"Pennsylvania", G_GetRandomData(10, 1500));
	pType1->AddData(L"Rhode Island", G_GetRandomData(10, 1500));
	pType1->AddData(L"South Carolina", G_GetRandomData(10, 1500));
	pType1->AddData(L"South Dakota", G_GetRandomData(10, 1500));
	pType1->AddData(L"Tennessee", G_GetRandomData(10, 1500));
	pType1->AddData(L"Texas", G_GetRandomData(10, 1500));
	pType1->AddData(L"Utah", G_GetRandomData(10, 1500));
	pType1->AddData(L"Vermont", G_GetRandomData(10, 1500));
	pType1->AddData(L"Virginia", G_GetRandomData(10, 1500));
	pType1->AddData(L"Washington", G_GetRandomData(10, 1500));
	pType1->AddData(L"West Virginia", G_GetRandomData(10, 1500));
	pType1->AddData(L"Wisconsin", G_GetRandomData(10, 1500));
	pType1->AddData(L"Wyoming", G_GetRandomData(10, 1500));
	pType1->AddData(L"Puerto Rico", G_GetRandomData(10, 1500));

	m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pType1);
	pType1->Release();

	m_pChart->GetGeneralOptions()->SetBackgroundColor(L"rgb(200,200,200)");
	/* 使配置生效;*/
	m_pChart->SetOption();
}