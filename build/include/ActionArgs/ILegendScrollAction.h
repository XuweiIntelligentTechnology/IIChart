#pragma once
/***********************************************************************
 * Module:  ILegendScrollActionArgs.h
 * Author:  杨鹏辉
 * Modified: 2022年6月30日 11:42:37
 * Purpose: 控制图例的滚动。当 legend.type 为 'scroll' 时有效。
 ***********************************************************************/

#include <ActionArgs/IAction.h>

namespace IIChart
{

	class ILegendScrollAction : virtual public IAction
	{
	public:

		virtual void SetScrollDataIndex(int nValue) = 0;
		virtual int GetScrollDataIndex() const = 0;

		virtual void SetLegendId(const wchar_t* wzId) = 0;
		virtual wchar_t* GetLegendId() const = 0;
	};
}


