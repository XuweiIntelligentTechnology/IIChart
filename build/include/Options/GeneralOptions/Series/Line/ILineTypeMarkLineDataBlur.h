#pragma once
/***********************************************************************
 * Module:   ILineTypeMarkLineDataBlur.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  图表标线数据的淡出样式
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/GeneralOptions/Series/Line/ILineTypeMarkLineLineStyle.h"
#include "Options/GeneralOptions/Series/Line/ILineTypeMarkLineLabel.h"

namespace IIChart
{
	namespace Line
	{
		/*@class
		*************************************************************************
		* 类  名: ILineTypeMarkLineDataBlur
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 图表标线数据的淡出样式
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class ILineTypeMarkLineDataBlur
		{
		public:

			/*@function
			*******************************************************************
			功  能: 淡出时的标线的线条样式。
			参  数: <无>;
			返回值: <ILineTypeMarkLineLineStyle*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILineTypeMarkLineLineStyle* GetLineStyle() = 0;

			/*@function
			*******************************************************************
			功  能: 淡出时的标线的标签样式。
			参  数: <无>;
			返回值: <ILineTypeMarkLineLabel*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILineTypeMarkLineLabel* GetLabel() = 0;
		};
	}
	
}
