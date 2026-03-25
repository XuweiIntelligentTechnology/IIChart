#pragma once
/***********************************************************************
 * Module:  IToolboxFeatureDataZoomTitle.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: 缩放和还原的标题文本。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/IColor.h"

namespace IIChart
{
	namespace Toolbox
	{
		
		class IToolboxFeatureDataZoomTitle // OK
		{
		public:

			/************************************************
			功  能：缩放的标题文本。
			参  数：<wzValue> 标题文;
			返回值：<无>;
			*************************************************/
			virtual void SetZoom(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetZoom() const = 0;

			/************************************************
			功  能：还原的标题文本。
			参  数：<wzValue> 标题文;
			返回值：<无>;
			*************************************************/
			virtual void SetBack(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetBack() const = 0;

		};
	}
}