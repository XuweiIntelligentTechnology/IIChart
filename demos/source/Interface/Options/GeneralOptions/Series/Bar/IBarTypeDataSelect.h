#pragma once
/***********************************************************************
 * Module:   IBarTypeDataSelect.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  单个数据的选中状态配置。
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
		* 类  名: IBarTypeDataSelect
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 单个数据的选中状态配置。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IBarTypeDataSelect
		{
		public:
			
			/*@function
			*******************************************************************
			功  能: 是否关闭高亮状态。
			参  数: <bValue>;
			返回值: <无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetDisabled(bool bValue) = 0;
			virtual bool GetDisabled() const = 0;

			/*@function
			******************************************************************
			功  能：选中时的 Label。
			参  数：<无>;
			返回值：<IBarTypeLabel*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IBarTypeLabel* GetLabel() = 0;

			/*@function
			******************************************************************
			功  能：选中时的 标签的视觉引导线配置。
			参  数：<无>;
			返回值：<IBarTypeLabelLine*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IBarTypeLabelLine* GetLabelLine() = 0;

			/*@function
			******************************************************************
			功  能：选中时的图形样式。
			参  数：<无>;
			返回值：<IBarTypeItemStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IBarTypeItemStyle* GetItemStyle() = 0;
			
		};
	}
	
}
