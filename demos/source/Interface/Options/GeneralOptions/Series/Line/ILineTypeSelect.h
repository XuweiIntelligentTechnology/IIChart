#pragma once
/***********************************************************************
 * Module:   ILineTypeSelect.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  折线图的选中状态。开启 selectedMode 后有效。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/ILineStyle.h"
#include "Options/GeneralOptions/Series/Line/ILineTypeSelectLabelLine.h"
#include "Options/GeneralOptions/Series/Line/ILineTypeSelectItemStyle.h"
#include "Options/GeneralOptions/Series/Line/ILineTypeSelectAreaStyle.h"
#include "Options/GeneralOptions/Series/Line/ILineTypeSelectEndLabel.h"
#include "Options/GeneralOptions/Series/Line/ILineTypeLabel.h"

namespace IIChart
{
	namespace Line
	{
		/*@class
		*************************************************************************
		* 类  名: ILineTypeSelect
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 折线图的选中状态。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class ILineTypeSelect
		{
		public:

			/*@function
			*******************************************************************
			功  能: 是否可以被选中。在开启selectedMode的时候有效，可以用于关闭部分数据。
			参  数: <bValue>;
			返回值: <无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetDisabled(bool bValue) = 0;
			virtual bool GetDisabled() const = 0;

			/*@function
			******************************************************************
			功  能：折线图选中时的 Label。
			参  数：<无>;
			返回值：<ILineTypeLabel*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILineTypeLabel* GetLabel() = 0;

			/*@function
			******************************************************************
			功  能：折线图选中时的 标签的视觉引导线配置。
			参  数：<无>;
			返回值：<ILineTypeSelectLabelLine*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILineTypeSelectLabelLine* GetLabelLine() = 0;

			/*@function
			******************************************************************
			功  能：折线图选中时的 ItemStyle。
			参  数：<无>;
			返回值：<ILineTypeSelectItemStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILineTypeSelectItemStyle* GetItemStyle() = 0;

			/*@function
			******************************************************************
			功  能：折线图选中时的 LineStyle。
			参  数：<无>;
			返回值：<ILineStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILineStyle* GetLineStyle() = 0;

			/*@function
			******************************************************************
			功  能：折线图选中时的 AreaStyle。
			参  数：<无>;
			返回值：<ILineTypeSelectAreaStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILineTypeSelectAreaStyle* GetAreaStyle() = 0;

			/*@function
			******************************************************************
			功  能：折线图选中时的 EndLabel。
			参  数：<无>;
			返回值：<ILineTypeSelectEndLabel*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILineTypeSelectEndLabel*  GetEndLabel() = 0;
			
		};
	}
	
}
