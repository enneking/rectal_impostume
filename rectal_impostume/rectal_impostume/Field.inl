using namespace RaptorEngine::Core;

template<class TType>
void Field<TType>::operator=(TType tValue)
{
	m_tValue = tValue;
}


template<class TType>
void Field<TType>::GetSignal() 
{
	return m_oSignal;
}


