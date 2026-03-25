#pragma once
/***********************************************************************
 * Module:   IRadarTypeDataBlur.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  单个拐点淡出状态的配置。
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
		* 类  名: IRadarTypeBlur
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 单个拐点淡出状态的配置。开启 emphasis.focus 后有效。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IRadarTypeDataBlur
		{
		public:

			/*@function
			******************************************************************
			功  能：淡出时的标签样式。
			参  数：<无>;
			返回值：<IRadarTypeDataLabel*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IRadarTypeDataLabel* GetLabel() = 0;	

			/*@function
			******************************************************************
			功  能：淡出时的拐点图形样式。
			参  数：<无>;
			返回值：<IRadarTypeDataItemStyle*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IRadarTypeDataItemStyle* GetItemStyle() = 0;

			/*@function
			******************************************************************
			功  能：淡出时的线条样式。
			参  数：<无>;
			返回值：<ILineStyle*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILineStyle* GetLineStyle() = 0;

			/*@function
			******************************************************************
			功  能：淡出时的区域填充样式。
			参  数：<无>;
			返回值：<IRadarTypeDataAreaStyle*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IRadarTypeDataAreaStyle* GetAreaStyle() = 0;
			
		};
	}
	
}
