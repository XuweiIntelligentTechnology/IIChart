#pragma once
/***********************************************************************
 * Module:   IScatterTypeSelect.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  选中状态。开启 selectedMode 后有效。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/ILineStyle.h"
#include "Options/GeneralOptions/Series/Scatter/IScatterTypeSelectLabelLine.h"
#include "Options/GeneralOptions/Series/Scatter/IScatterTypeSelectItemStyle.h"
#include "Options/GeneralOptions/Series/Scatter/IScatterTypeSelectLabel.h"

namespace IIChart
{
	namespace Scatter
	{
		/*@class
		*************************************************************************
		* 类  名: IScatterTypeSelect
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 气泡图的选中状态。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IScatterTypeSelect
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
			功  能：气泡图的选中时的标签样式。
			参  数：<无>;
			返回值：<IScatterTypeSelectLabel*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IScatterTypeSelectLabel* GetLabel() = 0;

			/*@function
			******************************************************************
			功  能：气泡图的选中时视觉引导线配置。
			参  数：<无>;
			返回值：<IScatterTypeSelectLabelLine*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IScatterTypeSelectLabelLine* GetLabelLine() = 0;

			/*@function
			******************************************************************
			功  能：气泡图的选中时的图形样式。
			参  数：<无>;
			返回值：<IScatterTypeSelectItemStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IScatterTypeSelectItemStyle* GetItemStyle() = 0;
		};
	}
	
}
