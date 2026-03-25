#pragma once
/***********************************************************************
 * Module:  ITimelineChangeActionArgs.h
 * Author:  杨鹏辉
 * Modified: 2022年6月30日 11:42:37
 * Purpose: 设置当前的时间点。
 ***********************************************************************/
#include <ActionArgs/IAction.h>

namespace IIChart
{

	class ITimelineChangeAction : virtual public IAction
	{
	public:
		// 时间点的 index
		virtual void SetCurrentIndex(int nIndex) = 0;
		virtual int GetCurrentIndex() = 0;
	};
}


