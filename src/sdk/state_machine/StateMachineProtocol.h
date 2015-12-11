#pragma once
#include "common/CommonDef.h"

BEGIN_NS_SDK

class StateMachineProtocol
{
public:
	virtual void OnStart() = 0;
	virtual void OnUpdate(float dt) = 0;
	virtual void OnEnd() = 0;
};

END_NS_SDK