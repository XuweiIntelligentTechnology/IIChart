#pragma once
/***********************************************************************
 * Module:   IBarTypeBlur.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  淡出时的图形样式和标签样式。开启 emphasis.focus 后有效。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/ILineStyle.h"
#include "Options/GeneralOptions/Series/Bar/IBarTypeLabel.h"
#include "Options/GeneralOptions/Series/Bar/IBarTypeBlurLabelLine.h"
#include "Options/GeneralOptions/Series/Bar/IBarTypeBlurItemStyle.h"


namespace IIChart
{
	namespace Bar
	{
		/*@class
		*************************************************************************
		* 类  名: IBarTypeBlur
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 淡出时的图形样式和标签样式。开启 emphasis.focus 后有效。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IBarTypeBlur
		{
		public:

			/*@function
			******************************************************************
			功  能：图形上的文本标签，可用于说明图形的一些数据信息，比如值，名称等。
			参  数：<无>;
			返回值：<IBarTypeLabel*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IBarTypeLabel* GetLabel() = 0;

			/*@function
			******************************************************************
			功  能：淡出时的 标签的视觉引导线配置。
			参  数：<无>;
			返回值：<IBarTypeBlurLabelLine*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IBarTypeBlurLabelLine* GetLabelLine() = 0;

			/*@function
			******************************************************************
			功  能：淡出时的图形样式
			参  数：<无>;
			返回值：<IBarTypeBlurItemStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IBarTypeBlurItemStyle* GetItemStyle() = 0;
			
		};
	}
	
}
