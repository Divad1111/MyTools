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

#include "externals/ini/INIReader.h"

IniConfigFile::IniConfigFile( const std::string& strName, const std::string& strFilePath ):
	ConfigFile(strName, strFilePath)
{	
	if ( !_Init() )
	{
		delete m_pIniReader;
		m_pIniReader = NULL;
	}
}

IniConfigFile::~IniConfigFile()
{
	if (m_pIniReader != NULL)
	{
		delete m_pIniReader;
	}
}

bool IniConfigFile::_Init()
{
	_SetType(E_INI);
	m_pIniReader = new INIReader(GetFilePath());
	if (m_pIniReader != NULL)
	{
		int nErr = m_pIniReader->ParseError();
		return nErr == 0?true:false;
	}
	else
	{
		return false;
	}
}

bool IniConfigFile::GetBool(const std::string& key, bool bDefalut)
{
	if (m_pIniReader == NULL)
	{
		return bDefalut;
	}

    StringArray strElements = _Split(key, ELEMENT_SPLIT_CHAR);
    if ( _IsValidKey(strElements) )
    {
        const std::string strDefault = bDefalut?"true":"false";
        std::string strRet = m_pIniReader->Get(strElements[0], strElements[1], strDefault);
        return strRet == "true"?true:false;
    }

    return bDefalut;
}

void IniConfigFile::SetBool( const std::string& key, bool bValue )
{

}

long IniConfigFile::GetInteger(const std::string& key, long nDefault)
{
	if (m_pIniReader == NULL)
	{
		return nDefault;
	}

    StringArray strElements = _Split(key, ELEMENT_SPLIT_CHAR);
    if ( _IsValidKey(strElements) )
    {   
        return m_pIniReader->GetInteger(strElements[0], strElements[1], nDefault);
    }

    return nDefault; 
}

void IniConfigFile::SetInteger( const std::string& key, long nValue )
{

}

std::string IniConfigFile::GetString(const std::string& key, const std::string& strDefault)
{
	if (m_pIniReader == NULL)
	{
		return strDefault;
	}

    StringArray strElements = _Split(key, ELEMENT_SPLIT_CHAR);
    if ( _IsValidKey(strElements) )
    {   
        return m_pIniReader->Get(strElements[0], strElements[1], strDefault);
    }

    return strDefault;
}

void IniConfigFile::SetString( const std::string& key, const std::string& strValue )
{

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