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

#include "common/Utility.h"

BEGIN_NS_SDK

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
	tinyxml2::XMLNode* pNode = _GetXmlNode(key);
	if (pNode == nullptr)
	{
		LOGE<<"pNode is null.";
		return bDefalut;
	}

	tinyxml2::XMLElement* pXmlElement = pNode->ToElement();
	if (pXmlElement != NULL)
	{
		if (_IsAttribute(key))
		{
			std::string strAttrName = _GetAttributeName(key);
			return pXmlElement->BoolAttribute(strAttrName.c_str());
		}
		else
		{
			const char* strXmlElement = pXmlElement->GetText();
			return Utility::ToLower(strXmlElement != NULL ? strXmlElement : "")== "true"?true:false;
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
	tinyxml2::XMLNode* pNode = _GetXmlNode(key);
	if (pNode == nullptr)
	{
		LOGE<<"pNode is null.";
		return ;
	}

	tinyxml2::XMLElement* pXmlElement = pNode->ToElement();
	if (pXmlElement != NULL)
	{
		if (_IsAttribute(key))
		{
			std::string strAttrName = _GetAttributeName(key);
			pXmlElement->SetAttribute(strAttrName.c_str(), bValue);
		}
		else
		{
			pXmlElement->SetText(bValue?"true":"false");
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
	tinyxml2::XMLNode* pNode = _GetXmlNode(key);
	if (pNode == nullptr)
	{
		LOGE<<"pNode is null.";
		return nDefault;
	}

	tinyxml2::XMLElement* pXmlElement = pNode->ToElement();
	if (pXmlElement != NULL)
	{
		if (_IsAttribute(key))
		{
			std::string strAttrName = _GetAttributeName(key);
			return pXmlElement->IntAttribute(strAttrName.c_str());
		}
		else
		{
			return atol(pXmlElement->GetText());
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
	tinyxml2::XMLNode* pNode = _GetXmlNode(key);
	if (pNode == nullptr)
	{
		LOGE<<"pNode is null.";
		return ;
	}

	tinyxml2::XMLElement* pXmlElement = pNode->ToElement();
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
			pXmlElement->SetText(buff);
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
	tinyxml2::XMLNode* pNode = _GetXmlNode(key);
	if (pNode == nullptr)
	{
		LOGE<<"pNode is null.";
		return strDefault;
	}

	tinyxml2::XMLElement* pXmlElement = pNode->ToElement();
	if (pXmlElement != NULL)
	{		
		if (_IsAttribute(key))
		{
			std::string strAttrName = _GetAttributeName(key);
			const char* strAttribue = pXmlElement->Attribute(strAttrName.c_str());
			return strAttribue != NULL ? strAttribue : "";
		}
		else
		{			
			const char* strXmlElement = pXmlElement->GetText();
			return strXmlElement != NULL ? strXmlElement : "";
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
	tinyxml2::XMLNode* pNode = _GetXmlNode(key);
	if (pNode == nullptr)
	{
		LOGE<<"pNode is null.";
		return ;
	}

	tinyxml2::XMLElement* pXmlElement = pNode->ToElement();
	if (pXmlElement != NULL)
	{
		if (_IsAttribute(key))
		{
			std::string strAttrName = _GetAttributeName(key);
			pXmlElement->SetAttribute(strAttrName.c_str(), strValue.c_str());
		}
		else
		{			
			pXmlElement->SetText(strValue.c_str());
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
	tinyxml2::XMLNode* pNode = _GetXmlNode(key);
	if (pNode == nullptr)
	{
		LOGE<<"pNode is null.";
		return nCount;
	}

	tinyxml2::XMLElement* pXmlElement = pNode->ToElement();	
	if (pXmlElement != NULL)
	{
		if (_IsAttribute(key))
		{
			nCount = 1;
		}
		else
		{
			nCount = 0;
			StringArray elements = _Split(key, ELEMENT_SPLIT_CHAR);
			const char* strLastElement = (*(--elements.end())).c_str();
			while(pXmlElement != NULL)
			{
				++nCount;
				pXmlElement = pXmlElement->NextSiblingElement(strLastElement);
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

tinyxml2::XMLNode* XmlConfigFile::_GetXmlNode( const std::string& key )
{
	tinyxml2::XMLNode* pCurElement = m_xmlDoc.GetDocument();
	if (pCurElement == NULL)
		return NULL;

	StringArray elements = _Split(key, ELEMENT_SPLIT_CHAR);
	tinyxml2::XMLNode* pTempElement = pCurElement;
	for (StringArray::const_iterator iter = elements.begin(); iter != elements.end(); ++iter)
	{
		pTempElement = pTempElement->FirstChildElement((*iter).c_str());
		if(pTempElement == NULL)
		{			
			StringArray sameElements =  _Split(*iter, ELEMENT_INDEX_SPLIT_CHAR);
			if (sameElements.size() == 2)
			{
				std::string strEleName = sameElements[0];
				pTempElement = pCurElement->FirstChildElement(strEleName.c_str());
				if (pTempElement != NULL)
				{
					int nEleNumber = atoi(sameElements[1].c_str());
					for (int nNum = 2; nNum <= nEleNumber; ++nNum)
					{	
						pTempElement = pTempElement->NextSiblingElement(strEleName.c_str());
					}
					pCurElement = pTempElement;
				}	
				else
				{
					return NULL;
				}
			}
			else
			{
				StringArray attribute =  _Split(*iter, ATTRIBUTE_SPLIT_CHAR);
				if (attribute.size() == 2)
				{
					std::string strEleName = attribute[0];					
					return pCurElement->FirstChildElement(strEleName.c_str());						
				}	
				return NULL;
			}
		}
		else
		{
			pCurElement = pTempElement;
		}
	}
	return pCurElement;
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

END_NS_SDK