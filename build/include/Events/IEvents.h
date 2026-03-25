/***********************************************************************
 * Module:  IEvents.h
 * Author:  杨鹏辉
 * Modified: 2022年6月30日 11:42:37
 * Purpose: Declaration of the class IEvents
 ***********************************************************************/
#pragma once

namespace IIChart
{
	typedef enum _EChartEvent
	{
		Evt_click = 0,          // 鼠标单击;
		Evt_dblclick,
		Evt_mousedown,
		Evt_mousemove,
		Evt_mouseup,
		Evt_mouseover,
		Evt_mouseout,
		Evt_globalout,
		Evt_contextmenu,
		
		Evt_highlight,         // 高亮事件
		Evt_downplay,          // 取消高亮事件。
		
		Evt_selectchanged,// ACTION: toggleSelected, select, unselect.在数据选中状态发生变化时触发的事件
		Evt_legendselectchanged, // ACTION: legendToggleSelect 切换图例选中状态后的事件。注：图例组件用户切换图例开关会触发该事件。
		Evt_legendselected, // ACTION: legendSelect 图例选中后的事件。
		Evt_legendunselected, // ACTION: legendUnSelect 图例取消选中后的事件。
		Evt_legendselectall,  // ACTION: legendAllSelect 图例全选后的事件
		Evt_legendinverseselect, // ACTION: legendInverseSelect 图例反选后的事件。
		
		Evt_legendscroll, // ACTION: legendscroll 图例滚动事件。
		Evt_datazoom,     // ACTION: dataZoom, 数据区域缩放后的事件。
		Evt_datarangeselected,  // ACTION: selectDataRange 视觉映射组件中，range 值改变后触发的事件。
		
		Evt_timelinechanged,     // ACTION: timelineChange 时间轴中的时间点改变后的事件。
		Evt_timelineplaychanged, // ACTION: timelinePlayChange 时间轴中播放状态的切换事件。
		
		Evt_restore,          // ACTION: restore 重置 option 事件。
		Evt_dataviewchanged,  // 工具栏中数据视图的修改事件。
		Evt_magictypechanged, // 工具栏中动态类型切换的切换事件。
		
		Evt_geoselectchanged, // ACTION: geoToggleSelect, geo 中地图区域切换选中状态的事件。用户点击选中会触发该事件。
		Evt_geoselected,      // ACTION: geoSelect, geo 中地图区域选中后的事件。使用dispatchAction可触发此事件，用户点击不会触发此事件（用户点击事件请使用 geoselectchanged）。
		Evt_geounselected,    // ACTION: geoUnSelect, geo 中地图区域取消选中后的事件。使用dispatchAction可触发此事件，用户点击不会触发此事件（用户点击事件请使用 geoselectchanged）。
		
		Evt_axisareaselected,  // 平行坐标轴 (Parallel)范围选取事件。当进行坐标轴范围选取时，可以用如下方式获取当前高亮的线所对应的 data indices （即 series 的 data 中的序号列表）。
		Evt_brush,             // “选框正在添加”事件。即发出 brush action 得到的事件。
		Evt_brushEnd,          // “选框添加完毕”事件。即发出 brushEnd action 得到的事件。
		Evt_brushselected,     // 这个事件，在 setOption 时不会发出，在其他的 dispatchAction 时，或者用户在界面中创建、删除、修改选框时会发出。
		Evt_globalcursortaken, // 刷选模式的开关。使用此 action 可将当前鼠标变为可刷选状态。 事实上，点击 toolbox 中的 brush 按钮时，就是通过这个 action，将当前普通鼠标变为刷选器的。
		Evt_rendered, // 渲染结束事件。注意 rendered 事件并不代表渲染动画（参见 animation 相关配置）或者渐进渲染（参见 progressive 相关配置）停止，只代表本帧的渲染结束。
		Evt_finished, // 渲染完成事件。当渲染动画（参见 animation 相关配置）或者渐进渲染（参见 progressive 相关配置）停止时触发。

		Evt_MAX
	}EChartEvent;


	class IEventArgs
	{
	public:

		virtual int GetErrorCode(wchar_t* wzDetail) = 0;

	};
}