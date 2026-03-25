#pragma once
/***********************************************************************
 * Module:  IToolboxFeatureRestore.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: 配置项还原。
 ***********************************************************************/
#include "Common\IEnum.h"
#include "Options/Common/IBaseArrayElement.h"
#include "Options/Common/ITextStyle.h"
#include "Options/GeneralOptions/Toolbox/IToolboxEmphasis.h"
#include "Options/GeneralOptions/Toolbox/IToolboxIconStyle.h"

namespace IIChart
{
	namespace Toolbox
	{
		/***************************
	    * 配置项还原;
	    ****************************/
		class IToolboxFeatureRestore
		{
		public:
			
			// 是否显示工具栏组件。
			virtual void SetShow(bool bValue) = 0;
			virtual bool GetShow() const = 0;

			virtual void SetTitle(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetTitle() const = 0;

			/************************************************
			 功  能：用图片设置 两侧缩放手柄的 icon 形状，支持路径字符串
			 注  意：本接口参数只能是以下几种形式：
					 1. 图片链接：
					 'image://http://example.website/a/b.png'
					 2. dataURI：
					 'image://data:image/gif;base64,R0lGODlhEAAQAMQAAORHHOVSKudfOulrSOp3WOyDZu6QdvCchPGolfO0o/XBs/fNwfjZ0frl3/zy7////wAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACH5BAkAABAALAAAAAAQABAAAAVVICSOZGlCQAosJ6mu7fiyZeKqNKToQGDsM8hBADgUXoGAiqhSvp5QAnQKGIgUhwFUYLCVDFCrKUE1lBavAViFIDlTImbKC5Gm2hB0SlBCBMQiB0UjIQA7'
					 3. 矢量路径：（可以参考 https://www.w3.org/TR/SVG/paths.html#PathData）
					 'path://M30.9,53.2C16.8,53.2,5.3,41.7,5.3,27.6S16.8,2,30.9,2C45,2,56.4,13.5,56.4,27.6S45,53.2,30.9,53.2z M30.9,3.5C17.6,3.5,6.8,14.4,6.8,27.6c0,13.3,10.8,24.1,24.101,24.1C44.2,51.7,55,40.9,55,27.6C54.9,14.4,44.1,3.5,30.9,3.5z M36.9,35.8c0,0.601-0.4,1-0.9,1h-1.3c-0.5,0-0.9-0.399-0.9-1V19.5c0-0.6,0.4-1,0.9-1H36c0.5,0,0.9,0.4,0.9,1V35.8z M27.8,35.8 c0,0.601-0.4,1-0.9,1h-1.3c-0.5,0-0.9-0.399-0.9-1V19.5c0-0.6,0.4-1,0.9-1H27c0.5,0,0.9,0.4,0.9,1L27.8,35.8L27.8,35.8z'
			 参  数：<wzValue>图片的 URL 或 dataURI也可以是 Path;
			 返回值：<无>;
			*************************************************/
			virtual void SetIcon(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetIcon() const = 0;

			// 公用的 icon 样式设置。由于 icon 的文本信息只在 icon hover 时候才显示，所以文字相关的配置项请在 emphasis 下设置。
			virtual IToolboxIconStyle* GetIconStyle() = 0;

			virtual IToolboxEmphasis* GetEmphasis() = 0;
		};
	}
	
}