#pragma once
/***********************************************************************
 * Module:  IDatasetTransformConfigItem.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: Declaration of the class IDataArray
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/IBaseArrayElement.h"


namespace IIChart
{
	namespace Dataset
	{
		/*@class
		*************************************************************************
		* 类  名: IDatasetTransformConfigItem
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: Dataset 组件数据转换功能的配置项;
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2023-1-10;
		************************************************************************/
		class IDatasetTransformConfigItem : virtual public IBaseArrayElement
		{
		public:

			/*@function
			******************************************************************
			功  能：指定了维度名称。
			参  数: <wzValue> ;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual int  SetDimension(const wchar_t*) = 0;

			/*@function
			******************************************************************
			功  能：设定成 dataset 中的维度序号;
			注  意：序号值从 0 开始;
			参  数: <wzValue> ;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void SetDimension(int nValue) = 0;

			/*@function
			******************************************************************
			功  能：设定 Sort 类型数据转换器的排序方式;
			注  意：只能用于 Sort 类型的数据转换器中;
			参  数: <eValue> ;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void SetOrder(ETransformSort eValue) = 0;

			/*@function
			******************************************************************
			功  能：添加一个关系操作。
			注  意：在一个配置项中可以同时存在多个关系操作;
			参  数: <eValue> 关系操作;
			        <nValue/fValue> ;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void AddRelationalOperation(ERelationalType eValue, int nValue) = 0;
			virtual void AddRelationalOperation(ERelationalType eValue, float fValue) = 0;
			virtual int  AddRelationalOperation(ERelationalType eValue, const wchar_t* wzValue) = 0;

			/*@function
			******************************************************************
			功  能：提供正则表达式比较操作。
			注  意：在一个配置项中可以同时存在多个关系操作;
			参  数: <wzValue> 正则表达式, 例如 L"/\s+Müller\s*$/";
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void AddRegOperation(const wchar_t* wzValue) = 0;

			/*@function
			******************************************************************
			功  能：针对 类数值的字符串 的数据添加一个关系操作。
			注  意：data 里的值，不仅可以是数值（ number ），也可以是“类数值的字符串”;
			       “类数值的字符串”本身是一个字符串，但是可以被转换为字面所描述的数值，
				   例如 ' 123 '。转换过程中，空格（全角半角空格）和换行符都能被 EPT_Trim 类
				   型的解析器消除。
			参  数: <eLogic> ;
					<wzValue> ;
					<eParser> 指定“解析器”（ parser ）来对值进行解析后再做比较;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual int AddRelationalOperation(ERelationalType eLogic, const wchar_t* wzValue, EParserType eParser) = 0;

		};

	}



}