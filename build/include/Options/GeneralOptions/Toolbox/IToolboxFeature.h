#pragma once
/***********************************************************************
 * Module:  IToolboxFeature.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: 各工具配置项。
 * 除了各个内置的工具按钮外，还可以自定义工具按钮。
 *		注意，自定义的工具名字，只能以 my 开头，例如下例中的 myTool1，myTool2：
 *		可以设置在全局，即 tooltip
 *		可以设置在坐标系中，即 grid.tooltip、polar.tooltip、single.tooltip
 *		可以设置在系列中，即 series.tooltip
 *		可以设置在系列的每个数据项中，即 series.data.tooltip
 ***********************************************************************/
#include "Options/GeneralOptions/Toolbox/IToolboxFeatureSaveAsImage.h"
#include "Options/GeneralOptions/Toolbox/IToolboxFeatureRestore.h"
#include "Options/GeneralOptions/Toolbox/IToolboxFeatureDataView.h"
#include "Options/GeneralOptions/Toolbox/IToolboxFeatureDataZoom.h"
#include "Options/GeneralOptions/Toolbox/IToolboxFeatureBrush.h"

namespace IIChart
{
	namespace Toolbox
	{
		/***************************
	    * IToolboxFeature;
	    ****************************/
		class IToolboxFeature
		{
		public:
			
			// 保存为图片。
			virtual IToolboxFeatureSaveAsImage* GetSaveAsImage() = 0;

			// 配置项还原。
			virtual IToolboxFeatureRestore* GetRestore() = 0;

			// 数据视图工具，可以展现当前图表所用的数据，编辑后可以动态更新。
			virtual IToolboxFeatureDataView* GetDataView() = 0;

			// 数据区域缩放。目前只支持直角坐标系的缩放。
			virtual IToolboxFeatureDataZoom* GetDataZoom() = 0;

			// 选框组件的控制按钮。
			virtual IToolboxFeatureBrush* GetBrush() = 0;
		};
	}
	
}