#pragma once

#include "CChartEventDelegate.h"

/*************************************************************
目标：
    1. 展示创建流程;
	2. 展示各个属性的作用与效果;
	3. 测试此系列所有功能;

**************************************************************/
class CPieTypeCase : public ICase
{
public:
	CPieTypeCase(IIChart::IChartManager* pManager , CIIChartDemoDlg* pDlg, IChartEventDelegate* pDelegate);
	~CPieTypeCase();

	virtual vector<wstring> GetFunctionList() override;
	virtual int RunFunction(const wstring& wsFunction) override;
	virtual void ClearChart() override;
	virtual void Release() override;

private:
	BOOL CreateRefererWebsite();
	BOOL CreateRoundedCorner();

	BOOL UpdateData();

private:
	IIChart::IChart* m_pChart = nullptr;
	IIChart::IChartManager* m_pManager = nullptr;
	CIIChartDemoDlg* m_pDlg = nullptr;
	IChartEventDelegate* m_pDelegate = nullptr;

	vector<wstring> m_vctFunction;

	IFixedQueue* m_pFixedQueue;
};

