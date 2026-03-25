#pragma once
/***********************************************************************
 * Module:  IBaseArrayElement.h
 * Author:  杨鹏辉
 * Modified: 2022年7月6日 22:59:41
 * Purpose: Declaration of the class IBaseArrayElement
 * Comment: Options 中的所有数组类型的基类;
 ***********************************************************************/

namespace IIChart
{
	class IBaseArrayElement
	{
	public:
		virtual void Reset() = 0;                  // 清空对象内容，便用对像复用;
		virtual void Release() = 0;                // 析构自身实例;
		virtual void* GetInternalObject(void) = 0; // 取内部对象，此接口上层用户不需要调用;
	};
}