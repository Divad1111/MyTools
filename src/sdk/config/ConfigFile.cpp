#include "ConfigFile.h"

BEGIN_NS_SDK

ConfigFile::~ConfigFile()
{

}

StringArray ConfigFile::_Split(const std::string& strSource, const char ch)
{
    StringArray arrRet;
    std::string::size_type nLength = strSource.length();
    if (nLength <= 0 )
    {
        return arrRet;
    }

    std::string strTmp = "";
    for (std::string::size_type i = 0; i < strSource.length(); ++i)
    {
        char chSplit = strSource[i];
        if (chSplit == ch)
        {
            arrRet.push_back(strTmp);
            strTmp = "";
        }
        else
        {
            strTmp += chSplit;
        }
    }
    arrRet.push_back(strTmp);

    return arrRet;
}

END_NS_SDK
