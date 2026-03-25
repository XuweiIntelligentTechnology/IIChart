#pragma once
/***********************************************************************
 * Module:  IDimensionsData.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: series-sunburst.data 的数据格式是树状的,例如：
			 [{
				name: 'parent1',
				value: 10,          // 可以不写父元素的 value，则为子元素之和；
									// 如果写了，并且大于子元素之和，可以用来表示还有其他子元素未显示
				children: [{
					value: 5,
					name: 'child1',
					children: [{
						value: 2,
						name: 'grandchild1',
						itemStyle: {
							// 每个数据可以有自己的样式，覆盖 series.itemStyle 和 level.itemStyle
						},
						label: {
							// 标签样式，同上
						}
					}]
				}, {
					value: 3,
					name: 'child2'
				}],
				itemStyle: {
					// parent1 的图形样式，不会被后代继承
				},
				label: {
					// parent1 的标签样式，不会被后代继承
				}
			}, {
				name: 'parent2',
				value: 4
			}]
 ***********************************************************************/
//#include "Common/IEnum.h"
#include "Options/Common/IBaseArrayElement.h"
#include "Options/GeneralOptions/Series/Sunburst/ISunburstTypeData.h"
#include "Options/GeneralOptions/Series/Sunburst/ISunburstTypeLabel.h"
#include "Options/GeneralOptions/Series/Sunburst/ISunburstTypeLabelLineEx.h"
#include "Options/GeneralOptions/Series/Sunburst/ISunburstTypeLabelLayout.h"
#include "Options/GeneralOptions/Series/Sunburst/ISunburstTypeItemStyleEx.h"
#include "Options/GeneralOptions/Series/Sunburst/ISunburstTypeDataEmphasis.h"
#include "Options/GeneralOptions/Series/Sunburst/ISunburstTypeBlur.h"
#include "Options/GeneralOptions/Series/Sunburst/ISunburstTypeSelect.h"

namespace IIChart
{
	namespace Sunburst
	{
		/*@class
		*************************************************************************
		* 类  名: ISunburstTypeData
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 系列中的数据
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class ISunburstTypeData : virtual public IBaseArrayElement
		{
		public:

			/*@function
			*******************************************************************
			功  能:  数据项名称
			参  数:  <wzValue>;
			返回值:  <无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetName(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetName() const = 0;

			/*@function
			*******************************************************************
			功  能:  数据值，
			注  意： 如果包含 children，则可以不写 value 值。这时，将使用子元素
					 的 value 之和作为父元素的 value。如果 value 大于子元素之和，
					 可以用来表示还有其他子元素未显示。
					 调用设置的值;
			参  数:  <nValue>;
			返回值:  <无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetValue(int nValue) = 0;
			virtual void GetValue(int* pnValue) = 0;

			/*@function
			*******************************************************************
			功  能:  数据值，
			注  意： 如果包含 children，则可以不写 value 值。这时，将使用子元素
			         的 value 之和作为父元素的 value。如果 value 大于子元素之和，
					 可以用来表示还有其他子元素未显示。
					 调用设置的值;
			参  数:  <fValue>;
			返回值:  <无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetValue(float fValue) = 0;
			virtual void GetValue(float* pfValue) = 0;

			/*@function
			*******************************************************************
			功  能: 描述了每个扇形块中，文本标签的样式。
			参  数: <无>;
			返回值: <ISunburstTypeLabel*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ISunburstTypeLabel* GetLabel() = 0;

			/*@function
			*******************************************************************
			* 功  能：标签的视觉引导线配置。
			* 注  意：该配置项是在每个系列默认的标签布局基础上，统一调整标签的(x, y)位置，
			*         标签对齐等属性以实现想要的标签布局效果。
			* 参  数：<无>;
			* 返回值：<ISunburstTypeLabelLineEx*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ISunburstTypeLabelLineEx* GetLabelLine() = 0;

			/*@function
			*******************************************************************
			* 功  能：旭日图扇形块的样式。
			* 参  数：<无>;
			* 返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ISunburstTypeItemStyleEx* GetItemStyle() = 0;

			/*@function
			*******************************************************************
			* 功  能：高亮状态配置。
			* 参  数：<无>;
			* 返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ISunburstTypeDataEmphasis* GetEmphasis() = 0;

			/*@function
			*******************************************************************
			* 功  能：淡出状态配置。开启 emphasis.focus 后有效。
			* 参  数：<无>;
			* 返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ISunburstTypeBlur* GetBlur() = 0;

			/*@function
			*******************************************************************
			* 功  能：选中状态配置。开启 selectedMode 后有效。
			* 参  数：<无>;
			* 返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual ISunburstTypeSelect* GetSelect() = 0;

			/*@function
			*******************************************************************
			* 功  能：删除掉所有已添加的子节点
			* 参  数：<无>;
			* 返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void ClearChildern() = 0;

			/*@function
			*******************************************************************
			* 功  能：添加一个子节点
			* 参  数：<wzName> 显示在扇形块中的描述文字;
			*         <nValue/fValue> 数据值，如果包含 children，则可以不写 value 值
			                          这时，将使用子元素的 value 之和作为父元素的 value。
									  如果 value 大于子元素之和，可以用来表示还有其他子元素未显示;
	                  <wzItemColor> 功能与 GetItemStyle()->SetColor(wzValue)相同;
			* 返回值：<ISunburstTypeData*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual int AddChildren(const wchar_t* wzName) = 0;
			virtual int AddChildren(const wchar_t* wzName, int nValue, const wchar_t* wzItemColor = nullptr) = 0;
			virtual int AddChildren(const wchar_t* wzName, float fValue, const wchar_t* wzItemColor = nullptr) = 0;

			/*@function
			*******************************************************************
			* 功  能：添加一个子节点
			* 参  数：<pValue>;
			* 返回值：<ISunburstTypeData*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual int AddChildren(ISunburstTypeData* pValue) = 0;

			/*@function
			******************************************************************
			* 功  能：添加多个子节点
			* 注  意：-- 此方法增加的数据只是一个一组数组;
			*         -- 由于原有的数据没有被消除，此方法会使显示的数据量一直增大
			* 参  数：<pQueue>;
			* 返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual int AddChildren(IFixedQueue* pQueue) = 0;

			/*@function
			******************************************************************
			* 功  能：设置多个子节点，原来的子节点将被覆盖掉;
			* 注  意：系列原来的数据将被覆盖掉;
			*         此接口可以方便的实现动态图表显示;
			* 参  数：<pQueue> 新的数据;
			* 返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual int SetChildern(IFixedQueue* pQueue) = 0;
		};
	}

}