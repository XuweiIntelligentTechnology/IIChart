# IIChart (Intelligent Industrial Chart Control)

`IIChart` is a native C++ chart control for MFC/Win32 applications. It ports Apache ECharts to desktop through WebView2 and can be deployed through Visual Studio NuGet Package Manager.

## Version

- Current package: `1.0.0.3`
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
3. Install the package.
4. Build the project using `Win32` platform.

After installation, you can include headers directly, for example:

```cpp
#include "IIIChart.h"
```

## License / watermark policy

- The control is free to use.
- The free mode displays a watermark in charts.
- A paid licence subscription is required to remove the watermark.

## Notes

- This package depends on WebView2 runtime and references `Microsoft.Web.WebView2`.
- If your project builds as `x64`, package `1.0.0.3` will fail the build intentionally; use `Win32` for this version.
