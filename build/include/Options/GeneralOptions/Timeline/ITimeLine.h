#pragma once
/***********************************************************************
 * Module:  ITimeLine.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: timeline 组件，提供了在多个 ECharts option 间进行切换、播放等操作的功能。
 * 提示框组件的通用介绍：
 *		提示框组件可以设置在多种地方：
 *		可以设置在全局，即 tooltip
 *		可以设置在坐标系中，即 grid.tooltip、polar.tooltip、single.tooltip
 *		可以设置在系列中，即 series.tooltip
 *		可以设置在系列的每个数据项中，即 series.data.tooltip
 ***********************************************************************/
#include <vector>
#include "Common\IEnum.h"
#include "Common/IFixedQueue.h"
#include "Options\Common\IBaseArrayElement.h"
#include "Options\Common\ITextStyle.h"
#include "Options/GeneralOptions/TimeLine/ITimeLineLabel.h"
#include "Options/GeneralOptions/TimeLine/ITimeLineCheckpointStyle.h"
#include "Options/GeneralOptions/TimeLine/ITimeLineControlStyle.h"
#include "Options/GeneralOptions/TimeLine/ITimeLineData.h"
#include "Options/GeneralOptions/TimeLine/ITimeLineEmphasis.h"
#include "Options/GeneralOptions/TimeLine/ITimeLineItemStyle.h"
#include "Options/GeneralOptions/TimeLine/ITimeLineLineStyle.h"
#include "Options/GeneralOptions/TimeLine/ITimeLineProgress.h"

namespace IIChart
{
	namespace TimeLine
	{
		/***************************
	    * ITimeLine 组件;
	    ****************************/
		class ITimeLine
		{
		public:
			// 是否显示 x/y 轴
			virtual void SetShow(bool bValue) = 0;
			virtual bool GetShow() const = 0;

			// 这个属性目前只支持为 slider，不需要更改。
			virtual void SetType(ETimeLineType eValue) = 0;
			virtual ETimeLineType GetTrigger() const = 0;

			// 轴的类型
			virtual void SetAxisType(ETimeLineAxisType eValue) = 0;
			virtual ETimeLineAxisType GetAxisType() const = 0;

			// 表示当前选中项是哪项。比如，currentIndex 为 0 时，表示当前选中项为 timeline.data[0]（即使用 options[0]）。
			virtual void SetCurrentIndex(int nValue) = 0;
			virtual int  GetCurrentIndex() const = 0;

			// 表示是否自动播放。
			virtual void SetAutoPlay(bool bValue) = 0;
			virtual bool GetAutoPlay() const = 0;

			// 表示是否反向播放。
			virtual void SetRewind(bool bValue) = 0;
			virtual bool GetRewind() const = 0;

			// 表示是否循环播放。
			virtual void SetLoop(bool bValue) = 0;
			virtual bool GetLoop() const = 0;

			// 表示播放的速度（跳动的间隔），单位毫秒（ms）。
			virtual void SetPlayInterval(int nValue) = 0;
			virtual int  GetPlayInterval() const = 0;

			// 拖动圆点的时候，是否实时更新视图。
			virtual void SetRealtime(int nValue) = 0;
			virtual bool GetRealtime() const = 0;

			// TODO:replaceMerge

			// 表示『播放』按钮的位置
			virtual void SetControlPosition(ETimeLineControlPosition eValue) = 0;
			virtual ETimeLineControlPosition GetControlPosition()const = 0;

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

			// 如何放置 visualMap 组件，水平（'horizontal'）或者竖直（'vertical'）。
			virtual void SetOrient(EOrient eValue) = 0;
			virtual EOrient GetOrient()const = 0;

			// visualMap-continuous内边距，单位px，默认各方向内边距为5，接受数组分别设定上右下左边距。例如：
			// 4：表示 padding: [4, 4, 4, 4];
			// 注意，visualMap-continuous内边距的 width 和 height 指定的是内容高宽，不包含 padding。
			virtual void  SetPadding(int nValue) = 0;
			virtual void  GetPadding(int* pnValue) = 0;

			// visualMap-continuous内边距，单位px，默认各方向内边距为5，接受数组分别设定上右下左边距。例如：
			// [3, 4]：表示 padding: [3, 4, 3, 4]。
			// 注意，visualMap-continuous内边距的 width 和 height 指定的是内容高宽，不包含 padding。
			virtual void  SetPadding(int nValue1, int nValue2) = 0;
			virtual void  GetPadding(int* pnValue1, int* pnValue2) = 0;

			// visualMap-continuous内边距，单位px，默认各方向内边距为5，接受数组分别设定上右下左边距。例如：
			// [3, 4, 5, 6]：表示 [上, 右, 下, 左] 的边距。
			// 注意，visualMap-continuous内边距的 width 和 height 指定的是内容高宽，不包含 padding。
			virtual void SetPadding(int nTop, int nRight, int nBottom, int nLeft) = 0;
			virtual void GetPadding(int* pnTop, int* pnRight, int* pnBottom, int* pnLeft) = 0;

			// 是否反向放置 timeline，反向则首位颠倒过来。
			virtual void SetInverse(bool bValue) = 0;
			virtual bool GetInverse() const = 0;

			/************************************************
			 功  能：设置 标记的图形
			 参  数：<nValue>;
			 返回值：<无>;
			*************************************************/
			virtual void SetSymbol(ESymbol nValue) = 0;
			virtual ESymbol GetSymbol() const = 0;

			/************************************************
			 功  能：用图片设置 标记的图形
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
			virtual void SetSymbolImage(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetSymbolImage() const = 0;

			// 标记的大小，可以设置成诸如 10 这样单一的数字
			virtual void SetSymbolSize(int nSize) = 0;
			virtual int GetSymbolSize() const = 0;

			// 标记的大小，高度
			virtual void SetSymbolSize(int nHeight, int nWidth) = 0;
			virtual void GetSymbolSize(int& nHeight, int& nWidth) = 0;

			// 标记的旋转角度（而非弧度）,正值表示逆时针旋转。
			// 注意在 markLine 中当 symbol 为 'arrow' 时会忽略 symbolRotate 强制设置为切线的角度。
			virtual void SetSymbolRotate(int nRotate) = 0;
			virtual int GetSymbolRotate() const = 0;

			// 如果 symbol 是 path:// 的形式，是否在缩放时保持该图形的长宽比。
			virtual void SetSymbolKeepAspect(bool bValue) = 0;
			virtual bool GetSymbolKeepAspect() const = 0;

			/************************************************
			 功  能：标记相对于原本位置的偏移。
			 注  意：默认情况下，标记会居中置放在数据对应的位置
					 但是如果 symbol 是自定义的矢量路径或者图片，就有可能不希望 symbol 居中。
					 这时候可以使用该配置项配置 symbol 相对于原本居中的偏移，此处为绝对的像素值，
			 参  数：<nX> 水平偏移;
					 <nY> 垂直偏移;
					 <bIsPercentage> 默认为false，表示偏移值为像素，否则为百分比;
			 返回值：<无>;
			*************************************************/
			virtual void SetSymbolOffset(int nX, int nY, bool bIsPercentage) = 0;
			virtual void GetSymbolOffset(int* pnX, int* pnY, bool* pbIsPercentage) = 0;

			virtual ITimeLineLineStyle* GetLineStyle() = 0;

			// 轴的文本标签。
			virtual ITimeLineLabel* GetLabel() = 0;

			// timeline 图形样式。
			virtual ITimeLineItemStyle* GetItemStyle() = 0;

			// 『当前项』（checkpoint）的图形样式。
			virtual ITimeLineCheckpointStyle* GetCheckpointStyle() = 0;

			// 『控制按钮』的样式。『控制按钮』包括：『播放按钮』、『前进按钮』、『后退按钮』。
			virtual ITimeLineControlStyle* GetControlStyle() = 0;

			// 进度条中的线条，拐点，标签的样式。
			virtual ITimeLineProgress* GetProgress() = 0;

			// emphasis 是文本高亮的样式，比如鼠标悬浮或者图例联动高亮的时候会使用 emphasis 作为文本的样式。
			virtual ITimeLineEmphasis* GetEmphasis() = 0;

			virtual ITimeLineData* CreateData() = 0;
			virtual ITimeLineData* CreateData(const wchar_t* wzValue) = 0;

			/************************************************
			* 功  能：清空 Data 数据;
			* 返回值：<错误码>;
			*************************************************/
			virtual void ClearData() = 0;

			/************************************************
			* 功  能：使用  定义 series.data 或者 dataset.source 的每个维度的信息。
			* 注  意：此接口创建的数据项可以作为IFixedQueue的元素
			*         -- 使用完后需要调用 Release 释放相资源;
			*         -- IFixedQueue中的元素将由其自动进行内存回收管理;
			* 参  数：<wzName> 名称;
			*         <eType> 类型;
			*         <wzDisplayName> 数据描述;
			* 返回值：ILineTypeData*;
			*************************************************/
			virtual ITimeLineData* CreateData() = 0;
			virtual ITimeLineData* CreateData(const wchar_t* wzValue) = 0;

			/************************************************
			* 功  能：添加纬度的值，如果此维度不想给出定义，则使用 nullptr 即可;
			* 参  数：<wzName> 名称;
			*         <eType> 类型;
			*         <wzDisplayName> 数据描述;
			* 返回值：<错误码>;
			*************************************************/
			virtual int AddData(ITimeLineData* pData) = 0;
			virtual int AddData(const wchar_t* wzName, EDDTypeValue eType, const wchar_t* wzDisplayName = nullptr) = 0;

			/************************************************
			* 功  能：在原来的数据后追加新数据;
			*         每个纬度的值之间使用“,”分隔;如：“date,open,close,highest,lowest”
			* 参  数：<wzValue> 使用“,”分隔的;
			* 返回值：<无>;
			*************************************************/
			virtual int Add(const wchar_t* wzValue) = 0;

			/************************************************
			* 功  能：在原来的数据后追加新数据;
			* 参  数：<vctValue>  数据;
			* 返回值：<无>;
			*************************************************/
			virtual int Add(const std::vector<wchar_t*>& vctValue) = 0;

			/************************************************
			* 功  能：在原来的 数据后追加新数据。
			* 参  数：<pQueue> 新的数据;
			* 返回值：<无>;
			*************************************************/
			virtual int Add(IFixedQueue* pQueue) = 0;

			/************************************************
			* 功  能：设置新数据，每个值之间使用“,”分隔;原来的数据将被覆盖掉;
			* 参  数：<wzValue> 使用“,”分隔的;
			* 返回值：<无>;
			*************************************************/
			virtual void Set(const wchar_t* wzValue) = 0;

			/************************************************
			* 功  能：设置新数据。原来的数据将被覆盖掉;
			* 参  数：<vctValue>  数据;
			* 返回值：<无>;
			*************************************************/
			virtual void Set(const std::vector<wchar_t*>& vctValue) = 0;

			/************************************************
			* 功  能：设置新数据。
			* 注  意：原来的数据将被覆盖掉;
			*         此接口可以方便的实现动态图表显示;
			* 参  数：<pQueue> 新的数据;
			* 返回值：<无>;
			*************************************************/
			virtual int Set(IFixedQueue* pQueue) = 0;
		};
	}
	
}