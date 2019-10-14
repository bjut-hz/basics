#ifndef COMMAND_H_
#define COMMAND_H_

#include "basic.h"
#include <string>
#include <iostream>
#include <memory>

namespace DP {
	class Receiver {
	public:
		void Action() {
			std::cout << "Receiver::Action" << std::endl;
		}
	};

	class Command {
	public:
		explicit Command(std::shared_ptr<Receiver> receiver) : receiver_(receiver) {}
		virtual void Excute() const = 0;
	protected:
		std::shared_ptr<Receiver> receiver_;
	};

	class ConcreteCommand : public Command {
	public:
		ConcreteCommand(std::shared_ptr<Receiver> receiver) : Command(receiver) {}
		void Excute() const override {
			receiver_->Action();
		}
	};

	class Invoker {
	public:
		void SetCommand(std::shared_ptr<Command> command) {
			command_ = command;
		}

		void ExcuteCommand() {
			command_->Excute();
		}
	private:
		std::shared_ptr<Command> command_;
	};
} // namespace DP

#endif // COMMAND_H_