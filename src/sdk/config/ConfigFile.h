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
#ifndef CONFIG_FILE_H_
#define CONFIG_FILE_H_

#include <string>
#include <vector>

#include "common/CommonDef.h"


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
    ConfigFile(const std::string& strName, const std::string& strPath)
        : m_strName(strName), m_strPath(strPath), m_eConfigType(E_UNKNOWN)
    {
        
    }

    //函数的中的key代表的是一个层级的绝对路径
    //比如A:B:C.D,获取的是A的子元素B的子元素下的C的子元素下的D属性，
    //比如A:B,获取A的子元素B的值
    //比如A:B_2,获取A的第2个子元素B的值
    //比如A:B_2.F,获取A的第2个子元素B的F属性值
    virtual bool GetBool(const std::string& key, bool bDefalut) = 0;
    virtual long GetInteger(const std::string& key, long nDefault) = 0;
    virtual std::string GetString(const std::string& key, const std::string& strDefault) = 0;
    
    std::string GetName() {return m_strName;}
    std::string GetFilePath() {return m_strPath;}
    EConfigType GetType() {return m_eConfigType; }

protected:
    void _SetType(EConfigType eConfigType) { m_eConfigType = eConfigType; }
    StringArray _Split(const std::string& strSource, const char ch);
private:
    std::string m_strName;
    std::string m_strPath;
    EConfigType m_eConfigType;
};


#endif //CONFIG_FILE_H_
