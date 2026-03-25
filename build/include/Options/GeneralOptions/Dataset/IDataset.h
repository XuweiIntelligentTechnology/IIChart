#pragma once
/***********************************************************************
 * Module:  IComponents.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: Declaration of the class IComponents
 ***********************************************************************/
#include <vector>
#include <string>
#include "Common/IEnum.h"
#include "Options/Common/IBaseArrayElement.h"
#include "Options/GeneralOptions/Dataset/IDatasetSource.h"
#include "Options/GeneralOptions/Dataset/IDatasetDimensionsData.h"
#include "Options/GeneralOptions/Dataset/IDatasetTransformConfig.h"


namespace IIChart
{
	namespace Dataset
	{
		
		/*@class
		*************************************************************************
		* 类  名: IDataset
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 数据集可以使数据进行单独管理，被多个组件复用，
		*         并且可以自由指定数据到视觉的映射。这在不少场景下能带来使用上的方便,具体：
		*         1. 能够贴近数据可视化常见思维方式：（I）提供数据，（II）指定数据到视觉的映射，从而形成图表
		*         2. 数据和其他配置可以被分离开来。数据常变，其他配置常不变。分开易于分别管理
		*         3. 数据可以被多个系列或者组件复用，对于大数据量的场景，不必为每个系列创建一份数据
		*         4. 支持更多的数据的常用格式，例如二维数组、对象数组等，一定程度上避免使用者为了数据格式而进行转换
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IDataset : virtual public IBaseArrayElement
		{
		public:

			/*@function
			******************************************************************
			功  能：组件 ID。默认不指定。指定则可用于在 option 或者 API 中引用组件。
			参  数: <wzValue> ;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void Reset() = 0;

			/*@function
			******************************************************************
			功  能：组件 ID。默认不指定。指定则可用于在 option 或者 API 中引用组件。
			注  意：调用 IGeneralOptions->Add() 增加新的 IDataset 的时候，若 ID 已经
			        存在，新增的 IDataset 只会将原 ID 的 Dataset 给替换掉。不会有将的
					IDataset 添加到 IGeneralOptions 中。此方法可以用来，修改原有的数据集;
			参  数: <wzValue> ;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetId(const wchar_t* wzId) = 0;
			virtual wchar_t* GetId() const = 0;

			/*@function
			******************************************************************
			* 功  能：取数据集组件的 数据源 对象，利用数据源对象可以向数据集中添加数据
			* 参  数：<无>;
			* 返回值：<IDatasetSource*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IDatasetSource* GetSource() = 0;

			/*****************************************************************
			* 功  能：dataset.source 第一行/列是否是 维度名 信息
			* 注  意：“第一行/列” 的意思是，如果 series.seriesLayoutBy 设置为 'column'（默认值），则取第一行，
			*        如果 series.seriesLayoutBy 设置为 'row'，则取第一列。
			* 参  数：<eValue> 新的数据;
			* 返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetSourceHeader(ESourceHeader eValue) = 0;
			virtual ESourceHeader GetSourceHeader() = 0;

			/*@function
			******************************************************************
			* 功  能：维度名行/列数，也就是数据行/列的开始索引。
			*        例如：sourceHeader: 2 意味着前两行/列为维度名，从第三行/列开始为数据。
			* 注  意：“第一行/列” 的意思是，如果 series.seriesLayoutBy 设置为 'column'（默认值），则取第一行，
			*        如果 series.seriesLayoutBy 设置为 'row'，则取第一列。
			* 参  数：<nNumber> 新的数据;
			* 返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetSourceHeader(int nNumber = 0) = 0;
			virtual void GetSourceHeader(int* pnNumber = 0) = 0;

			/*@function
			*****************************************************************
			* 功  能：清空 DimensionsData 数据;
			* 返回值：<错误码>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void ClearDimensionsData() = 0;

			/*@function
			*****************************************************************
			* 功  能：使用 dimensions 定义 series.data 或者 dataset.source 的每个维度的信息。
			* 注  意：此接口创建的数据项可以作为IFixedQueue的元素
			*         -- 使用完后需要调用 Release 释放相资源;
			*         -- IFixedQueue中的元素将由其自动进行内存回收管理;
			* 参  数：<wzName> 名称;
			*         <eType> 类型;
			*         <wzDisplayName> 数据描述;
			* 返回值：ILineTypeDimensionsData*;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IDatasetDimensionsData* CreateDimensionsData() = 0;
			virtual IDatasetDimensionsData* CreateDimensionsData(const wchar_t* wzName, EDDTypeValue eType, const wchar_t* wzDisplayName = nullptr) = 0;

			/*@function
			*****************************************************************
			* 功  能：添加纬度的值，如果此维度不想给出定义，则使用 nullptr 即可;
			* 参  数：<wzName> 名称;
			*         <eType> 类型;
			*         <wzDisplayName> 数据描述;
			* 返回值：<错误码>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual int AddDimensionsData(IDatasetDimensionsData* pData) = 0;
			virtual int AddDimensionsData(const wchar_t* wzName, EDDTypeValue eType, const wchar_t* wzDisplayName = nullptr) = 0;

			/*@function
			*****************************************************************
			* 功  能：在原来的 dimensions 数据后追加新数据;
			*         每个纬度的值之间使用“,”分隔;如：“date,open,close,highest,lowest”
			* 参  数：<wzValue> 使用“,”分隔的dimensions;
			* 返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual int AddDimensions(const wchar_t* wzValue) = 0;

			/*@function
			*****************************************************************
			* 功  能：在原来的 dimensions 数据后追加新数据;
			* 参  数：<vctValue> dimensions 数据;
			* 返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual int AddDimensions(const std::vector<std::wstring>& vctValue) = 0;

			/*@function
			*****************************************************************
			* 功  能：使用 dimensions 定义 series.data 或者 dataset.source 的每个维度的信息。
			* 注  意：在原来的 dimensions 数据后追加新数据;
			*         此接口可以方便的实现动态图表显示;
			* 参  数：<pQueue> 新的数据;
			* 返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual int AddDimensions(IFixedQueue* pQueue) = 0;

			/*@function
			*****************************************************************
			* 功  能：使用 dimensions 定义 series.data 或者 dataset.source 的每个维度的信息。
			*         每个纬度的值之间使用“,”分隔;如：“date,open,close,highest,lowest”
			* 参  数：<wzValue> 使用“,”分隔的dimensions;
			* 返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetDimensions(const wchar_t* wzValue) = 0;

			/*@function
			*****************************************************************
			* 功  能：使用 dimensions 定义 series.data 或者 dataset.source 的每个维度的信息。
			* 参  数：<vctValue> dimensions 数据;
			* 返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetDimensions(const std::vector<std::wstring>& vctValue) = 0;

			/*@function
			*****************************************************************
			* 功  能：使用 dimensions 定义 series.data 或者 dataset.source 的每个维度的信息。
			* 注  意：原来的 dimensions 数据将被覆盖掉;
			*         此接口可以方便的实现动态图表显示;
			* 参  数：<pQueue> 新的数据;
			* 返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual int SetDimensions(IFixedQueue* pQueue) = 0;

			/*@function
			*****************************************************************
			* 功  能：创建数据转换方法的具体配置。
			* 参  数：<无>;
			* 返回值：<IDatasetTransformConfig*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IDatasetTransformConfig* CreateTransformConfig() = 0;

			/*@function
			*****************************************************************
			* 功  能：添加数据转换方法。
			* 注  意：抽象地来说，数据转换是这样一种公式：outData = f(inputData)，其中f 是转换方法
			*        有了数据转换能力后，我们就至少可以做到这些事情：
			*        1. 把数据分成多份用不同的饼图展现。
			*        2. 进行一些数据统计运算，并展示结果。
			*        3. 用某些数据可视化算法处理数据，并展示结果。
			*        4. 数据排序。
			*        5. 去除或直选择数据项。
			*        ... ...
			* 参  数：<eValue> 内置的数据转换器类型;
			*         <bPrintf> 使用 transform 时，有时候我们会配不对，显示不出来结果，并且不知道哪里错了
			                    这个配置项 transform.print 方便 debug 。这个配置项只在开发环境中生效。;
			*         <wzConfig> 数据转换器的“条件”，其格式如：;
			*                    L"{dimension: 'Year', order: 'desc'}"
			*                    L"{dimension: 'Product', value: 'Tofu'}"
			*                    L"{dimension: 'Date', '>=': '2012-05', '<': '2012-06', parser: 'time'}"
			*                    L"{\"dimension\": \"Product\", \"value\": \"Biscuit\" }"
			*                    L"{'dimension': 'Product', 'value': 'Biscuit' }"
			* 返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual int AddTransform(ETransformType eValue, bool bPrintf, const wchar_t* wzConfig) = 0;
			virtual int AddTransform(ETransformType eValue, bool bPrintf, IDatasetTransformConfig* pConfig) = 0;

			/*@function
			*****************************************************************
			* 功  能：添加数据转换方法。
			* 注  意：抽象地来说，数据转换是这样一种公式：outData = f(inputData)，其中f 是转换方法
			*        有了数据转换能力后，我们就至少可以做到这些事情：
			*        1. 把数据分成多份用不同的饼图展现。
			*        2. 进行一些数据统计运算，并展示结果。
			*        3. 用某些数据可视化算法处理数据，并展示结果。
			*        4. 数据排序。
			*        5. 去除或直选择数据项。
			*        ... ...
			* 参  数：<wzTransformType> 外置的数据转换器类型;
			*         <bPrintf> 使用 transform 时，有时候我们会配不对，显示不出来结果，并且不知道哪里错了
			*					这个配置项 transform.print 方便 debug 。这个配置项只在开发环境中生效。;
			*         <wzConfig> 数据转换器的“条件”，其格式如：;
			*                    L"{dimension: 'Year', order: 'desc'}"
			*                    L"{dimension: 'Product', value: 'Tofu'}"
			* 返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			//virtual int AddTransform(const wchar_t* wzTransformType, bool bPrintf, const wchar_t* wzConfig) = 0;
			//virtual int AddTransform(const wchar_t* wzTransformType, bool bPrintf, IDatasetTransformConfig* pConfig) = 0;

			/*@function
			*****************************************************************
			* 功  能：添加排序数据转换方法。
			* 注  意：抽象地来说，数据转换是这样一种公式：outData = f(inputData)，其中f 是转换方法
			*        有了数据转换能力后，我们就至少可以做到这些事情：
			*        1. 把数据分成多份用不同的饼图展现。
			*        2. 进行一些数据统计运算，并展示结果。
			*        3. 用某些数据可视化算法处理数据，并展示结果。
			*        4. 数据排序。
			*        5. 去除或直选择数据项。
			*        ... ...
			* 参  数：<wzTransformType> 外置的数据转换器类型;
			*         <bPrintf> 使用 transform 时，有时候我们会配不对，显示不出来结果，并且不知道哪里错了
								这个配置项 transform.print 方便 debug 。这个配置项只在开发环境中生效。;
			*         <wzConfig> 数据转换器的“条件”;
			*         <eOrder> 排序方法;
			* 返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			//virtual int AddSortTransform(const wchar_t* wzTransformType, bool bPrintf, const wchar_t* wzConfig, ETransformSort eOrder) = 0;
			//virtual int AddSortTransform(const wchar_t* wzTransformType, bool bPrintf, IDatasetTransformConfig* pConfig, ETransformSort eOrder) = 0;

			/*@function
			*****************************************************************
			* 功  能：添加过滤数据转换方法。
			* 注  意：抽象地来说，数据转换是这样一种公式：outData = f(inputData)，其中f 是转换方法
			*        有了数据转换能力后，我们就至少可以做到这些事情：
			*        1. 把数据分成多份用不同的饼图展现。
			*        2. 进行一些数据统计运算，并展示结果。
			*        3. 用某些数据可视化算法处理数据，并展示结果。
			*        4. 数据排序。
			*        5. 去除或直选择数据项。
			*        ... ...
			* 参  数：<wzTransformType> 外置的数据转换器类型;
			*         <bPrintf> 使用 transform 时，有时候我们会配不对，显示不出来结果，并且不知道哪里错了
			*					这个配置项 transform.print 方便 debug 。这个配置项只在开发环境中生效。;
			*         <wzDimension> 数据转换器的“条件”中的“Dimension”;
			*         <nValue/fValue> 数据值;
			* 返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			//virtual int AddFilterTransform(const wchar_t* wzTransformType, bool bPrintf, const wchar_t* wzDimension, int nValue) = 0;
			//virtual int AddFilterTransform(const wchar_t* wzTransformType, bool bPrintf, const wchar_t* wzDimension, float fValue) = 0;

			/*@function
			*****************************************************************
			* 功  能：删除添加的数据转换方法。
			* 返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void ClearTransform() = 0;

			/*@function
			*****************************************************************
			* 功  能：指定 dataset.transform 以哪个 dataset 作为输入。
			* 注  意：如果 dataset.transform 被指定了，但是 fromDatasetIndex 和 fromDatasetId 
			*         都没有被指定，那么默认会使用 fromDatasetIndex: 0.
			* 参  数：<nValue> ;
			* 返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetFromDatasetIndex(int nValue) = 0;
			virtual int  GetFromDatasetIndex() const = 0;

			/*@function
			******************************************************************
			* 功  能：指定 dataset.transform 以哪个 dataset 作为输入。
			* 参  数：<wzValue> ;
			* 返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual int SetFromDatasetId(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetFromDatasetId() const = 0;

			/*@function
			*****************************************************************
			* 功  能：如果一个 dataset.transform 会产出多个结果 data ，我们可以使用 fromTransformResult 获得特定的结果。
			* 注  意：大多数场景下，transform 只会产出一个结果，所以大多数情况下 fromTransformResult 并不需要指定。
			*        当不指定 fromTransformResult 时，默认使用 fromTransformResult: 0。
			* 参  数：<nValue> ;
			* 返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetFromTransformResult(int nValue) = 0;
			virtual int  GetFromTransformResult() const = 0;
		};
	}
	


}