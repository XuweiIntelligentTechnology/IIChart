// pch.h: 这是预编译标头文件。
// 下方列出的文件仅编译一次，提高了将来生成的生成性能。
// 这还将影响 IntelliSense 性能，包括代码完成和许多代码浏览功能。
// 但是，如果此处列出的文件中的任何一个在生成之间有更新，它们全部都将被重新编译。
// 请勿在此处添加要频繁更新的文件，这将使得性能优势无效。

#ifndef PCH_H
#define PCH_H

// 添加要在此处预编译的标头

#include "framework.h"
#include <vector>
#include <string>
#include "IIIChart.h"
#include "ICase.h"

using namespace std;

inline wstring GetCurrentPath()
{
	wstring wsPath;
	TCHAR  szModlePath[MAX_PATH] = { 0 };

	// 取 DLL 路径;
	if (GetModuleFileName(nullptr, szModlePath, MAX_PATH))
	{
		wsPath = szModlePath;
		size_t iIndex = wsPath.find_last_of(L"\\");

		wsPath = wsPath.substr(0, iIndex + 1);
	}
	return wsPath;
}

inline void G_GetRandomData(vector<int>& vctResult, int nCount, int nMin, int nMax)
{
	for (int nIndex = 0; nIndex < nCount; ++nIndex)
	{
		int nValue = 0;
		do
		{
			nValue = rand() % nMax;

			if (nValue >= nMin)
				break;
			Sleep(20);

		} while (true);

		vctResult.push_back(nValue);
	}
}

inline int G_GetRandomData(int nMin, int nMax)
{
	int nValue = 0;
	do
	{
		nValue = rand() % nMax;

		if (nValue >= nMin)
			break;
		Sleep(20);

	} while (true);

	return nValue;
}

#endif //PCH_H
