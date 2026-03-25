
/***********************************************************************
 * Module:  IChartEventDelegate.h
 * Author:  杨鹏辉
 * Modified: 2022年6月30日 11:28:08
 * Purpose: Declaration of the class IChartEventDelegate
 ***********************************************************************/
#pragma once
#include "Events/IDownplayEventArgs.h"
#include "Events/IHighlightEventArgs.h"
#include "Events/IMouseEventArgs.h"
#include "Events/ISelectChangedEventArgs.h"
#include "Events/ILegendSelectChangedEventArgs.h"
#include "Events/ILegendSelectedEventArgs.h"
#include "Events/ILegendUnSelectedEventArgs.h"
#include "Events/ILegendSelectAllEventArgs.h"
#include "Events/ILegendInverseSelectEventArgs.h"
#include "Events/ILegendScrollEventArgs.h"
#include "Events/IDataZoomEventArgs.h"
#include "Events/IDataRangeSelectedEventArgs.h"
#include "Events/ITimeLineChangedEventArgs.h"
#include "Events/ITimeLinePlayChangedEventArgs.h"
#include "Events/IRestoreEventArgs.h"
#include "Events/IDataViewChangedEventArgs.h"
#include "Events/IMagicTypeChangedEventArgs.h"
#include "Events/IGeoSelectChangedEventArgs.h"
#include "Events/IGeoSelectedEventArgs.h"
#include "Events/IGeoUnselectedEventArgs.h"
#include "Events/IAxisAreaSelectedEventArgs.h"
#include "Events/IBurshEventArgs.h"
#include "Events/IBurshEndEventArgs.h"
#include "Events/IBurshSelectedEventArgs.h"
#include "Events/IGlobalcursortakenEventArgs.h"
#include "Events/IRenderedEventArgs.h"
#include "Events/IFinishedEventArgs.h"

namespace IIChart
{
	class IChart;

	/*@class
	*************************************************************************
	* 类  名: IChartEventDelegate
	* 修  改: 2022年7月1日 15:02:44
	* 功  能: Chart 响应事件处理接口;
	-----------------------------------------------------------------------
	作  者:  YangPenghui 2022-10-26;
	************************************************************************/
	class IChartEventDelegate
	{
	public:
		
		virtual void OnResize() = 0;

		/*@function
		*******************************************************************
		功  能:  鼠标事件;
		参  数:  <pArgs> 响应事件;
				 <pChart> 当前的 Chart 实例
		返回值:  <无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void OnClick(/* [in] */ IMouseEventArgs* pArgs, /* [in] */ IChart* pChart) {};
		virtual void OnDblClick(/* [in] */ IMouseEventArgs* pArgs, /* [in] */ IChart* pChart) {};
		virtual void OnMouseDown(/* [in] */ IMouseEventArgs* pArgs, /* [in] */ IChart* pChart) {};
		virtual void OnMouseMove(/* [in] */ IMouseEventArgs* pArgs, /* [in] */ IChart* pChart) {};
		virtual void OnMouseUp(/* [in] */ IMouseEventArgs* pArgs, /* [in] */ IChart* pChart) {};
		virtual void OnMouseOver(/* [in] */ IMouseEventArgs* pArgs, /* [in] */ IChart* pChart) {};
		virtual void OnMouseOut(/* [in] */ IMouseEventArgs* pArgs, /* [in] */ IChart* pChart) {};
		virtual void OnGlobalOut(/* [in] */ IMouseEventArgs* pArgs, /* [in] */ IChart* pChart) {};
		virtual void OnContextMenu(/* [in] */ IMouseEventArgs* pArgs, /* [in] */ IChart* pChart) {};

		/*@function
		*******************************************************************
		功  能:  高亮事件
		参  数:  <pArgs> 响应事件;
		         <pChart> 当前的 Chart 实例
		返回值:  <无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void OnHighlight(/* [in] */ IHighlightEventArgs* pArgs, /* [in] */ IChart* pChart) {};

		/*@function
		*******************************************************************
		功  能:  取消高亮事件
		参  数:  <pArgs> 响应事件;
				 <pChart> 当前的 Chart 实例
		返回值:  <无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void OnDownplay(/* [in] */ IDownplayEventArgs* pArgs, /* [in] */ IChart* pChart) {};

		/*@function
		*******************************************************************
		功  能:  渲染结束事件。注意 rendered 事件并不代表渲染动画或者渐进渲染停止，只代表本帧的渲染结束;
		参  数:  <pChart> 当前的图表对象;
		返回值:  <无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void OnRendered(/* [in] */ IRenderedEventArgs* pArgs, /* [in] */ IChart* pChart) {};

		/*@function
		*******************************************************************
		功  能:  渲染完成事件。当渲染动画或者渐进渲染停止时触发。
		参  数:  <pChart> 当前的图表对象;
		返回值:  <无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void OnFinish(/* [in] */ IFinishedEventArgs* pArgs, /* [in] */ IChart* pChart) {};

		/*@function
		*******************************************************************
		功  能:  在数据选中状态发生变化时触发的事件。
		参  数:  <pChart> 当前的图表对象;
		返回值:  <无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void OnSelectChanged(ISelectChangedEventArgs* pArgs, IChart* pChart) {};

		/*@function
		*******************************************************************
		功  能:  切换图例选中状态后的事件。注：图例组件用户切换图例开关会触发该事件。
		参  数:  <pChart> 当前的图表对象;
		返回值:  <无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void OnLegendSelectChanged(ILegendSelectChangedEventArgs* pArgs, IChart* pChart) {};

		/*@function
		*******************************************************************
		功  能:  图例选中后的事件。
		参  数:  <pChart> 当前的图表对象;
		返回值:  <无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void OnLegendSelected(ILegendSelectedEventArgs* pArgs, IChart* pChart) {};

		/*@function
		*******************************************************************
		功  能:  图例取消选中后的事件。
		参  数:  <pChart> 当前的图表对象;
		返回值:  <无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void OnLegendUnSelected(ILegendUnSelectedEventArgs* pArgs, IChart* pChart) {};

		/*@function
		*******************************************************************
		功  能:  图例全选后的事件。
		参  数:  <pChart> 当前的图表对象;
		返回值:  <无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void OnLegendSelectAll(ILegendSelectAllEventArgs* pArgs, IChart* pChart) {};

		/*@function
		*******************************************************************
		功  能:  图例反选后的事件。
		参  数:  <pChart> 当前的图表对象;
		返回值:  <无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void OnLegendInverseSelect(ILegendInverseSelectEventArgs* pArgs, IChart* pChart) {};

		/*@function
		*******************************************************************
		功  能:  图例滚动事件。
		参  数:  <pChart> 当前的图表对象;
		返回值:  <无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void OnLegendScroll(ILegendScrollEventArgs* pArgs, IChart* pChart) {};

		/*@function
		*******************************************************************
		功  能:  数据区域缩放后的事件。
		参  数:  <pChart> 当前的图表对象;
		返回值:  <无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void OnDataZoom(IDataZoomEventArgs* pArgs, IChart* pChart) {};

		/*@function
		*******************************************************************
		功  能:  视觉映射组件中，range 值改变后触发的事件。
		参  数:  <pChart> 当前的图表对象;
		返回值:  <无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void OnDataRangeSelected(IDataRangeSelectedEventArgs* pArgs, IChart* pChart) {};

		/*@function
		*******************************************************************
		功  能:  时间轴中的时间点改变后的事件。
		参  数:  <pChart> 当前的图表对象;
		返回值:  <无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void OnTimeLineChanged(ITimeLineChangedEventArgs* pArgs, IChart* pChart) {};

		/*@function
		*******************************************************************
		功  能:  时间轴中播放状态的切换事件。
		参  数:  <pChart> 当前的图表对象;
		返回值:  <无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void OnTimeLinePlayChanged(ITimeLinePlayChangedEventArgs* pArgs, IChart* pChart) {};

		/*@function
		*******************************************************************
		功  能:  重置 option 事件。
		参  数:  <pChart> 当前的图表对象;
		返回值:  <无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void OnRestore(IRestoreEventArgs* pArgs, IChart* pChart) {};

		/*@function
		*******************************************************************
		功  能:  工具栏中数据视图的修改事件。
		参  数:  <pChart> 当前的图表对象;
		返回值:  <无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void OnDataViewChanged(IDataViewChangedEventArgs* pArgs, IChart* pChart) {};

		/*@function
		*******************************************************************
		功  能:  工具栏中动态类型切换的切换事件。
		参  数:  <pChart> 当前的图表对象;
		返回值:  <无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void OnMagicTypeChanged(IMagicTypeChangedEventArgs* pArgs, IChart* pChart) {};

		/*@function
		*******************************************************************
		功  能:  geo 中地图区域切换选中状态的事件。
		参  数:  <pChart> 当前的图表对象;
		返回值:  <无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void OnGeoSelectChanged(IGeoSelectChangedEventArgs* pArgs, IChart* pChart) {};

		/*@function
		*******************************************************************
		功  能:  geo 中地图区域选中后的事件。
		参  数:  <pChart> 当前的图表对象;
		返回值:  <无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void OnGeoSelected(IGeoSelectedEventArgs* pArgs, IChart* pChart) {};

		/*@function
		*******************************************************************
		功  能:  geo 中地图区域取消选中后的事件。
		参  数:  <pChart> 当前的图表对象;
		返回值:  <无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void OnGeoUnSelected(IGeoUnSelectedEventArgs* pArgs, IChart* pChart) {};

		/*@function
		*******************************************************************
		功  能:  平行坐标轴 (Parallel)范围选取事件。
		参  数:  <pChart> 当前的图表对象;
		返回值:  <无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void OnAxisAreaSelected(IAxisAreaSelectedEventArgs* pArgs, IChart* pChart) {};

		/*@function
		*******************************************************************
		功  能:  “选框正在添加”事件。即发出 brush action 得到的事件。
		参  数:  <pChart> 当前的图表对象;
		返回值:  <无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void OnBrush(IBurshEventArgs* pArgs, IChart* pChart) {};

		/*@function
		*******************************************************************
		功  能:  “选框添加完毕”事件。即发出 brushEnd action 得到的事件。
		参  数:  <pChart> 当前的图表对象;
		返回值:  <无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void OnBrushEnd(IBurshEndEventArgs* pArgs, IChart* pChart) {};

		/*@function
		*******************************************************************
		功  能:  对外通知当前选中了什么。这个事件，在 setOption 时不会发出，在其他的 dispatchAction 时，或者用户在界面中创建、删除、修改选框时会发出。
		参  数:  <pChart> 当前的图表对象;
		返回值:  <无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void OnBrushSelected(IBurshSelectedEventArgs* pArgs, IChart* pChart) {};

		/*@function
		*******************************************************************
		功  能:  刷选模式的开关。使用此 action 可将当前鼠标变为可刷选状态。
		参  数:  <pChart> 当前的图表对象;
		返回值:  <无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void OnGlobalCursorTaken(IGlobalCursorTakenEventArgs* pArgs, IChart* pChart) {};

	};

}


