#pragma once
/***********************************************************************
 * Module:   IPieTypeSelect.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  选中状态。开启 selectedMode 后有效。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/ILineStyle.h"
#include "Options/GeneralOptions/Series/Pie/IPieTypeSelectLabelLine.h"
#include "Options/GeneralOptions/Series/Pie/IPieTypeSelectItemStyle.h"
#include "Options/GeneralOptions/Series/Pie/IPieTypeSelectLabel.h"

namespace IIChart
{
	namespace Pie
	{
		/*@class
		*************************************************************************
		* 类  名: IPieTypeSelect
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 饼图的选中状态。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IPieTypeSelect
		{
		public:

			/*@function
			*******************************************************************
			功  能: 是否可以被选中。在开启selectedMode的时候有效，可以用于关闭部分数据。
			参  数: <bValue>;
			返回值: <无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetDisabled(bool bValue) = 0;
			virtual bool GetDisabled() const = 0;

			/*@function
			******************************************************************
			功  能：选中时的 Label 样式。
			参  数：<无>;
			返回值：<IPieTypeSelectLabel*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IPieTypeSelectLabel* GetLabel() = 0;

			/*@function
			******************************************************************
			功  能：选中时的标签的视觉引导线配置。
			参  数：<无>;
			返回值：<IPieTypeSelectLabelLine*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IPieTypeSelectLabelLine* GetLabelLine() = 0;

			/*@function
			******************************************************************
			功  能：选中时的图形样式的配置。
			参  数：<无>;
			返回值：<IPieTypeSelectItemStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IPieTypeSelectItemStyle* GetItemStyle() = 0;
		};
	}
	
}
