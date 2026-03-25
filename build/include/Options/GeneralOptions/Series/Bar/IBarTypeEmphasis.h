#pragma once
/***********************************************************************
 * Module:   IBarTypeEmphasis.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  高亮状态。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/ILineStyle.h"
#include "Options/GeneralOptions/Series/Bar/IBarTypeLabel.h"
#include "Options/GeneralOptions/Series/Bar/IBarTypeEmphasisLabelLine.h"
#include "Options/GeneralOptions/Series/Bar/IBarTypeEmphasisItemStyle.h"


namespace IIChart
{
	namespace Bar
	{
		/*@class
		*************************************************************************
		* 类  名: IBarTypeEmphasis
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 高亮状态。开启 emphasis.focus 后有效。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IBarTypeEmphasis
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
			*******************************************************************
			功  能: 在高亮图形时，是否高亮其它数据的图形已达到聚焦的效果。
			参  数: <eValue>;
			返回值: <无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetFocus(EFocus eValue) = 0;
			virtual EFocus GetFocus() const = 0;

			/*@function
			*******************************************************************
			功  能: 在开启focus的时候，可以通过blurScope配置高亮的范围。
			参  数: <eValue>;
			返回值: <无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetBlurScope(EBlurScope eValue) = 0;
			virtual EBlurScope GetBlurScope() const = 0;

			/*@function
			******************************************************************
			功  能：高亮时的标签样式。
			参  数：<无>;
			返回值：<IBarTypeLabel*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IBarTypeLabel* GetLabel() = 0;

			/*@function
			******************************************************************
			功  能：高亮时的视觉引导线配置。
			参  数：<无>;
			返回值：<IBarTypeEmphasisLabelLine*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IBarTypeEmphasisLabelLine* GetLabelLine() = 0;

			/*@function
			******************************************************************
			功  能：高亮时的图形样式。
			参  数：<无>;
			返回值：<IBarTypeEmphasisItemStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IBarTypeEmphasisItemStyle* GetItemStyle() = 0;
		};
	}
	
}
