#pragma once

#include <vector>
#include <string>
#include <IChartManager.h>
#include <IGlobalUtility.h>
#include <Options\Common\IBaseArrayElement.h>
#include <Options\GeneralOptions\IGeneralOptions.h>

#include <Common\IEnum.h>

using namespace std;

#if defined NBECHART_EXPORTS
#define NBECHART_EXPORTS_API  extern "C" __declspec(dllexport)
#else
#define NBECHART_EXPORTS_API  extern "C" __declspec(dllimport)
#endif

namespace IIChart
{
	/*@function
	************************************************************************
	功  能：创建图表管理器;
	参  数：<无>;
	返回值：<IChartManager*>;
	-----------------------------------------------------------------------
	作  者:  YangPenghui 2022-10-26;
	************************************************************************/
	NBECHART_EXPORTS_API IChartManager* CreateChartManager();

	/*@function
	************************************************************************
	功  能：创建全局应用接口;
	参  数：<无>;
	返回值：<IChartManager*>;
	-----------------------------------------------------------------------
	作  者:  YangPenghui 2022-10-26;
	************************************************************************/
	NBECHART_EXPORTS_API IGlobalUtility* CreateGlobalUtility();

	
	typedef IChartManager* (*pCreateChartManager)();
	typedef IGlobalUtility* (*pCreateGlobalUtility)();
	
}