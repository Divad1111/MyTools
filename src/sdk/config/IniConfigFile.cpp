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
#include "IniConfigFile.h"

#include "externals/ini/ini.h"


bool IniConfigFile::GetBool(const std::string& key, bool bDefalut)
{
    StringArray strElements = _Split(key, ELEMENT_SPLIT_CHAR);
    if ( _IsValidKey(strElements) )
    {
        const std::string strDefault = bDefalut?"true":"false";
        std::string strRet = m_oIniReader.Get(strElements[0], strElements[1], strDefault);
        return strRet == "true"?true:false;
    }

    return bDefalut;
}

long IniConfigFile::GetInteger(const std::string& key, long nDefault)
{
    StringArray strElements = _Split(key, ELEMENT_SPLIT_CHAR);
    if ( _IsValidKey(strElements) )
    {   
        return m_oIniReader.GetInteger(strElements[0], strElements[1], nDefault);
    }

    return nDefault; 
}

std::string IniConfigFile::GetString(const std::string& key, const std::string& strDefault)
{
    StringArray strElements = _Split(key, ELEMENT_SPLIT_CHAR);
    if ( _IsValidKey(strElements) )
    {   
        return m_oIniReader.Get(strElements[0], strElements[1], strDefault);
    }

    return strDefault;
}

bool IniConfigFile::_IsValidKey(const StringArray& key)
{
    //对于ini文件来说，只存在两级
    if ( key.size() != 2 )
    {
        return false;
    }
    return true;
}
