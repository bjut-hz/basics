#ifndef ABSTRACT_FACTORY_H_
#define ABSTRACT_FACTORY_H_

#include "basic.h"
#include <memory>
#include <string>
#include <iostream>

namespace DP {
	enum Type {
		kA,
		kB,
	};
	/// 有多种类型对象,每个类型有不同实现,多种类型为一族对象
	/// 一个工厂生成一族对象,替换工厂可以替换掉一族对象的生成方式,比如在换DB的时候,只要换掉DB的生成工厂即可
	class AbstractProductA {
	public:
		virtual void Display() const = 0;
	};

	class ProductA1 : public AbstractProductA {
	public:
		void Display() const override {
			std::cout << "ProductA1::Display" << std::endl;
		}
	};
	class ProductA2 : public AbstractProductA {
	public:
		void Display() const override {
			std::cout << "ProductA2::Display" << std::endl;
		}
	};

	class AbstractProductB {
	public:
		virtual void Output() const = 0;
	};
	class ProductB1 : public AbstractProductB {
	public:
		void Output() const override {
			std::cout << "ProductB1::Output" << std::endl;
		}
	};
	class ProductB2 : public AbstractProductB {
	public:
		void Output() const override {
			std::cout << "ProductB2::Output" << std::endl;
		}
	};

	class AbstractFacroty {
	public:
		virtual std::shared_ptr<AbstractProductA> CreateProductA() const = 0;
		virtual std::shared_ptr<AbstractProductB> CreateProductB() const = 0;
	};

	class ConcreteFactory1 : public AbstractFacroty {
	public:
		virtual std::shared_ptr<AbstractProductA> CreateProductA() const override {
			return std::make_shared<ProductA1>();
		}

		virtual std::shared_ptr<AbstractProductB> CreateProductB() const override {
			return std::make_shared<ProductB1>();
		}
	};

	class ConcreteFactory2 : public AbstractFacroty {
	public:
		virtual std::shared_ptr<AbstractProductA> CreateProductA() const override {
			return std::make_shared<ProductA2>();
		}

		virtual std::shared_ptr<AbstractProductB> CreateProductB() const override {
			return std::make_shared<ProductB2>();
		}
	};

	/// 每次增加一种对象时,需要同时对所有工厂进行添加代码的操作,比较麻烦,使用简单工厂优化改进
	class DataAccess {
	public:
		static std::shared_ptr<AbstractProductA> CreateProductA() {
			switch (type_) {
				case Type::kA:
					return std::make_shared<ProductA1>();
				case Type::kB:
					return std::make_shared<ProductA2>();
				default:
					return std::make_shared<ProductA1>();
			}
		}

		static std::shared_ptr<AbstractProductB> CreateProductB() {
			switch (type_) {
				case Type::kA:
					return std::make_shared<ProductB1>();
				case Type::kB:
					return std::make_shared<ProductB2>();
				default:
					return std::make_shared<ProductB1>();
			}
		}
	public:
		static Type type_; // 
	};
	Type DataAccess::type_ = Type::kA; // 可以利用配置文件,然后用反射根据此字段组成对应规则直接生成类的对象
} // namespace DP

#endif // ABSTRACT_FACTORY_H_