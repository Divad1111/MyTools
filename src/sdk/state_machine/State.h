#pragma once

#include "common/CommonDef.h"
#include "StateProtocol.h"
#include "Parameter.h"


BEGIN_NS_SDK

class State :public StateProtocol
{
	friend class StateMachine;
public:
	State(int nStateId);
	virtual ~State();
	
	int GetStateId() const { return m_nStateId; }
	int SetStateId(int val) { m_nStateId = val; }
protected:
	void SetParameter(Parameter* param) { m_pParam = param; }
	Parameter* GetParameter() { return m_pParam; }
protected:
	//返回值为要切换到的状态ID
	virtual int OnCheckTranslation(Parameter& param);
	virtual void OnEnter();
	virtual void OnUpdate(float dt);
	virtual void OnExit();
protected:
	int				m_nStateId;
	Parameter*		m_pParam;	//析构的时候不用删除，此对象存在于状态机对象中，不要销毁它。
};

END_NS_SDK
