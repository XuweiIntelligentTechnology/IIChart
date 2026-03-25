#pragma once
/***********************************************************************
 * Module:  ILegendAllSelectActionArgs.h
 * Author:  杨鹏辉
 * Modified: 2022年6月30日 11:42:37
 * Purpose: 数据区域缩放。
 ***********************************************************************/

#include <ActionArgs/IAction.h>

namespace IIChart
{

	class IDataZoomAction : virtual public IAction
	{
	public:

		// 可选，dataZoom 组件的 index，多个 dataZoom 组件时有用，默认为 0
		virtual void SetDataZoomIndex(int nValue) = 0;
		virtual int GetDataZoomIndex() const = 0;

		// 开始位置的百分比，0 - 100
		virtual void SetStart(int nValue) = 0;
		virtual int GetStart() const = 0;

		// 结束位置的百分比，0 - 100
		virtual void SetEnd(int nValue) = 0;
		virtual int GetEnd() const = 0;

		// 开始位置的数值
		virtual void SetStartValue(int nValue) = 0;
		virtual int GetStartValue() const = 0;

		// 结束位置的数值
		virtual void SetEndValue(int nValue) = 0;
		virtual int GetEndValue() const = 0;

	};

}