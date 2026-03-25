#include "pch.h"
#include "IIChartDemoDlg.h"
#include "SunburstTypeCase.h"

CSunburstTypeCase::CSunburstTypeCase(IIChart::IChartManager* pManager, CIIChartDemoDlg* pDlg, IChartEventDelegate* pDelegate)
     : m_pManager(pManager)
	 , m_pDlg(pDlg)
	 , m_pDelegate(pDelegate)
{
	m_vctFunction.push_back(L"<1>基础旭日图");
	m_vctFunction.push_back(L"<2>饮料风味示例");
	//m_vctFunction.push_back(L"<3>旭日图使用视觉编码");
	//m_vctFunction.push_back(L"<4>模拟更新数据");
}

CSunburstTypeCase::~CSunburstTypeCase()
{
}

vector<wstring> CSunburstTypeCase::GetFunctionList()
{
	return m_vctFunction;
}

int CSunburstTypeCase::RunFunction(const wstring& wsItemName)
{
	int nResult = 1;

	do
	{
		m_pDlg->OutputLine(L"RunFunction:[%s]", wsItemName.c_str());
		if (0 == wsItemName.compare(L"<1>基础旭日图"))
		{
			CreateSunburstTypeChart();
		}	
		else if (0 == wsItemName.compare(L"<2>饮料风味示例"))
		{
			CreateDrinkFlavors();
		}
		else if (0 == wsItemName.compare(L"<3>旭日图使用视觉编码"))
		{
			
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

void CSunburstTypeCase::ClearChart()
{
	if (nullptr != m_pChart)
	{
		m_pChart->Release();
		m_pChart = nullptr;
	}
}

void CSunburstTypeCase::Release()
{
	delete this;
}

BOOL CSunburstTypeCase::UpdateData()
{
	if (nullptr == m_pChart)
	{
		m_pDlg->OutputError(L"未创建 Chart");
		return FALSE;
	}

	return TRUE;
}


BOOL CSunburstTypeCase::CreateSunburstTypeChart()
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
		m_pChart->GetGeneralOptions()->GetTitle()->SetText(L"基础旭日图"); // [可选项]设置标题

		/* 设置显示的系列  */
		Sunburst::ISunburstType* pType = m_pChart->GetGeneralOptions()->GetSeries()->CreateSunburstType();
		pType->SetId(L"LINE-001");
		pType->SetRadius(0, 90, true);
		pType->GetLabel()->SetRotate(ERotate::ER_Radial);

		Sunburst::ISunburstTypeData* root1 = pType->CreateData();
		Sunburst::ISunburstTypeData* root2 = pType->CreateData();
		Sunburst::ISunburstTypeData* child = pType->CreateData();
		Sunburst::ISunburstTypeData* childTemp = pType->CreateData();

		childTemp->SetName(L"Cousin Mary");
		childTemp->SetValue(5);
		childTemp->AddChildren(L"Jackson", 2);

		child->SetName(L"Uncle Leo");
		child->SetValue(15);
		child->AddChildren(L"Cousin Jack", 2);
		child->AddChildren(childTemp), childTemp->Reset();
		child->AddChildren(L"Cousin Ben", 4);

		root1->SetName(L"Grandpa");
		root1->AddChildren(child); child->Reset();

		child->SetName(L"Father");
		child->SetValue(10);
		child->AddChildren(L"Me", 5);
		child->AddChildren(L"Brother Peter", 1);
		root1->AddChildren(child); child->Reset();

		child->SetName(L"Uncle Nike");
		child->AddChildren(L"Cousin Betty", 1);
		child->AddChildren(L"Cousin Jenny", 2);
		root2->SetName(L"Nacy");
		root2->AddChildren(child), child->Reset();
		
		pType->AddData(root1);
		pType->AddData(root2);

		root1->Release();
		root2->Release();
		child->Release();
		childTemp->Release();

		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pType);

		m_pChart->SetOption();

		bResult = TRUE;
	} while (0);


	return bResult;
}


BOOL CSunburstTypeCase::CreateDrinkFlavors()
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

		/* 配置图表标题; */
		m_pChart->GetGeneralOptions()->GetTitle()->SetText(L"世界咖啡研究感官词典");
		m_pChart->GetGeneralOptions()->GetTitle()->SetSubText(L"Source: https://worldcoffeeresearch.org/work/sensory-lexicon/");
		m_pChart->GetGeneralOptions()->GetTitle()->GetTextStyle()->SetFontSize(14);
		m_pChart->GetGeneralOptions()->GetTitle()->SetSubLink(L"https://worldcoffeeresearch.org/work/sensory-lexicon/");


		/* 设置显示的系列  */
		Sunburst::ISunburstType* pType = m_pChart->GetGeneralOptions()->GetSeries()->CreateSunburstType();
		pType->SetId(L"LINE-001");
		pType->SetRadius(0, 95, true);
		pType->GetEmphasis()->SetFocus(ESunburstFocus::ESF_Ancestor);

		Sunburst::ISunburstTypeLevel* level = pType->CreateLevel();

		// 增加一个空的 level
		
		pType->AddLevel(level), level->Reset();

		// 第一层 level
		level->GetBlur();
		level->GetSelect();
		level->SetRadius(15, 35, true);
		level->GetItemStyle()->SetBorderWidth(2);
		level->GetLabel()->SetRotate(ERotate::ER_Tangential);
		pType->AddLevel(level), level->Reset();

		// 第二层 level
		level->SetRadius(35, 70, true);
		level->GetLabel()->SetAlign(EAlign::EA_Right);
		pType->AddLevel(level), level->Reset();

		// 第三层 level
		level->SetRadius(70, 72, true);
		level->GetItemStyle()->SetBorderWidth(2);
		level->GetLabel()->SetPosition(L"outside");
		level->GetLabel()->SetPadding(3);
		level->GetItemStyle()->SetBorderWidth(3);
		pType->AddLevel(level), level->Reset();
		level->Release();

		RetrieveDrinkFlavorsData(pType);
		
		m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(pType);

		m_pChart->SetOption();

		bResult = TRUE;
	} while (0);


	return bResult;
}

void CSunburstTypeCase::RetrieveDrinkFlavorsData(Sunburst::ISunburstType*& pType)
{
	Sunburst::ISunburstTypeData* child = pType->CreateData();
	Sunburst::ISunburstTypeData* childTemp = pType->CreateData();

	// Flora
	child->SetName(L"Flora");
	child->GetItemStyle()->SetColor(L"#da0d68");
	child->AddChildren(L"Black Tea", 1, L"#975e6d");

	// Flora -> Floral
	childTemp->SetName(L"Floral");
	childTemp->GetItemStyle()->SetColor(L"#e0719c");
	childTemp->AddChildren(L"Chamomile", 1, L"#f99e1c");
	childTemp->AddChildren(L"Rose", 1, L"#ef5a78");
	childTemp->AddChildren(L"Jasmine", 1, L"#f7f1bd");
	child->AddChildren(childTemp), childTemp->Reset();
	pType->AddData(child), child->Reset();

	// Fruity
	child->SetName(L"Fruity");
	child->GetItemStyle()->SetColor(L"#da1d23");

	// Fruity -> Berry
	childTemp->SetName(L"Berry");
	childTemp->GetItemStyle()->SetColor(L"#dd4c51");
	childTemp->AddChildren(L"Blackberry", 1, L"#3e0317");
	childTemp->AddChildren(L"Raspberry", 1, L"#e62969");
	childTemp->AddChildren(L"Blueberry", 1, L"#6569b0");
	childTemp->AddChildren(L"Strawberry", 1, L"#ef2d36");
	child->AddChildren(childTemp), childTemp->Reset();

	// Fruity -> Dried Fruit
	childTemp->SetName(L"Dried Fruit");
	childTemp->GetItemStyle()->SetColor(L"#c94a44");
	childTemp->AddChildren(L"Raisin", 1, L"#b53b54");
	childTemp->AddChildren(L"Prune", 1, L"#a5446f");
	child->AddChildren(childTemp), childTemp->Reset();

	// Fruity -> Other Fruit
	childTemp->SetName(L"Other Fruit");
	childTemp->GetItemStyle()->SetColor(L"#dd4c51");
	childTemp->AddChildren(L"Coconut", 1, L"#f2684b");
	childTemp->AddChildren(L"Cherry", 1, L"#e73451");
	childTemp->AddChildren(L"Pomegranate", 1, L"#e65656");
	childTemp->AddChildren(L"Pineapple", 1, L"#f89a1c");
	childTemp->AddChildren(L"Grape", 1, L"#aeb92c");
	childTemp->AddChildren(L"Apple", 1, L"#4eb849");
	childTemp->AddChildren(L"Peach", 1, L"#f68a5c");
	childTemp->AddChildren(L"Pear", 1, L"#baa635");
	child->AddChildren(childTemp), childTemp->Reset();

	// Fruity -> Citrus Fruit
	childTemp->SetName(L"Citrus Fruitt");
	childTemp->GetItemStyle()->SetColor(L"#f7a128");
	childTemp->AddChildren(L"Grapefruit", 1, L"#f26355");
	childTemp->AddChildren(L"Orange", 1, L"#e2631e");
	childTemp->AddChildren(L"Lemon", 1, L"#fde404");
	childTemp->AddChildren(L"Lime", 1, L"#7eb138");
	child->AddChildren(childTemp), childTemp->Reset();	
	pType->AddData(child), child->Reset();

	// Sour/Fermented
	child->SetName(L"Sour/\nFermented");
	child->GetItemStyle()->SetColor(L"#ebb40f");

	// Sour/Fermented -> Sour
	childTemp->SetName(L"Sour");
	childTemp->GetItemStyle()->SetColor(L"#e1c315");
	childTemp->AddChildren(L"Sour Aromatics", 1, L"#9ea718");
	childTemp->AddChildren(L"Acetic Acid", 1, L"#94a76f");
	childTemp->AddChildren(L"Butyric Acid", 1, L"#d0b24f");
	childTemp->AddChildren(L"Isovaleric Acid", 1, L"#8eb646");
	childTemp->AddChildren(L"Citric Acid", 1, L"#faef07");
	childTemp->AddChildren(L"Malic Acid", 1, L"#c1ba07");
	child->AddChildren(childTemp), childTemp->Reset();

	// Sour/Fermented -> Alcohol/\nFremented
	childTemp->SetName(L"Alcohol/\nFremented");
	childTemp->GetItemStyle()->SetColor(L"#b09733");
	childTemp->AddChildren(L"Winey", 1, L"#8f1c53");
	childTemp->AddChildren(L"Whiskey", 1, L"#b34039");
	childTemp->AddChildren(L"Frementedd", 1, L"#ba9232");
	childTemp->AddChildren(L"Overripe", 1, L"#8b6439");
	child->AddChildren(childTemp), childTemp->Reset();
	pType->AddData(child), child->Reset();

	// Green/Vegetative
	child->SetName(L"Green/\nVegetative");
	child->GetItemStyle()->SetColor(L"#187a2f");
	childTemp->AddChildren(L"Olive Oil", 1, L"#a2b029");
	childTemp->AddChildren(L"Raw", 1, L"#718933");

	// Green/Vegetative -> Green/Vegetative
	childTemp->SetName(L"Green/\nVegetative");
	childTemp->GetItemStyle()->SetColor(L"#3aa255");
	childTemp->AddChildren(L"Under-ripe", 1, L"#a2bb2b");
	childTemp->AddChildren(L"Peapod", 1, L"#62aa3c");
	childTemp->AddChildren(L"Fresh", 1, L"#03a653");
	childTemp->AddChildren(L"Dark Green", 1, L"#038549");
	childTemp->AddChildren(L"Vegetative", 1, L"#28b44b");
	childTemp->AddChildren(L"Hay-like", 1, L"#a3a830");
	childTemp->AddChildren(L"Herb-like", 1, L"#7ac141");
	child->AddChildren(childTemp), childTemp->Reset();
	child->AddChildren(L"Beany", 1, L"#5e9a80");
	
	pType->AddData(child), child->Reset();

	childTemp->Release();
	child->Release();
	
}