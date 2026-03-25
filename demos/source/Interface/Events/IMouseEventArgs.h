#pragma once
/***********************************************************************
 * Module:  IMouseEvent.h
 * Author:  杨鹏辉
 * Modified: 2022年6月30日 11:42:37
 * Purpose: 鼠标事件的事件参数
 ***********************************************************************/
#include "Common/IQueue.h"
#include <Events/IEvents.h>

namespace IIChart
{

	class IMouseEventArgs 
		: virtual public IEventArgs
	{
	public:

		// 当前点击的图形元素所属的组件名称，
		// 其值如 'series'、'markLine'、'markPoint'、'timeLine' 等。
		virtual wchar_t* GetComponentType() = 0;

		// 系列类型。值可能为：'line'、'bar'、'pie' 等。当 componentType 为 'series' 时有意义。
		virtual wchar_t* GetSeriesType() = 0;

		// 系列在传入的 option.series 中的 index。当 componentType 为 'series' 时有意义。
		virtual int GetSeriesIndex() = 0;

		// 系列名称。当 componentType 为 'series' 时有意义。
		virtual wchar_t* GetSeriesName() = 0;

		// 数据名，类目名
		virtual wchar_t* GetName() = 0;

		// 传入的原始数据项, 此值为 Object;
		virtual void* GetData() = 0;

		// sankey、graph 等图表同时含有 nodeData 和 edgeData 两种 data，
		// dataType 的值会是 'node' 或者 'edge'，表示当前点击在 node 还是 edge 上。
		// 其他大部分图表中只有一种 data，dataType 无意义。
		virtual wchar_t* GetDataType() = 0;

		// 传入的数据值
		virtual int GetValue(IQueue* pValues) = 0;
		virtual int GetValueCount(int* pnCount) = 0;
		virtual float GetValue(int nIndex) = 0;

		// 数据图形的颜色。当 componentType 为 'series' 时有意义。
		virtual wchar_t* GetColor() = 0;

		// 用户自定义的数据。只在 graphic component 和自定义系列（custom series）
		// 中生效，如果节点定义上设置了如：{type: 'circle', info: {some: 123}}。
		virtual void* GetInfo() = 0;

		// 百分比.当 'series' 为 'pie' 时有意义。
		virtual int GetPercent() = 0;

	};
}
