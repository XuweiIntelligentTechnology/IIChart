#pragma once
/***********************************************************************
 * Module:   IScatterTypeDataBlur.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  单个数据项的淡出样式和标签设置。
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
		* 类  名: IScatterTypeDataBlur
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 单个数据项的淡出样式和标签设置
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IScatterTypeDataBlur
		{
		public:

			/*@function
			******************************************************************
			功  能：数据淡出时的标签样式。
			参  数：<无>;
			返回值：<IScatterTypeDataLabel*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IScatterTypeDataLabel* GetLabel() = 0;

			/*@function
			******************************************************************
			功  能：数据淡出时的图形样式。
			参  数：<无>;
			返回值：<IScatterTypeDataItemStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IScatterTypeDataItemStyle* GetItemStyle() = 0;
			
		};
	}
	
}
