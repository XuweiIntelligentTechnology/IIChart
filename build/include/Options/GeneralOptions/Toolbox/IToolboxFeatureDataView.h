#pragma once
/***********************************************************************
 * Module:  Tooltip.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: 工具栏。
 * 内置有导出图片，数据视图，动态类型切换，数据区域缩放，重置五个工具。
 ***********************************************************************/
#include <vector>
#include "Common/IEnum.h"
#include "Common/IQueue.h"
#include "Options/GeneralOptions/Toolbox/IToolboxEmphasis.h"
#include "Options/GeneralOptions/Toolbox/IToolboxIconStyle.h"

namespace IIChart
{

	namespace Toolbox
	{
		/***************************
	    * 全局 Tooltip 组件;
	    ****************************/
		class IToolboxFeatureDataView
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

			// 是否不可编辑（只读）。
			virtual void SetReadOnly(bool bValue) = 0;
			virtual bool GetReadOnly() const = 0;

			/************************************************
			 功  能：自定义 dataView 展现函数，用以取代默认的 textarea 使用更丰富的数据编辑。可以返回 dom 对象或者 html 字符串。
			 注  意：回调函数格式：
					(option:Object) => HTMLDomElement|string
					如下示例使用表格展现数据值：
					optionToContent: function(opt) {
						var axisData = opt.xAxis[0].data;
						var series = opt.series;
						var table = '<table style="width:100%;text-align:center"><tbody><tr>'
									 + '<td>时间</td>'
									 + '<td>' + series[0].name + '</td>'
									 + '<td>' + series[1].name + '</td>'
									 + '</tr>';
						for (var i = 0, l = axisData.length; i < l; i++) {
							table += '<tr>'
									 + '<td>' + axisData[i] + '</td>'
									 + '<td>' + series[0].data[i] + '</td>'
									 + '<td>' + series[1].data[i] + '</td>'
									 + '</tr>';
						}
						table += '</tbody></table>';
						return table;
}
					更详细说明，可能参考：https://echarts.apache.org/zh/option.html#toolbox.feature.dataView.readOnly
			 参  数：<wzValue> ;
			 返回值：<无>;
			*************************************************/
			virtual void SetOptionToContentJSFun(const wchar_t* wzValue) = 0;

			/************************************************
			 功  能：在使用 optionToContent 的情况下，如果支持数据编辑后的刷新，需要自行通过该函数实现组装 option 的逻辑。
			 注  意：回调函数格式：
					(container:HTMLDomElement, option:Object) => Object
					更详细说明，可能参考：https://echarts.apache.org/zh/option.html#toolbox.feature.dataView.readOnly
			 参  数：<wzValue> ;
			 返回值：<无>;
			*************************************************/
			virtual void SetContentToOptionJSFun(const wchar_t* wzValue) = 0;

			/************************************************
			 功  能：数据视图上的话术。
					 每个数据的值之间使用“,”分隔;如：“周一,周二,周三,周四,周五”
			 参  数：<wzValue> 用“,”分隔的所有类目数据;
			 返回值：<无>;
			*************************************************/
			virtual void SetLang(const wchar_t* wzValue) = 0;

			/************************************************
			 功  能：数据视图上的话术。
			 参  数：<vctValue> 所有维度的值，单个元素为单个类目数据;
			 返回值：<无>;
			*************************************************/
			virtual int SetLang(const std::vector<std::wstring>& vctValue) = 0;

			/************************************************
			* 功  能：数据视图上的话术。
			* 参  数：<pQueue> 新的数据;
			* 返回值：<无>;
			*************************************************/
			virtual int SetLang(IQueue* pQueue) = 0;


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
			功  能：数据视图浮层文本输入区背景色。
			参  数：<wzValue> 可以用 RGB、RGBA、16进制三种字符串形式设置颜色。;
			返回值：<无>;
			*************************************************/
			virtual void SetTextareaColor(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetTextareaColor() const = 0;

			/************************************************
			功  能：以 RGBA 方式设置数据视图浮层文本输入区背景色。
			参  数：<略>;
			返回值：<无>;
			*************************************************/
			virtual void SetTextareaColor(int nR, int nG, int nB, float nTransparent = 1) = 0;
			virtual void GetTextareaColor(int* pnR, int* pnG, int* pnB, float* pnTransparent) = 0;


			/************************************************
			功  能：文本颜色
			参  数：<wzValue> 可以用 RGB、RGBA、16进制三种字符串形式设置颜色。;
			返回值：<无>;
			*************************************************/
			virtual void SetTextColor(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetTextColor() const = 0;

			/************************************************
			功  能：以 RGBA 方式设置文本颜色
			参  数：<略>;
			返回值：<无>;
			*************************************************/
			virtual void SetTextColor(int nR, int nG, int nB, float nTransparent = 1) = 0;
			virtual void GetTextColor(int* pnR, int* pnG, int* pnB, float* pnTransparent) = 0;

			/************************************************
			功  能：数据视图浮层文本输入区边框颜色。
			参  数：<wzValue> 可以用 RGB、RGBA、16进制三种字符串形式设置颜色。;
			返回值：<无>;
			*************************************************/
			virtual void SetTextareaBorderColor(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetTextareaBorderColor() const = 0;

			/************************************************
			功  能：以 RGBA 方式设置数据视图浮层文本输入区边框颜色。
			参  数：<略>;
			返回值：<无>;
			*************************************************/
			virtual void SetTextareaBorderColor(int nR, int nG, int nB, float nTransparent = 1) = 0;
			virtual void GetTextareaBorderColor(int* pnR, int* pnG, int* pnB, float* pnTransparent) = 0;

			/************************************************
			功  能：按钮颜色
			参  数：<wzValue> 可以用 RGB、RGBA、16进制三种字符串形式设置颜色。;
			返回值：<无>;
			*************************************************/
			virtual void SetButtonColor(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetButtonColor() const = 0;

			/************************************************
			功  能：以 RGBA 方式设置按钮颜色
			参  数：<略>;
			返回值：<无>;
			*************************************************/
			virtual void SetButtonColor(int nR, int nG, int nB, float nTransparent = 1) = 0;
			virtual void GetButtonColor(int* pnR, int* pnG, int* pnB, float* pnTransparent) = 0;


			/************************************************
			功  能：按钮文本颜色
			参  数：<wzValue> 可以用 RGB、RGBA、16进制三种字符串形式设置颜色。;
			返回值：<无>;
			*************************************************/
			virtual void SetButtonTextColor(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetButtonTextColor() const = 0;

			/************************************************
			功  能：以 RGBA 方式设置按钮文本颜色
			参  数：<略>;
			返回值：<无>;
			*************************************************/
			virtual void SetButtonTextColor(int nR, int nG, int nB, float nTransparent = 1) = 0;
			virtual void GetButtonTextColor(int* pnR, int* pnG, int* pnB, float* pnTransparent) = 0;
		};
	}
	
}