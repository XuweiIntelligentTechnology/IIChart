#pragma once
#include <map>


class CIIChartDemoDlg;
class CChartEventDelegate;
class CChartManagerDelegateImp;

class CCaseService
{
public:
	CCaseService(CIIChartDemoDlg* pDlg, IChartEventDelegate* pChartDelegate, IChartManagerDelegate* pChartManagerDelegate);
	~CCaseService();

	int Init(HWND hView);
	void Uninit();

	vector<wstring> GetCaseList(); // 取当前的 【用例】 列表;
	vector<wstring> GetFunctionList(const wstring& wsCase);  // 取指定 【用例】下的功能列表;
	int RunFunction(const wstring& wsCase, const wstring& wsFunction); // 运行指定的功能;
	int ClearCaseChart(const wstring& wsCase);

	void ClearChart();

private:
	int  InitIIChart();
	void UninitIIChart();

	void AddCase(const wstring& wsCase, ICase* pCase);

private:
	HINSTANCE m_hIIChart = nullptr;

	IChartManagerDelegate* m_pChartManagerDelegate = nullptr;

	CIIChartDemoDlg* m_pDlg = nullptr;
	IChartEventDelegate* m_pChartDelegate = nullptr;
	IIChart::IChartManager* m_pChartManager = nullptr;
	IIChart::IGlobalUtility* m_pGlobalUtility = nullptr;

	map<wstring, ICase*> m_mapCase;
	vector<wstring> m_vctCase;

};

