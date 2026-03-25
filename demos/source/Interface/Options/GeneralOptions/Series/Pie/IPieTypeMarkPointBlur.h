#pragma once
/***********************************************************************
 * Module:   IPieTypeMarkPointBlur.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  标注的淡出样式。淡出的规则跟随所在系列。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/GeneralOptions/Series/Pie/IPieTypeMarkPointItemStyle.h"
#include "Options/GeneralOptions/Series/Pie/IPieTypeMarkPointLabel.h"

namespace IIChart
{
	namespace Pie
	{
		/*@class
		*************************************************************************
		* 类  名: IPieTypeMarkPointBlur
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 标注的淡出样式
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IPieTypeMarkPointBlur
		{
		public:

			/*@function
			******************************************************************
			功  能：标注的 Label。
			参  数：<无>;
			返回值：<IPieTypeMarkPointLabel*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IPieTypeMarkPointLabel* GetLabel() = 0;

			/*@function
			******************************************************************
			功  能：标注的图形样式。
			参  数：<无>;
			返回值：<IPieTypeMarkPointItemStyle*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IPieTypeMarkPointItemStyle* GetItemStyle() = 0;
		};
	}
	
}
