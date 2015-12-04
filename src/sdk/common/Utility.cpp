/**************************************************************
 * 文件名: Utility.cpp
 * 功能说明: 实用工具集
 * 作者：zw
 * 日期：2015/12/03
 * 修改记录
 * -------------------------------------------------------------
 * 修改记录 :
  日期       版本    作者    内容
 **************************************************************/
#include "Utility.h"
#include <stdio.h>
#include <ctype.h>

#include "plog\Log.h"

bool Utility::FileIsExist(const std::string& strFilePath)
{
	if (strFilePath.empty())
	{
		LOGE<<"strFilePath is empty.";
		return false;
	}

	FILE* pFile = fopen(strFilePath.c_str(), "r");
	if(pFile==NULL)
		return false;
	else
	{
		fclose(pFile);
		return true;
	}
}

const std::string Utility::ToLower( const std::string& strSource )
{
	std::string strResult = "";
	if (strSource.empty())
		return strResult;

	int nLen = strSource.length();
	for (int i = 0; i < nLen; ++i)
	{
		strResult.push_back( tolower(strSource[i]) );
	}
	return strResult;
}

const std::string Utility::ToUpper( const std::string& strSource )
{
	std::string strResult = "";
	if (strSource.empty())
		return strResult;

	int nLen = strSource.length();
	for (int i = 0; i < nLen; ++i)
	{
		strResult.push_back( toupper(strSource[i]) );
	}
	return strResult;
}



