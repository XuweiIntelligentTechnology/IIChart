#pragma once

typedef enum _ERRORCODE
{
	ENBE_SUCCESS = 0,
	ENBE_UNKNOWN_ERROR = 1,
	ENBE_NOT_IMPLEMENT,           // 未实现;
	ENBE_INVALID_VALUE,           // 无效的值;
	ENBE_INVALID_PARM,            // 无效的参数;
	ENBE_MAX_INSTANCE_COUNT,      // 已达到最大实例数量;
	ENBE_LOAD_WEBVIEW_FAIL,       // 加载WebBrowser失败;
	ENBE_INIT_WEBVIEW_FAIL,       // 初始化WebBrowser失败;
	ENBE_ENV_NOT_INIT,            // 环境未初始化成功;
	ENBE_WBVIEW_INVALIBLE,        // WebView2 无效;
	ENBE_CHART_EXIST,             // Chart 已存在;
	ENBE_CHART_NOT_INITED,        // Chart 未初始化;

	ENBE_TYPE_MISMATCH,           // 类型不匹配;
	ENBE_INDEX_OUT_OF_RANGE,      // 序号超出范围;
	ENBE_TYPE_NOT_SUPPORT,        // 不支持此类型;
	ENBE_TYPE_NOT_FOUND,          // 没有找到;

	ENBE_SPECIAL_AREAS_NOT_JSON,  // 注册地图时，wzSpecialAreas 不是标准的json;

	ENBE_ALLOC_MEM_FAIL,          // 分配内存失败;
	ENBE_OPEN_FILE_FAIL,          // 打开文件失败;
	ENBE_READ_FILE_FAIL,          // 读取文件失败;
	ENBE_FILE_IS_EMPTY,           // 文件内容为空;
	ENBE_NOT_SUPPORT,             // 不支持当前运行;
	// EventArgs;
	ENBE_NO_PARSE,      // 参数未解析;
	ENBE_VALUE_IS_EMPTY, // 当前的值为空，值没有;

	// Rich;
	ENBE_INVALID_RICH_STYLE_NAME,            // 无效的 RichStyle 名字;
	// Dataset;
	ENBE_APPEND_JSONARRAY_FAIL, // 向Dsataset中增加 JSON 字符串失败;
	ENBE_PARSE_FILE_FAIL,       // 解析文件失败;
	// Series;
	ENBE_APPEND_SERIES_FAIL, // 向Options中增加 Series 字符串失败;

	ENBE_NAVIGATE_FAIL,
	ENBE_GOFORWORD_FAIL,
	ENBE_GOBACK_FAIL,
	ENBE_RELOAD_FAIL,            // Reload 失败;

	ENBE_COMPONENT_NOT_FOUND,    // 没有找到相应的功能组件;

	ENBE_ADD_DOCUMENT_TITLE_CHANGED_FAIL,
	ENBE_ADD_NAVIGATION_STARTING_FAIL,
	ENBE_ADD_NAVIGATION_COMPLETED_FAIL,
	ENBE_ADD_HISTORY_CHANGED_FAIL,

	ENBE_ADD_SOURCE_CHANGED_FAIL,
	ENBE_ADD_NEW_WINDOW_REQUESTED_FAIL,
	ENBE_ADD_PERMISSION_REQUESTED_FAIL,



	ENBE_CREATE_SCREENSHOT_FILE_FAIL,
	ENBE_CREATE_SCREENSHOT_FAIL, 
	ENBE_SETTING_PDF_PRINT_FAIL,  // 设置 PDF 打印失败;
	ENBE_NOT_SUPPORT_PDF_PRINTF_FAIL,  // 当前不支持 PDF 打印;

	ENBE_INJECT_SCRIPT_FAIL,
	ENBE_EXECUTE_ON_DOCUMENT_FAIL,
	ENBE_REMOVE_SCRIPT_TO_EXCU_ON_DOCUMENT_CREATED,
	ENBE_POST_WEB_MESSAGE_AS_STRING_FAIL,
	ENBE_POST_WEB_MESSAGE_AS_JSON_FAIL,

	ENBE_ADD_HOST_OBJECT_TO_SCRIPT_FAILED, // AddHostObjectToScript
	ENBE_COM_OBJECT_NOT_SUPPORT_IDISPATCH, // COM object doesn't support IDispatch
	ENBE_COCREATEiNSTANCE_FAILED,       // CoCreateInstance failed
	ENBE_CONVERT_TO_CLSID_PROGID_FAIL,  // Failed to convert string to CLSID or ProgID;

	ENBE_FILE_INVALID, // 关键文件被修改，无法完成初始化;

	// licence;
	ENBE_CHECK_AUTHCODE_FAIL,  // 检查 Authcode 失败;
	ENBE_CHECK_FILES_INTEGRITY, // 检查文件完整性;

	ENBE_MAX
}ERRORCODE;