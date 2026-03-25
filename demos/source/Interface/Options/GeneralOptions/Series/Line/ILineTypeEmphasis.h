#pragma once
/***********************************************************************
 * Module:   ILineTypeEmphasis.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  折线图的高亮状态。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/ILineStyle.h"
#include "Options/GeneralOptions/Series/Line/ILineTypeEmphasisLabel.h"
#include "Options/GeneralOptions/Series/Line/ILineTypeEmphasisLabelLine.h"
#include "Options/GeneralOptions/Series/Line/ILineTypeEmphasisItemStyle.h"
#include "Options/GeneralOptions/Series/Line/ILineTypeEmphasisAreaStyle.h"
#include "Options/GeneralOptions/Series/Line/ILineTypeEmphasisEndLabel.h"


namespace IIChart
{
	namespace Line
	{
		/*@class
		*************************************************************************
		* 类  名: ILineTypeEmphasis
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 折线图的高亮状态。开启 emphasis.focus 后有效。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class ILineTypeEmphasis
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
			功  能：折线图的高亮时的 Label。
			参  数：<无>;
			返回值：<ILineTypeEmphasisLabel*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILineTypeEmphasisLabel* GetLabel() = 0;

			/*@function
			******************************************************************
			功  能：折线图的高亮时的 标签的视觉引导线配置。
			参  数：<无>;
			返回值：<ILineTypeEmphasisLabelLine*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILineTypeEmphasisLabelLine* GetLabelLine() = 0;

			/*@function
			******************************************************************
			功  能：折线图的高亮时的 ItemStyle。
			参  数：<无>;
			返回值：<ILineTypeEmphasisItemStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILineTypeEmphasisItemStyle* GetItemStyle() = 0;

			/*@function
			******************************************************************
			功  能：折线图的高亮时的 LineStyle。
			参  数：<无>;
			返回值：<ILineStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILineStyle* GetLineStyle() = 0;

			/*@function
			******************************************************************
			功  能：折线图的高亮时的 AreaStyle。
			参  数：<无>;
			返回值：<ILineTypeEmphasisAreaStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILineTypeEmphasisAreaStyle* GetAreaStyle() = 0;

			/*@function
			******************************************************************
			功  能：折线图的高亮时的 EndLabel。
			参  数：<无>;
			返回值：<ILineTypeEmphasisEndLabel*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILineTypeEmphasisEndLabel*  GetEndLabel() = 0;
			
		};
	}
	
}
