#pragma once
/***********************************************************************
 * Module:  IVisualMapPiecewise.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: 分段型视觉映射组件（visualMapPiecewise）
 *		分段型视觉映射组件，有三种模式：
 *			- 连续型数据平均分段: 依据 visualMap-piecewise.splitNumber 来自动平均分割成若干块。
 *			- 连续型数据自定义分段: 依据 visualMap-piecewise.pieces 来定义每块范围。
 *			- 离散数据根据类别分段: 类别定义在 visualMap-piecewise.categories 中。
 ***********************************************************************/
#include <vector>
#include <string>
#include "Common/IEnum.h"
#include "Common/ICallback.h"
#include "Common/IFixedQueue.h"
#include "Options/Common/IBaseArrayElement.h"
#include "Options/Common/ICategoryData.h"
#include "Options/GeneralOptions/DataZoom/IDataZoomDataBackground.h"
#include "Options/GeneralOptions/DataZoom/IDataZoomSliderSelectedDataBackground.h"
#include "Options/GeneralOptions/DataZoom/IDataZoomSliderHandleStyle.h"
#include "Options/GeneralOptions/DataZoom/IDataZoomSliderMoveHandleStyle.h"
#include "Options/GeneralOptions/DataZoom/IDataZoomSliderTextStyle.h"
#include "Options/GeneralOptions/DataZoom/IDataZoomSliderBrushStyle.h"
#include "Options/GeneralOptions/DataZoom/IDataZoomSliderEmphasis.h"


namespace IIChart
{
	namespace DataZoom
	{
		
		/***********************************************************************
		 * Clsss:  IDataZoomSlider.h
		 * Author:  杨鹏辉
		 * Modified: 2022年8月20日 15:02:44
		 * Purpose: 分段型视觉映射组件;
		 ***********************************************************************/
		class IDataZoomSlider
			: public IBaseArrayElement
		{
		public:

			// 组件 ID。默认不指定。指定则可用于在 option 或者 API 中引用组件。
			virtual void SetId(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetId() const = 0;

			
			/************************************************
			 功  能：以16进制字符串形式设置文字块背景色;如果设置为 'inherit'，则为视觉映射得到的颜色，如系列色。
			 注  意：为颜色值时，必须以'#'开头，
			 参  数：<wzValue> 背景色16进制行;
			 返回值：<无>;
			 ************************************************/
			virtual void SetBackgroundColor(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetBackgroundColor() const = 0;

			/************************************************
			 功  能：文字块背景色。如果设置为 'inherit'，则为视觉映射得到的颜色，如系列色。
			 参  数：<略>;
			 返回值：<无>;
			 ************************************************/
			virtual void SetBackgroundColor(int nR, int nG, int nB, float nTransparent = 1) = 0;
			virtual void GetBackgroundColor(int* pnR, int* pnG, int* pnB, float* pnTransparent) = 0;

			// 数据阴影的样式。
			virtual IDataZoomDataBackground* GetBackgroundColor() = 0;

			// 选中部分数据阴影的样式。
			virtual IDataZoomSliderSelectedDataBackground* GetSlectedDataBackground() = 0;

			
			/************************************************
			 功  能：以16进制字符串形式设置选中范围的填充颜色;如果设置为 'inherit'，则为视觉映射得到的颜色，如系列色。
			 注  意：为颜色值时，必须以'#'开头，
			 参  数：<wzValue> 背景色16进制行;
			 返回值：<无>;
			 ************************************************/
			virtual void SetFillerColor(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetFillerColor() const = 0;

			/************************************************
			 功  能：选中范围的填充颜色。如果设置为 'inherit'，则为视觉映射得到的颜色，如系列色。
			 参  数：<略>;
			 返回值：<无>;
			 ************************************************/
			virtual void SetFillerColor(int nR, int nG, int nB, float nTransparent = 1) = 0;
			virtual void GetFillerColor(int* pnR, int* pnG, int* pnB, float* pnTransparent) = 0;

			/************************************************
			 功  能：以16进制字符串形式设置边框颜色;
			 注  意：为颜色值时，必须以'#'开头，
			 参  数：<wzValue> 背景色16进制行;
			 返回值：<无>;
			 ************************************************/
			virtual void SetBorderColor(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetBorderColor() const = 0;

			/************************************************
			 功  能：边框颜色。
			 参  数：<略>;
			 返回值：<无>;
			 ************************************************/
			virtual void SetBorderColor(int nR, int nG, int nB, float nTransparent = 1) = 0;
			virtual void GetBorderColor(int* pnR, int* pnG, int* pnB, float* pnTransparent) = 0;

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
			virtual void SetHandleIcon(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetHandleIcon() const = 0;

			// 控制手柄的尺寸，可以是像素大小，也可以是相对于 dataZoom 组件宽度的百分比，默认跟 dataZoom 宽度相同。
			virtual void SetHandleSize(int nSize, bool bIsPercentage) = 0;
			virtual void GetHandleSize(int* pnSize, bool* pbIsPercentage) const = 0;

			// 两侧缩放手柄的样式配置。
			virtual IDataZoomSliderHandleStyle* GetHandleStyle() = 0;

			/************************************************
			 功  能：用图片设置 移动手柄中间的 icon
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
			virtual void SetMoveHandleIcon(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetMoveHandleIcon() const = 0;

			// 移动手柄的尺寸高度。
			virtual void SetMoveHandleSize(int nSize) = 0;
			virtual int  GetMoveHandleSize() const = 0;

			// 两侧缩放手柄的样式配置。
			virtual IDataZoomSliderMoveHandleStyle* GetMoveHandleStyle() = 0;

			// 显示label的小数精度。默认根据数据自动决定。
			virtual void SetLabelPrecision(int nValue) = 0;
			virtual int  GetLabelPrecision() const = 0;

			/************************************************
			 功  能：刻度标签的内容格式器的字符串模板。字符串模板与回调函数返回的字符串均支持用 \n 换行。
			 注  意：字符串模板的模板变量有：
					{a}：系列名。
					{b}：数据名。
					{c}：数据值。
					{@xxx}：数据中名为 'xxx' 的维度的值，如 {@product} 表示名为 'product' 的维度的值。
					{@[n]}：数据中维度 n 的值，如 {@[3]} 表示维度 3 的值，从 0 开始计数。示例：
					formatter: '{b}: {@score}'
					例如：aaaa{value}bbbb，其中{value}会被替换为实际的数值。
			 参  数：<wzValue> 字符串模板;
			 返回值：<无>;
			*************************************************/
			virtual void SetLabelFormatter(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetLabelFormatter()const = 0;

			/************************************************
			 功  能：刻度标签的内容格式器的JavaScript回调函数;字符串模板与回调函数返回的字符串均支持用 \n 换行。
			 注  意：回调函数格式,例如：
					 //
					 // @param {*} value 如果 axis.type 为 'category'，则 `value` 为 axis.data 的 index。
					 //                  否则 `value` 是当前值。
					 // @param {strign} valueStr 内部格式化的结果。
					 // @return {string} 返回最终的label内容。
					labelFormatter: function(value) {
						return 'aaa' + value + 'bbb';
					}
					更详细说明，可能参考：https://echarts.apache.org/zh/option.html#dataZoom-slider.labelPrecision
			 参  数：<wzValue> 字符串模板;
			 返回值：<无>;
			*************************************************/
			virtual void SetLabelFormatterJSFun(const wchar_t* wzValue) = 0;

			// 是否显示detail，即拖拽时候显示详细数值信息。
			virtual void SetShowDetail(bool bValue) = 0;
			virtual bool GetShowDetail()const = 0;

			// TODO: showDataShadow
			

			// 拖动时，是否实时更新系列的视图。如果设置为 false，则只在拖拽结束的时候更新。
			virtual void SetRealtime(bool bValue) = 0;
			virtual bool GetRealtime()const = 0;

			// 
			virtual IDataZoomSliderTextStyle* GetTextStyle() = 0;

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

			/************************************************
			* 功  能：设置 dataZoom-inside 组件控制的 radius轴序号;
			* 参  数：<nValue>;
			* 返回值：<无>;
			*************************************************/
			virtual void SetRadiusAxisIndex(int nValue) = 0;
			virtual int  GetRadiusAxisIndex() const = 0;

			/************************************************
			* 功  能：设置 dataZoom-inside 组件控制的 Radius轴序号;
			*         每个序号之间使用“,”分隔;
			* 参  数：<wzValue> 使用“,”分隔的序号;
			* 返回值：<无>;
			*************************************************/
			virtual int SetRadiusAxisIndex(const wchar_t* wzValue) = 0;

			/************************************************
			* 功  能：设置 dataZoom-inside 组件控制的 Radius轴序号;
			*         每个序号之间使用“,”分隔;
			* 参  数：<wzValue> 使用“,”分隔的序号;
			* 返回值：<无>;
			*************************************************/
			virtual void SetRadiusAxisIndex(const std::vector<int>& vctValue) = 0;

			/************************************************
			* 功  能：设置 dataZoom-inside 组件控制的 Angle轴序号;
			* 参  数：<nValue>;
			* 返回值：<无>;
			*************************************************/
			virtual void SetAngleAxisIndex(int nValue) = 0;
			virtual int  GetAngleAxisIndex() const = 0;

			/************************************************
			* 功  能：设置 dataZoom-inside 组件控制的 Angle轴序号;
			*         每个序号之间使用“,”分隔;
			* 参  数：<wzValue> 使用“,”分隔的序号;
			* 返回值：<无>;
			*************************************************/
			virtual int SetAngleAxisIndex(const wchar_t* wzValue) = 0;

			/************************************************
			功  能：设置 dataZoom-inside 组件控制的 Angle轴序号;
					每个序号之间使用“,”分隔;
			参  数：<wzValue> 使用“,”分隔的序号;
			返回值：<无>;
			*************************************************/
			virtual void SetAngleAxisIndex(const std::vector<int>& vctValue) = 0;

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
			功  能：数据窗口范围的起始百分比。范围是：0 ~ 100。表示 0% ~ 100%。
			参  数：<nValue> ;
			返回值：<无>;
			*************************************************/
			virtual void SetStart(int nValue) = 0;
			virtual int  GetStart() const = 0;

			/************************************************
			功  能：数据窗口范围的结束百分比。范围是：0 ~ 100。
			参  数：<nValue> ;
			返回值：<无>;
			*************************************************/
			virtual void SetEnd(int nValue) = 0;
			virtual int  GetEnd() const = 0;


			/************************************************
			功  能：数据窗口范围的起始数值。
					如果设置了 dataZoom-inside.start 则 startValue 失效。
			参  数：<nValue> ;
			返回值：<无>;
			*************************************************/
			virtual void SetStartValue(int nValue) = 0;
			virtual int  GetStartValue() const = 0;

			virtual void SetStartValue(const wchar_t* wzValue) = 0;
			virtual void GetStartValue(wchar_t** pwzValue) = 0;

			/************************************************
			功  能：数据窗口范围的结束数值。
					如果设置了 dataZoom-inside.end 则 endValue 失效。
			参  数：<nValue> ;
			返回值：<无>;
			*************************************************/
			virtual void SetEndValue(int nValue) = 0;
			virtual int  GetEndValue() const = 0;

			virtual void SetEndValue(const wchar_t* wzValu) = 0;
			virtual void GetEndValue(wchar_t** pwzValue) = 0;


			// 用于限制窗口大小的最小值（百分比值），取值范围是 0 ~ 100。
			virtual void SetMinSpan(int nValue) = 0;
			virtual int  GetMinSpan() const = 0;

			// 用于限制窗口大小的最大值（百分比值），取值范围是 0 ~ 100。
			virtual void SetMaxSpan(int nValue) = 0;
			virtual int  GetMaxSpan() const = 0;

			// 用于限制窗口大小的最小值（实际数值）。
			// 如在时间轴上可以设置为：3600 * 24 * 1000 * 5 表示 5 天。 在类目轴上可以设置为 5 表示 5 个类目。
			virtual void SetMinValueSpan(int nValue) = 0;
			virtual int  GetMinValueSpan() const = 0;

			// 用于限制窗口大小的最大值（实际数值）。
			// 如在时间轴上可以设置为：3600 * 24 * 1000 * 5 表示 5 天。 在类目轴上可以设置为 5 表示 5 个类目。
			virtual void SetMaxValueSpan(int nValue) = 0;
			virtual int  GetMaxValueSpan() const = 0;

			// 布局方式是横还是竖。不仅是布局方式，对于直角坐标系而言，也决定了，缺省情况控制横向数轴还是纵向数轴。
			virtual void SetOrient(EOrient eValue) = 0;
			virtual EOrient GetOrient() const = 0;

			// 是否锁定选择区域（或叫做数据窗口）的大小。
			// 如果设置为 true 则锁定选择区域的大小，也就是说，只能平移，不能缩放。
			virtual void SetZoomLock(bool eValue) = 0;
			virtual bool GetZoomLock() const = 0;

			// 设置触发视图刷新的频率。单位为毫秒（ms）。
			// 如果 animation 设为 true 且 animationDurationUpdate 大于 0，可以保持 throttle 为默认值 100（或者设置为大于 0 的值），否则拖拽时有可能画面感觉卡顿。
			// 如果 animation 设为 false 或者 animationDurationUpdate 设为 0，且在数据量不大时，拖拽时画面感觉卡顿，可以把尝试把 throttle 设为 0 来改善。
			virtual void SetThrottle(int nValue) = 0;
			virtual int  GetThrottle() const = 0;

			// TODO:rangeMode



			// 所有图形的 zlevel 值。
			// zlevel用于 Canvas 分层，不同zlevel值的图形会放置在不同的 Canvas 中，
			// Canvas 分层是一种常见的优化手段。我们可以把一些图形变化频繁（例如有动画）的
			// 组件设置成一个单独的zlevel。需要注意的是过多的 Canvas 会引起内存开销的增大，
			// 在手机端上需要谨慎使用以防崩溃。
			// zlevel 大的 Canvas 会放在 zlevel 小的 Canvas 的上面。
			virtual void SetZLevel(int nLevel) = 0;
			virtual int GetZLevel() const = 0;

			// 组件的所有图形的z值。控制图形的前后顺序。z值小的图形会被z值大的图形覆盖。
			// z相比zlevel优先级更低，而且不会创建新的 Canvas。
			virtual void SetZ(int nLevel) = 0;
			virtual int GetZ() const = 0;

			// visualMap 组件离容器左侧的距离。
			virtual void SetLeft(int nValue) = 0;
			virtual int  GetLeft() const = 0;

			// visualMap 组件离容器左侧的距离。组件会根据相应的位置自动对齐
			virtual void SetLeft(EAlign eValue) = 0;
			virtual void GetLeft(EAlign* peValue) = 0;

			// visualMap 组件离容器上侧的距离。
			virtual void SetTop(int nValue) = 0;
			virtual int  GetTop() const = 0;

			// visualMap 组件离容器上侧的距离。组件会根据相应的位置自动对齐
			virtual void SetTop(EVerticalAlign eValue) = 0;
			virtual void GetTop(EVerticalAlign* peValue) = 0;

			// visualMap 组件离容器右侧的距离。
			// 值可以是像 20 这样的具体像素值，可以是像 '20%' 这样相对于容器高宽的百分比。
			virtual void SetRight(int nValue, bool bIsPercentage) = 0;
			virtual void GetRight(int* pnValue, bool* pbIsPercentage) = 0;

			// visualMap 组件离容器下侧的距离。
			// bottom 的值可以是像 20 这样的具体像素值，可以是像 '20%' 这样相对于容器高宽的百分比。
			virtual void SetBottom(int nValue, bool bIsPercentage) = 0;
			virtual void GetBottom(int* pnValue, bool* pbIsPercentage) = 0;

			// 是否开启刷选功能。在下图的 brush 区域你可以按住鼠标左键后框选出选中部分。
			virtual void SetBrushSelect(bool bValue) = 0;
			virtual bool GetBrushSelect() const = 0;

			// 刷选框样式设置。
			virtual IDataZoomSliderBrushStyle* GetBrushStyle() = 0;
			
			// 高亮样式设置。
			virtual IDataZoomSliderEmphasis* GetEmphasis() = 0;
		};
	}
	
}