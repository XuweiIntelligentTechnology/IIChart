#pragma once
/***********************************************************************
 * Module:  IPieTypeDimensionsData.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: dimensions 数组中的每一项数据;
 *          值得一提的是，当定义了 dimensions 后，默认 tooltip 中对个维度的显示
 *          会变为『竖排』，从而方便显示每个维度的名称。
 *          如果没有定义 dimensions，则默认 tooltip 会横排显示，且只显示数值没有维度名称可显示。
 * 
 *   使用 dimensions 定义 series.data 或者 dataset.source 的每个维度的信息。
 *   注意：如果使用了 dataset，那么可以在 dataset.dimensions 中定义 dimension ，或者在 dataset.source 的第一行/列中
 *   给出 dimension 名称。于是就不用在这里指定 dimension。但如果在这里指定了 dimensions，那么优先使用这里的。
 *  
 *   例如：

		option = {
			dataset: {
				source: [
					// 有了上面 dimensions 定义后，下面这五个维度的名称分别为：
					// 'date', 'open', 'close', 'highest', 'lowest'
					[12, 44, 55, 66, 2],
					[23, 6, 16, 23, 1],
					...
				]
			},
			series: {
				type: 'xxx',
				// 定义了每个维度的名称。这个名称会被显示到默认的 tooltip 中。
				dimensions: ['date', 'open', 'close', 'highest', 'lowest']
			}
		}
		series: {
			type: 'xxx',
			dimensions: [
				null,                // 如果此维度不想给出定义，则使用 null 即可
				{type: 'ordinal'},   // 只定义此维度的类型。
									 // 'ordinal' 表示离散型，一般文本使用这种类型。
									 // 如果类型没有被定义，会自动猜测类型。
				{name: 'good', type: 'number'},
				'bad'                // 等同于 {name: 'bad'}
			]
		}

   dimensions 数组中的每一项可以是：
    > string，如 'someName'，等同于 {name: 'someName'}
	> Object，属性可以有：
		> name: string。
		> type: string，支持
		    number，默认，表示普通数据。
		    ordinal，对于类目、文本这些 string 类型的数据，如果需要能在数轴上使用，
			         须是 'ordinal' 类型。ECharts 默认会自动判断这个类型。但是自动判断也是
					 不可能很完备的，所以使用者也可以手动强制指定。
		    float，即 Float64Array。
		    int，即 Int32Array。
		    time，表示时间类型。设置成 'time' 则能支持自动解析数据成时间戳（timestamp），比如
			      该维度的数据是 '2017-05-10'，会自动被解析。时间类型的支持参见 data。
		> displayName: 一般用于 tooltip 中维度名的展示。string 如果没有指定，默认使用 name 来展示。
	值得一提的是，当定义了 dimensions 后，默认 tooltip 中对个维度的显示，会变为『竖排』，从而方便显示
	每个维度的名称。如果没有定义 dimensions，则默认 tooltip 会横排显示，且只显示数值没有维度名称可显示。

 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/IBaseArrayElement.h"

namespace IIChart
{
	namespace Pie
	{
		/*@class
		*************************************************************************
		* 类  名: IPieTypeDimensionsData
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 使用 dimensions 定义 series.data 或者 dataset.source 的每个维度的信息。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IPieTypeDimensionsData : virtual public IBaseArrayElement
		{
		public:
			/*@function
			*******************************************************************
			功  能:  维度项名称
			参  数:  <wzValue>;
			返回值:  <无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetName(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetName() const = 0;

			/*@function
			*******************************************************************
			功  能:  维度数据类型
			参  数:  <eValue>;
			返回值:  <无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetType(EDDTypeValue eValue) = 0;
			virtual EDDTypeValue GetType() const = 0;

			/*@function
			*******************************************************************
			功  能:  一般用于 tooltip 中维度名的展示。string 如果没有指定，默认使用 name 来展示。
			参  数:  <wzValue> 为 nullptr 或 L"" 时原有的值将会被清空;
			返回值:  <无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetDisplayName(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetDisplayName() const = 0;
		};
	}

}