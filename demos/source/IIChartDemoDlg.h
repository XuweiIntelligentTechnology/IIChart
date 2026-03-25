
// IIChartDemoDlg.h: 头文件
//

#pragma once
#include "CChartEventDelegate.h"
#include "CChartManagerDelegateImp.h"
#include "CaseService.h"

// CIIChartDemoDlg 对话框
class CIIChartDemoDlg : public CDialogEx
{
// 构造
public:
	CIIChartDemoDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_IICHARTDEMO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

public:
	void OutputError(const wchar_t* fmt, ...);
	void OutputLine(const wchar_t* fmt, ...);

	void InitUIControl();
	void UpdateListControl();

	void RunCurrentFunction();

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CChartEventDelegate* m_pChartDelegate = nullptr;
	CChartManagerDelegateImp* m_pChartManagerDelegate = nullptr;

	CCaseService* m_pCaseService = nullptr;

	CString m_strMessage;
	CEdit m_editMessage;
	CComboBox m_combCase;
	CListBox m_lstFunction;

	wstring m_wsCurrentCase = L"";
	afx_msg void OnLbnDblclkListFunction();
	afx_msg void OnCbnSelchangeComboCase();
};
