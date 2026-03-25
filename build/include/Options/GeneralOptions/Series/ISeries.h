#pragma once
/***********************************************************************
 * Module:  ISeries.h
 * Author:  杨鹏辉
 * Modified: 2022年7月6日 22:58:54
 * Purpose: Declaration of the class ISeriesStore
 * Comment: 系列仓库
 *    1.创建单个系列，并设置系列内容；
 *    2. 生成多个系列数组；
 ***********************************************************************/
#include "Options/Common/IBaseArrayElement.h"
#include "Options/GeneralOptions/Series/Line/ILineType.h"
#include "Options/GeneralOptions/Series/Bar/IBarType.h"
//#include "Options/GeneralOptions/Series/CustomType/ICustomType.h"
#include "Options/GeneralOptions/Series/EffectScatter/IEffectScatterType.h"
#include "Options/GeneralOptions/Series/Gauge/IGaugeType.h"
#include "Options/GeneralOptions/Series/Map/IMapType.h"
#include "Options/GeneralOptions/Series/Pie/IPieType.h"
#include "Options/GeneralOptions/Series/Radar/IRadarType.h"
#include "Options/GeneralOptions/Series/Scatter/IScatterType.h"
#include "Options/GeneralOptions/Series/Sunburst/ISunburstType.h"

namespace IIChart
{
	class ISeries
	{
	public:
		virtual Line::ILineType* CreateLineType() = 0;
		virtual Bar::IBarType* CreateBarType() = 0;
		virtual EffectScatter::IEffectScatterType* CreateEffectScatterType() = 0;
		virtual Pie::IPieType* CreatePieType() = 0;
		virtual Radar::IRadarType* CreateRadarType() = 0;
		virtual Scatter::IScatterType* CreateScatterType() = 0;
		virtual Map::IMapType* CreateMapType() = 0;
		virtual Sunburst::ISunburstType* CreateSunburstType() = 0;
		virtual Gauge::IGaugeType* CreateGaugeType() = 0;

		virtual  int AppendSeries(IBaseArrayElement* pElement) = 0;
		virtual void* GetSeries(int nIndex) = 0;
		virtual void Reset() = 0;
	};

}

