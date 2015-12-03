/**************************************************************
 * �ļ���: IniConfigFile
 * ����˵��: Ini�����ļ���ʵ����
 * ���ߣ�zw
 * ���ڣ�2015/10/16
 * �޸ļ�¼
 * -------------------------------------------------------------
 * �޸ļ�¼ :
  ����       �汾    ����    ����
 **************************************************************/
#ifndef INI_CONFIG_FILE_H_
#define INI_CONFIG_FILE_H_

#include "ConfigFile.h"


class INIReader;

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

#endif//INI_CONFIG_FILE_H_
