#pragma once
#include <vector>
#include <string>

using namespace std;

class ICase
{
public:
	virtual vector<wstring> GetFunctionList() = 0;
	virtual int RunFunction(const wstring& wsFunction) = 0;
	virtual void ClearChart() = 0;
	virtual void Release() = 0;

};