#pragma once
/***********************************************************************
 * Module:   IPieTypeMarkLineDataBlur.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  标注的淡出样式。淡出的规则跟随所在系列。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/GeneralOptions/Series/Pie/IPieTypeMarkAreaDataItemStyle.h"
#include "Options/GeneralOptions/Series/Pie/IPieTypeMarkAreaDataLabel.h"

namespace IIChart
{
	namespace Pie
	{
		/*@class
		*************************************************************************
		* 类  名: IPieTypeMarkAreaDataBlur
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 图表标域数据项淡出的样式。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IPieTypeMarkAreaDataBlur
		{
		public:
			/*@function
			******************************************************************
			功  能：图表标域数据项淡出时的图形样式
			参  数：<无>;
			返回值：<IPieTypeMarkAreaDataItemStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IPieTypeMarkAreaDataItemStyle* GetItemStyle() = 0;

			/*@function
			******************************************************************
			功  能：图表标域数据项淡出时的标签样式
			参  数：<无>;
			返回值：<IPieTypeMarkAreaDataLabel*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IPieTypeMarkAreaDataLabel* GetLabel() = 0;
			
		};
	}
	
}
