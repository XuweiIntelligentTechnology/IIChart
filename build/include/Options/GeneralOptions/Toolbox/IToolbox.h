#pragma once
/***********************************************************************
 * Module:  Tooltip.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: 工具栏。
 * 内置有导出图片，数据视图，动态类型切换，数据区域缩放，重置五个工具。
 ***********************************************************************/
#include "Common\IEnum.h"
#include "Options/Common/IBaseArrayElement.h"
#include "Options/Common/ITextStyle.h"
#include "Options/GeneralOptions/Tooltip/ITooltip.h"
#include "Options/GeneralOptions/Toolbox/IToolboxEmphasis.h"
#include "Options/GeneralOptions/Toolbox/IToolboxFeature.h"
#include "Options/GeneralOptions/Toolbox/IToolboxIconStyle.h"

namespace IIChart
{
	using namespace Tooltip;

	namespace Toolbox
	{
		/***************************
	    * 全局 Tooltip 组件;
	    ****************************/
		class IToolbox
		{
		public:
			// 组件 ID。默认不指定。指定则可用于在 option 或者 API 中引用组件。
			virtual void SetId(const wchar_t* wzId) = 0;
			virtual wchar_t* GetId() const = 0;

			// 是否显示工具栏组件。
			virtual void SetShow(bool bValue) = 0;
			virtual bool GetShow() const = 0;

			// 工具栏 icon 的布局朝向。
			virtual void SetOrient(EOrient eValue) = 0;
			virtual EOrient GetOrient() const = 0;

			// 工具栏 icon 的大小。
			virtual void SetItemSize(int nValue) = 0;
			virtual int  GetItemSize() const = 0;

			// 工具栏 icon 每项之间的间隔。横向布局时为水平间隔，纵向布局时为纵向间隔。
			virtual void SetItemGap(int nValue) = 0;
			virtual int  GetItemGap() const = 0;

			// 是否在鼠标 hover 的时候显示每个工具 icon 的标题。
			virtual void SetShowTitle(bool bValue) = 0;
			virtual bool GetShowTitle() const = 0;

			// 各工具配置项。
			virtual IToolboxFeature* GetFeature() = 0;

			// 公用的 icon 样式设置。由于 icon 的文本信息只在 icon hover 时候才显示，所以文字相关的配置项请在 emphasis 下设置。
			virtual IToolboxIconStyle* GetIconStyle() = 0;


			virtual IToolboxEmphasis* GetEmphasis() = 0;

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
			virtual void SetLeft(int nValue, bool bIsPercentage) = 0;
			virtual void GetLeft(int* pnValue, bool* pbIsPercentage) = 0;

			// visualMap 组件离容器左侧的距离。组件会根据相应的位置自动对齐
			virtual void SetLeft(EAlign eValue) = 0;
			virtual void GetLeft(EAlign* peValue) = 0;

			// visualMap 组件离容器上侧的距离。
			virtual void SetTop(int nValue, bool bIsPercentage) = 0;
			virtual void GetTop(int* pnValue, bool* pbIsPercentage) = 0;

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

			// 工具栏组件的宽度。默认自适应。
			virtual void SetWidth(int nValue) = 0;
			virtual int  GetWidth() const = 0;

			// 工具栏组件的高度。默认自适应。
			virtual void SetHeight(int nValue) = 0;
			virtual int  GetHeight() const = 0;

			// 工具箱的 tooltip 配置，配置项同 tooltip。
			// 默认不显示，可以在需要特殊定制文字样式（尤其是想用自定义 CSS 控制文字样式）的时候开启 tooltip
			virtual ITooltip* GetTooltip() = 0;
		};
	}
	
}