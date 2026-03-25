#pragma once

namespace IIChart
{

	// (index: number, count: number) => number
	typedef int (*DelayCallback)(int nIndex, int nCount);
	
	typedef int (*AnimationDelayCallback)(int nIndex);

	typedef int (*AnimationDelayUpdateCallback)(int nIndex);

	typedef int (*AnimationDurationCallback)(int nIndex);

	typedef int (*AnimationDurationUpdateCallback)(int nIndex);



	typedef bool (*IntervalCallback)(int nIndex, const wchar_t* wzValue);
	typedef wchar_t* (*ColorCallback)(const wchar_t* wzValue);
	typedef wchar_t* (*LineItemStyleColorCallback)(int nSeriesIndex, int nDataIndex, void* data, void* value);

	// (value: Array|number, params: Object) => string
	// 其中第一个参数 value 为 data 中的数据值。第二个参数params 是其它的数据项参数。
	typedef wchar_t* (*SymbolCallback)(int* pnValue, int nCount, void* object);

	// (value: Array|number, params: Object) => number|Array
	// 其中第一个参数 value 为 data 中的数据值。第二个参数params 是其它的数据项参数。
	typedef wchar_t* (*SymbolSizeCallback)(int* pnValue, int nCount, void* object);

	// (value: Array|number, params: Object) => number
	// 其中第一个参数 value 为 data 中的数据值。第二个参数params 是其它的数据项参数。
	typedef wchar_t* (*SymbolRotateCallback)(int* pnValue, int nCount, void* object);

	// TODO:
	typedef wchar_t* (*FormatterCallback)(int* pnValue, int nCount, void* object);
}