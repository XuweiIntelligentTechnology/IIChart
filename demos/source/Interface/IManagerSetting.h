
/***********************************************************************
 * Module:  IManagerSetting.h
 * Author:  YangPenghui
 * Modified: 2022年6月30日 11:26:28
 * Purpose: 
 * 1. Chart 运行环境设置;
 * 2. 多个 Chart 布局设置: 各个 Chart 采用 flex 布局;
 ***********************************************************************/
#pragma once

namespace IIChart
{
	/* 项目的排列方向; */
	typedef enum _EFlexDirection
	{
		EFD_ROW = 0,       // （默认值）：主轴为水平方向，起点在左端
		EFD_ROW_REVERSE,   // 主轴为水平方向，起点在右端
		EFD_COLUMN,        // 主轴为垂直方向，起点在上沿
		EFD_COLUMN_REVERSE // 主轴为垂直方向，起点在下沿
	}EFlexDirection;

	/* 定义，如果一条轴线 排不下，如何换行; */
	typedef enum _EFlexWrap
	{
		EFW_WRAP = 0,       // （默认值）：换行，第一行在上方
		EFW_WRAP_REVERSE    // 换行，在第一行的下方
	}EFlexWrap;

	/* 定义了项目在主轴上的对齐方式; */
	typedef enum _EJustifyContent
	{
		EJC_START = 0,     // （默认值）：左对齐
		EJC_END,           // 右对齐
		EJC_CENTER,        // 居中
		EJC_SPACE_BERWEEN, // 两端对齐，项目之间的间隔都相等
		EJC_SPACE_AROUND   // 每个项目两侧的间隔相等。所以，项目之间的间隔比项目与边框的间隔大一倍。
	}EJustifyContent;


	/*@class
	*************************************************************************
	* 类  名: IManagerSetting
	* 修  改: 2022年7月1日 15:02:44
	* 功  能: ChartManager相关的配置;
	-----------------------------------------------------------------------
	作  者:  YangPenghui 2022-10-26;
	************************************************************************/
	class IManagerSetting
	{
	public:
		/*@function
		************************************************************************
		功  能：若设置的此路径为 WebView2 Runtime 目录，则使用固定版本的运行库;
		        默认为 nullptr ，即使用系统的 WebView2 Runtime （此种情况仅 ）
		说  明：Windows 11 及以上版本自动支持 WebView2, Windows10、Windows7 需要另外安装 WebView2 Runtime;
		        也可以使用本软件推荐的固定版本的 WebView2 Runtime 包，将其
		参  数：<eValue> 排列方向;
		返回值：<错误码>;
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		virtual void SetRuntimeFolder(const wchar_t* wzPath = nullptr) = 0;
		virtual wchar_t* GetRuntimeFolder() const = 0;

		/*@function
		************************************************************************
		功  能：各个子图表排列方向;
		参  数：<eValue> 排列方向;
		返回值：<错误码>;
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		virtual int SetFlexDirection(EFlexDirection eValue) = 0;
		virtual EFlexDirection GetFlexDirection() const = 0;

		/*@function
		************************************************************************
		功  能：各个子图表在一条轴线排不下时的换行方式;
		参  数：<eValue> 换行方式
		返回值：<错误码>;
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		virtual int SetFlexWrap(EFlexWrap eValue) = 0;
		virtual EFlexWrap GetFlexWrap() const = 0;

		/*@function
		************************************************************************
		功  能：各个子图表在主轴上的对齐方式;
		参  数：<eValue> 对齐方式
		返回值：<错误码>;
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		virtual int SetJustifyContent(EJustifyContent eValue) = 0;
		virtual EJustifyContent GetJustifyContent() const = 0;

	};

}

