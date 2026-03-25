#pragma once
/***********************************************************************
 * Module:  IEffectScatterType.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: 带有涟漪特效动画的散点（气泡）图。利用动画特效可以将某些想
   要突出的数据进行视觉突出。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Options/Common/IBaseArrayElement.h"


namespace IIChart
{
	namespace EffectScatter
	{

		
		class IEffectScatterType : public IBaseArrayElement
		{
		public:

			virtual wchar_t* GetType() const = 0;

			// 组件 ID。默认不指定。指定则可用于在 option 或者 API 中引用组件。
			virtual void SetId(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetId() const = 0;

			// 系列名称，用于tooltip的显示，legend 的图例筛选，在 setOption 更新数据和配置项时用于指定对应的系列。
			virtual void SetName(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetName() const = 0;

			// 从调色盘 option.color 中取色的策略
			virtual void SetColorBy(EColorBy eValue) = 0;
			virtual EColorBy GetColorBy() const = 0;

			// 特效类型，目前只支持涟漪特效'ripple'。
			virtual void SetEffectType(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetEffectType() const = 0;

			// 特效类型，目前只支持涟漪特效'ripple'。
			virtual void SetShowEffectOn(EShowEffectOpportunity eValue) = 0;
			virtual EShowEffectOpportunity GetShowEffectOn() const = 0;

			// 该系列使用的坐标系
			virtual void SetCoordinateSystem(ECoordinateSystem eValue) = 0;
			virtual ECoordinateSystem GetCoordinateSystem() const = 0;

			// 使用的 x 轴的 index，在单个图表实例中存在多个 x 轴的时候有用。
			virtual void SetXAxisIndex(int nValue) = 0;
			virtual int GetXAxisIndex() const = 0;

			// 使用的 y 轴的 index，在单个图表实例中存在多个 y轴的时候有用。
			virtual void SetYAxisIndex(int nValue) = 0;
			virtual int GetYAxisIndex() const = 0;

			// 使用的极坐标系的 index，在单个图表实例中存在多个极坐标系的时候有用。
			virtual void SetPolarIndex(int nValue) = 0;
			virtual int GetPolarIndex() const = 0;

			// 使用的地理坐标系的 index，在单个图表实例中存在多个地理坐标系的时候有用。
			virtual void SetGeoIndex(int nValue) = 0;
			virtual int GetGeoIndex() const = 0;

			// 使用的日历坐标系的 index，在单个图表实例中存在多个日历坐标系的时候有用。
			virtual void SetCalendarIndex(int nValue) = 0;
			virtual int GetCalendarIndex() const = 0;

			// 标记的图形
			virtual void SetSymbol(ESymbol nValue) = 0;
			virtual ESymbol GetSymbol() const = 0;

			// 标记的大小，可以设置成诸如 10 这样单一的数字
			virtual void SetSymbolSize(int nSize) = 0;
			virtual int GetSymbolSize() const = 0;

			// 标记的大小，高度
			virtual void SetSymbolSize(int nHeight, int nWidth) = 0;
			virtual void GetSymbolSize(int& nHeight, int& nWidth) = 0;

			// 标记的旋转角度（而非弧度）,正值表示逆时针旋转。
			// 注意在 markLine 中当 symbol 为 'arrow' 时会忽略 symbolRotate 强制设置为切线的角度。
			virtual void SetSymbolRotate(int nRotate) = 0;
			virtual int GetSymbolRotate() const = 0;

		};
	}

}
