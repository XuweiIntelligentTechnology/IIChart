#pragma once
/***********************************************************************
 * Module:   ITimeLineProgress.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  折线图的高亮状态。
 ***********************************************************************/
#include "Options/GeneralOptions/Timeline/ITimeLineProgressLineStyle.h"
#include "Options/GeneralOptions/Timeline/ITimeLineItemStyle.h"
#include "Options/GeneralOptions/Timeline/ITimeLineProgressLabel.h"


namespace IIChart
{
	namespace TimeLine
	{
		class ITimeLineProgress // OK
		{
		public:

			virtual ITimeLineProgressLineStyle* GetLineStyle() = 0;

			virtual ITimeLineItemStyle* GetItemStyle() = 0;

			virtual ITimeLineProgressLabel* GetLabel() = 0;

		};
	}
	
}
