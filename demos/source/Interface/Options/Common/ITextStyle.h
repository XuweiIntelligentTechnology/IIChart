#pragma once
/***********************************************************************
 * Module:  ITextStyle.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: Declaration of the class ITextStyle
 ***********************************************************************/
#include "Common\IEnum.h"
#include "Options\Common\IRich.h"

namespace IIChart
{
	/*@class
	***********************************************************************
	* 类  名: ITextStyle
	* 修  改: 2022年7月1日 15:02:44
	* 功  能: 公用文本样式。
	-----------------------------------------------------------------------
	* 作  者:  YangPenghui 2022-10-26;
	************************************************************************/
	class ITextStyle
	{
	public:

		/*@function
		******************************************************************
		功  能：文字的颜色。
		注  意：为颜色值时，可以使用以下形式，
					1. 可以使用 RGB 表示，比如 'rgb(128, 128, 128)'\
					2. 如果想要加上 alpha 通道，可以使用 RGBA，比如 'rgba(128, 128, 128, 0.5)'
					3. 可以使用十六进制格式，比如 '#ccc'
					4. 可以使用 CSS3 预定义的颜色名称，如'red'，'SlateGray';
		参  数：<wzValue> 为 nullptr 或 L"" 时将清空此项的原有配置;
		返回值：<无>;
			------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void SetColor(const wchar_t* wzValue) = 0;
		virtual wchar_t* GetColor() const = 0;
		
		/*@function
		******************************************************************
		功  能：文字的颜色。
		参  数：<略>;
		返回值：<无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void SetColor(int nR, int nG, int nB, float nTransparent) = 0;
		virtual void GetColor(int* pnR, int* pnG, int* pnB, float* pnTransparent) = 0;

		/*@function
		******************************************************************
		功  能：设置主标题文本，此方式可以借助相应的 IRich 接口显示更加丰富的文本风格;
		参  数：<vctFromatterString> 文本内容，可以分多段，每段之间使用wzJoin进行拼接;
										每个字符串内部支持使用 \n 换行;
										每个字符串可以使用,例如：L"{RichStyleName|string value}"的形式,其中：
										RichStyleName: 为使用 ITitleTextStyle->IRich->CreateStyle()创建的Style的名称;
													可以用此 IRichStyle 来设置 string value 的样式;
										string value:  为具体的字符串文本内容;
				<wzJoin> 将各个FormatterString拼接起来的字符串，支持使用 L"\n" 换行;
							若其值为 nullptr 或空字符串，则每两个 FromatterString 之间直接拼接;
			    <wzFromatterString> 文本内容, 格式如上所述，当值为 nullptr 或 L"" 时，将清除当前配置;
		返回值：<无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void SetTextFormatter(const wchar_t* wzFromatterString) = 0;
		virtual int  SetTextFormatter(const std::vector<std::wstring>& vctFromatterString, const wchar_t* wzJoin) = 0;

		/*@function
		******************************************************************
		功  能：文字字体的风格;
		参  数：<eValue>;
		返回值：<无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void SetFontStyle(EFontStyle eValue) = 0;
		virtual EFontStyle GetFontStyle() const = 0;

		/*@function
		******************************************************************
		功  能：主标题文字字体的粗细;
		参  数：<eValue>;
		返回值：<无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void SetFontWeight(EFontWeight eValue) = 0;
		virtual EFontWeight GetFontWeight() const = 0;

		/*@function
		******************************************************************
		功  能：主标题文字字体的粗细;
		参  数：<nValue>;
		返回值：<无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void SetFontWeight(int nValue) = 0;
		virtual void GetFontWeight(int* pnValue) = 0;

		/*@function
		******************************************************************
		功  能：文字的字体系列;
		参  数：<wzValue> 可以是 'sans-serif','serif', 'monospace', 'Arial', 'Courier New',
							'Microsoft YaHei', ...;为 nullptr 或 L"" 时将清空此项的原有配置;
		返回值：<无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void SetFontFamily(const wchar_t* wzValue) = 0;
		virtual wchar_t* GetFontFamily() const = 0;

		/*@function
		******************************************************************
		功  能：文字的字体大小;
		参  数：<nValue> ;
		返回值：<无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void SetFontSize(int nValue) = 0;
		virtual int GetFontSize() const = 0;

		/*@function
		******************************************************************
		功  能：文字水平对齐方式，默认自动;
		注  意：rich 中如果没有设置 align，则会取父层级的 align;
		参  数：<eValue> ;
		返回值：<无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void SetAlign(EAlign eValue) = 0;
		virtual EAlign GetAlign() const = 0;

		/*@function
		******************************************************************
		功  能：文字垂直对齐方式，默认自动;
		注  意：rich 中如果没有设置 verticalAlign，则会取父层级的 verticalAlign;
		参  数：<eValue> ;
		返回值：<无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void SetVerticalAlign(EVerticalAlign eValue) = 0;
		virtual EVerticalAlign GetVerticalAlign() const = 0;

		/*@function
		******************************************************************
		功  能：行高;
		参  数：<nValue> 如果 IRich 中如果没有设置 lineHeight，则会取父层级的 lineHeight;;
		返回值：<无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void SetLineHeight(int nValue) = 0;
		virtual int GetLineHeight() const = 0;

		/*@function
		******************************************************************
		功  能：设置文字块背景色。
		参  数：<wzValue> 为 nullptr 或 L"" 时将不显示任何颜色，支持以下方式的颜色值：
						1. 可以使用 RGB 表示，比如 'rgb(128, 128, 128)'\
						2. 如果想要加上 alpha 通道，可以使用 RGBA，比如 'rgba(128, 128, 128, 0.5)'
						3. 可以使用十六进制格式，比如 '#ccc'
						4. 可以使用 CSS3 预定义的颜色名称，如'red'，'SlateGray';
		返回值：<wzValue> 为 nullptr 或 L"" 时将清空此项的原有配置;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void SetBackgroundColor(const wchar_t* wzValue) = 0;
		virtual wchar_t* GetBackgroundColor() const = 0;

		/*@function
		 ******************************************************************
		 功  能：以 RGBA 方式设置文字块背景色。
		 参  数：<略>;
		 返回值：<无>;
		 ------------------------------------------------------------------
		 作  者:  YangPenghui 2022-10-26;
		 ******************************************************************/
		virtual void SetBackgroundColor(int nR, int nG, int nB, float nTransparent) = 0;
		virtual void GetBackgroundColor(int* pnR, int* pnG, int* pnB, float* pnTransparent) = 0;

		/*@function
		 ******************************************************************
		 功  能：文字块背图片, 例如：'xxx/xxx.png';
		        使用 Width 或 Height 指定高宽，不指定认为是自适应;
		 参  数：<略>;
		 返回值：<无>;
		 ------------------------------------------------------------------
		 作  者:  YangPenghui 2022-10-26;
		 ******************************************************************/
		virtual void SetBackgroundPic(const wchar_t* wzValue) = 0;
		virtual wchar_t* GetBackgroundPic() const = 0;

		/*@function
		******************************************************************
		功  能：设置文字块边框颜色。
		参  数：<wzValue> 为 nullptr 或 L"" 时将不显示任何颜色，支持以下方式的颜色值：
						1. 可以使用 RGB 表示，比如 'rgb(128, 128, 128)'\
						2. 如果想要加上 alpha 通道，可以使用 RGBA，比如 'rgba(128, 128, 128, 0.5)'
						3. 可以使用十六进制格式，比如 '#ccc'
						4. 可以使用 CSS3 预定义的颜色名称，如'red'，'SlateGray';
		返回值：<无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void SetBorderColor(const wchar_t* wzValue) = 0;
		virtual wchar_t* GetBorderColor() const = 0;

		/*@function
		 ******************************************************************
		 功  能：以 RGBA 方式设置文字块边框颜色。
		 参  数：<略>;
		 返回值：<无>;
		 ------------------------------------------------------------------
		 作  者:  YangPenghui 2022-10-26;
		 ******************************************************************/
		virtual void SetBorderColor(int nR, int nG, int nB, float nTransparent) = 0;
		virtual void GetBorderColor(int* pnR, int* pnG, int* pnB, float* pnTransparent) = 0;

		/*@function
		 ******************************************************************
		 功  能：文字块边框宽度。
		 参  数：<nValue>;
		 返回值：<无>;
		 ------------------------------------------------------------------
		 作  者:  YangPenghui 2022-10-26;
		 ******************************************************************/
		virtual void SetBorderWidth(int nValue) = 0;
		virtual int GetBorderWidth() const = 0;

		/*@function
		******************************************************************
		功  能：文字块边框的描边类型;
		参  数：<eValue>;
		返回值：<无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void SetBorderType(EBorderType eValue) = 0;
		virtual EBorderType GetBorderType() const = 0;

		/*@function
		*****************************************************************
		 功  能：文字块边框描边类型, 用数组以指定线条的 dash array
				 配合 borderDashOffset 可实现更灵活的虚线效果;
		 参  数：<nValue> 线条虚线的 dash array 首地址;
				 <nCount> array 数组大小;
		 返回值：<无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual int  SetBorderType(int* pnValue, int nCount) = 0;
		virtual void GetBorderType(int* pnValue, int* pnCount) = 0;

		/*@function
		*****************************************************************
		 功  能：文字块边框描边类型, 用数组以指定线条的 dash array
				 配合 borderDashOffset 可实现更灵活的虚线效果
		 参  数：<wzValue> 以英文“,”隔开的数字序列;
		 返回值：<无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual int  SetBorderType(const wchar_t* wzValue) = 0;
		virtual void GetBorderType(wchar_t** pwzValue) = 0;

		/*@function
		*****************************************************************
		 功  能：文字块边框描边类型, 用数组以指定线条的 dash array
				 配合 borderDashOffset 可实现更灵活的虚线效果
		 参  数：<vctValue> 数字序列;
		 返回值：<无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual int  SetBorderType(const std::vector<int>& vctValue) = 0;

		/*@function
		 ******************************************************************
		 功  能：用于设置虚线的偏移量，可搭配 borderType 指定 dash array 实现灵活的虚线效果;
		 参  数：<nValue>;
		 返回值：<无>;
		 ------------------------------------------------------------------
		 作  者:  YangPenghui 2022-10-26;
		 ******************************************************************/
		virtual void SetBorderDashOffset(int nValue) = 0;
		virtual int GetBorderDashOffset() const = 0;

		/*@function
		******************************************************************
		功  能：统一设置文字块的四个角的圆角大小，单位px;
		参  数：<nValue>;
		返回值：<无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void  SetBorderRadius(int nValue) = 0;
		virtual void  GetBorderRadius(int* pnValue) = 0;

		/*@function
		 ******************************************************************
		 功  能：设置文字块的圆角大小，单位px;
		  参  数：<nValue1> 左上、右下的圆角;
				 <nValue2> 右上、左下的圆角;
		 返回值：<无>;
		 ------------------------------------------------------------------
		 作  者:  YangPenghui 2022-10-26;
		 ******************************************************************/
		virtual void  SetBorderRadius(int nValue1, int nValue2) = 0;
		virtual void  GetBorderRadius(int* pnValue1, int* pnValue2) = 0;

		/*@function
		 ******************************************************************
		 功  能：设置文字块的圆角大小，单位px;
		 参  数：<nValue1> 左上的圆角;
				 <nValue2> 右上的圆角;
				 <nValue3> 右下的圆角;
				 <nValue4> 左下的圆角;
		 返回值：<无>;
		 ------------------------------------------------------------------
		 作  者:  YangPenghui 2022-10-26;
		 ******************************************************************/
		virtual void SetBorderRadius(int nValue1, int nValue2, int nValue3, int nValue4) = 0;
		virtual void GetBorderRadius(int* pnValue1, int* pnValue2, int* pnValue3, int* pnValue4) = 0;

		/*@function
		******************************************************************
		功  能：文字块的内边距，单位 px;
		注  意: 默认各方向内边距为5，接受数组分别设定上右下左边距。
		参  数：<nValue> 边距值，例如 4：表示 padding: [4, 4, 4, 4];;
		返回值：<无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void  SetPadding(int nValue) = 0;
		virtual void  GetPadding(int* pnValue) = 0;

		/*@function
		******************************************************************
		功  能：文字块的内边距，单位 px;
		注  意: 默认各方向内边距为5，接受数组分别设定上右下左边距。
		参  数：<nValue1> 边距值1
			   <nValue2> 边距值2
			   例如 [3, 4]：表示 padding: [3, 4, 3, 4];
		返回值：<无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void  SetPadding(int nValue1, int nValue2) = 0;
		virtual void  GetPadding(int* pnValue1, int* pnValue2) = 0;

		/*@function
		******************************************************************
		功  能：文字块的内边距，单位 px;
		注  意: 默认各方向内边距为5，接受数组分别设定上右下左边距。
		参  数：<nTop, nRight, nBottom, nLeft> 分别表示 [上, 右, 下, 左] 的边距
		返回值：<无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void SetPadding(int nTop, int nRight, int nBottom, int nLeft) = 0;
		virtual void GetPadding(int* pnTop, int* pnRight, int* pnBottom, int* pnLeft) = 0;

		/*@function
		******************************************************************
		功  能：文字块的颜色。
		参  数：<wzValue> 为 nullptr 或 L"" 时将不显示任何颜色，支持以下方式的颜色值：
						1. 可以使用 RGB 表示，比如 'rgb(128, 128, 128)'\
						2. 如果想要加上 alpha 通道，可以使用 RGBA，比如 'rgba(128, 128, 128, 0.5)'
						3. 可以使用十六进制格式，比如 '#ccc'
						4. 可以使用 CSS3 预定义的颜色名称，如'red'，'SlateGray';
		返回值：<无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void SetShadowColor(const wchar_t* wzValue) = 0;
		virtual wchar_t* GetShadowColor() const = 0;

		/*@function
		 ******************************************************************
		 功  能：以 RGBA 方式设置文字块的阴影颜色
		 参  数：<略>;
		 返回值：<无>;
		 ------------------------------------------------------------------
		 作  者:  YangPenghui 2022-10-26;
		 ******************************************************************/
		virtual void SetShadowColor(int nR, int nG, int nB, float nTransparent) = 0;
		virtual void GetShadowColor(int* pnR, int* pnG, int* pnB, float* pnTransparent) = 0;

		/*@function
		******************************************************************
		功  能：文字块的阴影的模糊大小;
		       该属性配合 shadowColor,shadowOffsetX, shadowOffsetY 一起设置图形的阴影效果。
		参  数：<nValue>;
		返回值：<无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void SetShadowBlur(int nValue) = 0;
		virtual int GetShadowBlur() const = 0;

		/*@function
		******************************************************************
		功  能：文字块的背景阴影 X 偏移;
		参  数：<nValue>;
		返回值：<无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void SetShadowOffsetX(int nValue) = 0;
		virtual int GetShadowOffsetX() const = 0;

		/*@function
		******************************************************************
		功  能：文字块的背景阴影 Y 偏移;
		参  数：<nValue>;
		返回值：<无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void SetShadowOffsetY(int nValue) = 0;
		virtual int GetShadowOffsetY() const = 0;

		/*@function
		******************************************************************
		功  能：文本显示宽度;
		参  数：<nValue> ;
		返回值：<无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void SetWidth(int nValue) = 0;
		virtual int GetWidth() const = 0;

		/*@function
		******************************************************************
		功  能：文本显示高度;
		参  数：<nValue> ;
		返回值：<无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void SetHeight(int nValue) = 0;
		virtual int GetHeight() const = 0;

		/*@function
		******************************************************************
		功  能：文字本身的描边颜色。
		注  意：为颜色值时，必须以'#'开头，
					1. 可以使用 RGB 表示，比如 'rgb(128, 128, 128)'\
					2. 如果想要加上 alpha 通道，可以使用 RGBA，比如 'rgba(128, 128, 128, 0.5)'
					3. 可以使用十六进制格式，比如 '#ccc'
					4. 可以使用 CSS3 预定义的颜色名称，如'red'，'SlateGray';
		参  数：<wzValue>  为 nullptr 或 L"" 时将清空此项的原有配置;
		返回值：<无>;
			------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void SetTextBorderColor(const wchar_t* wzValue) = 0;
		virtual wchar_t* GetTextBorderColor() const = 0;

		/*@function
		******************************************************************
		功  能：文字本身的描边颜色。
		参  数：<略>;
		返回值：<无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void SetTextBorderColor(int nR, int nG, int nB, float nTransparent) = 0;
		virtual void GetTextBorderColor(int* pnR, int* pnG, int* pnB, float* pnTransparent) = 0;

		/*@function
		******************************************************************
		功  能：文字本身的描边宽度;
		参  数：<nValue>;
		返回值：<无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void SetTextBorderWidth(int nValue) = 0;
		virtual int GetTextBorderWidth() const = 0;

		/*@function
		******************************************************************
		功  能：文字本身的描边类型;
		参  数：<eValue>;
		返回值：<无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void SetTextBorderType(EBorderType eValue) = 0;
		virtual EBorderType GetTextBorderType() const = 0;

		/*@function
		*****************************************************************
			功  能：文字本身描边类型, 用数组以指定线条的 dash array
					配合 borderDashOffset 可实现更灵活的虚线效果;
			参  数：<nValue> 线条虚线的 dash array 首地址;
					<nCount> array 数组大小;
			返回值：<无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual int  SetTextBorderType(int* nValue, int nCount) = 0;
		virtual void GetTextBorderType(int* pnValue, int* pnCount) = 0;

		/*@function
		*****************************************************************
		 功  能：文字本身描边类型, 用数组以指定线条的 dash array
				 配合 borderDashOffset 可实现更灵活的虚线效果
		 参  数：<wzValue> 以英文“,”隔开的数字序列;
		 返回值：<无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual int  SetTextBorderType(const wchar_t* wzValue) = 0;
		virtual void GetTextBorderType(wchar_t** pwzValue) = 0;

		/*@function
		*****************************************************************
		 功  能：文字本身描边类型, 用数组以指定线条的 dash array
				 配合 borderDashOffset 可实现更灵活的虚线效果
		 参  数：<vctValue> 数字序列;
		 返回值：<无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual int  SetTextBorderType(const std::vector<int>& vctValue) = 0;

		/*@function
		*****************************************************************
		 功  能：用于设置文字本身每两条虚线段之间的偏移量，可搭配 borderType 指
				 定 dash array 与 borderDashOffset实现灵活的虚线效果;
		 参  数：<nValue>;
		 返回值：<无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void SetTextBorderDashOffset(int nValue) = 0;
		virtual int GetTextBorderDashOffset() const = 0;

		/*@function
		******************************************************************
		功  能：文字本身的背景阴影颜色。
		注  意：为颜色值时，必须以'#'开头，
					1. 可以使用 RGB 表示，比如 'rgb(128, 128, 128)'\
					2. 如果想要加上 alpha 通道，可以使用 RGBA，比如 'rgba(128, 128, 128, 0.5)'
					3. 可以使用十六进制格式，比如 '#ccc'
					4. 可以使用 CSS3 预定义的颜色名称，如'red'，'SlateGray';
		参  数：<wzValue> 为 nullptr 或 L"" 时将清空此项的原有配置;
		返回值：<无>;
			------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void SetTextShadowColor(const wchar_t* wzValue) = 0;
		virtual wchar_t* GetTextShadowColor() const = 0;

		/*@function
		******************************************************************
		功  能：文字本身的背景阴影颜色。
		参  数：<略>;
		返回值：<无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void SetTextShadowColor(int nR, int nG, int nB, float nTransparent) = 0;
		virtual void GetTextShadowColor(int* pnR, int* pnG, int* pnB, float* pnTransparent) = 0;

		/*@function
		******************************************************************
		功  能：文字本身的背景阴影长度;
		参  数：<nValue>;
		返回值：<无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void SetTextShadowBlur(int nValue) = 0;
		virtual int GetTextShadowBlur() const = 0;

		/*@function
		******************************************************************
		功  能：文字本身的背景阴影 X 偏移;
		参  数：<nValue>;
		返回值：<无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void SetTextShadowOffsetX(int nValue) = 0;
		virtual int GetTextShadowOffsetX() const = 0;

		/*@function
		******************************************************************
		功  能：文字本身的背景阴影 Y 偏移;
		参  数：<nValue>;
		返回值：<无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void SetTextShadowOffsetY(int nValue) = 0;
		virtual int GetTextShadowOffsetY() const = 0;

		/*@function
		******************************************************************
		功  能：文字超出宽度是否截断或者换行。配置width时有效;
		参  数：<nValue>;
		返回值：<无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void SetOverflow(EOverflow eValue) = 0;
		virtual EOverflow GetOverflow() const = 0;

		/*@function
		******************************************************************
		功  能：在overflow配置为'truncate'的时候，可以通过该属性配置末尾显示的文本。如"...";
		参  数：<wzValue> 为 nullptr 或 L"" 时将清空此项的原有配置;
		返回值：<无>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual void SetEllipsis(const wchar_t* wzValue) = 0;
		virtual wchar_t* GetEllipsis() const = 0;

		/*@function
		******************************************************************
		功  能：在 rich 里面，可以自定义富文本样式。利用富文本样式，可以在标签中做出非常丰富的效果
		参  数：<无>;
		返回值：<IRich*>;
		------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		******************************************************************/
		virtual IRich* GetRich() = 0;

	};
}
