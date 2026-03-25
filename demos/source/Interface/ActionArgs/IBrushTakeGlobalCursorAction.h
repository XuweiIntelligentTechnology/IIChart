#pragma once
/***********************************************************************
 * Module:  IBrushTakeGlobalCursorActionArgs.h
 * Author:  杨鹏辉
 * Modified: 2022年6月30日 11:42:37
 * Purpose: 刷选模式的开关。使用此 action 可将当前鼠标变为可刷选状态。 
            事实上，点击 toolbox 中的 brush 按钮时，就是通过这个 action，
			将当前普通鼠标变为刷选器的。例如：

            此 action 对应的事件为 globalCursorTaken。
 ***********************************************************************/
#include <ActionArgs/IAction.h>
#include <ActionArgs/IBrushAction.h>

namespace IIChart
{

	class IBrushTakeGlobalCursorAction : virtual public IAction
	{
	public:
		virtual void SetBrushType(EBrushType eValue) = 0;
		virtual EBrushType GetBrushType() = 0;

		virtual void SetBrushMode(EBrushMode eValue) = 0;
		virtual EBrushMode GetBrushMode() = 0;
	};
}


