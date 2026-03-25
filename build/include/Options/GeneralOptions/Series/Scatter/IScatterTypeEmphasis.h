#pragma once
/***********************************************************************
 * Module:   IScatterTypeEmphasis.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  气泡图的高亮状态。开启 emphasis.focus 后有效。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/ILineStyle.h"
#include "Options/GeneralOptions/Series/Scatter/IScatterTypeEmphasisLabel.h"
#include "Options/GeneralOptions/Series/Scatter/IScatterTypeEmphasisLabelLine.h"
#include "Options/GeneralOptions/Series/Scatter/IScatterTypeEmphasisItemStyle.h"


namespace IIChart
{
	namespace Scatter
	{
		/*@class
		*************************************************************************
		* 类  名: IScatterTypeEmphasis
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 气泡图的高亮状态。开启 emphasis.focus 后有效。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IScatterTypeEmphasis
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
			功  能: 是否开启 hover 在拐点标志上的放大效果。
			参  数: <bValue>;
			返回值: <无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetScale(bool bValue) = 0;
			virtual bool GetScale() const = 0;

			/*@function
			*******************************************************************
			功  能: 用以设置高亮放大倍数，默认放大 1.1 倍。
			参  数: <fValue>;
			返回值: <无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetScale(float fValue) = 0;
			virtual void GetScale(float* pfValue) const = 0;

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
			功  能：气泡图高亮时的标签样式。
			参  数：<无>;
			返回值：<IScatterTypeEmphasisLabel*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IScatterTypeEmphasisLabel* GetLabel() = 0;

			/*@function
			******************************************************************
			功  能：气泡图高亮时的标签的视觉引导线配置。
			参  数：<无>;
			返回值：<IScatterTypeEmphasisLabelLine*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IScatterTypeEmphasisLabelLine* GetLabelLine() = 0;

			/*@function
			******************************************************************
			功  能：气泡图高亮时的图形样式。
			参  数：<无>;
			返回值：<IScatterTypeEmphasisItemStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IScatterTypeEmphasisItemStyle* GetItemStyle() = 0;
			
		};
	}
	
}
