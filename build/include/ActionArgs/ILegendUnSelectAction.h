#pragma once
/***********************************************************************
 * Module:  ILegendUnSelectActionArgs.h
 * Author:  杨鹏辉
 * Modified: 2022年6月30日 11:42:37
 * Purpose: 取消选中图例。
 ***********************************************************************/

#include <ActionArgs/IAction.h>

namespace IIChart
{

	class ILegendUnSelectAction : virtual public IAction
	{
	public:
		// 数据项名称，在有 dataIndex 的时候忽略
		virtual void SetName(const wchar_t* wzName) = 0;
		virtual wchar_t* GetName() const = 0;
	};
}


