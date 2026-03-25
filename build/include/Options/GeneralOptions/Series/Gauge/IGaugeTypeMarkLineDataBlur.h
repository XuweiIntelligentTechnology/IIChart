#pragma once
/***********************************************************************
 * Module:   IGaugeTypeMarkLineDataBlur.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  标线数据的淡出样式。淡出的规则跟随所在系列。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/GeneralOptions/Series/Gauge/IGaugeTypeMarkLineDataLineStyle.h"
#include "Options/GeneralOptions/Series/Gauge/IGaugeTypeLabel.h"

namespace IIChart
{
	namespace Gauge
	{
		/*@class
		*************************************************************************
		* 类  名: IGaugeTypeMarkLineDataBlur
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 标线数据的淡出样式。淡出的规则跟随所在系列。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IGaugeTypeMarkLineDataBlur
		{
		public:

			/*@function
			*******************************************************************
			 功  能：标线数据淡出时线条的样式
			 参  数：<无>;
			 返回值：<IGaugeTypeMarkLineDataLineStyle*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IGaugeTypeMarkLineDataLineStyle* GetLineStyle() = 0;

			/*@function
			*******************************************************************
			 功  能：标线数据淡出时标签的样式
			 参  数：<无>;
			 返回值：<IGaugeTypeLabel*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IGaugeTypeLabel* GetLabel() = 0;
		};
	}
	
}
