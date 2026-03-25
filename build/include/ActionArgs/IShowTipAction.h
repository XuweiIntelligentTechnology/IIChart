#pragma once
/***********************************************************************
 * Module:  IShowTipAction.h
 * Author:  杨鹏辉
 * Modified: 2022年6月30日 11:42:37
 * Purpose: 显示提示框。
 ***********************************************************************/
#include <ActionArgs/IAction.h>
#include <ActionArgs/ICommonGeoAction.h>

namespace IIChart
{

	class IShowTipAction : virtual public ICommonGeoAction
	{
	public:

		/* 有 3 种使用方式： */
		/* 1 指定在相对容器的位置处显示提示框，如果指定的位置无法显示则无效。 */
		
		// 屏幕上的 x 坐标
		virtual void SetX(float fValue) = 0;
		virtual float GetX() = 0;

		// 屏幕上的 y 坐标
		virtual void SetY(float fValue) = 0;
		virtual float GetY() = 0;

		/* 2 指定系列中的数据图形，根据 tooltip 的配置项显示提示框。 */

		// 用 index 指定单个或多个系列;
		virtual void SetSeriesIndex(int nIndex) = 0;
		virtual int GetSeriesIndex() const = 0;

		// 用 Id 指定单个或多个系列;
		virtual void SetDataIndex(int nIndex) = 0;
		virtual int GetDataIndex() const = 0;

		// 用 name 指定单个或多个系列;
		virtual void SetName(const wchar_t* nId) = 0;
		virtual wchar_t* GetName() const = 0;

		/* 3 指定 geo 组件中的 region 名，根据 tooltip 的配置项显示提示框。 */

	};
}


