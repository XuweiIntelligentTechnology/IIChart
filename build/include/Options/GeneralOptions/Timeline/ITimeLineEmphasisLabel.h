#pragma once
/***********************************************************************
 * Module:  ITimeLineEmphasisLabel.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: 轴的文本标签。
 ***********************************************************************/
#include "Common\IEnum.h"

namespace IIChart
{
	namespace TimeLine
	{

		class ITimeLineEmphasisLabel // Format 未定义
		{
		public:

			// 是否显示文本标签。如果 tooltip.axisPointer.type 设置为 'cross' 则默认显示标签，否则默认不显示。
			virtual void SetShow(bool bShow) = 0;
			virtual bool GetShow() const = 0;

			// label 的间隔。当指定为数值时，例如指定为 2，则每隔两个显示一个 label。
			virtual void SetInterval(int nValue) = 0;
			virtual int  GetInterval() const = 0;

			// label 的旋转角度。正值表示逆时针旋转。
			virtual void SetRotate(int nRotate) = 0;
			virtual int  GetRotate() const = 0;

			/************************************************
			 功  能：刻度标签的内容格式器的字符串模板。字符串模板与回调函数返回的字符串均支持用 \n 换行。
			 注  意：字符串模板的模板变量有：
					{a}：系列名。
					{b}：数据名。
					{c}：数据值。
					{@xxx}：数据中名为 'xxx' 的维度的值，如 {@product} 表示名为 'product' 的维度的值。
					{@[n]}：数据中维度 n 的值，如 {@[3]} 表示维度 3 的值，从 0 开始计数。示例：
					formatter: '{b}: {@score}'
			 参  数：<wzValue> 字符串模板;
			 返回值：<无>;
			*************************************************/
			virtual void SetFormatter(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetFormatter() const = 0;

			/************************************************
			 功  能：刻度标签的内容格式器的JavaScript回调函数;字符串模板与回调函数返回的字符串均支持用 \n 换行。
			 注  意：回调函数格式,例如：
					 formatter: function (value, index) {
						return value + 'kg';
					}
					更详细说明，可能参考：https://echarts.apache.org/zh/option.html#timeline.label
			 参  数：<wzValue> 字符串模板;
			 返回值：<无>;
			*************************************************/
			virtual void SetFormatterJSFun(const wchar_t* wzValue) = 0;

			// TODO: 刻度标签的内容格式器的C++回调;



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

			// 文字垂直对齐方式，默认自动。
			virtual void SetVerticalAlign(EVerticalAlign eValue) = 0;
			virtual EVerticalAlign GetVerticalAlign()const = 0;

			// 文字水平对齐方式，默认自动。
			virtual void SetAlign(EAlign eValue) = 0;
			virtual EAlign GetAlign()const = 0;

			// 行高。rich 中如果没有设置 lineHeight，则会取父层级的 lineHeight。
			virtual void SetLineHeight(int nValue) = 0;
			virtual int  GetLineHeight() const = 0;


			/************************************************
			 功  能：设置文字块背景图片;
			 注  意：直接使用图片，wzValue可以是
					 > 图片的 URL，
					 > 图片的 dataURI
			 参  数：<wzValue> 图片的URI;
			 返回值：<无>;
			 ************************************************/
			virtual void SetBackgroundImage(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetBackgroundImage() const = 0;

			/************************************************
			 功  能：以16进制字符串形式设置文字块背景色;如果设置为 'inherit'，则为视觉映射得到的颜色，如系列色。
			 注  意：为颜色值时，必须以'#'开头，
			 参  数：<wzValue> 背景色16进制行;
			 返回值：<无>;
			 ************************************************/
			virtual void SetBackgroundColor(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetBackgroundColor() const = 0;

			/************************************************
			 功  能：文字块背景色。如果设置为 'inherit'，则为视觉映射得到的颜色，如系列色。
			 参  数：<略>;
			 返回值：<无>;
			 ************************************************/
			virtual void SetBackgroundColor(int nR, int nG, int nB, float nTransparent = 1) = 0;
			virtual void GetBackgroundColor(int* pnR, int* pnG, int* pnB, float* pnTransparent) = 0;


			// 以16进制字符串形式设置文字块边框颜色。
			virtual void SetBorderColor(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetBorderColor() const = 0;

			// 文字块边框颜色。
			virtual void SetBorderColor(int nR, int nG, int nB, float nTransparent = 1) = 0;
			virtual void GetBorderColor(int* pnR, int* pnG, int* pnB, float* pnTransparent) = 0;

			// 文字块边框宽度;
			virtual void SetBorderWidth(int nValue) = 0;
			virtual int GetBorderWidth() const = 0;

			/************************************************
			 功  能：文字块边框描边类型。
			 参  数：<eValue>;
			 返回值：<无>;
			 ************************************************/
			virtual void SetBorderType(EBorderType eValue) = 0;
			virtual EBorderType GetBorderType() const = 0;

			/************************************************
			 功  能：number 数组，用以指定线条的 dash array;
					 配合 borderDashOffset 可实现更灵活的虚线效果
			 参  数：<eValue>;
			 返回值：<无>;
			 ************************************************/
			virtual int  SetBorderType(int* nValue, int nCount) = 0;
			virtual void GetBorderType(int* pnValue, int* pnCount) = 0;

			/************************************************
			 功  能：number 数组，用以指定线条的 dash array;
					 配合 borderDashOffset 可实现更灵活的虚线效果
			 参  数：<wzValue> 以英文“,”隔开的数字序列;
			 返回值：<无>;
			 ************************************************/
			virtual int  SetBorderType(const wchar_t* wzValue) = 0;
			virtual void GetBorderType(wchar_t** pwzValue) = 0;

			/************************************************
			 功  能：number 数组，用以指定线条的 dash array;
					 配合 borderDashOffset 可实现更灵活的虚线效果
			 参  数：<vctValue> 数字序列;
			 返回值：<无>;
			 ************************************************/
			virtual int  SetBorderType(const std::vector<int>& vctValue) = 0;

			// 用于设置虚线的偏移量，可搭配 borderType 指定 dash array 实现灵活的虚线效果;
			virtual void SetBorderDashOffset(int nValue) = 0;
			virtual int GetBorderDashOffset() const = 0;

			/************************************************
			 功  能：文字块的圆角;
					 左上，右上，左下，右下都用一样的圆角;
			 参  数：<vctValue> 数字序列;
			 返回值：<无>;
			 ************************************************/
			virtual void  SetBorderRadius(int nValue) = 0;
			virtual void  GetBorderRadius(int* pnValue) = 0;

			/************************************************
			 功  能：文字块的圆角;
			 参  数：<nValue1> 左上、右下的圆角;
					 <nValue2> 右上、左下的圆角;
			 返回值：<无>;
			 ************************************************/
			virtual void  SetBorderRadius(int nValue1, int nValue2) = 0;
			virtual void  GetBorderRadius(int* pnValue1, int* pnValue2) = 0;

			/************************************************
			 功  能：文字块的圆角;
			 参  数：<nValue1> 左上的圆角;
					 <nValue2> 右上的圆角;
					 <nValue3> 右下的圆角;
					 <nValue4> 左下的圆角;
			 返回值：<无>;
			 ************************************************/
			virtual void SetBorderRadius(int nValue1, int nValue2, int nValue3, int nValue4) = 0;
			virtual void GetBorderRadius(int* pnValue1, int* pnValue2, int* pnValue3, int* pnValue4) = 0;

			// 文字块的内边距。例如：
			// 4：表示 padding: [4, 4, 4, 4];
			// 注意，文字块的 width 和 height 指定的是内容高宽，不包含 padding。
			virtual void  SetPadding(int nValue) = 0;
			virtual void  GetPadding(int* pnValue) = 0;

			// 文字块的内边距。例如：
			// [3, 4]：表示 padding: [3, 4, 3, 4]。
			// 注意，文字块的 width 和 height 指定的是内容高宽，不包含 padding。
			virtual void  SetPadding(int nValue1, int nValue2) = 0;
			virtual void  GetPadding(int* pnValue1, int* pnValue2) = 0;

			// 文字块的内边距。例如：
			// [3, 4, 5, 6]：表示 [上, 右, 下, 左] 的边距。
			// 注意，文字块的 width 和 height 指定的是内容高宽，不包含 padding。
			virtual void SetPadding(int nTop, int nRight, int nBottom, int nLeft) = 0;
			virtual void GetPadding(int* pnTop, int* pnRight, int* pnBottom, int* pnLeft) = 0;

			
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

			// 在 rich 里面，可以自定义富文本样式。利用富文本样式，可以在标签中做出非常丰富的效果
			virtual IRich* GetRich() = 0;

		};
	}

}
