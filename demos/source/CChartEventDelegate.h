#pragma once
#include "IChartEventDelegate.h"

using namespace IIChart;
class CIIChartDemoDlg;
class CChartEventDelegate : public IChartEventDelegate
{
public:
	CChartEventDelegate(CIIChartDemoDlg* pDlg);
	~CChartEventDelegate();

	virtual void OnResize() override;

	virtual void OnClick(/* [in] */ IMouseEventArgs* pArgs, /* [in] */ IChart* pChart) override;
	virtual void OnMouseOver(/* [in] */ IMouseEventArgs* pArgs, /* [in] */ IChart* pChart) override;
	virtual void OnMouseOut(/* [in] */ IMouseEventArgs* pArgs, /* [in] */ IChart* pChart) override;

	virtual void OnSelectChanged(ISelectChangedEventArgs* pArgs, IChart* pChart) override;
	virtual void OnLegendSelectChanged(ILegendSelectChangedEventArgs* pArgs, IChart* pChart) override;
	virtual void OnLegendSelected(ILegendSelectedEventArgs* pArgs, IChart* pChart) override;
	virtual void OnLegendUnSelected(ILegendUnSelectedEventArgs* pArgs, IChart* pChart) override;
	virtual void OnLegendSelectAll(ILegendSelectAllEventArgs* pArgs, IChart* pChart) override;
	virtual void OnLegendInverseSelect(ILegendInverseSelectEventArgs* pArgs, IChart* pChart) override;
	virtual void OnGeoSelectChanged(IGeoSelectChangedEventArgs* pArgs, IChart* pChart) override;

private:
	HWND m_hWnd;
	CIIChartDemoDlg* m_pDlg;
};


