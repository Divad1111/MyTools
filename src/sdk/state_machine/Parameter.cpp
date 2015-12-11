#include "Parameter.h"

#include <plog/Log.h>

BEGIN_NS_SDK


int Parameter::GetInt( string strKey )
{	
	if (strKey.empty())
	{
		LOGE<<"strKey is empty.";
		return 0;
	}

	return m_mapIntValues[strKey];	
}

void Parameter::SetInt( string strKey, int nValue )
{	
	if (strKey.empty())
	{
		LOGE<<"strKey is empty.";
		return;
	}

	m_mapIntValues[strKey] = nValue;
}

float Parameter::GetFloat( string strKey )
{	
	if (strKey.empty())
	{
		LOGE<<"strKey is empty.";
		return 0.0f;
	}

	return m_mapFloatValues[strKey];
}

void Parameter::SetFloat( string strKey, float fValue )
{
	if (strKey.empty())
	{
		LOGE<<"strKey is empty.";
		return;
	}

	m_mapFloatValues[strKey] = fValue;
}

bool Parameter::GetBool( string strKey )
{	
	if (strKey.empty())
	{
		LOGE<<"strKey is empty.";
		return false;
	}

	return m_mapBoolValues[strKey];
}

void Parameter::SetBool( string strKey, bool bValue )
{
	if (strKey.empty())
	{
		LOGE<<"strKey is empty.";
		return;
	}

	m_mapBoolValues[strKey] = bValue;
}

string Parameter::GetString( string strKey )
{	
	if (strKey.empty())
	{
		LOGE<<"strKey is empty.";
		return "";
	}

	return m_mapStringValues[strKey];
}

void Parameter::SetString( string strKey, string strValue )
{
	if (strKey.empty())
	{
		LOGE<<"strKey is empty.";
		return;
	}

	m_mapStringValues[strKey] = strValue;
}

END_NS_SDK