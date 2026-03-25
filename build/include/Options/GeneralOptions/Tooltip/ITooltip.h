#pragma once
/***********************************************************************
 * Module:  IGlobalTooltip.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: 提示框组件
 * 提示框组件的通用介绍：
 *		提示框组件可以设置在多种地方：
 *		可以设置在全局，即 tooltip
 *		可以设置在坐标系中，即 grid.tooltip、polar.tooltip、single.tooltip
 *		可以设置在系列中，即 series.tooltip
 *		可以设置在系列的每个数据项中，即 series.data.tooltip
 ***********************************************************************/
#include "Common\IEnum.h"
#include "Options\Common\IBaseArrayElement.h"
#include "Options\Common\ITextStyle.h"
#include "Options/GeneralOptions/Tooltip/ITooltipAxisPointer.h"
#include "Options/GeneralOptions/Tooltip/ITooltipTextStyle.h"

namespace IIChart
{
	namespace Tooltip
	{
		/*@class
		*************************************************************************
		* 类  名: ITooltip
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 全局 Tooltip 组件：
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class ITooltip
		{
		public:
			/*@function
			******************************************************************
			功  能：是否显示提示框组件(包括提示框浮层和 axisPointer)。
			参  数：<bValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetShow(bool bValue) = 0;
			virtual bool GetShow() const = 0;

			/*@function
			******************************************************************
			功  能：触发类型。
			参  数：<eValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetTrigger(ETrigger eValue) = 0;
			virtual ETrigger GetTrigger() const = 0;

			/*@function
			******************************************************************
			功  能：坐标轴指示器配置项。。
			参  数：<无>;
			返回值：<ITooltipAxisPointer*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ITooltipAxisPointer* GetAxisPointer() = 0;

			/*@function
			******************************************************************
			功  能：是否显示提示框内容;
			注  意：默认情况下在移出可触发提示框区域后 一定时间 后隐藏，
			        设置为 true 可以保证一直显示提示框内容
			参  数：<bValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetShowContent(bool bValue) = 0;
			virtual bool GetShowContent() const = 0;
			
			/*@function
			******************************************************************
			功  能：是否永远显示提示框内容;
			注  意：默认情况下在移出可触发提示框区域后 一定时间 后隐藏，
					设置为 true 可以保证一直显示提示框内容
			参  数：<bValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetAlwaysShowContent(bool bValue) = 0;
			virtual bool GetAlwaysShowContent() const = 0;

			/*@function
			******************************************************************
			功  能：浮层显示的延迟，单位为 ms;
			注  意：默认没有延迟，也不建议设置。在 triggerOn 为 'mousemove' 时有效。
			参  数：<nValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetShowDelay(int nValue) = 0;
			virtual int  GetShowDelay() const = 0;

			/*@function
			******************************************************************
			功  能：浮层隐藏的延迟，单位为 ms;
			注  意：在 alwaysShowContent 为 true 的时候无效。
			参  数：<nValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetHideDelay(int nValue) = 0;
			virtual int  GetHideDelay() const = 0;

			/*@function
			******************************************************************
			功  能：鼠标是否可进入提示框浮层中;
			注  意：默认为false，如需详情内交互，如添加链接，按钮，可设置为 true;
			参  数：<bValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetEnterable(bool bValue) = 0;
			virtual bool GetEnterable() const = 0;

			/*@function
			******************************************************************
			功  能：是否将 tooltip 框限制在图表的区域内;
			注  意：当图表外层的 dom 被设置为 'overflow: hidden'，或者移动端窄屏
			        导致 tooltip 超出外界被截断时，此配置比较有用。
			参  数：<bValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetConfine(bool bValue) = 0;
			virtual bool GetConfine() const = 0;

			/*@function
			******************************************************************
			功  能：提示框浮层的移动动画过渡时间，单位是 s，设置为 0 的时候会紧跟着鼠标移动;
			注  意：当图表外层的 dom 被设置为 'overflow: hidden'，或者移动端窄屏
					导致 tooltip 超出外界被截断时，此配置比较有用。
			参  数：<bValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetTransitionDuration(float fValue) = 0;
			virtual float GetTransitionDuration() const = 0;

			/*@function
			******************************************************************
			功  能：提示框浮层的位置，默认不设置时位置会跟随鼠标的位置。
			参  数： <nX> 相对于容器左侧;
					<nY>  相对于容器上侧;
					<bIsPercent> 为 true 时 nValue 为距离底边界的百分比；
								 为 false 时 nValue 为距离底边界的像素个数；
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetPosition(int nX, int nY, bool bIsPercentage = false) = 0;
			virtual void GetPosition(int* pnX, int* pnY, bool* pbIsPercentage)const = 0;

			/*@function
			******************************************************************
			 功  能：提示框浮层的位置
			 注  意：回调函数格式：
					 (point: Array, params: Object|Array.<Object>, dom: HTMLDomElement, rect: Object, size: Object) => Array
					point: 鼠标位置，如 [20, 40]。
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
					dom: tooltip 的 dom 对象。
					rect: 只有鼠标在图形上时有效，是一个用x, y, width, height四个属性表达的图形包围盒。
					size: 包括 dom 的尺寸和 echarts 容器的当前尺寸，例如：{contentSize: [width, height], viewSize: [width, height]}。
					返回值：
					可以是一个表示 tooltip 位置的数组，数组值可以是绝对的像素值，也可以是相 百分比。
					也可以是一个对象，如：{left: 10, top: 30}，或者 {right: '20%', bottom: 40}。

					更详细说明，可能参考：https://echarts.apache.org/zh/option.html#tooltip.appendToBody
			 参  数：<wzValue> 字符串模板;
			 返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetPositionJSFun(const wchar_t* wzValue) = 0;

			// TODO: 提示框浮层的位置的C++回调;

			/*@function
			******************************************************************
			 功  能：提示框浮层内容格式器。字符串模板与回调函数返回的字符串均支持用 \n 换行。
			 注  意：模板变量有 {a}, {b}，{c}，{d}，{e}，分别表示系列名，数据名，数据值等。
					  在 trigger 为 'axis' 的时候，会有多个系列的数据，此时可以通过 {a0}, {a1}, {a2}
					  这种后面加索引的方式表示系列的索引。

					  不同图表类型下的 {a}，{b}，{c}，{d} 含义不一样。
					  > 折线（区域）图、柱状（条形）图、K线图 : {a}（系列名称），{b}（类目值），{c}（数值）, {d}（无）
					  > 散点图（气泡）图 : {a}（系列名称），{b}（数据名称），{c}（数值数组）, {d}（无）
					  > 地图 : {a}（系列名称），{b}（区域名称），{c}（合并数值）, {d}（无）
					  > 饼图、仪表盘、漏斗图: {a}（系列名称），{b}（数据项名称），{c}（数值）, {d}（百分比）
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
					(params: Object|Array, ticket: string, callback: (ticket: string, html: string)) => string | HTMLElement | HTMLElement[]
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
					更详细说明，可能参考：https://echarts.apache.org/zh/option.html#tooltip.appendToBody
			 参  数：<wzValue> 字符串模板;
			 返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetFormatterJSFun(const wchar_t* wzValue) = 0;

			// TODO: 刻度标签的内容格式器的C++回调;

			/*@function
			******************************************************************
			 功  能：tooltip 中数值显示部分的格式化回调函数。
			 注  意：回调函数格式：
					(value: number | string) => string
					示例：
					// 添加 $ 前缀
					valueFormatter: (value) => '$' + value.toFixed(2)
			 参  数：<wzValue> 字符串模板;
			 返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetValueFormatterJSFun(const wchar_t* wzValue) = 0;

			/*@function
			******************************************************************
			 功  能：以16进制字符串形式设置文字块背景色;如果设置为 'inherit'，则为视觉映射得到的颜色，如系列色。
			 注  意：为颜色值时，必须以'#'开头，
			 参  数：<wzValue> 背景色16进制行;
			 返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetBackgroundColor(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetBackgroundColor() const = 0;

			/*@function
			******************************************************************
			功  能：提示框浮层的背景颜色;
			参  数：<略>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetBackgroundColor(int nR, int nG, int nB, float fTransparent) = 0;
			virtual void GetBackgroundColor(int* pnR, int* pnG, int* pnB, float* pfTransparent) = 0;

			/*@function
			******************************************************************
			功  能：文字块背景色。
			注  意：为颜色值时，必须以'#'开头，
					  1. 可以使用 RGB 表示，比如 'rgb(128, 128, 128)'\
					  2. 如果想要加上 alpha 通道，可以使用 RGBA，比如 'rgba(128, 128, 128, 0.5)'
					  3. 可以使用十六进制格式，比如 '#ccc'
			参  数：<wzValue> 背景色16进制行;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetBorderColor(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetBorderColor() const = 0;

			/*@function
			******************************************************************
			功  能：提示框浮层的边框颜色;
			参  数：<略>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetBorderColor(int nR, int nG, int nB, float fTransparent) = 0;
			virtual void GetBorderColor(int* pnR, int* pnG, int* pnB, float* pfTransparent) = 0;

			/*@function
			******************************************************************
			功  能：提示框浮层的边框宽;
			参  数：<nValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetBorderWidth(int nValue) = 0;
			virtual int  GetBorderWidth() const = 0;

			/*@function
			******************************************************************
			功  能：提示框浮层内边距;
			注  意: 文字块的 width 和 height 指定的是内容高宽，不包含 padding。
			参  数：<nValue> 边距值，例如 4：表示 padding: [4, 4, 4, 4];;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void  SetPadding(int nValue) = 0;
			virtual void  GetPadding(int* pnValue) = 0;

			/*@function
			******************************************************************
			功  能：提示框浮层内边距;
			注  意: 文字块的 width 和 height 指定的是内容高宽，不包含 padding。
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
			功  能：提示框浮层内边距;
			注  意: 文字块的 width 和 height 指定的是内容高宽，不包含 padding。
			参  数：<nTop, nRight, nBottom, nLeft> 分别表示 [上, 右, 下, 左] 的边距
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetPadding(int nTop, int nRight, int nBottom, int nLeft) = 0;
			virtual void GetPadding(int* pnTop, int* pnRight, int* pnBottom, int* pnLeft) = 0;

			/*@function
			******************************************************************
			功  能：提示框浮层的文本样式;
			参  数：<无>;
			返回值：<ITextStyle*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ITooltipTextStyle* GetTextStyle() = 0;

			/*@function
			******************************************************************
			功  能：额外附加到浮层的 css 样式。如下为浮层添加阴影的示例：
				   extraCssText: 'box-shadow: 0 0 3px rgba(0, 0, 0, 0.3);'
			注  意：series.tooltip 仅在 tooltip.trigger 为 'item' 时有效。
			参  数：<wzValue> 背景色16进制行;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetExtraCssText(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetExtraCssText() const = 0;
		};
	}
	
}