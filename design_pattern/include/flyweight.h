#ifndef FLYWEIGHT_H_
#define FLYWEIGHT_H_

#include <memory>
#include <string>
#include <iostream>
#include <map>
#include "basic.h"

namespace DP {
	class Flyweight {
	public:
		virtual ~Flyweight() {}
		virtual void Operation(int) const = 0; // 传递非共享的外部状态
	};

	class ConcreteFlyweight : public Flyweight {
	public:
		virtual ~ConcreteFlyweight() {}
		void Operation(int extrinsic_state) const override {
			std::cout << "ConcreteFlyweight: " << extrinsic_state << std::endl;
		}
	};

	class UnsharedConcreteFlyweight : public Flyweight {
	public:
		virtual ~UnsharedConcreteFlyweight() {}
		void Operation(int extrinsic_state) const override {
			std::cout << "unshared flyweight: " << extrinsic_state << std::endl;
		}
	};

	class FlyweightFactory {
	public:
		FlyweightFactory() {
			flyweights_["X"] = std::make_shared<ConcreteFlyweight>();
			flyweights_["Y"] = std::make_shared<ConcreteFlyweight>();
			flyweights_["Z"] = std::make_shared<ConcreteFlyweight>();
		}

		std::shared_ptr<Flyweight> GetFlyweight(std::string key) {
			return std::dynamic_pointer_cast<Flyweight>(flyweights_[key]);
		}
	private:
		std::map<std::string, std::shared_ptr<ConcreteFlyweight>> flyweights_;
	};
} // namespace DP

#endif // FLYWEIGHT_H_