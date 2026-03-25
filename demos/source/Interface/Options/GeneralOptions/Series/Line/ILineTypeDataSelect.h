#pragma once
/***********************************************************************
 * Module:   ILineTypeDataSelect.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  单个拐点的选中样式和标签设置。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/ILineStyle.h"
#include "Options/GeneralOptions/Series/Line/ILineTypeDataItemStyle.h"
#include "Options/GeneralOptions/Series/Line/ILineTypeDataLabel.h"

namespace IIChart
{
	namespace Line
	{
		/*@class
		*************************************************************************
		* 类  名: ILineTypeDataSelect
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 单个拐点的选中样式和标签设置。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class ILineTypeDataSelect
		{
		public:
			/*@function
			*******************************************************************
			功  能: 是否可以被选中。
			注  意：在开启selectedMode的时候有效，可以用于关闭部分数据。
			参  数: <bValue>;
			返回值: <无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetDisabled(bool bValue) = 0;
			virtual bool GetDisabled() const = 0;

			/*@function
			*******************************************************************
			功  能: 单个拐点选中时标签的样式设置
			参  数: <无>;
			返回值: <ILineTypeDataLabel*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILineTypeDataLabel* GetLabel() = 0;

			/*@function
			*******************************************************************
			功  能: 单个拐点标志选中时的样式设置
			参  数: <无>;
			返回值: <ILineTypeDataItemStyle*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILineTypeDataItemStyle* GetItemStyle() = 0;
			
		};
	}
	
}
