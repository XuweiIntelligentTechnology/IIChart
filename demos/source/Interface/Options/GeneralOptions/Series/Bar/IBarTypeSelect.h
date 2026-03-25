#pragma once
/***********************************************************************
 * Module:   IBarTypeSelect.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  数据选中时的图形样式和标签样式。开启 selectedMode 后有效。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/ILineStyle.h"
#include "Options/GeneralOptions/Series/Bar/IBarTypeLabel.h"
#include "Options/GeneralOptions/Series/Bar/IBarTypeSelectLabelLine.h"
#include "Options/GeneralOptions/Series/Bar/IBarTypeSelectItemStyle.h"

namespace IIChart
{
	namespace Bar
	{
		/*@class
		*************************************************************************
		* 类  名: IBarTypeSelect
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 数据选中时的图形样式和标签样式。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IBarTypeSelect
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
			返回值：<IBarTypeSelectLabelLine*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IBarTypeSelectLabelLine* GetLabelLine() = 0;

			/*@function
			******************************************************************
			功  能：选中时的图形样式。
			参  数：<无>;
			返回值：<IBarTypeSelectItemStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IBarTypeSelectItemStyle* GetItemStyle() = 0;
		};
	}
	
}
