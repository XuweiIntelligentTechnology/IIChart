#pragma once
/***********************************************************************
 * Module:   ISunburstTypeSelect.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  选中状态配置。开启 selectedMode 后有效。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/ILineStyle.h"
#include "Options/GeneralOptions/Series/Sunburst/ISunburstTypeLabel.h"
#include "Options/GeneralOptions/Series/Sunburst/ISunburstTypeLabelLine.h"
#include "Options/GeneralOptions/Series/Sunburst/ISunburstTypeItemStyle.h"


namespace IIChart
{
	namespace Sunburst
	{
		/*@class
		*************************************************************************
		* 类  名: ISunburstTypeSelect
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 旭日图的选中状态。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class ISunburstTypeSelect
		{
		public:

			/*@function
			******************************************************************
			功  能：旭日图的选中时的文本标签的样式。
			参  数：<无>;
			返回值：<ISunburstTypeLabel*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ISunburstTypeLabel* GetLabel() = 0;

			/*@function
			******************************************************************
			功  能：旭日图的选中时标签的视觉引导线配置
			参  数：<无>;
			返回值：<ISunburstTypeLabelLine*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ISunburstTypeLabelLine* GetLabelLine() = 0;

			/*@function
			******************************************************************
			功  能：旭日图的选中时的旭日图扇形块的样式。
			参  数：<无>;
			返回值：<ISunburstTypeItemStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ISunburstTypeItemStyle* GetItemStyle() = 0;
		};
	}
	
}
