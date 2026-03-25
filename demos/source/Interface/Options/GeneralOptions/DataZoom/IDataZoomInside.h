#pragma once
/***********************************************************************
 * Module:  IVisualMapContinuous.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: 内置型数据区域缩放组件（dataZoomInside）
 * 
 * 所谓『内置』，即内置在坐标系中。
 * > 平移：在坐标系中滑动拖拽进行数据区域平移。
 * > 缩放：
 *     > PC端：鼠标在坐标系范围内滚轮滚动（MAC触控板类同）
 *     > 移动端：在移动端触屏上，支持两指滑动缩放。
 * 
 ***********************************************************************/
#include <vector>
#include <string>
#include "Common/IEnum.h"
#include "Common/ICallback.h"
#include "Common/IFixedQueue.h"
#include "Options/Common/IBaseArrayElement.h"
#include "Options/Common/ICategoryData.h"
#include "Options/GeneralOptions/VisualMap/IVisualMapController.h"
#include "Options/GeneralOptions/VisualMap/IVisualMapTextStyle.h"
#include "Options/GeneralOptions/VisualMap/IVisualMapHandleStyle.h"
#include "Options/GeneralOptions/VisualMap/IVisualMapIndicatorStyle.h"

namespace IIChart
{
	namespace DataZoom
	{
		
		/***********************************************************************
		 * Clsss:  IDataZoomInside.h
		 * Author:  杨鹏辉
		 * Modified: 2022年7月1日 15:02:44
		 * Purpose: 内置型数据区域缩放组件（dataZoomInside）
		 ***********************************************************************/
		class IDataZoomInside
			: public IBaseArrayElement
		{
		public:

			// 组件 ID。默认不指定。指定则可用于在 option 或者 API 中引用组件。
			virtual void SetId(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetId() const = 0;

			// 是否停止组件的功能。
			virtual void SetDisabled(bool bValue) = 0;
			virtual bool GetDisabled() const = 0;

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


			// 如何触发缩放。
			virtual void SetZoomOnMouseWheel(EZoomType eValue) =0;
			virtual EZoomType GetZoomOnMouseWheel() const = 0;

			// 如何触发数据窗口平移。
			virtual void SetMoveOnMouseMove(EZoomType eValue) = 0;
			virtual EZoomType GetMoveOnMouseMove() const = 0;

			// 如何触发数据窗口平移
			virtual void SetMoveOnMouseWheel(EZoomType eValue) = 0;
			virtual EZoomType GetMoveOnMouseWheel() const = 0;
			
			// 是否阻止 mousemove 事件的默认行为。
			virtual void SetPreventDefaultMouseMove(bool bValue) = 0;
			virtual bool GetPreventDefaultMouseMove() const = 0;
		};
	}
	
}