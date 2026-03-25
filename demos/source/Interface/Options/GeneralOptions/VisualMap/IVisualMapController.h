#pragma once
/***********************************************************************
 * Module:  IVisualMapController.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: visualMap 组件中，控制器 的 inRange outOfRange 设置。
 *          > 如果没有这个 controller 设置，控制器 会使用外层的 inRange outOfRange 设置；
 *          > 如果有这个 controller 设置，则会采用这个设置。
 *          适用于一些控制器视觉效果需要特殊定制或调整的场景。
 ***********************************************************************/
#include <vector>
#include <string>
#include "Common/ICallback.h"
#include "Options/Common/ICategoryData.h"
#include "Options/GeneralOptions/VisualMap/IVisualMapRange.h"

namespace IIChart
{
	namespace VisualMap
	{
		/*@class
		***********************************************************************
		* 类  名: IVisualMapController
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: visualMap 组件中，控制器 的 inRange outOfRange 设置。
		-----------------------------------------------------------------------
		* 作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IVisualMapController
		{
		public:

			/*@function
			******************************************************************
			功  能：定义 [在选中范围中] 的视觉元素。（用户可以和 visualMap 组件交互，用鼠标或触摸选择范围）
			参  数：<无>;
			返回值：<IVisualMapRange*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IVisualMapRange* GetInRange() = 0;

			/*@function
			******************************************************************
			功  能：定义 [在选中范围外] 的视觉元素。（用户可以和 visualMap 组件交互，用鼠标或触摸选择范围）
			参  数：<无>;
			返回值：<IVisualMapRange*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IVisualMapRange* GetOutOfRange() = 0;
		};
	}
	
}