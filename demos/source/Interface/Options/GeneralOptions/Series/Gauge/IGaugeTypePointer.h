#pragma once
/***********************************************************************
 * Module:  IGaugeTypePointer.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: 仪表盘指针。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/IHandle.h"
#include "Options/Common/IShadowStyle.h"
#include "Options/GeneralOptions/Series/Gauge/IGaugeTypeItemStyle.h"

namespace IIChart
{
	namespace Gauge
	{
		/*@class
		*************************************************************************
		* 类  名: IGaugeTypePointer
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 仪表盘指针。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IGaugeTypePointer
		{
		public:

			/*@function
			*******************************************************************
			功  能：是否显示指针。
			参  数：<bValue>;
			返回值：<无>;
			------------------------------------------------------------------
				作  者 : YangPenghui 2022 - 10 - 26;
			******************************************************************/
			virtual void SetShow(bool bValue) = 0;
			virtual bool GetShow() const = 0;

			/*@function
			*******************************************************************
			功  能：指针是否显示在标题和仪表盘详情上方。
			参  数：<bValue>;
			返回值：<无>;
			------------------------------------------------------------------
				作  者 : YangPenghui 2022 - 10 - 26;
			******************************************************************/
			virtual void SetShowAbove(bool bValue) = 0;
			virtual bool GetShowAbove() const = 0;

			/*@function
			*******************************************************************
			 功  能：设置 标记的图形
			 参  数：<nValue>;
			 返回值：<无>;
			------------------------------------------------------------------
				作  者 : YangPenghui 2022 - 10 - 26;
			******************************************************************/
			virtual void SetIcon(ESymbol nValue) = 0;
			virtual ESymbol GetIcon() const = 0;

			/*@function
			*******************************************************************
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
			------------------------------------------------------------------
				作  者 : YangPenghui 2022 - 10 - 26;
			******************************************************************/
			virtual void SetIconImage(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetIconImage() const = 0;

			/*@function
			*******************************************************************
			 功  能：相对于仪表盘中心的偏移位置，可以是绝对的数值，也可以是相对于仪表盘半径的百分比。
			 参  数：<nX> 水平方向的偏移;
			         <nY> 垂直方向的偏移;
			 返回值：<无>;
			------------------------------------------------------------------
				作  者 : YangPenghui 2022 - 10 - 26;
			******************************************************************/
			virtual void SetOffsetCenter(int nX, int nY, bool bIsPercentage) = 0;
			virtual void GetOffsetCenter(int* pnX, int* pnY, bool* pbIsPercentage) = 0;

			/*@function
			*******************************************************************
			 功  能：指针长度，可以是绝对数值，也可以是相对于半径的半分比。
			 参  数：<nValue> 水平方向的偏移;
					 <bIsPercentage> 为true时,nValue 则为百分比;
			 返回值：<无>;
			------------------------------------------------------------------
				作  者 : YangPenghui 2022 - 10 - 26;
			******************************************************************/
			virtual void SetLength(int nValue, bool bIsPercentage = false) = 0;
			virtual void GetLength(int* pnValue, bool* pbIsPercentage) = 0;

			/*@function
			*******************************************************************
			 功  能：指针宽度。
			 参  数：<nValue> 指针宽度;
			 返回值：<无>;
			------------------------------------------------------------------
				作  者 : YangPenghui 2022 - 10 - 26;
			******************************************************************/
			virtual void SetWidth(int nValue) = 0;
			virtual int  GetWidth() const = 0;

			/*@function
			*******************************************************************
			 功  能：如果图标是 path:// 的形式，是否在缩放时保持该图形的长宽比。
			 参  数：<bValue>;
			 返回值：<无>;
			------------------------------------------------------------------
				作  者 : YangPenghui 2022 - 10 - 26;
			******************************************************************/
			virtual void SetKeepAspect(bool bValue) = 0;
			virtual bool GetKeepAspect() const = 0;

			/*@function
			*******************************************************************
			 功  能：指针样式。
			 参  数：<无>;
			 返回值：<IGaugeTypeItemStyle*>;
			------------------------------------------------------------------
				作  者 : YangPenghui 2022 - 10 - 26;
			******************************************************************/
			virtual IGaugeTypeItemStyle* GetItemStyle() = 0;

		};
	}

	
}
