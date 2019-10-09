#ifndef TEMPLATE_METHOD_H_
#define TEMPLATE_METHOD_H_

#include<iostream>
#include "basic.h"

namespace DP {
	class AbstractClass {
	public:
		virtual void PrimitiveMethod1() const = 0;
		virtual void PrimitiveMethod2() const = 0;

		// 定义操作的骨架,子类实现不同的具体操作:PrimitiveMethod
		void TemplateMethod() {
			PrimitiveMethod1();
			PrimitiveMethod2();
		}
	};

	class ConcreteClass : public AbstractClass {
	public:
		void PrimitiveMethod1() const override  {
			std::cout << "ConcreteClass:PrimitiveMethod1" << std::endl;
		}

		void PrimitiveMethod2() const override  {
			std::cout << "ConcreteClass:PrimitiveMethod2" << std::endl;
		}
	};
} // namespace DP

#endif // TEMPLATE_METHOD_H_