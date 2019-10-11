#ifndef MEMENTO_H_
#define MEMENTO_H_

#include <string>
#include <memory>
#include <iostream>
#include "basic.h"

namespace DP {
	// 需要保证要保存字段与原来字段定义一致
	struct Memento {
		std::string state; // only save state
	};

	class Originator {
	public:
		Originator(std::string state, int hp) : state_(state), hp_(hp) {}

		std::shared_ptr<Memento> CreateMemento(){
			auto memento = std::make_shared<Memento>();
			memento->state = state_;
			return memento;
		}
		
		void SetMemento(Memento& memento) {
			state_ = memento.state;
		}

		void SetState(std::string state) {
			state_ = state;
		}
		void SetHp(int hp) {
			hp_ = hp;
		}
		
		void Show() {
			std::cout << "state: " << state_ << std::endl << "hp: " << hp_ << std::endl;
		}
	private:
		std::string state_;
		int hp_;
	};

	class Caretaker {
	public:
		std::shared_ptr<Memento> memento;
	};
} // namespace DP

#endif // MEMENTO_H_