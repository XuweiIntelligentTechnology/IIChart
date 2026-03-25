#pragma once
/***********************************************************************
 * Module:  ITimelinePlayChangeActionArgs.h
 * Author:  杨鹏辉
 * Modified: 2022年6月30日 11:42:37
 * Purpose: 切换时间轴的播放状态。
 ***********************************************************************/

#include <ActionArgs/IAction.h>

namespace IIChart
{

	class ITimelinePlayChangeAction : virtual public IAction
	{
	public:
		// 播放状态，true 为自动播放
		virtual void SetPlayState(bool bValue) = 0;
		virtual bool GetPlayState() = 0;
	};
}


