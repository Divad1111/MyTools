#pragma once

#include "common/CommonDef.h"
#include "gtest/gtest.h"
#include "state_machine/Parameter.h"

US_NS_SDK;

class ParameterTest :public testing::Test
{
protected:
	virtual void SetUp() 
	{
		m_oParam.SetInt("A", 10);
		m_oParam.SetInt("B", 20);
		m_oParam.SetInt("", 30);
		m_oParam.SetInt("D", 1.5);
		m_oParam.SetInt("F", true);

		m_oParam.SetFloat("A", 10);
		m_oParam.SetFloat("B", 20);
		m_oParam.SetFloat("", 30);
		m_oParam.SetFloat("D", 1.5);
		m_oParam.SetFloat("F", true);

		m_oParam.SetBool("A", true);
		m_oParam.SetBool("B", false);
		m_oParam.SetBool("", false);

		m_oParam.SetString("A", "10");
		m_oParam.SetString("B", "abcdefg");
		m_oParam.SetString("", "");
		m_oParam.SetString("D", "");
	}

	virtual void TearDown() 
	{
		
	}

protected:
	Parameter m_oParam;
};


TEST_F(ParameterTest, IntTest )
{
	EXPECT_EQ(0, m_oParam.GetInt(""));
	EXPECT_EQ(10, m_oParam.GetInt("A"));
	EXPECT_EQ(1, m_oParam.GetInt("D"));
	EXPECT_EQ(1, m_oParam.GetInt("F"));
	EXPECT_EQ(0, m_oParam.GetInt("fF"));
}

TEST_F(ParameterTest, FloatTest )
{
	EXPECT_FLOAT_EQ(0.0f, m_oParam.GetFloat(""));
	EXPECT_FLOAT_EQ(10.0f, m_oParam.GetFloat("A"));
	EXPECT_FLOAT_EQ(1.5f, m_oParam.GetFloat("D"));
	EXPECT_FLOAT_EQ(1.0f, m_oParam.GetFloat("F"));
	EXPECT_FLOAT_EQ(0.0f, m_oParam.GetFloat("fF"));
}

TEST_F(ParameterTest, BoolTest )
{
	EXPECT_FALSE( m_oParam.GetBool(""));
	EXPECT_TRUE( m_oParam.GetBool("A"));
	EXPECT_FALSE( m_oParam.GetBool("D"));
	EXPECT_FALSE( m_oParam.GetBool("F"));
	EXPECT_FALSE( m_oParam.GetBool("fF"));
}

TEST_F(ParameterTest, StringTest )
{
	EXPECT_STREQ("", m_oParam.GetString("").c_str());
	EXPECT_STREQ("10", m_oParam.GetString("A").c_str());
	EXPECT_STREQ("abcdefg", m_oParam.GetString("B").c_str());
	EXPECT_STREQ("", m_oParam.GetString("").c_str());
	EXPECT_STREQ("", m_oParam.GetString("fF").c_str());
	EXPECT_STREQ("", m_oParam.GetString("D").c_str());
}