#pragma once
/***********************************************************************
 * Module:  ITimeLineProgressLineStyle.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: 轴线的样式设置。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/IColor.h"

namespace IIChart
{
	namespace TimeLine
	{

		class ITimeLineProgressLineStyle // OK
		{
		public:
			
			/************************************************
			功  能：创建颜色对象;
			注  意：此功能除了可以设置纯色外，还可以设置渐变色和纹理填充;
			参  数：<无> 字符串模板;
			返回值：<无>;
			*************************************************/
			virtual IColor* CreateColor() = 0;

			/************************************************
			功  能：可以用 RGB、RGBA、16进制三种字符串形式设置颜色。
			参  数：<无> 字符串模板;
			返回值：<无>;
			*************************************************/
			virtual void SetColor(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetColor() const = 0;

			/************************************************
			功  能：以 RGBA 方式设置刻度标签文字的颜色，默认取 axisLine.lineStyle.color。
			参  数：<略>;
			返回值：<无>;
			*************************************************/
			virtual void SetColor(int nR, int nG, int nB, float nTransparent = 1) = 0;
			virtual void GetColor(int* pnR, int* pnG, int* pnB, float* pnTransparent) = 0;

			/************************************************
			功  能：设置图形的颜色，此方式除可设置纯色外还可以设置为渐变色和纹理填充;
			参  数：<无> 字符串模板;
			返回值：<无>;
			*************************************************/
			virtual void SetColor(IColor* pValue) = 0;

			// 线宽。
			virtual void SetWidth(int nValue) = 0;
			virtual int  GetWidth() = 0;

			// 线的类型。
			virtual void SetType(ELineStyle eValue) = 0;
			virtual ELineStyle GetType() const = 0;

			// number 数组，用以指定线条的 dash array，
		    // 配合 dashOffset 可实现更灵活的虚线效果。
			virtual int  SetType(int* nValue, int nCount) = 0;
			virtual void GetType(int* pnValue, int* pnCount) = 0;

			// 用于设置虚线的偏移量，可搭配 type 指定 dash array 实现灵活的虚线效果;
			virtual void SetDashOffset(int nValue) = 0;
			virtual int  GetDashOffset() const = 0;

			// 线的类型。默认值为 'ECS_Butt'。
			virtual void SetCap(ECapStyle eValue) = 0;
			virtual ECapStyle GetCap() const = 0;

			// 用于设置2个长度不为0的相连部分（线段，圆弧，曲线）如何连接在一起的属性（长度为0的变形部分，
			// 其指定的末端和控制点在同一位置，会被忽略）。
			virtual void SetJoin(EJoinStyle eValue) = 0;
			virtual EJoinStyle GetJoin() const = 0;

			// 用于设置斜接面限制比例。只有当 join 为 miter 时， miterLimit 才有效。
			// 默认值为 10。负数、0、Infinity 和 NaN 均会被忽略。
			virtual void SetMiterLimit(int nValue) = 0;
			virtual int  GetMiterLimit() const = 0;

			/************************************************
			功  能：可以用 RGB、RGBA、16进制三种字符串形式设置阴影颜色。
			参  数：<无> 字符串模板;
			返回值：<无>;
			*************************************************/
			virtual void SetShadowColor(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetShadowColor() const = 0;

			/************************************************
			功  能：以 RGBA 方式设置阴影的颜色，默认取 axisLine.lineStyle.color。
			参  数：<略>;
			返回值：<无>;
			*************************************************/
			virtual void SetShadowColor(int nR, int nG, int nB, float nTransparent = 1) = 0;
			virtual void GetShadowColor(int* pnR, int* pnG, int* pnB, float* pnTransparent) = 0;

			/************************************************
			功  能：设置图形的阴影颜色，此方式除可设置纯色外还可以设置为渐变色和纹理填充;
			参  数：<无> 字符串模板;
			返回值：<无>;
			*************************************************/
			virtual void SetShadowColor(IColor* pValue) = 0;

			// 图形阴影的模糊大小。该属性配合 shadowColor,shadowOffsetX, shadowOffsetY 一起设置图形的阴影效果。
			virtual void SetShadowBlur(int nValue) = 0;
			virtual int GetShadowBlur() const = 0;

			// 阴影水平方向上的偏移距离。
			virtual void SetShadowOffsetX(int nValue) = 0;
			virtual int GetShadowOffsetX() const = 0;

			// 阴影垂直方向上的偏移距离。
			virtual void SetShadowOffsetY(int nValue) = 0;
			virtual int GetShadowOffsetY() const = 0;

			// 图形透明度。支持从 0 到 1 的数字，为 0 时不绘制该图形。
			virtual void SetOpacity(float nValue) = 0;
			virtual float GetOpacity() const = 0;

		};
	}
}