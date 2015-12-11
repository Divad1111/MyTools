#include "StateMachine.h"

#include "common\CommonDef.h"
#include "state_machine\State.h"

BEGIN_NS_SDK


StateMachine* StateMachine::CreateStateMachine()
{
	return new StateMachine();
}

StateMachine::StateMachine():	
	m_pCurState(nullptr),
	m_pCallbackProtocol(nullptr),
	m_bIsFirstUpdate(true)
{

}

StateMachine::~StateMachine()
{
	for (MapStateList::const_iterator iter = m_mapStateList.begin();
		iter != m_mapStateList.end(); ++iter)
	{
		SAFE_DEL(iter->second)
	}
	m_mapStateList.clear();	
	m_pCurState = nullptr;

	SAFE_DEL(m_pCallbackProtocol);

	OnEnd();	
}

void StateMachine::AddState( State* pState )
{
	//check parameter
	if (pState == nullptr)
		return;
	
	//set default state
	if (m_pCurState == nullptr)
		m_pCurState = pState;

	//set set parameter of state
	pState->SetParameter(&m_oParameter);

	int nStateId = pState->GetStateId();
	MapStateList::const_iterator iterFinder = m_mapStateList.find(nStateId);
	if (iterFinder == m_mapStateList.end())
		m_mapStateList.insert(make_pair(nStateId, pState));
	else
		LOGE<<"Here is same state.";
}

void StateMachine::SetDefaultState( State* val )
{ 
	m_pCurState = val;
	AddState(val);
}

void StateMachine::Update( float dt )
{
	//状态机自生的更新状态回调
	if (m_bIsFirstUpdate)
	{
		OnStart();
		m_bIsFirstUpdate = false;
	}
	OnUpdate(dt);
	
	//检查状态的改变，并回调相应的函数
	if (m_pCurState != nullptr)
	{
		int nStateIdOfChange = m_pCurState->OnCheckTranslation(m_oParameter);
		//状态需要改变
		if (nStateIdOfChange != m_pCurState->GetStateId())
		{
			MapStateList::const_iterator iterFinder = m_mapStateList.find(nStateIdOfChange);
			if ( iterFinder != m_mapStateList.end() )
			{
				m_pCurState->OnExit();
				m_pCurState = iterFinder->second;
				m_pCurState->OnEnter();
			}
		}
		m_pCurState->OnUpdate(dt);
	}
}

void StateMachine::OnStart()
{
	if (m_pCallbackProtocol != nullptr)
		m_pCallbackProtocol->OnStart();
}

void StateMachine::OnUpdate( float dt )
{
	if (m_pCallbackProtocol != nullptr)
		m_pCallbackProtocol->OnUpdate(dt);
}

void StateMachine::OnEnd()
{
	if (m_pCallbackProtocol != nullptr)
		m_pCallbackProtocol->OnEnd();
}

END_NS_SDK