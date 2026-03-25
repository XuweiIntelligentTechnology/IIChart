#pragma once
/***********************************************************************
 * Module:  IDataZoomSliderSelectedDataBackground.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: 选中部分数据阴影的样式。。
 ***********************************************************************/
#include "Options/Common/ILineStyle.h"
#include "Options/GeneralOptions\DataZoom\IDataZoomAreaStyle.h"


namespace IIChart
{
	namespace DataZoom
	{

		/*@class
		*************************************************************************
		* 类  名: IDataZoomSliderSelectedDataBackground
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 选中部分数据阴影的样式。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IDataZoomSliderSelectedDataBackground
		{
		public:

			/*@function
			******************************************************************
			功  能：选中部分阴影的线条样式
			参  数: <无>;
			返回值：<ILineStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILineStyle* GetLineStyle() = 0;

			/*@function
			******************************************************************
			功  能：选中部分阴影的填充样式
			参  数: <无>;
			返回值：<IDataZoomAreaStyle*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IDataZoomAreaStyle* GetAreaStyle() = 0;
		};
	}

}