/**************************************************************
 * 文件名: ConfigFileMgr.h
 * 功能说明: 用于管理所有的配置文件（ini和xml）
 * 作者：zw
 * 日期：2015/12/03
 * 修改记录
 * -------------------------------------------------------------
 * 修改记录 :
  日期       版本    作者    内容
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