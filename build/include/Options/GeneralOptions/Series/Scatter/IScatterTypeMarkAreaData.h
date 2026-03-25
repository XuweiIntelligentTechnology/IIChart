#pragma once
/***********************************************************************
 * Module:  IScatterTypeMarkAreaData.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: 标域的数据数组元素。
 * 
 *     每个数组项可以是一个两个值的数组，分别表示线的起点和终点，
 *     每一项是一个对象，有下面几种方式指定起点或终点的位置。  
 *     1. 通过 x, y 属性指定相对容器的屏幕坐标，单位像素，支持百分比。
 *     2. 用 coord 属性指定数据在相应坐标系上的坐标位置，单个维度支持设置 'min', 'max', 'average'。
 *     3. 直接用 type 属性标注系列中的最大值，最小值。这时候可以使用 valueIndex 或者 valueDim 指定
 *         是在哪个维度上的最大值、最小值、平均值。
 *     4. 如果是笛卡尔坐标系的话，也可以通过只指定 xAxis 或者 yAxis 来实现 X 轴或者 Y 轴为某值的标线
 *	   
 *     当多个属性同时存在时，优先级按上述的顺序。例如：
	 data: [


		[
			{
				name: '平均值到最大值',
				type: 'average'
			},
			{
				type: 'max'
			}
		],

		[
			{
				name: '两个坐标之间的标域',
				coord: [10, 20]
			},
			{
				coord: [20, 30]
			}
		], [
			{
				name: '60分到80分',
				yAxis: 60
			},
			{
				yAxis: 80
			}
		], [
			{
				name: '所有数据范围区间',
				coord: ['min', 'min']
			},
			{
				coord: ['max', 'max']
			}
		],
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
#include "Options/GeneralOptions/Series/Scatter/IScatterTypeMarkAreaDataItemStyle.h"
#include "Options/GeneralOptions/Series/Scatter/IScatterTypeMarkAreaDataLabel.h"
#include "Options/GeneralOptions/Series/Scatter/IScatterTypeMarkAreaDataBlur.h"
#include "Options/GeneralOptions/Series/Scatter/IScatterTypeMarkAreaDataEmphasis.h"



namespace IIChart
{
	namespace Scatter
	{
		/*@class
		*************************************************************************
		* 类  名: IScatterTypeMarkAreaData
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 图表标域数据
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IScatterTypeMarkAreaData : virtual public IBaseArrayElement
		{
		public:
			
			/*@function
			******************************************************************
			功  能：特殊的标注类型，用于标注最大值最小值等。
			参  数：<eValue>;
			返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetType(EMarkLineDataType eValue) = 0;
			virtual EMarkLineDataType GetType() const = 0;

			/*@function
			******************************************************************
			功  能：在使用 type 时有效，用于指定在哪个维度上指定最大值最小值
				   可以是 0（xAxis, radiusAxis），1（yAxis, angleAxis），默认使用第一个数值轴所在的维度。
			参  数：<nIndex>;
			返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetValueIndex(int nIndex) = 0;
			virtual int  GetValueIndex() const = 0;

			/*@function
			******************************************************************
			功  能：在使用 type 时有效，用于指定在哪个维度上指定最大值最小值
			参  数：<eValue>;
			返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetValueDim(EValueDim eValue) = 0;
			virtual void GetValueDim(EValueDim* peValue) = 0;

			/*@function
			******************************************************************
			功  能：在使用 type 时有效，用于指定在哪个维度上指定最大值最小值
				    例如折线图时可以是x、angle等、candlestick 图时可以是open、close等维度名称。
			参  数：<nIndex>;
			返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetValueDim(const wchar_t* wzValue) = 0;
			virtual void GetValueDim(wchar_t** pwzValue) = 0;

			/*@function
			******************************************************************
			功  能：标注名称，将会作为文字显示。
			参  数：<wzValue>;
			返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetName(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetName() const = 0;

			/*@function
			******************************************************************
			功  能：清除掉起点或终点的坐标
			参  数：<无>;
			返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void ClearCoord() = 0;

			/*@function
			******************************************************************
			功  能：起点或终点的坐标。坐标格式视系列的坐标系而定:
				   > 可以是直角坐标系上的 x, y，
				   > 可以是极坐标系上的 radius, angle。
			参  数：<fX>;
				   <fY>;
			返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetCoord(float fX, float fY) = 0;

			/*@function
			******************************************************************
			功  能：对于 axis.type 为 'category' 类型的轴:
				   1. 如果 coord 值为 number，则表示 axis.data 的 index。
				   2. 如果 coord 值为 string，则表示 axis.data 中具体的值。
					  注意使用这种方式时，xAxis.data 不能写成 [number, number, ...]，
					  而只能写成 [string, string, ...]，否则不能被 markPoint / markLine 用『具体值』索引到。
			参  数：<略>;
			返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetCoord(const wchar_t* wzX, float fY) = 0;
			virtual void SetCoord(float fX, const wchar_t* wzY) = 0;
			virtual void SetCoord(const wchar_t* wzX, const wchar_t* wzY) = 0;

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
			功  能：标注值，可以不设。
			参  数：<nValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetValue(int nValue) = 0;
			virtual void GetValue(int* pnValue) const = 0;

			/*@function
			******************************************************************
			功  能：标注值，可以不设。
			参  数：<fValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetValue(float fValue) = 0;
			virtual void GetValue(float* pfValue) const = 0;

			/*@function
			******************************************************************
			功  能：标域数据的图形样式。
			参  数：<无>;
			返回值：<IScatterTypeMarkAreaDataItemStyle*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IScatterTypeMarkAreaDataItemStyle* GetItemStyle() = 0;

			/*@function
			******************************************************************
			功  能：标域数据的文本的样式设置。
			参  数：<无>;
			返回值：<IScatterTypeMarkAreaDataLabel*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IScatterTypeMarkAreaDataLabel * GetLabel() = 0;

			/*@function
			******************************************************************
			功  能：标域数据的高亮样式和标签设置。
			参  数：<无>;
			返回值：<IScatterTypeMarkAreaDataEmphasis*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IScatterTypeMarkAreaDataEmphasis* GetEmphasis() = 0;

			/*@function
			******************************************************************
			功  能：标域数据的淡出样式和标签设置。
			参  数：<无>;
			返回值：<IScatterTypeMarkAreaDataBlur*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IScatterTypeMarkAreaDataBlur* GetBlur() = 0;
		};
	}
}