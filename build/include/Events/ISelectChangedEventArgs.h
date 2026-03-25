#pragma once
/***********************************************************************
 * Module:  ISelectChangedEventArgs.h
 * Author:  杨鹏辉
 * Modified: 2022年6月30日 11:42:37
 * Purpose: ACTION: ISelectChangedEventArgs 切换图例选中状态后的事件
 *          注：图例组件用户切换图例开关会触发该事件。
 ***********************************************************************/

#include <vector>
#include <Events/IEvents.h>

using namespace std;

namespace IIChart
{

	class ISelectChangedEventArgs : virtual public IEventArgs
	{
	public:
		virtual wchar_t* GetFromAction() = 0;
		virtual int GetSeriesIndex() = 0;
		virtual int GetDataIndex() = 0;

	};
}
