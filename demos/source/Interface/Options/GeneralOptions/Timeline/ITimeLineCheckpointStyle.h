#pragma once
/***********************************************************************
 * Module:   ITimeLineCheckpointStyle.h
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

		class ITimeLineCheckpointStyle // Format 未定义
		{
		public:

			/************************************************
			 功  能：设置 标记的图形
			 参  数：<nValue>;
			 返回值：<无>;
			*************************************************/
			virtual void SetSymbol(ESymbol nValue) = 0;
			virtual ESymbol GetSymbol() const = 0;

			/************************************************
			 功  能：用图片设置 标记的图形
			 注  意：本接口参数只能是以下几种形式：
					 1. 图片链接：
					 'image://http://example.website/a/b.png'
					 2. dataURI：
					 'image://data:image/gif;base64,R0lGODlhEAAQAMQAAORHHOVSKudfOulrSOp3WOyDZu6QdvCchPGolfO0o/XBs/fNwfjZ0frl3/zy7////wAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACH5BAkAABAALAAAAAAQABAAAAVVICSOZGlCQAosJ6mu7fiyZeKqNKToQGDsM8hBADgUXoGAiqhSvp5QAnQKGIgUhwFUYLCVDFCrKUE1lBavAViFIDlTImbKC5Gm2hB0SlBCBMQiB0UjIQA7'
					 3. 矢量路径：（可以参考 https://www.w3.org/TR/SVG/paths.html#PathData）
					 'path://M30.9,53.2C16.8,53.2,5.3,41.7,5.3,27.6S16.8,2,30.9,2C45,2,56.4,13.5,56.4,27.6S45,53.2,30.9,53.2z M30.9,3.5C17.6,3.5,6.8,14.4,6.8,27.6c0,13.3,10.8,24.1,24.101,24.1C44.2,51.7,55,40.9,55,27.6C54.9,14.4,44.1,3.5,30.9,3.5z M36.9,35.8c0,0.601-0.4,1-0.9,1h-1.3c-0.5,0-0.9-0.399-0.9-1V19.5c0-0.6,0.4-1,0.9-1H36c0.5,0,0.9,0.4,0.9,1V35.8z M27.8,35.8 c0,0.601-0.4,1-0.9,1h-1.3c-0.5,0-0.9-0.399-0.9-1V19.5c0-0.6,0.4-1,0.9-1H27c0.5,0,0.9,0.4,0.9,1L27.8,35.8L27.8,35.8z'
			 参  数：<wzValue>图片的 URL 或 dataURI也可以是 Path;
			 返回值：<无>;
			*************************************************/
			virtual void SetSymbolImage(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetSymbolImage() const = 0;

			// 标记的大小，可以设置成诸如 10 这样单一的数字
			virtual void SetSymbolSize(int nSize) = 0;
			virtual int GetSymbolSize() const = 0;

			// 标记的大小，高度
			virtual void SetSymbolSize(int nHeight, int nWidth) = 0;
			virtual void GetSymbolSize(int& nHeight, int& nWidth) = 0;

			// 标记的旋转角度（而非弧度）,正值表示逆时针旋转。
			// 注意在 markLine 中当 symbol 为 'arrow' 时会忽略 symbolRotate 强制设置为切线的角度。
			virtual void SetSymbolRotate(int nRotate) = 0;
			virtual int GetSymbolRotate() const = 0;

			// 如果 symbol 是 path:// 的形式，是否在缩放时保持该图形的长宽比。
			virtual void SetSymbolKeepAspect(bool bValue) = 0;
			virtual bool GetSymbolKeepAspect() const = 0;

			/************************************************
			 功  能：标记相对于原本位置的偏移。
			 注  意：默认情况下，标记会居中置放在数据对应的位置
					 但是如果 symbol 是自定义的矢量路径或者图片，就有可能不希望 symbol 居中。
					 这时候可以使用该配置项配置 symbol 相对于原本居中的偏移，此处为绝对的像素值，
			 参  数：<nX> 水平偏移;
					 <nY> 垂直偏移;
					 <bIsPercentage> 默认为false，表示偏移值为像素，否则为百分比;
			 返回值：<无>;
			*************************************************/
			virtual void SetSymbolOffset(int nX, int nY, bool bIsPercentage) = 0;
			virtual void GetSymbolOffset(int* pnX, int* pnY, bool* pbIsPercentage) = 0;

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

			// 是否开启动画。
			virtual void SetAnimation(bool bValue) = 0;
			virtual bool GetAnimation() const = 0;

			// 初始动画的时长
			virtual void SetAnimationDuration(int nValue) = 0;
			virtual int  GetAnimationDuration() const = 0;

			// 初始动画的缓动效果。
			virtual void SetAnimationEasing(EAnimationEasing eValue) = 0;
			virtual EAnimationEasing GetAnimationEasing() const = 0;
		};
	}
}
