#pragma once
/***********************************************************************
 * Module:  IGaugeTypeMarkPointData.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: 标域的数据数组。
 * 
 *     标域的数据数组。每个数组项是一个两个项的数组，分别表示标域左上角和右下角的位置，
 *     每个项支持通过下面几种方式指定自己的位置。  
 *      通过 x, y 属性指定相对容器的屏幕坐标，单位像素，支持百分比。
 *      例如：
	 data: [

	[
			{
				name: '两个屏幕坐标之间的标域',
				x: 100,
				y: 100
			}, {
				x: '90%',
				y: '10%'
			}
		]
	]

 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/ILineStyle.h"
#include "Options/Common/IBaseArrayElement.h"
#include "Options/GeneralOptions/Series/Gauge/IGaugeTypeItemStyle.h"
#include "Options/GeneralOptions/Series/Gauge/IGaugeTypeMarkAreaLabel.h"
#include "Options/GeneralOptions/Series/Gauge/IGaugeTypeMarkAreaBlur.h"
#include "Options/GeneralOptions/Series/Gauge/IGaugeTypeMarkAreaEmphasis.h"



namespace IIChart
{
	namespace Gauge
	{
		/*@class
		*************************************************************************
		* 类  名: IGaugeTypeMarkAreaData
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 标域的数据。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IGaugeTypeMarkAreaData : virtual public IBaseArrayElement
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
			virtual int SetName(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetName() const = 0;

			/*@function
			******************************************************************
			功  能：相对容器的屏幕 x 坐标，单位像素。
			参  数：<wzValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetX(int nIndex) = 0;
			virtual int  GetX() const = 0;

			/*@function
			******************************************************************
			功  能：相对容器的屏幕 y 坐标，单位像素。
			参  数：<wzValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetY(int nIndex) = 0;
			virtual int  GetY() const = 0;

			/*@function
			******************************************************************
			功  能：标注值，可以不设。
			参  数：<nValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetValue(int nValue) = 0;
			virtual void SetValue(float fValue) = 0;
			virtual void GetValue(int* pnValue) const = 0;
			virtual void GetValue(float* pfValue) const = 0;
			
			/*@function
			*******************************************************************
			 功  能：该数据项区域的样式，起点和终点项的itemStyle会合并到一起。
			 参  数：<无>;
			 返回值：<IGaugeTypeItemStyle*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IGaugeTypeItemStyle* GetItemStyle() = 0;

			/*@function
			*******************************************************************
			 功  能：该数据项标签的样式，起点和终点项的label会合并到一起。
			 参  数：<无>;
			 返回值：<IGaugeTypeMarkAreaLabel*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IGaugeTypeMarkAreaLabel * GetLabel() = 0;

			/*@function
			*******************************************************************
			 功  能：该数据项高亮样式和标签设置
			 参  数：<无>;
			 返回值：<IGaugeTypeMarkAreaEmphasis*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IGaugeTypeMarkAreaEmphasis* GetEmphasis() = 0;

			/*@function
			*******************************************************************
			 功  能：该数据项的淡出样式和标签设置
			 参  数：<无>;
			 返回值：<IGaugeTypeMarkAreaBlur*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IGaugeTypeMarkAreaBlur* GetBlur() = 0;
		};
	}
}