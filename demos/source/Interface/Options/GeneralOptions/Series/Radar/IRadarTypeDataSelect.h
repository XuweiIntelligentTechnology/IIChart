#pragma once
/***********************************************************************
 * Module:   IPieTypeDataSelect.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  雷达图单个数据项的选中状态。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/ILineStyle.h"
#include "Options/GeneralOptions/Series/Radar/IRadarTypeDataLabel.h"
#include "Options/GeneralOptions/Series/Radar/IRadarTypeDataItemStyle.h"
#include "Options/GeneralOptions/Series/Radar/IRadarTypeDataAreaStyle.h"


namespace IIChart
{
	namespace Radar
	{
		/*@class
		*************************************************************************
		* 类  名: IRadarTypeDataSelect
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 雷达图单个数据项的选中状态。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IRadarTypeDataSelect
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
			功  能：雷达图单个数据项选中时的标签样式。
			参  数：<无>;
			返回值：<IRadarTypeDataLabel*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IRadarTypeDataLabel* GetLabel() = 0;

			/*@function
			******************************************************************
			功  能：雷达图单个数据项选中时的图形样式。
			参  数：<无>;
			返回值：<IRadarTypeDataItemStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IRadarTypeDataItemStyle* GetItemStyle() = 0;

			/*@function
			******************************************************************
			功  能：雷达图单个数据项选中时的线条样式。
			参  数：<无>;
			返回值：<ILineStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILineStyle* GetLineStyle() = 0;

			/*@function
			******************************************************************
			功  能：雷达图单个数据项选中时的区域样式。
			参  数：<无>;
			返回值：<IRadarTypeDataAreaStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IRadarTypeDataAreaStyle* GetAreaStyle() = 0;
			
		};
	}
	
}
