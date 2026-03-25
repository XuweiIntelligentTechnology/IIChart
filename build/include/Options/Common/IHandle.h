#pragma once
/***********************************************************************
 * Module:  ILabel.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: 拖拽手柄，适用于触屏的环境。
 *
 *	        
 ***********************************************************************/
#include "Common\IEnum.h"
#include "Options\Common\IBaseArrayElement.h"


namespace IIChart
{
	class IHandle
	{
	public:
		// 是否显示视觉引导线。
		virtual void SetShow(bool bValue) = 0;
		virtual bool GetShow() const = 0;

		// 手柄的图标。可以通过 'image://url' 设置为图片，其中 URL 为图片的链接，或者 dataURI。
		// URL 为图片链接例如：'image://http://example.website/a/b.png'
		// URL 为 dataURI 例如：
		//  'image://data:image/gif;base64,R0lGODlhEAAQAMQAAORHHOVSKudfOulrSOp3WOyDZu6QdvCchPGolfO0o/XBs/fNwfjZ0frl3/
		//  zy7////wAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACH5BAkAABAALAAAAAAQABAAAAVVICSOZGl
		//  CQAosJ6mu7fiyZeKqNKToQGDsM8hBADgUXoGAiqhSvp5QAnQKGIgUhwFUYLCVDFCrKUE1lBavAViFIDlTImbKC5Gm2hB0SlBCBMQiB0UjIQA7'
		// 可以通过 'path://' 将图标设置为任意的矢量路径。这种方式相比于使用图片的方式，不用担心因为缩放而产生锯齿或模糊，
		// 而且可以设置为任意颜色。路径图形会自适应调整为合适的大小。可以从 Adobe Illustrator 等工具编辑导出。
		virtual void SetIcon(const wchar_t* wzValue) = 0;
		virtual wchar_t* GetIcon() const = 0;

		// 手柄的尺寸，可以设置单值，如 45
		virtual void  SetSize(int nValue) = 0;
		virtual void  GetSize(int* pnValue) = 0;

		// 手柄的尺寸,设置为数组：[width, height]
		virtual void  SetSize(int nWidth, int nHeight) = 0;
		virtual void  GetSize(int* pnWidth, int* pnHeight) = 0;

		// 刻度标签与轴线之间的距离。
		virtual void SetMargin(int nValue) = 0;
		virtual int  GetMargin() const = 0;

		// 以16进制字符串形式设置手柄颜色。
		virtual void SetColor(const wchar_t* wzValue) = 0;
		virtual wchar_t* GetColor() const = 0;

		// 手柄颜色。
		virtual void SetColor(int nR, int nG, int nB, float nTransparent = 1) = 0;
		virtual void GetColor(int* pnR, int* pnG, int* pnB, float* pnTransparent) = 0;

		// 手柄拖拽时触发视图更新周期，单位毫秒，调大这个数值可以改善性能，但是降低体验。
		virtual void SetThrottle(int nValue) = 0;
		virtual int  GetThrottle() const = 0;

		// 以16进制字符串形式设置图形阴影。
		virtual void SetShadowColor(const wchar_t* wzValue) = 0;
		virtual wchar_t* GetShadowColor() const = 0;

		// 图形阴影颜色。
		virtual void SetShadowColor(int nR, int nG, int nB, float nTransparent = 1) = 0;
		virtual void GetShadowColor(int* pnR, int* pnG, int* pnB, float* pnTransparent) = 0;

		// 图形阴影长度;
		virtual void SetShadowBlur(int nValue) = 0;
		virtual int GetShadowBlur() const = 0;

		// 图形阴影 X 偏移;
		virtual void SetShadowOffsetX(int nValue) = 0;
		virtual int GetShadowOffsetX() const = 0;

		// 图形阴影 Y 偏移;
		virtual void SetShadowOffsetY(int nValue) = 0;
		virtual int GetShadowOffsetY() const = 0;
	};
}
	
	