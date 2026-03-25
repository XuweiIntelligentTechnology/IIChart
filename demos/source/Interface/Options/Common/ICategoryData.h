#pragma once
/***********************************************************************
 * Module:  ICategoryData.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: 类目数据，在类目轴（type: 'category'）中有效。
 *     可用作类目轴的组件有：
 *     xAxis与yAxis, radiusAxis, angleAxis, parallelAxis, singleAxis
 * 
 *     如果没有设置 type，但是设置了 axis.data，则认为 type 是 'category'。
 *     如果设置了 type 是 'category'，但没有设置 axis.data，则 axis.data 的内容会
 *     自动从 series.data 中获取，这会比较方便。
 *     不过注意，axis.data 指明的是 'category' 轴的取值范围。
 *     如果不指定而是从 series.data 中获取，那么只能获取到 series.data 中出现的值。
 *     比如说，假如 series.data 为空时，就什么也获取不到。
 *
 ***********************************************************************/
#include "Options/Common/ITextStyle.h"
#include "Options/Common/IBaseArrayElement.h"

namespace IIChart
{
	/*@class
	***********************************************************************
	* 类  名: ICategoryData
	* 修  改: 2022年7月1日 15:02:44
	* 功  能: 类目数据。
	-----------------------------------------------------------------------
	* 作  者:  YangPenghui 2022-10-26;
	************************************************************************/
	class ICategoryData
		: public IBaseArrayElement
	{
	public:
		/*@function
		******************************************************************
		功  能：数据值，即单个类目名称。
		参  数：<wzValue>;
		返回值：<无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual int SetValue(const wchar_t* wzValue) = 0;
		virtual wchar_t* GetValue() const = 0;

		/*@function
		******************************************************************
		功  能：数据值的文本样式。
		参  数：<无>;
		返回值：<ITextStyle*>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual ITextStyle* GetTextStyle() = 0;
	};
}
