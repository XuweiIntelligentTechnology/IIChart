#pragma once
/***********************************************************************
 * Module:  ILineTypeTooltip.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: 本系列特定的 tooltip 设定。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/IBaseArrayElement.h"
#include "Options/Common/ITextStyle.h"
#include "Options/GeneralOptions/Geo/IGeoTooltipTextStyle.h"

namespace IIChart
{
	namespace Geo
	{
		
		class IGeoTooltip
		{
		public:

			// TODO: position

			// TODO: formatter

			// TODO: valueFormatter

			// 以16进制字符串形式设置提示框浮层的背景颜色。
			virtual void SetBackgroundColor(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetBackgroundColor() const = 0;

			// 提示框浮层的背景颜色。
			virtual void SetBackgroundColor(int nR, int nG, int nB, float nTransparent) = 0;
			virtual void GetBackgroundColor(int* pnR, int* pnG, int* pnB, float* pnTransparent) = 0;

			// 以16进制字符串形式设置提示框浮层的背景颜色。
			virtual void SetBorderColor(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetBorderColor() const = 0;

			// 提示框浮层的边框颜色;
			virtual void SetBorderColor(int nR, int nG, int nB, float nTransparent) = 0;
			virtual void GetBorderColor(int* pnR, int* pnG, int* pnB, float* pnTransparent) = 0;

			// 提示框浮层的边框宽;
			virtual void SetBorderWidth(int nValue) = 0;
			virtual int  GetBorderWidth() const = 0;

			// 提示框浮层内边距，单位px，默认各方向内边距为5，接受数组分别设定上右下左边距。
			virtual int  SetPadding(int* nValue, int nCount) = 0;
			virtual void GetPadding(int* pnValue, int* pnCount) = 0;

			// 提示框浮层的文本样式;
			virtual IGeoTooltipTextStyle* GetTextStyle() = 0;

			// 额外附加到浮层的 css 样式。如下为浮层添加阴影的示例：
			// extraCssText: 'box-shadow: 0 0 3px rgba(0, 0, 0, 0.3);'
			// 注意：series.tooltip 仅在 tooltip.trigger 为 'item' 时有效。
			virtual void SetExtraCssText(const wchar_t* wzValeu) = 0;
			virtual wchar_t* GetExtraCssText() const = 0;
		};
	}
	
}