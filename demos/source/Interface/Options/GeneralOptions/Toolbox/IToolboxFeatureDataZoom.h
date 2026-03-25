#pragma once
/***********************************************************************
 * Module:  IToolboxFeatureDataZoom.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: 工具栏。
 * 内置有导出图片，数据视图，动态类型切换，数据区域缩放，重置五个工具。
 ***********************************************************************/
#include "Common\IEnum.h"
#include "Options/Common/IBaseArrayElement.h"
#include "Options/Common/ITextStyle.h"
#include "Options/GeneralOptions/Toolbox/IToolboxEmphasis.h"
#include "Options/GeneralOptions/Toolbox/IToolboxIconStyle.h"
#include "Options/GeneralOptions/Toolbox/IToolboxFeatureDataZoomIcon.h"
#include "Options/GeneralOptions/Toolbox/IToolboxFeatureDataZoomTitle.h"
#include "Options/GeneralOptions/Toolbox/IToolboxFeatureDataZoomBrushStyle.h"

namespace IIChart
{
	namespace Toolbox
	{
		/***************************
	    * 全局 Tooltip 组件;
	    ****************************/
		class IToolboxFeatureDataZoom
		{
		public:
			// 是否显示工具栏组件。
			virtual void SetShow(bool bValue) = 0;
			virtual bool GetShow() const = 0;

			// 缩放和还原的标题文本。
			virtual IToolboxFeatureDataZoomTitle* GetTitle() = 0;

			// 缩放和还原的 icon path。
			virtual IToolboxFeatureDataZoomIcon* GetIcon() = 0;

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

			/************************************************
			功  能：数据过滤模式
					dataZoom 的运行原理是通过 数据过滤 以及在内部设置轴的显示窗口来达到 数据窗口缩放 的效果。
					如何设置，由用户根据场景和需求自己决定。经验来说：
					> 当『只有 X 轴 或 只有 Y 轴受 dataZoom 组件控制』时，
					  常使用 filterMode: 'filter'，这样能使另一个轴自适应过滤后的数值范围。
					> 当『X 轴 Y 轴分别受 dataZoom 组件控制』时：
					  >> 如果 X 轴和 Y 轴是『同等地位的、不应互相影响的』，比如在『双数值轴散点图』中，
						 那么两个轴可都设为 filterMode: 'empty'。
					  >> 如果 X 轴为主，Y 轴为辅，比如在『柱状图』中，需要『拖动 dataZoomX 改变 X 轴过滤柱子时，
						 Y 轴的范围也自适应剩余柱子的高度』，『拖动 dataZoomY 改变 Y 轴过滤柱子时，X 轴范围不受影响』，
						 那么就 X轴设为 filterMode: 'filter'，Y 轴设为 filterMode: 'empty'，即主轴 'filter'，辅轴 'empty'。
					详细参考：https://echarts.apache.org/zh/option.html#dataZoom-inside.filterMode
			参  数：<eValue> ;
			返回值：<无>;
			*************************************************/
			virtual void SetFilterMode(EFilterMode eValue) = 0;
			virtual EFilterMode GetFilterMode()const = 0;

			/************************************************
			* 功  能：设置 dataZoom-inside 组件控制的 x轴序号;
			* 参  数：<nValue>;
			* 返回值：<无>;
			*************************************************/
			virtual void SetXAxisIndex(int nValue) = 0;
			virtual int  GetXAxisIndex()const = 0;

			/************************************************
			* 功  能：设置 dataZoom-inside 组件控制的 x轴序号;
			*         每个序号之间使用“,”分隔;
			* 参  数：<wzValue> 使用“,”分隔的序号;
			* 返回值：<无>;
			*************************************************/
			virtual int SetXAxisIndex(const wchar_t* wzValue) = 0;

			/************************************************
			* 功  能：设置 dataZoom-inside 组件控制的 x轴序号;
			*         每个序号之间使用“,”分隔;
			* 参  数：<wzValue> 使用“,”分隔的序号;
			* 返回值：<无>;
			*************************************************/
			virtual void SetXAxisIndex(const std::vector<int>& vctValue) = 0;

			/************************************************
			* 功  能：设置 dataZoom-inside 组件控制的 y轴序号;
			* 参  数：<nValue>;
			* 返回值：<无>;
			*************************************************/
			virtual void SetYAxisIndex(int nValue) = 0;
			virtual int  GetYAxisIndex() const = 0;

			/************************************************
			* 功  能：设置 dataZoom-inside 组件控制的 y轴序号;
			*         每个序号之间使用“,”分隔;
			* 参  数：<wzValue> 使用“,”分隔的序号;
			* 返回值：<无>;
			*************************************************/
			virtual int SetYAxisIndex(const wchar_t* wzValue) = 0;

			/************************************************
			* 功  能：设置 dataZoom-inside 组件控制的 x轴序号;
			*         每个序号之间使用“,”分隔;
			* 参  数：<wzValue> 使用“,”分隔的序号;
			* 返回值：<无>;
			*************************************************/
			virtual void SetYAxisIndex(const std::vector<int>& vctValue) = 0;

			// 刷选框样式
			virtual IToolboxFeatureDataZoomBrushStyle* GetBrushStyle() = 0;
		};
	}
	
}