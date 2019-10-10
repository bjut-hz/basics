#ifndef OBSERVER_H_
#define OBSERVER_H_

#include "SimpleSignal.h"
#include "basic.h"
#include <list>
#include <memory>
#include <algorithm>
#include <string>
#include <iostream>

#define USE_DELEGATE

namespace DP {
#ifndef USE_DELEGATE

	/// 不使用用代理的时候,每个观察者必须实现相同的接口
	class Observer {
	public:
		virtual void Update() = 0;
		virtual ~Observer() {}
	};

	class Subject {
	public:
		void Attatch(std::shared_ptr<Observer> observer) {
			observers_.emplace_back(observer);
		}

		void Detach(std::shared_ptr<Observer> observer) {
			std::remove_if(observers_.begin(), observers_.end(), [&observer](const std::shared_ptr<Observer>& ele) {
				return observer == ele;
			});
		}

		void Notify() {
			for (auto& observer : observers_) {
				observer->Update();
			}
		}

		virtual ~Subject() {}
	private:
		std::list<std::shared_ptr<Observer>> observers_;
	};

	class ConcreteSubject : public Subject {
	public:
		std::string subject() { return subject_state_; }
		void SetSubject(std::string subject) {
			subject_state_ = subject;
		}

	private:
		std::string subject_state_;
	};


	class ConcreteObserver : public Observer {
	public:
		explicit ConcreteObserver(std::weak_ptr<ConcreteSubject> s, int id) : subject_(s), id_(id){}
		// subject_ must point a valid subject when Update is called.
		void Update() override {
			std::cout << "ConcreteObserver::Update ==> id:" << id_ << std::endl;
			auto s = subject_.lock();
			std::cout << s->subject() << std::endl;
		}

	private:
		std::weak_ptr<ConcreteSubject> subject_; // 小心循环引用
		int id_;
	};


#else
	class Subject  {
	public:
		Simple::Signal<void()> Update;

		void Notify() {
			Update.emit();
		}

		std::string subject() { return subject_state_; }
		void SetSubject(std::string subject) {
			subject_state_ = subject;
		}
	private:
		std::string subject_state_;
	};

	class ObserverA {
	public:
		explicit ObserverA(std::shared_ptr<Subject> s) : subject_(s) {}

		void UpdateA() {
			std::cout << "ObserverA::UpdateA ==> " << subject_->subject() << std::endl;
		}
	private:
		std::shared_ptr<Subject> subject_;
	};


	class ObserverB {
	public:
		explicit ObserverB(std::shared_ptr<Subject> s) : subject_(s) {}

		void UpdateB() {
			std::cout << "ObserverB::UpdateB ==> " << subject_->subject() << std::endl;
		}
	private:
		std::shared_ptr<Subject> subject_;
	};
#endif
} // namespace DP

#endif // OBSERVER_H_