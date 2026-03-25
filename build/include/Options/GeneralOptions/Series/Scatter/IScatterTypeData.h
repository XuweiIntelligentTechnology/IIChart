#pragma once
/***********************************************************************
 * Module:  IScatterTypeData.h
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
#include "Options/Common/ICompactTooltip.h"
#include "Options/GeneralOptions/Series/Scatter/IScatterTypeDataLabelLine.h"
#include "Options/GeneralOptions/Series/Scatter/IScatterTypeDataItemStyle.h"
#include "Options/GeneralOptions/Series/Scatter/IScatterTypeDataLabel.h"
#include "Options/GeneralOptions/Series/Scatter/IScatterTypeDataSelect.h"		  
#include "Options/GeneralOptions/Series/Scatter/IScatterTypeDataBlur.h"
#include "Options/GeneralOptions/Series/Scatter/IScatterTypeDataEmphasis.h"

namespace IIChart
{
	namespace Scatter
	{
		/*@class
		*************************************************************************
		* 类  名: IScatterTypeData
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 系列中的数据
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IScatterTypeData : virtual public IBaseArrayElement
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
			注  意： 一个 ILineTypeData 对象中只会一个值；并且值为最后的 SetValue
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
			注  意： 一个 ILineTypeData 对象中只会一个值；并且值为最后的 SetValue
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
			注  意： 一个 ILineTypeData 对象中只会一个值；并且值为最后的 SetValue
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
			功  能:  设置 标记的图形
			参  数:  <eValue>;
			返回值:  <无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetSymbol(ESymbol eValue) = 0;
			virtual ESymbol GetSymbol() const = 0;

			/*@function
			*******************************************************************
			 功  能：用图片设置 标记的图形
			 注  意：本接口参数只能是以下几种形式：
					 1. 图片链接：
					 'image://http://example.website/a/b.png'
					 2. dataURI：
					 'image://data:image/gif;base64,R0lGODlhEAAQAMQAAORHHOVSKudfOulrS
							Op3WOyDZu6QdvCchPGolfO0o/XBs/fNwfjZ0frl3/zy7////wAAAAAAAAA
							AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACH5B
							AkAABAALAAAAAAQABAAAAVVICSOZGlCQAosJ6mu7fiyZeKqNKToQGDsM8hBA
							DgUXoGAiqhSvp5QAnQKGIgUhwFUYLCVDFCrKUE1lBavAViFIDlTImbKC5Gm2h
							B0SlBCBMQiB0UjIQA7'
					 3. 矢量路径：（可以参考 https://www.w3.org/TR/SVG/paths.html#PathData）
							'path://M30.9,53.2C16.8,53.2,5.3,41.7,5.3,27.6S16.8,2,30.9,2C45,
							2,56.4,13.5,56.4,27.6S45,53.2,30.9,53.2z M30.9,3.5C17.6,3.5,6.8,
							14.4,6.8,27.6c0,13.3,10.8,24.1,24.101,24.1C44.2,51.7,55,40.9,55,
							27.6C54.9,14.4,44.1,3.5,30.9,3.5z M36.9,35.8c0,0.601-0.4,1-0.9,
							1h-1.3c-0.5,0-0.9-0.399-0.9-1V19.5c0-0.6,0.4-1,0.9-1H36c0.5,0,0.9,
							0.4,0.9,1V35.8z M27.8,35.8 c0,0.601-0.4,1-0.9,1h-1.3c-0.5,
							0-0.9-0.399-0.9-1V19.5c0-0.6,0.4-1,0.9-1H27c0.5,0,0.9,0.4,0.9,1L27.8,
							35.8L27.8,35.8z'
			 参  数：<wzValue>图片的 URL 或 dataURI也可以是 Path;
			 返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetSymbolImage(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetSymbolImage() const = 0;

			/*@function
			*******************************************************************
			功  能:  标记的大小，可以设置成诸如 10 这样单一的数字
			参  数:  <nSize>;
			返回值:  <无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetSymbolSize(int nSize) = 0;
			virtual int GetSymbolSize() const = 0;

			/*@function
			*******************************************************************
			功  能: 标记的大小，高度
			参  数: <nSize>;
			返回值: <无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetSymbolSize(int nHeight, int nWidth) = 0;
			virtual void GetSymbolSize(int& nHeight, int& nWidth) = 0;

			/*@function
			*******************************************************************
			功  能: 标记的旋转角度（而非弧度）,正值表示逆时针旋转。
			注  意: 在 markLine 中当 symbol 为 'arrow' 时会忽略 symbolRotate 强制设置为切线的角度。
			参  数: <nSize>;
			返回值: <无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetSymbolRotate(int nRotate) = 0;
			virtual int GetSymbolRotate() const = 0;

			/*@function
			*******************************************************************
			功  能: 如果 symbol 是 path:// 的形式，是否在缩放时保持该图形的长宽比。
			参  数: <nSize>;
			返回值: <无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetSymbolKeepAspect(bool bValue) = 0;
			virtual bool GetSymbolKeepAspect() const = 0;

			/*@function
			*******************************************************************
			 功  能：标记相对于原本位置的偏移。
			 注  意：默认情况下，标记会居中置放在数据对应的位置
					 但是如果 symbol 是自定义的矢量路径或者图片，就有可能不希望 symbol 居中。
					 这时候可以使用该配置项配置 symbol 相对于原本居中的偏移，此处为绝对的像素值，
			 参  数：<nX> 水平偏移;
					 <nY> 垂直偏移;
					 <bIsPercentage> 默认为false，表示偏移值为像素，否则为百分比;
			 返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetSymbolOffset(int nX, int nY, bool bIsPercentage) = 0;
			virtual void GetSymbolOffset(int* pnX, int* pnY, bool* pbIsPercentage) = 0;

			/*@function
			*******************************************************************
			功  能: 单个数据项的文本的样式设置
			参  数: <无>;
			返回值: <IScatterTypeDataLabel*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IScatterTypeDataLabel* GetLabel() = 0;

			/*@function
			*******************************************************************
			功  能: 标签的视觉引导线配置。
			参  数: <无>;
			返回值: <IScatterTypeDataLabel*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IScatterTypeDataLabelLine* GetLabelLine() = 0;

			/*@function
			*******************************************************************
			功  能: 单个数据项的的图形样式设置
			参  数: <无>;
			返回值: <IScatterTypeDataItemStyle*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IScatterTypeDataItemStyle* GetItemStyle() = 0;

			/*@function
			*******************************************************************
			功  能: 单个数据项的的高亮样式和标签设置
			参  数: <无>;
			返回值: <IScatterTypeDataEmphasis*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IScatterTypeDataEmphasis* GetEmphasis() = 0;

			/*@function
			*******************************************************************
			功  能: 单个数据项的淡出样式和标签设置
			参  数: <无>;
			返回值: <IScatterTypeDataBlur*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IScatterTypeDataBlur* GetBlur() = 0;

			/*@function
			*******************************************************************
			功  能: 单个数据项的选中样式和标签设置。
			参  数: <无>;
			返回值: <IScatterTypeDataBlur*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IScatterTypeDataSelect* GetSelect() = 0;

			/*@function
			*******************************************************************
			功  能: 本系列单个数据项中特定的 tooltip 设定。
			参  数: <无>;
			返回值: <ICompactTooltip*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ICompactTooltip* GetTooltip() = 0;
		};
	}

}