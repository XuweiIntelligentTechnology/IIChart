#pragma once
/***********************************************************************
 * Module:  ITakeGlobalCursorActionArgs.h
 * Author:  杨鹏辉
 * Modified: 2022年6月30日 11:42:37
 * Purpose: 启动或关闭 toolbox 中 dataZoom 的刷选状态。
 ***********************************************************************/
#include <ActionArgs/IAction.h>

namespace IIChart
{

	class IDataZoomTakeGlobalCursorAction : virtual public IAction
	{
	public:
		virtual void SetDataZoomSelectActive(bool bValue) = 0;
		virtual bool GetDataZoomSelectActive() = 0;
	};
}


