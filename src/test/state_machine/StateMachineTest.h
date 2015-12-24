#pragma once

#include "state_machine/StateMachine.h"

#include <iostream>

#include "StateA.h"
#include "StateB.h"
#include "StateC.h"
#include "gtest/gtest.h"


#define STATE_A		1
#define STATE_B		2
#define STATE_C		3

using namespace Sdk;

class StateMachineTest : public StateMachine
{
public:
	StateMachineTest(){}
protected:
	virtual void OnStart() 
	{
		std::cout<<"The state machine is started."<<std::endl;	
		auto pA = new StateA(STATE_A);
		this->SetDefaultState(pA);
		AddState(pA);
		AddState(new StateB(STATE_B));		
		AddState(new StateC(STATE_C));	
		

		m_oParameter.SetBool("StateA", true);
		m_oParameter.SetBool("StateB", false);
		m_oParameter.SetBool("StateC", false);
	}

	virtual void OnUpdate( float dt ) 
	{
		std::cout<<"The state machine is call function of OnUpdate."<<std::endl;
	}

	virtual void OnEnd() 
	{
		std::cout<<"The state machine is end."<<std::endl;
	}
};

