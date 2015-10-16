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

#include "externals\ini\INIReader.h"


class IniConfigFile : public ConfigFile
{
public:
    IniConfigFile(const std::string& strName, const std::string& strPath):
        m_oIniReader(strPath), ConfigFile(strName, strPath)
    {
        _SetType(E_INI);
    }

    virtual bool GetBool(const std::string& key, bool bDefalut);
    virtual long GetInteger(const std::string& key, long nDefault);
    virtual std::string GetString(const std::string& key, const std::string& strDefault);

private:
    bool _IsValidKey(const StringArray& key);
private:
    INIReader   m_oIniReader;
};

#endif//INI_CONFIG_FILE_H_
