#pragma once
/***********************************************************************
 * Module:  IDatasetDimensionsData.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: dimensions 数组中的每一项数据;
 *          值得一提的是，当定义了 dimensions 后，默认 tooltip 中对个维度的显示
 *          会变为『竖排』，从而方便显示每个维度的名称。
 *          如果没有定义 dimensions，则默认 tooltip 会横排显示，且只显示数值没有维度名称可显示。
 * 
 *          使用 dimensions 定义 series.data 或者 dataset.source 的每个维度的信息。
 * 
 *          注意：如果使用了 dataset，那么可以在 dataset.dimensions 中定义 dimension ，或者
 *          在 dataset.source 的第一行/列中给出 dimension 名称。于是就不用在这里指定 dimension。
 *          但如果在这里指定了 dimensions，那么优先使用这里的。
 * 
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/IBaseArrayElement.h"

namespace IIChart
{
	namespace Dataset
	{
		/*@class
		*************************************************************************
		* 类  名: IDatasetDimensionsData
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 使用 dimensions 定义 series.data 或者 dataset.source 的每个维度的信息。
		*         并且可以自由指定数据到视觉的映射。这在不少场景下能带来使用上的方便,具体：
		*         1. 能够贴近数据可视化常见思维方式：（I）提供数据，（II）指定数据到视觉的映射，从而形成图表
		*         2. 数据和其他配置可以被分离开来。数据常变，其他配置常不变。分开易于分别管理
		*         3. 数据可以被多个系列或者组件复用，对于大数据量的场景，不必为每个系列创建一份数据
		*         4. 支持更多的数据的常用格式，例如二维数组、对象数组等，一定程度上避免使用者为了数据格式而进行转换
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IDatasetDimensionsData : virtual public IBaseArrayElement
		{
		public:

			/*@function
			******************************************************************
			功  能：名称;
			参  数: <wzValue> ;
			返回值：<错误码>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual int SetName(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetName() const = 0;

			/*@function
			******************************************************************
			功  能：数据类型;
			参  数: <eValue> ;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetType(EDDTypeValue eValue) = 0;
			virtual EDDTypeValue GetType() const = 0;

			/*@function
			******************************************************************
			功  能：一般用于 tooltip 中维度名的展示。string 如果没有指定，默认使用 name 来展示。
			参  数: <wzValue> ;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual int SetDisplayName(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetDisplayName() const = 0;
		};
	}
	
}