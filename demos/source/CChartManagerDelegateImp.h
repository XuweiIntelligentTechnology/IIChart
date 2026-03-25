#pragma once
#include "IChartManagerDelegate.h"

using namespace IIChart;

class CIIChartDemoDlg;

class CChartManagerDelegateImp : public IChartManagerDelegate
{
public:
	CChartManagerDelegateImp(CIIChartDemoDlg* pDlg);
	~CChartManagerDelegateImp();

public:
	virtual void OnInitialized() override; // 环境已经初始化完成;
	virtual void OnPdfPrintFinished(const wchar_t* wzPdfFile, int nError, bool bOk) override; // 完成视图容内容 PDF 格式打印结束;
	virtual void OnCapturePreviewCompleted(const wchar_t* wzFile, int nError) override; // 完成容器视图内容保存为图片;

private:
	CIIChartDemoDlg* m_pDlg = nullptr;
};

