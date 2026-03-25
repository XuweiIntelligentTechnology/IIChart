#pragma once
/***********************************************************************
 * Module:   IBarTypeMarkLineBlur.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  标线的淡出样式。淡出的规则跟随所在系列。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/GeneralOptions/Series/Bar/IBarTypeMarkLineLabel.h"
#include "Options/GeneralOptions/Series/Bar/IBarTypeMarkLineLineStyle.h"

namespace IIChart
{
	namespace Bar
	{
		/*@class
		*************************************************************************
		* 类  名: IBarTypeMarkLineBlur
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 淡出样式
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IBarTypeMarkLineBlur
		{
		public:

			/*@function
			******************************************************************
			功  能：淡出时的标签样式。
			参  数：<无>;
			返回值：<IBarTypeMarkLineLabel*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IBarTypeMarkLineLabel* GetLabel() = 0;

			/*@function
			******************************************************************
			功  能：标注淡出时的线条样式。
			参  数：<无>;
			返回值：<IBarTypeMarkLineLineStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IBarTypeMarkLineLineStyle* GetItemStyle() = 0;
		};
	}
	
}
