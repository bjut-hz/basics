#ifndef STATE_H_
#define STATE_H_

#include "basic.h"
#include <memory>
#include <string>
#include <iostream>

namespace DP {
	class Context;
	class State {
	public:
		virtual void Handle(Context& context) = 0;
	};

	class Context {
	public:
		explicit Context(std::unique_ptr<State>&& state) {
			state_ = std::move(state);
		}
		void Request() {
			state_->Handle(*this);
		}
	public:
		std::unique_ptr<State> state_;
	};

	class ConcreteStateB : public State {
	public:
		void Handle(Context& context) override {
			std::cout << "ConcreteStateB" << std::endl;
		}
	};	

	class ConcreteStateA : public State {
	public:
		void Handle(Context& context) override {
			std::cout << "ConcreteStateA switch to ConcreteStateB" << std::endl;
			context.state_ = std::make_unique<ConcreteStateB>();
		}
	};
} // namespace DP

#endif // STATE_H_