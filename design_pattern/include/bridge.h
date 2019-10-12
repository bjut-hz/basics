#ifndef BRIDGE_H_
#define BRIDGE_H_

#include <iostream>
#include <string>
#include <memory>
#include "basic.h"

namespace DP {
	// PIMPL模式, 桥接模式
	class Implementor {
	public:
		virtual void Operation() = 0;
	};

	class ConcreteImplementorA : public Implementor {
	public:
		virtual void Operation() override {
			std::cout << "ConcreteImplementorA::Operation" << std::endl;
		}
	};

	class ConcreteImplementorB : public Implementor {
	public:
		virtual void Operation() override {
			std::cout << "ConcreteImplementorB::Operation" << std::endl;
		}
	};

	class Abstraction {
	public:
		virtual void Operation() {
			implementor_->Operation();
		}
		void SetImplementor(std::shared_ptr<Implementor> implementor) {
			implementor_ = implementor;
		}
	protected:
		std::shared_ptr<Implementor> implementor_;
	};

	class RefinedAbstraction : public Abstraction {
	public:
		void Operation() override {
			implementor_->Operation();
		}
	};
} // namespace DP

#endif // BRIDGE_H_