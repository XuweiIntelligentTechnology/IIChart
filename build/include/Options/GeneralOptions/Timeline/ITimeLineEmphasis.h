#pragma once
/***********************************************************************
 * Module:   IBarTypeEmphasis.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  折线图的高亮状态。
 ***********************************************************************/
#include "Options/GeneralOptions/Timeline/ITimeLineProgressLineStyle.h"
#include "Options/GeneralOptions/Timeline/ITimeLineItemStyle.h"
#include "Options/GeneralOptions/Timeline/ITimeLineEmphasisLabel.h"
#include "Options/GeneralOptions/Timeline/ITimeLineCheckpointStyle.h"
#include "Options/GeneralOptions/Timeline/ITimeLineControlStyle.h"


namespace IIChart
{
	namespace TimeLine
	{
		class ITimeLineEmphasis // OK
		{
		public:

			virtual ITimeLineItemStyle* GetItemStyle() = 0;

			virtual ITimeLineEmphasisLabel* GetLabel() = 0;
			
			virtual ITimeLineCheckpointStyle* GetCheckpointStyle() = 0;

			virtual ITimeLineControlStyle* GetControlStyle() = 0;
		};
	}
	
}
