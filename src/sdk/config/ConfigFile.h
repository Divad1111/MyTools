/**************************************************************
 * 文件名: ConfigFile
 * 功能说明: 配置文件基类
 * 作者：zw
 * 日期：2015/10/16
 * 修改记录
 * -------------------------------------------------------------
 * 修改记录 :
  日期       版本    作者    内容
 **************************************************************/
#pragma once

#include <string>
#include <vector>

#include "common/CommonDef.h"

BEGIN_NS_SDK

//配置表类型
enum EConfigType
{
    E_INI,
    E_XML,
    E_UNKNOWN,
};

//key的分割字符
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

    //函数的中的key代表的是一个层级的绝对路径
    //比如A:B:C.D,获取的是A的子元素B的子元素下的C的子元素下的D属性，
    //比如A:B,获取A的子元素B的值
    //比如A:B_2,获取A的第2个子元素B的值
    //比如A:B_2.F,获取A的第2个子元素B的F属性值
    virtual bool GetBool(const std::string& key, bool bDefalut) = 0;
	virtual void SetBool(const std::string& key, bool bValue) = 0;
    virtual long GetInteger(const std::string& key, long nDefault) = 0;
	virtual void SetInteger(const std::string& key, long nValue) = 0;
    virtual std::string GetString(const std::string& key, const std::string& strDefault) = 0;
	virtual void SetString(const std::string& key, const std::string& strValue) = 0;

	//获取指定key的数量，只针对xml类型的配置文件
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
