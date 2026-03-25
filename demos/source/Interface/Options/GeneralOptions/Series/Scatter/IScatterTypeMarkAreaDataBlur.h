#pragma once
/***********************************************************************
 * Module:   IScatterTypeMarkAreaDataBlur.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  标域数据的淡出样式
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/GeneralOptions/Series/Scatter/IScatterTypeMarkAreaDataItemStyle.h"
#include "Options/GeneralOptions/Series/Scatter/IScatterTypeMarkAreaDataLabel.h"

namespace IIChart
{
	namespace Scatter
	{
		/*@class
		*************************************************************************
		* 类  名: IScatterTypeMarkAreaDataBlur
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 标域数据的淡出样式
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IScatterTypeMarkAreaDataBlur
		{
		public:

			/*@function
			******************************************************************
			功  能：标域数据淡出时的图形样式。
			参  数：<无>;
			返回值：<IScatterTypeMarkAreaDataItemStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IScatterTypeMarkAreaDataItemStyle* GetItemStyle() = 0;

			/*@function
			******************************************************************
			功  能：标域数据淡出时的标签样式。
			参  数：<无>;
			返回值：<IScatterTypeMarkAreaDataLabel*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IScatterTypeMarkAreaDataLabel* GetLabel() = 0;
			
		};
	}
	
}
