#pragma once
/***********************************************************************
 * Module:  IAxisPoITooltipAxisPointerinter.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: 坐标轴指示器配置项。
 *  tooltip.axisPointer 是配置坐标轴指示器的快捷方式。实际上坐标轴指示器的
    全部功能，都可以通过轴上的 axisPointer 配置项完成（例如 xAxis.axisPointer 或 angleAxis.axisPointer）。
	但是使用 tooltip.axisPointer 在简单场景下会更方便一些。
 ***********************************************************************/
#include "Common/IEnum.h"
#include "Common/ICallback.h"
//#include "Options/Common/IHandle.h"
#include "Options/Common/IShadowStyle.h"
#include "Options/GeneralOptions/Grid/IGridTooltipAxisPointerLabel.h"
#include "Options/GeneralOptions/Grid/IGridTooltipAxisPointerLineStyle.h"
#include "Options/GeneralOptions/Grid/IGridTooltipAxisPointerCrossStyle.h"

namespace IIChart
{
	namespace Grid
	{
		/*@class
		*************************************************************************
		* 类  名: IGridTooltipAxisPointer
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 本坐标系特定的 tooltip 的坐标轴指示器配置项：
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IGridTooltipAxisPointer
		{
		public:

			/*@function
			******************************************************************
			功  能：指示器类型。
			参  数：<eValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetType(ETooltipAxisPointerType eValue) = 0;
			virtual ETooltipAxisPointerType GetType()const = 0;

			/*@function
			******************************************************************
			功  能：指示器的坐标轴类型。
			注  意: 默认情况，坐标系会自动选择显示哪个轴的 axisPointer（默认取类目轴或者时间轴）。
			参  数：<eValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetAxis(EAxisType eValue) = 0;
			virtual EAxisType GetAxis() const = 0;

			/*@function
			******************************************************************
			功  能：坐标轴指示器是否自动吸附到点上。
			注  意: 默认自动判断。这个功能在数值轴和时间轴上比较有意义，可以自动寻找细小的数值点。
			参  数：<bValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetSnap(bool bValue) = 0;
			virtual bool GetSnap() const = 0;

			/*@function
			******************************************************************
			功  能：坐标轴指示器的 z 值;控制图形的前后顺序。z值小的图形会被z值大的图形覆盖。
			参  数：<nValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetZ(int nValue) = 0;
			virtual int  GetZ() const = 0;
			
			/*@function
			******************************************************************
			功  能：获取坐标轴指示器的文本标签;
			参  数：<无>;
			返回值：<IGridTooltipAxisPointerLabel*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IGridTooltipAxisPointerLabel* GetLabel() = 0;

			/*@function
			******************************************************************
			功  能：获取线的样式;
			参  数：<无>;
			返回值：<IGridTooltipAxisPointerLineStyle*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IGridTooltipAxisPointerLineStyle* GetLineStyle() = 0;

			/*@function
			******************************************************************
			功  能：获指示器阴影的样式;
			注  意：type 为 'shadow' 时有效。
			参  数：<eValue>;
			返回值：<IShadowStyle*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IShadowStyle* GetShadowStyle() = 0;

			/*@function
			******************************************************************
			功  能：获指示器交叉线的样式;
			注  意：axisPointer.type 为 'cross' 时有效。
			参  数：<无>;
			返回值：<IGridTooltipAxisPointerCrossStyle*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IGridTooltipAxisPointerCrossStyle* GetCrossStyle() = 0;
			
			/*@function
			******************************************************************
			功  能：是否开启动画;
			参  数：<bValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetAnimation(bool bValue) = 0;
			virtual bool GetAnimation() const = 0;

			/*@function
			******************************************************************
			功  能：是否开启动画的阈值，当单个系列显示的图形数量大于这个阈值时会关闭动画。
			参  数：<nValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetAnimationThreshold(int nValue) = 0;
			virtual int  GetAnimationThreshold() const = 0;

			/*@function
			******************************************************************
			功  能：初始动画的时长。
			参  数：<nValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetAnimationDuration(int nValue) = 0;
			virtual int  GetAnimationDuration() const = 0;

			/*@function
			******************************************************************
			功  能：设置 初始动画的时长 的 JavaScript 回调函数
			注  意：可以通过每个数据返回不同的时长实现更戏剧的初始动画效果，例如：
					animationDuration: function (idx) {
						// 越往后的数据时长越大
						return idx * 100;
					}
			参  数：<wzValue> JavaScript 函数字符串;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual int SetAnimationDurationJSFun(const wchar_t* wzValue) = 0;

			/*@function
			******************************************************************
			功  能：初始动画的时长 的回调函数。
			注  意：可以通过每个数据返回不同的时长实现更戏剧的初始动画效果
			参  数：<pCallback>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual int SetAnimationDurationCallback(AnimationDurationCallback* pCallback) = 0;

			/*@function
			******************************************************************
			功  能：初始动画的缓动效果。
			参  数：<eValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetAnimationEasing(EAnimationEasing eValue) = 0;
			virtual EAnimationEasing GetAnimationEasing() const = 0;

			/*@function
			******************************************************************
			功  能：初始动画的延迟;
			参  数：<eValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetAnimationDelay(int nValue) = 0;
			virtual int  GetAnimationDelay() const = 0;

			/*@function
			******************************************************************
			功  能：设置 初始动画的延迟 的 JavaScript 回调函数
			注  意：可以通过每个数据返回不同的 delay 时间实现更戏剧的初始动画效果。例如：
					animationDelay: function (idx) {
						// 越往后的数据延迟越大
						return idx * 100;
					}
			参  数：<wzValue> JavaScript 函数字符串;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual int SetAnimationDelayJSFun(const wchar_t* wzValue) = 0;

			/*@function
			******************************************************************
			功  能：设置 初始动画的延迟 的回调函数
			参  数：<pCallback>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual int SetAnimationDelayCallback(AnimationDelayCallback* pCallback) = 0;

			/*@function
			******************************************************************
			功  能：数据更新动画的时长。
			参  数：<pCallback>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetAnimationDurationUpdate(int nValue) = 0;
			virtual int  GetAnimationDurationUpdate() const = 0;

			/*@function
			******************************************************************
			功  能：设置 数据更新动画的时长 的 JavaScript 回调函数
			注  意：可以通过每个数据返回不同的时长实现更戏剧的更新动画效果。例如：
					animationDurationUpdate: function (idx) {
						// 越往后的数据延迟越大
						return idx * 100;
					}
			参  数：<wzValue> JavaScript 函数字符串;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual int SetAnimationDurationUpdateJSFun(const wchar_t* wzValue) = 0;

			/*@function
			******************************************************************
			功  能：设置 数据更新动画的时长 的回调函数
			参  数：<pCallback>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual int SetAnimationDurationUpdateCallback(AnimationDurationUpdateCallback* pCallback) = 0;

			/*@function
			******************************************************************
			功  能：数据更新动画的缓动效果
			参  数：<eValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetAnimationEasingUpdate(EAnimationEasing eValue) = 0;
			virtual EAnimationEasing GetAnimationEasingUpdate() const = 0;

			/*@function
			******************************************************************
			功  能：数据更新动画的延迟
			参  数：<nValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetAnimationDelayUpdate(int nValue) = 0;
			virtual int  GetAnimationDelayUpdate() const = 0;

			/*@function
			******************************************************************
			功  能：设置 数据更新动画的延迟 的 JavaScript 回调函数
			注  意：可以通过每个数据返回不同的 delay 时间实现更戏剧的更新动画效果。例如：
					animationDelayUpdate: function (idx) {
						// 越往后的数据延迟越大
						return idx * 100;
					}
			参  数：<wzValue> JavaScript 函数字符串;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual int SetAnimationDelayUpdateJSFun(const wchar_t* wzValue) = 0;

			/*@function
			******************************************************************
			功  能：设置 数据更新动画的延迟 的回调函数
			参  数：<pCallback>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual int SetAnimationDelayUpdateCallback(AnimationDelayUpdateCallback* pCallback) = 0;
		};
	}

	
}
