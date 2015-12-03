/**************************************************************
 * 文件名: ConfigFileMgr.cpp
 * 功能说明: 用于管理所有的配置文件（ini和xml）
 * 作者：zw
 * 日期：2015/12/03
 * 修改记录
 * -------------------------------------------------------------
 * 修改记录 :
  日期       版本    作者    内容
 **************************************************************/

#include "ConfigFileMgr.h"

#include "plog\Log.h"
#include "common\Utility.h"
#include "IniConfigFile.h"
#include "XmlConfigFile.h"

ConfigFileMgr* ConfigFileMgr::m_pConfigMgr = NULL;

ConfigFileMgr* ConfigFileMgr::GetInstance()
{
	if (m_pConfigMgr == NULL)
	{
		m_pConfigMgr = new ConfigFileMgr();
	}
	return m_pConfigMgr;
}

void ConfigFileMgr::Add( const std::string& strConfigName, const std::string& strFilePath, EConfigType eType)
{
	if (strConfigName.empty())
	{
		LOGE<<"strFileName is empty.";
		return;
	}
	if (strFilePath.empty())
	{
		LOGE<<"strFilePath is empty.";
		return;
	}
	if ( !Utility::FileIsExist(strFilePath) )
	{
		LOGE<<strFilePath<<" is not exist.";
		return;
	}

	ConfigFile* pResultConfigFile = NULL;
	if (eType == E_INI)	
		pResultConfigFile = new IniConfigFile(strConfigName, strFilePath);	
	else if (eType == E_XML)	
		pResultConfigFile = new XmlConfigFile(strConfigName, strFilePath);	
	else	
		LOGE<<"eType is unknow.";
	
	m_mapConfigFiles.insert( make_pair(strConfigName, pResultConfigFile) );
}

void ConfigFileMgr::Remove( const std::string& strConfigName )
{
	DictConfigFile::const_iterator iterFinder = m_mapConfigFiles.find(strConfigName);
	if (iterFinder != m_mapConfigFiles.end())
	{
		ConfigFile* pConfigFile = iterFinder->second;
		if(pConfigFile != NULL)
			delete pConfigFile;
		m_mapConfigFiles.erase(iterFinder);
	}
}

void ConfigFileMgr::Pure()
{
	for (DictConfigFile::const_iterator iter = m_mapConfigFiles.begin();
		iter != m_mapConfigFiles.end(); ++iter)
	{
		ConfigFile* pConfigFile = iter->second;
		if(pConfigFile != NULL)
			delete pConfigFile;		
	}
	m_mapConfigFiles.clear();
}

ConfigFile* ConfigFileMgr::GetConfigFile( const std::string& strConfigName )
{
	DictConfigFile::const_iterator iterFinder = m_mapConfigFiles.find(strConfigName);
	if (iterFinder != m_mapConfigFiles.end())
	{
		return iterFinder->second;
	}
	return NULL;
}

