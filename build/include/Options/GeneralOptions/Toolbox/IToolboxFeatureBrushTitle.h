#pragma once
/***********************************************************************
 * Module:  IToolboxFeatureBrushTitle.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: 标题文本。
 ***********************************************************************/

namespace IIChart
{
	namespace Toolbox
	{
		
		class IToolboxFeatureBrushTitle // OK
		{
		public:

			/************************************************
			功  能：矩形选择按钮的标题文本。
			参  数：<wzValue> 标题文;
			返回值：<无>;
			*************************************************/
			virtual void SetRect(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetRect() const = 0;

			/************************************************
			功  能：圈选按钮的标题文本。
			参  数：<wzValue> 标题文;
			返回值：<无>;
			*************************************************/
			virtual void SetPolygon(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetPolygon() const = 0;

			/************************************************
			功  能：横向选择按钮的标题文本。
			参  数：<wzValue> 标题文;
			返回值：<无>;
			*************************************************/
			virtual void SetLineX(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetLineX() const = 0;

			/************************************************
			功  能：纵向选择按钮的标题文本。
			参  数：<wzValue> 标题文;
			返回值：<无>;
			*************************************************/
			virtual void SetLineY(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetLineY() const = 0;

			/************************************************
			功  能：保持选择按钮的标题文本。
			参  数：<wzValue> 标题文;
			返回值：<无>;
			*************************************************/
			virtual void SetKeep(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetKeep() const = 0;

			/************************************************
			功  能：清除选择按钮的标题文本。
			参  数：<wzValue> 标题文;
			返回值：<无>;
			*************************************************/
			virtual void SetClear(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetClear() const = 0;


		};
	}
}