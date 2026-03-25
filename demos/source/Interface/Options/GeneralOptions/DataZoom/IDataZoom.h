#pragma once
/***********************************************************************
 * Module:  IDataZoom.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: dataZoom 组件 用于区域缩放，从而能自由关注细节的数据信息，或者概览数据整体，或者去除离群点的影响。
 *          现在支持这几种类型的 dataZoom 组件：
 *           1. 内置型数据区域缩放组件（dataZoomInside）：内置于坐标系中，使用户可以在坐标系上通过鼠标拖拽、鼠标滚轮、
 *              手指滑动（触屏上）来缩放或漫游坐标系。
 *           2. 滑动条型数据区域缩放组件（dataZoomSlider）：有单独的滑动条，用户在滑动条上进行缩放或漫游。
 *           3. 框选型数据区域缩放组件（dataZoomSelect）：提供一个选框进行数据区域缩放。即 toolbox.feature.dataZoom，配置项在 toolbox 中。
 * 
 * 【dataZoom 和 数轴的关系】
 * dataZoom 主要是对 数轴（axis） 进行操作（控制数轴的显示范围，或称窗口（window））。
 * 可以通过 dataZoom.xAxisIndex 或 dataZoom.yAxisIndex 或 dataZoom.radiusAxisIndex 或 dataZoom.angleAxisIndex 来指定 dataZoom 控制哪个或哪些数轴。
 * dataZoom 组件可 同时存在多个，起到共同控制的作用。如果多个 dataZoom 组件共同控制同一个数轴，他们会自动联动。
 * 
 * 【dataZoom 组件如何影响轴和数据】
 * dataZoom 的运行原理是通过 数据过滤 以及在内部设置轴的显示窗口来达到 数据窗口缩放 的效果。
 * 数据过滤模式（dataZoom.filterMode）的设置不同，效果也不同。
 * 可选值为：
 * > 'filter'：当前数据窗口外的数据，被 过滤掉。即 会 影响其他轴的数据范围。每个数据项，只要有一个维度在数据窗口外，整个数据项就会被过滤掉。
 * > 'weakFilter'：当前数据窗口外的数据，被 过滤掉。即 会 影响其他轴的数据范围。每个数据项，只有当全部维度都在数据窗口同侧外部，整个数据项才会被过滤掉。
 * > 'empty'：当前数据窗口外的数据，被 设置为空。即 不会 影响其他轴的数据范围。
 * > 'none': 不过滤数据，只改变数轴范围。
 * 如何设置，由用户根据场景和需求自己决定。经验来说：
 * > 当『只有 X 轴 或 只有 Y 轴受 dataZoom 组件控制』时，常使用 filterMode: 'filter'，这样能使另一个轴自适应过滤后的数值范围。
 * > 当『X 轴 Y 轴分别受 dataZoom 组件控制』时：
 *   >> 如果 X 轴和 Y 轴是『同等地位的、不应互相影响的』，比如在『双数值轴散点图』中，那么两个轴可都设为 filterMode: 'empty'。
 *   >> 如果 X 轴为主，Y 轴为辅，比如在『柱状图』中，需要『拖动 dataZoomX 改变 X 轴过滤柱子时，Y 轴的范围也自适应剩余柱子的高度』，
 *      『拖动 dataZoomY 改变 Y 轴过滤柱子时，X轴范围不受影响』，那么就 X轴设为 filterMode: 'filter'，Y 轴设为 filterMode: 'empty'，
 *	   即主轴 'filter'，辅轴 'empty'。
 * 
 * 【数据窗口的设置】
 * dataZoom 的数据窗口范围的设置，目前支持两种形式：
 * > 百分比形式：即设置 dataZoom.start 和 dataZoom.end。
 * > 绝对数值形式：即设置 dataZoom.startValue 和 dataZoom.endValue。
 * 注意：当使用百分比形式指定 dataZoom 范围时，且处于如下场景（或类似场景）中，dataZoom 的结果是和 dataZoom 组件的定义顺序相关的。
 * 
 ***********************************************************************/
#include <vector>
#include <string>
#include "Common/ICallback.h"
#include "Options/Common/ICategoryData.h"
#include "Options/GeneralOptions\DataZoom\IDataZoomInside.h"
#include "Options/GeneralOptions\DataZoom\IDataZoomSlider.h"

namespace IIChart
{
	namespace DataZoom
	{
		
		 /*@class
		 *************************************************************************
		 * 类  名: IDataZoom
		 * 修  改: 2022年7月1日 15:02:44
		 * 功  能: dataZoom 组件 用于区域缩放，从而能自由关注细节的数据信息，或者概览数据整体，或者去除离群点的影响。
		 -----------------------------------------------------------------------
		 作  者:  YangPenghui 2022-10-26;
		 ************************************************************************/
		class IDataZoom
		{
		public:
			
			/*@function
			******************************************************************
			功  能：内置型数据区域缩放组件（dataZoomInside）
			参  数: <无>;
			返回值：<IDataZoomInside*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IDataZoomInside* CreateInsizde() = 0;

			/*@function
			******************************************************************
			功  能：滑动条型数据区域缩放组件（dataZoomInside）
			参  数: <无> ;
			返回值：<IDataZoomSlider*>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IDataZoomSlider* CreateSlider() = 0;

			/*@function
			******************************************************************
			功  能：清除所有已添加的组件;
			参  数: <无>;
			返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void Clear() = 0;

			/*@function
			******************************************************************
			功  能：添加组件;
			参  数: <wzValue> 为 nullptr 或 L"" 时为不指定,原有的值将会被清空;
			返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual int Add(IDataZoomInside* pValue) = 0;
			virtual int Add(IDataZoomSlider* pValue) = 0;
			
		};
	}
	
}