#pragma once
#include "common/CommonDef.h"
#include "StateMachineProtocol.h"
#include "Parameter.h"

BEGIN_NS_SDK

using namespace std;

class State;

class StateMachine : public StateMachineProtocol
{
public:
	static StateMachine* CreateStateMachine();
	virtual ~StateMachine();
	void AddState(State* pState);
	Parameter& GetParam() { return m_oParameter; }
	void SetParam(Parameter val) { m_oParameter = val; }
	State* GetDefaultState() const { return m_pCurState; }
	void SetDefaultState(State* val);
	State* GetCurState() { return m_pCurState; }
	void SetCallbackProtocol(StateMachineProtocol* val) { m_pCallbackProtocol = val; }
	void Update(float dt);

protected:
	StateMachine();
protected:	
	virtual void OnStart();
	virtual void OnUpdate(float dt);
	virtual void OnEnd();

protected:	
	State*				m_pCurState;
	Parameter			m_oParameter;
	StateMachineProtocol* m_pCallbackProtocol;
	bool				m_bIsFirstUpdate;
	typedef map<int, State*> MapStateList;
	MapStateList		m_mapStateList;
};

END_NS_SDK