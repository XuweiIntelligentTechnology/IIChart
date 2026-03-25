#pragma once
/***********************************************************************
 * Module:  IVisualMapContinuousTextStyle.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: 坐标轴名称的文字样式。
 ***********************************************************************/
#include "Common/IEnum.h"

namespace IIChart
{
	namespace DataZoom
	{

		class IDataZoomSliderTextStyle // OK
		{
		public:
			// 以16进制字符串形式设置文字的颜色;;
			virtual void SetColor(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetColor() const = 0;

			// 文字的颜色;
			virtual void SetColor(int nR, int nG, int nB, float nTransparent = 1) = 0;
			virtual void GetColor(int* pnR, int* pnG, int* pnB, float* pnTransparent) = 0;

			// 文字字体的风格;
			virtual void SetFontStyle(EFontStyle eValue) = 0;
			virtual EFontStyle GetFontStyle() const = 0;

			// 文字字体的粗细;
			virtual void SetFontWeight(EFontWeight eValue) = 0;
			virtual EFontWeight GetFontWeight() const = 0;

			virtual void SetFontWeight(int nValue) = 0;
			virtual void GetFontWeight(int* pnValue) = 0;

			// 文字的字体系列;
			// 可以是 'sans-serif','serif', 'monospace', 'Arial', 'Courier New', 'Microsoft YaHei', ...
			virtual void SetFontFamily(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetFontFamily() const = 0;

			// 文字的字体大小;
			virtual void SetFontSize(int nValue) = 0;
			virtual int GetFontSize() const = 0;
			
			// 行高;
			// rich 中如果没有设置 lineHeight，则会取父层级的 lineHeight;
			virtual void SetLineHeight(int nValue) = 0;
			virtual int GetLineHeight() const = 0;

			// 文本显示宽度;
			virtual void SetWidth(int nValue) = 0;
			virtual int GetWidth() const = 0;

			// 文本显示高度;
			virtual void SetHeight(int nValue) = 0;
			virtual int GetHeight() const = 0;

			// 以16进制字符串形式设置文字本身的描边颜色;
			virtual void SetTextBorderColor(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetTextBorderColor() const = 0;

			// 文字本身的描边颜色;
			virtual void SetTextBorderColor(int nR, int nG, int nB, float nTransparent = 1) = 0;
			virtual void GetTextBorderColor(int* pnR, int* pnG, int* pnB, float* pnTransparent) = 0;

			// 文字本身的描边宽度;
			virtual void SetTextBorderWidth(int nValue) = 0;
			virtual int GetTextBorderWidth() const = 0;

			/************************************************
			 功  能：文字本身描边类型。
			 参  数：<eValue>;
			 返回值：<无>;
			 ************************************************/
			virtual void SetTextBorderType(EBorderType eValue) = 0;
			virtual EBorderType GetTextBorderType() const = 0;

			/************************************************
			 功  能：文字本身描边类型。
					 配合 borderDashOffset 可实现更灵活的虚线效果
			 参  数：<eValue>;
			 返回值：<无>;
			 ************************************************/
			virtual int  SetTextBorderType(int* nValue, int nCount) = 0;
			virtual void GetTextBorderType(int* pnValue, int* pnCount) = 0;

			/************************************************
			 功  能：文字本身描边类型。
					 配合 borderDashOffset 可实现更灵活的虚线效果
			 参  数：<wzValue> 以英文“,”隔开的数字序列;
			 返回值：<无>;
			 ************************************************/
			virtual int  SetTextBorderType(const wchar_t* wzValue) = 0;
			virtual void GetTextBorderType(wchar_t** pwzValue) = 0;

			/************************************************
			 功  能：文字本身描边类型。
					 配合 borderDashOffset 可实现更灵活的虚线效果
			 参  数：<vctValue> 数字序列;
			 返回值：<无>;
			 ************************************************/
			virtual int  SetTextBorderType(const std::vector<int>& vctValue) = 0;

			// 用于设置文字本身虚线的偏移量，可搭配 borderType 指定 dash array 实现灵活的虚线效果;
			virtual void SetTextBorderDashOffset(int nValue) = 0;
			virtual int GetTextBorderDashOffset() const = 0;

			// 以16进制字符串形式设置文字本身的背景阴影颜色。
			virtual void SetTextShadowColor(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetTextShadowColor() const = 0;

			// 文字本身的背景阴影颜色。
			virtual void SetTextShadowColor(int nR, int nG, int nB, float nTransparent = 1) = 0;
			virtual void GetTextShadowColor(int* pnR, int* pnG, int* pnB, float* pnTransparent) = 0;

			// 文字本身的背景阴影长度;
			virtual void SetTextShadowBlur(int nValue) = 0;
			virtual int GetTextShadowBlur() const = 0;

			// 文字本身的背景阴影 X 偏移;
			virtual void SetTextShadowOffsetX(int nValue) = 0;
			virtual int GetTextShadowOffsetX() const = 0;

			// 文字本身的背景阴影 Y 偏移;
			virtual void SetTextShadowOffsetY(int nValue) = 0;
			virtual int GetTextShadowOffsetY() const = 0;

			// 文字超出宽度是否截断或者换行。配置width时有效;
			virtual void SetOverflow(EOverflow eValue) = 0;
			virtual EOverflow GetOverflow() const = 0;

			// 在overflow配置为'truncate'的时候，可以通过该属性配置末尾显示的文本。如"...";
			virtual void SetEllipsis(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetEllipsis() const = 0;

		};
	}
}