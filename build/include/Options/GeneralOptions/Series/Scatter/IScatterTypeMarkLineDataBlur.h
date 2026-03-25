#pragma once
/***********************************************************************
 * Module:   IScatterTypeMarkLineDataBlur.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  标线数据的淡出样式。淡出的规则跟随所在系列。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/GeneralOptions/Series/Scatter/IScatterTypeMarkLineDataLineStyle.h"
#include "Options/GeneralOptions/Series/Scatter/IScatterTypeMarkLineDataLabel.h"

namespace IIChart
{
	namespace Scatter
	{
		/*@class
		*************************************************************************
		* 类  名: IScatterTypeMarkLineBlur
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 标线数据的淡出样式
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IScatterTypeMarkLineDataBlur
		{
		public:

			/*@function
			******************************************************************
			功  能：标线数据淡出时的线条样式。
			参  数：<无>;
			返回值：<IScatterTypeMarkLineDataLineStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IScatterTypeMarkLineDataLineStyle* GetLineStyle() = 0;

			/*@function
			******************************************************************
			功  能：标线数据淡出时的标签样式。
			参  数：<无>;
			返回值：<IScatterTypeMarkLineDataLabel*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IScatterTypeMarkLineDataLabel* GetLabel() = 0;
			
		};
	}
	
}
