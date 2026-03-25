#pragma once
/***********************************************************************
 * Module:  IVisualMap.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: visualMap 是视觉映射组件，用于进行『视觉编码』，
 *          也就是将数据映射到视觉元素（视觉通道）。
 *       视觉元素可以是：
 *			- symbol: 图元的图形类别。
 *			- symbolSize: 图元的大小。
 *			- color: 图元的颜色。
 *			- colorAlpha: 图元的颜色的透明度。
 *			- opacity: 图元以及其附属物（如文字标签）的透明度。
 *			- colorLightness: 颜色的明暗度，参见 HSL。
 *			- colorSaturation: 颜色的饱和度，参见 HSL。
 *			- colorHue: 颜色的色调，参见 HSL(https://en.wikipedia.org/wiki/HSL_and_HSV)。
 * 
 *		visualMap 组件可以定义多个，从而可以同时对数据中的多个维度进行视觉映射。
 *		visualMap 组件可以定义为 分段型（visualMapPiecewise） 或 连续型（visualMapContinuous）
 * 
 *		既然是『数据』到『视觉元素』的映射，visualMap 中可以指定数据的『哪个维度』
 *		映射到哪些『视觉元素』
 *		在 visualMap 组件所控制的 series 中，如果 series 中某个数据项需要避开 visualMap 映射，
 *		可以这么配置：
 *		 series: {
 *			type: '...',
 *			data: [
 *				{name: 'Shanghai', value: 251},
 *				{name: 'Haikou', value: 21},
 *				// 设置 `visualMap: false` 则 visualMap 不对此项进行控制，此时系列
 *				// 可使用自身的视觉参数（color/symbol/ ...控制此项的显示。
 *				{name: 'Beijing', value: 821, visualMap: false},
 *				...
 *			]
 *		}
 *
 ***********************************************************************/
#include <vector>
#include <string>
#include "Common/ICallback.h"
#include "Options/Common/ICategoryData.h"
#include "Options/GeneralOptions\VisualMap\IVisualMapContinuous.h"
#include "Options/GeneralOptions\VisualMap\IVisualMapPiecewise.h"

namespace IIChart
{
	namespace VisualMap
	{
		
		 /*@class
		 *************************************************************************
		 * 类  名: IVisualMap
		 * 修  改: 2022年7月1日 15:02:44
		 * 功  能: 视觉映射组件,用于进行『视觉编码』，也就是将数据映射到视觉元素（视觉通道）
		 -----------------------------------------------------------------------
		 作  者:  YangPenghui 2022-10-26;
		 ************************************************************************/
		class IVisualMap
		{
		public:
			
			/*@function
			******************************************************************
			功  能：创建连续型视觉映射组件（visualMapContinuous）;
			参  数: <eValue> ;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual IVisualMapContinuous* CreateContinuous() = 0;

			/*@function
			******************************************************************
			功  能：创建分段型视觉映射组件（visualMapPiecewise）;
			参  数: <eValue> ;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual IVisualMapPiecewise* CreatePiecewiseType() = 0;

			/*@function
			******************************************************************
			功  能：向 VisualMap 中添加一个组件;;
			参  数: <pValue> ;
			返回值：<int> 错误码;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual int Add(IVisualMapContinuous* pValue) = 0;
			virtual int Add(IVisualMapPiecewise* pValue) = 0;

			/*@function
			******************************************************************
			功  能：清除 VisualMap 中所有已添加的视觉映射组件;
			参  数: <pValue> ;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void Clear() = 0;
		};
	}
	
}