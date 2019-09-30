#ifndef DECORATOR_H_
#define DECORATOR_H_

#include<string>
#include<iostream>
#include<memory>
#include "basic.h"

namespace DP {
	class Component {
	public:
		virtual void Operation() = 0;
	};

	class ConcreteComponent : public Component {
	public:
		void Operation() override {
			std::cout << "ConcreteComponent::Operation" << std::endl;
		}
	};

	// Decorator类继承Component是为了可以作为component传参,最后形成一个完整的component的operation调用链
	class Decorator : public Component {
	public:
		void SetComponent(std::shared_ptr<Component>& component) {
			component_ = component;
		}

		void Operation() override {
			if(component_) {
				component_->Operation();
			}
		}
	protected:
		std::shared_ptr<Component> component_;
	};

	class ConcreteDecoratorA : public Decorator {
	public:
		void Operation() override {
			Decorator::Operation();
			std::cout << "ConcreteDecoratorA::Operation" << std::endl;
		}
	};


	class ConcreteDecoratorB : public Decorator {
	public:
		void Operation() override {
			Decorator::Operation();
			std::cout << "ConcreteDecoratorB::Operation" << std::endl;
		}
	};
} // namespace DP


#endif // DECORATOR_H_