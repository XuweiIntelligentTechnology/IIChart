
// IIChartTestDlg.h: 头文件
//

#pragma once

#include "IIIChart.h"

using namespace IIChart;

// CIIChartTestDlg 对话框
class CIIChartTestDlg : public CDialogEx
{
// 构造
public:
	CIIChartTestDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_IICHARTTEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

	int InitChart();
	int ShowLineChart();
	int UpdateChartData();


private:
	IChartManager* m_pChartManager = nullptr;
	IGlobalUtility* m_pGlobalUtility = nullptr;

	IChart* m_pChart = nullptr;
	Axis::IAxis* m_pXAxis = nullptr;
	Axis::IAxis* m_pYAxis = nullptr;
	Line::ILineType* m_pLineType = nullptr;

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
	afx_msg void OnBnClickedButtonShowChart();
	afx_msg void OnBnClickedButtonUpdate();
};
