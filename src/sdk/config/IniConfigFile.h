/**************************************************************
 * 文件名: IniConfigFile
 * 功能说明: Ini配置文件的实现类
 * 作者：zw
 * 日期：2015/10/16
 * 修改记录
 * -------------------------------------------------------------
 * 修改记录 :
  日期       版本    作者    内容
 **************************************************************/
#pragma once

#include "ConfigFile.h"

class INIReader;

BEGIN_NS_SDK

class IniConfigFile : public ConfigFile
{
public:
    IniConfigFile(const std::string& strName, const std::string& strFilePath);
	virtual ~IniConfigFile();

    virtual bool GetBool(const std::string& key, bool bDefalut);
	virtual void SetBool( const std::string& key, bool bValue );
    virtual long GetInteger(const std::string& key, long nDefault);
	virtual void SetInteger( const std::string& key, long nValue );
    virtual std::string GetString(const std::string& key, const std::string& strDefault);
	virtual void SetString( const std::string& key, const std::string& strValue );

	virtual int GetKeyCount( const std::string& key );

private:
	bool _Init();
    bool _IsValidKey(const StringArray& key);
private:
    INIReader*   m_pIniReader;
};

END_NS_SDK