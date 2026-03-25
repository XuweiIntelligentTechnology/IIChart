#pragma once
/***********************************************************************
 * Module:   IBarTypeItemStyle.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  图形样式。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/IRich.h"
#include "Common/ICallback.h"
#include "Options/Common/IColor.h"
#include "Options/GeneralOptions/Series/Bar/IBarTypeDecal.h"


namespace IIChart
{
	namespace TimeLine
	{

		class ITimeLineItemStyle // Format 未定义
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

			/************************************************
			功  能：可以用 RGB、RGBA、16进制三种字符串形式设置字块边框颜色。
			参  数：<无> 字符串模板;
			返回值：<无>;
			*************************************************/
			virtual void SetBorderColor(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetBorderColor() const = 0;

			/************************************************
			功  能：以 RGBA 方式设置图形边框的颜色
			参  数：<无> 字符串模板;
			返回值：<无>;
			*************************************************/
			virtual void SetBorderColor(int nR, int nG, int nB, float nTransparent = 1) = 0;
			virtual void GetBorderColor(int* pnR, int* pnG, int* pnB, float* pnTransparent) = 0;

			/************************************************
			功  能：设置图形边框的颜色，此方式除可设置纯色外还可以设置为渐变色和纹理填充;
			参  数：<无> 字符串模板;
			返回值：<无>;
			*************************************************/
			virtual void SetBorderColor(IColor* pValue) = 0;

			// 文字块边框宽度;
			virtual void SetBorderWidth(int nValue) = 0;
			virtual int GetBorderWidth() const = 0;

			// 文字块边框描边类型。
			virtual void SetBorderType(EBorderType eValue) = 0;
			virtual EBorderType GetBorderType() const = 0;

			// number 数组，用以指定线条的 dash array;
			// 配合 borderDashOffset 可实现更灵活的虚线效果
			virtual int  SetBorderType(int* nValue, int nCount) = 0;
			virtual void GetBorderType(int* pnValue, int* pnCount) = 0;

			// 用于设置虚线的偏移量，可搭配 borderType 指定 dash array 实现灵活的虚线效果;
			virtual void SetBorderDashOffset(int nValue) = 0;
			virtual int GetBorderDashOffset() const = 0;

			// 用于指定线段末端的绘制方式,默认值为 'butt'
			virtual void SetBorderCap(EBorderCap eValue) = 0;
			virtual EBorderCap GetBorderCap() const = 0;

			// 用于设置2个长度不为0的相连部分（线段，圆弧，曲线）如何连接在一起的属性
			// （长度为0的变形部分，其指定的末端和控制点在同一位置，会被忽略）。
			virtual void SetBorderJoin(EBorderJoin eValue) = 0;
			virtual EBorderJoin GetBorderJoin() const = 0;

			// 用于设置斜接面限制比例。只有当 borderJoin 为 miter 时， borderMiterLimit 才有效。
			// 默认值为 10。负数、0、Infinity 和 NaN 均会被忽略。TODO:
			virtual void SetBorderMiterLimit(int nValue) = 0;
			virtual int  GetBorderMiterLimit() const = 0;

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

			// 文字块的背景阴影长度;
			virtual void SetShadowBlur(int nValue) = 0;
			virtual int GetShadowBlur() const = 0;

			// 文字块的背景阴影 X 偏移;
			virtual void SetShadowOffsetX(int nValue) = 0;
			virtual int GetShadowOffsetX() const = 0;

			// 文字块的背景阴影 Y 偏移;
			virtual void SetShadowOffsetY(int nValue) = 0;
			virtual int GetShadowOffsetY() const = 0;

			// 图形透明度。支持从 0 到 1 的数字，为 0 时不绘制该图形。
			virtual void SetOpacity(float nValue) = 0;
			virtual float  GetOpacity() const = 0;

		};
	}
}
