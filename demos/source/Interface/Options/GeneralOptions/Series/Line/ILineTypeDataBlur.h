#pragma once
/***********************************************************************
 * Module:   ILineTypeDataBlur.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  单个拐点的淡出样式设置。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/ILineStyle.h"
#include "Options/GeneralOptions/Series/Line/ILineTypeDataItemStyle.h"
#include "Options/GeneralOptions/Series/Line/ILineTypeDataLabel.h"

namespace IIChart
{
	namespace Line
	{
		/*@class
		*************************************************************************
		* 类  名: ILineTypeDataBlur
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 单个拐点的淡出样式设置。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class ILineTypeDataBlur
		{
		public:
			/*@function
			*******************************************************************
			功  能: 单个拐点文本淡出时的标签样式设置
			参  数: <无>;
			返回值: <ILineTypeDataLabel*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILineTypeDataLabel* GetLabel() = 0;

			/*@function
			*******************************************************************
			功  能: 单个拐点标志淡出时的样式设置
			参  数: <无>;
			返回值: <ILineTypeDataItemStyle*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILineTypeDataItemStyle* GetItemStyle() = 0;
			
		};
	}
	
}
