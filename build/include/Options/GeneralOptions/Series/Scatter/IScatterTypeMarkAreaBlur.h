#pragma once
/***********************************************************************
 * Module:   IScatterTypeMarkAreaBlur.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  标注的淡出样式。淡出的规则跟随所在系列。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/GeneralOptions/Series/Scatter/IScatterTypeMarkAreaBlurItemStyle.h"
#include "Options/GeneralOptions/Series/Scatter/IScatterTypeMarkAreaBlurLabel.h"

namespace IIChart
{
	namespace Scatter
	{
		/*@class
		*************************************************************************
		* 类  名: IScatterTypeMarkAreaBlur
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 标域的淡出样式
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IScatterTypeMarkAreaBlur
		{
		public:

			/*@function
			******************************************************************
			功  能：标域淡出时的标签样式。
			参  数：<无>;
			返回值：<IScatterTypeMarkAreaBlurLabel*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IScatterTypeMarkAreaBlurLabel* GetLabel() = 0;

			/*@function
			******************************************************************
			功  能：标域淡出时的图形样式。
			参  数：<无>;
			返回值：<IScatterTypeMarkAreaBlurItemStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IScatterTypeMarkAreaBlurItemStyle* GetItemStyle() = 0;
		};
	}
	
}
