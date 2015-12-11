#pragma once
#include "common/CommonDef.h"

BEGIN_NS_SDK

using namespace std;

class Parameter
{
public:
	int GetInt(string strKey);
	void SetInt(string strKey, int nValue);
	float GetFloat(string strKey);
	void SetFloat(string strKey, float fValue);
	bool GetBool(string strKey);
	void SetBool(string strKey, bool bValue);
	string GetString(string strKey);
	void SetString(string strKey, string strValue);
private:
	map<string, int> m_mapIntValues;
	map<string, float> m_mapFloatValues;
	map<string, bool> m_mapBoolValues;
	map<string, string> m_mapStringValues;
};


END_NS_SDK