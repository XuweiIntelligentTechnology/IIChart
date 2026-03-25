#pragma once
/***********************************************************************
 * Module:   ILineTypeBlur.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  折线图的淡出状态。开启 emphasis.focus 后有效。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/ILineStyle.h"
#include "Options/GeneralOptions/Series/Line/ILineTypeBlurLabelLine.h"
#include "Options/GeneralOptions/Series/Line/ILineTypeBlurItemStyle.h"
#include "Options/GeneralOptions/Series/Line/ILineTypeBlurAreaStyle.h"
#include "Options/GeneralOptions/Series/Line/ILineTypeBlurEndLabel.h"
#include "Options/GeneralOptions/Series/Line/ILineTypeBlurLabel.h"

namespace IIChart
{
	namespace Line
	{
		/*@class
		*************************************************************************
		* 类  名: ILineTypeBlur
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 折线图的淡出状态。开启 emphasis.focus 后有效。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class ILineTypeBlur
		{
		public:

			/*@function
			******************************************************************
			功  能：折线图的淡出时的 Label。
			参  数：<无>;
			返回值：<ILineBlurTypeLabel*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILineTypeBlurLabel* GetLabel() = 0;

			/*@function
			******************************************************************
			功  能：折线图的淡出时的 标签的视觉引导线配置。
			参  数：<无>;
			返回值：<ILineTypeBlurLabelLine*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILineTypeBlurLabelLine* GetLabelLine() = 0;

			/*@function
			******************************************************************
			功  能：折线图的淡出时的 ItemStyle。
			参  数：<无>;
			返回值：<ILineTypeBlurItemStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILineTypeBlurItemStyle* GetItemStyle() = 0;

			/*@function
			******************************************************************
			功  能：折线图的淡出时的 LineStyle。
			参  数：<无>;
			返回值：<ILineStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILineStyle* GetLineStyle() = 0;

			/*@function
			******************************************************************
			功  能：折线图的淡出时的 AreaStyle。
			参  数：<无>;
			返回值：<ILineTypeBlurAreaStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILineTypeBlurAreaStyle* GetAreaStyle() = 0;

			/*@function
			******************************************************************
			功  能：折线图的淡出时的 EndLabel。
			参  数：<无>;
			返回值：<ILineTypeBlurEndLabel*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILineTypeBlurEndLabel*  GetEndLabel() = 0;
			
		};
	}
	
}
