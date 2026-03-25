#pragma once
/***********************************************************************
 * Module:   IPieTypeMarkPointEmphasis.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  标注的高亮样式。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/GeneralOptions/Series/Pie/IPieTypeMarkPointItemStyle.h"
#include "Options/GeneralOptions/Series/Pie/IPieTypeMarkPointLabel.h"

namespace IIChart
{
	namespace Pie
	{
		/*@class
		*************************************************************************
		* 类  名: IPieTypeMarkPointEmphasis
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 标注的高亮样式
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IPieTypeMarkPointEmphasis
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
			功  能：标注的标签样式。
			参  数：<无>;
			返回值：<IPieTypeMarkPointLabel*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IPieTypeMarkPointLabel* GetLabel() = 0;

			/*@function
			******************************************************************
			功  能：标注的图形的样式。
			参  数：<无>;
			返回值：<IPieTypeMarkPointItemStyle*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IPieTypeMarkPointItemStyle* GetItemStyle() = 0;
		};
	}
	
}
