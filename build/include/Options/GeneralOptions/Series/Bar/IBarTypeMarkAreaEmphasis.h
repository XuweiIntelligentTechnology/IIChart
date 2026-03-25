#pragma once
/***********************************************************************
 * Module:   IBarTypeMarkAreaEmphasis.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  标域的高亮样式。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/GeneralOptions/Series/Bar/IBarTypeMarkAreaItemStyle.h"
#include "Options/GeneralOptions/Series/Bar/IBarTypeMarkAreaLabel.h"

namespace IIChart
{
	namespace Bar
	{
		/*@class
		*************************************************************************
		* 类  名: IBarTypeMarkAreaEmphasis
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 标域的高亮样式
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IBarTypeMarkAreaEmphasis
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
			功  能：标域文本配置。
			参  数：<无>;
			返回值：<IBarTypeMarkAreaLabel*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IBarTypeMarkAreaLabel* GetLabel() = 0;

			/*@function
			******************************************************************
			功  能：标域文本配置。
			参  数：<无>;
			返回值：<IBarTypeMarkAreaItemStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IBarTypeMarkAreaItemStyle* GetItemStyle() = 0;
		};
	}
	
}
