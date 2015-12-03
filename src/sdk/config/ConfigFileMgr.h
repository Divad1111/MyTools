/**************************************************************
 * �ļ���: ConfigFileMgr.h
 * ����˵��: ���ڹ������е������ļ���ini��xml��
 * ���ߣ�zw
 * ���ڣ�2015/12/03
 * �޸ļ�¼
 * -------------------------------------------------------------
 * �޸ļ�¼ :
  ����       �汾    ����    ����
 **************************************************************/
#pragma once
#include <string>
#include <map>
#include <utility>
#include "ConfigFile.h"

class ConfigFile;

class ConfigFileMgr
{
public:
	static ConfigFileMgr* GetInstance();
	void Add(const std::string& strConfigName, const std::string& strFilePath, EConfigType eType);
	void Remove(const std::string& strConfigName);
	void Pure();
	ConfigFile* GetConfigFile(const std::string& strConfigName);
private:
	ConfigFileMgr(){}

private:
	static ConfigFileMgr* m_pConfigMgr;
	typedef std::map<std::string, ConfigFile*> DictConfigFile;
	DictConfigFile m_mapConfigFiles;
};