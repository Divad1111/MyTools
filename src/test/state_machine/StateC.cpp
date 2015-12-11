#include "StateC.h"
#include "StateMachineTest.h"

int StateC::OnCheckTranslation( Parameter& param )
{
	if (param.GetBool("StateC") == false)
	{
		if (param.GetBool("StateA") == true)
		{
			return STATE_A;
		}else if (param.GetBool("StateB") == true)
		{
			return STATE_B;
		}
	}
	return STATE_C;
}

void StateC::OnEnter()
{
	std::cout<<"StateC OnEnter."<<endl;
}

void StateC::OnUpdate( float dt )
{
	m_nTimes += 1;
	if (m_nTimes >= 5 )
	{
		m_pParam->SetBool("StateA", true);
		m_pParam->SetBool("StateB", false);
		m_pParam->SetBool("StateC", false);
		m_nTimes = 0;
	}
	std::cout<<"StateC OnUpdate:"<<m_nTimes<<endl;
}

void StateC::OnExit()
{
	std::cout<<"StateC OnExit."<<endl;
}



