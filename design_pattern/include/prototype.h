#ifndef PROTOTYPE_H_
#define PROTOTYPE_H_

#include "basic.h"

namespace DP {
	class Prototype {
	public:
		virtual Prototype* Clone() = 0;
		
		explicit Prototype(int id) : id_(id) {}
		
		int id() { 
			return id_;
		}
	protected:
		int id_ = 0;
	};

	class ConcretePrototype1 : public Prototype {
	public:
		explicit ConcretePrototype1(int id) : Prototype(id) {}
		Prototype* Clone() override {
			return new ConcretePrototype1(*this);
		}
	};
} // namespace DP

#endif // PROTOTYPE_H_