#ifndef BUILDER_H_
#define BUILDER_H_

#include<iostream>
#include<list>
#include<string>
#include "basic.h"

// 建造者模式是在当创建复杂对象的算法应该独立于该对象的组成部分以及他们的装配方式时适用的模式
namespace DP {
	class Product {
	public:
		void Add(std::string part) {
			parts_.push_back(part);
		}

		void Show() {
			std::cout << "======create product========" << std::endl;
			for(auto& part : parts_) {
				std::cout << part << std::endl;
			}
		}
	private:
		std::list<std::string> parts_;
	};

	class Builder {
	public:
		virtual void BuildPartA() = 0;
		virtual void BuildPartB() = 0;
		virtual Product& GetResult() = 0;
	};

	class ConcreteBuilder1 : public Builder {
	public:
		void BuildPartA() override {
			product_.Add("part A");
		}

		void BuildPartB() override {
			product_.Add("part B");
		}

		Product& GetResult() override {
			return product_;
		}
	private:
		Product product_;
	};


	class ConcreteBuilder2 : public Builder {
	public:
		void BuildPartA() override {
			product_.Add("part C");
		}

		void BuildPartB() override {
			product_.Add("part D");
		}

		Product& GetResult() override {
			return product_;
		}
	private:
		Product product_;
	};

	class Director {
	public:
		Product& Construct(Builder& builder) {
			// 用来指挥具体的建造过程
			builder.BuildPartA();
			builder.BuildPartB();

			return builder.GetResult();
		}
	};
} // namespace DP

#endif // BUILDER_H_