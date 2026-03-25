#pragma once
/***********************************************************************
 * Module:  ISunburstLevel.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: 旭日图（Sunburst）
 
	旭日图是一种有层次的结构，为了方便同一层样式的配置，我们提供了 levels 配置项。
	它是一个数组，其中的第 0 项表示数据下钻后返回上级的图形，其后的每一项分别表示从圆心向外层的层级。

    例如，假设我们没有数据下钻功能，并且希望将最内层的扇形块的颜色设为红色，文字设为蓝色，可以这样设置：
	series: {
		// ...
		levels: [
			{
				// 留给数据下钻点的空白配置
			},
			{
				// 最靠内测的第一层
				itemStyle: {
					color: 'red'
				},
				label: {
					color: 'blue'
				}
			},
			{
				// 第二层 ...
			}
		]
	}
 ***********************************************************************/
#include "Options/Common/IBaseArrayElement.h"
#include "Options/GeneralOptions/Series/Sunburst/ISunburstTypeLabel.h"
#include "Options/GeneralOptions/Series/Sunburst/ISunburstTypeLabelLine.h"
#include "Options/GeneralOptions/Series/Sunburst/ISunburstTypeItemStyle.h"
#include "Options/GeneralOptions/Series/Sunburst/ISunburstTypeLevelEmphasis.h"
#include "Options/GeneralOptions/Series/Sunburst/ISunburstTypeBlur.h"
#include "Options/GeneralOptions/Series/Sunburst/ISunburstTypeSelect.h"

namespace IIChart
{
	namespace Sunburst
	{
		/*@class
		*************************************************************************
		* 类  名: ISunburstTypeLevel
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 多层配置。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class ISunburstTypeLevel : virtual public IBaseArrayElement
		{
		public:

			/*@function
			******************************************************************
			功  能：当前层的内半径和外半径，注意其它层的内外半径不会因为该层的改变自适应。
			参  数：<nValue>;
			        <bIsPercentage> 为true时 nVlaue为百分比的值;
			返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetRadius(int nValue, bool bIsPercentage) = 0;
			virtual void GetRadius(int* pnValue, bool* pbIsPercentage) = 0;

			/*@function
			******************************************************************
			功  能：当前层的内半径和外半径，数组的第一项是内半径，第二项是外半径。
			参  数：<nInner> 内半径;
			        <nOutter> 外半径;
					<bIsPercentage> 为true时 nVlaue为百分比的值;
			返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetRadius(int nInner, int nOutter, bool bIsPercent) = 0;
			virtual void GetRadius(int* pnInner, int* pnOutter, bool* pbIsPercent) = 0;

			/*@function
			******************************************************************
			* 功  能：描述了每个扇形块中，文本标签的样式。
			* 参  数：<无>;
			* 返回值：<ISunburstTypeLabel*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ISunburstTypeLabel* GetLabel() = 0;

			/*@function
			******************************************************************
			* 功  能：标签的视觉引导线配置。
			* 注  意：该配置项是在每个系列默认的标签布局基础上，统一调整标签的(x, y)位置，
			*         标签对齐等属性以实现想要的标签布局效果。
			* 参  数：<无>;
			* 返回值：<ISunburstTypeLabelLine*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ISunburstTypeLabelLine* GetLabelLine() = 0;

			/*@function
			******************************************************************
			* 功  能：旭日图扇形块的样式。
			* 参  数：<无>;
			* 返回值：<ISunburstTypeItemStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ISunburstTypeItemStyle* GetItemStyle() = 0;


			/*@function
			******************************************************************
			* 功  能：高亮状态配置。
			* 参  数：<无>;
			* 返回值：<ISunburstTypeLevelEmphasis*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ISunburstTypeLevelEmphasis* GetEmphasis() = 0;

			/*@function
			******************************************************************
			* 功  能：淡出状态配置。开启 emphasis.focus 后有效。
			* 参  数：<无>;
			* 返回值：<ISunburstTypeBlur*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ISunburstTypeBlur* GetBlur() = 0;

			/*@function
			******************************************************************
			* 功  能：选中状态配置。开启 selectedMode 后有效。
			* 参  数：<无>;
			* 返回值：<ISunburstTypeSelect*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ISunburstTypeSelect* GetSelect() = 0;

		};
	}

	
}
