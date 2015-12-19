#pragma once
#include "common/CommonDef.h"

BEGIN_NS_SDK

class Parameter;

class StateProtocol
{
public:
	//����ֵΪҪ�л�����״̬ID
	virtual int OnCheckTranslation(Parameter& param) = 0;
	virtual void OnEnter() = 0;
	virtual void OnUpdate(float dt) = 0;
	virtual void OnExit() = 0;
};

END_NS_SDK