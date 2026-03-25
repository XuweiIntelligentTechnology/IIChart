#pragma once
#include "Common/IEnum.h"
#include "Options/Common/IBaseArrayElement.h"

namespace IIChart
{
	
	/*************************************************************************
	*  名    称：可变长度的队列
	*  用    途：主要用于数据可以不是一种类型的情况。
	/*************************************************************************/
	class IQueue
	{

	public:

		// 释放所有资源，同时也会释放每一个IBaseArrayElement占用的资源，包括对象本身,;
		virtual void Release() = 0;


	public:

		// 取当前元素个数;
		virtual int GetElementCount() const = 0;


		// 在尾部增加 int 类型元素;
		virtual void PushBack(int nValue) = 0;

		// 在尾部增加 float 类型元素;
		virtual void PushBack(float fValue) = 0;

		// 在尾部增加 wchar_t* 类型元素;
		virtual void PushBack(const wchar_t* wzValue) = 0;

		// 在尾部增加对象元素;
		virtual void PushBack(IBaseArrayElement* pValue) = 0;


		// 在头部增加 int 类型元素;
		virtual void PushHead(int nValue) = 0;

		// 在头部增加 float 类型元素;
		virtual void PushHead(float fValue) = 0;

		// 在头部增加 wchar_t* 类型元素;
		virtual void PushHead(const wchar_t* wzValue) = 0;

		// 在头部增加对象元素;
		virtual void PushHead(IBaseArrayElement* pValue) = 0;

		// 指定元素的类型;
		virtual EQueueDataType GetElementType(int nIndex) = 0;

		// 若 nIndex 元素为 int 时，取此 int 值;
		virtual int GetElement(int nIndex, int* pnValue ) = 0;

		// 若 nIndex 元素为 int 时，取此 int 值;
		virtual int GetElement(int nIndex, float* pfValue) = 0;

		// 若 nIndex 元素为 wchar_t 时，取此 wchar_t 值, 此内存不需要调用者管理;
		virtual int GetElement(int nIndex, wchar_t** pwzValue) = 0;

		// 若 nIndex 元素为 int 时，取此 int 值;
		virtual int GetElement(int nIndex, IBaseArrayElement** ppValue) = 0;

		// 以 JSON 格式显示已添加的数据;
		//virtual wchar_t* GetDisplayString() = 0;

		// 清除所有元素，同时也会释放每一个IBaseArrayElement占用的资源;
		virtual void Clear() = 0;

	};
}