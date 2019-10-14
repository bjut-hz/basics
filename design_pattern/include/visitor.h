#ifndef EXAMPLE_H_
#define EXAMPLE_H_

#include <memory>
#include <iostream>
#include <string>
#include <list>
#include "basic.h"

namespace DP {
	// 数据结构保持稳定,对于不同的数据结构采取不同的操作:即随意添加访问者子类
	class ConcreteElementA;
	class ConcreteElementB;
	class Visitor {
	public:
		virtual ~Visitor() {}
		virtual void VisitConcreteElementA(const ConcreteElementA&) const = 0;
		virtual void VisitConcreteElementB(const ConcreteElementB&) const = 0;
	};

	class Element {
	public:
		virtual ~Element() {}
		virtual void Accept(const Visitor&) const = 0;
	};
	class ConcreteElementA : public Element {
	public:
		virtual ~ConcreteElementA() {}
		virtual void Accept(const Visitor& visitor) const override {
			visitor.VisitConcreteElementA(*this);
		}
	};
	class ConcreteElementB : public Element {
	public:
		virtual ~ConcreteElementB() {}
		virtual void Accept(const Visitor& visitor) const override {
			visitor.VisitConcreteElementB(*this);
		}
	};

	// specific visitors 
	class ConcreteVisitor1 : public Visitor {
	public:
		virtual ~ConcreteVisitor1() {}

		virtual void VisitConcreteElementA(const ConcreteElementA& element) const override {
			std::cout << "ConcreteVisitor1 visit ConcreteElementA, addr:" << &element << std::endl; 
		}

		virtual void VisitConcreteElementB(const ConcreteElementB& element) const override {
			std::cout << "ConcreteVisitor1 visit ConcreteElementB, addr:" << &element << std::endl; 			
		}
	};

	class ConcreteVisitor2 : public Visitor {
	public:
		virtual ~ConcreteVisitor2() {}

		virtual void VisitConcreteElementA(const ConcreteElementA& element) const override {
			std::cout << "ConcreteVisitor2 visit ConcreteElementA, addr:" << &element << std::endl; 
		}

		virtual void VisitConcreteElementB(const ConcreteElementB& element) const override {
			std::cout << "ConcreteVisitor2 visit ConcreteElementB, addr:" << &element << std::endl; 			
		}
	};

	class ObjectStructure {
	public:
		void Attach(std::shared_ptr<Element> element) {
			elements_.emplace_back(element);
		}
		void Detach(std::shared_ptr<Element> element) {
			elements_.remove_if([&](const std::shared_ptr<Element>& ele) {
				return ele == element;
			});
		}

		void Accept(Visitor& visitor) {
			for(auto& ele : elements_) {
				ele->Accept(visitor);
			}
		}
	private:
		std::list<std::shared_ptr<Element>> elements_;
	};
} // namespace DP

#endif // EXAMPLE_H_