/**************************************************************
 * �ļ���: Utility.h
 * ����˵��: ʵ�ù��߼�
 * ���ߣ�zw
 * ���ڣ�2015/12/03
 * �޸ļ�¼
 * -------------------------------------------------------------
 * �޸ļ�¼ :
  ����       �汾    ����    ����
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


