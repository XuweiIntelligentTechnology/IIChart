#include "pch.h"
#include "IIChartDemoDlg.h"
#include "DatasetTypeCase.h"

CDatasetTypeCase::CDatasetTypeCase(IIChart::IChartManager* pManager, CIIChartDemoDlg* pDlg, IChartEventDelegate* pDelegate)
     : m_pManager(pManager)
	 , m_pDlg(pDlg)
	 , m_pDelegate(pDelegate)
{
	m_vctFunction.push_back(L"<1>分割数据到数个饼图");
	//m_vctFunction.push_back(L"<2>指定数据到坐标轴的映射");	
	//m_vctFunction.push_back(L"<3>默认encode设置");
	//m_vctFunction.push_back(L"<4>指定数据到坐标轴的映射");
	//m_vctFunction.push_back(L"<5>联动和共享数据集");
	//m_vctFunction.push_back(L"<6>最简单的数据集");
	//m_vctFunction.push_back(L"<7>模拟更新数据");
}

CDatasetTypeCase::~CDatasetTypeCase()
{
}

vector<wstring> CDatasetTypeCase::GetFunctionList()
{
	return m_vctFunction;
}

int CDatasetTypeCase::RunFunction(const wstring& wsItemName)
{
	int nResult = 1;

	do
	{

		m_pDlg->OutputLine(L"RunFunction:[%s]", wsItemName.c_str());
		if (0 == wsItemName.compare(L"<1>分割数据到数个饼图"))
		{
			SplittingDataIntoMultiplePieCharts();
		}	
		else if (0 == wsItemName.compare(L"<2>指定数据到坐标轴的映射"))
		{
			
		}
		else if (0 == wsItemName.compare(L"<3>默认encode设置"))
		{
		}
		else if (0 == wsItemName.compare(L"<4>指定数据到坐标轴的映射"))
		{
		}
		else if (0 == wsItemName.compare(L"<5>联动和共享数据集"))
		{
		}
		else if (0 == wsItemName.compare(L"<6>最简单的数据集"))
		{
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

void CDatasetTypeCase::ClearChart()
{
	if (nullptr != m_pChart)
	{
		m_pChart->Release();
		m_pChart = nullptr;
	}
}

void CDatasetTypeCase::Release()
{
	delete this;
}

BOOL CDatasetTypeCase::UpdateData()
{
	if (nullptr == m_pChart)
	{
		m_pDlg->OutputError(L"未创建 Chart");
		return FALSE;
	}

	return TRUE;
}


BOOL CDatasetTypeCase::SplittingDataIntoMultiplePieCharts()
{
	int nError = 0;

	do
	{
		/* 为了方便查看 Chart 的整个编辑过程，此处把之前的实例删除掉; */
		if (nullptr != m_pChart)
		{
			m_pChart->Release();
			m_pChart = nullptr;
		}

		wstring wsTheme = GetCurrentPath() + L"EChartCode\\theme\\shine.project.json";
		// m_pManager->RegisterThemeFromFile(L"shine", L"D:\\当前项目\\IIChart\\Coding\\IIChartCode\\Debug\\EChartCode\\theme\\shine.project.json");

		m_pChart = m_pManager->CreateChart(nError, L"DatasetSourceChart");
		if (0 != nError)
		{
			m_pDlg->OutputError(L"创建 Chart 失败", nError);
			break;
		}

		m_pChart->GetSetting()->SetTheme(L"shine");
		m_pChart->Init();
		m_pChart->SetEventDelegate(m_pDelegate); // 设置接收响应事件的代理;
		m_pChart->On(Evt_click, L"series");      // 注册一个点击事件;

		
		/* 配置图表; */
		m_pChart->GetGeneralOptions()->GetTitle()->SetText(L"Dataset 测试"); // 设置标题
		m_pChart->GetGeneralOptions()->GetTitle()->SetLeft(ELeftValue::ELV_Center);
		m_pChart->GetGeneralOptions()->GetTitle()->SetTop(ETopValue::ETV_Bottom);
		m_pChart->GetGeneralOptions()->GetLegend();
		m_pChart->GetGeneralOptions()->GetTooltip();

		//m_pChart->GetGeneralOptions()->GetGrid()->SetBackgroundColor(L"SlateGray");
		m_pChart->GetGeneralOptions()->GetGrid()->SetTop(40, true);

		m_pChart->GetGeneralOptions()->GetXAxis()->SetGridIndex(0);
		m_pChart->GetGeneralOptions()->GetXAxis()->SetType(ERCTAxisType::E_Category);
		m_pChart->GetGeneralOptions()->GetYAxis()->SetGridIndex(0);
		//m_pChart->GetGeneralOptions()->GetYAxis()->SetType(ERCTAxisType::E_Value);

		m_pChart->GetGeneralOptions()->SetAnimation(true);
		m_pChart->GetGeneralOptions()->SetAnimationEasing(EAnimationEasing::EAE_CircularIn);
		m_pChart->GetGeneralOptions()->SetAnimationDuration(2000);

		/* 配置 Dataset; */
		Dataset::IDataset* pDataset = m_pChart->GetGeneralOptions()->CreateDataset();
		pDataset->SetId(L"DataSource");
		pDataset->GetSource()->AddRow(L"Product, Sales, Price, Year");
		pDataset->GetSource()->AddRow(L"Cake,123,32,2011");
		pDataset->GetSource()->AddRow(L"Cereal,231,14,2011");
		pDataset->GetSource()->AddRow(L"Tofu,235,5,2011");
		pDataset->GetSource()->AddRow(L"Dumpling,341,25, 2011");
		pDataset->GetSource()->AddRow(L"Biscuit, 122, 29, 2011");
		pDataset->GetSource()->AddRow(L"Cake, 143, 30, 2012");
		pDataset->GetSource()->AddRow(L"Cereal, 201, 19, 2012");
		pDataset->GetSource()->AddRow(L"Tofu, 255, 7, 2012");
		pDataset->GetSource()->AddRow(L"Dumpling, 241, 27, 2012");
		pDataset->GetSource()->AddRow(L"Biscuit, 102, 34, 2012");
		pDataset->GetSource()->AddRow(L"Cake, 153, 28, 2013");
		pDataset->GetSource()->AddRow(L"Cereal, 181, 21, 2013");
		pDataset->GetSource()->AddRow(L"Tofu, 395, 4, 2013");
		pDataset->GetSource()->AddRow(L"Dumpling, 281, 31, 2013");
		pDataset->GetSource()->AddRow(L"Biscuit, 92, 39, 2013");
		pDataset->GetSource()->AddRow(L"Cake, 223, 29, 2014");
		pDataset->GetSource()->AddRow(L"Cereal, 211, 17, 2014");
		pDataset->GetSource()->AddRow(L"Tofu, 345, 3, 2014");
		pDataset->GetSource()->AddRow(L"Dumpling, 211, 35, 2014");
		pDataset->GetSource()->AddRow(L"Biscuit, 72, 24, 2014");
		m_pChart->GetGeneralOptions()->Add(pDataset);

		Dataset::IDataset* pDataset1 = m_pChart->GetGeneralOptions()->CreateDataset();
		pDataset1->AddTransform(ETransformType::ETT_Filter, false, L"{\"dimension\": \"Year\", \"value\": 2011 }");
		m_pChart->GetGeneralOptions()->Add(pDataset1);
		pDataset1->Release();

		Dataset::IDataset* pDataset2 = m_pChart->GetGeneralOptions()->CreateDataset();
		pDataset2->AddTransform(ETransformType::ETT_Filter, false, L"{\"dimension\": \"Year\", \"value\": 2012 }");
		m_pChart->GetGeneralOptions()->Add(pDataset2);
		pDataset2->Release();

		Dataset::IDataset* pDataset3 = m_pChart->GetGeneralOptions()->CreateDataset();
		pDataset3->AddTransform(ETransformType::ETT_Filter, false, L"{\"dimension\": \"Year\", \"value\": 2013 }");
		m_pChart->GetGeneralOptions()->Add(pDataset3);
		pDataset3->Release();

		Dataset::IDataset* pDataset4 = m_pChart->GetGeneralOptions()->CreateDataset();
		pDataset4->AddTransform(ETransformType::ETT_Filter, false, L"{\"dimension\": \"Product\", \"value\": \"Cake\" }");
		m_pChart->GetGeneralOptions()->Add(pDataset4);
		pDataset4->Release();

		Dataset::IDataset* pDataset5 = m_pChart->GetGeneralOptions()->CreateDataset();
		pDataset5->AddTransform(ETransformType::ETT_Filter, false, L"{\"dimension\": \"Product\", \"value\": \"Cereal\" }");
		m_pChart->GetGeneralOptions()->Add(pDataset5);
		pDataset5->Release();

		Dataset::IDataset* pDataset6 = m_pChart->GetGeneralOptions()->CreateDataset();
		pDataset6->AddTransform(ETransformType::ETT_Filter, false, L"{\"dimension\": \"Product\", \"value\": \"Tofu\" }");
		m_pChart->GetGeneralOptions()->Add(pDataset6);
		pDataset6->Release();

		Dataset::IDataset* pDataset7 = m_pChart->GetGeneralOptions()->CreateDataset();
		pDataset7->AddTransform(ETransformType::ETT_Filter, false, L"{\"dimension\": \"Product\", \"value\": \"Dumpling\" }");
		m_pChart->GetGeneralOptions()->Add(pDataset7);
		pDataset7->Release();

		Dataset::IDataset* pDataset8 = m_pChart->GetGeneralOptions()->CreateDataset();
		pDataset8->AddTransform(ETransformType::ETT_Filter, false, L"{\"dimension\": \"Product\", \"value\": \"Biscuit\" }");
		m_pChart->GetGeneralOptions()->Add(pDataset8);
		pDataset8->Release();


		/* 设置显示的系列  */
		Pie::IPieType* pPieType1 = m_pChart->GetGeneralOptions()->GetSeries()->CreatePieType(); // 显示为Line;
		pPieType1->SetRadius(50, false);
		pPieType1->SetCenter(25, 20, true);
		pPieType1->SetDatasetIndex(1);
		pPieType1->GetLabel()->SetShow(true);
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pPieType1);
		pPieType1->Release();

		Pie::IPieType* pPieType2 = m_pChart->GetGeneralOptions()->GetSeries()->CreatePieType(); // 显示为Line;
		pPieType2->SetRadius(50, false);
		pPieType2->SetCenter(50, 20, true);
		pPieType2->SetDatasetIndex(2);
		pPieType2->GetLabel()->SetShow(true);
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pPieType2);
		pPieType2->Release();

		Pie::IPieType* pPieType3 = m_pChart->GetGeneralOptions()->GetSeries()->CreatePieType(); // 显示为Line;
		pPieType3->SetRadius(50, false);
		pPieType3->SetCenter(75, 20, true);
		pPieType3->SetDatasetIndex(2);
		pPieType3->GetLabel()->SetShow(true);
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pPieType3);
		pPieType3->Release();


		Bar::IBarType* pLineType1 = m_pChart->GetGeneralOptions()->GetSeries()->CreateBarType(); // 显示为Line;
		pLineType1->SetXAxisIndex(0);
		pLineType1->SetYAxisIndex(0);
		pLineType1->SetDatasetIndex(4);
		pLineType1->GetEncode()->SetX(L"Year");
		pLineType1->GetEncode()->SetY(L"Sales");
		pLineType1->GetEncode()->SetItemName(L"Product");
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pLineType1);
		pLineType1->Release();

		Bar::IBarType* pLineType2 = m_pChart->GetGeneralOptions()->GetSeries()->CreateBarType(); // 显示为Line;
		pLineType2->SetXAxisIndex(0);
		pLineType2->SetYAxisIndex(0);
		pLineType2->SetDatasetIndex(5);
		pLineType2->GetEncode()->SetX(L"Year");
		pLineType2->GetEncode()->SetY(L"Sales");
		pLineType2->GetEncode()->SetItemName(L"Product");
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pLineType2);
		pLineType2->Release();

		Bar::IBarType* pLineType3 = m_pChart->GetGeneralOptions()->GetSeries()->CreateBarType(); // 显示为Line;
		pLineType3->SetXAxisIndex(0);
		pLineType3->SetYAxisIndex(0);
		pLineType3->SetDatasetIndex(6);
		pLineType3->GetLabel();
		pLineType3->GetEncode()->SetX(L"Year");
		pLineType3->GetEncode()->SetY(L"Sales");
		pLineType3->GetEncode()->SetItemName(L"Product");
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pLineType3);
		pLineType3->Release();

		Bar::IBarType* pLineType4 = m_pChart->GetGeneralOptions()->GetSeries()->CreateBarType(); // 显示为Line;
		pLineType4->SetXAxisIndex(0);
		pLineType4->SetYAxisIndex(0);
		pLineType4->SetDatasetIndex(7);
		pLineType4->GetEncode()->SetX(L"Year");
		pLineType4->GetEncode()->SetY(L"Sales");
		pLineType4->GetEncode()->SetItemName(L"Product");
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pLineType4);
		pLineType4->Release();

		Bar::IBarType* pLineType5 = m_pChart->GetGeneralOptions()->GetSeries()->CreateBarType(); // 显示为Line;
		pLineType5->SetXAxisIndex(0);
		pLineType5->SetYAxisIndex(0);
		pLineType5->SetDatasetIndex(8);
		pLineType5->GetEncode()->SetX(L"Year");
		pLineType5->GetEncode()->SetY(L"Sales");
		pLineType5->GetEncode()->SetItemName(L"Product");
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pLineType5);
		pLineType5->Release();


		/* 使配置生效;*/
		m_pChart->SetOption();

	} while (0);

	return nError;
}