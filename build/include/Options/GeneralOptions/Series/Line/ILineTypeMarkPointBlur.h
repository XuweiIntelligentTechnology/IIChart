#pragma once
/***********************************************************************
 * Module:   ILineTypeMarkPointBlur.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  标注的淡出样式。淡出的规则跟随所在系列。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/GeneralOptions/Series/Line/ILineTypeBlurItemStyle.h"
#include "Options/GeneralOptions/Series/Line/ILineTypeLabel.h"

namespace IIChart
{
	namespace Line
	{
		/*@class
		*************************************************************************
		* 类  名: ILineTypeMarkPointBlur
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 标注的淡出样式
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class ILineTypeMarkPointBlur 
		{
		public:
			/*@function
			******************************************************************
			功  能：标注淡出时的 Label 样式。
			参  数：<无>;
			返回值：<ILineTypeLabel*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILineTypeLabel* GetLabel() = 0;

			/*@function
			******************************************************************
			功  能：标注淡出时的样式。
			参  数：<无>;
			返回值：<ILineTypeBlurItemStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILineTypeBlurItemStyle* GetItemStyle() = 0;
		};
	}
	
}
