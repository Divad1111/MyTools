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
	//����ֵΪҪ�л�����״̬ID
	virtual int OnCheckTranslation(Parameter& param);
	virtual void OnEnter();
	virtual void OnUpdate(float dt);
	virtual void OnExit();
protected:
	int				m_nStateId;
	Parameter*		m_pParam;	//������ʱ����ɾ�����˶��������״̬�������У���Ҫ��������
};

END_NS_SDK
