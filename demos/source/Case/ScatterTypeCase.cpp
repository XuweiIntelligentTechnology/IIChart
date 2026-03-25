#include "pch.h"
#include "IIChartDemoDlg.h"
#include "ScatterTypeCase.h"

CScatterTypeCase::CScatterTypeCase(IIChart::IChartManager* pManager, CIIChartDemoDlg* pDlg, IChartEventDelegate* pDelegate)
     : m_pManager(pManager)
	 , m_pDlg(pDlg)
	 , m_pDelegate(pDelegate)
{
	m_vctFunction.push_back(L"<1>基础散点图");	
	//m_vctFunction.push_back(L"<2>数据聚合");
	//m_vctFunction.push_back(L"<3>GitHub打卡气泡图");
	//m_vctFunction.push_back(L"<4>模拟更新数据");
}

CScatterTypeCase::~CScatterTypeCase()
{
}

vector<wstring> CScatterTypeCase::GetFunctionList()
{
	return m_vctFunction;
}

int CScatterTypeCase::RunFunction(const wstring& wsItemName)
{
	int nResult = 1;

	do
	{
		m_pDlg->OutputLine(L"RunFunction:[%s]", wsItemName.c_str());
		if (0 == wsItemName.compare(L"<1>基础散点图"))
		{
			if (FALSE == CreateBasicScatter()) break;
		}
		else if (0 == wsItemName.compare(L"<2>数据聚合"))
		{
			if (FALSE == CreateClusteringProcess()) break;
		}
		else if (0 == wsItemName.compare(L"<3>GitHub打卡气泡图"))
		{
			if (FALSE == CreatePunchCardofGithub()) break;
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

void CScatterTypeCase::ClearChart()
{
	if (nullptr != m_pChart)
	{
		m_pChart->Release();
		m_pChart = nullptr;
	}
}

void CScatterTypeCase::Release()
{
	delete this;
}

BOOL CScatterTypeCase::UpdateData()
{
	if (nullptr == m_pChart)
	{
		m_pDlg->OutputError(L"未创建 Chart");
		return FALSE;
	}

	return TRUE;
}

BOOL CScatterTypeCase::CreateBasicScatter()
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
		m_pChart->GetGeneralOptions()->GetXAxis(); // 设置平面坐标轴：X 为类目(2. 必须)
		m_pChart->GetGeneralOptions()->GetYAxis(); // 设置平面坐标轴：Y 为 值(2. 必须);

		/* 设置显示的系列  */
		Scatter::IScatterType* pScatterType = m_pChart->GetGeneralOptions()->GetSeries()->CreateScatterType(); // 显示为Scatter;
		pScatterType->SetSymbolSize(20);

		pScatterType->SetDataWithJson(_T("[[10.0, 8.04],[8.07, 6.95],[13.0, 7.58],[9.05, 8.81],[11.0, 8.33],[14.0, 7.66],[13.4, 6.81],[10.0, 6.33],[14.0, 8.96],[12.5, 6.82],[9.15, 7.2],[11.5, 7.2],[3.03, 4.23],[12.2, 7.83],[2.02, 4.47],[1.05, 3.33],[4.05, 4.96],[6.03, 7.24],[12.0, 6.26],[12.0, 8.84],[7.08, 5.82],[5.02, 5.68]]"));


		/* 增加创建的 BarType; (4. 必须) */
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pScatterType);

		/* 使配置生效; (5. 必须)*/
		m_pChart->SetOption();

		bResult = TRUE;
	} while (0);


	return bResult;
}

BOOL CScatterTypeCase::CreateClusteringProcess()
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
		
		

		/* 设置显示的系列  */
		Scatter::IScatterType* pScatterType = m_pChart->GetGeneralOptions()->GetSeries()->CreateScatterType(); // 显示为Scatter;

		wstring strData = _T("[[3.275154, 2.957587],[-3.344465, 2.603513],[0.355083, -3.376585],[1.852435, 3.547351],[-2.078973, 2.552013],[-0.993756, -0.884433],[2.682252, 4.007573],\
			[-3.087776, 2.878713], [-1.565978, -1.256985], [2.441611, 0.444826], [-0.659487, 3.111284], [-0.459601, -2.618005], [2.17768, 2.387793], [-2.920969, 2.917485],\
			[-0.028814, -4.168078],[3.625746, 2.119041],[-3.912363, 1.325108],[-0.551694, -2.814223],[2.855808, 3.483301],[-3.594448, 2.856651],[0.421993, -2.372646],\
			[1.650821, 3.407572],[-2.082902, 3.384412],[-0.718809, -2.492514],[4.513623, 3.841029],[-4.822011, 4.607049],[-0.656297, -1.449872],[1.919901, 4.439368],\
			[-3.287749, 3.918836],[-1.576936, -2.977622],[3.598143, 1.97597],[-3.977329, 4.900932],[-1.79108, -2.184517],[3.914654, 3.559303],[-1.910108, 4.166946],\
			[-1.226597, -3.317889],[1.148946, 3.345138],[-2.113864, 3.548172],[0.845762, -3.589788],[2.629062, 3.535831],[-1.640717, 2.990517],[-1.881012, -2.485405],\
			[4.606999, 3.510312],[-4.366462, 4.023316],[0.765015, -3.00127],[3.121904, 2.173988],[-4.025139, 4.65231],[-0.559558, -3.840539],[4.376754, 4.863579],\
			[-1.874308, 4.032237],[-0.089337, -3.026809],[3.997787, 2.518662],[-3.082978, 2.884822],[0.845235, -3.454465],[1.327224, 3.358778],[-2.889949, 3.596178],\
			[-0.966018, -2.839827],[2.960769, 3.079555],[-3.275518, 1.577068],[0.639276, -3.41284]]");

		Dataset::IDataset* pDataset = m_pChart->GetGeneralOptions()->CreateDataset();
		pDataset->SetId(L"DataSource");
		pDataset->SetSourceHeader(ESourceHeader::ESH_Data);

		Dataset::IDatasetTransformConfig* pConfig = pDataset->CreateTransformConfig();
		Dataset::IDatasetTransformConfigItem* pItem = pConfig->CreateItem();

		pConfig->AddAndItem(pItem);
		pItem->Reset();

		pDataset->AddTransform(ETransformType::ETT_Cluster, true, pConfig);
		pConfig->Reset();

		m_pChart->GetGeneralOptions()->Add(pDataset);
		pDataset->Reset();

		VisualMap::IVisualMapPiecewise* pPiecewise = m_pChart->GetGeneralOptions()->GetVisualMap()->CreatePiecewiseType();
		pPiecewise->SetTop(ETV_Middle);
		pPiecewise->AddPieceMin(0);
		pPiecewise->AddPieceMax(6);
		pPiecewise->SetLeft(10);
		pPiecewise->SetSplitNumber(6);
		pPiecewise->SetDimension(2);
		pPiecewise->AddPiece(0, L"cluster0", L"#37A2DA");
		pPiecewise->AddPiece(1, L"cluster1", L"#e06343");
		pPiecewise->AddPiece(2, L"cluster2", L"#37a354");
		pPiecewise->AddPiece(3, L"cluster3", L"#b55dba");
		pPiecewise->AddPiece(4, L"cluster4", L"#b5bd48");
		pPiecewise->AddPiece(5, L"cluster5", L"#8378EA");
		m_pChart->GetGeneralOptions()->GetVisualMap()->Add(pPiecewise);


		/* 增加创建的 BarType; (4. 必须) */
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pScatterType);

		/* 使配置生效; (5. 必须)*/
		m_pChart->SetOption();

		bResult = TRUE;
	} while (0);


	return bResult;
}

BOOL CScatterTypeCase::CreatePunchCardofGithub()
{
	return TRUE;
}

