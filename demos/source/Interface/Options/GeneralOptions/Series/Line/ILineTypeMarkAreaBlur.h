#pragma once
/***********************************************************************
 * Module:   ILineTypeMarkAreaBlur.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  标注的淡出样式。淡出的规则跟随所在系列。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/GeneralOptions/Series/Line/ILineTypeEmphasisItemStyle.h"
#include "Options/GeneralOptions/Series/Line/ILineTypeMarkAreaLabel.h"

namespace IIChart
{
	namespace Line
	{
		/*@class
		*************************************************************************
		* 类  名: ILineTypeMarkAreaBlur
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 淡出时的标域样式。淡出的规则跟随所在系列。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class ILineTypeMarkAreaBlur
		{
		public:

			/*@function
			******************************************************************
			功  能：淡出时标域文本配置。
			参  数：<无>;
			返回值：<ILineTypeMarkAreaLabel*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILineTypeMarkAreaLabel* GetLabel() = 0;

			/*@function
			******************************************************************
			功  能：淡出时该标域的样式。
			参  数：<无>;
			返回值：<ILineTypeMarkAreaItemStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILineTypeEmphasisItemStyle* GetItemStyle() = 0;
		};
	}
	
}
