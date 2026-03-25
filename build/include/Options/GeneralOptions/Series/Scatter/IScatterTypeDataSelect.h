#pragma once
/***********************************************************************
 * Module:   IScatterTypeDataSelect.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  单个数据项选中时的样式配置。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/ILineStyle.h"
#include "Options/GeneralOptions/Series/Scatter/IScatterTypeDataItemStyle.h"
#include "Options/GeneralOptions/Series/Scatter/IScatterTypeDataLabel.h"

namespace IIChart
{
	namespace Scatter
	{
		/*@class
		*************************************************************************
		* 类  名: IScatterTypeDataSelect
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 单个数据项选中时的样式配置。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IScatterTypeDataSelect
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
			功  能：单个数据项的标签样式。
			参  数：<无>;
			返回值：<IScatterTypeDataLabel*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IScatterTypeDataLabel* GetLabel() = 0;

			/*@function
			******************************************************************
			功  能：单个数据项的图形样式。
			参  数：<无>;
			返回值：<IScatterTypeDataItemStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IScatterTypeDataItemStyle* GetItemStyle() = 0;
			
		};
	}
	
}
