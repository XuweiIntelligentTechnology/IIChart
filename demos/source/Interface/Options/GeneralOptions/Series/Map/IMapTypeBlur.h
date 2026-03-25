#pragma once
/***********************************************************************
 * Module:   IMapTypeBlur.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  淡出状态下的多边形和标签样式
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/ILineStyle.h"
#include "Options/GeneralOptions/Series/Map/IMapTypeLabel.h"
#include "Options/GeneralOptions/Series/Map/IMapTypeLabelLine.h"
#include "Options/GeneralOptions/Series/Map/IMapTypeItemStyle.h"


namespace IIChart
{
	namespace Map
	{
		/*@class
		*************************************************************************
		* 类  名: IMapTypeBlur
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 淡出状态下的多边形和标签样式。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IMapTypeBlur
		{
		public:

			/*@function
			******************************************************************
			功  能：淡出状态下的标签样式。
			参  数：<无>;
			返回值：<IMapTypeLabel*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IMapTypeLabel* GetLabel() = 0;

			/*@function
			******************************************************************
			功  能：淡出状态下的图形样式。
			参  数：<无>;
			返回值：<IMapTypeItemStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IMapTypeItemStyle* GetItemStyle() = 0;
		};
	}
	
}
