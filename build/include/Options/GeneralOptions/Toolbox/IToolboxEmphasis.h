#pragma once
/***********************************************************************
 * Module:  IToolboxIconStyle.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: 公用的 icon 样式设置
 * 由于 icon 的文本信息只在 icon hover 时候才显示，所以文字相关的配置项请在 emphasis 下设置。
 ***********************************************************************/
#include "Options/GeneralOptions/Toolbox/IToolboxIconStyle.h"

namespace IIChart
{
	namespace Toolbox
	{
		/***************************
	    * IToolboxEmphasis;
	    ****************************/
		class IToolboxEmphasis
		{
		public:
			virtual IToolboxIconStyle* GetIconStyle() = 0;

		};
	}
	
}