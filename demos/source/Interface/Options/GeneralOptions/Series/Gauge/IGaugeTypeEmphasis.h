#pragma once
/***********************************************************************
 * Module:  IGaugeTypeAnchor.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: 高亮的仪表盘指针样式
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/IHandle.h"
#include "Options/Common/IShadowStyle.h"
#include "Options/GeneralOptions/Series/Gauge/IGaugeTypeItemStyle.h"

namespace IIChart
{
	namespace Gauge
	{
		/*@class
		*************************************************************************
		* 类  名: IGaugeTypeEmphasis
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 高亮的仪表盘指针样式。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IGaugeTypeEmphasis
		{
		public:

			/*@function
			******************************************************************
			功  能：是否关闭高亮状态
			说  明：关闭高亮状态可以在鼠标移到图形上，tooltip 触发，或者图例联动的时候
			        不再触发高亮效果。在图形非常多的时候可以关闭以提升交互流畅性。
			参  数：<nValue>;
			返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetDisabled(bool bValue) = 0;
			virtual bool GetDisabled() const = 0;

			/*@function
			******************************************************************
			功  能：高亮的仪表盘指针样式
			参  数：<无>;
			返回值：<IGaugeTypeItemStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IGaugeTypeItemStyle* GetItemStyle() = 0;
		};
	}
	
}
