#pragma once

#include "state_machine/State.h"

using namespace Sdk;

class StateB : public State
{
public:
	StateB(int nSateId):
		State(nSateId),
		m_nTimes(0)
	{

	}
	virtual ~StateB(){}
protected:
	virtual int OnCheckTranslation( Parameter& param );

	virtual void OnEnter();

	virtual void OnUpdate( float dt );

	virtual void OnExit();

private:
	int m_nTimes;

};