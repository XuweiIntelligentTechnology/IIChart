#pragma once
/***********************************************************************
 * Module:   IBarTypeMarkAreaBlur.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  标注的淡出样式。淡出的规则跟随所在系列。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/GeneralOptions/Series/Bar/IBarTypeMarkAreaItemStyle.h"
#include "Options/GeneralOptions/Series/Bar/IBarTypeMarkAreaLabel.h"

namespace IIChart
{
	namespace Bar
	{

		/*@class
		*************************************************************************
		* 类  名: IBarTypeMarkAreaBlur
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 淡出的标域样式。淡出的规则跟随所在系列。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IBarTypeMarkAreaBlur
		{
		public:

			/*@function
			******************************************************************
			功  能：标域文本配置。
			参  数：<无>;
			返回值：<IBarTypeMarkAreaLabel*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IBarTypeMarkAreaLabel* GetLabel() = 0;

			/*@function
			******************************************************************
			功  能：该标域的样式。
			参  数：<无>;
			返回值：<IBarTypeMarkAreaItemStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IBarTypeMarkAreaItemStyle* GetItemStyle() = 0;
		};
	}
	
}
