#pragma once
/***********************************************************************
 * Module:  IToolboxFeatureSaveAsImage.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: 保存为图片。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/IBaseArrayElement.h"
#include "Options/Common/ITextStyle.h"
#include "Options/GeneralOptions/Tooltip/ITooltip.h"
#include "Options/GeneralOptions/Toolbox/IToolboxEmphasis.h"
#include "Options/GeneralOptions/Toolbox/IToolboxIconStyle.h"

namespace IIChart
{
	using namespace Tooltip;

	namespace Toolbox
	{
		/***************************
	    * 保存为图片;
	    ****************************/
		class IToolboxFeatureSaveAsImage
		{
		public:
			// 组件 ID。默认不指定。指定则可用于在 option 或者 API 中引用组件。
			virtual void SetType(EImageType eValue) = 0;
			virtual EImageType GetType() const = 0;

			// 保存的文件名称，默认使用 title.text 作为名称。
			virtual void SetName(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetName() const = 0;

			/************************************************
			功  能：保存的图片背景色，默认使用 backgroundColor，如果backgroundColor不存在的话会取白色。
			参  数：<wzValue> 可以用 RGB、RGBA、16进制三种字符串形式设置颜色。;
			返回值：<无>;
			*************************************************/
			virtual void SetBackgroundColor(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetBackgroundColor() const = 0;

			/************************************************
			功  能：以 RGBA 方式设置刻度标签文字的颜色，默认取 axisLine.lineStyle.color。
			        保存的图片背景色，默认使用 backgroundColor，如果backgroundColor不存在的话会取白色。
			参  数：<略>;
			返回值：<无>;
			*************************************************/
			virtual void SetBackgroundColor(int nR, int nG, int nB, float nTransparent = 1) = 0;
			virtual void GetBackgroundColor(int* pnR, int* pnG, int* pnB, float* pnTransparent) = 0;

			/************************************************
			功  能：如果图表使用了 echarts.connect 对多个图表进行联动，
			        则在导出图片时会导出这些联动的图表。该配置项决定了图表与图表之间间隙处的填充色。
			参  数：<wzValue> 可以用 RGB、RGBA、16进制三种字符串形式设置颜色。;
			返回值：<无>;
			*************************************************/
			virtual void SetConnectedBackgroundColor(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetConnectedBackgroundColor() const = 0;

			/************************************************
			功  能：以 RGBA 方式设置颜色
					如果图表使用了 echarts.connect 对多个图表进行联动，
			        则在导出图片时会导出这些联动的图表。该配置项决定了图表与图表之间间隙处的填充色。
			参  数：<略>;
			返回值：<无>;
			*************************************************/
			virtual void SetConnectedBackgroundColor(int nR, int nG, int nB, float nTransparent = 1) = 0;
			virtual void GetConnectedBackgroundColor(int* pnR, int* pnG, int* pnB, float* pnTransparent) = 0;

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
			
			// 保存图片的分辨率比例，默认跟容器相同大小，如果需要保存更高分辨率的，可以设置为大于 1 的值，例如 2。
			virtual void SetPixelRatiol(int nLevel) = 0;
			virtual int GetPixelRatiol() const = 0;
		};
	}
	
}