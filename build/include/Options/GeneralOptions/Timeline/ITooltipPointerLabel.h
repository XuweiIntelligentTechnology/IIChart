#pragma once
/***********************************************************************
 * Module:  IAxisPointerLabel.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: 坐标轴刻度标签的相关设置。
 ***********************************************************************/
#include "Common\IEnum.h"

namespace IIChart
{
	namespace Axis
	{

		class IAxisPointerLabel // Format 未定义
		{
		public:
			// 是否显示文本标签。如果 tooltip.axisPointer.type 设置为 'cross' 则默认显示标签，否则默认不显示。
			virtual void SetShow(bool bShow) = 0;
			virtual bool GetShow() const = 0;

			// 文本标签中数值的小数点精度。默认根据当前轴的值自动判断。也可以指定如 2 表示保留两位小数。
			virtual void SetPrecision(int nValue) = 0;
			virtual int  GetPrecision() const = 0;

			// TODO Format:
			// 文本标签文字的格式化器。



			// label 距离轴的距离。
			virtual void SetMargin(int nValue) = 0;
			virtual int  GetMargin() const = 0;

			// 以16进制字符串形式设置文字的颜色。
			virtual void SetColor(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetColor() const = 0;

			// 文字的颜色，默认取 axisLine.lineStyle.color。支持回调函数，格式如下
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

			// 文字本身的描边类型;
			virtual void SetTextBorderType(EBorderType eValue) = 0;
			virtual EBorderType GetTextBorderType() const = 0;

			// number 数组，用以指定线条的 dash array;
			// 配合 TextBorderDashOffset 可实现更灵活的虚线效果
			virtual int  SetTextBorderType(int* nValue, int nCount) = 0;
			virtual void GetTextBorderType(int* pnValue, int* pnCount) = 0;

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

			// axisPointer内边距，单位px，默认各方向内边距为5，接受数组分别设定上右下左边距。例如：
			// [3, 4, 5, 6]：表示 [上, 右, 下, 左] 的边距。
			// 4：表示 padding: [4, 4, 4, 4];
			// [3, 4]：表示 padding: [3, 4, 3, 4]。
			// 注意，文字块的 width 和 height 指定的是内容高宽，不包含 padding。
			virtual int  SetPadding(int* nValue, int nCount) = 0;
			virtual void GetPadding(int* pnValue, int* pnCount) = 0;

			// 以16进制字符串形式设置文本标签背景色;
			// 也可以直接使用图片
			virtual void SetBackgroundColor(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetBackgroundColor() const = 0;

			// 文本标签背景色。
			virtual void SetBackgroundColor(int nR, int nG, int nB, float nTransparent = 1) = 0;
			virtual void GetBackgroundColor(int* pnR, int* pnG, int* pnB, float* pnTransparent) = 0;

			// 以16进制字符串形式设置文本标签边框颜色。
			virtual void SetBorderColor(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetBorderColor() const = 0;

			// 文本标签边框颜色。
			virtual void SetBorderColor(int nR, int nG, int nB, float nTransparent = 1) = 0;
			virtual void GetBorderColor(int* pnR, int* pnG, int* pnB, float* pnTransparent) = 0;

			// 文本标签边框宽度;
			virtual void SetBorderWidth(int nValue) = 0;
			virtual int GetBorderWidth() const = 0;

			
			// 以16进制字符串形式设置文本标签的背景阴影颜色。
			virtual void SetShadowColor(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetShadowColor() const = 0;

			// 阴影颜色。
			virtual void SetShadowColor(int nR, int nG, int nB, float nTransparent = 1) = 0;
			virtual void GetShadowColor(int* pnR, int* pnG, int* pnB, float* pnTransparent) = 0;

			// 图形阴影的模糊大小。
			virtual void SetShadowBlur(int nValue) = 0;
			virtual int GetShadowBlur() const = 0;

			// 文本标签的背景阴影 X 偏移;
			virtual void SetShadowOffsetX(int nValue) = 0;
			virtual int GetShadowOffsetX() const = 0;

			// 文本标签的背景阴影 Y 偏移;
			virtual void SetShadowOffsetY(int nValue) = 0;
			virtual int GetShadowOffsetY() const = 0;
		
		};
	}

}
