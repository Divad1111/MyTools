#include "StateB.h"
#include "StateMachineTest.h"

int StateB::OnCheckTranslation( Parameter& param )
{
	if (param.GetBool("StateB") == false)
	{
		if (param.GetBool("StateC") == true)
		{
			return STATE_C;
		}else if (param.GetBool("StateA") == true)
		{
			return STATE_A;
		}

	}
	return STATE_B;
}

void StateB::OnEnter()
{
	std::cout<<"StateB OnEnter."<<endl;
}

void StateB::OnUpdate( float dt )
{
	m_nTimes += 1;
	if (m_nTimes >= 5 )
	{
		m_pParam->SetBool("StateA", false);
		m_pParam->SetBool("StateB", false);
		m_pParam->SetBool("StateC", true);
		m_nTimes = 0;
	}
	std::cout<<"StateB OnUpdate:"<<m_nTimes<<endl;
}

void StateB::OnExit()
{
	std::cout<<"StateB OnExit"<<endl;
}

