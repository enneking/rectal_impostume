#pragma once

#include<unordered_map>

namespace RaptorEngine {
namespace Core {

template<class TSignalArgs>
class Signal {
public:
	template<class TClass> 
	void AddSlot( TClass* const pClass, void(TClass::* const pMethod)(TSignalArgs) );
public:
	std::unordered_map <Slot<TSignalArgs> > m_mMethodContainer;
};

};
};


#include"Signal.inl"