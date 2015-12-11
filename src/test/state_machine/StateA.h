#pragma once

#include "state_machine/State.h"

using namespace Sdk;

class StateA : public State
{
public:	
	StateA(int nSateId);
	
protected:
	virtual int OnCheckTranslation( Parameter& param );

	virtual void OnEnter();

	virtual void OnUpdate( float dt );

	virtual void OnExit();

private:
	int m_nTimes;

};
