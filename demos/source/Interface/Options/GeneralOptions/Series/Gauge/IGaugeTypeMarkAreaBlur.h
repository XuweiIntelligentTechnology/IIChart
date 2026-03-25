#pragma once
/***********************************************************************
 * Module:   IGaugeTypeMarkAreaBlur.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  标域的淡出样式。淡出的规则跟随所在系列。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/GeneralOptions/Series/Gauge/IGaugeTypeItemStyle.h"
#include "Options/GeneralOptions/Series/Gauge/IGaugeTypeMarkAreaLabel.h"

namespace IIChart
{
	namespace Gauge
	{
		/*@class
		*************************************************************************
		* 类  名: IGaugeTypeMarkAreaBlur
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 标域的淡出样式。淡出的规则跟随所在系列。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IGaugeTypeMarkAreaBlur
		{
		public:

			/*@function
			*******************************************************************
			 功  能：标域淡出时标签的样式
			 参  数：<无>;
			 返回值：<IGaugeTypeMarkAreaLabel*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IGaugeTypeMarkAreaLabel* GetLabel() = 0;

			/*@function
			*******************************************************************
			 功  能：标域淡出时的图形样式
			 参  数：<无>;
			 返回值：<IGaugeTypeItemStyle*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IGaugeTypeItemStyle* GetItemStyle() = 0;
		};
	}
	
}
