#pragma once
/***********************************************************************
 * Module:  IGenOptionsEnum.h
 * Author:  杨鹏辉
 * Modified: 2022年7月1日 15:02:44
 * Purpose: Series 用到的公共枚举类型;
 ***********************************************************************/

namespace IIChart
{
	/* 特效显示的时机; */
	typedef enum _EShowEffectOpportunity
	{
		ERT_RENDER = 0, // 绘制完成后显示特效。
		ERT_EMPHASIS    // 高亮（hover）的时候显示特效。
	}EShowEffectOpportunity;


	typedef enum _EProgressiveChunkMode
	{
		EPC_Sequential = 0, // 按照数据的顺序分片。缺点是渲染过程不自然。
		EPC_Mod    // 取模分片，即每个片段中的点会遍布于整个数据，从而能够视觉上均匀得渲染。
	}EProgressiveChunkMode;


	typedef enum _EMarkPointDataType
	{
		EDTV_Min = 0, // 最小值。
		EDTV_Max,     // 最大值。
		EDTV_Average  // 平均值。
	}EMarkPointDataType;

	typedef enum _ERadarShape
	{
		ERS_Polygon = 0,
		ERS_Circle
	}ERadarShape;

	typedef enum _EFocus
	{
		EF_None = 0, // 不淡出其它图形，默认使用该配置。
		EF_Self,     // 只聚焦（不淡出）当前高亮的数据的图形。
		EF_Series    // 聚焦当前高亮的数据所在的系列的所有图形。
	}EFocus;

	typedef enum _EBlurScope
	{
		EBS_CoordinateSystem = 0, // 淡出范围为坐标系，默认使用该配置。
		EBS_Series,   // 淡出范围为系列。
		EBS_Global    //  淡出范围为全局。
	}EBlurScope;

	typedef enum _ESunburstFocus
	{
		ESF_None = 0, // 不淡出其它图形，默认使用该配置。
		ESF_Self = 1,       // 只聚焦（不淡出）当前高亮的数据的图形。
		ESF_Series = 2,     // 聚焦当前高亮的数据所在的系列的所有图形。
		ESF_Ancestor = 3,   // 聚焦所有祖先节点
		ESF_Descendant = 4  // 聚焦所有子孙节点
	}ESunburstFocus;


	typedef enum _EMoveOverlap
	{
		EMO_ShiftX = 0, // 水平方向依次位移，在水平方向对齐时使用
		EMO_ShiftY      // 垂直方向依次位移，在垂直方向对齐时使用
	}EMoveOverlap;


	typedef enum _EMapValueCalculation
	{
		EMVC_Sum = 0,     // 取和。
		EMVC_Average = 1, // 取平均值。
		EMVC_Max = 2, // 取最大值。
		EMVC_Min = 3  // 取最小值。
	}EMapValueCalculation;

	typedef enum _EMapRoam
	{
		EMR_False = 0,
		EMR_Scale = 1,
		EMR_Move,
		EMR_True   // 都开启;
	}EMapRoam;

	typedef enum _ESunburstSort
	{
		ESS_Desc = 0, // 默认值 'desc' 表示降序排序
		ESS_Asc = 1,  // 表示升序排序
		ESS_Null = 2  // 表示不排序，使用原始数据的顺序；或者用回调函数进行排列：
	}ESunburstSort;

	typedef enum _ESunburstNodeClick
	{
		ESNC_False = 0, // 节点点击无反应。
		ESNC_RootToNode = 1, // 点击节点后以该节点为根结点。
		ESNC_Link = 2   // 如果节点数据中有 link 点击节点后会进行超链接跳转。
	}ESunburstNodeClick;

	typedef enum _ERotate
	{
		ER_Radial = 0, // 表示径向旋转
		ER_Tangential  // 表示切向旋转。
	}ERotate;
	
	typedef enum _ESelectorPosition
	{
		ESP_Start = 0, // 控制块在左或上。
		ESP_End        // 控制块在右或下。
	}ESelectorPosition;

	typedef enum _EPageButtonPosition
	{
		EPBP_Start = 0, // 控制块在左或上。
		EPBP_End        // 控制块在右或下。
	}EPageButtonPosition;

	typedef enum _EToolboxBrushType
	{
		ETBT_Rect = 0,
		ETBT_Polygon,
		ETBT_LineX,
		ETBT_LineY,
		ETBT_Keep,
		ETBT_Clear
	}EToolboxBrushType;

	typedef enum _EImageType
	{
		EIT_Png = 0,
		EIT_Jpg,
		EIT_Svg   
	}EImageType;

	typedef enum _EFilterMode
	{
		EFM_Filter = 0, // 'filter'：当前数据窗口外的数据，被 过滤掉。即 会 影响其他轴的数据范围。每个数据项，只要有一个维度在数据窗口外，整个数据项就会被过滤掉。
		EFM_WeakFilter, // 当前数据窗口外的数据，被 过滤掉。即 会 影响其他轴的数据范围。每个数据项，只有当全部维度都在数据窗口同侧外部，整个数据项才会被过滤掉。
		EFM_Empty,  // 当前数据窗口外的数据，被 设置为空。即 不会 影响其他轴的数据范围。
		EFM_None    // 不过滤数据，只改变数轴范围。
	}EFilterMode;

	typedef enum _EZoomType
	{
		EZT_True,  // 表示不按任何功能键，鼠标滚轮能触发缩放。
		EZT_False, // 表示鼠标滚轮不能触发缩放。
		EZT_Shift, // 表示按住 shift 和鼠标滚轮能触发缩放。
		EZT_Ctrl,  // 表示按住 ctrl 和鼠标滚轮能触发缩放。
		EZT_Zlt    // 表示按住 alt 和鼠标滚轮能触发缩放。
	}EZoomType;


	typedef enum _ETimeLinePosition
	{
		ETLP_Auto = 0, //  完全自动决定。
		ETLP_Left,     // 贴左边界放置。 当 timline.orient 为 'vertical' 时有效。
		ETLP_Right,    // 当 timline.orient 为 'vertical' 时有效。 贴右边界放置。
		ETLP_Top,      // 贴上边界放置。 当 timline.orient 为 'horizontal' 时有效。
		ETLP_Bottom    // 贴下边界放置。 当 timline.orient 为 'horizontal' 时有效。
	}ETimeLinePosition;


	typedef enum _ETimeLineType
	{
		ETLT_Slider // 这个属性目前只支持为 slider，不需要更改。
	}ETimeLineType;

	typedef enum _ETooltipAxisPointerType
	{
		EAPT_Line,   // 直线指示器;
		EAPT_Shadow, // 阴影指示器
		EAPT_None,   // 无指示器
		EAPT_Cross   // 十字准星指示器。其实是种简写，表示启用两个正交的轴的 axisPointer。
	}ETooltipAxisPointerType;

	typedef enum _ERelationalType
	{
		ERT_Lt = 0, // 小于，less than
		ERT_Gt,     // 大于，greater than
		ERT_Lte,    // 小于等于less than or equals
		ERT_Gte,    // 大于等于，greater than or equals
		ERT_Eq,     // 等于;
		ERT_Ne      // 不等于;
	}ERelationalType;

	typedef enum _ETransformSort
	{
		ETS_Desc = 0, // 默认值 'desc' 表示降序排序
		ETS_Asc = 1,  // 表示升序排序
		ETS_Null = 2  // 表示不排序，使用原始数据的顺序；或者用回调函数进行排列：
	}ETransformSort;

	typedef enum _EParserType
	{
		EPT_Time = 0, // 把原始值解析成时间戳（ timestamp ）后再做比较。
		              // 当原始值为是时间戳，或者是描述时间的字符串（例如 '2012-05-12 03:11:22' ），
					  // 都可以被解析为时间戳，然后就可以基于数值大小进行比较。
					  // 如果原始数据是其他不可解析为时间戳的值，那么会被解析为 NaN。
		
		EPT_Trim,     // 如果原始数据是字符串，则把字符串两端的空格（全角半角）和换行符去掉。如果不是字符串，还保持为原始数据。
		
		EPT_Number    // 强制把原始数据转成数值。如果不能转成有意义的数值，那么转成 NaN。
		              // 在大多数场景下，我们并不需要这个解析器，因为按默认策略，“像数值的字符串”就会被转成数值。
		              // 但是默认策略比较严格，这个解析器比较宽松，如果我们遇到含有尾缀的字符串（例如 '33%', 12px），
		              // 我们需要手动指定 parser: 'number'，从而去掉尾缀转为数值才能比较。
	}EParserType;

	typedef enum _ESourceHeader
	{
		ESH_Auto = 0, // 默认，自动探测
		ESH_Header,   // 第一行/列是维度名信息
		ESH_Data      // 第一行/列直接开始是数据
	}ESourceHeader;

	typedef enum _ETransformType
	{
		ETT_Filter = 0, // 默认，自动探测
		ETT_Sort,   // 第一行/列是维度名信息
		ETT_Regression,
		ETT_Boxplot,
		ETT_Cluster,
		ETT_Aggregate
	}ETransformType;


	// 坐标轴类型
	typedef enum _ERCTAxisType
	{
		E_Category = 0,
		E_Value,
		E_Time,
		E_Log
	}ERCTAxisType;

	// 坐标轴名称显示位置
	typedef enum _ENameLocation
	{
		ENL_Start = 0,
		ENL_Center,
		ENL_End,
	}ENameLocation;

	// x/y 轴的位置
	typedef enum _EAxisPosition
	{
		EAP_Top = 0,
		EAP_Bottom
	}EAxisPosition;

	// x/y 轴的位置
	typedef enum _ETimeLineControlPosition
	{
		ETLCP_Left = 0,
		ETLCP_Right
	}ETimeLineControlPosition;


	//typedef enum _ESeriesLayoutBy
	//{
	//	ESLB_Colume = 0, // 默认，dataset 的列对应于系列，从而 dataset 中每一列是一个维度（dimension）。
	//	ESLB_Row    // dataset 的行对应于系列，从而 dataset 中每一行是一个维度（dimension）。

	//}ESeriesLayoutBy;

	//// 堆积数值的策略，前提是stack属性已被设置。其值可以是：
	//typedef enum _EStackStrategy
	//{
	//	ESS_Samesign = 0, // 只在要堆叠的值与当前累积的堆叠值具有相同的正负符号时才堆叠。
	//	ESS_All,      // 堆叠所有的值，不管当前或累积的堆叠值的正负符号是什么。
	//	ESS_Positive, // 只堆积正值。
	//	ESS_Negative, // 只堆叠负值。

	//}EStackStrategy;

	//typedef enum _EStepType
	//{
	//	EST_None = 0,   // 不显示;
	//	EST_Auto = 1,    // 系统自动方式显示;
	//	EST_Start,       // 在当前点。
	//	EST_Middle,      // 当前点与下个点的中间点。
	//	EST_End,         // 下个点拐弯。

	//}EStepType;

	
	typedef enum _EInactiveBorderWidthType
	{
		EIBWT_Auto = 0,   // 不支持选择;
		EIBWT_Inherit = 1 // 单选。
	}EInactiveBorderWidthType;

	typedef enum _ELegendSelectedMode
	{
		ELSM_None = 0,   // 不支持选择;
		ELSM_Single = 1, // 单选。
		ELSM_Multiple    // 多选。
	}ELegendSelectedMode;

	typedef enum _EVisualMapSelectedMode
	{
		EVMSM_None = 0,   // 不支持选择;
		EVMSM_Single = 1, // 单选。
		EVMSM_Multiple   // 多选。
	}EVisualMapSelectedMode;

	//typedef enum _ESelectedMode
	//{
	//	ESM_None = 0,   // 不支持选择;
	//	ESM_Single = 1, // 单选。
	//	ESM_Multiple,   // 多选。
	//	ESM_Series,     // 选择整个系列。
	//}ESelectedMode;

	//typedef enum _ESmoothMonotone
	//{
	//	ESMM_None = 0,
	//	ESMM_X,   // 在 x 轴上保持单调性。
	//	ESMM_Y    // 在 y 轴上保持单调性。
	//}ESmoothMonotone;

	//typedef enum _ESampling
	//{
	//	ES_None = 0,// 关闭此功能;
	//	ES_Lttb = 0,// 采用 Largest-Triangle-Three-Bucket 算法，可以最大程度保证采样后线条的趋势，形状和极值。
	//	ES_Average, // 取过滤点的平均值
	//	ES_Max,     //  取过滤点的最大值
	//	ES_Min,     // 取过滤点的最小值
	//	ES_Sum      // 取过滤点的和
	//}ESampling;

	// 南丁格尔图
	typedef enum _ERoseType
	{
		ERT_None = 0, // 不显示;
		ERT_Raius,    // 扇区圆心角展现数据的百分比，半径展现数据的大小。
		ERT_Area      // 所有扇区圆心角相同，仅通过半径展现数据大小。
	}ERoseType;

	typedef enum _EDivideShape
	{
		EDS_Split = 0, // 通过一定的算法将分割图形成为多个。
		EDS_Clone      // 从当前图形克隆得到多个。
	}EDivideShape;


	typedef enum _EAlignTo
	{
		EAT_None = 0,  // 默认label line 的长度为固定值，分别为 labelLine.length 及 labelLine.length2。
		EAT_LabelLine, // label line 的末端对齐，其中最短的长度由 labelLine.length2 决定。
		EAT_Edge       // 文字对齐，文字的边距由 label.edgeDistance 决定。
	}EAlignTo;

	// 指示器的坐标轴。
	typedef enum _ETimeLineAxisType
	{
		ETLT_Value = 0,
		ETLT_Category = 1,
		ETLT_Time
	}ETimeLineAxisType;

	// 指示器的坐标轴。
	typedef enum _EAxisType
	{
		ELS_Auto = 0,
		ELS_X = 1,
		ELS_Y, 
		ELS_Radius,
		ELS_Angle
	}EAxisType;

	// 线的类型。
	typedef enum _EAxisPointerType
	{
		ELS_Line = 0, // 直线指示器
		ELS_Shadow,   // 阴影指示器
		ELS_None      // 无指示器
	}EAxisPointerType;

	typedef enum _EMarkLineDataType
	{
		EMDTV_Min = 0, // 最小值。
		EMDTV_Max,     // 最大值。
		EMDTV_Average, // 平均值。
		EMDTV_None
	}EMarkLineDataType;

	typedef enum _EValueDim
	{
		EVD_X = 0,
		EVD_Y,
		EVD_Radius,
		EVD_Angle,
		EVD_Open,
		EVD_Close,
		EVD_None
	}EValueDim;

	// Dimensions数据的类型;
	typedef enum _EDDTypeValue
	{
		EDTV_Number = 0, // 默认，表示普通数据。
		EDTV_Ordinal,    // 对于类目、文本这些 string 类型的数据，如果需要能在数轴上使用，
						 // 须是 'ordinal' 类型。ECharts 默认会自动判断这个类型。
						 // 但是自动判断也是不可能很完备的，所以使用者也可以手动强制指定。
		EDTV_Float,
		EDTV_Int,
		EDTV_Time        // 表示时间类型。设置成 'time' 则能支持自动解析数据成时间戳（timestamp），
						// 比如该维度的数据是 '2017-05-10'，会自动被解析。时间类型的支持参见 data。
	}EDDTypeValue;

	typedef enum _EPosition
	{
		EP_Top = 1,
		EP_Left,
		EP_Right,
		EP_Bottom,
		EP_Inside,
		EP_InsideLeft,
		EP_InsideRight,
		EP_InsideTop,
		EP_InsideBottom,
		EP_InsideTopLeft,
		EP_InsideBottomLeft,
		EP_InsideTopRight,
		EP_InsideBottomRight
	}EPosition;

	// 线的类型。
	typedef enum _ELineStyle
	{
		ELS_Solid = 0,
		ELS_Dashed,
		ELS_Dotted
	}ELineStyle;

	// 用于指定线段末端的绘制方式
	typedef enum _ECapStyle
	{
		ECS_Butt = 0, // 线段末端以方形结束
		ECS_Round,    // 线段末端以圆形结束
		ECS_Square    // 线段末端以方形结束，但是增加了一个宽度和线段相同，高度是线段厚度一半的矩形区域。
	}ECapStyle;

	// 用于设置2个长度不为0的相连部分（线段，圆弧，曲线）如何连接在一起的属性
	typedef enum _EJoinStyle
	{
		EJS_Bevel = 0, // 在相连部分的末端填充一个额外的以三角形为底的区域， 每个部分都有各自独立的矩形拐角。
		EJS_Round,     // 通过填充一个额外的，圆心在相连部分末端的扇形，绘制拐角的形状。 圆角的半径是线段的宽度。
		EJS_Miter      // 通过延伸相连部分的外边缘，使其相交于一点，形成一个额外的菱形区域。这个设置可以通过 miterLimit 属性看到效果。
	}EJoinStyle;


	typedef enum _EBorderCap
	{
		EBC_Butt = 0, // 线段末端以方形结束。
		EBC_Round,    // 线段末端以圆形结束。
		EBC_Square    // 线段末端以方形结束，但是增加了一个宽度和线段相同，高度是线段厚度一半的矩形区域。
	}EBorderCap;

	typedef enum _EBorderJoin
	{
		EBJ_Bevel = 0, // 在相连部分的末端填充一个额外的以三角形为底的区域， 每个部分都有各自独立的矩形拐角。
		EBJ_Round,     // 通过填充一个额外的，圆心在相连部分末端的扇形，绘制拐角的形状。 圆角的半径是线段的宽度。
		EBJ_Miter      // 通过延伸相连部分的外边缘，使其相交于一点，形成一个额外的菱形区域。这个设置可以通过
					  // borderMiterLimit 属性看到效果。
	}EBorderJoin;

	// 图形区域的起始位置。
	typedef enum _EOrigin
	{
		EO_Auto = 0, // 填充坐标轴轴线到数据间的区域（默认值）
		EO_Start,    // 填充坐标轴底部（非 inverse 情况是最小值）到数据间的区域
		EO_End,      // 填充坐标轴顶部（非 inverse 情况是最大值）到数据间的区域
	}EOrigin;


	// 文字字体的风格;
	typedef enum _EFontStyle
	{
		EFS_Normal = 0, // 常规
		EFS_Italic,     // 斜体
		EFS_Oblique     // 加粗
	}EFontStyle;

	// 文字字体的粗细;
	typedef enum _EFontWeight
	{
		EFW_Normal = 0,
		EFW_Bold,
		EFW_Bolder,
		EFW_Lighter
	}EFontWeight;



	// 指定选框的类型。可以为 'polygon', 'rect', 'lineX', 'lineY'
	typedef enum _EBrushType
	{
		EBT_Polygon = 0, // 选框为多边形
		EBT_Rect,
		EBT_LineX,
		EBT_LineY
	}EBrushType;

	// 指定选框的类型。可以为 'polygon', 'rect', 'lineX', 'lineY'
	typedef enum _EBrushMode
	{
		EBM_Single = 0,
		EBM_Multiple
	}EBrushMode;


	// 否截断或者换行。
	typedef enum _EOverflow
	{
		EO_None = 0,
		EO_Truncate, // 截断，并在末尾显示ellipsis配置的文本，默认为...
		EO_Break,        // 换行
		EO_Breakall      // 换行，跟'break'不同的是，在英语等拉丁文中，'breakAll'还会强制单词内换行
	}EOverflow;

	// 边框描边类型。
	typedef enum _EBorderType
	{
		EBT_Solid = 0,
		EBT_Dashed,
		EBT_Dotted
	}EBorderType;

	// 朝向。
	typedef enum _EOrient
	{
		EO_Horizontal = 0, // 水平;
		EA_Vertical // 垂直;
	}EOrient;

	// 水平对齐方式，默认自动。
	typedef enum _EVisualMapAlign
	{
		EVMA_Auto = 0, // 自动决定
		EVMA_Left,     // 手柄和label在右，orient 为 horizontal 时有效。
		EVMA_Right,    // 手柄和label在左，orient 为 horizontal 时有效。
		EVMA_Top,      // 手柄和label在下，orient 为 vertical 时有效。
		EVMA_Bottom    // 手柄和label在上，orient 为 vertical 时有效。
	}EVisualMapAlign;

	// 水平对齐方式，默认自动。
	typedef enum _EVisualMapPiecewiseAlign
	{
		EVMPA_Auto = 0, // 自动决定
		EVMPA_Left,     // 图形在左文字在右。
		EVMPA_Right    // 图形在右文字在左。
	}EVisualMapPiecewiseAlign;

	// 图例标记和文本的对齐;
	typedef enum _ELegendAlign
	{
		ELA_Auto = 0,
		ELA_Left,
		ELA_Right
	}ELegendAlign;

	// 水平对齐方式，默认自动。
	typedef enum _EAlign
	{
		EA_Auto = 0,
		EA_Left,
		EA_Center,
		EA_Right
	}EAlign;

	// 垂直对齐方式，默认自动。
	typedef enum _EVerticalAlign
	{
		EVA_Auto = 0,
		EVA_Top,
		EVA_Middle,
		EVA_Bottom
	}EVerticalAlign;

	/* 图例的类型 */
	typedef enum _ELegendType
	{
		ELT_Plain = 0, // 普通图例。缺省就是普通图例。
		ELT_Scroll     // 可滚动翻页的图例。当图例数量较多时可以使用。
	}ELegendType;


	typedef enum _EColorBy
	{
		ECB_Series = 0, // 按照系列分配调色盘中的颜色，同一系列中的所有数据都是用相同的颜色；
		ECB_Data,       // 按照数据项分配调色盘中的颜色，每个数据项都使用不同的颜色。

	}EColorBy;

	typedef enum _ECoordinateSystem
	{
		ECS_Cartesian2d = 0, // 使用二维的直角坐标系（也称笛卡尔坐标系），通过 xAxisIndex, yAxisIndex指定相应的坐标轴组件；
		ECS_Ploar,   // 使用极坐标系，通过 polarIndex 指定相应的极坐标组件。
		ECS_Geo          // 使用地理坐标系，通过 geoIndex 指定相应的地理坐标系组件。
	}ECoordinateSystem;

	typedef enum _ESymbol
	{
		ES_EmptyCircle = 0,
		ES_Circle,
		ES_Rect,
		ES_RoundRect,
		ES_Triangle,
		ES_Diamond,
		ES_Pin,
		ES_Arrow,
		ES_None
	}ESymbol;

	typedef enum _EShowAllSymbol
	{
		ES_Auto = 0, // 默认，如果有足够空间则显示标志图形，否则随主轴标签间隔隐藏策略。
		ES_All, // 显示所有图形.
		ES_Main // 随主轴标签间隔隐藏策略。
	}EShowAllSymbol;

	// 触发类型。
	typedef enum _ETrigger
	{
		ETT_Item = 0, // 数据项图形触发，主要在散点图，饼图等无类目轴的图表中使用。
		ETT_Axis,     // 坐标轴触发，主要在柱状图，折线图等会使用类目轴的图表中使用。
		ETT_None      // 什么都不触发。
	}ETrigger;

	// 颜色渐变类型;
	typedef enum _EColorType
	{
		ECT_None,    // 纹理;
		ECT_Linear,  // 线性渐变
		ECT_Radial   // 径向渐变
	}EColorType;

	// 纹理填充图片平铺类型;
	typedef enum _ERepeatType
	{
		ERT_Repeat, 
		ERT_RepeatX,
		ERT_RepeatY,
		ERT_NoRepeat
	}ERepeatType;

	typedef enum _EAnimationEasing
	{
		EAE_Linear = 0, 
		EAE_QuadraticIn, 
		EAE_QuadraticOut,
		EAE_QuadraticInOut,
		EAE_CubicIn,
		EAE_CubicOut,

		EAE_CubicInOut,
		EAE_QuarticIn,
		EAE_QuarticOut,
		EAE_QuarticInOut,
		EAE_QuinticIn,
		EAE_QuinticOut,

		EAE_QuinticInOut,
		EAE_SinusoidalIn,
		EAE_SinusoidalOut,
		EAE_SinusoidallInOut,
		EAE_ExponentialIn,
		EAE_ExponentialOut,
		
		EAE_ExponentialInOut,
		EAE_CircularIn,
		EAE_CircularOut,
		EAE_CircularInOut,
		EAE_ElasticIn,
		EAE_ElasticOut,
		
		EAE_ElasticInOut,
		EAE_BackIn,
		EAE_BackOut,
		EAE_BackInOut,
		EAE_BounceIn,
		EAE_BounceOut,

		EAE_BounceInOut
		
	}EAnimationEasing;


	typedef enum _EQueueDataType
	{
		EFQDT_Int = 0,  // int 类型;
		EFQDT_Float = 1,// float 类型;
		EFQDT_WChar,    // wchar_t* 类型;
		EFQDT_Object,   // IBaseArrayElement* 实例;
		EFQDT_None      // 不存在值;
	}EQueueDataType;

	// Screenshot 的格式;
	typedef enum _EPrintImageFormat
	{
		EIF_PNG = 0, // 默认值，以纵向打印页面;
		EIF_JPEG = 1 // 横向打印页面;
	}EPrintImageFormat;


	typedef enum _ESeriesLayoutBy
	{
		ESLB_Colume = 0, // 默认，dataset 的列对应于系列，从而 dataset 中每一列是一个维度（dimension）。
		ESLB_Row    // dataset 的行对应于系列，从而 dataset 中每一行是一个维度（dimension）。

	}ESeriesLayoutBy;


	// 堆积数值的策略，前提是stack属性已被设置。其值可以是：
	typedef enum _EStackStrategy
	{
		ESS_Samesign = 0, // 只在要堆叠的值与当前累积的堆叠值具有相同的正负符号时才堆叠。
		ESS_All,      // 堆叠所有的值，不管当前或累积的堆叠值的正负符号是什么。
		ESS_Positive, // 只堆积正值。
		ESS_Negative, // 只堆叠负值。

	}EStackStrategy;

	typedef enum _EStepType
	{
		EST_None = 0,   // 不显示;
		EST_Auto = 1,    // 系统自动方式显示;
		EST_Start,       // 在当前点。
		EST_Middle,      // 当前点与下个点的中间点。
		EST_End,         // 下个点拐弯。

	}EStepType;

	typedef enum _ESelectedMode
	{
		ESM_None = 0,   // 不支持选择;
		ESM_Single = 1, // 单选。
		ESM_Multiple,   // 多选。
		ESM_Series,     // 选择整个系列。

	}ESelectedMode;

	typedef enum _ESmoothMonotone
	{
		ESMM_None = 0,
		ESMM_X,   // 在 x 轴上保持单调性。
		ESMM_Y    // 在 y 轴上保持单调性。
	}ESmoothMonotone;

	typedef enum _ESampling
	{
		ES_Disable = 0,// 关闭此功能;
		ES_Lttb,    // 采用 Largest-Triangle-Three-Bucket 算法，可以最大程度保证采样后线条的趋势，形状和极值。
		ES_Average, // 取过滤点的平均值
		ES_Max,     // 取过滤点的最大值
		ES_Min,     // 取过滤点的最小值
		ES_Sum      // 取过滤点的和
	}ESampling;

	typedef enum _ELeftValue
	{
		ELV_Left = 0,
		ELV_Center = 1,
		ELV_Right
	}ELeftValue;

	typedef enum _ETopValue
	{
		ETV_Top = 0,
		ETV_Middle = 1,
		ETV_Bottom
	}ETopValue;

	// 指定窗口打开主标题超链接。
	typedef enum _ETitleTarget
	{
		ETT_Self = 0, // 当前窗口打开
		ETT_Blank     // 新窗口打开
	}ETitleTarget;
}
