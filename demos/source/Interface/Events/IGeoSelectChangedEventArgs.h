#pragma once
/***********************************************************************
 * Module:  IGeoSelectChangedEventArgs.h
 * Author:  杨鹏辉
 * Modified: 2022年6月30日 11:42:37
 * Purpose: ACTION: legendToggleSelect 切换图例选中状态后的事件
 *          注：图例组件用户切换图例开关会触发该事件。
 ***********************************************************************/

#include <list>
#include <Events/IEvents.h>

using namespace std;

namespace IIChart
{

	class IGeoSelectChangedEventArgs : virtual public IEventArgs
	{
	public:

		// 切换的图例名称
		virtual wchar_t* GetDataName() = 0;

	};
}
