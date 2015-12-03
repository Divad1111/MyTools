/**************************************************************
 * 文件名: XmlConfigFile.cpp
 * 功能说明: 读取xml类型的配置文件
 * 作者：zw
 * 日期：2015/10/27
 * 修改记录
 * -------------------------------------------------------------
 * 修改记录 :
  日期       版本    作者    内容
 **************************************************************/
#include "XmlConfigFile.h"

#include <plog/Log.h>



XmlConfigFile::XmlConfigFile( const std::string& strName, const std::string& strFilePath ):
	ConfigFile(strName, strFilePath)
{
	_SetType(E_XML);

	int nError = m_xmlDoc.LoadFile(strFilePath.c_str());
	if (tinyxml2::XML_SUCCESS != nError)
	{
		LOGE<<"Init file is failed, error code:"<<nError;
	}
}

XmlConfigFile::~XmlConfigFile()
{

}

bool XmlConfigFile::GetBool( const std::string& key, bool bDefalut )
{
	if (key.empty())
	{
		LOGE<<"key is empty.";
		return bDefalut;
	}

	tinyxml2::XMLElement* pXmlElement = _GetXmlNode(key);
	if (pXmlElement != NULL)
	{
		if (_IsAttribute(key))
		{
			std::string strAttrName = _GetAttributeName(key);
			return pXmlElement->BoolAttribute(strAttrName.c_str());
		}
		else
		{
			return pXmlElement->Value() == "true"?true:false;
		}
	}
	return bDefalut;
}

void XmlConfigFile::SetBool( const std::string& key, bool bValue )
{
	if (key.empty())
	{
		LOGE<<"key is empty.";
		return;
	}

	tinyxml2::XMLElement* pXmlElement = _GetXmlNode(key);
	if (pXmlElement != NULL)
	{
		if (_IsAttribute(key))
		{
			std::string strAttrName = _GetAttributeName(key);
			pXmlElement->SetAttribute(strAttrName.c_str(), bValue);
		}
		else
		{
			pXmlElement->SetValue(bValue?"true":"false");
		}
	}
}

long XmlConfigFile::GetInteger( const std::string& key, long nDefault )
{
	if (key.empty())
	{
		LOGE<<"key is empty.";
		return nDefault;
	}

	tinyxml2::XMLElement* pXmlElement = _GetXmlNode(key);
	if (pXmlElement != NULL)
	{
		if (_IsAttribute(key))
		{
			std::string strAttrName = _GetAttributeName(key);
			return pXmlElement->IntAttribute(strAttrName.c_str());
		}
		else
		{
			return atol(pXmlElement->Value());
		}
	}
	return nDefault;
}

void XmlConfigFile::SetInteger( const std::string& key, long nValue )
{
	if (key.empty())
	{
		LOGE<<"key is empty.";
		return;
	}

	tinyxml2::XMLElement* pXmlElement = _GetXmlNode(key);
	if (pXmlElement != NULL)
	{
		if (_IsAttribute(key))
		{
			std::string strAttrName = _GetAttributeName(key);
			pXmlElement->SetAttribute(strAttrName.c_str(), nValue);
		}
		else
		{
			char buff[32] = {0};
			_ltoa(nValue, buff, 10);
			pXmlElement->SetValue(buff);
		}
	}
}

std::string XmlConfigFile::GetString( const std::string& key, const std::string& strDefault )
{
	if (key.empty())
	{
		LOGE<<"key is empty.";
		return strDefault;
	}

	tinyxml2::XMLElement* pXmlElement = _GetXmlNode(key);
	if (pXmlElement != NULL)
	{
		if (_IsAttribute(key))
		{
			std::string strAttrName = _GetAttributeName(key);
			return pXmlElement->Attribute(strAttrName.c_str());
		}
		else
		{
			return pXmlElement->Value();
		}
	}
	return strDefault;
}

void XmlConfigFile::SetString( const std::string& key, const std::string& strValue )
{
	if (key.empty())
	{
		LOGE<<"key is empty.";
		return;
	}

	tinyxml2::XMLElement* pXmlElement = _GetXmlNode(key);
	if (pXmlElement != NULL)
	{
		if (_IsAttribute(key))
		{
			std::string strAttrName = _GetAttributeName(key);
			pXmlElement->SetAttribute(strAttrName.c_str(), strValue.c_str());
		}
		else
		{			
			pXmlElement->SetValue(strValue.c_str());
		}
	}
}

int XmlConfigFile::GetKeyCount( const std::string& key )
{
	int nCount = 0;
	if (key.empty())
	{
		LOGE<<"key is empty.";
		return nCount;
	}

	tinyxml2::XMLElement* pXmlElement = _GetXmlNode(key);
	if (pXmlElement != NULL)
	{
		if (_IsAttribute(key))
		{
			nCount = 1;
		}
		else
		{
			nCount = 1;
			StringArray elements = _Split(key, ELEMENT_SPLIT_CHAR);
			if (NULL != pXmlElement->NextSiblingElement((*(--elements.end())).c_str()))
			{
				nCount++;
			}
		}
	}
	return nCount;
}

void XmlConfigFile::Flush()
{
	int nError = m_xmlDoc.SaveFile( GetFilePath().c_str() );
	if (tinyxml2::XML_SUCCESS != nError)
	{
		LOGE<<"saving file is failed, error code:"<<nError;
	}
}

tinyxml2::XMLElement* XmlConfigFile::_GetXmlNode( const std::string& key )
{
	tinyxml2::XMLElement* pElement = m_xmlDoc.RootElement();

	StringArray elements = _Split(key, ELEMENT_SPLIT_CHAR);
	for (StringArray::const_iterator iter = elements.begin(); iter != elements.end(); ++iter)
	{
		pElement = pElement->FirstChildElement((*iter).c_str());
		if(pElement == NULL)
		{			
			StringArray sameElements =  _Split(*iter, ELEMENT_INDEX_SPLIT_CHAR);
			if (sameElements.size() == 2)
			{
				std::string strEleName = sameElements[0];
				pElement = pElement->FirstChildElement(strEleName.c_str());
				if (pElement != NULL)
				{
					int nEleNumber = atoi(sameElements[1].c_str());
					for (int nNum = 2; nNum <= nEleNumber; ++nNum)
					{
						pElement = pElement->NextSiblingElement(strEleName.c_str());
					}
				}				
			}
			else
			{
				StringArray attribute =  _Split(*iter, ATTRIBUTE_SPLIT_CHAR);
				if (attribute.size() == 2)
				{
					std::string strEleName = attribute[0];					
					return pElement->FirstChildElement(strEleName.c_str());						
				}	
				return NULL;
			}
		}
	}
	return pElement;
}

bool XmlConfigFile::_IsAttribute( const std::string& key )
{
	StringArray elements = _Split(key, ELEMENT_SPLIT_CHAR);
	StringArray attributes =  _Split((*(--elements.end())).c_str(), ATTRIBUTE_SPLIT_CHAR);
	return attributes.size() == 2 ? true:false;
}

std::string XmlConfigFile::_GetAttributeName( const std::string& key )
{
	StringArray elements = _Split(key, ELEMENT_SPLIT_CHAR);
	StringArray attributes =  _Split((*(--elements.end())).c_str(), ATTRIBUTE_SPLIT_CHAR);
	if (attributes.size() == 2)
		return attributes[1];
	else
		return "";
}