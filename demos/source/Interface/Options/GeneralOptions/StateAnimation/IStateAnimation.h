#pragma once
/***********************************************************************
 * Module:  IStateAnimation.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: 状态切换的动画配置，支持在每个系列里设置单独针对该系列的配置。
 ***********************************************************************/
#include <Common/IEnum.h>

namespace IIChart
{
	namespace StateAnimation
	{
		
		
		/***********************************************************************
		 * Clsss:  IStateAnimation.h
		 * Author:  杨鹏辉
		 * Modified: 2022年7月1日 15:02:44
		 * Purpose: 状态切换的动画配置，支持在每个系列里设置单独针对该系列的配置。
		 ***********************************************************************/
		class IStateAnimation
		{
		public:
			// 状态切换的动画时长，设为 0 则关闭状态动画。
			virtual void SetDuration(int nValue) = 0;
			virtual int  GetDuration() const = 0;

			// 初始动画的缓动效果。
			virtual void SetEasing(EAnimationEasing eValue) = 0;
			virtual EAnimationEasing GetEasing() const = 0;
		};
	}
	
}