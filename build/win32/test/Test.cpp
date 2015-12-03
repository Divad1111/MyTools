// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include "gtest/gtest.h"

#include "config/IniTest.h"

int _tmain(int argc, _TCHAR** argv)
{	
	testing::InitGoogleTest(&argc, argv);
	
	int nRet = RUN_ALL_TESTS();
	std::cout<<"press any key to continue.";
	getchar();
	return nRet;
}

