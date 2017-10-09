#pragma once

namespace RaptorEngine {
namespace Core {

	template<class TClass>
	class Slot {
	public:

	public:
		TClass* const pClass;
		TClass::* const pMethod;
	};

};
};


#include"Slot.inl"