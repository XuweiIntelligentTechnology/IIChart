#pragma once
/***********************************************************************
 * Module:   ILineTypeMarkLineBlur.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  图表标线淡出时的样式。淡出的规则跟随所在系列。
 ***********************************************************************/
#include "Options/GeneralOptions/Series/Line/ILineTypeMarkLineLineStyle.h"
#include "Options/GeneralOptions/Series/Line/ILineTypeMarkLineLabel.h"

namespace IIChart
{
	namespace Line
	{
		/*@class
		*************************************************************************
		* 类  名: ILineTypeMarkLineBlur
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 图表标线淡出时的样式。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class ILineTypeMarkLineBlur
		{
		public:

			/*@function
			******************************************************************
			功  能：图表标线文本配置。
			参  数：<无>;
			返回值：<ILineTypeMarkLineLabel*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILineTypeMarkLineLabel* GetLabel() = 0;

			/*@function
			******************************************************************
			功  能：该图表标线的样式。
			参  数：<无>;
			返回值：<ILineTypeMarkLineLineStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILineTypeMarkLineLineStyle* GetLineStyle() = 0;
		};
	}
	
}
