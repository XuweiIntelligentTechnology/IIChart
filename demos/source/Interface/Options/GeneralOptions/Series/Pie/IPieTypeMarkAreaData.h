#pragma once
/***********************************************************************
 * Module:  IPieTypeMarkAreaData.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: 标域的数据数组。
 * 
 *     每个数组项可以是一个两个值的数组，分别表示线的起点和终点，
 *     每一项是一个对象，有下面几种方式指定起点或终点的位置。  
 *     1. 通过 x, y 属性指定相对容器的屏幕坐标，单位像素，支持百分比。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/ILineStyle.h"
#include "Options/Common/IBaseArrayElement.h"
#include "Options/GeneralOptions/Series/Pie/IPieTypeMarkAreaDataItemStyle.h"
#include "Options/GeneralOptions/Series/Pie/IPieTypeMarkAreaDataLabel.h"
#include "Options/GeneralOptions/Series/Pie/IPieTypeMarkAreaDataBlur.h"
#include "Options/GeneralOptions/Series/Pie/IPieTypeMarkAreaDataEmphasis.h"



namespace IIChart
{
	namespace Pie
	{
		/*@class
		*************************************************************************
		* 类  名: IPieTypeMarkAreaData
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 图表标域数据
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IPieTypeMarkAreaData : virtual public IBaseArrayElement
		{
		public:
			
			/*@function
			******************************************************************
			功  能：标域名称。
			参  数：<wzValue>;
			返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetName(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetName() const = 0;

			/*@function
			******************************************************************
			功  能：相对容器的屏幕 x 坐标，单位像素。
			参  数：<nValue>;
				   <bIsPercentage> 为 true 时，以百分比设置标签的 x 位置。;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetX(int nValue, bool bIsPercentage) = 0;
			virtual void GetX(int* pnValue, bool* pbIsPercentage) = 0;

			/*@function
			******************************************************************
			功  能：相对容器的屏幕 y 坐标，单位像素。
			参  数：<nValue>;
				    <bIsPercentage> 为 true 时，以百分比设置标签的 y 位置。;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetY(int nValue, bool bIsPercentage) = 0;
			virtual void GetY(int* pnValue, bool* pbIsPercentage) = 0;

			/*@function
			******************************************************************
			功  能：标域值，可以不设。
			参  数：<nValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetValue(int nValue) = 0;
			virtual void GetValue(int* pnValue) const = 0;

			/*@function
			******************************************************************
			功  能：标域值，可以不设。
			参  数：<fValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetValue(float fValue) = 0;
			virtual void GetValue(float* pfValue) const = 0;
			
			/*@function
			******************************************************************
			功  能：该标域数据项的样式
			参  数：<无>;
			返回值：<IPieTypeMarkAreaDataItemStyle*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IPieTypeMarkAreaDataItemStyle* GetItemStyle() = 0;

			/*@function
			******************************************************************
			功  能：该标域数据项的标签样式
			参  数：<无>;
			返回值：<IPieTypeMarkAreaDataLabel*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IPieTypeMarkAreaDataLabel * GetLabel() = 0;

			/*@function
			******************************************************************
			功  能：该标域数据项的高亮样式和标签设置
			参  数：<无>;
			返回值：<IPieTypeMarkAreaDataEmphasis*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IPieTypeMarkAreaDataEmphasis* GetEmphasis() = 0;

			/*@function
			******************************************************************
			功  能：该标域数据项的淡出样式和标签设置
			参  数：<无>;
			返回值：<IPieTypeMarkAreaDataBlur*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IPieTypeMarkAreaDataBlur* GetBlur() = 0;
		};
	}
}