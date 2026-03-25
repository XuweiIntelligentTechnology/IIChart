#pragma once

#include "CChartEventDelegate.h"

/*************************************************************
目标：
    1. 展示创建流程;
	2. 展示各个属性的作用与效果;
	3. 测试此系列所有功能;

**************************************************************/
class CLineTypeCase : public ICase
{
public:
	CLineTypeCase(IIChart::IChartManager* pManager, CIIChartDemoDlg* pDlg, IChartEventDelegate* pDelegate);
	~CLineTypeCase();

	virtual vector<wstring> GetFunctionList() override;
	virtual int RunFunction(const wstring& wsFunction) override;
	virtual void ClearChart() override;
	virtual void Release() override;

private:

	BOOL UpdateData();

	BOOL CreateBasicLineChart();
	BOOL CreateBasicSmoothLineChart();
	BOOL CreateBasicAreaChart();
	BOOL CreateBasicSmoothAreaChart();

	BOOL CreateX2YBasicLineChart();
	BOOL CreateGrideLegendBasicLineChart();
	BOOL CreateShowXAxisBasicLineChart();
	BOOL CreateLadderBasicLineChart();
	BOOL CreateSmoothBasicLineChart();

	BOOL CreateBasicAreaChartEx();

	BOOL CreateStackedLineChart();
	BOOL CreateStackedAreaChart();
	BOOL CreateGradientStackedAreaChart();

private:

private:
	IIChart::IChart* m_pChart = nullptr;
	IIChart::IChartManager* m_pManager = nullptr;
	CIIChartDemoDlg* m_pDlg = nullptr;
	IChartEventDelegate* m_pDelegate = nullptr;

	vector<wstring> m_vctFunction;
};

