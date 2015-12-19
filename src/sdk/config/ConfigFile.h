/**************************************************************
 * �ļ���: ConfigFile
 * ����˵��: �����ļ�����
 * ���ߣ�zw
 * ���ڣ�2015/10/16
 * �޸ļ�¼
 * -------------------------------------------------------------
 * �޸ļ�¼ :
  ����       �汾    ����    ����
 **************************************************************/
#pragma once

#include <string>
#include <vector>

#include "common/CommonDef.h"

BEGIN_NS_SDK

//���ñ�����
enum EConfigType
{
    E_INI,
    E_XML,
    E_UNKNOWN,
};

//key�ķָ��ַ�
#define ELEMENT_SPLIT_CHAR          ':'
#define ATTRIBUTE_SPLIT_CHAR        '.'
#define ELEMENT_INDEX_SPLIT_CHAR    '_'


class ConfigFile
{
public:
    ConfigFile(const std::string& strName, const std::string& strFilePath)
        : m_strName(strName), m_strFilePath(strFilePath), m_eConfigType(E_UNKNOWN)
    {
        
    }

	virtual ~ConfigFile();

    //�������е�key�������һ���㼶�ľ���·��
    //����A:B:C.D,��ȡ����A����Ԫ��B����Ԫ���µ�C����Ԫ���µ�D���ԣ�
    //����A:B,��ȡA����Ԫ��B��ֵ
    //����A:B_2,��ȡA�ĵ�2����Ԫ��B��ֵ
    //����A:B_2.F,��ȡA�ĵ�2����Ԫ��B��F����ֵ
    virtual bool GetBool(const std::string& key, bool bDefalut) = 0;
	virtual void SetBool(const std::string& key, bool bValue) = 0;
    virtual long GetInteger(const std::string& key, long nDefault) = 0;
	virtual void SetInteger(const std::string& key, long nValue) = 0;
    virtual std::string GetString(const std::string& key, const std::string& strDefault) = 0;
	virtual void SetString(const std::string& key, const std::string& strValue) = 0;

	//��ȡָ��key��������ֻ���xml���͵������ļ�
	virtual int GetKeyCount(const std::string& key) = 0;
	virtual void Flush(){};
    
    std::string GetName() {return m_strName;}
    std::string GetFilePath() {return m_strFilePath;}
    EConfigType GetType() {return m_eConfigType; }

protected:
    void _SetType(EConfigType eConfigType) { m_eConfigType = eConfigType; }
    StringArray _Split(const std::string& strSource, const char ch);
private:
    std::string m_strName;
    std::string m_strFilePath;
    EConfigType m_eConfigType;
};

END_NS_SDK
