#pragma once
/***********************************************************************
 * Module:  IMapTypeLabelEx.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: 图形上的文本标签，可用于说明图形的一些数据信息，比如值，名称等。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/IRich.h"
#include "Common/ICallback.h"
#include "Options/GeneralOptions/Series/Map/IMapTypeLabel.h"


namespace IIChart
{
	namespace Map
	{

		/*@class
		*************************************************************************
		* 类  名: IMapTypeLabelEx
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 图形上的文本标签，可用于说明图形的一些数据信息，比如值，名称等。
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IMapTypeLabelEx
			: virtual public IMapTypeLabel
		{
		public:
			
			/*@function
			******************************************************************
			 功  能：标签的内容格式器的JavaScript回调函数;字符串模板与回调函数返回的字符串均支持用 \n 换行。
			 注  意：回调函数格式：
					(params: Object|Array) => string
					参数 params 是 formatter 需要的单个数据集。格式如下：
					{
						componentType: 'series',
						// 系列类型
						seriesType: string,
						// 系列在传入的 option.series 中的 index
						seriesIndex: number,
						// 系列名称
						seriesName: string,
						// 数据名，类目名
						name: string,
						// 数据在传入的 data 数组中的 index
						dataIndex: number,
						// 传入的原始数据项
						data: Object,
						// 传入的数据值。在多数系列下它和 data 相同。在一些系列下是 data 中的分量（如 map、radar 中）
						value: number|Array|Object,
						// 坐标轴 encode 映射信息，
						// key 为坐标轴（如 'x' 'y' 'radius' 'angle' 等）
						// value 必然为数组，不会为 null/undefied，表示 dimension index 。
						// 其内容如：
						// {
						//     x: [2] // dimension index 为 2 的数据映射到 x 轴
						//     y: [0] // dimension index 为 0 的数据映射到 y 轴
						// }
						encode: Object,
						// 维度名列表
						dimensionNames: Array<String>,
						// 数据的维度 index，如 0 或 1 或 2 ...
						// 仅在雷达图中使用。
						dimensionIndex: number,
						// 数据图形的颜色
						color: string
					}
					更详细说明，可能参考：https://echarts.apache.org/zh/option.html#series-line.type
			 参  数：<wzValue> 字符串模板;
			 返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual int SetFormatterJSFun(const wchar_t* wzValue) = 0;


		};
	}
}
