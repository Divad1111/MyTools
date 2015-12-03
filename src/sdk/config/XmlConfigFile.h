/**************************************************************
 * �ļ���: XmlConfigFile.h
 * ����˵��: ��ȡxml���͵������ļ�
 * ���ߣ�zw
 * ���ڣ�2015/10/27
 * �޸ļ�¼
 * -------------------------------------------------------------
 * �޸ļ�¼ :
  ����       �汾    ����    ����
 **************************************************************/
#include "ConfigFile.h"

#include <xml/tinyxml2.h>

class XmlConfigFile : public ConfigFile
{
public:
	XmlConfigFile(const std::string& strName, const std::string& strFilePath);
	virtual ~XmlConfigFile();

	virtual bool GetBool( const std::string& key, bool bDefalut );
	virtual void SetBool( const std::string& key, bool bValue );

	virtual long GetInteger( const std::string& key, long nDefault );
	virtual void SetInteger( const std::string& key, long nValue );

	virtual std::string GetString( const std::string& key, const std::string& strDefault );
	virtual void SetString( const std::string& key, const std::string& strValue );

	virtual int GetKeyCount( const std::string& key );
	virtual void Flush();

private:
	tinyxml2::XMLElement* _GetXmlNode(const std::string& key);
	bool _IsAttribute(const std::string& key);
	std::string _GetAttributeName(const std::string& key);
private:
	tinyxml2::XMLDocument m_xmlDoc;
};