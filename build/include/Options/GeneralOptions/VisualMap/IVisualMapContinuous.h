#pragma once
/***********************************************************************
 * Module:  IVisualMapContinuous.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: Declaration of the class IComponents
 ***********************************************************************/
#include <vector>
#include <string>
#include "Common/IEnum.h"
#include "Common/ICallback.h"
#include "Common/IFixedQueue.h"
#include "Options/Common/\ICategoryData.h"
#include "Options/Common/IBaseArrayElement.h"
#include "Options/GeneralOptions/VisualMap/IVisualMapTarget.h"
#include "Options/GeneralOptions/VisualMap/IVisualMapController.h"
#include "Options/GeneralOptions/VisualMap/IVisualMapTextStyle.h"
#include "Options/GeneralOptions/VisualMap/IVisualMapHandleStyle.h"
#include "Options/GeneralOptions/VisualMap/IVisualMapIndicatorStyle.h"

namespace IIChart
{
	namespace VisualMap
	{
		 /*@class
		 *************************************************************************
		 * 类  名: IVisualMapContinuous
		 * 修  改: 2022年7月1日 15:02:44
		 * 功  能: 连续型视觉映射组件（visualMapContinuous）;
		 -----------------------------------------------------------------------
		 作  者:  YangPenghui 2022-10-26;
		 ************************************************************************/
		class IVisualMapContinuous
			: virtual public IBaseArrayElement
		{
		public:

			/*@function
			******************************************************************
			功  能：组件 ID。默认不指定。指定则可用于在 option 或者 API 中引用组件。
			参  数: <wzValue> ;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual int SetId(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetId() const = 0;

			/*@function
			******************************************************************
			功  能：指定 visualMapContinuous 组件的允许的最小值;
			注  意：此值必须由用户指定。[visualMap.min, visualMax.max] 形成了视觉映射的『定义域』
			参  数: <wzValue> ;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void SetMin(int nValue) = 0;
			virtual int  GetMin() const = 0;

			/*@function
			******************************************************************
			功  能：指定 visualMapContinuous 组件的允许的最大值;
			注  意：此值必须由用户指定。[visualMap.min, visualMax.max] 形成了视觉映射的『定义域』
			参  数: <wzValue> ;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void SetMax(int nValue) = 0;
			virtual int  GetMax() const = 0;

			/*@function
			******************************************************************
			功  能：指定手柄对应数值的位置。range 应在 min max 范围内;
			注  意：以下两种情况的处理，有区别：
			        1. 如果 range 不设置（或设置为 null）
					   不设置 range，则 range 默认为 [min, max]，即 [10, 300]。
					   再次使用 setOption 改变 min、max，range 也自然会更新成改变过后的 [min, max]
					2. 如果 range 被以具体值设置了（例如设置为 [10, 300]），例如
					   使用 chart.setOption({visualMap: {min: 10, max: 300, range: [20, 80]}}); 
					   此时，再次使用 setOption 改变 min、max，如
					   chart.setOption({visualMap: {min: 0, max: 400}});
					   此时 range 不会改变而仍维持本来的数值，仍为 [20, 80]
					   如果，这个时候再把 range 设为 null，如：
					   chart.setOption({visualMap: {range: null}});
					   则 range 恢复为 [min, max]，即 [0, 400]，同时也恢复了自动随 min max 而改变的能力。
			参  数: <nStart> Range 的起始值;
			        <nEnd> Range 的终止值;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void SetRange(int nStart, int nEnd) = 0;
			virtual void GetRange(int* pnStart, int* pnEnd) = 0;

			/*@function
			******************************************************************
			功  能：把 range 设为 null,使用 Range 恢复自动随 min max 而改变的能力;
			注  意：以下两种情况的处理，有区别：
					1. 如果 range 不设置（或设置为 null）
					   不设置 range，则 range 默认为 [min, max]，即 [10, 300]。
					   再次使用 setOption 改变 min、max，range 也自然会更新成改变过后的 [min, max]
					2. 如果 range 被以具体值设置了（例如设置为 [10, 300]），例如
					   使用 chart.setOption({visualMap: {min: 10, max: 300, range: [20, 80]}});
					   此时，再次使用 setOption 改变 min、max，如
					   chart.setOption({visualMap: {min: 0, max: 400}});
					   此时 range 不会改变而仍维持本来的数值，仍为 [20, 80]
					   如果，这个时候再把 range 设为 null，如：
					   chart.setOption({visualMap: {range: null}});
					   则 range 恢复为 [min, max]，即 [0, 400]，同时也恢复了自动随 min max 而改变的能力。
			参  数: <无> ;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void ClearRange() = 0;

			/*@function
			******************************************************************
			功  能：是否显示拖拽用的手柄（手柄能拖拽调整选中范围）;
			参  数: <bValue> ;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void SetCalculable(bool bValue) = 0;
			virtual bool GetCalculable() const = 0;

			/*@function
			******************************************************************
			功  能：拖拽时，是否实时更新;
			参  数: <bValue> 如果为true则拖拽手柄过程中实时更新图表视图;
			                 如果为false则拖拽结束时，才更新视图;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void SetRealtime(bool bValue) = 0;
			virtual bool GetRealtime() const = 0;

			/*@function
			******************************************************************
			功  能：是否反转 visualMap 组件;
			参  数: <bValue> 为false时，数据大小的位置规则，和直角坐标系相同，即;
							 > 当 visualMap.orient 为'vertical'时，数据上大下小。
							 > 当 visualMap.orient 为'horizontal'时，数据右大左小。
							 为true时，上述情况相反。
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void SetInverse(bool bValue) = 0;
			virtual bool GetInverse() const = 0;

			/*@function
			******************************************************************
			功  能：数据展示的小数精度;
			参  数: <nValue> 默认为0，无小数点
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void SetPrecision(int nValue) = 0;
			virtual int  GetPrecision() const = 0;

			/*@function
			******************************************************************
			功  能：图形的宽度，即长条的宽度;
			参  数: <nValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void SetItemWidth(int nValue) = 0;
			virtual int  GetItemWidth() const = 0;

			/*@function
			******************************************************************
			功  能：图形的高度，即长条的高度;
			参  数: <nValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void SetItemHeight(int nValue) = 0;
			virtual int  GetItemHeight() const = 0;

			/*@function
			******************************************************************
			功  能：指定组件中手柄和文字的摆放位置;
			参  数: <nValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void SetAlign(EVisualMapAlign eValue) = 0;
			virtual EVisualMapAlign GetAlign() const = 0;

			/*@function
			******************************************************************
			功  能：两端的文本，如 ['High', 'Low'];
			参  数: <wzStart> 为 nullptr 时，不显示起始文本;
			        <wzEnd> 为 nullptr 时，不显示结束文本;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void SetText(const wchar_t* wzStart, const wchar_t* wzEnd) = 0;
			virtual void GetText(wchar_t** pwzStart, wchar_t** pwzEnd) = 0;

			/*@function
			******************************************************************
			功  能：两端文字主体之间的距离，单位为 px;
			参  数: <nValue> ;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void SetTextGap(int nValue) = 0;
			virtual int  GetTextGap() const = 0;

			/*@function
			******************************************************************
			功  能：是否显示 visualMap-continuous 组件;
			参  数: <bValue> 如果设置为 false，不会显示，但是数据映射的功能还存在;;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void SetShow(bool bValue) = 0;
			virtual bool GetShow() const = 0;

			/*@function
			******************************************************************
			功  能：指定用数据的『哪个维度』，映射到视觉元素上;
			参  数: <nValue> 默认取 data 中最后一个维度;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void SetDimension(int nValue) = 0;
			virtual int  GetDimension() const = 0;

			/*@function
			******************************************************************
			功  能：指定取哪个系列的数据，即哪个系列的 series.data;
			参  数: <nValue> 默认取 data 中最后一个维度;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void SetSeriesIndex(int nGridIndex) = 0;
			virtual int  GetSeriesIndex() const = 0;

			/*@function
			******************************************************************
			功  能：指定取哪个系列的数据，即哪个系列的 series.data;
			参  数: <wzValue> 使用“,”分隔的SeriesIndex;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual int SetSeriesIndex(const wchar_t* wzValue) = 0;

			/*@function
			******************************************************************
			功  能：指定取哪个系列的数据，即哪个系列的 series.data;
			参  数: <vctValue> SeriesIndex;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual int SetSeriesIndex(const std::vector<int>& vctValue) = 0;

			/*@function
			******************************************************************
			功  能：指定取哪个系列的数据，即哪个系列的 series.data;
			参  数: <pnValue> 数组指针;
			        <nCount>  数组元素个数;  
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual int SetSeriesIndex(int* pnValue, int nCount) = 0;

			/*@function
			******************************************************************
			功  能：打开 hoverLink 功能时，鼠标悬浮到 visualMap 组件上时，鼠标位置对应
			        的数值 在 图表中对应的图形元素，会高亮。反之，鼠标悬浮到图表中的图
					形元素上时，在 visualMap 组件的相应位置会有三角提示其所对应的数值。
			参  数: <bValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void SetHoverLink(bool bValue) = 0;
			virtual bool GetHoverLink() const = 0;

			/*@function
			******************************************************************
			功  能：获取本组件的 inRange 实例;
			参  数: <无>;
			返回值：<IVisualMapRange*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual IVisualMapRange* GetInRange() = 0;

			/*@function
			******************************************************************
			功  能：获取本组件的 outOfRange 实例;
			参  数: <无>;
			返回值：<IVisualMapRange*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual IVisualMapRange* GetOutOfRange() = 0;

			/*@function
			******************************************************************
			功  能：visualMap 组件中，控制器 的 inRange outOfRange 设置。
			注  意：如果没有这个 controller 设置，控制器 会使用外层的 inRange outOfRange 设置；
			        如果有这个 controller 设置，则会采用这个设置。适用于一些控制器视觉效果需要
					特殊定制或调整的场景。
			参  数: <无>;
			返回值：<IVisualMapController*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual IVisualMapController* GetController() = 0;

			/*@function
			******************************************************************
			功  能：目标系列 的视觉样式
			参  数: <无>;
			返回值：<IVisualMapTarget*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual IVisualMapTarget* GetTarget() = 0;

			/*@function
			******************************************************************
			功  能：所有图形的 zlevel 值。
			注  意: zlevel用于 Canvas 分层，不同zlevel值的图形会放置在不同的 Canvas 中，
					Canvas 分层是一种常见的优化手段。我们可以把一些图形变化频繁（例如有动画）的
					组件设置成一个单独的zlevel。需要注意的是过多的 Canvas 会引起内存开销的增大，
					在手机端上需要谨慎使用以防崩溃。
					zlevel 大的 Canvas 会放在 zlevel 小的 Canvas 的上面。
			参  数: <nLevel> ;
			返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetZLevel(int nLevel) = 0;
			virtual int  GetZLevel() const = 0;

			/*@function
			******************************************************************
			功  能：组件的所有图形的z值。控制图形的前后顺序。z值小的图形会被z值大的图形覆盖。
			注  意: z相比zlevel优先级更低，而且不会创建新的 Canvas。
			参  数: <nLevel> ;
			返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetZ(int nLevel) = 0;
			virtual int  GetZ() const = 0;

			/*@function
			******************************************************************
			功  能：grid 组件离容器左侧的距离。
			参  数: <nValue> ;
				   <bIsPercent> 为 true 时 nValue 为距离左边界的百分比；
								为 false 时 nValue 为距离左边界的像素个数；
			返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetLeft(int nValue, bool bIsPercent = false) = 0;
			virtual int GetLeft() const = 0;

			/*@function
			******************************************************************
			功  能：grid 组件离容器左侧的距离。
			注  意: 此种形式的设置，组件会根据相应的位置自动对齐
			参  数: <eValue> ;
			返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetLeft(ELeftValue eValue) = 0;
			virtual void GetLeft(ELeftValue* peValue) = 0;

			/*@function
			******************************************************************
			功  能：grid 组件离容器顶边的距离。
			参  数: <nValue> ;
				   <bIsPercent> 为 true 时 nValue 为距离顶边界的百分比；
								 为 false 时 nValue 为距离顶边界的像素个数；
			返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetTop(int nValue, bool bIsPercent = false) = 0;
			virtual int GetTop() const = 0;

			/*@function
			******************************************************************
			功  能：grid 组件离容器顶边的距离。
			注  意: 此种形式的设置，组件会根据相应的位置自动对齐
			参  数: <eValue> ;
			返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetTop(ETopValue eValue) = 0;
			virtual void GetTop(ETopValue* peValue) = 0;

			/*@function
			******************************************************************
			功  能：grid 组件离容器右侧的距离。
			参  数：<nValue> ;
					<bIsPercent> 为 true 时 nValue 为距离右侧边界的百分比；
								 为 false 时 nValue 为距离右侧边界的像素个数；
			返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetRight(int nValue, bool bIsPercent) = 0;
			virtual int GetRight() const = 0;

			/*@function
			******************************************************************
			功  能：grid 组件离容器底边界的距离。。
			参  数：<nValue> ;
					<bIsPercent> 为 true 时 nValue 为距离底边界的百分比；
								 为 false 时 nValue 为距离底边界的像素个数；
			返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetBottom(int nValue, bool bIsPercent) = 0;
			virtual int GetBottom() const = 0;

			/*@function
			******************************************************************
			功  能：如何放置 visualMap 组件，水平（'horizontal'）或者竖直（'vertical'）。
			参  数：<eValue> ;
			返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetOrient(EOrient eValue) = 0;
			virtual EOrient GetOrient()const = 0;

			/*@function
			******************************************************************
			功  能：visualMap-continuous内边距，单位 px;
			注  意: 默认各方向内边距为5，接受数组分别设定上右下左边距。
			参  数：<nValue> 边距值，例如 4：表示 padding: [4, 4, 4, 4];;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void  SetPadding(int nValue) = 0;
			virtual void  GetPadding(int* pnValue) = 0;

			/*@function
			******************************************************************
			功  能：visualMap-continuous内边距，单位 px;
			注  意: 默认各方向内边距为5，接受数组分别设定上右下左边距。
			参  数：<nValue1> 边距值1
				   <nValue2> 边距值2
				   例如 [3, 4]：表示 padding: [3, 4, 3, 4];
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void  SetPadding(int nValue1, int nValue2) = 0;
			virtual void  GetPadding(int* pnValue1, int* pnValue2) = 0;

			/*@function
			******************************************************************
			功  能：visualMap-continuous内边距，单位 px;
			注  意: 默认各方向内边距为5，接受数组分别设定上右下左边距。
			参  数：<nTop, nRight, nBottom, nLeft> 分别表示 [上, 右, 下, 左] 的边距
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetPadding(int nTop, int nRight, int nBottom, int nLeft) = 0;
			virtual void GetPadding(int* pnTop, int* pnRight, int* pnBottom, int* pnLeft) = 0;

			/*@function
			******************************************************************
			功  能：背景色，默认透明。
			注  意：为颜色值时，必须以'#'开头，
					 1. 可以使用 RGB 表示，比如 'rgb(128, 128, 128)'\
					 2. 如果想要加上 alpha 通道，可以使用 RGBA，比如 'rgba(128, 128, 128, 0.5)'
					 3. 可以使用十六进制格式，比如 '#ccc'
					 4. 可以使用 CSS3 预定义的颜色名称，如'red'，'SlateGray';
			参  数：<wzValue> 背景色16进制行;
			返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetBackgroundColor(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetBackgroundColor() const = 0;

			/*@function
			******************************************************************
			功  能：背景色，默认透明。
			参  数：<略>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetBackgroundColor(int nR, int nG, int nB, float fTransparent = 1) = 0;
			virtual void GetBackgroundColor(int* pnR, int* pnG, int* pnB, float* pfTransparent) = 0;

			/*@function
			******************************************************************
			功  能：边框颜色。
			注  意：为颜色值时，必须以'#'开头，
					 1. 可以使用 RGB 表示，比如 'rgb(128, 128, 128)'\
					 2. 如果想要加上 alpha 通道，可以使用 RGBA，比如 'rgba(128, 128, 128, 0.5)'
					 3. 可以使用十六进制格式，比如 '#ccc'
					 4. 可以使用 CSS3 预定义的颜色名称，如'red'，'SlateGray';
			参  数：<wzValue> 背景色16进制行;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetBorderColor(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetBorderColor() const = 0;

			/*@function
			******************************************************************
			功  能：边框颜色。
			参  数：<略>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetBorderColor(int nR, int nG, int nB, float fTransparent = 1) = 0;
			virtual void GetBorderColor(int* pnR, int* pnG, int* pnB, float* pfTransparent) = 0;

			/*@function
			******************************************************************
			功  能：边框线宽。
			参  数：<nValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetBorderWidth(int nValue) = 0;
			virtual int GetBorderWidth() const = 0;

			/*@function
			******************************************************************
			功  能：visualMap 文字的样式;
			参  数：<无>;
			返回值：<IVisualMapTextStyle*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IVisualMapTextStyle* GetTextStyle() = 0;

			/*@function
			******************************************************************
			功  能：标签的格式化工具。
			注  意：字符串模板的模板变量有：
				{a}：系列名。
				{b}：数据名。
				{c}：数据值。
				{@xxx}：数据中名为 'xxx' 的维度的值，如 {@product} 表示名为 'product' 的维度的值。
				{@[n]}：数据中维度 n 的值，如 {@[3]} 表示维度 3 的值，从 0 开始计数。示例：
				formatter: '{b}: {@score}'
			参  数：<wzValue> 字符串模板;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetFormatter(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetFormatter() const = 0;

			/*@function
			******************************************************************
			 功  能：标签的格式化工具。
			 注  意：回调函数格式：
					(params: Object|Array) => string
					参数 params 是 formatter 需要的单个数据集。格式如下：
					{
						componentType: 'series',
						// 系列类型
						seriesType: string,
						// 系列在传入的 option.series 中的 index
						seriesIndex: number,
						// 系列名称
						seriesName: string,
						// 数据名，类目名
						name: string,
						// 数据在传入的 data 数组中的 index
						dataIndex: number,
						// 传入的原始数据项
						data: Object,
						// 传入的数据值。在多数系列下它和 data 相同。在一些系列下是 data 中的分量（如 map、radar 中）
						value: number|Array|Object,
						// 坐标轴 encode 映射信息，
						// key 为坐标轴（如 'x' 'y' 'radius' 'angle' 等）
						// value 必然为数组，不会为 null/undefied，表示 dimension index 。
						// 其内容如：
						// {
						//     x: [2] // dimension index 为 2 的数据映射到 x 轴
						//     y: [0] // dimension index 为 0 的数据映射到 y 轴
						// }
						encode: Object,
						// 维度名列表
						dimensionNames: Array<String>,
						// 数据的维度 index，如 0 或 1 或 2 ...
						// 仅在雷达图中使用。
						dimensionIndex: number,
						// 数据图形的颜色
						color: string
					}
					更详细说明，可能参考：https://echarts.apache.org/zh/option.html#series-line.type
			 参  数：<wzValue> 字符串模板;
			 返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetFormatterJSFun(const wchar_t* wzValue) = 0;

			/*@function
			******************************************************************
			 功  能：两端手柄的形状.
			 注  意：本接口参数只能是以下几种形式：
					 1. 图片链接：
					 'image://http://example.website/a/b.png'
					 2. dataURI：
					 'image://data:image/gif;base64,R0lGODlhEAAQAMQAAORHHOVSKudfOulrSOp3WOyDZu6QdvCchPGolfO0o/XBs/fNwfjZ0frl3/zy7////wAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACH5BAkAABAALAAAAAAQABAAAAVVICSOZGlCQAosJ6mu7fiyZeKqNKToQGDsM8hBADgUXoGAiqhSvp5QAnQKGIgUhwFUYLCVDFCrKUE1lBavAViFIDlTImbKC5Gm2hB0SlBCBMQiB0UjIQA7'
					 3. 矢量路径：（可以参考 https://www.w3.org/TR/SVG/paths.html#PathData）
					 'path://M30.9,53.2C16.8,53.2,5.3,41.7,5.3,27.6S16.8,2,30.9,2C45,2,56.4,13.5,56.4,27.6S45,53.2,30.9,53.2z M30.9,3.5C17.6,3.5,6.8,14.4,6.8,27.6c0,13.3,10.8,24.1,24.101,24.1C44.2,51.7,55,40.9,55,27.6C54.9,14.4,44.1,3.5,30.9,3.5z M36.9,35.8c0,0.601-0.4,1-0.9,1h-1.3c-0.5,0-0.9-0.399-0.9-1V19.5c0-0.6,0.4-1,0.9-1H36c0.5,0,0.9,0.4,0.9,1V35.8z M27.8,35.8 c0,0.601-0.4,1-0.9,1h-1.3c-0.5,0-0.9-0.399-0.9-1V19.5c0-0.6,0.4-1,0.9-1H27c0.5,0,0.9,0.4,0.9,1L27.8,35.8L27.8,35.8z'
			 参  数：<wzValue>图片的 URL 或 dataURI也可以是 Path;
			 返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetHandleIcon(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetHandleIcon() const = 0;

			/*@function
			******************************************************************
			功  能：手柄的大小。可以是相对于组件尺寸的百分比大小;
			参  数：<无>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetHandleSize(int nValue, bool bIsPercentage) = 0;
			virtual void GetHandleSize(int* pnValue, bool* pbIsPercentage) = 0;

			/*@function
			******************************************************************
			功  能：手柄的样式配置;
			参  数：<无>;
			返回值：<IVisualMapHandleStyle*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IVisualMapHandleStyle* GetHandleStyle() = 0;

			/*@function
			******************************************************************
			功  能：指示器的形状，默认为圆形。指示器在鼠标移到组件上，或者在移到系列图形上联动高亮的时候出现。
			参  数：<无>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetIndicatorIcon(ESymbol eValue) = 0;
			virtual ESymbol GetIndicatorIcon() const = 0;

			/*@function
			******************************************************************
			功  能：指示器的大小。可以是相对于组件尺寸的百分比大小。
			参  数：<nValue> ;
			        <bIsPercentage> true时，nValue 为百分比;
					                false 时, nValue 为大小的值，单位为 px;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetIndicatorSize(int nValue, bool bIsPercentage) = 0;
			virtual void GetIndicatorSize(int* pnValue, bool* pbIsPercentage) = 0;

			/*@function
			******************************************************************
			功  能：指示器样式配置。
			参  数：<无>;
			返回值：<IVisualMapIndicatorStyle*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IVisualMapIndicatorStyle* GetIndicatorStyle() = 0;
		};
	}
	
}