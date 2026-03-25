#pragma once
/***********************************************************************
 * Module:   IPieTypeMarkLineBlur.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  标注的淡出样式。淡出的规则跟随所在系列。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/GeneralOptions/Series/Pie/IPieTypeMarkLineLineStyle.h"
#include "Options/GeneralOptions/Series/Pie/IPieTypeMarkLineLabel.h"

namespace IIChart
{
	namespace Pie
	{
		/*@class
		*************************************************************************
		* 类  名: IPieTypeMarkLineBlur
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 标线淡出时的样式。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IPieTypeMarkLineBlur
		{
		public:

			/*@function
			******************************************************************
			功  能：标线淡出时的Label的样式 。
			参  数：<无>;
			返回值：<IPieTypeMarkLineDataLineStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IPieTypeMarkLineLabel* GetLabel() = 0;

			/*@function
			******************************************************************
			功  能：标线淡出时的线的样式 。
			参  数：<无>;
			返回值：<IPieTypeMarkLineDataLineStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IPieTypeMarkLineLineStyle* GetLineStyle() = 0;
		};
	}
	
}
