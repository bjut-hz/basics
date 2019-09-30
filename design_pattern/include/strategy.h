#ifndef STRATEGY_H_
#define STRATEGY_H_

#include<iostream>
#include<memory>
#include<string>
#include "basic.h"

namespace DP {
	class IStrategy {
	public:
		virtual void AlgrithmInterface() = 0;
	};


	class ConcreteStrategyA : public IStrategy {
	public:
		void AlgrithmInterface() override {
			std::cout << "ConcreteStrategyA::AlgrithmInterface" << std::endl;
		}
	};

	class ConcreteStrategyB : public IStrategy {
	public:
		void AlgrithmInterface() override {
			std::cout << "ConcreteStrategyB::AlgrithmInterface" << std::endl;
		}
	};

	class Context {
	public:
		enum StrategyType {
			kA,
			kB,
		};
	public:
		explicit Context(std::shared_ptr<IStrategy>& strategy) {
			strategy_ = strategy;
		}

		explicit Context(StrategyType type) {
			switch (type)
			{
			case StrategyType::kA:
				strategy_ = std::make_shared<ConcreteStrategyA>();
				break;
			case StrategyType::kB:
				strategy_ = std::make_shared<ConcreteStrategyB>();
				break;
			default:
				break;
			}
		}
		// function type should be consistent with AlgrithmInterface
		void ContextInterface() {
			return strategy_->AlgrithmInterface();
		}
	private:
		std::shared_ptr<IStrategy> strategy_;
	};
} // namespace DP


#endif