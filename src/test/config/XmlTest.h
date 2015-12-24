#include "gtest/gtest.h"
#include "config/ConfigFileMgr.h"

US_NS_SDK;

#define XmlFilePath "test1.xml"

class XmlTest :public testing::Test
{
protected:
	virtual void SetUp() 
	{
		m_pConfigFileMgr = ConfigFileMgr::GetInstance();
		m_pConfigFileMgr->Add("test1", XmlFilePath, E_XML);		
	}

	virtual void TearDown() 
	{
		m_pConfigFileMgr->Pure();
	}

protected:
	ConfigFileMgr* m_pConfigFileMgr;
};

TEST_F(XmlTest, ReadConfigBasicInfo)
{
	ConfigFile* pIniFile = m_pConfigFileMgr->GetConfigFile("test1");
	ASSERT_STREQ("test1",pIniFile->GetName().c_str());
	ASSERT_STREQ(XmlFilePath, pIniFile->GetFilePath().c_str());
	EXPECT_EQ(0,pIniFile->GetKeyCount("ResourceVersion:server"));
	EXPECT_EQ(E_XML, pIniFile->GetType());
}

TEST_F(XmlTest, ReadConfigContent)
{
	ConfigFile* pIniFile = m_pConfigFileMgr->GetConfigFile("test1");
	EXPECT_STREQ("this is base version", pIniFile->GetString("ResourceVersion:VersionBase.desc", "").c_str())<<pIniFile->GetString("ResourceVersion:VersionBase.desc", "12323");
	pIniFile->SetString("ResourceVersion:VersionBase:FromVersion", "2.0");
	pIniFile->Flush();
	EXPECT_STREQ("2.0", pIniFile->GetString("ResourceVersion:VersionBase:FromVersion", "").c_str());
	EXPECT_STREQ("1.0", pIniFile->GetString("ResourceVersion:VersionBase:ToVersion", "").c_str());
	EXPECT_STREQ("", pIniFile->GetString("ResourceVersion:VersionBase:ToVersion1", "").c_str());
	EXPECT_STREQ("http://192.168.1.200/Android/all/1.0=1.1", pIniFile->GetString("ResourceVersion:VersionBase:PatchFile", "").c_str())<<pIniFile->GetString("ResourceVersion:VersionBase:PatchFile", "");
	EXPECT_STREQ("1.5", pIniFile->GetString("ResourceVersion:VersionPatch_6:FromVersion", "").c_str());
	EXPECT_STREQ("this is from version.", pIniFile->GetString("ResourceVersion:VersionPatch_6:FromVersion_2.desc", "").c_str());
	EXPECT_STREQ("1.0", pIniFile->GetString("ResourceVersion:VersionPatch:FromVersion", "").c_str());
	EXPECT_STREQ("", pIniFile->GetString("ResourceVersion:VersionPatch.desc:ToVersion", "").c_str());

	//EXPECT_EQ(19868, pIniFile->GetInteger("VersionBase:FileSize", 0));
	pIniFile->SetInteger("ResourceVersion:VersionBase:FileSize", 2000);
	pIniFile->Flush();
	EXPECT_EQ(2000, pIniFile->GetInteger("ResourceVersion:VersionBase:FileSize", 0) );


	int nCount = pIniFile->GetKeyCount("ResourceVersion:VersionPatch");
	for (int i = 1; i <= nCount; ++i)
	{
		char buff[256] = {0};
		sprintf(buff, "ResourceVersion:VersionPatch_%d:FromVersion", i);
		std::string strFrom(buff);
		memset(buff,0, 256);

		sprintf(buff, "ResourceVersion:VersionPatch_%d:ToVersion", i);
		std::string strTo(buff);
		memset(buff,0, 256);

		sprintf(buff, "ResourceVersion:VersionPatch_%d:PatchFile", i);
		std::string strPatchFile(buff);
		memset(buff,0, 256);

		sprintf(buff, "ResourceVersion:VersionPatch_%d:PatchFileMD5", i);
		std::string strPatchFileMD5(buff);
		memset(buff,0, 256);

		sprintf(buff, "ResourceVersion:VersionPatch_%d:FileSize", i);
		std::string strFileSize(buff);
		

		char resultBuff[1024] = {0};
		sprintf(resultBuff, "%s-%s File:%s MD5:%s FileSize:%d", 
			pIniFile->GetString(strFrom, "").c_str(),
			pIniFile->GetString(strTo, "").c_str(),
			pIniFile->GetString(strPatchFile, "").c_str(),
			pIniFile->GetString(strPatchFileMD5, "").c_str(),
			pIniFile->GetInteger(strFileSize, 0)
			);
		printf(resultBuff);
		printf("\n");
	}
	
	
	
	/*EXPECT_EQ(1250, pIniFile->GetInteger("server:port", 0));
	EXPECT_EQ(1251, pIniFile->GetInteger("client:port", 0));
	EXPECT_EQ(192, pIniFile->GetInteger("client:ip", 0));
	EXPECT_TRUE(pIniFile->GetBool("server:isAuto", false));
	EXPECT_TRUE(pIniFile->GetBool("client:isAuto", false));*/
	//pIniFile->Flush();
}

