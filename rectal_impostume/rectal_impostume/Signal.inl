using namespace RaptorEngine::Core;

template<class TSignalArgs>
template<class TClass>
void Signal<TSignalArgs>::AddSlot(TClass* const pClass, void(TClass::* const pMethod)(TSignalArgs))
{
	m_mMethodContainer.insert()
}