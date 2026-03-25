#pragma once
/***********************************************************************
 * Module:   IScatterTypeMarkPointBlur.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  标注的淡出样式。淡出的规则跟随所在系列。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/GeneralOptions/Series/Scatter/IScatterTypeMarkPointBlurItemStyle.h"
#include "Options/GeneralOptions/Series/Scatter/IScatterTypeMarkPointBlurLabel.h"

namespace IIChart
{
	namespace Scatter
	{
		/*@class
		*************************************************************************
		* 类  名: IScatterTypeMarkPointBlur
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 标注淡出时的样式
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IScatterTypeMarkPointBlur
		{
		public:

			/*@function
			******************************************************************
			功  能：标注淡出时的标签样式。
			参  数：<无>;
			返回值：<IScatterTypeMarkPointBlurLabel*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IScatterTypeMarkPointBlurLabel* GetLabel() = 0;

			/*@function
			******************************************************************
			功  能：标注淡出时的图形样式。
			参  数：<无>;
			返回值：<IScatterTypeMarkPointBlurItemStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IScatterTypeMarkPointBlurItemStyle* GetItemStyle() = 0;
		};
	}
	
}
