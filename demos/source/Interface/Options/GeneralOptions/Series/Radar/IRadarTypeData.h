#pragma once
/***********************************************************************
 * Module:  IRadarTypeData.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: 雷达图的数据是多变量（维度）的，如下示例：
	 data : [
		{
			value : [4300, 10000, 28000, 35000, 50000, 19000],
			name : '预算分配（Allocated Budget）'
		},
		{
			value : [5000, 14000, 28000, 31000, 42000, 21000],
			name : '实际开销（Actual Spending）'
		}
	]
	其中的value项数组是具体的数据，每个值跟 radar.indicator 一一对应。

***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/IBaseArrayElement.h"
#include "Options/Common/ILineStyle.h"
#include "Options/Common/ICompactTooltip.h"
#include "Options/GeneralOptions/Series/Radar/IRadarTypeDataLabel.h"
#include "Options/GeneralOptions/Series/Radar/IRadarTypeDataItemStyle.h"
#include "Options/GeneralOptions/Series/Radar/IRadarTypeDataAreaStyle.h"
#include "Options/GeneralOptions/Series/Radar/IRadarTypeDataSelect.h"		  
#include "Options/GeneralOptions/Series/Radar/IRadarTypeDataBlur.h"
#include "Options/GeneralOptions/Series/Radar/IRadarTypeDataEmphasis.h"

namespace IIChart
{
	namespace Radar
	{
		/*@class
		*************************************************************************
		* 类  名: IRadarTypeData
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 雷达图的数据
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IRadarTypeData : virtual public IBaseArrayElement
		{
		public:

			/*@function
			*******************************************************************
			功  能:  数据项名称
			参  数:  <wzValue>;
			返回值:  <无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetName(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetName() const = 0;

			/*@function
			*******************************************************************
			功  能:  单个数据项的整数类型数值
			注  意： 一个 ILineTypeData 对象中只会一个值；并且值为最后的 SetValue
					 调用设置的值;
			参  数:  <nValue>;
			返回值:  <无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetValue(int nValue) = 0;
			virtual void GetValue(int* pnValue) = 0;

			/*@function
			*******************************************************************
			功  能:  单个数据项的小数类型数值
			注  意： 一个 ILineTypeData 对象中只会一个值；并且值为最后的 SetValue
					 调用设置的值;
			参  数:  <nValue>;
			返回值:  <无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetValue(float fValue) = 0;
			virtual void GetValue(float* pfValue) = 0;

			/*@function
			*******************************************************************
			功  能:  该数据项的组 ID。组 ID 会被用于分类数据，并在全局过渡动画中决定如何进行合并和分裂动画。
			参  数:  <nValue>;
			返回值:  <无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetGroupId(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetGroupId() const = 0;

			/*@function
			*******************************************************************
			功  能:  设置 标记的图形
			参  数:  <eValue>;
			返回值:  <无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetSymbol(ESymbol eValue) = 0;
			virtual ESymbol GetSymbol() const = 0;

			/*@function
			*******************************************************************
			 功  能：用图片设置 标记的图形
			 注  意：本接口参数只能是以下几种形式：
					 1. 图片链接：
					 'image://http://example.website/a/b.png'
					 2. dataURI：
					 'image://data:image/gif;base64,R0lGODlhEAAQAMQAAORHHOVSKudfOulrS
							Op3WOyDZu6QdvCchPGolfO0o/XBs/fNwfjZ0frl3/zy7////wAAAAAAAAA
							AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACH5B
							AkAABAALAAAAAAQABAAAAVVICSOZGlCQAosJ6mu7fiyZeKqNKToQGDsM8hBA
							DgUXoGAiqhSvp5QAnQKGIgUhwFUYLCVDFCrKUE1lBavAViFIDlTImbKC5Gm2h
							B0SlBCBMQiB0UjIQA7'
					 3. 矢量路径：（可以参考 https://www.w3.org/TR/SVG/paths.html#PathData）
							'path://M30.9,53.2C16.8,53.2,5.3,41.7,5.3,27.6S16.8,2,30.9,2C45,
							2,56.4,13.5,56.4,27.6S45,53.2,30.9,53.2z M30.9,3.5C17.6,3.5,6.8,
							14.4,6.8,27.6c0,13.3,10.8,24.1,24.101,24.1C44.2,51.7,55,40.9,55,
							27.6C54.9,14.4,44.1,3.5,30.9,3.5z M36.9,35.8c0,0.601-0.4,1-0.9,
							1h-1.3c-0.5,0-0.9-0.399-0.9-1V19.5c0-0.6,0.4-1,0.9-1H36c0.5,0,0.9,
							0.4,0.9,1V35.8z M27.8,35.8 c0,0.601-0.4,1-0.9,1h-1.3c-0.5,
							0-0.9-0.399-0.9-1V19.5c0-0.6,0.4-1,0.9-1H27c0.5,0,0.9,0.4,0.9,1L27.8,
							35.8L27.8,35.8z'
			 参  数：<wzValue>图片的 URL 或 dataURI也可以是 Path;
			 返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetSymbolImage(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetSymbolImage() const = 0;

			/*@function
			*******************************************************************
			功  能:  标记的大小，可以设置成诸如 10 这样单一的数字
			参  数:  <nSize>;
			返回值:  <无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetSymbolSize(int nSize) = 0;
			virtual int GetSymbolSize() const = 0;

			/*@function
			*******************************************************************
			功  能: 标记的大小，高度
			参  数: <nSize>;
			返回值: <无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetSymbolSize(int nHeight, int nWidth) = 0;
			virtual void GetSymbolSize(int& nHeight, int& nWidth) = 0;

			/*@function
			*******************************************************************
			功  能: 标记的旋转角度（而非弧度）,正值表示逆时针旋转。
			注  意: 在 markLine 中当 symbol 为 'arrow' 时会忽略 symbolRotate 强制设置为切线的角度。
			参  数: <nSize>;
			返回值: <无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetSymbolRotate(int nRotate) = 0;
			virtual int GetSymbolRotate() const = 0;

			/*@function
			*******************************************************************
			功  能: 如果 symbol 是 path:// 的形式，是否在缩放时保持该图形的长宽比。
			参  数: <nSize>;
			返回值: <无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetSymbolKeepAspect(bool bValue) = 0;
			virtual bool GetSymbolKeepAspect() const = 0;

			/*@function
			*******************************************************************
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
			*******************************************************************
			功  能: 单个拐点文本的样式设置
			参  数: <无>;
			返回值: <IRadarTypeDataLabel*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IRadarTypeDataLabel* GetLabel() = 0;

			/*@function
			*******************************************************************
			功  能: 单个拐点标志的样式设置
			参  数: <无>;
			返回值: <IRadarTypeDataItemStyle*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IRadarTypeDataItemStyle* GetItemStyle() = 0;

			/*@function
			*******************************************************************
			功  能: 单项线条样式
			参  数: <无>;
			返回值: <ILineStyle*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ILineStyle* GetLineStyle() = 0;

			/*@function
			*******************************************************************
			功  能: 单项区域填充样式
			参  数: <无>;
			返回值: <IRadarTypeDataAreaStyle*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IRadarTypeDataAreaStyle* GetAreaStyle() = 0;

			/*@function
			*******************************************************************
			功  能: 单个数据项样式的高亮状态
			参  数: <无>;
			返回值: <IRadarTypeDataEmphasis*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IRadarTypeDataEmphasis* GetEmphasis() = 0;

			/*@function
			*******************************************************************
			功  能: 单个数据项样式的淡出状态
			参  数: <无>;
			返回值: <IRadarTypeDataBlur*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IRadarTypeDataBlur* GetBlur() = 0;

			/*@function
			*******************************************************************
			功  能: 单个数据项样式的选中状态
			参  数: <无>;
			返回值: <IRadarTypeDataSelect*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IRadarTypeDataSelect* GetSelect() = 0;

			/*@function
			*******************************************************************
			功  能: 本系列每个数据项中特定的 tooltip 设定。
			参  数: <无>;
			返回值: <ICompactTooltip*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ICompactTooltip* GetTooltip() = 0;
		};
	}

}