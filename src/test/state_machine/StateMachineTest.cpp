#pragma once

#include "state_machine/StateMachine.h"

#include "StateMachineTest.h"

#include <iostream>

#include "gtest/gtest.h"



TEST(StateMachineTest, StateCircle)
{
	auto pStateMachine = StateMachineTest::CreateStateMachine();
	while (true)
	{
		pStateMachine->Update(10);
	}
}