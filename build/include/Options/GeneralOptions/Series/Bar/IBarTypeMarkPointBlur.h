#pragma once
/***********************************************************************
 * Module:   IBarTypeMarkPointBlur.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  标注的淡出样式。淡出的规则跟随所在系列。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/GeneralOptions/Series/Bar/IBarTypeLabel.h"
#include "Options/GeneralOptions/Series/Bar/IBarTypeMarkPointItemStyle.h"


namespace IIChart
{
	namespace Bar
	{
		/*@class
		*************************************************************************
		* 类  名: IBarTypeMarkPointBlur
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 标注的淡出样式
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IBarTypeMarkPointBlur
		{
		public:

			/*@function
			******************************************************************
			功  能：标注淡出时的标签样式。
			参  数：<无>;
			返回值：<IBarTypeLabel*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IBarTypeLabel* GetLabel() = 0;

			/*@function
			******************************************************************
			功  能：标注淡出时的图形样式。
			参  数：<无>;
			返回值：<IBarTypeMarkPointItemStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IBarTypeMarkPointItemStyle* GetItemStyle() = 0;
		};
	}
	
}
