#pragma once
/***********************************************************************
 * Module:   IScatterTypeMarkLineBlur.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  标注的淡出样式。淡出的规则跟随所在系列。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/GeneralOptions/Series/Scatter/IScatterTypeMarkLineBlurLineStyle.h"
#include "Options/GeneralOptions/Series/Scatter/IScatterTypeMarkLineBlurLabel.h"

namespace IIChart
{
	namespace Scatter
	{
		/*@class
		*************************************************************************
		* 类  名: IScatterTypeMarkLineBlur
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 标线的淡出样式
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IScatterTypeMarkLineBlur
		{
		public:

			/*@function
			******************************************************************
			功  能：标线淡出时的标签样式。
			参  数：<无>;
			返回值：<IScatterTypeMarkLineBlurLabel*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IScatterTypeMarkLineBlurLabel* GetLabel() = 0;

			/*@function
			******************************************************************
			功  能：标线淡出时的线条样式。
			参  数：<无>;
			返回值：<IScatterTypeMarkLineBlurLineStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IScatterTypeMarkLineBlurLineStyle* GetLineStyle() = 0;
		};
	}
	
}
