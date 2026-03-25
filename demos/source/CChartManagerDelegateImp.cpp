#include "pch.h"
#include "IIChartDemoDlg.h"
#include "CChartManagerDelegateImp.h"

CChartManagerDelegateImp::CChartManagerDelegateImp(CIIChartDemoDlg* pDlg)
	: m_pDlg(pDlg)
{
}

CChartManagerDelegateImp::~CChartManagerDelegateImp()
{
}

void CChartManagerDelegateImp::OnInitialized()
{
	m_pDlg->OutputLine(L"IIChart 初始化完成;");

	/* IIChart 控件初始化完成后，才可以进行绘图相关操作; */
	m_pDlg->InitUIControl();
}

void CChartManagerDelegateImp::OnPdfPrintFinished(const wchar_t* wzPdfFile, int nError, bool bOk)
{
}

void CChartManagerDelegateImp::OnCapturePreviewCompleted(const wchar_t* wzFile, int nError)
{
}
