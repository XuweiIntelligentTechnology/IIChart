#pragma once
/***********************************************************************
 * Module:  Tooltip.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: 工具栏。
 * 内置有导出图片，数据视图，动态类型切换，数据区域缩放，重置五个工具。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/IBaseArrayElement.h"
#include "Options/Common/ITextStyle.h"
#include "Options/GeneralOptions/Toolbox/IToolboxFeatureBrushTitle.h"
#include "Options/GeneralOptions/Toolbox/IToolboxFeatureBrushIcon.h"

namespace IIChart
{
	namespace Toolbox
	{
		/***************************
	    * 全局 Tooltip 组件;
	    ****************************/
		class IToolboxFeatureBrush
		{
		public:
			// 使用的按钮
			virtual void SetType(EToolboxBrushType eValue) = 0;
			virtual EToolboxBrushType GetType() const = 0;

			// 标题文本。
			virtual IToolboxFeatureBrushTitle* GetTitle() = 0;

			// 每个按钮的 icon path。
			virtual IToolboxFeatureBrushIcon* GetIcon() = 0;
		};
	}
	
}