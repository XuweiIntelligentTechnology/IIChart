#pragma once
/***********************************************************************
 * Module:   ILineTypeItemStyle.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  仪表盘指针样式。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/IRich.h"
#include "Options/Common/IColor.h"
#include "Options/GeneralOptions/Series/Gauge/IGaugeTypeDecal.h"
#include "Options/GeneralOptions/Series/Gauge/IGaugeTypeItemStyle.h"


namespace IIChart
{
	namespace Gauge
	{
		/*@class
		*************************************************************************
		* 类  名: IGaugeTypeItemStyleEx
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 进度条样式。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IGaugeTypeItemStyleEx
			: public IGaugeTypeItemStyle
		{
		public:

			/*@function
			******************************************************************
			功  能：图形的贴花图案;
			参  数：<无>;
			返回值：<IGaugeTypeDecal*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IGaugeTypeDecal* GetDecal() = 0;

		};
	}
}
