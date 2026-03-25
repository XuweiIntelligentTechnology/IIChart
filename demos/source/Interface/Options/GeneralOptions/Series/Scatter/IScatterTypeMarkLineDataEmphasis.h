#pragma once
/***********************************************************************
 * Module:   IScatterTypeMarkLineDataEmphasis.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  气泡图标线数据项的高亮状态。
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
		* 类  名: IScatterTypeMarkLineDataEmphasis
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 气泡图标线数据项的高亮状态。开启 emphasis.focus 后有效。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IScatterTypeMarkLineDataEmphasis
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
			功  能：气泡图标线数据项高亮时的线条样式。
			参  数：<无>;
			返回值：<IScatterTypeMarkLineDataLineStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IScatterTypeMarkLineDataLineStyle* GetLineStyle() = 0;

			/*@function
			******************************************************************
			功  能：气泡图标线数据项高亮时的标签样式。
			参  数：<无>;
			返回值：<IScatterTypeMarkLineDataLabel*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IScatterTypeMarkLineDataLabel* GetLabel() = 0;
		};
	}
	
}
