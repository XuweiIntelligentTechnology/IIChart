#pragma once
/***********************************************************************
 * Module:  IColor.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: 调色盘颜色。如果系列没有设置颜色，则会依次循环从该列表中取颜色作为系列颜色。 默认为：
 *          ['#5470c6', '#91cc75', '#fac858', '#ee6666', '#73c0de', '#3ba272', '#fc8452', '#9a60b4', '#ea7ccc']
 *	        支持的颜色格式：
 *			使用 RGB 表示颜色，比如 'rgb(128, 128, 128)'
 *			如果想要加上 alpha 通道表示不透明度，可以使用 RGBA，比如 'rgba(128, 128, 128, 0.5)'，也可以使用十六进制格式，比如 '#ccc'。
 *			支持渐变色或者纹理填充
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/IBaseArrayElement.h"

namespace IIChart
{
	
	class IColor : virtual public IBaseArrayElement
	{
	public:

		/************************************************
		功  能：字符串形式设置颜色支持 RGB 与 RGBA 格式,同时支持以16进制格式;
		注  意：RGB 表示颜色，比如 'rgb(128, 128, 128)'
		        RGBA 表示颜色，比如 'rgba(128, 128, 128, 0.5)'
				16进制 表示颜色，比如 '#ccc'
		参  数：<略>;
		返回值：<无>;
		************************************************/
		virtual void SetColor(const wchar_t* wzValue) = 0;
		virtual wchar_t* GetColor() const = 0;

		/************************************************
		功  能：设置颜色
		参  数：<略>;
		返回值：<无>;
		************************************************/
		virtual void SetColor(int nR, int nG, int nB, float nTransparent = 1) = 0;
		virtual void GetColor(int* pnR, int* pnG, int* pnB, float* pnTransparent) = 0;

		/************************************************
		功  能：渐变色类型
		注  意：线性渐变，前四个参数分别是 x, y, x2, y2, 
		        范围从 0 - 1，相当于在图形包围盒中的百分比，
				如果 globalCoord 为 `true`，则该四个值是绝对的像素位置

				径向渐变，前三个参数分别是圆心 x, y 和半径，取值同线性渐变
		参  数：<略>;
		返回值：<无>;
		************************************************/
		virtual void SetType(EColorType eValue) = 0;
		virtual EColorType GetType() const = 0;

		/************************************************
		功  能：径向渐变时，是圆心坐标 x;
		        线性渐变时，是起点坐标 x;
		注  意：取范围从 0 - 1，相当于在图形包围盒中的百分比，
				如果 globalCoord 为 `true`，则该值将自动转成int,并作为绝对的像素位置
		参  数：<略>;
		返回值：<无>;
		************************************************/
		virtual void SetX(float fValue) = 0;
		virtual float GetX() const = 0;

		/************************************************
		功  能：径向渐变时，是圆心坐标 y;
		        线性渐变时，是起点坐标 y;
		注  意：取范围从 0 - 1，相当于在图形包围盒中的百分比，
				如果 globalCoord 为 `true`，则该值将自动转成int,并作为绝对的像素位置
		参  数：<略>;
		返回值：<无>;
		************************************************/
		virtual void SetY(float fValue) = 0;
		virtual float GetY() const = 0;

		/************************************************
		功  能：线性渐变时，是终点坐标 x;
		注  意：取范围从 0 - 1，相当于在图形包围盒中的百分比，
				如果 globalCoord 为 `true`，则该值将自动转成int,并作为绝对的像素位置
		参  数：<略>;
		返回值：<无>;
		************************************************/
		virtual void SetX2(float fValue) = 0;
		virtual float GetX2() const = 0;

		/************************************************
		功  能：线性渐变时，是络点坐标 y;
		注  意：取范围从 0 - 1，相当于在图形包围盒中的百分比，
				如果 globalCoord 为 `true`，则该值将自动转成int,并作为绝对的像素位置
		参  数：<略>;
		返回值：<无>;
		************************************************/
		virtual void SetY2(float fValue) = 0;
		virtual float GetY2() const = 0;

		/************************************************
		功  能：径向渐变的圆心半径;
		注  意：取范围从 0 - 1，相当于在图形包围盒中的百分比，
		        如果 globalCoord 为 `true`，则该值将自动转成int,并作为绝对的像素位置
		参  数：<略>;
		返回值：<无>;
		************************************************/
		virtual void SetR(float fValue) = 0;
		virtual float GetR() const = 0;

		/************************************************
		功  能：清除所有添加的 colorStops;
		参  数：<无>;
		返回值：<无>;
		************************************************/
		virtual void ClearColorStops() = 0;

		/************************************************
		功  能：在原有的指示器后增加新的指示器。
		注  意：此接口可以方便实现动态图表;
		参  数：<pQueue> 新的数据,其元素可以是 IRadarIndicator* 类型的数据;
		返回值：<无>;
		*************************************************/
		virtual int  AddColorStops(float fOffset, const wchar_t* wzColor = nullptr) = 0;
		virtual int  AddColorStops(float fOffset, int nR, int nG, int nB, float nTransparent = 1) = 0;

		virtual void SetGlobal(bool bValue) = 0;
		virtual bool GetGlobal() const = 0;

		/************************************************
		功  能：设置纹理填充时的图片;
		注  意：支持为 HTMLImageElement, HTMLCanvasElement，不支持路径字符串
		参  数：<略>;
		返回值：<无>;
		************************************************/
		virtual void SetImage(const wchar_t* wzValue) = 0;
		virtual wchar_t* GetImage() const = 0;

		/************************************************
		功  能：纹理填充图片平铺类型;
		参  数：<略>;
		返回值：<无>;
		************************************************/
		virtual void SetRepeat(ERepeatType eValue) = 0;
		virtual ERepeatType GetRepeat() = 0;
	};
}