#pragma once
/***********************************************************************
 * Module:   IScatterTypeBlur.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  淡出样式
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/ILineStyle.h"
#include "Options/GeneralOptions/Series/Scatter/IScatterTypeBlurLabelLine.h"
#include "Options/GeneralOptions/Series/Scatter/IScatterTypeBlurItemStyle.h"
#include "Options/GeneralOptions/Series/Scatter/IScatterTypeBlurLabel.h"

namespace IIChart
{
	namespace Scatter
	{
		/*@class
		*************************************************************************
		* 类  名: IScatterTypeBlur
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 淡出样式
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IScatterTypeBlur
		{
		public:

			/*@function
			******************************************************************
			功  能：淡出时的标签样式。
			参  数：<无>;
			返回值：<IScatterTypeBlurLabel*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IScatterTypeBlurLabel* GetLabel() = 0;

			/*@function
			******************************************************************
			功  能：淡出时的标签的视觉引导线配置。
			参  数：<无>;
			返回值：<IScatterTypeBlurLabelLine*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IScatterTypeBlurLabelLine* GetLabelLine() = 0;

			/*@function
			******************************************************************
			功  能：淡出时的图形样式。
			参  数：<无>;
			返回值：<IScatterTypeBlurItemStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IScatterTypeBlurItemStyle* GetItemStyle() = 0;
			
		};
	}
	
}
