#pragma once

#include "state_machine/State.h"

using namespace Sdk;

class StateC : public State
{	
public:
	StateC(int nStateId):State(nStateId), m_nTimes(0){}
protected:
	virtual int OnCheckTranslation( Parameter& param );
	virtual void OnEnter();
	virtual void OnUpdate( float dt );
	virtual void OnExit();

private:
	int m_nTimes;
};