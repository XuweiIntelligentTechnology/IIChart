#pragma once
/***********************************************************************
 * Module:  IMapTypeProjection.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: 自定义地图投影，至少需要提供project, unproject两个方法分别用来计算投影后的坐标以及计算投影前的坐标。
 *          比如墨卡托投影：
 * 
 *			  series: {
 *				type: 'map',
 *				projection: {
 *					project: (point) => [point[0] / 180 * Math.PI, -Math.log(Math.tan((Math.PI / 2 + point[1] / 180 * Math.PI) / 2))],
 *					unproject: (point) => [point[0] * 180 / Math.PI, 2 * 180 / Math.PI * Math.atan(Math.exp(point[1])) - 90]
 *				}
 *			}
 *      除了我们自己实现投影公式，我们也可以使用 d3-geo 等第三方库提供的现成的投影实现：
 *      (d3-geo https://github.com/d3/d3-geo)  例如：
		
		series: {
			type: 'map',
			projection: {
				project: (point) => d3.geoConicEqualArea(point),
				unproject: (point) => d3.geoConicEqualArea.invert(point)
			}
		}

		注：自定义投影只有在使用GeoJSON作为数据源的时候有用。
 ***********************************************************************/

namespace IIChart
{
	namespace Map
	{
		/*@class
		*************************************************************************
		* 类  名: IMapTypeProjection
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 自定义地图投影
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IMapTypeProjection
		{
		public:
			
			/*@function
			******************************************************************
			 功  能：将经纬度坐标投影为其它坐标。
			 注  意：回调函数格式：
					(coord: [number, number]) => [number, number]
			 参  数：<wzValue> ;
			 返回值：<错误码>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual int SetProjectJSFun(const wchar_t* wzValue) = 0;

			/*@function
			******************************************************************
			 功  能：根据投影后坐标计算投影前的经纬度坐标
			 注  意：回调函数格式：
					(point: [number, number]) => [number, number]
			 参  数：<wzValue> ;
			 返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual int SetUnprojectJSFun(const wchar_t* wzValue) = 0;
			
			/*@function
			******************************************************************
			 功  能：该属性主要用于适配 d3-geo 中使用的 stream 接口。在引入 stream 后
			         可以同时引入d3-geo 中实现的Antimeridian Clipping以及Adaptive Sampling算法。
			 注  意：例如：
						series: {
						type: 'map',
						projection: {
							// project 和 unproject 依旧需要配置。
							project: (point) => d3.geoProjection((x, y) => ([x, y / 0.75])),
							unproject: (point) => d3.geoProjection((x, y) => ([x, y / 0.75])),
							// 可以直接使用 d3-geo 提供的 stream 方法。
							stream: d3.geoProjection((x, y) => ([x, y / 0.75])).stream
							}
						}
			 参  数：<wzValue> 字符串模板;
			 返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual int SetStreamJSFun(const wchar_t* wzValue) = 0;
		};
	}
}
