#pragma once
/***********************************************************************
 * Module:   IMapTypeSelectEx.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  选中状态配置。开启 selectedMode 后有效。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/ILineStyle.h"
#include "Options/GeneralOptions/Series/Map/IMapTypeLabelEx.h"
#include "Options/GeneralOptions/Series/Map/IMapTypeLabelLine.h"
#include "Options/GeneralOptions/Series/Map/IMapTypeItemStyle.h"


namespace IIChart
{
	namespace Map
	{
		/*@class
		*************************************************************************
		* 类  名: IMapTypeSelectEx
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 高亮状态下的多边形和标签样式。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IMapTypeSelectEx
		{
		public:

			/*@function
			*******************************************************************
			功  能: 是否关闭选中状态。
			参  数: <bValue>;
			返回值: <无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetDisabled(bool bValue) = 0;
			virtual bool GetDisabled() const = 0;

			/*@function
			******************************************************************
			功  能：选中状态下的标签样式。
			参  数：<无>;
			返回值：<IMapTypeLabelEx*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IMapTypeLabelEx* GetLabel() = 0;

			/*@function
			******************************************************************
			功  能：选中状态下的图形样式。
			参  数：<无>;
			返回值：<IMapTypeItemStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IMapTypeItemStyle* GetItemStyle() = 0;

			/*@function
			******************************************************************
			功  能：选中状态下的标签视觉引导线样式。
			参  数：<无>;
			返回值：<IMapTypeLabelLine*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IMapTypeLabelLine* GetLabelLine() = 0;
		};
	}
	
}
