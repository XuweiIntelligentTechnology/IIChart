#pragma once
/***********************************************************************
 * Module:  ILegend.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: 图例组件。

	图例组件展现了不同系列的标记(symbol)，颜色和名字。可以通过点击图例控制哪些系列不显示。
	ECharts 3 中单个 echarts 实例中可以存在多个图例组件，会方便多个图例的布局。

	当图例数量过多时，可以使用 滚动图例（垂直） 或 滚动图例（水平），参见：legend.type
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Common/IQueue.h"
#include "Options/Common/IBaseArrayElement.h"
#include "Options/GeneralOptions/Tooltip/ITooltip.h"
#include "Options/GeneralOptions/Legend/ILegendItemStyle.h"
#include "Options/GeneralOptions/Legend/ILegendLineStyle.h"
#include "Options/GeneralOptions/Legend/ILegendTextStyle.h"
#include "Options/GeneralOptions/Legend/ILegendSelectorLabel.h"
#include "Options/GeneralOptions/Legend/ILegendEmphasis.h"
#include "Options/GeneralOptions/Legend/ILegendPageTextStyle.h"
#include "Options/GeneralOptions/Legend/ILegendPageIcons.h"
#include "Options/GeneralOptions/Legend/ILegendData.h"

namespace IIChart
{
	using namespace Tooltip;

	namespace Legend
	{
		/*@class
		*************************************************************************
		* 类  名: ILegend
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 图例组件
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class ILegend
		{
		public:

			/*@function
			******************************************************************
			功  能：图例的类型。
			参  数: <eValue> ;
			返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetType(ELegendType eValue) = 0;
			virtual ELegendType GetType() const = 0;

			/*@function
			******************************************************************
			功  能：组件 ID。默认不指定。指定则可用于在 option 或者 API 中引用组件。
			参  数: <wzValue> 为 nullptr 或 L"" 时为不指定;
			返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetId(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetId() const = 0;

			/*@function
			******************************************************************
			功  能：是否显示。
			参  数: <bValue>;
			返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetShow(bool bValue) = 0;
			virtual bool GetShow() const = 0;

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
			virtual void GetLeft(int* pnValue, bool* pbIsPercentage) = 0;

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
			virtual void GetTop(int* pnValue, bool* pbIsPercentage)  = 0;

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
			virtual void GetRight(int* pnValue, bool* pbIsPercentage) = 0;

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
			virtual void GetBottom(int* pnValue, bool* pbIsPercentage) = 0;

			/*@function
			******************************************************************
			功  能：grid 组件的宽度。默认自适应。
			参  数：<nValue> ;
			返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetWidth(int nValue) = 0;
			virtual int  GetWidth() const = 0;

			/*@function
			******************************************************************
			功  能：grid 组件的高度。默认自适应。
			参  数：<nValue> ;
			返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetHeight(int nValue) = 0;
			virtual int  GetHeight() const = 0;

			/*@function
			******************************************************************
			功  能：图例列表的布局朝向。
			参  数：<eValue> ;
			返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetOrient(EOrient eValue) = 0;
			virtual EOrient GetOrient() const = 0;

			/*@function
			******************************************************************
			功  能：图例标记和文本的对齐。
			参  数：<eValue> 默认自动，根据组件的位置和 orient 决定，当组件的 left 值为 'right' 以及
			                纵向布局（orient 为 'vertical'）的时候为右对齐，即为 'right';
			返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetAlign(ELegendAlign eValue) = 0;
			virtual ELegendAlign GetAlign() const = 0;

			/*@function
			******************************************************************
			功  能：内边距，单位 px;
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
			功  能：内边距，单位 px;
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
			功  能：内边距，单位 px;
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
			功  能：图例每项之间的间隔;
			注  意: 横向布局时为水平间隔，纵向布局时为纵向间隔。
			参  数：<nValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetItemGap(int nValue) = 0;
			virtual int  GetItemGap() const = 0;

			/*@function
			******************************************************************
			功  能：图例标记的图形宽度;
			参  数：<nValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetItemWidth(int nValue) = 0;
			virtual int  GetItemWidth() const = 0;

			/*@function
			******************************************************************
			功  能：图例标记的图形高度;
			参  数：<nValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetItemHeight(int nValue) = 0;
			virtual int  GetItemHeight() const = 0;

			/*@function
			******************************************************************
			功  能：图例的图形样式;
			注  意: 其属性的取值为 'inherit' 时，表示继承系列中的属性值。
			参  数：<无>;
			返回值：<ILegendItemStyle*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILegendItemStyle* GetItemStyle() = 0;

			/*@function
			******************************************************************
			功  能：图例图形中线的样式，用于诸如折线图图例横线的样式设置;
			注  意: 其属性的取值为 'inherit' 时，表示继承系列中的属性值。
			参  数：<无>;
			返回值：<ILegendLineStyle*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILegendLineStyle* GetLineStyle() = 0;

			/*@function
			******************************************************************
			功  能：标记的旋转角度（而非弧度）,正值表示逆时针旋转;
			注  意: 如果为 'inherit'，表示取系列的 symbolRotate。
			参  数：<nRotate>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetSymbolRotate(int nRotate) = 0;
			virtual int  GetSymbolRotate() const = 0;

			/*@function
			******************************************************************
			 功  能：刻度标签的内容格式器的字符串模板。字符串模板与回调函数返回的字符串均支持用 \n 换行。
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
			 功  能：刻度标签的内容格式器的JavaScript回调函数;字符串模板与回调函数返回的字符串均支持用 \n 换行。
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
			virtual int SetFormatterJSFun(const wchar_t* wzValue) = 0;

			/*@function
			******************************************************************
			功  能：图例选择的模式，控制是否可以通过点击图例改变系列的显示状态;
			注  意: 默认开启图例选择。
			参  数：<nRotate>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetSelectedMode(ELegendSelectedMode eValue) = 0;
			virtual ELegendSelectedMode GetSelectedMode() const = 0;

			/*@function
			*****************************************************************
			功  能：图例关闭时的颜色。
			参  数：<wzValue> 值为 nullptr 或 L"" 时不会有任何效果;支持以下方式的颜色值：
							  1. 可以使用 RGB 表示，比如 'rgb(128, 128, 128)'\
							  2. 如果想要加上 alpha 通道，可以使用 RGBA，比如 'rgba(128, 128, 128, 0.5)'
							  3. 可以使用十六进制格式，比如 '#ccc'
							  4. 可以使用 CSS3 预定义的颜色名称，如'red'，'SlateGray';
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetInactiveColor(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetInactiveColor() const = 0;

			/*@function
			*****************************************************************
			功  能：图例关闭时的颜色。
			参  数：<略> ;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetInactiveColor(int nR, int nG, int nB, float nTransparent = 1) = 0;
			virtual void GetInactiveColor(int* pnR, int* pnG, int* pnB, float* pnTransparent) = 0;

			/*@function
			*****************************************************************
			功  能：图例关闭时的描边颜色。
			参  数：<wzValue> 值为 nullptr 或 L"" 时不会有任何效果;支持以下方式的颜色值：
							  1. 可以使用 RGB 表示，比如 'rgb(128, 128, 128)'\
							  2. 如果想要加上 alpha 通道，可以使用 RGBA，比如 'rgba(128, 128, 128, 0.5)'
							  3. 可以使用十六进制格式，比如 '#ccc'
							  4. 可以使用 CSS3 预定义的颜色名称，如'red'，'SlateGray';
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetInactiveBorderColor(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetInactiveBorderColor() const = 0;

			/*@function
			*****************************************************************
			功  能：图例关闭时的描边颜色。
			参  数：<略> ;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetInactiveBorderColor(int nR, int nG, int nB, float nTransparent = 1) = 0;
			virtual void GetInactiveBorderColor(int* pnR, int* pnG, int* pnB, float* pnTransparent) = 0;

			/*@function
			*****************************************************************
			功  能：图例关闭时的描边粗细。
			注  意：如果为 'auto' 表示：如果系列存在描边，则取 2,如果系列不存在描边，则取 0;
				   如果为 'inherit' 则表示：始终取系列的描边粗细;
			参  数：<nValue> ;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetInactiveBorderWidth(EInactiveBorderWidthType eValue) = 0;
			virtual void GetInactiveBorderWidth(EInactiveBorderWidthType* peValue) = 0;

			/*@function
			*****************************************************************
			功  能：图例关闭时的描边粗细。
			参  数：<nValue> ;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetInactiveBorderWidth(int nValue) = 0;
			virtual int  GetInactiveBorderWidth() const = 0;

			/*@function
			******************************************************************
			功  能：图例选中状态表。例如：
					 selected: {
						// 选中'系列1'
						'系列1': true,
						// 不选中'系列2'
						'系列2': false
					}
			参  数：<wzSeries> 系列名称,为 nullptr 或 L"" 时表示其他选项;
				   <bValue> true 表示选中，false 表示未选中;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void SetSelected(const wchar_t* wzSeries, bool bValue) = 0;
			virtual void ClearSelected() = 0;

			/*@function
			*****************************************************************
			功  能：图例的公用文本样式。
			参  数：<无> ;
			返回值：<ILegendTextStyle*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILegendTextStyle* GetTextStyle() = 0;

			/*@function
			*****************************************************************
			功  能：图例的 tooltip 配置。
			参  数：<无> ;
			返回值：<ITooltip*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ITooltip* GetTooltip() = 0;

			/*@function
			*****************************************************************
			功  能：设置 图例项的 icon。
			参  数：<nValue> ;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetIcon(ESymbol nValue) = 0;
			virtual ESymbol GetIcon() const = 0;

			/*@function
			******************************************************************
			 功  能：用图片设置 图例项的 icon
			 注  意：本接口参数只能是以下几种形式：
					 1. 图片链接：
					 'image://http://example.website/a/b.png'
					 2. dataURI：
					 'image://data:image/gif;base64,R0lGODlhEAAQAMQAAORHHOVSKudfOulrSOp3WOyDZu6QdvCchPGolfO0o/XBs/fNwfjZ0frl3/zy7////wAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACH5BAkAABAALAAAAAAQABAAAAVVICSOZGlCQAosJ6mu7fiyZeKqNKToQGDsM8hBADgUXoGAiqhSvp5QAnQKGIgUhwFUYLCVDFCrKUE1lBavAViFIDlTImbKC5Gm2hB0SlBCBMQiB0UjIQA7'
					 3. 矢量路径：（可以参考 https://www.w3.org/TR/SVG/paths.html#PathData）
					 'path://M30.9,53.2C16.8,53.2,5.3,41.7,5.3,27.6S16.8,2,30.9,2C45,2,56.4,13.5,56.4,27.6S45,53.2,30.9,53.2z M30.9,3.5C17.6,3.5,6.8,14.4,6.8,27.6c0,13.3,10.8,24.1,24.101,24.1C44.2,51.7,55,40.9,55,27.6C54.9,14.4,44.1,3.5,30.9,3.5z M36.9,35.8c0,0.601-0.4,1-0.9,1h-1.3c-0.5,0-0.9-0.399-0.9-1V19.5c0-0.6,0.4-1,0.9-1H36c0.5,0,0.9,0.4,0.9,1V35.8z M27.8,35.8 c0,0.601-0.4,1-0.9,1h-1.3c-0.5,0-0.9-0.399-0.9-1V19.5c0-0.6,0.4-1,0.9-1H27c0.5,0,0.9,0.4,0.9,1L27.8,35.8L27.8,35.8z'
			 参  数：<wzValue> 图片的 URL 或 dataURI也可以是 Path;
			                   值为 nullptr 或 L"" 时不会有任何效果;
			 返回值：<无>;
			------------------------------------------------------------------
			 作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetIconImage(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetIconImage() const = 0;

			/*@function
			*****************************************************************
			功  能：清空 Data 数据。
			参  数：<无> ;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void ClearData() = 0;

			/*@function
			******************************************************************
			 功  能：创建图例的数据
			 参  数：<wzName>  图例项的名称，应等于某系列的name值（如果是饼图，也可以是饼图单个数据的 name）;
			                   若值为 nullptr 或 L"" 时不会有相应的名称;
			        <eIcon>    图例项的 icon。;
			        <wzValue> 图例项的 icon 的 URL 或 dataURI,也可以是 Path, 具体为以下几种形式：
					 1. 图片链接：
					 'image://http://example.website/a/b.png'
					 2. dataURI：
					 'image://data:image/gif;base64,R0lGODlhEAAQAMQAAORHHOVSKudfOulrSOp
					 3WOyDZu6QdvCchPGolfO0o/XBs/fNwfjZ0frl3/zy7////wAAAAAAAAAAAAAAAAAAAA
					 AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACH5BAkAABAALAAAAAAQABAAAA
					 VVICSOZGlCQAosJ6mu7fiyZeKqNKToQGDsM8hBADgUXoGAiqhSvp5QAnQKGIgUhwFUYL
					 CVDFCrKUE1lBavAViFIDlTImbKC5Gm2hB0SlBCBMQiB0UjIQA7'
					 3. 矢量路径：（可以参考 https://www.w3.org/TR/SVG/paths.html#PathData）
					 'path://M30.9,53.2C16.8,53.2,5.3,41.7,5.3,27.6S16.8,2,30.9,2C45,2,56.4,13.5,
					 56.4,27.6S45,53.2,30.9,53.2z M30.9,3.5C17.6,3.5,6.8,14.4,6.8,27.6c0,13.3,10.8,
					 24.1,24.101,24.1C44.2,51.7,55,40.9,55,27.6C54.9,14.4,44.1,3.5,30.9,3.5z M36.9,35.8c0,
					 0.601-0.4,1-0.9,1h-1.3c-0.5,0-0.9-0.399-0.9-1V19.5c0-0.6,0.4-1,0.9-1H36c0.5,0,0.9,
					 0.4,0.9,1V35.8z M27.8,35.8 c0,0.601-0.4,1-0.9,1h-1.3c-0.5,0-0.9-0.399-0.9-1V19.5c0-0.6,
					 0.4-1,0.9-1H27c0.5,0,0.9,0.4,0.9,1L27.8,35.8L27.8,35.8z';
			 返回值：<无>;
			------------------------------------------------------------------
			 作  者:  YangPenghui 2022-10-26;
			******************************************************************/			
			virtual ILegendData* CreateData() = 0;
			virtual ILegendData* CreateData(const wchar_t* wzName, ESymbol eIcon) = 0;
			virtual ILegendData* CreateData(const wchar_t* wzName, const wchar_t* wzValue) = 0;

			/*@function
			******************************************************************
			 功  能：新增加一个图例的数据
			 参  数：<wzName>  图例项的名称，应等于某系列的name值（如果是饼图，也可以是饼图单个数据的 name）;
			                   若值为 nullptr 或 L"" 时不会有相应的名称;
					<eIcon>    图例项的 icon。;
					<wzIcon> 图例项的 icon 的 URL 或 dataURI,也可以是 Path, 具体为以下几种形式：
					 1. 图片链接：
					 'image://http://example.website/a/b.png'
					 2. dataURI：
					 'image://data:image/gif;base64,R0lGODlhEAAQAMQAAORHHOVSKudfOulrSOp
					 3WOyDZu6QdvCchPGolfO0o/XBs/fNwfjZ0frl3/zy7////wAAAAAAAAAAAAAAAAAAAA
					 AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACH5BAkAABAALAAAAAAQABAAAA
					 VVICSOZGlCQAosJ6mu7fiyZeKqNKToQGDsM8hBADgUXoGAiqhSvp5QAnQKGIgUhwFUYL
					 CVDFCrKUE1lBavAViFIDlTImbKC5Gm2hB0SlBCBMQiB0UjIQA7'
					 3. 矢量路径：（可以参考 https://www.w3.org/TR/SVG/paths.html#PathData）
					 'path://M30.9,53.2C16.8,53.2,5.3,41.7,5.3,27.6S16.8,2,30.9,2C45,2,56.4,13.5,
					 56.4,27.6S45,53.2,30.9,53.2z M30.9,3.5C17.6,3.5,6.8,14.4,6.8,27.6c0,13.3,10.8,
					 24.1,24.101,24.1C44.2,51.7,55,40.9,55,27.6C54.9,14.4,44.1,3.5,30.9,3.5z M36.9,35.8c0,
					 0.601-0.4,1-0.9,1h-1.3c-0.5,0-0.9-0.399-0.9-1V19.5c0-0.6,0.4-1,0.9-1H36c0.5,0,0.9,
					 0.4,0.9,1V35.8z M27.8,35.8 c0,0.601-0.4,1-0.9,1h-1.3c-0.5,0-0.9-0.399-0.9-1V19.5c0-0.6,
					 0.4-1,0.9-1H27c0.5,0,0.9,0.4,0.9,1L27.8,35.8L27.8,35.8z';
			 返回值：<无>;
			------------------------------------------------------------------
			 作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual int AddData(ILegendData* pData) = 0;
			virtual int AddData(const wchar_t* wzName, ESymbol eIcon) = 0;
			virtual int AddData(const wchar_t* wzName, const wchar_t* wzIcon) = 0;

			/*@function
			 ******************************************************************
			 功  能：新增加图例的数据。
			 参  数：<wzNames> 为以“,”分隔的字符串，每个字符串表示一个图例名字;
			 返回值：<无>;
			 ------------------------------------------------------------------
			 作  者:  YangPenghui 2022-10-26;
			 ******************************************************************/
			virtual int AddData(const wchar_t* wzNames) = 0;

			/*@function
			******************************************************************
			 功  能：新增加图例的数据
			 参  数：<pQueue>  图例的数据，其元素可以是 ILegendData* 类型，
			         也可是表示图例项的 icon 的 URL 或 dataURI,也可以是 Path, 具体为以下几种形式：
					 1. 图片链接：
					 'image://http://example.website/a/b.png'
					 2. dataURI：
					 'image://data:image/gif;base64,R0lGODlhEAAQAMQAAORHHOVSKudfOulrSOp
					 3WOyDZu6QdvCchPGolfO0o/XBs/fNwfjZ0frl3/zy7////wAAAAAAAAAAAAAAAAAAAA
					 AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACH5BAkAABAALAAAAAAQABAAAA
					 VVICSOZGlCQAosJ6mu7fiyZeKqNKToQGDsM8hBADgUXoGAiqhSvp5QAnQKGIgUhwFUYL
					 CVDFCrKUE1lBavAViFIDlTImbKC5Gm2hB0SlBCBMQiB0UjIQA7'
					 3. 矢量路径：（可以参考 https://www.w3.org/TR/SVG/paths.html#PathData）
					 'path://M30.9,53.2C16.8,53.2,5.3,41.7,5.3,27.6S16.8,2,30.9,2C45,2,56.4,13.5,
					 56.4,27.6S45,53.2,30.9,53.2z M30.9,3.5C17.6,3.5,6.8,14.4,6.8,27.6c0,13.3,10.8,
					 24.1,24.101,24.1C44.2,51.7,55,40.9,55,27.6C54.9,14.4,44.1,3.5,30.9,3.5z M36.9,35.8c0,
					 0.601-0.4,1-0.9,1h-1.3c-0.5,0-0.9-0.399-0.9-1V19.5c0-0.6,0.4-1,0.9-1H36c0.5,0,0.9,
					 0.4,0.9,1V35.8z M27.8,35.8 c0,0.601-0.4,1-0.9,1h-1.3c-0.5,0-0.9-0.399-0.9-1V19.5c0-0.6,
					 0.4-1,0.9-1H27c0.5,0,0.9,0.4,0.9,1L27.8,35.8L27.8,35.8z';
			 返回值：<无>;
			------------------------------------------------------------------
			 作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual int AddData(IQueue* pQueue) = 0;

			/*@function
			******************************************************************
			 功  能：设置图例的数据数组
			 参  数：<pQueue>  图例的数据，其元素可以是 ILegendData* 类型，
					 也可是表示图例项的 icon 的 URL 或 dataURI,也可以是 Path, 具体为以下几种形式：
					 1. 图片链接：
					 'image://http://example.website/a/b.png'
					 2. dataURI：
					 'image://data:image/gif;base64,R0lGODlhEAAQAMQAAORHHOVSKudfOulrSOp
					 3WOyDZu6QdvCchPGolfO0o/XBs/fNwfjZ0frl3/zy7////wAAAAAAAAAAAAAAAAAAAA
					 AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACH5BAkAABAALAAAAAAQABAAAA
					 VVICSOZGlCQAosJ6mu7fiyZeKqNKToQGDsM8hBADgUXoGAiqhSvp5QAnQKGIgUhwFUYL
					 CVDFCrKUE1lBavAViFIDlTImbKC5Gm2hB0SlBCBMQiB0UjIQA7'
					 3. 矢量路径：（可以参考 https://www.w3.org/TR/SVG/paths.html#PathData）
					 'path://M30.9,53.2C16.8,53.2,5.3,41.7,5.3,27.6S16.8,2,30.9,2C45,2,56.4,13.5,
					 56.4,27.6S45,53.2,30.9,53.2z M30.9,3.5C17.6,3.5,6.8,14.4,6.8,27.6c0,13.3,10.8,
					 24.1,24.101,24.1C44.2,51.7,55,40.9,55,27.6C54.9,14.4,44.1,3.5,30.9,3.5z M36.9,35.8c0,
					 0.601-0.4,1-0.9,1h-1.3c-0.5,0-0.9-0.399-0.9-1V19.5c0-0.6,0.4-1,0.9-1H36c0.5,0,0.9,
					 0.4,0.9,1V35.8z M27.8,35.8 c0,0.601-0.4,1-0.9,1h-1.3c-0.5,0-0.9-0.399-0.9-1V19.5c0-0.6,
					 0.4-1,0.9-1H27c0.5,0,0.9,0.4,0.9,1L27.8,35.8L27.8,35.8z';
			 返回值：<无>;
			------------------------------------------------------------------
			 作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual int SetData(IQueue* pQueue) = 0;

			/*@function
			 ******************************************************************
			 功  能：设置图例的数据数组。
			 参  数：<wzNames> 为以“,”分隔的字符串，每个字符串表示一个图例名字;
			 返回值：<无>;
			 ------------------------------------------------------------------
			 作  者:  YangPenghui 2022-10-26;
			 ******************************************************************/
			virtual int SetData(const wchar_t* wzNames) = 0;

			/*@function
			 ******************************************************************
			 功  能：设置图例背景色。
			 参  数：<wzValue> 为 nullptr 或 L"" 时将不显示任何颜色，支持以下方式的颜色值：
							  1. 可以使用 RGB 表示，比如 'rgb(128, 128, 128)'\
							  2. 如果想要加上 alpha 通道，可以使用 RGBA，比如 'rgba(128, 128, 128, 0.5)'
							  3. 可以使用十六进制格式，比如 '#ccc'
							  4. 可以使用 CSS3 预定义的颜色名称，如'red'，'SlateGray';
			 返回值：<无>;
			 ------------------------------------------------------------------
			 作  者:  YangPenghui 2022-10-26;
			 ******************************************************************/
			virtual void SetBackgroundColor(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetBackgroundColor() const = 0;

			/*@function
			 ******************************************************************
			 功  能：以 RGBA 方式设置图例背景色。
			 参  数：<略>;
			 返回值：<无>;
			 ------------------------------------------------------------------
			 作  者:  YangPenghui 2022-10-26;
			 ******************************************************************/
			virtual void SetBackgroundColor(int nR, int nG, int nB, float nTransparent = 1) = 0;
			virtual void GetBackgroundColor(int* pnR, int* pnG, int* pnB, float* pnTransparent) = 0;

			/*@function
			 ******************************************************************
			 功  能：置图例的边框颜色。
			 参  数：<wzValue> 为 nullptr 或 L"" 时将不显示任何颜色，支持以下方式的颜色值：
							  1. 可以使用 RGB 表示，比如 'rgb(128, 128, 128)'\
							  2. 如果想要加上 alpha 通道，可以使用 RGBA，比如 'rgba(128, 128, 128, 0.5)'
							  3. 可以使用十六进制格式，比如 '#ccc'
							  4. 可以使用 CSS3 预定义的颜色名称，如'red'，'SlateGray';
			 返回值：<无>;
			 ------------------------------------------------------------------
			 作  者:  YangPenghui 2022-10-26;
			 ******************************************************************/
			virtual void SetBorderColor(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetBorderColor() const = 0;

			/*@function
			 ******************************************************************
			 功  能：以 RGBA 方式设置图例边框颜色
			 参  数：<略>;
			 返回值：<无>;
			 ------------------------------------------------------------------
			 作  者:  YangPenghui 2022-10-26;
			 ******************************************************************/
			virtual void SetBorderColor(int nR, int nG, int nB, float nTransparent = 1) = 0;
			virtual void GetBorderColor(int* pnR, int* pnG, int* pnB, float* pnTransparent) = 0;

			/*@function
			 ******************************************************************
			 功  能：图例的边框线宽
			 参  数：<nValue>;
			 返回值：<无>;
			 ------------------------------------------------------------------
			 作  者:  YangPenghui 2022-10-26;
			 ******************************************************************/
			virtual void SetBorderWidth(int nValue) = 0;
			virtual int GetBorderWidth() const = 0;

			/*@function
			 ******************************************************************
			 功  能：统一设置四个角的圆角大小，单位px;
			 参  数：<nValue>;
			 返回值：<无>;
			 ------------------------------------------------------------------
			 作  者:  YangPenghui 2022-10-26;
			 ******************************************************************/
			virtual void  SetBorderRadius(int nValue) = 0;
			virtual void  GetBorderRadius(int* pnValue) = 0;

			/*@function
			 ******************************************************************
			 功  能：设置圆角大小，单位px;
			  参  数：<nValue1> 左上、右下的圆角;
					 <nValue2> 右上、左下的圆角;
			 返回值：<无>;
			 ------------------------------------------------------------------
			 作  者:  YangPenghui 2022-10-26;
			 ******************************************************************/
			virtual void  SetBorderRadius(int nValue1, int nValue2) = 0;
			virtual void  GetBorderRadius(int* pnValue1, int* pnValue2) = 0;

			/*@function
			 ******************************************************************
			 功  能：设置圆角大小，单位px;
			 参  数：<nValue1> 左上的圆角;
					 <nValue2> 右上的圆角;
					 <nValue3> 右下的圆角;
					 <nValue4> 左下的圆角;
			 返回值：<无>;
			 ------------------------------------------------------------------
			 作  者:  YangPenghui 2022-10-26;
			 ******************************************************************/
			virtual void SetBorderRadius(int nValue1, int nValue2, int nValue3, int nValue4) = 0;
			virtual void GetBorderRadius(int* pnValue1, int* pnValue2, int* pnValue3, int* pnValue4) = 0;

			/*@function
			 ******************************************************************
			 功  能：图形阴影的模糊大小;该属性配合 shadowColor,shadowOffsetX, shadowOffsetY 一起设置图形的阴影效果。
			 参  数：<nValue>;
			 返回值：<无>;
			 ------------------------------------------------------------------
			 作  者:  YangPenghui 2022-10-26;
			 ******************************************************************/
			virtual void SetShadowBlur(int nValue) = 0;
			virtual int GetShadowBlur() const = 0;

			/*@function
			 ******************************************************************
			 功  能：阴影颜色。
			 参  数：<wzValue> 为 nullptr 或 L"" 时将不显示任何颜色，支持以下方式的颜色值：
							  1. 可以使用 RGB 表示，比如 'rgb(128, 128, 128)'\
							  2. 如果想要加上 alpha 通道，可以使用 RGBA，比如 'rgba(128, 128, 128, 0.5)'
							  3. 可以使用十六进制格式，比如 '#ccc'
							  4. 可以使用 CSS3 预定义的颜色名称，如'red'，'SlateGray';
			 返回值：<无>;
			 ------------------------------------------------------------------
			 作  者:  YangPenghui 2022-10-26;
			 ******************************************************************/
			virtual void SetShadowColor(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetShadowColor() const = 0;

			/*@function
			 ******************************************************************
			 功  能：以 RGBA 方式设置图例阴影颜色
			 参  数：<略>;
			 返回值：<无>;
			 ------------------------------------------------------------------
			 作  者:  YangPenghui 2022-10-26;
			 ******************************************************************/
			virtual void SetShadowColor(int nR, int nG, int nB, float nTransparent = 1) = 0;
			virtual void GetShadowColor(int* pnR, int* pnG, int* pnB, float* pnTransparent) = 0;

			/*@function
			******************************************************************
			功  能：图形的背景阴影 X 偏移;
			参  数：<nValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetShadowOffsetX(int nValue) = 0;
			virtual int GetShadowOffsetX() const = 0;

			/*@function
			******************************************************************
			功  能：图形的背景阴影 Y 偏移;
			参  数：<nValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetShadowOffsetY(int nValue) = 0;
			virtual int GetShadowOffsetY() const = 0;

			/*@function
			******************************************************************
			功  能：图例当前最左上显示项的 dataIndex。
			注  意：legend.type 为 'scroll' 时有效
					setOption 时指定此项的话，可决定当前图例滚动到哪里。
					但是，如果仅仅想改变图例翻页，一般并不调用 setOption（因为这太重量了），
					仅仅使用 action legendScroll 即可。
			参  数：<略>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetScrollDataIndex(int nValue) = 0;
			virtual int  GetScrollDataIndex() const = 0;

			/************************************************
			功  能：图例控制块中，按钮和页信息之间的间隔。
					legend.type 为 'scroll' 时有效
			参  数：<略>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetPageButtonItemGap(int nValue) = 0;
			virtual int  GetPageButtonItemGap() const = 0;

			/************************************************
			功  能：图例控制块和图例项之间的间隔。
					legend.type 为 'scroll' 时有效
			参  数：<略>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetPageButtonGap(int nValue) = 0;
			virtual int  GetPageButtonGap() const = 0;


			/************************************************
			 功  能：图例控制块的位置
			 参  数：<wzValue> JS函数模板;
			 返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetPageButtonPosition(EPageButtonPosition eValue) = 0;
			virtual EPageButtonPosition GetPageButtonPosition() const = 0;

			/************************************************
			 功  能：图例控制块中，页信息的显示格式。
			 注  意：legend.type 为 'scroll' 时有效。
			         默认为 '{current}/{total}'，
					 其中 {current} 是当前页号（从 1 开始计数），
					 {total} 是总页数。
			 参  数：<wzValue> 字符串模板;
			 返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetPageFormatter(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetPageFormatter()const = 0;

			/************************************************
			 功  能：刻度标签的内容格式器的JavaScript回调函数;字符串模板与回调函数返回的字符串均支持用 \n 换行。
			 注  意：如果 pageFormatter 使用函数，须返回字符串，参数为：
					{
						current: number
						total: number
					}
			 参  数：<wzValue> JS函数模板;
			 返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual int SetPageFormatterJSFun(const wchar_t* wzValue) = 0;

			/*@function
			 ******************************************************************
			 功  能：图例控制块的图标。。
			 参  数：<无> ;
			 返回值：<ILegendPageIcons*>;
			 ------------------------------------------------------------------
			 作  者:  YangPenghui 2022-10-26;
			 ******************************************************************/
			virtual ILegendPageIcons* GetPageIcons() = 0;

			/*@function
			 ******************************************************************
			 功  能：设置翻页按钮的颜色。
			 参  数：<wzValue> 为 nullptr 或 L"" 时将不显示任何颜色，支持以下方式的颜色值：
							  1. 可以使用 RGB 表示，比如 'rgb(128, 128, 128)'\
							  2. 如果想要加上 alpha 通道，可以使用 RGBA，比如 'rgba(128, 128, 128, 0.5)'
							  3. 可以使用十六进制格式，比如 '#ccc'
							  4. 可以使用 CSS3 预定义的颜色名称，如'red'，'SlateGray';
			 返回值：<无>;
			 ------------------------------------------------------------------
			 作  者:  YangPenghui 2022-10-26;
			 ******************************************************************/
			virtual void SetPageIconColor(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetPageIconColor() const = 0;

			/*@function
			 ******************************************************************
			 功  能：以 RGBA 方式设置翻页按钮的颜色。
			 参  数：<略>;
			 返回值：<无>;
			 ------------------------------------------------------------------
			 作  者:  YangPenghui 2022-10-26;
			 ******************************************************************/
			virtual void SetPageIconColor(int nR, int nG, int nB, float nTransparent = 1) = 0;
			virtual void GetPageIconColor(int* pnR, int* pnG, int* pnB, float* pnTransparent) = 0;

			/*@function
			 ******************************************************************
			 功  能：设置翻页按钮不激活时（即翻页到头时）的颜色。
			 参  数：<wzValue> 为 nullptr 或 L"" 时将不显示任何颜色，支持以下方式的颜色值：
							  1. 可以使用 RGB 表示，比如 'rgb(128, 128, 128)'\
							  2. 如果想要加上 alpha 通道，可以使用 RGBA，比如 'rgba(128, 128, 128, 0.5)'
							  3. 可以使用十六进制格式，比如 '#ccc'
							  4. 可以使用 CSS3 预定义的颜色名称，如'red'，'SlateGray';
			 返回值：<无>;
			 ------------------------------------------------------------------
			 作  者:  YangPenghui 2022-10-26;
			 ******************************************************************/
			virtual void SetPageIconInactiveColor(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetPageIconInactiveColor() const = 0;

			/*@function
			 ******************************************************************
			 功  能：以 RGBA 方式设置翻页按钮不激活时（即翻页到头时）的颜色。
			 参  数：<略>;
			 返回值：<无>;
			 ------------------------------------------------------------------
			 作  者:  YangPenghui 2022-10-26;
			 ******************************************************************/
			virtual void SetPageIconInactiveColor(int nR, int nG, int nB, float nTransparent = 1) = 0;
			virtual void GetPageIconInactiveColor(int* pnR, int* pnG, int* pnB, float* pnTransparent) = 0;

			/*@function
			 ******************************************************************
			功  能：翻页按钮的大小
			注  意：legend.type 为 'scroll' 时有效。
			参  数：<略>;
			返回值：<无>;
			------------------------------------------------------------------
			 作  者:  YangPenghui 2022-10-26;
			 ******************************************************************/
			virtual void  SetPageIconSize(int nValue) = 0;
			virtual void  GetPageIconSize(int* pnValue) = 0;

			/*@function
			 ******************************************************************
			功  能：翻页按钮的大小
			注  意：legend.type 为 'scroll' 时有效。
			参  数：<略>;
			返回值：<无>;
			------------------------------------------------------------------
			 作  者:  YangPenghui 2022-10-26;
			 ******************************************************************/
			virtual void  SetPageIconSize(int nWidth, int nHeight) = 0;
			virtual void  GetPageIconSize(int* pnWidth, int* pnHeight) = 0;

			/*@function
			******************************************************************
			功  能：图例页信息的文字样式。
			参  数：<略>;
			返回值：<无>;
			------------------------------------------------------------------
			 作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILegendPageTextStyle* GetPageTextStyle() = 0;

			/*@function
			******************************************************************
			功  能：图例翻页是否使用动画。
			参  数：<略>;
			返回值：<无>;
			------------------------------------------------------------------
			 作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetAnimation(bool bValue) = 0;
			virtual bool GetAnimation() const = 0;

			/*@function
			******************************************************************
			功  能：图例翻页时的动画时长。
			参  数：<略>;
			返回值：<无>;
			------------------------------------------------------------------
			 作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetAnimationDurationUpdate(int nValue) = 0;
			virtual int  GetAnimationDurationUpdate() const = 0;

			/*@function
			******************************************************************
			功  能：图例页信息的文字样式。
			参  数：<无>;
			返回值：<ILegendEmphasis*>;
			------------------------------------------------------------------
			 作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILegendEmphasis* GetEmphasis() = 0;

			/*@function
			******************************************************************
			功  能：图例组件中的选择器按钮，目前包括全选和反选两种功能。默认不显示。
			参  数：<略>;
			返回值：<无>;
			------------------------------------------------------------------
			 作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetSelector(bool bValue) = 0;
			virtual bool GetSelector() const = 0;
			
			/*@function
			******************************************************************
			功  能：选择器按钮的文本标签样式，默认显示。
			参  数：<略>;
			返回值：<无>;
			------------------------------------------------------------------
			 作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILegendSelectorLabel* GetSelectorLabel() = 0;

			/*@function
			******************************************************************
			功  能：选择器的位置，可以放在图例的尾部或者头部，对应的值分别为 'end' 和 'start'。
			注  意：默认情况下，图例横向布局的时候，选择器放在图例的尾部；图例纵向布局的时候，选择器放在图例的头部。
			参  数：<略>;
			返回值：<无>;
			------------------------------------------------------------------
			 作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetSelectorPosition(ESelectorPosition eValue) = 0;
			virtual ESelectorPosition GetSelectorPosition() const = 0;

			/*@function
			 ******************************************************************
			功  能：选择器按钮之间的间隔。
			参  数：<略>;
			返回值：<无>;
			------------------------------------------------------------------
			 作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetSelectorItemGap(int nValue) = 0;
			virtual int  GetSelectorItemGap() const = 0;

			/*@function
			******************************************************************
			功  能：选择器按钮与图例组件之间的间隔。
			参  数：<略>;
			返回值：<无>;
			------------------------------------------------------------------
			 作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetSelectorButtonGap(int nValue) = 0;
			virtual int  GetSelectorButtonGap() const = 0;
		};
	}
	
}
