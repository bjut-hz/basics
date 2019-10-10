#ifndef OBSERVER_H_
#define OBSERVER_H_

#include "basic.h"
#include <list>
#include <memory>
#include <algorithm>
#include <string>
#include <iostream>

namespace DP {
#ifndef USE_DELEGATE
// 不实用代理的时候,每个观察者必须实现相同的接口
	class Observer {
	public:
		virtual void Update() = 0;
	};

	class ConcreteSubject;
	class ConcreteObserver : public Observer {
	public:
		void Update() override {
			std::cout << "ConcreteObserver::Update ==> subject:" << std::endl;
			std::cout << subject_.subject() << std::endl;
		}

	private:
		ConcreteSubject subject_;
	};

	class Subject {
	public:
		void Attatch(std::shared_ptr<Observer> observer) {
			observers_.emplace_back(observer);
		}

		void Detach(std::shared_ptr<Observer> observer) {
			std::remove_if(observers_.begin(), observers_.end(), [&observer](const std::shared_ptr<Observer>& ele){
				return observer == ele;
			});
		}

		void Notify() {
			for(auto& observer : observers_) {
				observer->Update();
			}
		}
	private:
		std::list<std::shared_ptr<Observer>> observers_;
	};

	class ConcreteSubject : public Subject {
	public:
		std::string& subject() { return subject_state_; }
		void SetSubject(std::string& subject) {
			subject_state_ = subject;
		}
	private:
		std::string subject_state_;
	};
#else
#endif
} // namespace DP

#endif // OBSERVER_H_