#pragma once
/***********************************************************************
 * Module:   IRadarTypeBlur.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  淡出状态的配置。开启 emphasis.focus 后有效。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/ILineStyle.h"
#include "Options/GeneralOptions/Series/Radar/IRadarTypeBlurLabel.h"
#include "Options/GeneralOptions/Series/Radar/IRadarTypeBlurAreaStyle.h"
#include "Options/GeneralOptions/Series/Radar/IRadarTypeBlurItemStyle.h"

namespace IIChart
{
	namespace Radar
	{
		/*@class
		*************************************************************************
		* 类  名: IRadarTypeBlur
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 淡出状态的配置。开启 emphasis.focus 后有效。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IRadarTypeBlur
		{
		public:

			/*@function
			******************************************************************
			功  能：淡出时的折线拐点标志的样式。
			参  数：<无>;
			返回值：<IRadarTypeBlurItemStyle*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IRadarTypeBlurItemStyle* GetItemStyle() = 0;

			/*@function
			******************************************************************
			功  能：淡出时的标签样式。
			参  数：<无>;
			返回值：<IRadarTypeBlurLabel*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IRadarTypeBlurLabel* GetLabel() = 0;

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
			返回值：<IRadarTypeBlurAreaStyle*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IRadarTypeBlurAreaStyle* GetAreaStyle() = 0;
			
		};
	}
	
}
