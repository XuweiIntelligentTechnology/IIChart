#pragma once
/***********************************************************************
 * Module:   IScatterTypeMarkPointEmphasis.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  标注的高亮样式。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/GeneralOptions/Series/Scatter/IScatterTypeMarkPointEmphasisItemStyle.h"
#include "Options/GeneralOptions/Series/Scatter/IScatterTypeMarkPointEmphasisLabel.h"

namespace IIChart
{
	namespace Scatter
	{
		/*@class
		*************************************************************************
		* 类  名: IScatterTypeMarkPointEmphasis
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 标注的高亮样式
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IScatterTypeMarkPointEmphasis
		{
		public:

			/*@function
			*******************************************************************
			功  能: 是否关闭高亮状态,关闭高亮状态可以在鼠标移到图形上，tooltip 触
			        发，或者图例联动的时候不再触发高亮效果。在图形非常多的时候可以
					关闭以提升交互流畅性.
			参  数: <bValue>;
			返回值: <无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetDisabled(bool bValue) = 0;
			virtual bool GetDisabled() const = 0;

			/*@function
			******************************************************************
			功  能：标注高亮时的标签样式
			参  数：<无>;
			返回值：<IScatterTypeMarkPointEmphasisLabel*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IScatterTypeMarkPointEmphasisLabel* GetLabel() = 0;

			/*@function
			******************************************************************
			功  能：标注高亮时的图形样式。
			参  数：<无>;
			返回值：<IScatterTypeMarkPointEmphasisItemStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IScatterTypeMarkPointEmphasisItemStyle* GetItemStyle() = 0;
		};
	}
	
}
