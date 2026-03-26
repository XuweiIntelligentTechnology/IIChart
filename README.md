# IIChart (Intelligent Industrial Chart Control)

`IIChart` is a native C++ chart control for MFC/Win32 applications. It ports Apache ECharts to desktop through WebView2 and can be deployed through Visual Studio NuGet Package Manager.

## Version

- Current package: `1.0.0.4`
- Platform support: `x86 / Win32` only
- Planned next version: `1.0.1.0` (adds `x64` support)

## What this package provides

- Public header files under `build/native/include`
- Native binaries and runtime resources under `build/native/bin/<platform>/<configuration>`
- Auto integration through `build/native/IIChartControl.targets`
  - Adds include directory
  - Adds library directories and `.lib` dependencies
  - Copies runtime files (such as chart resources and related binaries) to output directory

## Install

Install in Visual Studio:

1. Open **Manage NuGet Packages** for your C++ project.
2. Search for `IIChart`.
3. Install the package (this repo’s demo also references `Microsoft.Web.WebView2`).
4. Build the project using `Win32` platform.

After installation, you can include headers directly, for example:

```cpp
#include "IIIChart.h"
```

## Usage

1. **Host window**  
   Place a child window (for example a **Picture Control** or static placeholder) on your dialog or view. You will pass its `HWND` to the chart manager.

2. **MFC**  
   Call `AfxEnableControlContainer()` in `InitInstance()` before showing dialogs that host ActiveX / WebView2 content.

3. **Lifecycle**  
   - Create `IChartManager` and `IGlobalUtility` with `IIChart::CreateChartManager()` and `IIChart::CreateGlobalUtility()`.  
   - Call `IChartManager::Init(hwnd)` with the host control’s `HWND` (after the control exists, typically in `OnInitDialog`).  
   - Create an `IChart` via `CreateChart`, configure size via `GetSetting()`, then build axes and series from `GetGeneralOptions()`.  
   - Call `IChart::SetOption()` to apply or refresh the chart (including after data updates).

4. **Axes and series**  
   - X axis: often `ERCTAxisType::E_Category` with `AddData` for comma-separated category labels (wide strings).  
   - Y axis: often `ERCTAxisType::E_Value`.  
   - Add axes with `GetGeneralOptions()->Add(...)`.  
   - Create a line series with `GetSeries()->CreateLineType()`, `SetData` with comma-separated numbers or a `std::vector<int>`, then `AppendSeries`.  
   - Call `SetOption()` again to redraw after changing data.

5. **Return codes**  
   `Init` and `CreateChart` use output parameters / return values; check for non-zero failures as in the example below.

This repository’s **IIChartTest** MFC dialog demonstrates the full flow (`IIChartTestDlg.cpp` / `IIChartTestDlg.h`).

## Example code

The following is adapted from this demo: initialize the manager on a dialog control `IDC_CHART`, then show a line chart and update series data.

**Header (member pointers and include):**

```cpp
#include "IIIChart.h"
using namespace IIChart;

class CMyDlg : public CDialogEx
{
    // ...
private:
    IChartManager* m_pChartManager = nullptr;
    IGlobalUtility* m_pGlobalUtility = nullptr;
    IChart* m_pChart = nullptr;
    Axis::IAxis* m_pXAxis = nullptr;
    Axis::IAxis* m_pYAxis = nullptr;
    Line::ILineType* m_pLineType = nullptr;
};
```

**Initialize WebView2 host on the chart control `HWND`:**

```cpp
int CMyDlg::InitChart()
{
    int nResult = 0;
    HWND hWnd = GetDlgItem(IDC_CHART)->GetSafeHwnd();

    try
    {
        m_pChartManager = IIChart::CreateChartManager();
        m_pGlobalUtility = IIChart::CreateGlobalUtility();

        nResult = m_pChartManager->Init(hWnd);
        if (nResult != 0)
            return nResult;
    }
    catch (...)
    {
        return 1;
    }
    return nResult;
}
```

**Create a line chart (call after `InitChart`, e.g. when the user clicks “Show chart”):**

```cpp
int CMyDlg::ShowLineChart()
{
    int nResult = 0;
    CWnd* pWnd = GetDlgItem(IDC_CHART);
    CRect rect;
    pWnd->GetWindowRect(&rect);
    int width = rect.Width();
    int height = rect.Height() - 50;  // optional: reserve space for UI

    try
    {
        m_pChart = m_pChartManager->CreateChart(nResult);
        m_pChart->GetSetting()->SetWidth(width);
        m_pChart->GetSetting()->SetHeight(height);
        m_pChart->Init();

        m_pXAxis = m_pChart->GetGeneralOptions()->GetXAxis();
        m_pXAxis->SetType(ERCTAxisType::E_Category);
        m_pXAxis->AddData(L"Mon,Tue,Wed,Thu,Fri,Sat,Sun");

        m_pYAxis = m_pChart->GetGeneralOptions()->GetYAxis();
        m_pYAxis->SetType(ERCTAxisType::E_Value);

        m_pChart->GetGeneralOptions()->Add(m_pXAxis);
        m_pChart->GetGeneralOptions()->Add(m_pYAxis);

        m_pLineType = m_pChart->GetGeneralOptions()->GetSeries()->CreateLineType();
        m_pLineType->SetData(L"1,21,25,65,85,14,23");
        m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(m_pLineType);

        m_pChart->SetOption();
    }
    catch (...) { }

    return 0;
}
```

**Update series data at runtime:**

```cpp
void CMyDlg::OnUpdateData()
{
    std::vector<int> vctData = { /* fill your values */ };
    m_pLineType->SetData(vctData);
    m_pChart->GetGeneralOptions()->GetSeries()->AppendSeries(m_pLineType);
    m_pChart->SetOption();
}
```

In **OnInitDialog**, call `InitChart()` once the dialog and `IDC_CHART` exist. Wire buttons or menus to `ShowLineChart()` and your update handler as needed.

---

## 中文：使用说明

1. **宿主窗口**  
   在对话框或视图中放一个子窗口控件（如 **Picture Control** 或占位静态控件），记下其资源 ID（示例中为 `IDC_CHART`），将其 `HWND` 传给 `IChartManager::Init`。

2. **MFC 环境**  
   在 `InitInstance()` 里、显示对话框之前调用 `AfxEnableControlContainer()`，以便嵌入 WebView2 等容器类控件。

3. **典型调用顺序**  
   - 使用 `IIChart::CreateChartManager()`、`IIChart::CreateGlobalUtility()` 创建管理器与全局工具接口。  
   - 在控件已创建后（例如 `OnInitDialog`）对宿主控件调用 `m_pChartManager->Init(hWnd)`。  
   - 用 `CreateChart` 创建图表，通过 `GetSetting()` 设置宽高，必要时先 `Init()`。  
   - 通过 `GetGeneralOptions()` 配置 X/Y 轴类型与数据，`GetSeries()` 创建折线并 `AppendSeries`。  
   - 每次配置或修改数据后调用 `SetOption()` 刷新显示。

4. **数据格式**  
   - 分类轴可用 `AddData` 传入逗号分隔的宽字符串（如 `L"周一,周二,..."`）。  
   - 折线数据可用 `SetData` 传入逗号分隔数字字符串，或 `std::vector<int>`。  
   - 更新数据后同样需要 `AppendSeries`（与演示工程一致）并再次 `SetOption()`。

5. **本仓库示例**  
   完整可编译示例见 **IIChartTest** 工程中的 `IIChartTestDlg.h` / `IIChartTestDlg.cpp`：`InitChart` 在 `OnInitDialog` 中调用；“显示图表”按钮调用 `ShowLineChart`；“更新”按钮随机生成 7 个整数并刷新折线。

## 中文：示例代码要点

与上文英文示例一致：头文件中包含 `IIIChart.h` 并 `using namespace IIChart`；在 `OnInitDialog` 里 `InitChart()`；按钮触发 `ShowLineChart()` 展示默认折线；更新时用 `m_pLineType->SetData(vctData)`，再 `AppendSeries` 与 `SetOption()`。分类轴示例使用中文标签：

```cpp
m_pXAxis->AddData(L"周一,周二,周三,周四,周五,周六,周日");
m_pLineType->SetData(L"1,21,25,65,85,14,23");
```

## License / watermark policy

- The control is free to use.
- The free mode displays a watermark in charts.
- A paid licence subscription is required to remove the watermark.

## Notes

- This package depends on WebView2 runtime and references `Microsoft.Web.WebView2`.
- If your project builds as `x64`, package `1.0.0.4` will fail the build intentionally; use `Win32` for this version.
