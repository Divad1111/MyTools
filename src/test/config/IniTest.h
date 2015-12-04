#include "gtest/gtest.h"
#include "config/ConfigFileMgr.h"

#define IniFilePath "test1.ini"

class IniTest :public testing::Test
{
protected:
	virtual void SetUp() 
	{
		m_pConfigFileMgr = ConfigFileMgr::GetInstance();
		m_pConfigFileMgr->Add("test1", IniFilePath, E_INI);		
	}

	virtual void TearDown() 
	{
		m_pConfigFileMgr->Remove("test1");
	}

protected:
	ConfigFileMgr* m_pConfigFileMgr;
};

TEST_F(IniTest, ReadConfigBasicInfo)
{
	ConfigFile* pIniFile = m_pConfigFileMgr->GetConfigFile("test1");
	ASSERT_STREQ("test1",pIniFile->GetName().c_str());
	ASSERT_STREQ(IniFilePath, pIniFile->GetFilePath().c_str());
	EXPECT_EQ(0,pIniFile->GetKeyCount("server"));
	EXPECT_EQ(E_INI, pIniFile->GetType());
}

TEST_F(IniTest, ReadConfigContent)
{
	ConfigFile* pIniFile = m_pConfigFileMgr->GetConfigFile("test1");
	EXPECT_STREQ("192.168.1.200", pIniFile->GetString("server:ip", "192.168.1.1").c_str());
	EXPECT_STREQ("192.168.1.1", pIniFile->GetString("server", "192.168.1.1").c_str());
	EXPECT_STREQ("192.168.1.1", pIniFile->GetString("server:ID", "192.168.1.1").c_str());
	EXPECT_EQ(1250, pIniFile->GetInteger("server:port", 0));
	EXPECT_EQ(1251, pIniFile->GetInteger("client:port", 0));
	EXPECT_EQ(192, pIniFile->GetInteger("client:ip", 0));
	EXPECT_EQ("1250", pIniFile->GetString("server:port", "0"));
	EXPECT_TRUE(pIniFile->GetBool("server:isAuto", false));
	EXPECT_TRUE(pIniFile->GetBool("client:isAuto", false));
	pIniFile->Flush();
}

