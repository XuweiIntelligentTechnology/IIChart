/***********************************************************************
 * Module:  IAction.h
 * Author:  杨鹏辉
 * Modified: 2022年6月30日 11:42:37
 * Purpose: Declaration of the class IAction
 ***********************************************************************/
#pragma once

namespace IIChart
{

	class IAction
	{
	public:
		virtual wchar_t* GetType() = 0;
		virtual wchar_t* Serialize(void) = 0;
		virtual void* GetInternalObject(void) = 0; // 取内部对象，此接口上层用户不需要调用;
		virtual void Reset(void) = 0;
		virtual void Release() = 0;
	};
}


