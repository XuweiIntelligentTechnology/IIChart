#pragma once
/***********************************************************************
 * Module:  ILegendData.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: 图例的数据。
 *    数组项通常为一个字符串，每一项代表一个系列的 name（如果是饼图，也可以是饼图单个数据的 name）。
 *    图例组件会自动根据对应系列的图形标记（symbol）来绘制自己的颜色和标记，
 *    特殊字符串 ''（空字符串）或者 '\n'（换行字符串）用于图例的换行。
 *  
 *    如果 data 没有被指定，会自动从当前系列中获取。多数系列会取自 series.name 或者 series.encode 的 seriesName 
 *    所指定的维度。如 饼图 and 漏斗图 等会取自 series.data 中的 name。
 *    如果要设置单独一项的样式，也可以把该项写成配置项对象。此时必须使用 name 属性对应表示系列的 name。
 * 
 ***********************************************************************/
#include <vector>
#include <string>
#include "Common/IEnum.h"
#include "Common/ICallback.h"
#include "Common/IFixedQueue.h"
#include "Options/Common/IBaseArrayElement.h"
#include "Options/Common/ICategoryData.h"
#include "Options/GeneralOptions/Legend/ILegendItemStyle.h"
#include "Options/GeneralOptions/Legend/ILegendLineStyle.h"
#include "Options/GeneralOptions/Legend/ILegendTextStyle.h"

namespace IIChart
{
	namespace Legend
	{
		/*@class
		*************************************************************************
		* 类  名: ILegendData
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 图例的数据
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class ILegendData
			: public IBaseArrayElement
		{
		public:

			/*@function
			******************************************************************
			功  能：图例项的名称，应等于某系列的name值（如果是饼图，也可以是饼图单个数据的 name）。
			参  数: <wzValue> 为 nullptr 或 L"" 时为不指定;
			返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetName(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetName() const = 0;

			/*@function
			******************************************************************
			功  能：图例项的 icon。
			参  数: <eValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetIcon(ESymbol eValue) = 0;
			virtual ESymbol GetIcon() const = 0;

			/*@function
			******************************************************************
			 功  能：用图片设置 图例项的 icon。
			 注  意：本接口参数只能是以下几种形式：
					 1. 图片链接：
					 'image://http://example.website/a/b.png'
					 2. dataURI：
					 'image://data:image/gif;base64,R0lGODlhEAAQAMQAAORHHOVSKudfOulrSOp3WOyDZu6QdvCchPGolfO0o/XBs/fNwfjZ0frl3/zy7////wAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACH5BAkAABAALAAAAAAQABAAAAVVICSOZGlCQAosJ6mu7fiyZeKqNKToQGDsM8hBADgUXoGAiqhSvp5QAnQKGIgUhwFUYLCVDFCrKUE1lBavAViFIDlTImbKC5Gm2hB0SlBCBMQiB0UjIQA7'
					 3. 矢量路径：（可以参考 https://www.w3.org/TR/SVG/paths.html#PathData）
					 'path://M30.9,53.2C16.8,53.2,5.3,41.7,5.3,27.6S16.8,2,30.9,2C45,2,56.4,13.5,56.4,27.6S45,53.2,30.9,53.2z M30.9,3.5C17.6,3.5,6.8,14.4,6.8,27.6c0,13.3,10.8,24.1,24.101,24.1C44.2,51.7,55,40.9,55,27.6C54.9,14.4,44.1,3.5,30.9,3.5z M36.9,35.8c0,0.601-0.4,1-0.9,1h-1.3c-0.5,0-0.9-0.399-0.9-1V19.5c0-0.6,0.4-1,0.9-1H36c0.5,0,0.9,0.4,0.9,1V35.8z M27.8,35.8 c0,0.601-0.4,1-0.9,1h-1.3c-0.5,0-0.9-0.399-0.9-1V19.5c0-0.6,0.4-1,0.9-1H27c0.5,0,0.9,0.4,0.9,1L27.8,35.8L27.8,35.8z'
			 参  数：<wzValue> 为 nullptr 或 L"" 时为不指定;
			 返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetIconImage(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetIconImage() const = 0;

			/*@function
			******************************************************************
			功  能：图例项的图形样式。
			参  数: <无>;
			返回值：<ILegendItemStyle* >;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILegendItemStyle* GetItemStyle() = 0;

			/*@function
			******************************************************************
			功  能：图例项图形中线的样式，用于诸如折线图图例横线的样式设置。
			参  数: <无>;
			返回值：<ILegendLineStyle* >;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILegendLineStyle* GetLineStyle() = 0;

			/*@function
			******************************************************************
			功  能：图形旋转角度，。
			参  数: <nRotate>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetSymbolRotate(int nRotate) = 0;
			virtual int  GetSymbolRotate() const = 0;

			/*@function
			******************************************************************
			功  能：图例项的文本样式，。
			参  数: <无>;
			返回值：<ILegendTextStyle*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILegendTextStyle* GetTextStyle() = 0;
		};
	}
	
}