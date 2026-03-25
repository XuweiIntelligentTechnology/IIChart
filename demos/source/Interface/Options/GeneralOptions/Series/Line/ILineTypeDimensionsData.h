#pragma once
/***********************************************************************
 * Module:  ILineTypeDimensionsData.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: dimensions 数组中的每一项数据;
 *          值得一提的是，当定义了 dimensions 后，默认 tooltip 中对个维度的显示
 *          会变为『竖排』，从而方便显示每个维度的名称。
 *          如果没有定义 dimensions，则默认 tooltip 会横排显示，且只显示数值没有维度名称可显示。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/IBaseArrayElement.h"

namespace IIChart
{
	namespace Line
	{
		/*@class
		*************************************************************************
		* 类  名: ILineTypeDimensionsData
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 使用 dimensions 定义 series.data 或者 dataset.source 的每个维度的信息。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class ILineTypeDimensionsData : virtual public IBaseArrayElement
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