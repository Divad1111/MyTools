#include "State.h"

BEGIN_NS_SDK

State::State( int nStateId ):
	m_nStateId(nStateId)
{

}

State::~State()
{

}

int State::OnCheckTranslation( Parameter& param )
{	
	return m_nStateId;
}

void State::OnEnter()
{	
}

void State::OnUpdate(float dt)
{	
}

void State::OnExit()
{

}

END_NS_SDK