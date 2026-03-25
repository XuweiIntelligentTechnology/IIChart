#pragma once
/***********************************************************************
 * Module:  IVisualMapPiecewise.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: 分段型视觉映射组件（visualMapPiecewise）
 *		分段型视觉映射组件，有三种模式：
 *			- 连续型数据平均分段: 依据 visualMap-piecewise.splitNumber 来自动平均分割成若干块。
 *			- 连续型数据自定义分段: 依据 visualMap-piecewise.pieces 来定义每块范围。
 *			- 离散数据根据类别分段: 类别定义在 visualMap-piecewise.categories 中。
 ***********************************************************************/
#include <vector>
#include <string>
#include "Common/IEnum.h"
#include "Common/ICallback.h"
#include "Common/IFixedQueue.h"
#include "Common/IQueue.h"
#include "Options/Common/ICategoryData.h"
#include "Options/GeneralOptions/VisualMap/IVisualMapTarget.h"
#include "Options/GeneralOptions/VisualMap/IVisualMapPieceComponent.h"
#include "Options/GeneralOptions/VisualMap/IVisualMapController.h"
#include "Options/GeneralOptions/VisualMap/IVisualMapTextStyle.h"


namespace IIChart
{
	namespace VisualMap
	{
		/*@class
		*************************************************************************
		* 类  名: IVisualMap
		* 修  改: 2022年7月1日 15:02:44
		* 功  能: 分段型视觉映射组件
		-----------------------------------------------------------------------
		作  者:  YangPenghui 2022-10-26;
		************************************************************************/
		class IVisualMapPiecewise
			: public IBaseArrayElement
		{
		public:

			/*@function
			******************************************************************
			功  能：组件 ID。默认不指定。指定则可用于在 option 或者 API 中引用组件。
			参  数: <wzValue> ;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void SetId(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetId() const = 0;

			/*@function
			******************************************************************
			功  能：对于连续型数据，自动平均切分成几段。默认为5段。
			注  意：连续数据的范围需要 max 和 min 来指定。
			       如果设置了 visualMap-piecewise.pieces 或者 visualMap-piecewise.categories，
					则 splitNumber 无效。
			参  数: <nValue> ;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void SetSplitNumber(int nValue = 5) = 0;
			virtual int  GetSplitNumber() const = 0;

			/*@function
			******************************************************************
			功  能：创建每一段的特别的样式;
			参  数: <无> ;
			返回值：<IVisualMapPieceComponent*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual IVisualMapPieceComponent* CreatePieceComponent() = 0;

			/*@function
			******************************************************************
			功  能：增加一个区间;
			注  意：AppendPieceMin(1500); 表示此区间的最小值为1500;
				    AppendPiece(900, 1500): 在（900， 1500）之间的值;
				    AppendPieceMax(5); 表示此区间的最大值为5，
			参  数: <nValue> ;
			        <wzLabel> 为区间提示;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void AddPieceMin(int nMin, const wchar_t* wzLabel = nullptr, const wchar_t* wzColor = nullptr) = 0;
			virtual void AddPieceMax(int nMax, const wchar_t* wzLabel = nullptr, const wchar_t* wzColor = nullptr) = 0;
			virtual void AddPiece(int nMin, int nMax, const wchar_t* wzLabel = nullptr, const wchar_t* wzColor = nullptr) = 0;

			virtual int  AddPieceMin(int nMin, const wchar_t* wzLabel, IVisualMapPieceComponent* pValue) = 0;
			virtual int  AddPieceMax(int nMax, const wchar_t* wzLabel, IVisualMapPieceComponent* pValue) = 0;
			virtual int  AddPiece(int nMin, int nMax, const wchar_t* wzLabel, IVisualMapPieceComponent* pValue) = 0;

			/*@function
			******************************************************************
			功  能：增加一个指定值区间;
			说  明：AddPiece(123, L"123（自定义特殊颜色）", L"#FF55FF")表示：
			       当值为 123 时，颜色显示为 #FF55FF;
			参  数: <nValue> ;
					<wzLabel> 此段值显示的 label;
					<wzColor> 为颜色值时，必须以'#'开头，
							 1. 可以使用 RGB 表示，比如 'rgb(128, 128, 128)'\
							 2. 如果想要加上 alpha 通道，可以使用 RGBA，比如 'rgba(128, 128, 128, 0.5)'
							 3. 可以使用十六进制格式，比如 '#ccc'
							 4. 可以使用 CSS3 预定义的颜色名称，如'red'，'SlateGray';
					<pValue>  值映射在此区间的 VisualMap 属性样式, 此种方式可以设置更复杂的映射效果;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void AddPiece(int nValue, const wchar_t* wzLabel = nullptr, const wchar_t* wzColor = nullptr) = 0;
			virtual int  AddPiece(int nValue, const wchar_t* wzLabel, IVisualMapPieceComponent* pValue = nullptr) = 0;

			/*@function
			******************************************************************
			功  能：增加一个指定值开区间,例如"[10,*)", 即所有大于等10的值;
			注  意：此处的 ERelationalType 类型不支持 ERT_Eq 与 ERT_Ne;
			参  数: <eValue>  区间关系操作;
					<nValue> 区间关系操作值;
					<wzLabel> 此段值显示的 label;
					<pValue>  值映射在此区间的 VisualMap 属性样式, 此种方式可以设置更复杂的映射效果;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual int AddPiece(ERelationalType eValue, int nValue, const wchar_t* wzLabel = nullptr, const wchar_t* wzColor = nullptr) = 0;
			virtual int AddPiece(ERelationalType eValue, int nValue, const wchar_t* wzLabel, IVisualMapPieceComponent* pValue) = 0;

			/*@function
			******************************************************************
			功  能：增加一个指定值闭区间,例如"[10,100)", 即所有大于等10且小于100的值;
			注  意：此处的 ERelationalType 类型不支持 ERT_Eq 与 ERT_Ne;
			参  数: <eStart> 区间左边关系操作;
					<nStartValue> 区间左边关系操作值;
					<eEnd> 区间右边关系操作;
					<nEndRight> 区间右边关系操作值;
					<wzLabel> 此段值显示的 label;
					<pValue>  值在此区间的 VisualMap 属性样式, 此种方式可以设置更复杂的映射效果;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual int AddPiece(ERelationalType eStart, int nStartValue, ERelationalType eEnd, int nEndRight, const wchar_t* wzLabel = nullptr, const wchar_t* wzColor = nullptr) = 0;
			virtual int AddPiece(ERelationalType eStart, int nStartValue, ERelationalType eEnd, int nEndRight, const wchar_t* wzLabel, IVisualMapPieceComponent* pValue) = 0;

			/*@function
			******************************************************************
			功  能：清除添加的所有区间;
			参  数: <无> ;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void ClearPieces() = 0;

			/*@function
			******************************************************************
			功  能：清除添加的所有Ctegories;
			参  数: <无> ;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void ClearCtegories() = 0;

			/*@function
			******************************************************************
			功  能：用于表示离散型数据（或可以称为类别型数据、枚举型数据）的全集。
			参  数: <wzValue> 使用“,”分隔的纬度的值,如：“date, open, close, highest, lowest”;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual int SetCategories(const wchar_t* wzValue) = 0;

			/*@function
			******************************************************************
			功  能：用于表示离散型数据（或可以称为类别型数据、枚举型数据）的全集。
			参  数:<vctValue> Ctegories 数据;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual int SetCategories(const std::vector<std::wstring>& vctValue) = 0;

			/*@function
			******************************************************************
			功  能：用于表示离散型数据（或可以称为类别型数据、枚举型数据）的全集。
			参  数: <pQueue> Ctegories数据;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual int SetCategories(IQueue* pQueue) = 0;

			/*@function
			******************************************************************
			功  能：指定 visualMapPiecewise 组件的最小值。
			注  意：在 连续型数据自定义分段 模式（即 visualMap-piecewise.pieces 被使用）或 离散数据根据类别
				   分段 模式（即 visualMap-piecewise.categories 被使用）时，max 和 min 不需指定。
				   在 连续型数据平均分段 模式（即 (that is, when visualMap-piecewise.splitNumber 被使用时）
				   需指定 min、max，如果不指定，则默认为 [0, 200]（注意并不是默认为 series.data 的
				   dataMin 和 dataMax）。
			参  数: <nValue> ;
					<wzLabel> 为区间提示;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void SetMin(int nValue) = 0;
			virtual int GetMin() const = 0;

			/*@function
			******************************************************************
			功  能：指定 visualMapPiecewise 组件的最大值。
			参  数: <nValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void SetMax(int nValue) = 0;
			virtual int GetMax() const = 0;

			/*@function
			******************************************************************
			功  能：使用 min/max/splitNumber 时，此参数有效。
			参  数: <bValue>当值为 true 时，界面上会额外多出一个『< min』的选块。;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void SetMinOpen(bool bValue) = 0;
			virtual bool GetMinOpen() const = 0;

			/*@function
			******************************************************************
			功  能：使用 min/max/splitNumber 时，此参数有效。
			参  数: <bValue>当值为 true 时，界面上会额外多出一个『< max』的选块。;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void SetMaxOpen(bool bValue) = 0;
			virtual bool GetMaxOpen() const = 0;

			/*@function
			******************************************************************
			功  能：选择模式。
			参  数: <eValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void SetSelectedMode(EVisualMapSelectedMode eValue) = 0;
			virtual EVisualMapSelectedMode GetSelectedMode()const = 0;

			/*@function
			******************************************************************
			功  能：设置某个类别的选中状态。例如：
					 selected: {
						// 选中'系列1'
						'系列1': true,
						// 不选中'系列2'
						'系列2': false
					}
			参  数：<wzSeries> 系列名称,为 nullptr 或 L"" 时表示其他选项;
			       <bValue> true 表示选中，false 表示未选中;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void SetSelected(const wchar_t* wzSeries, bool bValue) = 0;
			virtual void ClearSelected() = 0;

			/*@function
			******************************************************************
			功  能：是否反转 visualMap 组件;
			参  数: <bValue> 为false时，数据大小的位置规则，和直角坐标系相同，即;
							 > 当 visualMap.orient 为'vertical'时，数据上大下小。
							 > 当 visualMap.orient 为'horizontal'时，数据右大左小。
							 为true时，上述情况相反。
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void SetInverse(bool bValue) = 0;
			virtual bool GetInverse() const = 0;

			/*@function
			******************************************************************
			功  能：数据展示的小数精度，默认为0，无小数点。
			参  数: <nValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void SetPrecision(int nValue) = 0;
			virtual int  GetPrecision() const = 0;

			/*@function
			******************************************************************
			功  能：图形的宽度，即长条的宽度。
			参  数: <nValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void SetItemWidth(int nValue) = 0;
			virtual int  GetItemWidth() const = 0;

			/*@function
			******************************************************************
			功  能：图形的高度，即长条的高度。
			参  数: <nValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void SetItemHeight(int nValue) = 0;
			virtual int  GetItemHeight() const = 0;

			/*@function
			******************************************************************
			功  能：指定组件中手柄和文字的摆放位置。
			注  意：本属性对 Categories 不起作用; 对 InRange、Piecces 都可以起作用;
			参  数: <eValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void SetAlign(EVisualMapPiecewiseAlign eValue) = 0;
			virtual EVisualMapPiecewiseAlign GetAlign() const = 0;

			/*@function
			******************************************************************
			功  能：两端的文本，如 ['High', 'Low'];
			参  数: <wzStart> 为 nullptr 时，不显示起始文本;
					<wzEnd> 为 nullptr 时，不显示结束文本;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void SetText(const wchar_t* wzStart, const wchar_t* wzEnd) = 0;
			virtual void GetText(wchar_t** pwzStart, wchar_t** pwzEnd) = 0;

			/*@function
			******************************************************************
			功  能：两端文字主体之间的距离，单位为 px;
			参  数: <nValue> ;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void SetTextGap(int nValue) = 0;
			virtual int  GetTextGap() const = 0;

			/*@function
			******************************************************************
			功  能：是否显示每项的文本标签。默认情况是，如果 visualMap-piecewise.text 
			       被使用则不显示文本标签，否则显示。
			参  数: <bValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void SetShowLabel(bool bValue) = 0;
			virtual bool GetShowLabel() const = 0;

			/*@function
			******************************************************************
			功  能：每两个图元之间的间隔距离，单位为px。
			参  数: <nValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void SetItemGap(int nValue) = 0;
			virtual int  GetItemGap() const = 0;

			/*@function
			******************************************************************
			功  能：默认的图形。
			参  数: <eValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void SetItemSymbol(ESymbol eValue) = 0;
			virtual ESymbol GetItemSymbol() const = 0;

			/*@function
			******************************************************************
			功  能：是否显示 visualMap-piecewise 组件。如果设置为 false，不会显示，但是数据映射的功能还存在;
			参  数: <bValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void SetShow(bool bValue) = 0;
			virtual bool GetShow() const = 0;

			/*@function
			******************************************************************
			功  能：指定用数据的『哪个维度』，映射到视觉元素上;
			参  数: <nValue> 默认取 data 中最后一个维度;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void SetDimension(int nValue) = 0;
			virtual int  GetDimension() const = 0;

			/*@function
			******************************************************************
			功  能：指定取哪个系列的数据，即哪个系列的 series.data;
			参  数: <nValue> 默认取 data 中最后一个维度;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void SetSeriesIndex(int nGridIndex) = 0;
			virtual int  GetSeriesIndex() const = 0;

			/*@function
			******************************************************************
			功  能：指定取哪个系列的数据，即哪个系列的 series.data;
			参  数: <wzValue> 使用“,”分隔的SeriesIndex;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual int SetSeriesIndex(const wchar_t* wzValue) = 0;

			/*@function
			******************************************************************
			功  能：指定取哪个系列的数据，即哪个系列的 series.data;
			参  数: <vctValue> SeriesIndex;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual int SetSeriesIndex(const std::vector<int>& vctValue) = 0;

			/*@function
			******************************************************************
			功  能：指定取哪个系列的数据，即哪个系列的 series.data;
			参  数: <pnValue> 数组指针;
					<nCount>  数组元素个数;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual int SetSeriesIndex(int* pnValue, int nCount) = 0;

			/*@function
			******************************************************************
			功  能：打开 hoverLink 功能时，鼠标悬浮到 visualMap 组件上时，鼠标位置对应
					的数值 在 图表中对应的图形元素，会高亮。反之，鼠标悬浮到图表中的图
					形元素上时，在 visualMap 组件的相应位置会有三角提示其所对应的数值。
			参  数: <bValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual void SetHoverLink(bool bValue) = 0;
			virtual bool GetHoverLink() const = 0;

			/*@function
			******************************************************************
			功  能：获取本组件的 inRange 实例;
			参  数: <无>;
			返回值：<IVisualMapRange*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual IVisualMapRange* GetInRange() = 0;

			/*@function
			******************************************************************
			功  能：获取本组件的 outOfRange 实例;
			参  数: <无>;
			返回值：<IVisualMapRange*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual IVisualMapRange* GetOutOfRange() = 0;

			/*@function
			******************************************************************
			功  能：visualMap 组件中，控制器 的 inRange outOfRange 设置。
			注  意：如果没有这个 controller 设置，控制器 会使用外层的 inRange outOfRange 设置；
					如果有这个 controller 设置，则会采用这个设置。适用于一些控制器视觉效果需要
					特殊定制或调整的场景。
			参  数: <无>;
			返回值：<IVisualMapController*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual IVisualMapController* GetController() = 0;

			/*@function
			******************************************************************
			功  能：目标系列 的视觉样式
			参  数: <无>;
			返回值：<IVisualMapTarget*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2023-1-10;
			******************************************************************/
			virtual IVisualMapTarget* GetTarget() = 0;

			/*@function
			******************************************************************
			功  能：所有图形的 zlevel 值。
			注  意: zlevel用于 Canvas 分层，不同zlevel值的图形会放置在不同的 Canvas 中，
					Canvas 分层是一种常见的优化手段。我们可以把一些图形变化频繁（例如有动画）的
					组件设置成一个单独的zlevel。需要注意的是过多的 Canvas 会引起内存开销的增大，
					在手机端上需要谨慎使用以防崩溃。
					zlevel 大的 Canvas 会放在 zlevel 小的 Canvas 的上面。
			参  数: <nLevel> ;
			返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetZLevel(int nLevel) = 0;
			virtual int  GetZLevel() const = 0;

			/*@function
			******************************************************************
			功  能：组件的所有图形的z值。控制图形的前后顺序。z值小的图形会被z值大的图形覆盖。
			注  意: z相比zlevel优先级更低，而且不会创建新的 Canvas。
			参  数: <nLevel> ;
			返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetZ(int nLevel) = 0;
			virtual int GetZ() const = 0;

			/*@function
			******************************************************************
			功  能：grid 组件离容器左侧的距离。
			参  数: <nValue> ;
				   <bIsPercent> 为 true 时 nValue 为距离左边界的百分比；
								 为 false 时 nValue 为距离左边界的像素个数；
			返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetLeft(int nValue, bool bIsPercent = false) = 0;
			virtual int GetLeft() const = 0;

			/*@function
			******************************************************************
			功  能：grid 组件离容器左侧的距离。
			注  意: 此种形式的设置，组件会根据相应的位置自动对齐
			参  数: <eValue> ;
			返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetLeft(ELeftValue eValue) = 0;
			virtual void GetLeft(ELeftValue* peValue) = 0;

			/*@function
			******************************************************************
			功  能：grid 组件离容器顶边的距离。
			参  数: <nValue> ;
				   <bIsPercent> 为 true 时 nValue 为距离顶边界的百分比；
								 为 false 时 nValue 为距离顶边界的像素个数；
			返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetTop(int nValue, bool bIsPercent = false) = 0;
			virtual int GetTop() const = 0;

			/*@function
			******************************************************************
			功  能：grid 组件离容器顶边的距离。
			注  意: 此种形式的设置，组件会根据相应的位置自动对齐
			参  数: <eValue> ;
			返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetTop(ETopValue eValue) = 0;
			virtual void GetTop(ETopValue* peValue) = 0;

			/*@function
			******************************************************************
			功  能：grid 组件离容器右侧的距离。
			参  数：<nValue> ;
					<bIsPercent> 为 true 时 nValue 为距离右侧边界的百分比；
								 为 false 时 nValue 为距离右侧边界的像素个数；
			返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetRight(int nValue, bool bIsPercent) = 0;
			virtual int GetRight() const = 0;

			/*@function
			******************************************************************
			功  能：grid 组件离容器底边界的距离。。
			参  数：<nValue> ;
					<bIsPercent> 为 true 时 nValue 为距离底边界的百分比；
								 为 false 时 nValue 为距离底边界的像素个数；
			返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetBottom(int nValue, bool bIsPercent) = 0;
			virtual int GetBottom() const = 0;

			/*@function
			******************************************************************
			功  能：如何放置 visualMap 组件，水平（'horizontal'）或者竖直（'vertical'）。
			参  数：<eValue> ;
			返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetOrient(EOrient eValue) = 0;
			virtual EOrient GetOrient()const = 0;

			/*@function
			******************************************************************
			功  能：visualMap-continuous内边距，单位 px;
			注  意: 默认各方向内边距为5，接受数组分别设定上右下左边距。
			参  数：<nValue> 边距值，例如 4：表示 padding: [4, 4, 4, 4];;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void  SetPadding(int nValue) = 0;
			virtual void  GetPadding(int* pnValue) = 0;

			/*@function
			******************************************************************
			功  能：visualMap-continuous内边距，单位 px;
			注  意: 默认各方向内边距为5，接受数组分别设定上右下左边距。
			参  数：<nValue1> 边距值1
				   <nValue2> 边距值2
				   例如 [3, 4]：表示 padding: [3, 4, 3, 4];
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void  SetPadding(int nValue1, int nValue2) = 0;
			virtual void  GetPadding(int* pnValue1, int* pnValue2) = 0;

			/*@function
			******************************************************************
			功  能：visualMap-continuous内边距，单位 px;
			注  意: 默认各方向内边距为5，接受数组分别设定上右下左边距。
			参  数：<nTop, nRight, nBottom, nLeft> 分别表示 [上, 右, 下, 左] 的边距
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetPadding(int nTop, int nRight, int nBottom, int nLeft) = 0;
			virtual void GetPadding(int* pnTop, int* pnRight, int* pnBottom, int* pnLeft) = 0;

			/*@function
			******************************************************************
			功  能：背景色，默认透明。
			注  意：为颜色值时，必须以'#'开头，
					 1. 可以使用 RGB 表示，比如 'rgb(128, 128, 128)'\
					 2. 如果想要加上 alpha 通道，可以使用 RGBA，比如 'rgba(128, 128, 128, 0.5)'
					 3. 可以使用十六进制格式，比如 '#ccc'
					 4. 可以使用 CSS3 预定义的颜色名称，如'red'，'SlateGray';
			参  数：<wzValue> 背景色16进制行;
			返回值：<无>;
			 ------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetBackgroundColor(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetBackgroundColor() const = 0;

			/*@function
			******************************************************************
			功  能：背景色，默认透明。
			参  数：<略>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetBackgroundColor(int nR, int nG, int nB, float fTransparent = 1) = 0;
			virtual void GetBackgroundColor(int* pnR, int* pnG, int* pnB, float* pfTransparent) = 0;

			/*@function
			******************************************************************
			功  能：边框颜色。
			注  意：为颜色值时，必须以'#'开头，
					 1. 可以使用 RGB 表示，比如 'rgb(128, 128, 128)'\
					 2. 如果想要加上 alpha 通道，可以使用 RGBA，比如 'rgba(128, 128, 128, 0.5)'
					 3. 可以使用十六进制格式，比如 '#ccc'
					 4. 可以使用 CSS3 预定义的颜色名称，如'red'，'SlateGray';
			参  数：<wzValue> 背景色16进制行;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetBorderColor(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetBorderColor() const = 0;

			/*@function
			******************************************************************
			功  能：边框颜色。
			参  数：<略>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetBorderColor(int nR, int nG, int nB, float fTransparent = 1) = 0;
			virtual void GetBorderColor(int* pnR, int* pnG, int* pnB, float* pfTransparent) = 0;

			/*@function
			******************************************************************
			功  能：边框线宽。
			参  数：<nValue>;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetBorderWidth(int nValue) = 0;
			virtual int GetBorderWidth() const = 0;

			/*@function
			******************************************************************
			功  能：visualMap 文字的样式;
			参  数：<无>;
			返回值：<IVisualMapTextStyle*>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual IVisualMapTextStyle* GetTextStyle() = 0;

			/*@function
			******************************************************************
			功  能：标签的格式化工具。
			注  意：字符串模板的模板变量有：
				{a}：系列名。
				{b}：数据名。
				{c}：数据值。
				{@xxx}：数据中名为 'xxx' 的维度的值，如 {@product} 表示名为 'product' 的维度的值。
				{@[n]}：数据中维度 n 的值，如 {@[3]} 表示维度 3 的值，从 0 开始计数。示例：
				formatter: '{b}: {@score}'
			参  数：<wzValue> 字符串模板;
			返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetFormatter(const wchar_t* wzValue) = 0;
			virtual wchar_t* GetFormatter() const = 0;

			/*@function
			******************************************************************
			 功  能：标签的格式化工具。
			 注  意：回调函数格式：
					(params: Object|Array) => string
					参数 params 是 formatter 需要的单个数据集。格式如下：
					{
						componentType: 'series',
						// 系列类型
						seriesType: string,
						// 系列在传入的 option.series 中的 index
						seriesIndex: number,
						// 系列名称
						seriesName: string,
						// 数据名，类目名
						name: string,
						// 数据在传入的 data 数组中的 index
						dataIndex: number,
						// 传入的原始数据项
						data: Object,
						// 传入的数据值。在多数系列下它和 data 相同。在一些系列下是 data 中的分量（如 map、radar 中）
						value: number|Array|Object,
						// 坐标轴 encode 映射信息，
						// key 为坐标轴（如 'x' 'y' 'radius' 'angle' 等）
						// value 必然为数组，不会为 null/undefied，表示 dimension index 。
						// 其内容如：
						// {
						//     x: [2] // dimension index 为 2 的数据映射到 x 轴
						//     y: [0] // dimension index 为 0 的数据映射到 y 轴
						// }
						encode: Object,
						// 维度名列表
						dimensionNames: Array<String>,
						// 数据的维度 index，如 0 或 1 或 2 ...
						// 仅在雷达图中使用。
						dimensionIndex: number,
						// 数据图形的颜色
						color: string
					}
					更详细说明，可能参考：https://echarts.apache.org/zh/option.html#series-line.type
			 参  数：<wzValue> 字符串模板;
			 返回值：<无>;
			------------------------------------------------------------------
			作  者:  YangPenghui 2022-10-26;
			******************************************************************/
			virtual void SetFormatterJSFun(const wchar_t* wzValue) = 0;

		};
	}
	
}