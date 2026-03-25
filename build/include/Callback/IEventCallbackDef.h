#pragma once
/***********************************************************************
 * Module:  IEventCallbackDef.h
 * Author:  杨鹏辉
 * Modified: 2022年6月30日 11:42:37
 * Purpose: 定义在 IChart.On(...) 中调用的事件;
 ***********************************************************************/

#include "Events\IMouseEventArgs.h"

namespace IIChart
{
	typedef void (*OnMouseEventCallback)(IMouseEventArgs*);
}