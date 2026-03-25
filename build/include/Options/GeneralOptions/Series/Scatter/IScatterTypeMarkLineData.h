#pragma once
/***********************************************************************
 * Module:  IScatterTypeMarkLineData.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: 标线的数据数组。
 * 
 *     每个数组项可以是一个两个值的数组，分别表示线的起点和终点，
 *     每一项是一个对象，有下面几种方式指定起点或终点的位置。  
 *     1. 通过 x, y 属性指定相对容器的屏幕坐标，单位像素，支持百分比。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/IBaseArrayElement.h"
#include "Options/GeneralOptions/Series/Scatter/IScatterTypeMarkLineDataLineStyle.h"
#include "Options/GeneralOptions/Series/Scatter/IScatterTypeMarkLineDataLabel.h"
#include "Options/GeneralOptions/Series/Scatter/IScatterTypeMarkLineDataEmphasis.h"
#include "Options/GeneralOptions/Series/Scatter/IScatterTypeMarkLineDataBlur.h"


namespace IIChart
{
	namespace Scatter
	{
		/*@class
		*************************************************************************
		* 类  名: IScatterTypeMarkLineData
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 图表标线，常用于标记图表中某个范围的数据，例如标出某段时间投放了广告。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IScatterTypeMarkLineData : virtual public IBaseArrayElement
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
			参  数：<无>;
			返回值：<wchar_t*>;
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
			功  能： x 值为给定值的标记线，仅对数据值是一项的设置有效。
					例： data: [{
						name: 'X 轴值为 100 的竖直线',
						xAxis: 100
					}]
			参  数：<略>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetXAxis(int nValue) = 0;
			virtual void GetXAxis(int* pnValue) const = 0;
			virtual void SetXAxis(float nValue) = 0;
			virtual void GetXAxis(float* pnValue) const = 0;


			/*@function
			******************************************************************
			功  能： 对于 'time' 类型的 xAxis，可以设置为：
					 例： data: [{
							name: 'X 轴值为 "2020-01-01" 的竖直线',
							xAxis: '2020-01-01'
						}]
			参  数：<略>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetXAxis(const wchar_t* wzValue) = 0;
			virtual void GetXAxis(wchar_t** wzValue) const = 0;

			/*@function
			******************************************************************
			功  能： y 值为给定值的标记线，仅对数据值是一项的设置有效。
					 例： data: [{
							name: 'Y 轴值为 100 的竖直线',
							yAxis: 100
						}]
			参  数：<略>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetYAxis(int nValue) = 0;
			virtual void GetYAxis(int* pnValue) const = 0;
			virtual void SetYAxis(float nValue) = 0;
			virtual void GetYAxis(float* pnValue) const = 0;

			/*@function
			******************************************************************
			功  能： 对于 'time' 类型的 yAxis，可以设置为：
					 例： data: [{
							name: 'Y 轴值为 "2020-01-01" 的竖直线',
							yAxis: '2020-01-01'
						}]
			参  数：<略>;
			返回值：<无>;
			------------------------------------------------------------------
				作  者 : YangPenghui 2022 - 10 - 26;
			******************************************************************/
			virtual void SetYAxis(const wchar_t* wzValue) = 0;
			virtual void GetYAxis(wchar_t** wzValue) const = 0;


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
			功  能：起点标记的图形
			参  数：<eValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetSymbol(ESymbol eValue) = 0;
			virtual ESymbol GetSymbol() const = 0;

			/*@function
			******************************************************************
			功  能：用图片设置 标记的图形
			注  意：本接口参数只能是以下几种形式：
					 1. 图片链接：
					 'image://http://example.website/a/b.png'
					 2. dataURI：
					 'image://data:image/gif;base64,R0lGODlhEAAQAMQAAORHHOVSKudfOulr
					 SOp3WOyDZu6QdvCchPGolfO0o/XBs/fNwfjZ0frl3/zy7////wAAAAAAAAAAAAAA
					 AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACH5BAkAABAALAAAA
					 AAQABAAAAVVICSOZGlCQAosJ6mu7fiyZeKqNKToQGDsM8hBADgUXoGAiqhSvp5QAn
					 QKGIgUhwFUYLCVDFCrKUE1lBavAViFIDlTImbKC5Gm2hB0SlBCBMQiB0UjIQA7'
					 3. 矢量路径：（可以参考 https://www.w3.org/TR/SVG/paths.html#PathData）
					 'path://M30.9,53.2C16.8,53.2,5.3,41.7,5.3,27.6S16.8,2,30.9,2C45,2,56.4,
					 13.5,56.4,27.6S45,53.2,30.9,53.2z M30.9,3.5C17.6,3.5,6.8,14.4,6.8,27.6c0,
					 13.3,10.8,24.1,24.101,24.1C44.2,51.7,55,40.9,55,27.6C54.9,14.4,44.1,3.5,
					 30.9,3.5z M36.9,35.8c0,0.601-0.4,1-0.9,1h-1.3c-0.5,0-0.9-0.399-0.9-1V19.5c0-0.6,
					 0.4-1,0.9-1H36c0.5,0,0.9,0.4,0.9,1V35.8z M27.8,35.8 c0,0.601-0.4,1-0.9,1h-1.3c-0.5,
					 0-0.9-0.399-0.9-1V19.5c0-0.6,0.4-1,0.9-1H27c0.5,0,0.9,0.4,0.9,1L27.8,35.8L27.8,35.8z'
			参  数：<wzValue>图片的 URL 或 dataURI也可以是 Path;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetSymbolImage(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetSymbolImage() const = 0;

			/*@function
			******************************************************************
			功  能：标记的大小，可以设置成诸如 10 这样单一的数字
			参  数：<nValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetSymbolSize(int nValue) = 0;
			virtual int  GetSymbolSize() const = 0;

			/*@function
			******************************************************************
			功  能：标记的大小
			参  数：<nWidth>;
				   <nHeight>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetSymbolSize(int nWidth, int nHeight) = 0;
			virtual void GetSymbolSize(int* pnWidth, int* pnHeight) = 0;

			/*@function
			******************************************************************
			功  能：标记的旋转角度（而非弧度）。正值表示逆时针旋转。
			注  意: 在 markLine 中当 symbol 为 'arrow' 时会忽略symbolRotate 强制设置为切线的角度。
			参  数：<nValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetSymbolRotate(int nValue) = 0;
			virtual int GetSymbolRotate() const = 0;

			/*@function
			******************************************************************
			功  能：如果 symbol 是 path:// 的形式，是否在缩放时保持该图形的长宽比。
			参  数：<nValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetSymbolKeepAspect(bool bValue) = 0;
			virtual bool GetSymbolKeepAspect() const = 0;

			/*@function
			******************************************************************
			 功  能：标记相对于原本位置的偏移。
			 注  意：默认情况下，标记会居中置放在数据对应的位置
					 但是如果 symbol 是自定义的矢量路径或者图片，就有可能不希望 symbol 居中。
					 这时候可以使用该配置项配置 symbol 相对于原本居中的偏移，此处为绝对的像素值，
			 参  数：<nX> 水平偏移;
					 <nY> 垂直偏移;
					 <bIsPercentage> 默认为false，表示偏移值为像素，否则为百分比;
			 返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetSymbolOffset(int nX, int nY, bool bIsPercentage) = 0;
			virtual void GetSymbolOffset(int* pnX, int* pnY, bool* pbIsPercentage) = 0;

			/*@function
			******************************************************************
			功  能：该数据项线的样式，起点和终点项的 lineStyle会合并到一起。
			参  数：<nValue>;
			返回值：<IScatterTypeMarkLineDataLineStyle*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IScatterTypeMarkLineDataLineStyle* GetLineStyle() = 0;

			/*@function
			******************************************************************
			功  能：该数据项标签的样式，起点和终点项的 label会合并到一起。
			参  数：<nValue>;
			返回值：<IScatterTypeMarkLineDataLabel*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IScatterTypeMarkLineDataLabel* GetLabel() = 0;
			
			/*@function
			******************************************************************
			功  能：该数据项高亮时的样式
			参  数：<nValue>;
			返回值：<IScatterTypeMarkLineDataEmphasis*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IScatterTypeMarkLineDataEmphasis* GetEmphasis() = 0;

			/*@function
			******************************************************************
			功  能：该数据项淡出时的样式
			参  数：<nValue>;
			返回值：<IScatterTypeMarkLineDataBlur*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IScatterTypeMarkLineDataBlur* GetBlur() = 0;
		};
	}
}