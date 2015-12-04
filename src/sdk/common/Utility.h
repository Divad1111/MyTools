/**************************************************************
 * 文件名: Utility.h
 * 功能说明: 实用工具集
 * 作者：zw
 * 日期：2015/12/03
 * 修改记录
 * -------------------------------------------------------------
 * 修改记录 :
  日期       版本    作者    内容
 **************************************************************/

#pragma once

#include <string>

class Utility
{
public:
	static bool FileIsExist(const std::string& strFilePath);
	static const std::string ToLower(const std::string& strSource);
	static const std::string ToUpper(const std::string& strSource);
};


