#pragma once
/***********************************************************************
 * Module:   IPieTypeDataBlur.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  饼图单个数据项的淡出状态。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/ILineStyle.h"
#include "Options/GeneralOptions/Series/Pie/IPieTypeDataLabel.h"
#include "Options/GeneralOptions/Series/Pie/IPieTypeDataBlurLabelLine.h"
#include "Options/GeneralOptions/Series/Pie/IPieTypeDataBlurItemStyle.h"


namespace IIChart
{
	namespace Pie
	{
		/*@class
		*************************************************************************
		* 类  名: IPieTypeDataBlur
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 饼图单个数据项的淡出状态
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IPieTypeDataBlur
		{
		public:
			/*@function
			******************************************************************
			功  能：饼图单个数据项的淡出时的 Label。
			参  数：<无>;
			返回值：<IPieTypeDataLabel*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IPieTypeDataLabel* GetLabel() = 0;

			/*@function
			******************************************************************
			功  能：饼图单个数据项淡出时的视觉引导线配置。
			参  数：<无>;
			返回值：<IPieTypeDataBlurLabelLine*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IPieTypeDataBlurLabelLine* GetLabelLine() = 0;

			/*@function
			******************************************************************
			功  能：饼图单个数据项淡出时的图形的样式。
			参  数：<无>;
			返回值：<IPieTypeDataBlurItemStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IPieTypeDataBlurItemStyle* GetItemStyle() = 0;
			
		};
	}
	
}
