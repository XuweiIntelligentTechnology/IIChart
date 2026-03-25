#include "pch.h"
#include "IIChartDemoDlg.h"
#include "CChartEventDelegate.h"
#include "CChartManagerDelegateImp.h"

#include "LineTypeCase.h"
#include "BarTypeCase.h"
#include "PieTypeCase.h"
#include "ScatterTypeCase.h"
#include "MapTypeCase.h"
#include "RadarTypeCase.h"
#include "SunburstTypeCase.h"
#include "GaugeTypeCase.h"
#include "DatasetTypeCase.h"

#include "CaseService.h"

CCaseService::CCaseService(CIIChartDemoDlg* pDlg, IChartEventDelegate* pChartDelegate, IChartManagerDelegate* pChartManagerDelegate)
	: m_pDlg(pDlg)
	, m_pChartDelegate(pChartDelegate)
	, m_pChartManagerDelegate(pChartManagerDelegate)
{
}

CCaseService::~CCaseService()
{
}

int CCaseService::Init(HWND hView)
{
	int nResult = 0;
	if (nullptr == m_pChartManager)
	{
		nResult = InitIIChart();
		if (0 != nResult)
		{
			m_pDlg->OutputError(L"加载 IIChart.dll 失败:%d", nResult);
			return nResult;
		}

		m_pChartManager->SetDelegate(m_pChartManagerDelegate);

		nResult = m_pChartManager->Init(hView);
		if (0 != nResult)
		{
			m_pDlg->OutputError(L"初始化 IIChart 失败:%d", nResult);
			return nResult;
		}
	}
	else
	{
		return 0;
	}
	
	AddCase(L">地理坐标/地图", new CMapTypeCase(m_pChartManager, m_pDlg, m_pChartDelegate));
	AddCase(L">折线图", new CLineTypeCase(m_pChartManager, m_pDlg, m_pChartDelegate));
	AddCase(L">柱状图", new CBarTypeCase(m_pChartManager, m_pDlg, m_pChartDelegate));
	AddCase(L">饼图", new CPieTypeCase(m_pChartManager, m_pDlg, m_pChartDelegate));
	AddCase(L">散点图 ", new CScatterTypeCase(m_pChartManager, m_pDlg, m_pChartDelegate));
	AddCase(L">雷达图 ", new CRadarTypeCase(m_pChartManager, m_pDlg, m_pChartDelegate));
	AddCase(L">旭日图", new CSunburstTypeCase(m_pChartManager, m_pDlg, m_pChartDelegate));
	AddCase(L">仪表盘", new CGaugeTypeCase(m_pChartManager, m_pDlg, m_pChartDelegate));
	AddCase(L">数据集", new CDatasetTypeCase(m_pChartManager, m_pDlg, m_pChartDelegate));

	return 0;
}

void CCaseService::Uninit()
{
	/*vector<CChartDemoCategory*>::iterator it = m_vctDemoCategory.begin();
	for (; it != m_vctDemoCategory.end(); ++it)
	{
		(*it)->Uninit();
		delete (*it);
	}*/
}

vector<wstring> CCaseService::GetCaseList()
{
	return m_vctCase;
}

vector<wstring> CCaseService::GetFunctionList(const wstring& wsCase)
{
	map<wstring, ICase*>::iterator it = m_mapCase.begin();
	for (; it != m_mapCase.end(); ++it)
	{
		if (0 == it->first.compare(wsCase))
		{
			return it->second->GetFunctionList();
		}
	}

	return vector<wstring>();
}

int CCaseService::RunFunction(const wstring& wsCase, const wstring& wsFunction)
{
	map<wstring, ICase*>::iterator it = m_mapCase.begin();
	for (; it != m_mapCase.end(); ++it)
	{
		if (0 == it->first.compare(wsCase))
		{
			return it->second->RunFunction(wsFunction);
		}
	}

	return 1;
}

int CCaseService::ClearCaseChart(const wstring& wsCase)
{
	map<wstring, ICase*>::iterator it = m_mapCase.begin();
	for (; it != m_mapCase.end(); ++it)
	{
		if (0 == it->first.compare(wsCase))
		{
			it->second->ClearChart();
			return 0;
		}
	}

	return 1;
}

void CCaseService::ClearChart()
{
}


int CCaseService::InitIIChart()
{
	TCHAR  szModlePath[MAX_PATH] = { 0 };
	wstring szDll;


	// 取 DLL 路径;
	if (GetModuleFileName(nullptr, szModlePath, MAX_PATH))
	{
		DWORD dwRst = 0;
		szDll = szModlePath;
		size_t iIndex = szDll.find_last_of(L"\\");

		szDll = szDll.substr(0, iIndex + 1);

#ifdef _DEBUG
		szDll += L"IIChartd.dll";
#else
		szDll += L"IIChart.dll";
#endif

		// 加载 DLL;
		if (TRUE == PathFileExists(szDll.c_str()))
		{
			m_hIIChart = LoadLibrary(szDll.c_str());
			// 加载成功,获取接口;
			pCreateChartManager pfnCreateChartManager = nullptr;
			pfnCreateChartManager = (pCreateChartManager)GetProcAddress(m_hIIChart, "CreateChartManager");

			if (nullptr != pfnCreateChartManager)
			{
				// 创建对象;
				m_pChartManager = pfnCreateChartManager();
			}
			else
			{
				return GetLastError();
			}

			// 加载成功,获取接口;
			pCreateGlobalUtility pfnCreateGlobalUtility = nullptr;
			pfnCreateGlobalUtility = (pCreateGlobalUtility)GetProcAddress(m_hIIChart, "CreateGlobalUtility");

			if (nullptr != pfnCreateGlobalUtility)
			{
				// 创建对象;
				m_pGlobalUtility = pfnCreateGlobalUtility();
			}
			else
			{
				return GetLastError();
			}
		}
		else
		{
			m_pChartManager = nullptr;
		}

		if (nullptr != m_pChartManager && nullptr != m_pGlobalUtility)
		{
			return 0;
		}
	}

	return 1;
}

void CCaseService::UninitIIChart()
{
	if (NULL != m_pChartManager)
	{
		m_pChartManager->Release();
		m_pChartManager = NULL;
	}

	if (NULL != m_hIIChart)
	{
		FreeLibrary(m_hIIChart);
		m_hIIChart = NULL;
	}
}

void CCaseService::AddCase(const wstring& wsCase, ICase* pCase)
{
	m_vctCase.push_back(wsCase);
	m_mapCase.insert(pair<wstring, ICase*>(wsCase, pCase));
}
