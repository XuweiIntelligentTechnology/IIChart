#pragma once
/***********************************************************************
 * Module:   IMapTypeEmphasis.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  高亮状态下的多边形和标签样式。
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
		* 类  名: IMapTypeEmphasis
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 高亮状态下的多边形和标签样式。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IMapTypeEmphasis
		{
		public:

			/*@function
			*******************************************************************
			功  能: 是否关闭高亮状态。
			注  意：关闭高亮状态可以在鼠标移到图形上，tooltip 触发，或者图例联动的时候不再触发高亮效果。
					在图形非常多的时候可以关闭以提升交互流畅性。
			参  数: <bValue>;
			返回值: <无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetDisabled(bool bValue) = 0;
			virtual bool GetDisabled() const = 0;

			/*@function
			******************************************************************
			功  能：高亮状态下的标签样式。
			参  数：<无>;
			返回值：<IMapTypeLabel*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IMapTypeLabel* GetLabel() = 0;

			/*@function
			******************************************************************
			功  能：高亮状态下的多边形的样式。
			参  数：<无>;
			返回值：<IMapTypeItemStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IMapTypeItemStyle* GetItemStyle() = 0;
		};
	}
	
}
