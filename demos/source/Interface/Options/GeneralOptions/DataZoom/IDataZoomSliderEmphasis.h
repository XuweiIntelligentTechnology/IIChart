#pragma once
/***********************************************************************
 * Module:  IDataZoomSliderEmphasis.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  高亮样式设置。
 ***********************************************************************/
#include <vector>
#include <string>
#include "Common/ICallback.h"
#include "Options/Common/ICategoryData.h"
#include "Options\GeneralOptions\DataZoom\IDataZoomSliderHandleStyle.h"
#include "Options\GeneralOptions\DataZoom\IDataZoomSliderMoveHandleStyle.h"

namespace IIChart
{
	namespace DataZoom
	{

		/***********************************************************************
		 * Clsss:    IDataZoomSliderEmphasis.h
		 * Author:   杨鹏辉
		 * Modified: 2022年7月1日 15:02:44
		 * Purpose:  高亮样式设置。
		 ***********************************************************************/
		class IDataZoomSliderEmphasis
		{
		public:

			virtual IDataZoomSliderHandleStyle* GetHandleStyle() = 0;

			virtual IDataZoomSliderMoveHandleStyle* GetMoveHandleStyle() = 0;
		};
	}

}