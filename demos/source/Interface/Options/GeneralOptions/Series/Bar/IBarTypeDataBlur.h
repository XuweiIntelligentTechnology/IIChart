#pragma once
/***********************************************************************
 * Module:   ILineTypeDataBlur.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  单个数据的淡出状态配置。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/ILineStyle.h"
#include "Options/GeneralOptions/Series/Bar/IBarTypeItemStyle.h"
#include "Options/GeneralOptions/Series/Bar/IBarTypeLabel.h"
#include "Options/GeneralOptions/Series/Bar/IBarTypeLabelLine.h"

namespace IIChart
{
	namespace Bar
	{
		/*@class
		*************************************************************************
		* 类  名: IBarTypeDataBlur
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 单个数据的淡出状态配置。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IBarTypeDataBlur
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
			功  能：标签的视觉引导线配置。
			参  数：<无>;
			返回值：<IBarTypeLabelLine*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IBarTypeLabelLine* GetLabelLine() = 0;

			/*@function
			******************************************************************
			功  能：图形样式设置。
			参  数：<无>;
			返回值：<IBarTypeItemStyle*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IBarTypeItemStyle* GetItemStyle() = 0;
			
		};
	}
	
}
