#pragma once
/***********************************************************************
 * Module:   ILineTypeBlur.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  饼图的淡出状态
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/ILineStyle.h"
#include "Options/GeneralOptions/Series/Pie/IPieTypeBlurLabelLine.h"
#include "Options/GeneralOptions/Series/Pie/IPieTypeBlurItemStyle.h"
#include "Options/GeneralOptions/Series/Pie/IPieTypeBlurLabel.h"

namespace IIChart
{
	namespace Pie
	{
		/*@class
		*************************************************************************
		* 类  名: IPieTypeBlur
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 饼图的淡出状态
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IPieTypeBlur
		{
		public:
			/*@function
			******************************************************************
			功  能：饼图的淡出时的 Label。
			参  数：<无>;
			返回值：<IPieTypeBlurLabel*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IPieTypeBlurLabel* GetLabel() = 0;

			/*@function
			******************************************************************
			功  能：饼图的淡出时的视觉引导线配置。
			参  数：<无>;
			返回值：<IPieTypeBlurLabelLine*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IPieTypeBlurLabelLine* GetLabelLine() = 0;

			/*@function
			******************************************************************
			功  能：饼图的淡出时的图形样式
			参  数：<无>;
			返回值：<IPieTypeBlurItemStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IPieTypeBlurItemStyle* GetItemStyle() = 0;
			
		};
	}
	
}
