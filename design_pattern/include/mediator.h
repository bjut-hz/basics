#ifndef MEDIATOR_H_
#define MEDIATOR_H_

#include <string>
#include <iostream>
#include <memory>
#include "basic.h"

namespace DP {
	class Mediator;
	class Colleague {
	public:
		virtual ~Colleague() {}
		explicit Colleague(std::shared_ptr<Mediator> mediator) : mediator_(mediator) {}
	protected:
		std::shared_ptr<Mediator> mediator_;
	};

	class Mediator {
	public:
		virtual ~Mediator() {}
 		virtual void Send(std::string message, const Colleague& colleague) const = 0;
	};

	class ConcreteColleague1 : public Colleague {
	public:
		explicit ConcreteColleague1(std::shared_ptr<Mediator> mediator) : Colleague(mediator) {}
		void Send(std::string message) {
			mediator_->Send(message, *this);
		}

		void Notify(std::string message) {
			std::cout << "colleague1 got message: " << message << std::endl;
		}
	};

	class ConcreteColleague2 : public Colleague {
	public:
		explicit ConcreteColleague2(std::shared_ptr<Mediator> mediator) : Colleague(mediator) {}
		void Send(std::string message) {
			mediator_->Send(message, *this);
		}

		void Notify(std::string message) {
			std::cout << "colleague2 got message: " << message << std::endl;
		}
	};

	class ConcreteMediator : public Mediator {
	public:
		void SetColleague1(std::shared_ptr<ConcreteColleague1> colleague) {
			colleague1_ = colleague;
		}
		void SetColleague2(std::shared_ptr<ConcreteColleague2> colleague) {
			colleague2_ = colleague;
		}

		virtual void Send(std::string message, const Colleague& colleague) const override {
			auto c1 = colleague1_.lock();
			auto c2 = colleague2_.lock();
			if(c1.get() == &colleague) {
				c2->Notify(message);
			} else {
				c1->Notify(message);
			}
		}
		
	private:
		std::weak_ptr<ConcreteColleague1> colleague1_;
		std::weak_ptr<ConcreteColleague2> colleague2_;
	};
} // namespace DP

#endif // MEDIATOR_H_