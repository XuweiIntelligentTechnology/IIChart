#pragma once
/***********************************************************************
 * Module:   IPieTypeDataSelect.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  饼图单个数据项的选中状态。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/ILineStyle.h"
#include "Options/GeneralOptions/Series/Pie/IPieTypeDataLabel.h"
#include "Options/GeneralOptions/Series/Pie/IPieTypeDataSelectLabelLine.h"
#include "Options/GeneralOptions/Series/Pie/IPieTypeDataSelectItemStyle.h"

namespace IIChart
{
	namespace Pie
	{
		/*@class
		*************************************************************************
		* 类  名: IPieTypeDataSelect
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 饼图单个数据项的选中状态。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IPieTypeDataSelect
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
			功  能：单个数据项选中时的标签样式。
			参  数：<无>;
			返回值：<IPieTypeDataLabel*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IPieTypeDataLabel* GetLabel() = 0;

			/*@function
			******************************************************************
			功  能：单个数据项选中时的标签的视觉引导线配置。
			参  数：<无>;
			返回值：<IPieTypeDataSelectLabelLine*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IPieTypeDataSelectLabelLine* GetLabelLine() = 0;

			/*@function
			******************************************************************
			功  能：单个数据项选中时的数据项的样式。
			参  数：<无>;
			返回值：<IPieTypeDataSelectItemStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IPieTypeDataSelectItemStyle* GetItemStyle() = 0;
			
		};
	}
	
}
