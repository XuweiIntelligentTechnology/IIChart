#pragma once

#include <vector>
#include <string>
#include "IChartManager.h"
#include "IGlobalUtility.h"
#include "Options\Common\IBaseArrayElement.h"
#include "Options\GeneralOptions\IGeneralOptions.h"

using namespace std;

#if defined NBECHART_EXPORTS
#define NBECHART_EXPORTS_API __declspec(dllexport)
#else
#define NBECHART_EXPORTS_API __declspec(dllimport)
#endif

#ifndef II_CHART_CALL
#define II_CHART_CALL __cdecl
#endif

/*
 * Stable C ABI exports for both usage modes:
 * 1) Import library (.lib) implicit linking
 * 2) LoadLibrary/GetProcAddress explicit loading
 */
extern "C"
{
	/*@function
	************************************************************************
	功  能：创建图表管理器;
	参  数：<无>;
	返回值：<IChartManager*>;
	-----------------------------------------------------------------------
	作  者:  YangPenghui 2022-10-26;
	************************************************************************/
	NBECHART_EXPORTS_API IIChart::IChartManager* II_CHART_CALL CreateChartManager();

	/*@function
	************************************************************************
	功  能：创建全局应用接口;
	参  数：<无>;
	返回值：<IChartManager*>;
	-----------------------------------------------------------------------
	作  者:  YangPenghui 2022-10-26;
	************************************************************************/
	NBECHART_EXPORTS_API IIChart::IGlobalUtility* II_CHART_CALL CreateGlobalUtility();
}

namespace IIChart
{
	/* Keep namespace-style usage for source compatibility. */
	inline IChartManager* CreateChartManager()
	{
		return ::CreateChartManager();
	}

	inline IGlobalUtility* CreateGlobalUtility()
	{
		return ::CreateGlobalUtility();
	}

	/* Safer function pointer typedefs for GetProcAddress. */
	typedef IChartManager* (II_CHART_CALL* pCreateChartManager)();
	typedef IGlobalUtility* (II_CHART_CALL* pCreateGlobalUtility)();
}