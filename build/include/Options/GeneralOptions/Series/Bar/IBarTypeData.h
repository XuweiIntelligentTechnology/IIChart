#pragma once
/***********************************************************************
 * Module:  IBarTypeData.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: 系列中的数据内容数组。数组项通常为具体的数据项。
 *          注意，如果系列没有指定 data，并且 option 有 dataset，
 *          那么默认使用第一个 dataset。如果指定了 data，则不会再使用 dataset。
 *          可以使用 series.datasetIndex 指定其他的 dataset。
 * 
 *          通常来说，数据用一个二维数组表示。如下，每一列被称为一个『维度』。
 *			 series: [{
 *				data: [
					// 维度X   维度Y   其他维度 ...
					[  3.4,    4.5,   15,   43],
					[  4.2,    2.3,   20,   91],
					[  10.8,   9.5,   30,   18],
					[  7.2,    8.8,   18,   57]
				]
			}]
 * 
 *           在 直角坐标系 (grid) 中『维度X』和『维度Y』会默认对应于 xAxis 和 yAxis。
 *           在 极坐标系 (polar) 中『维度X』和『维度Y』会默认对应于 radiusAxis 和 angleAxis。
 *           后面的其他维度是可选的，可以在别处被使用，例如：
 *               在 visualMap 中可以将一个或多个维度映射到颜色，大小等多个图形属性上。
 *               在 series.symbolSize 中可以使用回调函数，基于某个维度得到 symbolSize 值。
 *               使用 tooltip.formatter 或 series.label.formatter 可以把其他维度的值展示出来。
 *           特别地，当只有一个轴为类目轴（axis.type 为 'category'）的时候，
             数据可以简化用一个一维数组表示。例如：
			xAxis: {
				data: ['a', 'b', 'm', 'n']
			},
			series: [{
				// 与 xAxis.data 一一对应。
				data: [23,  44,  55,  19]
				// 它其实是下面这种形式的简化：
				// data: [[0, 23], [1, 44], [2, 55], [3, 19]]
			}]
 *          
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/IBaseArrayElement.h"
#include "Options/GeneralOptions/Series/Bar/IBarTypeDataLabelLine.h"
#include "Options/GeneralOptions/Series/Bar/IBarTypeDataItemStyle.h"
#include "Options/GeneralOptions/Series/Bar/IBarTypeDataLabel.h"
#include "Options/GeneralOptions/Series/Bar/IBarTypeDataSelect.h"		  
#include "Options/GeneralOptions/Series/Bar/IBarTypeDataBlur.h"
#include "Options/GeneralOptions/Series/Bar/IBarTypeDataEmphasis.h"

namespace IIChart
{
	namespace Bar
	{
		/*@class
		*************************************************************************
		* 类  名: IBarTypeData
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 系列中的数据内容数组。数组项通常为具体的数据项。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IBarTypeData : virtual public IBaseArrayElement
		{
		public:

			/*@function
			*******************************************************************
			功  能:  数据项名称
			参  数:  <wzValue>;
			返回值:  <无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetName(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetName() const = 0;

			/*@function
			*******************************************************************
			功  能:  单个数据项的整数类型数值
			注  意： 一个 IBarTypeData 对象中只会一个值；并且值为最后的 SetValue
					 调用设置的值;
			参  数:  <nValue>;
			返回值:  <无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetValue(int nValue) = 0;
			virtual void GetValue(int* pnValue) = 0;

			/*@function
			*******************************************************************
			功  能:  单个数据项的小数类型数值
			注  意： 一个 IBarTypeData 对象中只会一个值；并且值为最后的 SetValue
					 调用设置的值;
			参  数:  <nValue>;
			返回值:  <无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetValue(float fValue) = 0;
			virtual void GetValue(float* pfValue) = 0;

			/*@function
			*******************************************************************
			功  能:  单个数据项的字符串型数值
			注  意： 一个 IBarTypeData 对象中只会一个值；并且值为最后的 SetValue
					 调用设置的值;
			参  数:  <nValue>;
			返回值:  <无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetValue(const wchar_t* wzValue) = 0;
			virtual void GetValue(const wchar_t** pwzValue) = 0;

			/*@function
			*******************************************************************
			功  能:  该数据项的组 ID。组 ID 会被用于分类数据，并在全局过渡动画中决定如何进行合并和分裂动画。
			参  数:  <nValue>;
			返回值:  <无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetGroupId(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetGroupId() const = 0;

			/*@function
			*******************************************************************
			功  能: 单个拐点文本的样式设置
			参  数: <无>;
			返回值: <IBarTypeDataLabel*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IBarTypeDataLabel* GetLabel() = 0;

			/*@function
			*******************************************************************
			功  能: 标签的视觉引导线配置
			参  数: <无>;
			返回值: <IBarTypeDataLabelLine*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IBarTypeDataLabelLine* GetLabelLine() = 0;

			/*@function
			*******************************************************************
			功  能: 单个数据的图形样式设置
			参  数: <无>;
			返回值: <IBarTypeDataItemStyle*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IBarTypeDataItemStyle* GetItemStyle() = 0;

			/*@function
			*******************************************************************
			功  能: 单个数据的高亮状态配置。
			参  数: <无>;
			返回值: <IBarTypeDataEmphasis*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IBarTypeDataEmphasis* GetEmphasis() = 0;

			/*@function
			*******************************************************************
			功  能: 单个数据的淡出状态配置
			参  数: <无>;
			返回值: <IBarTypeDataBlur*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IBarTypeDataBlur* GetBlur() = 0;

			/*@function
			*******************************************************************
			功  能: 单个数据的选中状态配置
			参  数: <无>;
			返回值: <IBarTypeDataSelect*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IBarTypeDataSelect* GetSelect() = 0;

		};
	}

}