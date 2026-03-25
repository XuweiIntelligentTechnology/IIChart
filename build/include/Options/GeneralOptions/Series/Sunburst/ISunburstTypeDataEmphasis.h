#pragma once
/***********************************************************************
 * Module:   ISunburstTypeEmphasis.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  高亮状态配置。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/ILineStyle.h"
#include "Options/GeneralOptions/Series/Sunburst/ISunburstTypeLabel.h"
#include "Options/GeneralOptions/Series/Sunburst/ISunburstTypeLabelLine.h"
#include "Options/GeneralOptions/Series/Sunburst/ISunburstTypeItemStyle.h"

namespace IIChart
{
	namespace Sunburst
	{
		/*@class
		*************************************************************************
		* 类  名: ISunburstTypeBlur
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 数据高亮时的状态配置。开启 emphasis.focus 后有效。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class ISunburstTypeDataEmphasis
		{
		public:
			
			/*@function
			*******************************************************************
			* 功  能：数据高亮时文本标签的样式。
			* 参  数：<无> ;
			* 返回值：<ISunburstTypeLabel*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ISunburstTypeLabel* GetLabel() = 0;

			/*@function
			*******************************************************************
			* 功  能：数据高亮时视觉引导线配置。
			* 参  数：<无> ;
			* 返回值：<ISunburstTypeLabelLine*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ISunburstTypeLabelLine* GetLabelLine() = 0;

			/*@function
			*******************************************************************
			* 功  能：数据高亮时旭日图扇形块的样式。
			* 参  数：<无> ;
			* 返回值：<ISunburstTypeItemStyle*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ISunburstTypeItemStyle* GetItemStyle() = 0;

		};
	}
	
}
