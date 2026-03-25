#pragma once
/***********************************************************************
 * Module:   IPieTypeMarkAreaBlur.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  标注的淡出样式。淡出的规则跟随所在系列。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/GeneralOptions/Series/Pie/IPieTypeMarkAreaItemStyle.h"
#include "Options/GeneralOptions/Series/Pie/IPieTypeMarkAreaLabel.h"

namespace IIChart
{
	namespace Pie
	{
		/*@class
		*************************************************************************
		* 类  名: IPieTypeMarkAreaBlur
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 图表标域淡出的样式。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IPieTypeMarkAreaBlur
		{
		public:

			/*@function
			******************************************************************
			功  能：图表标域淡出的Label样式
			参  数：<无>;
			返回值：<IPieTypeMarkAreaLabel*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IPieTypeMarkAreaLabel* GetLabel() = 0;

			/*@function
			******************************************************************
			功  能：图表标域淡出的样式
			参  数：<无>;
			返回值：<IPieTypeMarkAreaItemStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IPieTypeMarkAreaItemStyle* GetItemStyle() = 0;
		};
	}
	
}
