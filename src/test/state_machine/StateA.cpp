#include "StateA.h"
#include "state_machine/StateMachineTest.h"

#include <iostream>

StateA::StateA( int nSateId ):
	Sdk::State(nSateId), 
	m_nTimes(0)
{		
}	

int StateA::OnCheckTranslation( Parameter& param )
{
	if (param.GetBool("StateA") == false)
	{
		if (param.GetBool("StateB") == true)
		{
			return STATE_B;
		}else if (param.GetBool("StateC") == true)
		{
			return STATE_C;
		}
		else
		{
			std::cout<<"state is error.";
		}
	}
	return STATE_A;
}

void StateA::OnEnter()
{
	std::cout<<"StateA OnEnter."<<endl;
}

void StateA::OnUpdate( float dt )
{
	m_nTimes += 1;
	if (m_nTimes >= 5 )
	{
		m_pParam->SetBool("StateA", false);
		m_pParam->SetBool("StateB", true);
		m_pParam->SetBool("StateC", false);
		m_nTimes = 0;
	}
	std::cout<<"StateA OnUpdate:"<<m_nTimes<<endl;
}

void StateA::OnExit()
{
	std::cout<<"StateA OnExit"<<endl;
}


