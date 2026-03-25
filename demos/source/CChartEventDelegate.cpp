#include "pch.h"
#include "IIChartDemoDlg.h"
#include "CChartEventDelegate.h"

CChartEventDelegate::CChartEventDelegate(CIIChartDemoDlg* pDlg)
	: m_pDlg(pDlg)
{
}

CChartEventDelegate::~CChartEventDelegate()
{
}

void CChartEventDelegate::OnResize()
{
}

void CChartEventDelegate::OnClick(IMouseEventArgs* pArgs, IChart* pChart)
{
	wchar_t wzTemp[1024] = { 0 };
	wstring wsMsg = L"-->¡¾OnClick¡¿\r\n";

	if (nullptr != pArgs->GetComponentType())
	{
		wsprintf(wzTemp, L"GetComponentType: %s\r\n", pArgs->GetComponentType());
		wsMsg += wzTemp;
	}
	
	if (nullptr != pArgs->GetSeriesType())
	{
		wsprintf(wzTemp, L"GetSeriesType: %s\r\n", pArgs->GetSeriesType());
		wsMsg += wzTemp;
	}

	wsprintf(wzTemp, L"GetSeriesIndex: %d\r\n", pArgs->GetSeriesIndex());
	wsMsg += wzTemp;

	if (nullptr != pArgs->GetSeriesName())
	{
		wsprintf(wzTemp, L"GetSeriesName: %s\r\n", pArgs->GetSeriesName());
		wsMsg += wzTemp;
	}

	if (nullptr != pArgs->GetName())
	{
		wsprintf(wzTemp, L"GetName:%s\r\n", pArgs->GetName());
		wsMsg += wzTemp;
	}

	if (nullptr != pArgs->GetDataType())
	{
		wsprintf(wzTemp, L"GetDataType: %s\r\n", pArgs->GetDataType());
		wsMsg += wzTemp;
	}

	int nCount = 0;
	int nResult = pArgs->GetValueCount(&nCount);
	if (0 == nResult)
	{
		wsprintf(wzTemp, L"GetValueCount: %d\r\n", nCount);
		wsMsg += wzTemp;

		if (0 < nCount)
		{
			wsMsg += L"Value: ";
			for (int nIndex = 0; nIndex < nCount; ++nIndex)
			{
				float fValue = pArgs->GetValue(nIndex);
				wsprintf(wzTemp, L"%d, ",(int)fValue);
				wsMsg += wzTemp;
			}
			wsMsg += L"\r\n";
		}
	}
	
	
	if (nullptr != pArgs->GetColor())
	{
		wsprintf(wzTemp, L"GetColor: %s\r\n", pArgs->GetColor());
		wsMsg += wzTemp;
	}

	m_pDlg->OutputLine(wsMsg.c_str());
}

void CChartEventDelegate::OnMouseOver(IMouseEventArgs* pArgs, IChart* pChart)
{
	if (pChart && pArgs)
	{
		IGeoHighlightAction* pHighlightAction = pChart->GetActionArgsFactory()->CreateGeoHighlightAction();
		pHighlightAction->SetGeoIndex(L"0");
		pHighlightAction->SetName(pArgs->GetName());
		pChart->DispatchAction(pHighlightAction);
	}
}

void CChartEventDelegate::OnMouseOut(IMouseEventArgs* pArgs, IChart* pChart)
{
	if (pChart && pArgs)
	{
		IGeoDownplayAction* pDownPlayAction = pChart->GetActionArgsFactory()->CreateGeoDownplayAction();
		pDownPlayAction->SetGeoIndex(L"0");
		pDownPlayAction->SetName(pArgs->GetName());
		pChart->DispatchAction(pDownPlayAction);
	}
}

void CChartEventDelegate::OnSelectChanged(ISelectChangedEventArgs* pArgs, IChart* pChart)
{
	wchar_t wzTemp[1024] = { 0 };
	wstring wsMsg = L"-->¡¾OnSelectChanged¡¿\r\n";

	if (nullptr != pArgs->GetFromAction())
	{
		wsprintf(wzTemp, L"GetFromAction: %s\r\n", pArgs->GetFromAction());
		wsMsg += wzTemp;
	}

	wsprintf(wzTemp, L"GetSeriesIndex: %d\r\n", pArgs->GetSeriesIndex());
	wsMsg += wzTemp;

	wsprintf(wzTemp, L"GetDataIndex: %d\r\n", pArgs->GetDataIndex());
	wsMsg += wzTemp;


	m_pDlg->OutputLine(wsMsg.c_str());
}

void CChartEventDelegate::OnLegendSelectChanged(ILegendSelectChangedEventArgs* pArgs, IChart* pChart)
{

}

void CChartEventDelegate::OnLegendSelected(ILegendSelectedEventArgs* pArgs, IChart* pChart)
{

}
void CChartEventDelegate::OnLegendUnSelected(ILegendUnSelectedEventArgs* pArgs, IChart* pChart)
{

}

void CChartEventDelegate::OnLegendSelectAll(ILegendSelectAllEventArgs* pArgs, IChart* pChart)
{

}

void CChartEventDelegate::OnLegendInverseSelect(ILegendInverseSelectEventArgs* pArgs, IChart* pChart)
{

}

void CChartEventDelegate::OnGeoSelectChanged(IGeoSelectChangedEventArgs* pArgs, IChart* pChart)
{
	wchar_t wzTemp[1024] = { 0 };
	wstring wsMsg = L"-->¡¾OnGeoSelectChanged¡¿\r\n";

	if (nullptr != pArgs->GetDataName())
	{
		wsprintf(wzTemp, L"GetDataName: %s\r\n", pArgs->GetDataName());
		wsMsg += wzTemp;
	}

	m_pDlg->OutputLine(wsMsg.c_str());
}