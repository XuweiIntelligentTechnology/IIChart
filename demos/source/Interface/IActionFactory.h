
/***********************************************************************
 * Module:  IActionFactory.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 16:48:26
 * Purpose: Declaration of the class IActionFactory
 ***********************************************************************/
#pragma once
#include <ActionArgs/IAction.h>
#include <ActionArgs/IBrushAction.h>
#include <ActionArgs/IBrushEndAction.h>
#include <ActionArgs/IBrushTakeGlobalCursorAction.h>
#include <ActionArgs/ICommonAction.h>
#include <ActionArgs/ICommonGeoAction.h>
#include <ActionArgs/IDataZoomAction.h>
#include <ActionArgs/IDataZoomTakeGlobalCursorAction.h>
#include <ActionArgs/IDownplayAction.h>
#include <ActionArgs/IGeoDownplayAction.h>
#include <ActionArgs/IGeoHighlightAction.h>
#include <ActionArgs/IGeoSelectAction.h>
#include <ActionArgs/IGeoToggleSelectAction.h>
#include <ActionArgs/IGeoUnSelectAction.h>
#include <ActionArgs/IHideTipAction.h>
#include <ActionArgs/IHighlightAction.h>
#include <ActionArgs/ILegendAllSelectAction.h>
#include <ActionArgs/ILegendInverseSelectAction.h>
#include <ActionArgs/ILegendScrollAction.h>
#include <ActionArgs/ILegendSelectAction.h>
#include <ActionArgs/ILegendToggleSelectAction.h>
#include <ActionArgs/ILegendUnSelectAction.h>
#include <ActionArgs/ISelectAction.h>
#include <ActionArgs/ISelectDataRangeAction.h>
#include <ActionArgs/IShowTipAction.h>
#include <ActionArgs/ITimelineChangeAction.h>
#include <ActionArgs/ITimelinePlayChangeAction.h>
#include <ActionArgs/IToggleSelectedAction.h>
#include <ActionArgs/IToolboxRestoreAction.h>
#include <ActionArgs/IUnselectAction.h>


namespace IIChart
{
	/*@class
	*******************************************************************
	类  名:  IActionFactory;
	功  能:  Chart Action 工厂类;
	备  注:  ;
	--------------------------------------------------------------------
	作  者:  YangPenghui 2022-3-26;
	*******************************************************************/
	class IActionFactory
	{
	public:

		virtual IBrushAction* CreateBrushAction() = 0;
		virtual IBrushEndAction* CreateBrushEndAction() = 0;
		virtual IBrushTakeGlobalCursorAction* CreateBrushTakeGlobalCursorAction() = 0;
		virtual IDataZoomAction* CreateDataZoomAction() = 0;
		virtual IDataZoomTakeGlobalCursorAction* CreateDataZoomTakeGlobalCursorAction() = 0;

		/*@function
		*******************************************************************
		功  能:  取消高亮的动作;
		参  数:  <无> ;
		返回值:  <IDownplayAction*>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual IDownplayAction* CreateDownplayAction() = 0;
		virtual IGeoDownplayAction* CreateGeoDownplayAction() = 0;
		virtual IGeoHighlightAction* CreateGeoHighlightAction() = 0;
		virtual IGeoSelectAction* CreateGeoSelectAction() = 0;
		virtual IGeoToggleSelectAction* CreateGeoToggleSelectAction() = 0;
		virtual IGeoUnSelectAction* CreateGeoUnSelectAction() = 0;
		virtual IHideTipAction* CreateHideTipAction() = 0;

		/*@function
		*******************************************************************
		功  能:  取消高亮的动作;
		参  数:  <无> ;
		返回值:  <IHighlightAction*>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual IHighlightAction* CreateHighlightAction() = 0;
		virtual ILegendAllSelectAction* CreateLegendAllSelectAction() = 0;
		virtual ILegendInverseSelectAction* CreateLegendInverseSelectAction() = 0;
		virtual ILegendScrollAction* CreateLegendScrollAction() = 0;
		virtual ILegendSelectAction* CreateLegendSelectAction() = 0;
		virtual ILegendToggleSelectAction* CreateLegendToggleSelectAction() = 0;
		virtual ILegendUnSelectAction* CreateLegendUnSelectAction() = 0;
		virtual ISelectAction* CreateSelectAction() = 0;
		virtual ISelectDataRangeAction* CreateSelectDataRangeAction() = 0;
		virtual IShowTipAction* CreateShowTipAction() = 0;
		virtual ITimelineChangeAction* CreateTimelineChangeAction() = 0;
		virtual ITimelinePlayChangeAction* CreateTimelinePlayChangeAction() = 0;
		virtual IToggleSelectedAction* CreateToggleSelectedAction() = 0;
		virtual IToolboxRestoreAction* CreateToolboxRestoreAction() = 0;
		virtual IUnselectAction* CreateUnselectAction() = 0;
	};

}


