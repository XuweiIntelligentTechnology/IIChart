#pragma once
/***********************************************************************
 * Module:  ISelectDataRangeActionArgs.h
 * Author:  杨鹏辉
 * Modified: 2022年6月30日 11:42:37
 * Purpose: 针对 VisualMap 的选取映射的数值范围。
 ***********************************************************************/

#include <ActionArgs/IAction.h>

namespace IIChart
{
	// 注意：
	// 连续型 visualMap 和 离散型 visualMap 不一样
	// 连续型的是一个表示数值范围的数组。
	// 离散型的是一个对象，键值是类目或者分段的索引。值是 `true`, `false`

	class ISelectDataRangeAction : virtual public IAction
	{
	public:
		// 可选，visualMap 组件的 index，多个 visualMap 组件时有用，默认为 0
		virtual void SetVisualMapIndex(int nIndex) = 0;
		virtual int GetVisualMapIndex() = 0;

		// 连续型,例如：选取 20 到 40 的值范围，selected: [20, 40] ,
		virtual void SetSelectedRange(int nBegin, int nEnd) = 0;
		virtual void GetSelectedRange(int* pnBegin, int* pnEnd) = 0;

		// 离散型,例如：取消选中第二段 ，selected: { 1: false };
		//              取消选中类目 `优`,selected: { '优': false }
		virtual int AddSelectedObjectValue(const wchar_t* wzKey, bool bValue) = 0;
		virtual int AddSelectedObjectValue(int nKey, bool bValue) = 0;
		virtual int AddSelectedObjectValue(float fKey, bool bValue) = 0;
	};
}


