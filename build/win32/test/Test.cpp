// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include "gtest/gtest.h"
#include "plog/Log.h"

#define STATE_MACHINE
#define CONFIG_FILE

//≈‰÷√∂¡»°≤‚ ‘
#ifdef CONFIG_FILE 
#include "config/IniTest.h"
#include "config/XmlTest.h"
#endif

//◊¥Ã¨ª˙≤‚ ‘
#ifdef STATE_MACHINE
#include "state_machine/ParameterTest.h"
#include "state_machine/StateA.h"
#include "state_machine/StateB.h"
#include "state_machine/StateC.h"
#include "state_machine/StateMachineTest.h"
#endif



int _tmain(int argc, _TCHAR** argv)
{	

	plog::init(plog::debug, "Hello.txt"); 

	testing::InitGoogleTest(&argc, argv);
	
	int nRet = RUN_ALL_TESTS();
	std::cout<<"press any key to continue.";
	getchar();
	return nRet;
}

