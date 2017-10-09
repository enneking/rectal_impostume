#pragma once
#include "Signal.h"

namespace RaptorEngine {
namespace Core {

template<class TType>
class Field {
public:
	void operator=(TType tValue);
	Signal GetSignal();

private:
	TType m_tValue;
	Signal m_oSignal;
};
};	
};

#include "Field.inl"