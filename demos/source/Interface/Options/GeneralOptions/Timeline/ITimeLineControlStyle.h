#pragma once
/***********************************************************************
 * Module:   ITimeLineControlStyle.h
 * Author:   杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose:  图形样式。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/IRich.h"
#include "Common/ICallback.h"
#include "Options/GeneralOptions/Series/Bar/IBarTypeDecal.h"


namespace IIChart
{
	namespace TimeLine
	{

		class ITimeLineControlStyle // Format 未定义
		{
		public:
			// 是否显示『控制按钮』。
			virtual void SetShow(bool bValue) = 0;
			virtual bool GetShow() const = 0;

			// 是否显示『播放按钮』。
			virtual void SetShowPlayBtn(bool bValue) = 0;
			virtual bool GetShowPlayBtn() const = 0;

			// 是否显示『后退按钮』。
			virtual void SetShowPrevBtn(bool bValue) = 0;
			virtual bool GetShowPrevBtn() const = 0;

			// 是否显示『前进按钮』。
			virtual void SetShowNextBtn(bool bValue) = 0;
			virtual bool GetShowNextBtn() const = 0;

			// 『控制按钮』的尺寸，单位为像素（px）;
			virtual void SetItemSize(int nValue) = 0;
			virtual int  GetItemSize() const = 0;

			// 『控制按钮』的间隔，单位为像素（px）。
			virtual void SetItemGap(int nValue) = 0;
			virtual int  GetItemGap() const = 0;

			/************************************************
			功  能：『控制按钮』的位置;
			注  意：当 timeline.orient 为 'horizontal'时，'left'、'right'有效。
			        当 timeline.orient 为 'vertical'时，'top'、'bottom'有效。
			参  数：<eValue> 字符串模板;
			返回值：<无>;
			*************************************************/
			virtual void SetPosition(ETimeLinePosition eValue) = 0;
			virtual ETimeLinePosition SetPosition() const = 0;

			/************************************************
			 功  能：『播放按钮』的『可播放状态』的图形。
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
			virtual void SetPlayIcon(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetPlayIcon() const = 0;

			/************************************************
			 功  能：『播放按钮』的『可停止状态』的图形。
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
			virtual void SetStopIcon(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetStopIcon() const = 0;

			/************************************************
			 功  能：『后退按钮』的图形
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
			virtual void SetPrevIcon(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetPrevIcon() const = 0;

			/************************************************
			 功  能：『前进按钮』的图形
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
			virtual void SetNextIcon(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetNextIcon() const = 0;

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
